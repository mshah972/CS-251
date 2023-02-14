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

using namespace std;

int MAX_CHARACTERS = 150;

bool data_loaded = false;
string state = "N/A";
string command = " ";
string is_data_loaded = " ";

void display_prompt()
{
    if (data_loaded == true)
    {
        is_data_loaded = "Yes";
    }
    else
    {
        is_data_loaded = "No";
    }

    cout << "Data loaded? " << is_data_loaded << endl;
    cout << "State: " << state << endl;
    cout << endl;

    cout << "Enter a command: ";
    getline(cin, command);
    cout << endl;
}

int main()
{
    // TODO:  Write your code here.
    //  You should have LOTS of function decomposition.

    display_prompt();

    cout << "Here is the command you entered: " << command << endl;

    return 0;
}