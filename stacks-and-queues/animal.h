#ifndef ANIMAL_HEADER
#define ANIMAL_HEADER

#include <string>

using namespace std;

class Animal
{
    private:
        string type;

    public:
        // default constructor
        Animal(string type);

        string getType();
};

#endif
