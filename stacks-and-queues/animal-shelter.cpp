#include <queue>
#include "animal.cpp"
#include <limits>
#include <iostream>

using namespace std;

/**
 * The animal shelter operates in FIFO basis (Queue)
 * People must adopt an animal that is oldest in terms of arrival time
 * Or they can select an dog/cat and choose the oldest in terms of arrival time
 */

class AnimalShelter
{
    private:
        queue<Animal> dogs;
        queue<Animal> cats;
        int size;

    public:
        AnimalShelter()
        {
            size = 0;
        }

        /**
         * Creates an AnimalShelter with a list of animals
         *
         * @param vector<string>& animals
         */
        AnimalShelter(vector<string>& animals)
        {
            size = 0;

            this->insert(animals);
        }

        /**
         * Insert a group of animals into the shelter
         *
         * @param vector<string>& animals
         * @return void
         */
        void insert(vector<string>& animals)
        {
            for (string animal : animals)
            {
                this->insert(animal);
            }
        }

        /**
         * Returns whether an animal is a dog
         *
         * @param Animal animal
         * @return bool
         */
        bool isDog(Animal animal)
        {
            return animal.getType() == "dog";
        }

        /**
         * Returns whether an animal is a dog
         *
         * @param string animal
         * @return bool
         */
        bool isDog(string animal)
        {
            return animal == "dog";
        }

        /**
         * Returns whether an animal is a cat
         *
         * @param string animal
         * @return bool
         */
        bool isCat(string animal)
        {
            return animal == "cat";
        }

        /**
         * Insert an element into the shelter
         *
         * @param string animal
         * @return void
         */
        void insert(string animal)
        {
            if (isDog(animal))
            {
                dogs.push(Animal(animal, size));
            }
            else if (isCat(animal))
            {
                cats.push(Animal(animal, size));
            }
            else
            {
                throw "Invalid animal type";
            }

            size++;
        }

        /**
         * Returns the most recently added Cat in the animal shelter
         *
         * @return Animal
         */
        Animal topCat()
        {
            if (cats.empty()) throw "No cats in the shelter";

            return cats.front();
        }

        /**
         * Returns the most recently added Dog in the animal shelter
         *
         * @return Animal
         */
        Animal topDog()
        {
            if (dogs.empty()) throw "No dogs in the shelter";

            return dogs.front();
        }

        /**
         * Removes the most recently added Cat in the animal shelter
         *
         * @return Animal
         */
        Animal popCat()
        {
            if (cats.empty()) throw "No cats in the shelter";

            Animal c = topCat();

            cats.pop();

            size--;

            return c;
        }

        /**
         * Removes the most recently added Dog in the animal shelter
         *
         * @return Animal
         */
        Animal popDog()
        {
            if (dogs.empty()) throw "No dogs in the shelter";

            Animal d = topDog();

            dogs.pop();

            size--;

            return d;
        }

        /**
         * Returns the most recently added Animal in the animal shelter
         *
         * @return Animal
         */
        Animal topAnimal()
        {
            Animal d = dogs.front();

            Animal c = cats.front();

            if (d.isOlderThan(c)) return d;

            return c;
        }

        /**
         * Removes the most recently added Animal in the animal shelter
         *
         * @return Animal
         */
        Animal popAnimal()
        {
            Animal d = dogs.front();

            Animal c = cats.front();

            size--;

            // In case the cat was added in before the dog, return the cat
            if (c.isOlderThan(d))
            {
                cats.pop();

                return c;
            }

            dogs.pop();

            return d;
        }

        /**
         * Returns whether there are no dogs in the shelter
         *
         * @return bool
         */
        bool dogsEmpty()
        {
            return dogs.empty();
        }

        /**
         * Returns whether there are no cats in the shelter
         *
         * @return bool
         */
        bool catsEmpty()
        {
            return cats.empty();
        }

        /**
         * Removes the most recently added element in the animal shelter
         *
         * @return Animal
         */
        Animal pop()
        {
            if (this->isEmpty()) throw "No animals in the shelter";

            if (this->dogsEmpty()) return popCat();

            else if (this->catsEmpty()) return popDog();

            return popAnimal();
        }

        /**
         * Returns the most recently added animal in the shelter
         *
         * @return Animal
         */
        Animal top()
        {
            if (this->isEmpty()) throw "No animals in the shelter";

            else if (this->dogsEmpty()) return topCat();

            else if (this->catsEmpty()) return topDog();

            return topAnimal();
        }

        /**
         * Return if the size of stack is empty
         *
         * @return bool
         */
        bool isEmpty()
        {
            return (cats.empty()) && (dogs.empty());
        }

        /**
         * Returns the number of elements in the stack
         *
         * @return int
         */
        int numElems()
        {
            return size;
        }

        /**
         * Prints all the animals in the shelter
         *
         * @return void
         */
        void printShelter()
        {
            // TODO
            return;
        }
};

int main()
{
    vector<string> v = {"dog", "cat", "cat", "cat", "dog"};

    for (string elem : v) cout << elem << " ";

    cout << endl;

    AnimalShelter as = AnimalShelter(v);

    cout << "Size of the stack " << as.numElems() << endl;

    cout << "Popping the stack with " << as.popCat().getType() << endl;

    cout << "Popping the stack " << as.pop().getType() << endl;

    cout << "Popping the stack " << as.pop().getType() << endl;

    cout << "Size of the stack " << as.numElems() << endl;

    cout << "Popping the stack with " << as.popDog().getType() << endl;

    cout << "Popping the stack " << as.pop().getType() << endl;

    cout << "Is the stack empty " << as.isEmpty() << endl;

    cout << "Size of the stack " << as.numElems() << endl;
}
