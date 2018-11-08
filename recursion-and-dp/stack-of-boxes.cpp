/**
 * You have a stack of n boxes, (w, h, d)
 * Boxes can be stacked on top of one another
 * A box can be put above another box only if
 * - it is smaller in w, h, d
 * Compute the height of the tallest possible stack
 * where height of the stack is size of the total stack
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Box
{
    private:
        /**
         * Height of the box
         * @param int height
         */
        int height;

        /**
         * Width of the box
         * @param int width
         */
        int width;

        /**
         * Depth of the box
         * @param int depth
         */
        int depth;

    public:
        Box(int h, int w, int d)
        {
            height = h;

            width = w;

            depth = d;
        }

        /**
         * Returns the height of the box
         * @return int
         */
        int getHeight()
        {
            return height;
        }

        /**
         * Returns the width of the box
         * @return int
         */
        int getWidth()
        {
            return width;
        }

        /**
         * Returns the depth of the box
         * @return int
         */
        int getDepth()
        {
            return depth;
        }

        /**
         * Returns whether the other box's width is smaller than this box's width
         * @param Box& other
         * @return bool
         */
        bool canPlaceWidth(Box& other)
        {
            return this->getWidth() >= other.getWidth();
        }

        /**
         * Returns whether the other box's height is smaller than this box's height
         * @param Box& other
         * @return bool
         */
        bool canPlaceHeight(Box& other)
        {
            return this->getHeight() >= other.getHeight();
        }

        /**
         * Returns whether the other box's depth is smaller than this box's depth
         * @param Box& other
         * @return bool
         */
        bool canPlaceDepth(Box& other)
        {
            return this->getDepth() >= other.getDepth();
        }

        /**
         * Returns whether the other box can be placed above this
         * @param Box& other
         * @return bool
         */
        bool canPlaceAbove(Box& other)
        {
            return this->canPlaceWidth(other) && this->canPlaceHeight(other) && this->canPlaceDepth(other);
        }

        /**
         * Prints the dimensions of the box
         */
        void printBox()
        {
            printf("width: %d height: %d depth: %d Box\n", width, height, depth);
        }
};

int getMaxHeightOfStack(vector<Box>& stackOfBoxes, int bottom)
{
    if (bottom >= stackOfBoxes.size()) return 0;

    int maxHeight = stackOfBoxes[bottom].getHeight();

    for (int i = bottom+1; i<stackOfBoxes.size(); i++)
    {
        if (!stackOfBoxes[bottom].canPlaceAbove(stackOfBoxes[i])) continue;

        int height = getMaxHeightOfStack(stackOfBoxes, i);

        maxHeight = max(maxHeight, stackOfBoxes[bottom].getHeight() + height);
    }

    return maxHeight;
}

bool compare(Box& b1, Box& b2)
{
    return b1.getHeight() > b2.getHeight();
}

int main()
{
    int n = 4;

    vector<Box> stackOfBoxes;

    int maxEdge = 100;

    for (int i=0; i<n; i++)
    {
        int h = rand() % maxEdge;

        int w = rand() % maxEdge;

        int d = rand() % maxEdge;

        stackOfBoxes.push_back(Box(h, w, d));
    }

    // We sort the stack of boxes by increasing order of height
    sort(stackOfBoxes.begin(), stackOfBoxes.end(), compare);

    for (Box b : stackOfBoxes) b.printBox();

    printf("The max possible height for the stack of boxes is %d\n", getMaxHeightOfStack(stackOfBoxes, 0));
}
