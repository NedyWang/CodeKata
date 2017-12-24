//
// Created by root on 12/24/17.
//

#include <iostream>

class Base {
public:
    virtual void func() {
        std::cout << "Base func" << std::endl;
    }
};

class Derive : public Base {
public:
    virtual void func() {
        std::cout << "Derive func" << std::endl;
    }
};

int main(void)
{
    Base *b = new Base();
    Derive *d = new Derive();
    std::cout << "Base size is " <<  sizeof(*b) << std::endl;
    std::cout << "Derive size is " <<  sizeof(*d) << std::endl;

    std::cout << "============================" << std::endl;
    std::cout << "Class Derive's vtable address[OCT] = " << *(int *)(d) << std::endl;
    std::cout << "Class Base's vtable address[OCT] = " << *(int *)(b) << std::endl;

    std::cout << "============================" << std::endl;
    std::cout << "Class Derive's vtable address[HEX] = " << (int*)(*(int *)(d)) << std ::endl;
    std::cout << "Class Base's vtable address[OCT] = " << (int*)(*(int *)(b)) << std ::endl;

    std::cout << "============================" << std::endl;
    std::cout << "Function Derive::func address = " << (int*)(*((int*)(*(int *)(d)))) << std ::endl;
    std::cout << "Function Base::func address = " << (int*)(*((int*)(*(int *)(b)))) << std ::endl;

    typedef void(*Func)();
    Func pFun = (Func) (int *)(*((int*)(*((int*)d))));
    pFun();

    Func pFunB = (Func) (int *)(*((int*)(*((int*)b))));
    pFunB();

    return 0;
}
