#include "researcher.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;

Researcher::Researcher(string name, string institute, int nr, string researcharea)
    : m_researcharea{researcharea}
{
    cout << "Costructing Researcher" << endl;
}
Researcher::~Researcher()
{
    cout << "Destroying Researcher" << endl;
}
const string &Researcher::researcharea() const
{
    return m_researcharea;
}
string Researcher::classname() const
{
    return "Researcher";
}
