#pragma once
#include <string>
#include "employee.h"

class Lecturer : public virtual Employee {
public:
    Lecturer(std::string name, std::string institute, int nr, std::string studies, std::string course);
    ~Lecturer();
    std::string studies() const;
    std::string course() const;
    std::string classname() const override;

protected:
    std::string m_studies;
    std::string m_course;
};
