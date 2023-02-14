#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;


struct District {
    int districtNum;
    int democraticVotes;
    int republicanVotes;
};

int main() {
    vector<District> districts;
    string state;

    ifstream districtsFile("districts.txt");
    string line;
    while (getline(districtsFile, line)) {
    stringstream ss(line);
    getline(ss, state, ',');

    District newDistrict;
    ss >> newDistrict.districtNum;
    ss >> newDistrict.democraticVotes;
    ss >> newDistrict.republicanVotes;


    districts.push_back(newDistrict);
    }  
    districtsFile.close();

// print out the information for each district
    for (District district : districts) {
        cout << "State: " << state << endl;
        cout << "District Number: " << district.districtNum << endl;
        cout << "Democratic Votes: " << district.democraticVotes << endl;
        cout << "Republican Votes: " << district.republicanVotes << endl;
}
}


