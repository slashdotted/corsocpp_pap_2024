#include "mylist.h"

int main()
{
    MyList<int> m{10};
    m[3] = 7;

    MyList<double> b{10};
    b[3] = 3.14;
}
