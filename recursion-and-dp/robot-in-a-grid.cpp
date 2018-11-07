/**
 * Given a grid with (r, c) cells, and a robot starting in (0, 0)
 * Have the robot move from there to (r-1, c-1) by moving right, down
 * Some cells are off limits and are blocked
 */

#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Grid
{
    private:
        vector<vector<int>> grid;
        int rows;
        int cols;
    public:
        Grid(int r, int c)
        {
            this->rows = r;
            this->cols = c;

            grid.resize(r, vector<int>(c, 0));
        }

        int getContentAt(int i, int j)
        {
            return grid[i][j];
        }

        void AddBlockers(vector<vector<int>>& blockers)
        {
            for (vector<int> b : blockers)
            {
                // -1 signals that there exists a blocker at (i, j)
                this->addBlocker(b[0], b[1]);
            }
        }

        void addBlocker(int x, int y)
        {
            grid[x][y] = -1;
        }

        bool isLastCell(int i, int j)
        {
            return (this->rows == i+1) && (this->cols == j+1);
        }

        void printGrid()
        {
            for (vector<int> v : grid)
            {
                for (int elem : v)
                {
                    cout << elem << " ";
                }

                cout << endl;
            }
        }

        bool isBlocked(int i, int j)
        {
            return this->getContentAt(i, j) == -1;
        }

        void generateBlockers(int n)
        {
            while (n > 0)
            {
                int i = rand() % this->rows;

                int j = rand() % this->cols;

                if (!this->isBlocked(i, j))
                {
                    this->addBlocker(i, j);

                    n--;
                }
            }
        }

        bool isValid(int i, int j)
        {
            bool valid = (i >= 0 && i < this->rows) && (j >= 0 && j < this->cols);

            return valid && !this->isBlocked(i, j);
        }
};

class Point
{
    private:
        int x, y;

    public:
        Point(int i, int j)
        {
            this->x = i;

            this->y = j;
        }

        void print()
        {
            cout << this->x << " " << this->y << endl;
        }
};

unordered_map<string, bool> hashmap;

bool getPathToEnd(Grid& g, int currX, int currY, vector<Point>& points)
{
    if (!g.isValid(currX, currY)) return false;

    string key = to_string(currX) + '-' + to_string(currY);

    if (hashmap.find(key) != hashmap.end()) return hashmap[key];

    if (g.isLastCell(currX, currY))
    {
        points.insert(points.begin(), Point(currX, currY));

        return true;
    }

    bool success = false;

    if (getPathToEnd(g, currX+1, currY, points)) success = true;

    else if (getPathToEnd(g, currX, currY+1, points)) success = true;

    hashmap[key] = success;

    // If we cannot reach the end point from (currX, currY), we remove the point
    if (success) points.insert(points.begin(), Point(currX, currY));

    return success;
}

int main()
{
    Grid g = Grid(6, 6);

    g.generateBlockers(5);

    g.printGrid();

    int robX = 0; int robY = 0;

    vector<Point> points;

    bool success = getPathToEnd(g, robX, robY, points);

    cout << endl;

    if (success)
    {
        for (Point p : points)
        {
            p.print();
        }
    }
}

