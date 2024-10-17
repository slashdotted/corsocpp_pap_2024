#include <iostream>
#include <string>
#include "orange.h"

struct BoxAllInOne {
    BoxAllInOne()
    {
        std::cout << "Creo BoxAllInOne\n";
    }

    ~BoxAllInOne()
    {
        std::cout << "Distruggo BoxAllInOne\n";
    }

    Orange arancia_y{"Y1"};
    Orange arancia_x{"X1"};
};

struct BoxExternal {
    BoxExternal() : arancia_y{new Orange{"Y2"}},
    arancia_x{new Orange{"X2"}}
    {
        std::cout << "Creo BoxExternal\n";
    }

    // costruttore di copia / copy constructor
    BoxExternal(const BoxExternal& o)
    // per copiare Orange... chiedo al costruttore di copia
    // di Orange
        : arancia_y{new Orange{*o.arancia_y}},
    arancia_x{new Orange{*o.arancia_x}}
    {
    }

    BoxExternal& operator=(const BoxExternal& o)
    {
        *arancia_y = *o.arancia_y;
        *arancia_x = *o.arancia_x;
        return *this;
    }

    ~BoxExternal()
    {
        std::cout << "Distruggo BoxExternal\n";
        delete arancia_x;
        delete arancia_y;
    }

    Orange *arancia_y;
    Orange *arancia_x;
};


void howManyOranges()
{
    std::cout << Orange::count() << '\n';
}

void foo(BoxAllInOne b)
{
    std::cout << "Sono in Foo\n";
}

void foo(BoxExternal b)
{
    std::cout << "Sono in Foo\n";
}


int main()
{
    //BoxAllInOne ba;
    //foo(ba);

    BoxExternal bb1;
    //foo(bb1);
    BoxExternal bb2;
    bb1 = bb2;



    /*howManyOranges(); // 0
    Orange a{"A"};
    howManyOranges(); // 1
    {
        Orange c{"C"};
        howManyOranges(); // 2
    }
    howManyOranges(); // 1
    Orange *d{new Orange{"D"}};
    howManyOranges(); // 2
    delete d;
    howManyOranges(); // 1*/
}
