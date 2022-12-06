/*
 * Name: Kelly Tsidji
 * Date: 07.06.2022
 * Assignment: Project 1: Metro Simulator
 * Purpose: This class represents a queue of Passengers. Mainly, users can add a
 *          Passenger to the back of the queue, and remove a Passenger from the
 *          front of the queue. To insert a Passenger to the end of the queue,
 *          use the enqueue() function, and to remove a Passenger from the front
 *          of the queue, use the dequeue() function. 
 */
 
#include "PassengerQueue.h"
#include <iostream>
#include <queue>



PassengerQueue::~PassengerQueue()
{
        ::queue<Passenger> temp;
        queue.swap(temp);
}

// Returns, but does not remove, the passenger at the front of the queue
Passenger PassengerQueue::front()
{
        if (queue.empty()) {
                throw runtime_error("cannot get first of empty PassengerQueue");
        }
        return queue.front();
}

// Removes the passenger at the front of the queue
void PassengerQueue::dequeue()
{
        if (queue.empty()) {
                throw runtime_error("cannot remove from empty PassengerQueue");
        }
        queue.pop();
}

// Inserts a new passenger at the end of the queue
void PassengerQueue::enqueue(const Passenger &passenger)
{
        queue.push(passenger);
}

// Returns the number of elements in the queue.
int PassengerQueue::size()
{
        return queue.size();
}

// Prints each Passenger in the queue to the given output stream. Passengers 
// are printed from front to back, with no spaces in between and no trailing 
// newline. For example, output might look like: 
// [1, 1->2][2, 1->3][3, 2->3][4, 2->3]
void PassengerQueue::print(ostream &output)
{
        ::queue<Passenger> tempQueue = queue;

        while (!tempQueue.empty()) {
                tempQueue.front().print(output);
                tempQueue.pop();
        }
}
