#pragma once
#include <string>

struct Researcher
{
public:
    Researcher(std::string name, std::string institute, int nr, std::string researcharea);
    ~Researcher();
    const std::string &researcharea() const;
    std::string classname() const;

protected:
    std::string m_researcharea;
};
