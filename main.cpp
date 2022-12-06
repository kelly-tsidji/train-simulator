/*
 * Name: Kelly Tsidji
 * Date: 07.06.2022
 * Assignment: Project 1: Metro Simulator
 * Purpose: This program simulates a Train that picks up and drops off 
 *          passengers at various stations
 */

#include <iostream>
#include <fstream>
#include <string>
#include "MetroSim.h"
#include "PassengerQueue.h"
#include "Passenger.h"
using namespace std;


bool checkArgNum(int argNum);
bool openStationsFile(string fileName, ifstream& stations_input);
bool openCmdFile(string fileName, ifstream& commands);



int main(int argc, char *argv[])
{
        // stops program if there are < 3 args or > 4 args given to the command
        if (checkArgNum(argc)) {
                return 1;
        }
        // stops program if stationsFile cannot be opened
        ifstream stations_input;
        if (not openStationsFile(argv[1], stations_input)) {
                return 1;
        }
        // checks if outputFile exists. if not, it creates one.
        fstream output(argv[2], ios::in);
        if (output) {}
        else {
                output.close();
                output.open(argv[2], ios::out);
        }
        // checks if the commandsFile provided can be opened
        bool commandsFileProvided = false;
        ifstream commands;
        if (argc == 4) {
                commandsFileProvided = true;
                if (not openCmdFile(argv[3], commands)) {
                        return 1;
                }
        }
        MetroSim simulation(stations_input, commandsFileProvided);
        // Passes files to beginSim() to begin simulation
        simulation.beginSim(output, commands);
        return 0;
}

// returns true if the command line has an incorrect number of arguments
bool checkArgNum(int argNum)
{
        if (argNum < 3 or argNum > 4) {
                cerr << "Usage: ./MetroSim stationsFile outputFile "
                     << "[commandsFile]";
                return true;
        }
        return false;
}

// returns false if stationsFile cannot be opened
bool openStationsFile(string fileName, ifstream& stations_input)
{
        stations_input.open(fileName);
        if (not stations_input.is_open()) {
                cerr << "Error: could not open file " << fileName;
                return false;
        }
        return true;
}

// returns false if commandsFile cannot be opened
bool openCmdFile(string fileName, ifstream& commands)
{
        commands.open(fileName);
        if (not commands.is_open()) {
                cerr << "Error: could not open file " << fileName;
                return false;
        }
        return true;
        
}
