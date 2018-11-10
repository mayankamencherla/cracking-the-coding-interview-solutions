/**
 * Implement an LRU cache
 */

#include <iostream>
#include <limits>
#include <vector>
#include <unordered_map>
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

        /**
         * Map containing location of cache item
         * @param unordered_map<T, typename list<T>::iterator> hashmap
         */
        unordered_map<T, typename list<T>::iterator> hashmap;
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
                hashmap.erase(cache.back());

                cache.pop_back();
            }

            cache.push_front(item);

            hashmap[item] = cache.begin();
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

        /**
         * Returns whether the item exists in the cache
         * @param T elem
         * @returns bool
         */
        bool itemExists(T elem)
        {
            return hashmap.find(elem) != hashmap.end();
        }

        /**
         * Returns an item in the cache
         * @param T elem
         * @returns T
         */
        T get(T elem)
        {
            if (!this->itemExists(elem)) throw "Item does not exist in the cache";

            auto it = hashmap.find(elem);

            cache.erase(it->second);

            cache.push_front(elem);

            hashmap[elem] = cache.begin();

            return elem;
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

    c.get(3);

    cout << endl;

    c.printCache();

    cout << endl;

    c.get(5);

    cout << endl;

    c.printCache();
}
