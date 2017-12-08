//
// Created by root on 12/8/17.
//

#include <iostream>
#include <zconf.h>
#include "Thread.h"

//using namespace alpha;

class EchoThread:public Thread {
public:
    explicit EchoThread(bool bCreateDetached = false,
                        bool bDeleteWhenComplete = true,
                        const char *name = nullptr)
            : Thread(bCreateDetached, bDeleteWhenComplete, name) {}

    virtual int main() {
        std::cout << "This is echo thread " << std::endl;
        return 0;
    }

    void start() {
        this->go();
    }
};
