//
// Created by root on 12/19/17.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <vector>
#include <unistd.h>
#include <iostream>
#include <bits/shared_ptr.h>
#include "../Thread/Thread.h"

#define LISTEN_PORT 8788
#define LISTEN_QUEUE_CNT 5
#define THREAD_CNT 10


#ifdef MULTI_THREAD_ACCEPT
/**
 * @brief Demo of multi thread to do accept.
 */
class TimeServerThread: public Thread {
public:
    explicit TimeServerThread(int listen_fd,
                              bool bCreateDetached = false,
                              bool bDeleteWhenComplete = true,
                              const char *name = nullptr
                              ): Thread(bCreateDetached,
                                        bDeleteWhenComplete,
                                        name) {
        m_listen_fd = listen_fd;
        std::cout << "echo thread [" << name << "] is created" << std::endl;
    }

    virtual ~TimeServerThread() { }

    virtual int main() {
        while(true) {
            pthread_mutex_lock(&lock);
            struct sockaddr_in client_address;
            socklen_t client_len = sizeof(client_address);
            int conn_fd = accept(m_listen_fd, (struct sockaddr*)&client_address, &client_len);
            doProcess(conn_fd, client_address, client_len);
            close(conn_fd);
            pthread_mutex_unlock(&lock);
        }
    }

private:
    int m_listen_fd;
    static pthread_mutex_t lock;

private:
    void doProcess(int fd, struct sockaddr_in& cli_addr, int client_len) {
        time_t tickets = time(nullptr);
        char buf[1024] ={'\0'};
        snprintf(buf, sizeof(buf), "server time is [%s]", ctime(&tickets));
        write(fd, buf, strlen(buf));
    }
};


pthread_mutex_t TimeServerThread::lock = PTHREAD_MUTEX_INITIALIZER;

int main()
{
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_address;
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(LISTEN_PORT);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    bind(listen_fd, (struct sockaddr*)&server_address, sizeof(server_address));
    listen(listen_fd, LISTEN_QUEUE_CNT);

    std::vector<Thread*> threads;
    for (int i = 0; i < THREAD_CNT; ++i) {
        Thread* thread = new TimeServerThread(listen_fd, true, true, to_string(i).c_str());
        threads.push_back(thread);
    }

    for(auto thread: threads) {
        thread->go();
    }
    return 0;
}
#else

class TimeServerThd: public Thread
{
public:
    TimeServerThd(int *m_get,
                  int *m_put,
                  bool bCreateDetached = false,
                  bool bDeleteWhenComplete = true,
                  const char *name = nullptr)
    :Thread(bCreateDetached, bDeleteWhenComplete, name), _m_get(m_get), _m_put(m_put){

    }

    virtual ~TimeServerThd() {}

    virtual int main() {
        pthread_mutex_lock(&lock);
        while( *_m_put == *_m_get)
            pthread_cond_wait(&cond, &lock);
        /*
         * do process
         */
        pthread_mutex_unlock(&lock);
    }

    void start() {
        this->go();
    }

private:
    std::shared_ptr<int *> _m_get;
    std::shared_ptr<int *> _m_put;
    static pthread_mutex_t lock;
    static pthread_cond_t cond;
//    static bool isInited;
};



#endif
