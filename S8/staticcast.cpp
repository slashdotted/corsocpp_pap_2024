#include <iostream>
#include "lecturerresearcher.h"

int main()
{
    Employee e{"John", "ISIN", 123};
    Lecturer l{"Mark", "ISEA", 555, "Computer Science", "C++"};
    Researcher r{"Alice", "ISEA", 5595, "AI"};
    LecturerResearcher lr{"John", "ISIN", 3565, "CompSci", "ParallelProgramming", "DS", 50.0};

    // Slicing / Conversione di oggetti
    auto el{static_cast<Employee>(l)};
    Employee el2{l};

    // Upcasting
    Employee& er{static_cast<Employee&>(r)};
    Employee& er2{r};

    // Upcasting
    Employee* ep{static_cast<Employee*>(&r)};
    Employee* ep2{&r};

    // Downcasting
    Researcher* lrp{&lr};
    LecturerResearcher* lr2{static_cast<LecturerResearcher*>(lrp)};
    Researcher& lrr{lr};
    LecturerResearcher& lrr2{static_cast<LecturerResearcher&>(lrr)};

    // Non posso fare downcasting con static_cast attraversando una derivazione virtual
    //Researcher* rp{static_cast<Researcher*>(ep)}; // virtual base class

    // Non posso "saltare" tra due rami della gerarchia
    // perché non posso garantire che dietro al puntatore Researcher*
    // c'è un Lecturer
    //Lecturer* lrp_ok{static_cast<Lecturer*>(lrp)};

    // Wrong cast
    Researcher& rr{r};
    LecturerResearcher& lrr3{static_cast<LecturerResearcher&>(rr)};
    std::cout << "% ricerca: " << lrr3.researchpercentage() << std::endl;

    Researcher* rrp{&r};
    LecturerResearcher* lrrp3{static_cast<LecturerResearcher*>(rrp)};
    std::cout << "% ricerca: " << lrrp3->researchpercentage() << std::endl;

    //LecturerResearcher lrrp4{static_cast<LecturerResearcher>(r)};

    void* vp{&r};
    LecturerResearcher* lrrp4{static_cast<LecturerResearcher*>(vp)};
    std::cout << "% ricerca: " << lrrp4->researchpercentage() << std::endl;
}

