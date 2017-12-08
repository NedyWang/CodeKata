//
// Created by root on 12/8/17.

#include "Thread.h"
using namespace std;

//namespace alpha {
    void *create_stub(void *arg) {
        Thread *thread = static_cast<Thread *>(arg);
        int ret = thread->main();
        if (thread->deleteWhenComplete()) {
            delete thread;
        }
        pthread_exit(&ret);
        return nullptr;
    }

    bool Thread::go() {
        if (m_bCreateDetached) {
            pthread_attr_t attr;
            pthread_attr_init(&attr);
            int status1 = pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);
            int status2 = pthread_create(&m_id, &attr, create_stub, this);
            int status3 = pthread_attr_destroy(&attr);
            return status2 == 0;
        } else {
            int ret = pthread_create(&m_id, nullptr, create_stub, this);
            return ret == 0;
        }
    }
//}
