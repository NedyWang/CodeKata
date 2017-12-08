//
// Created by root on 12/8/17.
//

#ifndef LEET_CODE_THREAD_H
#define LEET_CODE_THREAD_H

#include <string>
#include <pthread.h>

using namespace std;

//namespace alpha {
class Thread {
public:
    explicit Thread(bool bCreateDetached = false,
                    bool bDeleteWhenComplete = true,
                    const char *name = nullptr):
            m_bCreateDetached(bCreateDetached),
            m_bDeleteWhenComplete(bDeleteWhenComplete),
            m_id(0) {
        m_name = name == nullptr ? "unnamed" : name;
    }

    virtual ~Thread() = default;

    virtual int main() = 0;

    bool join(void **m_return = nullptr) {
        int status = pthread_join(m_id, m_return);
        return status == 0;
    }

    bool go();

    bool deleteWhenComplete() {
        return m_bDeleteWhenComplete;
    }

    void setName(const string name) {
        m_name = name;
    }

    string getName() {
        return m_name;
    }

    pthread_t getId() {
        return m_id;
    }

private:
    bool m_bCreateDetached;
    bool m_bDeleteWhenComplete;
    string m_name;
    pthread_t m_id;
};
//}


#endif //LEET_CODE_THREAD_H
