#include "animal.h"

using namespace std;

/**
 * This implementation of an animal class
 */

/**
 * Animal class constructor
 *
 * @param string type
 */
Animal::Animal(string type)
{
    this->type = type;
}

/**
 * Returns animal type
 *
 * @param void
 * @return string
 */
string Animal::getType()
{
    return this->type;
}
