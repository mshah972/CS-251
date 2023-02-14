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
#include <vector>
#include <sstream>

using namespace std;


bool data_loaded = false;
string state = "N/A";
string command = " ";
string is_data_loaded = " ";
vector<vector<string>> districts_info;


void load_districts()
{
    
}

int main()
{
    cout << "Welcome to Gerrymandering!" << endl;

    load_districts();


    return 0;
}