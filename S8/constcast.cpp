#include <map>

struct Calcolatore {
    // TODO: Aggiungere "cache" dei valori già calcolati

    unsigned long fattoriale(unsigned long n) const
    {
        auto it{m_cache.find(n)};
        if (it == m_cache.end()) {
            unsigned long r = 1;
            for(unsigned long  i=n; i>1; --i) {
                r = r*i;
            }
            // this : const Calcolatore*
            auto self{const_cast<Calcolatore*>(this)};
            self->m_cache[n] = r;
            return r;
        }
        else {
            return it->second;
        }
    }

private:
    std::map<unsigned long,unsigned long> m_cache;
};

void fun(const Calcolatore& c)
{
    c.fattoriale(88);
    c.fattoriale(20);
}


int main()
{
    Calcolatore c1;
    fun(c1);
}

