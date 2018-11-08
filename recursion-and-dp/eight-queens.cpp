/**
 * Given 8 queens, place them on a 8x8 grid
 * None of them should share the same row, col and diagonal
 */

#include <vector>
#include <iostream>

using namespace std;

class Grid
{
    private:
        /**
         * Rows of the grid
         *
         * @param vector<int> rows
         */
        vector<int> rows;

        /**
         * Cols of the grid
         *
         * @param vector<int> cols
         */
        vector<int> cols;

    public:

        /**
         * Constructor of the grid
         *
         * @param int r
         * @param int c
         */
        Grid(int r, int c)
        {
            rows.resize(r, -1);

            cols.resize(c, -1);
        }

        /**
         * Returns whether the column at y has queen
         *
         * @param int y
         * @return bool
         */
        bool colHasQueen(int y)
        {
            if (!this->pointInGrid(0, y)) return false;

            return cols[y] > 0;
        }

        /**
         * Returns whether the row at x has queen
         *
         * @param int x
         * @return bool
         */
        bool rowHasQueen(int x)
        {
            if (!this->pointInGrid(x, 0)) return false;

            return rows[x] > 0;
        }

        /**
         * Returns whether the color at x, y, has queen
         *
         * @param int x
         * @param int y
         * @return bool
         */
        bool hasQueen(int x, int y)
        {
            return (rows[x] == y) && (cols[y] == x);
        }

        /**
         * Returns whether the location is in the grid
         *
         * @param int x
         * @param int y
         * @return bool
         */
        bool pointInGrid(int x, int y)
        {
            return (x >= 0 && x < rows.size()) && (y >= 0 && y < cols.size());
        }

        /**
         * Fills the location with the given color
         *
         * @param int x
         * @param int y
         * @return void
         */
        void colorPoint(int x, int y)
        {
            rows[x] = y;

            cols[y] = x;
        }

        /**
         * Uncolors the location with the white color
         *
         * @param int x
         * @param int y
         * @return void
         */
        void uncolorPoint(int x, int y)
        {
            rows[x] = -1;

            cols[y] = -1;
        }

        /**
         * Method to check if row in grid
         *
         * @param int x
         * @return bool
         */
        bool isRowInGrid(int x)
        {
            return this->pointInGrid(x, 0);
        }

        /**
         * Prints the entire grid
         */
        void printGrid()
        {
            cout << endl;

            for (int row = 0; row < rows.size(); row++)
            {
                for (int col = 0; col < cols.size(); col++)
                {
                    int val = this->hasQueen(row, col);

                    cout << val << " ";
                }

                cout << endl;
            }
        }

        /**
         * Returns the number of columns
         * @return int col
         */
        int getNumCols()
        {
            return cols.size();
        }

        /**
         * Returns whether given row and col can be filled with a color
         *
         * @param int row
         * @param int col
         * @return bool
         */
        bool canFillWithQueen(int row, int col)
        {
            // All rows from [rows.size()-1, row+1] cannot have a queen in column col
            if (this->colHasQueen(col)) return false;

            // We are placing only 1 queen per row, so no need to check all columns in a row

            // Check left diagonal from [rows.size()-1, row+1] in reverse order
            // This is because we have already placed queens in locations until row
            int r = row+1; int c = col-1;

            while (this->pointInGrid(r, c))
            {
                if (this->hasQueen(r, c)) return false;

                r++;

                c--;
            }

            // Check right diagonal from [rows.size()-1, row+1] in reverse order
            // This is because we have already placed queens in locations until row
            r = row+1; c = col+1;

            while (this->pointInGrid(r, c))
            {
                if (this->hasQueen(r, c)) return false;

                r++;

                c++;
            }

            return true;
        }
};

/**
 * Recursively fill all rows from [0, rows.size()-1]
 */
int numWaysToFillWithQueens(Grid& g, int row)
{
    // We found a way to fill the grid, as all rows are filled
    if (row < 0)
    {
        g.printGrid();

        return 1;
    }

    int ways = 0;

    for (int col=0; col<g.getNumCols(); col++)
    {
        if (!g.canFillWithQueen(row, col)) continue;

        g.colorPoint(row, col);

        ways += numWaysToFillWithQueens(g, row-1);

        g.uncolorPoint(row, col);
    }

    return ways;
}

int main()
{
    int n = 5;

    Grid g = Grid(n, n);

    g.printGrid();

    printf("The number of ways to fill a %dby%d grid with queens is %d\n", n, n, numWaysToFillWithQueens(g, n-1));
}
