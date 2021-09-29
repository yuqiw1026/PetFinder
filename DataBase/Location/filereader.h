#ifndef FILEREADER_H
#define FILEREADER_H
#define earthRadiusKm 6371.0
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <map>
#include <vector>
#include <sstream>
#include <cmath>
using namespace std;

class FileReader
{
public:
    unordered_set<string>* states;
    map<string, string>* coordinations;
    map<string, vector<string>*>* cities;
    FileReader();
    void read();
    void generateCitiesAndStatesFiles();
    vector<string>* getCitiesByState(string state);

    string getCoordinationByAddress(string address);
    double deg2rad(double deg);
    double rad2deg(double rad);
    double distanceEarth(string address1, string address2);

};

#endif // FILEREADER_H
