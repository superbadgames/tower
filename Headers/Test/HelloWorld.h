#include "pch.h"
#include "Tower/framework.h"
using namespace Tower;

namespace Tower_Test
{
    class HelloWorld
    {
    public:
        // Constructors
        HelloWorld(void);

        ~HelloWorld(void);

        // Accessors
        // Implemented in a separate file for testing purposes
        void SetName(string name);

        string GetName(void) const;

        // Implemented Inline for testing purposed
        inline void SetAge(U8 age)
        {
            _age = age;
        }

        inline U8 GetAge(void) const
        {
            return _age;
        }

    private:
        string _name;
        U8 _age;
    };
}