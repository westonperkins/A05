#include "Vector.h"
#include <iostream>

void info(CS52::Vector &c)
{
    std::cout << "Size is: " << c.size() << "\n";
    std::cout << "Capacity is: " << c.capacity() << "\n";
    std::cout << "Contents: ";
    for (int i = 0; i < c.size(); i++)
    {
        std::cout << c[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
    std::cout << "HELLO" << std::endl;

    // default constructor, push_back, at methods
    std::cout << "// default constructor, push_back, at \nCS52::Vector a;\n";
    CS52::Vector a;
    std::cout << "\na.push_back(10); a.push_back(88)\n";
    a.push_back(10);
    a.push_back(88);
    std::cout << "a.at(0) = 99;\n";
    a.at(0) = 99;
    info(a);

    // overloaded constructor, [] op, at, empty, clear, exception handling: at
    std::cout << "\n// overloaded constructor, [] op, at, empty, clear, "
                 "exception handling: at \nCS52::Vector b(2,5);\n";
    CS52::Vector b(2, 5);
    std::cout << "b is " << b << "\n";

    // Add more elements to b
    std::cout << "\nb.push_back(10); b.push_back(2);\n";
    std::cout << "b.push_back(99); b.push_back(-5);\n";
    b.push_back(10);
    b.push_back(2);
    b.push_back(99);
    b.push_back(-5);

    // array index [] and at()
    std::cout << "b[0] = 25; b[1] = 1;\n";
    b[0] = 25;
    b[1] = 1;
    std::cout << "b.at(0); b.at(1);\n";
    std::cout << b.at(0) << " " << b.at(1) << "\n";

    // empty method, size, and capacity
    std::cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n";
    std::cout << "b.clear()\n";
    b.clear();
    info(b);
    std::cout << "b.empty() " << (b.empty() ? "True" : "False") << "\n";

    // Exception handling:
    try
    {
        std::cout << "\nb.at(9) = ";
        std::cout << b.at(9);
    }
    catch (std::string msg)
    {
        std::cerr << "\n"
                  << msg << std::endl;
    }

    // copy constructor, copy assignment, pop_back, capacity, size
    std::cout << "\n// copy constructor, copy assignment, pop_back, capacity, "
                 "size\nCS52::Vector c(b);\n";
    b.push_back(11);
    b.push_back(7);
    b.push_back(3);
    b.push_back(23);
    CS52::Vector c(b);
    info(c);

    // copy assignment
    std::cout << "\n// copy assignment\n";
    CS52::Vector d;
    d = c;
    std::cout << "CS52::Vector d = c;\n";
    std::cout << "d is " << d << "\n";

    std::cout << "d.size() is " << d.size() << "\n";
    std::cout << "d.capacity() is " << d.capacity() << "\n";

    // pop_back()
    d.pop_back();
    d.pop_back();
    std::cout << "d.size() is " << d.size() << "\n";
    std::cout << "d.capacity() is " << d.capacity() << "\n";

    // Test overloaded + operator
    CS52::Vector m(5, 3);
    CS52::Vector n(3, 0);
    n[0] = 55;
    n[1] = 100;
    n[2] = 500;
    std::cout << "TEST" << std::endl;
    CS52::Vector o = m + n;
    std::cout << "Test overloaded + operator\n";
    std::cout << "m = [3,3,3,3,3], n = [55,100,500]\n";
    std::cout << "o = m + n = [" << o << "]\n";

    const int SIZE = 2;
    CS52::Container *container[SIZE];
    container[0] = new CS52::Vector(2, 1);
    container[1] = new CS52::Vector(5, 3);

    std::cout << "\nTest polymorphism\n";
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << "container[" << i << "] is a " << container[i]->type() << ": "
                  << *(dynamic_cast<CS52::Vector *>(container[i])) << "\n";
    }

    for (int i = 0; i < SIZE; i++)
    {
        delete container[i];
    }

    char stop;
    std::cin >> stop;
    return 0;
}
