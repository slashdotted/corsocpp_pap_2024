#include "libreria.h"
#include <iostream>

namespace corsocpp {
    void funzione() {
        std::cout << "corsocpp::funzione\n";
    }

    int moltiplica(int a, int b, int c, int d) {
        return a*b*c*d;
    }
}

namespace supsi {
    void funzione() {
        std::cout << "corsocpp::funzione\n";
    }
}
