//
// Created by root on 12/8/17.
//
#include "EchoThread.h"
//using namespace std;
//using namespace alpha;

int main()
{
    Thread *thread = new EchoThread(false, true, "EchoThread");
    std::cout << "main thread..."<< std::endl;
    thread->go();
}
