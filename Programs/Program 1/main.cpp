//
//  Project 1 Starter Code - Gerrymandering
//  Moksh Shah
//  CS 251 - Data Structures
//  01/15/2023
//

#include "ourvector.h"
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
#include <iomanip>

using namespace std;

bool data_loaded = false;
string state_name = "N/A";
string command = " ";
string is_data_loaded = " ";

void display_prompt()
{
    if(data_loaded == true)
    {
        is_data_loaded = "Yes";
    }
    else
    {
        is_data_loaded = "No";
    }

    cout << "Data Loaded? " << is_data_loaded << endl;
    cout << "State: " << state_name << endl;
    cout << endl;

    cout << "Enter command: ";
    getline(cin, command);

    cout << endl;

    cout << setfill('-') << setw(40) << "-" << endl;
}


int main() {
    //TODO:  Write your code here.  
    // You should have LOTS of function decomposition.
    display_prompt();

    return 0;
}