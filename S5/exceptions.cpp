#include <iostream>
#include <exception>

void fun()
{
    throw std::out_of_range("Valore non valido");
}

int main()
{
    try {
        fun();
    }
    catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }

    try {
        throw 11;
    }
    catch (int e) {
        std::cout << "Eccezione:" << e << '\n';
    }

}
