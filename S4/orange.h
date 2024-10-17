#pragma once
#include <string>
#include <iostream>

struct Orange {
    Orange(const std::string name) : m_name{name}
    {
        std::cout << "Creo " << m_name << '\n';
        ++orange_count;
    }

    //Orange(const Orange& o) : m_name{o.m_name} {}

    ~Orange()
    {

        std::cout << "Distruggo " << m_name << '\n';
        --orange_count;
    }

    static unsigned int count()
    {
        return orange_count;
    }

    /*std::string name() const
    {
        return m_name;
    }*/
private:
    std::string m_name;
    static unsigned int orange_count;
};
