/*
 * Name: Kelly Tsidji
 * Date: 07.06.2022
 * Assignment: Project 1: Metro Simulator
 * Purpose: This class simulates a Train that picks up and drops off 
 *          passengers at various stations. Each instance of MetroSim is 
 *          initialized with an empty Train and empty stations (no people on 
 *          either). A file with stations name is used to create the stations.
 *          The user can add a file containing commands to operate on the 
 *          system, or they can provided those commands via cin. The command
 *          options are: adding a Passenger to a station (p ARRIVAL DEPARTURE), 
 *          moving the train to the next station (m m), or ending the 
 *          simulation (m f).
 */

#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <string.h>

/*
constructor:
Runs if commands file is provided
Parameters: stationsFile, outputFile, commandsFile
Reads in station names into a vector of Station Structs
Updates the # of stations
Updates the train vector w/ as many PassengerQueues as stations
Sets the current station (index) to 0
Sets cmdFileProvided to true if the commandsFile is provided
*/
MetroSim::MetroSim(ifstream& stations_input, bool commandsFileProvided) 
{
        // reads in station names into a vector of Station Structs
        while (stations_input) {
                struct Station station;
                getline(stations_input, station.name);
                station.numPassengers = 0;
                stations.push_back(station);
        }
        stations.resize(stations.size() - 1);

        // sets the number of stations
        numStations = stations.size();

        // updates the train vector w/ as many PassengerQueues as stations
        for (int i = 0; i < numStations; i++) {
                PassengerQueue passengerCar;
                train.push_back(passengerCar);
        }

        // sets the current station (index) to 0
        currStation = 0;

        // sets cmdFileProvided to true if the commandsFile is provided
        cmdFileProvided = commandsFileProvided;

        // set endSim to false for now. will become true when program should end
        endSim = false;
        oneMoreRound = false;

        id = 1;
}

/* beginSim
 * Purpose: Runs the Metro Simulation
 * Parameters: An input file stream that contains the commands to be performed
 *             during the Metro Similation, and
 *             An output file stream that will contain information about
 *             Passengers that exited the train
 * Returns: Nothing
 */
void MetroSim::beginSim(fstream& output, ifstream& commands)
{
        printMap();
        checkEndSim(commands);
        while (not endSim) {
                runCmd(output);
                printMap();
                checkEndSim(commands);
        }
        cout << "Thanks for playing MetroSim. Have a nice day!" << endl;
}

/* printMap
 * Purpose: Prints the state of the simulation (the current Passengers on the
 *          train, and the Passengers waiting at each station)
 * Parameters: None
 * Returns: Nothing
 */
void MetroSim::printMap()
{
        // print the passengers on the train
        cout << "Passengers on the train: {";
        for (unsigned int i = 0; i < train.size(); i++) {
                train.at(i).print(cout);
        }
        cout << "}" << endl;

        // print each station
        for (int i = 0; i < numStations; i++) {
                if (i == currStation) {
                        cout << "TRAIN: ";
                }
                else {
                        cout << "       ";
                }
                cout << "[" << i << "] " << stations.at(i).name << " {";
                stations.at(i).station_queue.print(cout);
                cout << "}" << endl;
        }
}

/* checkEndSim
 * Purpose: Signals when it is time to end the simulation, whether it is
 *          because the commandsFile ran out of commands, or the command given
 *          by the user or file is "m f" (which means to stop the simulation)
 * Parameters: An input file stream that contains the commands to be performed
 *             during the Metro Similation
 * Returns: Nothing
 */
void MetroSim::checkEndSim(ifstream& commands)
{
        updateCmd(commands);
        if (oneMoreRound) {
                endSim = true;
        }
        if (currCmd == "m f") {
                endSim = true;
        }
        if (commands.eof()) {
                oneMoreRound = true;
        }
}

/* updateCmd
 * Purpose: Reads a command from either cin or the commandsFile
 * Parameters: An input file stream that contains the commands to be performed
 *             during the Metro Similation
 * Returns: Nothing
 */
void MetroSim::updateCmd(ifstream& commands)
{
        cout << "Command? ";
        if (cmdFileProvided) {
                getline(commands, currCmd);
        }
        else {
                getline(cin, currCmd);
        }
}

/* runCmd
 * Purpose: Performs the appropriate operation based on the current command.
 *          (Either moving the train to the next station - "m m", adding a 
 *          Passenger to a station - "p", or doing nothing if neither of those
 *          commands are given)
 * Parameters: An output file stream that will contain information about
 *             Passengers that exited the train
 * Returns: Nothing
 */
void MetroSim::runCmd(fstream& output)
{
        string command = currCmd.substr(0, 2);

        if (currCmd == "m m") {
                // embark passengers from current station
                embark();

                // move to next station
                currStation++;
                if (currStation >= numStations) {
                        currStation = 0;
                }

                // disembark appropriate passengers from current station
                disembark(output);
        }
        else if (command == "p ") {
                addPassenger();
        }
        else {
                return;
        }
}

/* embark
 * Purpose: Moves every passenger at the current station to the appropriate
 *          passenger car (on the train)
 * Parameters: None
 * Returns: Nothing
 */
void MetroSim::embark()
{
        while ( stations.at(currStation).station_queue.size() > 0 ) {

                // adds the passenger at the front of the station to the train
                Passenger passengerToBoard;
                passengerToBoard = 
                stations.at(currStation).station_queue.front();
                train.at(stations.at(currStation).station_queue.front().to)
                .enqueue(passengerToBoard);

                // removes the passenger at the front from the station
                stations.at(currStation).station_queue.dequeue();
        }
}

/* disembark
 * Purpose: Removes Passengers that are exiting at the current station
 * Parameters: An output file stream that will contain information about
 *             Passengers that exited the train
 * Returns: Nothing
 */
void MetroSim::disembark(fstream& output)
{
        while ( train.at(currStation).size() > 0 ) {
                Passenger passengerToLeave;
                passengerToLeave = train.at(currStation).front();

                // prints passenger to leave to output file
                output << "Passenger " << passengerToLeave.id 
                << " left train at station " 
                << stations.at(currStation).name << endl;

                // removes passenger from train
                train.at(currStation).dequeue();
        }
}

/* addPassenger
 * Purpose: Adds a Passenger to a specifiec station
 * Parameters: None
 * Returns: Nothing
 */
void MetroSim::addPassenger()
{
        string arrival;
        string departure;
        int arrivalEndIndex;
        int length = currCmd.length();

        for (int i = 3; i < length; i++) {
                if (currCmd.at(i) == ' ') {
                        arrivalEndIndex = i;
                        i = currCmd.length();
                }
        }

        arrival = currCmd.substr(2, arrivalEndIndex - 2);
        departure = currCmd.substr(arrivalEndIndex + 1, 
        currCmd.length() - arrivalEndIndex + 1);

        int arrivalNum = stoi(arrival);
        int departureNum = stoi(departure);

        // create a new passenger and add to station of arrival
        Passenger newPassenger(id, arrivalNum, departureNum);
        stations.at(arrivalNum).station_queue.enqueue(newPassenger);

        id++;

}


