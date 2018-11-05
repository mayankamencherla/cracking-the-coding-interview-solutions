#include "animal.h"

using namespace std;

/**
 * This implementation of an animal class
 */

/**
 * Animal class constructor
 *
 * @param string type
 * @param int index
 */
Animal::Animal(string type, int index)
{
    this->type = type;

    this->index = index;
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

/**
 * Returns animal index
 *
 * @param void
 * @return int
 */
int Animal::getIndex()
{
    return this->index;
}

/**
 * Returns whether this animal is older than other
 * This animal is older if its index is lower,
 * as that would imply that the animal was inserted sooner
 *
 * @param Animal& other
 * @return bool
 */
bool Animal::isOlderThan(Animal& other)
{
    return this->index < other.getIndex();
}
