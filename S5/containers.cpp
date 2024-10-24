#include <iostream>
#include <vector>
#include <list>
#include <map>

struct Foo {
    Foo() {}
    Foo(const Foo&)
    {
        std::cout << "Copia\n";
    }
    ~Foo()
    {
        std::cout << "~Foo()\n";
    }
};

void print_vector(const std::vector<double>& v)
{
    for(unsigned int i{0}; i<v.size(); ++i) {
        std::cout << v.at(i) << '\n';
        std::cout << v[i] << '\n';
    }
}


void vector_examples()
{
    {
        std::vector<double> v{1.3,7,3.14,0,-5};
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(6.7);
        v.push_back(2);
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
    }
    {
        std::vector<double> v;
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(1);
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(2);
        v.push_back(3);
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        for(unsigned int i{0}; i<v.size(); ++i) {
            std::cout << v.at(i) << '\n';
            std::cout << v[i] << '\n';
        }
        v.erase(v.begin() + 1);
        auto it{v.begin() + 2};
        std::cout << *it << '\n';
        print_vector(v);
    }
    {
        std::vector<Foo> v;
        v.reserve(4);
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(Foo{});
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(Foo{});
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(Foo{});
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(Foo{});
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
    }
    {
        std::vector<Foo*> v;
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(new Foo);
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(new Foo);
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(new Foo);
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        v.push_back(new Foo);
        std::cout << "Size: " << v.size() << '\n';
        std::cout << "Capacity: " << v.capacity() << '\n';
        for(const auto& a : v) {
            delete a;
        }
        v.clear();
    }
}

void list_examples()
{
    std::list<int> l{1,2,3,4,5};
    for (const auto& e : l) {
        std::cout << e << '\n';
    }
    l.push_back(6);
    l.push_front(0);
    for (const auto& e : l) {
        std::cout << e << '\n';
    }
    auto it{l.begin()};
    std::advance(it, 2);
    l.erase(it);
    for (const auto& e : l) {
        std::cout << e << '\n';
    }
    std::cout << "Size: " << l.size() << '\n';
    l.pop_back();
    l.pop_front();
    for (const auto& e : l) {
        std::cout << e << '\n';
    }
}

void map_examples()
{
    std::map<std::string,double> tassi{{"CHF", 1.0},{"EUR", 0.98}};
    tassi.insert({"USD", 0.92});
    tassi["GBP"] = 1.12;
    if (tassi.count("GBP") == 1) {
        std::cout << tassi["GBP"] << '\n';
    }
    tassi["JPY"] = 0.0057;
    auto it{tassi.find("JPY")};
    if (it != tassi.end()) {
        std::cout << it->first << ": " << it->second << '\n';
        tassi.erase(it);
    }
}

int main()
{
    vector_examples();
    list_examples();
    map_examples();
}
