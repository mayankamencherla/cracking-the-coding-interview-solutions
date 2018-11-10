/**
 * Design a parking lot using object oriented principles
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class ParkingLot
{
    private:
        /**
         * Width of the parking lot
         * @param int width
         */
        int width;

        /**
         * Height of the parking lot
         * @param int height
         */
        int height;

        /**
         * Area of the parking lot
         * @param int area
         */
        int area;

        /**
         * Number of motorcycles that fit into the lot
         * @param int motorCycleCapacity
         */
        int motorCycleCapacity;

        /**
         * Number of motorcycles that are in the lot
         * @param int motorCycleFilled
         */
        int motorCycleFilled;

        /**
         * Number of buses that fit into the lot
         * @param int busCapacity
         */
        int busCapacity;

        /**
         * Number of buses that are in the lot
         * @param int busFilled
         */
        int busFilled;

        /**
         * Number of cars that fit into the lot
         * @param int carCapacity
         */
        int carCapacity;

        /**
         * Number of cars that are in the lot
         * @param int carFilled
         */
        int carFilled;

        /**
         * Sets area of the parking lot
         * @return void
         */
        void computeArea() { this->area = this->width * this->height; }

        /**
         * Returns the area of one motorcycle space
         * @return int
         */
        int getMotorCycleArea()
        {
            // 2 by 1
            return 2;
        }

        /**
         * Returns the area of one car space
         * @return int
         */
        int getCarArea()
        {
            // 3 by 2
            return 6;
        }

        /**
         * Returns the area of one bus space
         * @return int
         */
        int getBusArea()
        {
            // 5 by 3
            return 15;
        }

        /**
         * Returns the area of the lot allocated to motorcycles
         * @return int
         */
        double getMotorCycleAllocation()
        {
            // 30%
            return .3 * this->getArea();
        }

        /**
         * Returns the area of the lot allocated to cars
         * @return int
         */
        double getCarAllocation()
        {
            // 40%
            return .4 * this->getArea();
        }

        /**
         * Returns the area of the lot allocated to buses
         * @return int
         */
        int getBusAllocation()
        {
            // 20%
            return .2 * this->getArea();
        }

        /**
         * Initializes the motorcycle capacity of the lot
         * @return void
         */
        void initializeMotorCycleCapacity()
        {
            this->motorCycleFilled = 0;

            this->motorCycleCapacity = this->getMotorCycleAllocation() / this->getMotorCycleArea();
        }

        /**
         * Initializes the car capacity of the lot
         * @return void
         */
        void initializeCarCapacity()
        {
            this->carFilled = 0;

            this->carCapacity = this->getCarAllocation() / this->getCarArea();
        }

        /**
         * Initializes the bus capacity of the lot
         * @return void
         */
        void initializeBusCapacity()
        {
            this->busFilled = 0;

            this->busCapacity = this->getBusAllocation() / this->getBusArea();
        }

        /**
         * Initializes the capacity of the lot
         * @return void
         */
        void initializeLotCapacity()
        {
            this->initializeMotorCycleCapacity();

            this->initializeCarCapacity();

            this->initializeBusCapacity();
        }

        /**
         * Validates the dimensions of the input
         * @param int h
         * @param int w
         */
        void validateDimensions(int h, int w)
        {
            if (h < 10 || w < 10) throw "Invalid dimensions";
        }

        /**
         * Returns the height of the lot
         * @return int
         */
        int getHeight()
        {
            return this->height;
        }

        /**
         * Returns the width of the lot
         * @return int
         */
        int getWidth()
        {
            return this->width;
        }

        /**
         * Returns the area of the lot
         * @return int
         */
        int getArea()
        {
            return this->area;
        }

        /**
         * Returns the capacity of motor cycle slots in the lot
         * @return int
         */
        int getMotorCycleCapacity()
        {
            return this->motorCycleCapacity;
        }

        /**
         * Returns the number of filled motor cycle slots in the lot
         * @return int
         */
        int getMotorCycleFilled()
        {
            return this->motorCycleFilled;
        }

        /**
         * Returns the capacity of car slots in the lot
         * @return int
         */
        int getCarCapacity()
        {
            return this->carCapacity;
        }

        /**
         * Returns the number of filled car slots in the lot
         * @return int
         */
        int getCarFilled()
        {
            return this->carFilled;
        }

        /**
         * Returns the capacity of bus slots in the lot
         * @return int
         */
        int getBusCapacity()
        {
            return this->busCapacity;
        }

        /**
         * Returns the number of filled bus slots in the lot
         * @return int
         */
        int getBusFilled()
        {
            return this->busFilled;
        }

        /**
         * Returns whether all the car slots are taken
         * @return bool
         */
        bool carSlotsFull()
        {
            return this->carFilled == this->carCapacity;
        }

        /**
         * Returns whether all the bus slots are taken
         * @return bool
         */
        bool busSlotsFull()
        {
            return this->busFilled == this->busCapacity;
        }

        /**
         * Returns whether all the motor cycle slots are taken
         * @return bool
         */
        bool motorCycleSlotsFull()
        {
            return this->motorCycleFilled == this->motorCycleCapacity;
        }

        /**
         * Returns whether all the car slots are empty
         * @return bool
         */
        bool carSlotsEmpty()
        {
            return this->carFilled == 0;
        }

        /**
         * Returns whether all the bus slots are empty
         * @return bool
         */
        bool busSlotsEmpty()
        {
            return this->busFilled == 0;
        }

        /**
         * Returns whether all the motor cycle slots are empty
         * @return bool
         */
        bool motorCycleSlotsEmpty()
        {
            return this->motorCycleFilled == 0;
        }

    public:
        ParkingLot(int h, int w)
        {
            this->validateDimensions(h, w);

            this->width = w;

            this->height = h;

            this->computeArea();

            this->initializeLotCapacity();
        }

        /**
         * Prints the parking lot's features
         * @return void
         */
        void print()
        {
            printf("The parking lot's dimensions are %d-by-%d\n", this->getWidth(), this->getHeight());

            printf("The parking lot's area is %d\n", this->getArea());

            printf("The lot can have %d motorcycles, of which %d slots are filled\n",
                this->getMotorCycleCapacity(), this->getMotorCycleFilled());

            printf("The lot can have %d car, of which %d slots are filled\n",
                this->getCarCapacity(), this->getCarFilled());

            printf("The lot can have %d bus, of which %d slots are filled\n",
                this->getBusCapacity(), this->getBusFilled());
        }

        /**
         * Park car, and increment number of slots filled
         * @return void
         */
        void parkCar()
        {
            if (this->carSlotsFull()) throw "All car parking slots are full";

            this->carFilled++;
        }

        /**
         * Park bus, and increment number of slots filled
         * @return void
         */
        void parkBus()
        {
            if (this->busSlotsFull()) throw "All bus parking slots are full";

            this->busFilled++;
        }

        /**
         * Park motor cycle, and increment number of slots filled
         * @return void
         */
        void parkMotorCycle()
        {
            if (this->motorCycleSlotsFull()) throw "All motor cycle parking slots are full";

            this->motorCycleFilled++;
        }

        /**
         * Remove car, and decrement number of slots filled
         * @return void
         */
        void removeCar()
        {
            if (this->carSlotsEmpty()) throw "None of the car slots are full";

            this->carFilled--;
        }

        /**
         * Remove bus, and decrement number of slots filled
         * @return void
         */
        void removeBus()
        {
            if (this->busSlotsEmpty()) throw "None of the bus slots are full";

            this->busFilled--;
        }

        /**
         * Remove motor cycle, and decrement number of slots filled
         * @return void
         */
        void removeMotorCycle()
        {
            if (this->motorCycleSlotsEmpty()) throw "None of the motor cycle slots are full";

            this->motorCycleFilled--;
        }
};

int main()
{
    ParkingLot pl = ParkingLot(10, 10);

    pl.print();

    pl.parkCar();

    pl.parkCar();

    pl.parkMotorCycle();

    pl.parkBus();

    pl.parkMotorCycle();

    cout << endl;

    pl.print();

    pl.removeCar();

    pl.removeMotorCycle();

    pl.removeBus();

    cout << endl;

    pl.print();
}
