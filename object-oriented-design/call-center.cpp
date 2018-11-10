/**
 * Design a call center with 3 levels of employees: respondent, manager and director
 * Incoming telephone must be handed to a respondent first, then manager and then director
 * Design a method to dispatchCall to the first available respondent
 */

#include <iostream>
#include <vector>
#include <limits>
#include <queue>

using namespace std;

enum EmployeeType {respondent, manager, director};

class Call
{
    private:
        /**
         * ID of the call
         * @param int ID
         */
        int ID;

        /**
         * ID of the employee taking this call
         * @param int employeeId
         */
        int employeeId;

        /**
         * Duration of the call
         * @param int duration
         */
        int duration;

        /**
         * The instant in time when the call arrives
         * @param int arriveTime
         */
        int arriveTime;

    public:
        Call(){}

        Call(int a, int d)
        {
            this->ID = rand() % numeric_limits<int>::max();

            this->duration = d;

            this->arriveTime = a;
        }

        /**
         * Returns the ID of the call
         * @returns int
         */
        int getId()
        {
            return this->ID;
        }

        /**
         * Sets the employeeId of the employee taking this call
         * @returns void
         */
        void setEmployeeId(int employeeId)
        {
            this->employeeId = employeeId;
        }

        /**
         * Returns the ID of the employee taking this call
         * @returns int
         */
        int getEmployeeId()
        {
            return this->employeeId;
        }

        /**
         * Returns the end time of the call
         * @returns int
         */
        int getEndTime()
        {
            return this->arriveTime + this->duration;
        }

        /**
         * Returns whether the call has ended at given time
         * @param int time
         * @returns bool
         */
        bool hasEnded(int time)
        {
            return this->getEndTime() >= time;
        }

        /**
         * Returns the arrival time of the call
         * @returns int
         */
        int getArriveTime()
        {
            return this->arriveTime;
        }

        /**
         * Prints the call properties in a human readable way
         * @returns void
         */
        void print()
        {
            printf("The call arrived at %d, and will end at %d\n", this->getArriveTime(), this->getEndTime());
        }
};

class Employee
{
    private:
        /**
         * Whether the employee is available to accept a new call
         * @param bool available
         */
        bool available;

        /**
         * Level of the employee
         * @param int level
         */
        int level;

        /**
         * The call that the employee is attending
         * Valid only if the employee is unavailable
         * @param Call call
         */
        Call call;

        /**
         * The ID of the employee
         * @param int ID
         */
        int ID;

    public:
        Employee()
        {
            this->available = true;

            this->ID = rand() % numeric_limits<int>::max();
        }

        /**
         * Employee takes the call
         * @param Call& c
         */
        void takeCall(Call& c)
        {
            this->available = false;

            this->call = c;

            printf("Employee with ID: %d and Level: %d has received the call\n", this->getId(), this->getLevel());
        }

        /**
         * Employee has ended the call
         * @returns void
         */
        void endCall()
        {
            this->available = true;
        }

        /**
         * Whether the employee is available
         * @returns bool
         */
        bool isAvailable()
        {
            return this->available;
        }

        /**
         * Returns the level of the employee
         * @returns bool
         */
        int getLevel()
        {
            return this->level;
        }

        /**
         * Returns the ID of the employee
         * @returns int
         */
        int getId()
        {
            return this->ID;
        }

        /**
         * Sets the level of the employee
         * @param int l
         * @returns void
         */
        void setLevel(int l)
        {
            this->level = l;
        }

        /**
         * Returns the call associated with the employee
         * @returns Call
         */
        Call getCall()
        {
            return this->call;
        }

        /**
         * Returns the time when the employee will be available, or -1 if available now
         * @returns int
         */
        int getAvailableTime()
        {
            if (this->isAvailable()) return -1;

            return this->getCall().getEndTime();
        }

        /**
         * Prints the employee properties in a human readable way
         * @returns void
         */
        void print()
        {
            string av = this->isAvailable() ? "available" : "not available";

            printf("The employee at level: %d, and is %s, and will be available at %d \n",
                this->getLevel(), av.c_str(), this->getAvailableTime());
        }
};

class Respondent : public Employee
{
    public:
        Respondent()
        {
            this->setLevel(1);
        }

        /**
         * Returns the type of the employee
         * @returns EmployeeType
         */
        EmployeeType getType()
        {
            return EmployeeType::respondent;
        }
};

class Manager : public Employee
{
    public:
        Manager()
        {
            this->setLevel(2);
        }

        /**
         * Returns the type of the employee
         * @returns EmployeeType
         */
        EmployeeType getType()
        {
            return EmployeeType::manager;
        }
};

class Director : public Employee
{
    public:
        Director()
        {
            this->setLevel(3);
        }

        /**
         * Returns the type of the employee
         * @returns EmployeeType
         */
        EmployeeType getType()
        {
            return EmployeeType::director;
        }
};

class CallCenter
{
    private:
        /**
         * Number of employees
         * @param int employees
         */
        int employees;

        /**
         * Number of respondents
         * @param int respondents
         */
        int respondents;

        /**
         * Number of managers
         * @param int managers
         */
        int managers;

        /**
         * Number of directors
         * @param int directors
         */
        int directors;

        /**
         * Custom comparator for the priority queues
         * @param class Compare
         */
        class Compare
        {
            public:
                bool operator() (Employee& e1, Employee& e2)
                {
                    if (!e1.isAvailable() && !e2.isAvailable())
                    {
                        return e1.getCall().getEndTime() > e2.getCall().getEndTime();
                    }

                    return !e1.isAvailable();
                }
        };

