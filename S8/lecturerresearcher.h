#pragma once
#include <string>
#include "lecturer.h"
#include "researcher.h"

class LecturerResearcher : public Lecturer, public Researcher {
public:
    LecturerResearcher(std::string name, std::string institute, int nr,
                       std::string studies, std::string course,
                       std::string researcharea, double researchpercentage);

    double researchpercentage() const;
    std::string classname() const override;

protected:
    double m_researchpercentage;
};
