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

    auto el{static_cast<Employee>(l)};
    Employee el2{l};

    Employee& er{static_cast<Employee&>(r)};
    Employee& er2{r};

    Employee* ep{static_cast<Employee*>(&r)};
    Employee* ep2{&r};

    // Non posso fare downcasting con static_cast attraversando una derivazione virtual
    //Researcher* rp{static_cast<Researcher*>(ep)}; // virtual base class

    Researcher* lrp{&lr};
    // Non posso "saltare" tra due rami della gerarchia
    //Lecturer* lrp_ok{static_cast<Lecturer*>(lrp)};

    LecturerResearcher* lr2{static_cast<LecturerResearcher*>(lrp)};
    Researcher& lrr{lr};
    LecturerResearcher& lrr2{static_cast<LecturerResearcher&>(lrr)};

    // Wrong cast
    Researcher& rr{r};
    LecturerResearcher& lrr3{static_cast<LecturerResearcher&>(rr)};

    Researcher* rrp{&r};
    LecturerResearcher* lrrp3{static_cast<LecturerResearcher*>(rrp)};

    //LecturerResearcher lrrp4{static_cast<LecturerResearcher>(r)};

    void* vp{&r};
    LecturerResearcher* lrrp4{static_cast<LecturerResearcher*>(vp)};

    Bar b;
    Foo* f{&b};
    auto d{static_cast<Bar*>(f)};
}
#endif
