#pragma once
#include <string>

class LecturerResearcher
{
public:
    LecturerResearcher(std::string name, std::string institute, int nr,
                       std::string studies, std::string course,
                       std::string researcharea, double researchpercentage);

    double researchpercentage() const;

protected:
    double m_researchpercentage;
};
