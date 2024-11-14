#include <iostream>
#include "lecturerresearcher.h"

#ifndef FOO
int main() {}
#else
int main()
{
    Employee e{"John", "ISIN", 123};
    Lecturer l{"Mark", "ISEA", 555, "Computer Science", "C++"};
    Researcher r{"Alice", "ISEA", 5595, "AI"};
    LecturerResearcher lr{"John", "ISIN", 3565, "CompSci", "ParallelProgramming", "DS", 50.0};

    //auto el{dynamic_cast<Employee>(l)};
    Employee el2{l};

    Employee& er{dynamic_cast<Employee&>(r)};
    Employee& er2{r};

    Employee* ep{dynamic_cast<Employee*>(&r)};
    Employee* ep2{&r};

    // dynamic_cast può fare downcasting attraversando una derivazione virtual
    Researcher* rp{dynamic_cast<Researcher*>(ep)}; // virtual base class
    Researcher* lrp{&lr};

    // Cast valido da un puntatore a Researcher (con "collegato" un LecturerResearcher) a
    // puntatore a Lecturer
    Lecturer* lrp_ok{dynamic_cast<Lecturer*>(lrp)};
    if (lrp_ok == nullptr) {
        std::cout << "Cast non valido da Researcher* a Lecturer* (con LecturerResearcher)" << std::endl;
    }

    // Cast NON valido da un puntatore a Researcher (con "collegato" un Researcher) a
    // puntatore a Lecturer
    Lecturer* lrp_wrong{dynamic_cast<Lecturer*>(&r)};
    if (lrp_wrong == nullptr) {
        std::cout << "Cast non valido da Researcher* a Lecturer* (con Researcher)" << std::endl;
    }

    // Cast valido da un riferimento a Researcher (con "collegato" un LecturerResearcher) a
    // riferimento a Lecturer
    Lecturer& rlrp_ok{dynamic_cast<Lecturer&>(lr)};

    try {
        // Cast NON valido da un riferimento a Researcher (con "collegato" un LecturerResearcher) a
        // riferimento a Lecturer
        Lecturer& rlrp_wrong{dynamic_cast<Lecturer&>(r)};
    }
    catch (const std::bad_cast& e) {
        // cast non valido
    }

    // Cast NON valido da un puntatore generico (anche se "collegato" un Researcher) a
    // puntatore a Researcher
    void* vp{&r};
    //Researcher* lrrp4{dynamic_cast<Researcher*>(vp)};


    Bar b;
    Foo* f{&b};
    // Cast NON valido quando la sorgente non è un tipo polimorfico (non ha nessun metodo virtual)
    auto d{dynamic_cast<Bar*>(f)};
}
#endif
