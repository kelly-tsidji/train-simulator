/*
 * Name: Kelly Tsidji
 * Date: 07.06.2022
 * Assignment: Project 1: Metro Simulator
 * Purpose: This program tests the Passenger and PassengerQueue classes
 */

#include <iostream>
#include <fstream>
#include <string>
#include "PassengerQueue.h"
#include "Passenger.h"
using namespace std;

//void passengerPrintTest();

int main()
{
        cout << "Testing Passenger class" << endl;      

        cout << "Creating Passenger 1" << endl;               // arrival: 3
        Passenger passenger1(1, 3, 1);                          // departure: 1
        passenger1.print(cout);                                  // id is 1
        cout << endl;

        cout << "Creating Passenger 2" << endl;
        Passenger passenger2(2, 4, 3);                        
        passenger2.print(cout);                                
        cout << endl;

        cout << "Creating Passenger 3" << endl;
        Passenger passenger3(3, 5, 2);                        
        passenger3.print(cout);                                
        cout << endl;

        cout << "Testing PassengerQueue class" << endl;

        cout << "Creating an empty PassengerQueue" << endl;
        PassengerQueue queue;

        cout << "Printing the empty queue" << endl;
        queue.print(cout);

        /* Test should fail
        cout << "Trying to print first passenger of empty queue; fails" << endl;
        queue.front().print(cout);
        */

        cout << "Printing the queue size (0)" << endl;          // should be 0
        cout << "Size of queue: " << queue.size() << endl;

        cout << "Adding Passenger 1 to queue" << endl;
        queue.enqueue(passenger1);

        cout << "Printing the queue size (1)" << endl;          // should be 1
        cout << "Size of queue: " << queue.size() << endl;

        cout << "Printing the queue; holds Passenger 1" << endl;
        queue.print(cout);
        cout << endl;

        cout << "Printing 1st passenger of queue: Passenger 1" << endl;
        queue.front().print(cout);
        cout << endl;

        cout << "Adding Passenger 2 to queue" << endl;
        queue.enqueue(passenger2);

        cout << "Printing the queue size (2)" << endl;          // should be 2
        cout << "Size of queue: " << queue.size() << endl;

        cout << "Printing the queue; holds Passengers 1-2" << endl;
        queue.print(cout);
        cout << endl;

        cout << "Printing 1st passenger of queue: Passenger 1" << endl;
        queue.front().print(cout);
        cout << endl;

        cout << "Adding Passenger 3 to queue" << endl;
        queue.enqueue(passenger3);

        cout << "Printing the queue size (3)" << endl;          // should be 3
        cout << "Size of queue: " << queue.size() << endl;

        cout << "Printing the queue; holds Passengers 1-3" << endl;
        queue.print(cout);
        cout << endl;

        cout << "Printing 1st passenger of queue: Passenger 1" << endl;
        queue.front().print(cout);
        cout << endl;

        cout << "Removing Passenger 1 from queue" << endl;
        queue.dequeue();

        cout << "Printing the queue size (2)" << endl;          // should be 2
        cout << "Size of queue: " << queue.size() << endl;

        cout << "Printing the queue; holds Passengers 2-3" << endl;
        queue.print(cout);
        cout << endl;

        cout << "Printing 1st passenger of queue: Passenger 2" << endl;
        queue.front().print(cout);
        cout << endl;

        cout << "Removing Passenger 2 from queue" << endl;
        queue.dequeue();

        cout << "Printing the queue size (1)" << endl;          // should be 1
        cout << "Size of queue: " << queue.size() << endl;

        cout << "Printing the queue; holds Passenger 3" << endl;
        queue.print(cout);
        cout << endl;

        cout << "Printing 1st passenger of queue: Passenger 3" << endl;
        queue.front().print(cout);
        cout << endl;

        cout << "Removing Passenger 3 from queue" << endl;
        queue.dequeue();

        cout << "Printing the queue size (0)" << endl;          // should be 0
        cout << "Size of queue: " << queue.size() << endl;

        cout << "Printing the empty queue" << endl;
        queue.print(cout);

        /* Test should fail
        cout << "Printing 1st passenger of empty queue: should fail" << endl;
        queue.front().print(cout);
        cout << endl;
        */

        /* Test should fail
        cout << "Removing from empty queue - should fail" << endl;
        queue.dequeue();
        */
        
        return 0;
}
