#include <iostream>

using namespace std;

class Base {
public:
    virtual ~Base()
    {
        cout << "Destroying Base" << endl;
    }
};

class Derived : public Base {
public:
    Derived() : m_intptr { new int } {};
    ~Derived() override
    {
        cout << "Destroying Derived" << endl;
        delete m_intptr;
    }
private:
    Derived(const Derived&) = delete;
    Derived& operator=(const Derived&) = delete;
    int* m_intptr;
};

class Manager {
public:
    Manager() : m_resource{nullptr} {};
    ~Manager()
    {
        delete m_resource;
    }
    void manage(Base* r)
    {
        delete m_resource;
        m_resource = r;
    }
private:
    Manager(const Manager&) = delete;
    Manager& operator=(const Manager&) = delete;
    Base* m_resource;
};

int main()
{
    Manager g;
    Derived* pd = new Derived();
    g.manage(pd);
}
