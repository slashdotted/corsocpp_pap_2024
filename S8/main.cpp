#include "employee.h"
#include "researcher.h"
#include "lecturer.h"
#include "lecturerresearcher.h"
#include <iostream>

using std::cout;

void stampaEmployee(const Employee& e)
{
    cout << "---\n" << "Name: " << e.name() << " Institute: "
         << e.institute() << " Nr.:" <<  e.employeenr()
         << " Class: " << e.classname() << "\n---\n" << '\n';
}

void stampaEmployee(Employee* e)
{
    cout << "---\n" << "Name: " << e->name() << " Institute: "
         << e->institute() << " Nr.:" <<  e->employeenr()
         << " Class: " << e->classname() << "\n---\n" << '\n';
}

void stampaEmployee2(Employee e)
{
    cout << "---\n" << "Name: " << e.name() << " Institute: "
         << e.institute() << " Nr.:" <<  e.employeenr()
         << " Class: " << e.classname() << "\n---\n" << '\n';
}

int main()
{
    Employee e{"Ethan","Santuzzo Research", 1};
    stampaEmployee(&e);

    Researcher r{"Riccardo","Santuzzo Research", 2, "Computer Graphics"};
    stampaEmployee(r);
    cout << " Area: " << r.researcharea()
         << " Class: " << r.classname() << '\n';

    Lecturer l{"Lucia", "Santuzzo Research", 3, "Data Science", "AI"};
    stampaEmployee(&l);
    stampaEmployee2(l); // slicing!!!
    cout << " Studies: " << l.studies() << " Course:" << l.course()
         << " Class: " << l.classname() << '\n';

    LecturerResearcher lr{"Amos", "ISIN", 165,
                          "Computer Science",
                          "Languages and frameworks",
                          "Distributed Systems",
                          10};

    // Upcasting
    Lecturer& llr{lr};
    Researcher& rlr{lr};
    Employee& elr{elr};

    stampaEmployee(&lr);
    stampaEmployee(&l);
    stampaEmployee(&r);

    // Downcasting
    Employee& re{r};
    //Lecturer& l_from_re{re};
    //LecturerResearcher& lr_from_llr{llr};
    //LecturerResearcher& lr_from_rlr{llr};
    //LecturerResearcher& lr_from_elr{elr};

}
