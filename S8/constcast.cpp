struct Calcolatore {
    unsigned long fattoriale(unsigned long n) const
    {
        unsigned long r = 1;
        for(unsigned long  i=n; i>1; --i) {
            r = r*i;
        }
        return r;
    }
};

int main()
{
    Calcolatore c1;
    c1.fattoriale(88);
}

