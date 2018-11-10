/**
 * Given 2 line segments, represented by (start, end)
 * Find a point of intersection, if any
 */

#include <iostream>
#include <limits>

using namespace std;

class Point
{
    private:
        /**
         * (x, y) representing point in the 2D space
         * @param double x
         * @param double y
         */
        double x, y;

    public:
        Point() {}

        Point(double px, double py)
        {
            x = px;
            y = py;
        }

        /**
         * Returns the x-coordinate
         * @returns double
         */
        double getX() { return x; }

        /**
         * Returns the y-coordinate
         * @returns double
         */
        double getY() { return y; }

        /**
         * Returns whether the point is an empty point
         * @returns bool
         */
        bool isNull()
        {
            return (this->getX() == numeric_limits<double>::max()) &&
                   (this->getY() == numeric_limits<double>::max());
        }

        /**
         * Prints the point in (x, y) format
         * @returns void
         */
        void printPoint()
        {
            printf("The point is (x, y) = (%f, %f)\n", this->getX(), this->getY());
        }
};

class Line
{
    private:
        /**
         * (start, end) representing line in the 2D space
         * @param Point start
         * @param Point end
         */
        Point start, end;

        /**
         * Slope of the line
         * @param double slope
         */
        double slope;

        /**
         * Intercept of the line
         * @param double intercept
         */
        double intercept;

    public:
        Line() {}

        /**
         * Constructor for the line object
         * @param Point& start
         * @param Point& end
         */
        Line(Point& start, Point& end)
        {
            this->start = start;

            this->end = end;

            computeSlope();

            computeIntercept();
        }

        /**
         * Constructor for the line object
         * @param double sx
         * @param double sy
         * @param double ex
         * @param double ey
         */
        Line(double sx, double sy, double ex, double ey)
        {
            this->start = Point(sx, sy);

            this->end = Point(ex, ey);

            computeSlope();

            computeIntercept();
        }

        /**
         * Returns the slope of the line
         * @returns double
         */
        double getSlope()
        {
            return this->slope;
        }

        /**
         * Computes the slope of the line
         * @returns void
         */
        void computeSlope()
        {
            double diffY = end.getY() - start.getY();

            double diffX = end.getX() - start.getX();

            this->slope = diffY / diffX;
        }

        /**
         * Returns the intercept of the line
         * @returns double
         */
        double getIntercept()
        {
            return this->intercept;
        }

        /**
         * Computes the intercept of the line
         * @returns void
         */
        void computeIntercept()
        {
            this->intercept = start.getY() - this->getSlope() * start.getX();
        }

        /**
         * Returns an empty point
         * @returns Point
         */
        Point emptyPoint()
        {
            return Point(numeric_limits<double>::max(), numeric_limits<double>::max());
        }

        /**
         * Computes the line's intersection with the other line
         * @param Line& other
         * @returns Point
         */
        Point computeIntersection(Line& other)
        {
            // Parallel lines do not intersect
            if (this->getSlope() == other.getSlope()) return emptyPoint();

            // y = m1x + c1 and y = m2x + c2
            double x = (other.getIntercept() - this->getIntercept()) / (this->getSlope() - other.getSlope());

            double y = (this->getSlope() * x) + this->getIntercept();

            return Point(x, y);
        }

        /**
         * Prints line in the form y = mx + c
         * @returns void
         */
        void printLine()
        {
            printf("y = %fx + %f\n\n", this->getSlope(), this->getIntercept());
        }
};

int main()
{
    // Parallel lines

    Line l1 = Line(1, 2, 3, 5);

    Line l2 = Line(2, 5, 4, 8);

    l1.printLine(); l2.printLine();

    Point intersection = l1.computeIntersection(l2);

    printf("Do the 2 parallel lines intersect? %s\n\n", intersection.isNull() ? "False" : "True");

    // Non parallel lines

    l1 = Line(1, 2, 3, 5);

    l2 = Line(3, 3, 4, 9);

    l1.printLine(); l2.printLine();

    intersection = l1.computeIntersection(l2);

    printf("Do the 2 non-parallel lines intersect? %s\n", intersection.isNull() ? "False" : "True");

    intersection.printPoint();
}
