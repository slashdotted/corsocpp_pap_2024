#include <iostream>
#include <string>

void heap_allocation() {
    // Allocazione sullo stack (gestita automaticamente)
    double pi{3.14};
    std::string messaggio{"Hello world"};

    // Allocazione (esplicita) sullo heap
    // i,j,k,l sono sullo stack
    // e puntano a memoria sullo heap
    int* i{new int{6}};
    // equivale a
    int* j{new int};
    *j = 6;
    // """equivale a"""
    int* k = (int*) malloc(sizeof(int));
    *k = 6;
    int* l{new int[10]}; // array di 10 interi

    std::cout << "*i=" << *i << std::endl;

    // Dereferenziare un puntatore non valido porta
    // a un segmentation fault
    // double* z{nullptr};
    // std::cout << "*z=" << *z << std::endl;

    // Deallocazione esplicita necessaria
    delete i;
    delete j;
    free(k);
    delete[] l; // Deallocazione di un array
}

void stack_allocation() {
    double pi{3.14};
    std::string messaggio{"Hello world"};
    std::string title; // oggetto di tipo string sullo stack
    std::cout << "sizeof(double)=" << sizeof(double) << std::endl;
    std::cout << "sizeof(string)=" << sizeof(std::string) << std::endl;
}

void stampa(std::string* s) {
    std::cout << *s << std::endl;
}

void stampa(std::string s) {
    std::cout << s << std::endl;
}

void no_swap(int x, int y) {
    int temp{x};
    x = y;
    y = temp;
}

void swap(int* x, int* y) {
    int temp{*x};
    *x = *y;
    *y = temp;
}

void pointers() {
    int k{7};
    int* p{&k}; // i puntatori non significano per forza
             // memoria allocata dinamicamente sull heap

    // I puntatori posso essere usati per passare un parametro
    // a una funzione in modo più economico
    std::string msg{"Hello world"};
    std::cout << "sizeof(string)=" << sizeof(std::string) << std::endl;
    std::cout << "sizeof(string*)=" << sizeof(std::string*) << std::endl;
    stampa(msg); // passaggio per valore: l'oggetto string viene copiato
    stampa(&msg); // passaggio per valore: l'indirizzo (puntatore) viene copiato

    // I puntatori possono essere utilizzati per permette a una
    // funzione di manipolare dei dati "esterni"
    int a{6};
    int b{11};
    std::cout << "a=" << a << ", b=" << b << std::endl;
    no_swap(a,b);
    std::cout << "a=" << a << ", b=" << b << std::endl;
    swap(&a,&b);
    std::cout << "a=" << a << ", b=" << b << std::endl;
}

void swap_byref(int& x, int& y) {
    int temp{x};
    x = y;
    y = temp;
}

void stampa_byref(std::string& m) {
    std::cout << m << std::endl;
}

void stampa_byref2(const std::string& m) {
    std::cout << m << std::endl;
}

// R-Value reference
void stampa_byref3(std::string&& m) {
    std::cout << m << std::endl;
}

void references() {
    double pi{3.14};
    double& po{pi};
    std::cout << "pi=" << pi << ", po=" << po << std::endl;
    std::cout << "&pi=" << &pi << ", &po=" << &po << std::endl;
    pi = 3.1415;
    std::cout << "pi=" << pi << ", po=" << po << std::endl;
    po = 3.1;
    std::cout << "pi=" << pi << ", po=" << po << std::endl;

    int a{6};
    int b{11};
    std::cout << "a=" << a << ", b=" << b << std::endl;
    swap_byref(a,b);

    std::cout << "a=" << a << ", b=" << b << std::endl;

    std::string msg{"ciao"};
    stampa_byref(msg);

    // Non posso passare per riferimento un valore temporaneo (R-value)
    // stampa_byref(std::string{"hello"});
    // ma se il riferimento è const posso farlo
    stampa_byref2(std::string{"hello"});

    // Utilizzo dei riferimenti per modificare i dati di un array
    int dati[] { 1,2,3,4,5};
    for(int v : dati) {
        std::cout << v << ",";
    }
    std::cout << std::endl;
    for (int i{0}; i<5; ++i) {
        dati[i] *= 2;
    }
    for(int v : dati) { // "for each"
        std::cout << v << ",";
    }
    std::cout << std::endl;
    for(int& v : dati) {
        v *= 2;
    }
    for(int v : dati) {
        std::cout << v << ",";
    }
    std::cout << std::endl;
    for(auto& v : dati) {
        v *= 2;
    }
    for(auto v : dati) {
        std::cout << v << ",";
    }
    std::cout << std::endl;
}

int main() {
    stack_allocation();
    heap_allocation();
    pointers();
    references();
}
