#include "employee.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;


Employee::Employee(string name, string institute,
                   int nr)
    : m_name{name}, m_institute{institute},
      m_employeenr{nr}
{
    cout << "Constructing Employee " << m_name << endl;
}

Employee::~Employee()
{
    cout << "Destroying Employee " << m_name << endl;
}

string Employee::name() const
{
    return m_name;
}

string Employee::institute() const
{
    return m_institute;
}

int Employee::employeenr() const
{
    return m_employeenr;
}

string Employee::classname() const
{
    return "Employee";
}
