/*
 * Name: Kelly Tsidji
 * Date: 07.06.2022
 * Assignment: Project 1: Metro Simulator
 * Purpose: This class represents a single Passenger on the train, or waiting at
 *          a station to be picked up by the train. An instance of Passenger
 *          has an ID, an arrival station (where the Passenger is picked up by 
 *          the train), and a departure station (where the Passenger is dropped
 *          off by the train). 
 *  
 */

#include <iostream>
#include <string>
#include "Passenger.h"
using namespace std;

/*
 * Format: [PASSENGER_ID, ARRIVAL->DEPARTURE]
 */
void Passenger::print(ostream &output)
{
        output << "[" << id << ", " << from << "->" << to << "]";
}
