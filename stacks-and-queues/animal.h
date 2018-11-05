#ifndef ANIMAL_HEADER
#define ANIMAL_HEADER

#include <string>

using namespace std;

class Animal
{
    private:
        string type;
        int index;

    public:
        // default constructor
        Animal(string type, int index);

        string getType();

        int getIndex();

        bool isOlderThan(Animal& other);
};

#endif
