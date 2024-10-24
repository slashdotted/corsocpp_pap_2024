#include <iostream>
#include <memory>
#include <vector>

struct MyUniquePtrInt {
    MyUniquePtrInt(int *p) : m_p{p} {}

    int& operator*()
    {
        return *m_p;
    }

    ~MyUniquePtrInt()
    {
        delete m_p;
    }

private:
    MyUniquePtrInt(const MyUniquePtrInt&) {}
    MyUniquePtrInt& operator=(const MyUniquePtrInt&) {}
    int* m_p{nullptr};
};

struct MySharedPtrInt {
    MySharedPtrInt(int *p) : m_p{p} {}

    int& operator*()
    {
        return *m_p;
    }

    ~MySharedPtrInt()
    {
        // TODO: contatore
        delete m_p;
    }

    MySharedPtrInt(const MySharedPtrInt&)
    {
        // TODO: contatore
    }

    MySharedPtrInt& operator=(const MySharedPtrInt&)
    {
        // TODO: contatore
    }

private:
    int* m_p{nullptr};
};

void foo(const std::unique_ptr<int>& q)
{
    std::cout << *q << '\n';
}

void foo(std::shared_ptr<int> q)
{
    std::cout << *q << '\n';
}

void bar(int* q)
{
    std::cout << *q << '\n';
}

void unique_ptr_examples()
{
    //auto p{new int{42}}; // naked pointer
    std::unique_ptr<int> p{new int{42}};
    std::unique_ptr<int> p2{std::make_unique<int>(42)};
    std::cout << *p << '\n';
    foo(p);
    bar(p.get());
    std::vector<std::unique_ptr<int>> v;
    //v.push_back(p); // richiede la copia
    v.push_back(std::move(p)); // "sposto" la gestione dentro vector
    //delete p;
}

void shared_ptr_examples()
{
    std::shared_ptr<int> p{new int{42}};
    std::shared_ptr<int> p2{std::make_shared<int>(42)};
    std::cout << *p << '\n';
    foo(p);
    bar(p.get());
    std::vector<std::shared_ptr<int>> v;
    v.push_back(p);
}

int main()
{
    unique_ptr_examples();
    shared_ptr_examples();
}
