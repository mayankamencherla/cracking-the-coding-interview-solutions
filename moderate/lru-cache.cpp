/**
 * Implement an LRU cache
 */

#include <iostream>
#include <limits>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

template <class T>
class LRUCache
{
    private:
        /**
         * Size of the cache
         * @param int size
         */
        int size;

        /**
         * List containing the items
         * @param list<T> cache
         */
        list<T> cache;
    public:
        LRUCache(int sz)
        {
            this->size = sz;
        };

        /**
         * Returns whether the cache is full
         * @returns bool
         */
        bool isFull()
        {
            return this->getCapacity() == this->getSize();
        }

        /**
         * Returns whether the cache is empty
         * @returns bool
         */
        bool isEmpty()
        {
            return cache.size() == 0;
        }

        /**
         * Adds an item to the LRU cache
         * @param T item
         * @returns void
         */
        void add(T item)
        {
            if (this->isFull())
            {
                cache.pop_back();
            }

            cache.push_front(item);
        }

        /**
         * Returns recently used element
         * @returns T
         */
        T recentlyUsed()
        {
            if (this->isEmpty()) throw "No elements in the cache";

            return cache.front();
        }

        /**
         * Returns the capacity of the LRU Cache
         * @returns int
         */
        int getCapacity()
        {
            return this->size;
        }

        /**
         * Returns the size of the LRU Cache
         * @returns int
         */
        int getSize()
        {
            return this->cache.size();
        }

        /**
         * Prints the cache from most to least recently used
         * @returns void
         */
        void printCache()
        {
            printf("Printing most to least recently used\n");

            for (typename list<T>::iterator it=cache.begin(); it!=cache.end(); it++)
            {
                cout << *it << " ";
            }

            cout << endl;
        }
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5};

    LRUCache<int> c = LRUCache<int>(4);

    for (int elem : v)
    {
        c.add(elem);

        printf("Most recently added element %d\n", c.recentlyUsed());
    }

    cout << endl;

    c.printCache();
}
