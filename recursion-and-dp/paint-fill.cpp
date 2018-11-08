/**
 * Given a string, compute all permutations of the string
 * The string has only unique characters
 */

#include <vector>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

enum Color {white, black, brown, yellow};

class Grid
{
    private:
        /**
         * This 2D grid
         *
         * @param vector<vector<Color>> grid
         */
        vector<vector<Color>> grid;

        /**
         * Number of rows in the grid
         *
         * @param int rows
         */
        int rows;

        /**
         * Number of cols in the grid
         *
         * @param int cols
         */
        int cols;

    public:

        /**
         * Constructor of the grid
         *
         * @param int r
         * @param int c
         */
        Grid(int r, int c)
        {
            rows = r;

            cols = c;

            Color w = white;

            grid.resize(r, vector<Color>(c, w));
        }

        /**
         * Randomly generates colors for the grid
         *
         * @return void
         */
        void generateColors()
        {
            for (int r=0; r<rows; r++)
            {
                for (int c=0; c<cols; c++)
                {
                    int color = rand() % 4;

                    Color colorObj;

                    switch (color)
                    {
                        case 0:
                            colorObj = white;
                            break;

                        case 1:
                            colorObj = black;
                            break;

                        case 2:
                            colorObj = brown;
                            break;

                        default:
                            colorObj = yellow;
                            break;
                    }

                    grid[r][c] = colorObj;
                }
            }
        }

        /**
         * Prints the grid
         *
         * @return void
         */
        void printGrid()
        {
            for (int r=0; r<rows; r++)
            {
                for (int c=0; c<cols; c++)
                {
                    Color color = grid[r][c];

                    int val = 0;

                    switch (color)
                    {
                        case white:
                            val = 0;
                            break;

                        case black:
                            val = 1;
                            break;

                        case brown:
                            val = 2;
                            break;

                        default:
                            val = 3;
                            break;
                    }

                    cout << val << " ";
                }

                cout << endl;
            }
        }

        /**
         * Returns the color at location
         *
         * @param int x
         * @param int y
         * @return Color
         */
        Color getColorAt(int x, int y)
        {
            return grid[x][y];
        }

        /**
         * Returns whether the color at x, y, is equal to the given color
         *
         * @param int x
         * @param int y
         * @param Color color
         * @return bool
         */
        bool isColorEqualTo(int x, int y, Color color)
        {
            return this->getColorAt(x, y) == color;
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
            return (x >= 0 && x < rows) && (y >= 0 && y < cols);
        }

        /**
         * Fills the location with the given color
         *
         * @param int x
         * @param int y
         * @param Color fill
         * @return void
         */
        void colorPoint(int x, int y, Color fill)
        {
            grid[x][y] = fill;
        }

        /**
         * Replaces the given location as well as all the neighbouring indices with the given color
         * We are using a Depth-First-Search algorithm in this case
         *
         * @param int x
         * @param int y
         * @param Color replace
         * @param Color fill
         * @return void
         */
        void paintFill(int x, int y, Color replace, Color fill)
        {
            if (!pointInGrid(x, y) || !isColorEqualTo(x, y, replace)) return;

            colorPoint(x, y, fill);

            paintFill(x-1, y, replace, fill);

            paintFill(x+1, y, replace, fill);

            paintFill(x, y-1, replace, fill);

            paintFill(x, y+1, replace, fill);
        }
};

int main()
{
    Grid g = Grid(10, 10);

    g.generateColors();

    printf("Printing grid after coloring the grid \n\n");

    g.printGrid();

    cout << endl;

    Color fill = black;

    Color replace = white;

    g.paintFill(4, 4, replace, fill);

    printf("Printing grid after re-coloring the grid with blacks \n\n");

    g.printGrid();

    fill = yellow;

    g.paintFill(8, 1, replace, fill);

    printf("Printing grid after re-coloring the grid with yellows \n\n");

    g.printGrid();
}
