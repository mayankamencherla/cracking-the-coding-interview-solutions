/**
 * Implement an LRU cache
 */

#include <iostream>
#include <unordered_map>
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
            return cache.size() == this->size;
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
}
