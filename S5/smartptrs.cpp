#include <iostream>
#include <memory>
#include <vector>

/**
 * MyUniquePtrInt gestisce un puntatore a un'intero allocato sullo heap
 */
struct MyUniquePtrInt {
    MyUniquePtrInt(int *p) : m_p{p} {}

    int& operator*() const
    {
        return *m_p;
    }

    int* get() const
    {
        return m_p;
    }

    ~MyUniquePtrInt()
    {
        delete m_p;
    }

private:
    MyUniquePtrInt(const MyUniquePtrInt&) {}
    MyUniquePtrInt& operator=(const MyUniquePtrInt&)
    {
        return *this;
    }
    int* m_p{nullptr};
};

struct MySharedPtrInt {
    // il contatore m_counter è condiviso tra le "copie" di questa istanza
    // di MySharedPtrInt
    MySharedPtrInt(int *p) : m_p{p}, m_counter{new int{1}} {}

    int& operator*() const
    {
        return *m_p;
    }

    int* get() const
    {
        return m_p;
    }

    ~MySharedPtrInt()
    {
        --(*m_counter); // decremento il contatore condiviso
        if (*m_counter == 0) { // se non ci sono più copie posso deallocare
            delete m_counter;
            delete m_p;
        }
    }

    // Ogni copia condivide il puntatore all'allocazione che deve gestire
    // e il puntatore al contatore del numero di copie
    MySharedPtrInt(const MySharedPtrInt& o) : m_p{o.m_p}, m_counter{o.m_counter}
    {
        ++(*m_counter); // Tengo conto della copia appena creata
    }

    MySharedPtrInt& operator=(const MySharedPtrInt& o)
    {
        // Caso speciale: se stiamo gestendo la stessa allocazione allora
        // ignoriamo la copia
        if (m_counter == o.m_counter) {
            return *this;
        }

        // Prima gestisco l'allocazione corrente, che perde un riferimento
        --(*m_counter); // decremento il contatore condiviso
        if (*m_counter == 0) { // se non ci sono più copie posso deallocare
            delete m_counter;
            delete m_p;
        }

        // Poi riassegno i puntatori
        m_counter = o.m_counter;
        m_p = o.m_p;

        // Infine tengo conto della copia appena creata
        ++(*m_counter);
        return *this;
    }

private:
    int* m_p{nullptr};
    int* m_counter;
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


void myunique_ptr_examples()
{
    std::cout << "MyUniquePtr\n";
    MyUniquePtrInt p{new int{42}};
    MyUniquePtrInt q{new int{77}};
    // p = q; // impossibile: operatore di assegnamento di copia è privato
    std::cout << *p << '\n';
    bar(p.get());
}

void myshared_ptr_examples()
{
    std::cout << "MySharedPtrInt\n";
    MySharedPtrInt p{new int{42}};
    std::cout << *p << '\n';
    bar(p.get());
    MySharedPtrInt q{new int{77}};
    std::cout << *q << '\n';
    MySharedPtrInt r{q}; // Costruttore di copia
    std::cout << *r << '\n';
    r = p; // Operatore di assegnamento di copia
    std::vector<MySharedPtrInt> v;
    v.push_back(p);
    v.push_back(q);
    v.push_back(r);
}

void naked_ptr_examples()
{
    std::cout << "Naked pointers\n";
    int* p{new int{42}};
    std::cout << *p << '\n';
    bar(p);
    int* q{new int{77}};
    int* r{q};
    r = p;
    std::vector<int*> v;
    v.push_back(p);
    v.push_back(q);
    v.push_back(r);
    // Leaks!
}

int main()
{
    unique_ptr_examples();
    shared_ptr_examples();
    //naked_ptr_examples();
    myunique_ptr_examples();
    myshared_ptr_examples();
}
