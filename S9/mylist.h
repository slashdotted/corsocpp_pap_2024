#pragma once
#include <stdexcept>
#include <iostream>

template <typename Tipo>
class MyList {
public:
    explicit MyList(int size);
    MyList(const MyList& o) = delete;
    MyList(const MyList&& o) = delete;
    int& operator=(const MyList& o) = delete;
    int& operator=(const MyList&& o) = delete;
    ~MyList();
    Tipo& operator[](int i);
    const Tipo& operator[](int i) const;
    int size() const;
private:
    Tipo* m_array;
    int m_size;
};

template <typename Tipo>
MyList<Tipo>::MyList(int size)
{
    if (size <= 0) {
        throw std::out_of_range("Invalid size");
    }
    m_array = new Tipo[size];
    m_size = size;
}

template <typename Tipo>
const Tipo& MyList<Tipo>::operator[](int i) const
{
    if (i < 0 || i >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template <typename Tipo>
Tipo& MyList<Tipo>::operator[](int i)
{
    if (i < 0 || i >= m_size) {
        throw std::out_of_range("Invalid index");
    }
    return m_array[i];
}

template <typename Tipo>
int MyList<Tipo>::size() const
{
    return m_size;
}

template <typename Tipo>
MyList<Tipo>::~MyList()
{
    delete[] m_array;
}

