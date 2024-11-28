#include <iostream>
#include <string>

struct Foo {
    void saluta(const std::string& nome = "Pippo") const
    {
        std::cout << "Ciao " << nome << '\n';
    }

    void operator()(const std::string& nome = "Pippo")
    {
        std::cout << "Hello " << nome << '\n';
    }
};


int main()
{
    Foo f;
    f.saluta();
    f("Gianni");
    f();

    auto l = [](const std::string& nome = "Pippo") -> bool {
        std::cout << "Hello " << nome << '\n';
        return true;
    };
    l("Santuzzo");

    std::string saluto{"Bonjour"};
    std::string suffisso{"!!!"};

    // saluto e suffisso sono catturati per riferimento
    auto p = [&saluto,&suffisso](const std::string& nome = "Pippo") -> bool {
        std::cout << saluto << " " << nome << suffisso << '\n';
        return true;
    };

    // saluto è catturato per valore, suffisso per riferimento
    auto q = [saluto,&suffisso](const std::string& nome = "Pippo") -> bool {
        std::cout << saluto << " " << nome << suffisso << '\n';
        return true;
    };

    // Tutto è catturato per valore (copia)
    auto r = [=](const std::string& nome = "Pippo") -> bool {
        std::cout << saluto << " " << nome << suffisso << '\n';
        return true;
    };

    // Tutto è catturato per riferimento
    auto s = [&](const std::string& nome = "Pippo") -> bool {
        std::cout << saluto << " " << nome << suffisso << '\n';
        return true;
    };

    // Tutto è catturato per riferimento, tranne saluto (copiato)
    auto t = [&,saluto](const std::string& nome = "Pippo") -> bool {
        std::cout << saluto << " " << nome << suffisso << '\n';
        return true;
    };

    // Tutto è catturato per valore, tranne saluto (per riferimento)
    auto u = [=,&saluto](const std::string& nome = "Pippo") -> bool {
        std::cout << saluto << " " << nome << suffisso << '\n';
        return true;
    };


    p();
    saluto = "Hallo";
    p();
    q();
    r();
    s();
}
