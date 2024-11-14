#include "lecturerresearcher.h"

LecturerResearcher::LecturerResearcher(std::string name,
                                       std::string institute,
                                       int nr,
                                       std::string studies,
                                       std::string course,
                                       std::string researcharea,
                                       double researchpercentage)
    : /* TODO */ m_researchpercentage{researchpercentage}
{}

double LecturerResearcher::researchpercentage() const
{
    return m_researchpercentage;
}