        /**
         * The priority_queue of all respondents in the call center
         * @param priority_queue<Respondent> respondentQ
         */
        priority_queue<Respondent, vector<Respondent>, Compare> respondentQ;

        /**
         * The priority_queue of all managers in the call center
         * @param priority_queue<Manager> managerQ
         */
        priority_queue<Manager, vector<Manager>, Compare> managerQ;

        /**
         * The priority_queue of all directors in the call center
         * @param priority_queue<Director> directorQ
         */
        priority_queue<Director, vector<Director>, Compare> directorQ;

    public:
        CallCenter(int r, int m, int d)
        {
            this->respondents = r;

            this->managers = m;

            this->directors = d;

            this->employees = r + m + d;

            this->initializeEmployeeQueues();
        }

        /**
         * Initializes the employee queues
         * @returns void
         */
        void initializeEmployeeQueues()
        {
            this->initializeRespondentQueue();

            this->initializeManagerQueue();

            this->initializeDirectorQueue();
        }

        /**
         * Initializes the respondent queues
         * @returns void
         */
        void initializeRespondentQueue()
        {
            for (int i=0; i<this->respondents; i++)
            {
                Respondent r = Respondent();

                this->respondentQ.push(r);
            }
        }

        /**
         * Initializes the manager queue
         * @returns void
         */
        void initializeManagerQueue()
        {
            for (int i=0; i<this->managers; i++)
            {
                Manager m = Manager();

                this->managerQ.push(m);
            }
        }

        /**
         * Initializes the director queue
         * @returns void
         */
        void initializeDirectorQueue()
        {
            for (int i=0; i<this->directors; i++)
            {
                Director d = Director();

                this->directorQ.push(d);
            }
        }

        /**
         * Checks whether there exists a free respondent in the queue
         * @param Call& c
         * @returns bool
         */
        bool hasFreeRespondent(Call& c)
        {
            Respondent r = respondentQ.top();

            if (r.isAvailable()) return true;

            return r.getAvailableTime() <= c.getArriveTime();
        }

        /**
         * Checks whether there exists a free manager in the queue
         * @param Call& c
         * @returns bool
         */
        bool hasFreeManager(Call& c)
        {
            Manager m = managerQ.top();

            if (m.isAvailable()) return true;

            return m.getAvailableTime() <= c.getArriveTime();
        }

        /**
         * Checks whether there exists a free director in the queue
         * @param Call& c
         * @returns bool
         */
        bool hasFreeDirector(Call& c)
        {
            Director d = directorQ.top();

            if (d.isAvailable()) return true;

            return d.getAvailableTime() <= c.getArriveTime();
        }

        /**
         * Dispatches call to respondent
         * @param Call& c
         * @returns void
         */
        void dispatchCallToRespondent(Call& c)
        {
            Respondent r = this->respondentQ.top();

            this->respondentQ.pop();

            r.takeCall(c);

            this->respondentQ.push(r);
        }

        /**
         * Dispatches call to manager
         * @param Call& c
         * @returns void
         */
        void dispatchCallToManager(Call& c)
        {
            Manager m = this->managerQ.top();

            this->managerQ.pop();

            m.takeCall(c);

            this->managerQ.push(m);
        }

        /**
         * Dispatches call to director
         * @param Call& c
         * @returns void
         */
        void dispatchCallToDirector(Call& c)
        {
            Director d = this->directorQ.top();

            this->directorQ.pop();

            d.takeCall(c);

            this->directorQ.push(d);
        }

        /**
         * Receive the call at the call center
         * Throws an exception if there are no free respondents
         * @param Call& c
         * @returns void
         */
        void dispatchCall(Call& c)
        {
            if (this->hasFreeRespondent(c))
            {
                this->dispatchCallToRespondent(c);
            }
            else if (this->hasFreeManager(c))
            {
                this->dispatchCallToManager(c);
            }
            else if (this->hasFreeDirector(c))
            {
                this->dispatchCallToDirector(c);
            }
            else
            {
                while (!this->respondentQ.empty())
                {
                    auto r = this->respondentQ.top();

                    this->respondentQ.pop();

                    r.print();
                }

                while (!this->managerQ.empty())
                {
                    auto m = this->managerQ.top();

                    this->managerQ.pop();

                    m.print();
                }

                while (!this->directorQ.empty())
                {
                    auto d = this->directorQ.top();

                    this->directorQ.pop();

                    d.print();
                }

                throw "No employees available to take this call";
            }
        }
};

int main()
{
    // Lets say we create a call center with 10 respondents, 5 managers and 2 directors
    CallCenter cC = CallCenter(10, 5, 2);

    // Simulate 20 calls being received by the center at differing intervals of time

    vector<int> start = {1, 1, 2, 3, 3, 5, 6, 8, 9, 11, 12, 12, 14, 15, 16, 16, 17, 18, 19, 19};

    vector<int> duration = {1, 2, 18, 20, 30, 25, 43, 62, 31, 25, 33, 22, 55, 52, 3, 4, 3, 2, 5, 2};

    int limit = start.size();

    for (int i=0; i<limit; i++)
    {
        printf("Caller Id: %d\n", i);

        Call c = Call(start[i], duration[i]);

        c.print();

        cC.dispatchCall(c);

        cout << endl;
    }
};
