/*
 * Name: Kelly Tsidji
 * Date: 07.06.2022
 * Assignment: Project 1: Metro Simulator
 * Purpose: This class simulates a Train that picks up and drops off 
 *          passengers at various stations. The Train is composed of 
 *          PassengerQueue objects, each representing a passenger car of the 
 *          Train. This class can simulate a Train moving from one station to 
 *          the next, as well as picking up and dropping off passengers at each
 *          station. Each instance of MetroSim is initialized with an empty
 *          Train and empty stations (no people on either).
 */

#ifndef _METROSIM_H_
#define _METROSIM_H_
#include "Passenger.h"
#include "PassengerQueue.h"
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// Put any other necessary includes here


// Put any other structs you need here

class MetroSim
{

        public:
        MetroSim(ifstream& stations_input, bool commandsFileProvided);

        //begin simulation
        void beginSim(fstream& output, ifstream& commands);

        private:

                struct Station {
                        string name;                    // name of station
                        // PassengerQueue of people waiting to get on train
                        PassengerQueue station_queue;
                        // number of people waiting at the station
                        int numPassengers; 
                };

                vector<PassengerQueue> train;
                vector<Station> stations; 
                string currCmd;                         // holds current command
                bool cmdFileProvided;        // true if command file is provided
                int numStations;                         // holds # of stations
                int currStation;                        // holds current station
                bool endSim;                   // true if the program should end
                // true if the simulation should run one last time
                bool oneMoreRound;
                int id;                                          // passenger ID

                
                void printMap();
                void checkEndSim(ifstream& commands);
                void updateCmd(ifstream& commands);
                void runCmd(fstream& output);
                void embark();
                void disembark(fstream& output);
                void addPassenger();

};

#endif
