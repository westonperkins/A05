#include <iostream>
#include "Container.h"

namespace CS52 {
    class Vector : public Container {
    public:
        Vector(); // Default constructor
        Vector(int size, int int_val); // Overloaded constructor
        Vector(const Vector&); // Copy constructor
        ~Vector(); // Destructor

        // Returns a reference to the element at index i
        // throws a string if i is out-of-bounds.
        int& at(int i) const;

        // Erases the elements of the Vector but does not change capacity.
        void clear();

        // Returns pointer to the first element in the Vector.
        int* data() const;

        // If Vector is empty return true, else false.
        bool empty() const;

        // Deletes the element at the end of the Vector.
        void pop_back();

        // Add an element to the end of the Vector.
        void push_back(int element);

        // Returns the number of elements in the Vector.
        int size() const override;

        // Returns the allocated storage for the Container.
        int capacity() const override;

        // Returns the type name "Vector"
        std::string type() const override;

        // Overloaded operators
        int& operator[](int index); // [] array syntax
        Vector& operator=(const Vector&); // copy assignment

        // overloaded + operator to add two Vectors
        Vector operator+(const Vector& rhs);

        // Overloaded stream insertion operator
        friend std::ostream& operator<<(std::ostream& output_stream, const Vector& vector);

    private:
        int _size = 0;
        int _capacity = 0;
        int* _data = nullptr;
    };
}
