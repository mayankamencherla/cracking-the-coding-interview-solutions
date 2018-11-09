/**
 * Write an algorithm to search for an element given a matrix
 * That is sorted row wise and column wise
 */

#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>

using namespace std;

class Coordinate
{
    private:
        int x, y;
    public:
        Coordinate(int cx, int cy)
        {
            x = cx;
            y = cy;
        }

        /**
         * Sets a coordinate containing average of this and other
         */
        void setAverage(Coordinate& other)
        {
            this->x = (this->getX() + other.getX()) / 2;

            this->y = (this->getY() + other.getY()) / 2;
        }

        int getX() { return this->x; }

        int getY() { return this->y; }

        void incrementX() { this->x++; }

        void incrementY() { this->y++; }

        void decrementX() { this->x--; }

        void decrementY() { this->y--; }

        bool isBefore(Coordinate& other)
        {
            return this->getX() <= other.getX() && this->getY() <= other.getY();
        }

        void setX(int xv) { this->x = xv; }

        void setY(int yv) { this->y = yv; }

        Coordinate clone()
        {
            return Coordinate(this->getX(), this->getY());
        }

        bool isNull()
        {
            return (this->getX() == -1) && (this->getY() == -1);
        }
};

Coordinate binarySearch(vector<vector<int>>& v, int search, Coordinate& start, Coordinate& end);

Coordinate partitionAndSearch(vector<vector<int>>& v, int search, Coordinate& topLeft, Coordinate& bottomRight, Coordinate& pivot)
{
    // pivot points to the top left element in the bottom right quadrant
    // search element must be in the BL / TR quadrant
    // TL TR
    // BL BR

    Coordinate topRightOrigin = Coordinate(topLeft.getX(), pivot.getY());

    Coordinate topRightDest = Coordinate(pivot.getX()-1, bottomRight.getY());

    Coordinate bottomLeftOrigin = Coordinate(pivot.getX(), topLeft.getY());

    Coordinate bottomLeftDest = Coordinate(bottomRight.getX(), pivot.getY()-1);

    Coordinate bottomLeft = binarySearch(v, search, bottomLeftOrigin, bottomLeftDest);

    if (bottomLeft.isNull()) return binarySearch(v, search, topRightOrigin, topRightDest);

    return bottomLeft;
}

int getValAt(vector<vector<int>>& v, Coordinate& origin)
{
    return v[origin.getX()][origin.getY()];
}

bool notInBounds(Coordinate& point, vector<vector<int>>& v)
{
    int sx = v.size(); int sy = v[0].size();

    bool inBounds = (point.getX() >= 0 && point.getX() < sx) && (point.getY() >= 0 && point.getY() < sy);

    return !inBounds;
}

Coordinate binarySearch(vector<vector<int>>& v, int search, Coordinate& start, Coordinate& end)
{
    if (notInBounds(start, v) || notInBounds(end, v)) return Coordinate(-1, -1);

    if (!start.isBefore(end)) return Coordinate(-1, -1);

    if (getValAt(v, start) == search) return start;

    Coordinate origin = start.clone(); Coordinate dest = end.clone();

    // Start, end have a diagonal, so go along the diagonal to get 4 quadrants
    Coordinate p = start.clone();

    int diag = min(end.getX() - start.getX(), end.getY() - start.getY());

    end.setX(start.getX() + diag);

    end.setY(start.getY() + diag);

    // Binary search on diagonal to find element x > search
    while (start.isBefore(end))
    {
        p = start.clone();

        p.setAverage(end);

        if (v[p.getX()][p.getY()] < search)
        {
            start = p.clone();

            start.incrementX();

            start.incrementY();
        }
        else
        {
            end = p.clone();

            end.decrementX();

            end.decrementY();
        }
    }

    if (!notInBounds(start, v) && getValAt(v, start) == search) return start;

    return partitionAndSearch(v, search, origin, dest, start);
}

Coordinate binarySearch(vector<vector<int>>& v, int search)
{
    Coordinate start = Coordinate(0, 0);

    Coordinate end = Coordinate(v.size()-1, v[0].size()-1);

    return binarySearch(v, search, start, end);
}

int main()
{
    vector<vector<int>> v = {
        {15, 25, 70,  85 },
        {20, 35, 80,  100},
        {30, 55, 95,  105},
        {40, 90, 120, 125}
    };

    for (int i=0; i<v.size(); i++)
    {
        for (int j=0; j<v[i].size(); j++)
        {
            int search = v[i][j];

            printf("Search for %d located at index (%d, %d)\n", search, i, j);

            Coordinate p = binarySearch(v, search);

            printf("Item found at (%d, %d)\n\n", p.getX(), p.getY());
        }
    }
}
