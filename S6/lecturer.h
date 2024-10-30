#pragma once
#include <string>

class Lecturer
{
public:
    Lecturer(std::string name, std::string institute, int nr, std::string studies, std::string course);
    ~Lecturer();
    std::string studies() const;
    std::string course() const;
    std::string classname() const;

protected:
    std::string m_studies;
    std::string m_course;
};
