#include <iostream>
#include <memory>
using namespace std;

class A {
public:
    void pub() {};
protected:
    void pro() {};
private:
    void pri() {};
};

class B1 : private A {
public:
    void t()
    {
        pub(); // Became private
        pro(); // Became private
//pri(); // Error
    }
};

class B2 : protected A {
public:
    void t()
    {
        pub(); // Became protected
        pro();
        //pri(); // Error
    }
};


class C1 : public B1 {
public:
    void r()
    {
        //pub(); // Error, is private in B1
        //pro(); // Error, is private in B1
        //pri(); // Error, is private in B1
    }
};

class C2 : public B2 {
public:
    void r()
    {
        pub(); // Ok, is protected
        pro(); // Ok, is protected
        //pri(); // Error, is private in B2
    }
};

int main()
{
    C1 c1;
    c1.r();
    // c1.pub(); // Error, is private in B1!
    C2 c2;
    c2.r();
    // c2.pub(); // Error, is protected!
}
