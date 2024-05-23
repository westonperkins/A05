// Weston Perkins
// CS52
// 1669
// 1934744
// 5/23/24
// Build an integer Vector class defined in namespace CS52 that has similar behavior to std::vector

#include "Vector.h"

// Define the CS52 namespace, same as the namepsace in Vector.h, and container.h
namespace CS52
{

    // Define constructor 'Vector' to 'Vector' class
    Vector::Vector() : _size(0), _capacity(0), _data(nullptr) {}

    // Create overloaded constructor which initializes a vector with a given size and fills it with the specified initial value
    // overloaded constructors allow you to create multiple constructors for a class, each with different parameters. This provides flexibility to initialize objects in different ways.
    Vector::Vector(int size, int initial_val) : _size(size), _capacity(size)
    {
        // new keyword always assigns a pointer to the allocated memory
        // allocated memory for a new data array to store elements of the new vector
        _data = new int[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            _data[i] = initial_val;
        }
    }

    // Third constructor that nitializes a vector as a copy of another vector
    // const keyword indicates that the function will not modify the argument passed to it
    Vector::Vector(const Vector &copied) : _size(copied._size), _capacity(copied._capacity)
    {
        _data = new int[_capacity];
        for (int i = 0; i < _size; ++i)
        {
            _data[i] = copied._data[i];
        }
    }

    // Destructor
    Vector::~Vector()
    {
        delete[] _data;
    }

    // Returns a reference to the element at index i
    int &Vector::at(int i) const
    {
        if (i >= _size || i < 0)
        {
            throw std::string("Index out of range");
        }
        return _data[i];
    }

    // Erases the elements of the Vector but does not change capacity.
    void Vector::clear()
    {
        _size = 0;
    }

    // Returns pointer to the first element in the vector.
    int *Vector::data() const
    {
        return _data;
    }

    // If Vector is empty return true, if not return false.
    bool Vector::empty() const
    {
        return _size == 0;
    }

    // Deletes the element at the end of the vector.
    void Vector::pop_back()
    {
        if (_size > 0)
        {
            // Decrement the size by 1
            --_size;
        }
    }

    // Add an element to the end of the vector.
    void Vector::push_back(int element)
    {
        if (_size == _capacity)
        {
            int newCap = (_capacity > 0) ? (_capacity * 2) : 1;
            int *newData = new int[newCap];
            for (int i = 0; i < _size; ++i)
            {
                newData[i] = _data[i];
            }
            delete[] _data;
            _data = newData;
            _capacity = newCap;
        }
        _data[_size++] = element;
    }

    // Returns the number of elements in the vector.
    int Vector::size() const
    {
        return _size;
    }

    // Returns the allocated storage for the container.
    int Vector::capacity() const
    {
        return _capacity;
    }

    // Returns the type name "vector"
    std::string Vector::type() const
    {
        return "CS52::Vector";
    }

    // Returns a reference to the element at the specified index
    // 'operator[]' = overloading the subscript operator '[]' - operator is a keyword
    // establishing the operator[] on the Vector class, you are able to use use this class like a normal vector, accessing data at an index with the subscript notation
    int &Vector::operator[](int index)
    {
        return _data[index];
    }

    // Assigns the contents of the copied vector to this vector
    // allows you to assign one vector object to another vector object
    Vector &Vector::operator=(const Vector &copied)
    {
        if (this != &copied)
        {
            delete[] _data;
            _size = copied._size;
            _capacity = copied._capacity;
            _data = new int[_capacity];
            for (int i = 0; i < _size; ++i)
            {
                _data[i] = copied._data[i];
            }
        }
        return *this;
    }

    // Adds corresponding elements of two vectors and returns a new vector
    // allows for the use of the + operator between vector elements
    Vector Vector::operator+(const Vector &vector)
    {
        int new_size = _size < vector._size ? _size : vector._size;
        Vector result(new_size, 0);
        for (int i = 0; i < new_size; ++i)
        {
            result._data[i] = _data[i] + vector._data[i];
        }
        return result;
    }

    // Outputs the elements of the vector to the given output stream
    // allows the use of the overloaded insertion (<<) operator
    std::ostream &operator<<(std::ostream &output_stream, const Vector &vector)
    {
        for (int i = 0; i < vector.size(); ++i)
        {
            output_stream << vector.at(i);
            if (i < vector.size() - 1)
            {
                output_stream << " ";
            }
        }
        return output_stream;
    }

}
