#pragma once
#include <string>

class HasClassName {
public:
    virtual std::string classname() const = 0; // pure virtual method
    void foo()
    {
    }
};

class Employee : public HasClassName {
public:
    Employee(std::string name, std::string
             institute, int nr);
    ~Employee();
    std::string name() const;
    std::string institute() const;
    int employeenr() const;
    std::string classname() const override;
protected:
    std::string m_name;
    std::string m_institute;
    int m_employeenr;
};
