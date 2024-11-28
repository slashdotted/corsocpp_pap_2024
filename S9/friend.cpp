#include <iostream>

struct Dato {
public:
    Dato(int id, int rev) : m_id{id}, m_revision{rev} {}

    int id() const
    {
        return m_id;
    }

    void id(int v)
    {
        m_id = v;
        ++m_revision;
    }

    bool checkRevision(int i) const
    {
        return m_revision >= i;
    }

    friend struct Serializer;
    friend void debug(const Dato&);
    friend std::ostream& operator<<(std::ostream&,const Dato&);

private:
    int m_id;
    int m_revision;
};

struct Serializer {
    void serializza(const Dato& d)
    {
        std::cout << d.m_revision;
    }
};

void debug(const Dato& d)
{
    std::cout << d.m_revision;
}

std::ostream& operator<<(std::ostream& o,const Dato& d)
{
    o << d.m_id << "," << d.m_revision;
    return o;
}


int main()
{
    Dato d{1,0};
    Dato e{1,1};
    std::cout << d.checkRevision(2);
}
