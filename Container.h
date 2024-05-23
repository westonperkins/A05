/* Container class Declaration */
#include <string>

namespace CS52 {
    class Container {
    public:
        virtual int size() const = 0;
        virtual int capacity() const = 0;
        virtual std::string type() const = 0;
        virtual ~Container() {}
    };
}
