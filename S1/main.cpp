#include <iostream>
#include <string>
#include "libreria.h"

//using namespace std; // importa i simboli del namespace std
void streams() {
    std::cout << "Ciao mondo\n";
    int i;
    std::cin >> i;
    std::cerr << "Errore";
}

void funzione() {
    std::cout << "::funzione()\n";
}

// Overloading di somma "alla Java"
/*int somma(int a, int b, int c, int d) {
    return a+b+c+d;
}

int somma(int a, int b, int c) {
    return somma(a,b,c,0);
}

int somma(int a, int b) {
    return somma(a,b,0,0);
}*/

int somma(int a, int b, int c = 0, int d = 0) {
    return a+b+c+d;
}

// Non è un overload valido
//int funzione() {
//    std::cout << "::funzione()\n";
//}

void funzione(int i) {
    std::cout << "::funzione()" << i << '\n';
}

namespace std {
void funzione() {
   ::funzione(); // accesso a un simbolo nel namespace di default
}
}

// Namespace gerarchici
namespace org {
    namespace test {
        void funzione() {
           ::funzione();
        }
    }
}

void namespaces() {
    //using namespace org::test;
    namespace abc = supsi; // alias
    funzione();
    corsocpp::funzione();
    supsi::funzione();
    org::test::funzione();
    abc::funzione();
}

void default_values() {
    somma(3,4);
    somma(3,4,5);
    somma(3,4,5,6);
}

void string_type() {
    std::string messaggio{"Ciao mondo"};
    std::cout << messaggio << '\n';
    messaggio += "!!!";
    std::cout << messaggio[3] << '\n';
    // slide 23
}

auto g(int a, int b) {
    return a+b;
}

void f(int a, double b) {
    auto c{a+b};
}

void initialization() {
    //int pi{3.14};
    auto pi2{3.1415};
    //pi = 3.14;
}

int main() {
    namespaces();
    default_values();
    string_type();
    initialization();
}
