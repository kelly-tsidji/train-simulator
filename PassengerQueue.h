/*
 * Name: Kelly Tsidji
 * Date: 07.06.2022
 * Assignment: Project 1: Metro Simulator
 * Purpose: This class represents a queue of Passengers. Mainly, users can add a
 *          Passenger to the back of the queue, and remove a Passenger from the
 *          front of the queue. PassengerQueues are used to make up the train 
 *          for the MetroSim class. PassengerQueues are composed of Passenger
 *          objects. 
 */
 

#include "Passenger.h"
#ifndef __PASSENGER_QUEUE_H__
#define __PASSENGER_QUEUE_H__
#include <iostream>
#include <queue>
using namespace std;

class PassengerQueue
{
        public:
                ~PassengerQueue();
                Passenger front();
                void dequeue();
                void enqueue(const Passenger &passenger);
                int size();
                void print(ostream &output);

        private:
                queue<Passenger> queue;
};


#endif