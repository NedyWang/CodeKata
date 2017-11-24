//
// Created by root on 11/20/17.
//


#include <iostream>
#include <memory>

class Component {
public:
    virtual void Operation() = 0;
};

class ConcertComponent : public Component {
public:
    virtual void Operation() {
        std::cout << "Conert component operation" << std::endl;
    }
};


class Decorator : public Component {
public:
    explicit Decorator(Component *_component) : component(_component) {}

    virtual void Operation() {
        component->Operation();
        std::cout << "Decorator operation..." << std::endl;
    }

    virtual ~Decorator(){
        delete component;
    }

protected:
    Component *component;
};

class Decorator_A : public Decorator {
public:
    explicit Decorator_A(Component *_component) :
            Decorator(_component) {}

    virtual void Operation() {
        AddOperation();
        std::cout << "Decorator_A operation..." << std::endl;
        component->Operation();
    }

    void AddOperation() {
        std::cout << "Add Operation in Decorator_A" << std::endl;
    }
};

class Decorator_B : public Decorator {
public:
    explicit Decorator_B(Component *_component) :
            Decorator(_component) {}

    virtual void Operation() {
        AddOperation();
//        std::cout << "Decorator_B operation..." << std::endl;
        component->Operation();
    }

    void AddOperation() {
        std::cout << "Add Operation in Decorator_B" << std::endl;
    }
};


int main()
{
    Component *component = new ConcertComponent;
    Component *decorator_a = new Decorator_A(component);
    Component *decorator_b = new Decorator_B(decorator_a);

    decorator_a->Operation();
    decorator_b->Operation();

    delete component;
    delete decorator_a;
    delete decorator_b;

    std::shared_ptr<Component> sharedPtr(new ConcertComponent);
    sharedPtr->Operation();
    return 0;
}
