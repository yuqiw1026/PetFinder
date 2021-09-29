#include "filereader.h"

FileReader::FileReader()
{
    this->states = new unordered_set<string>();
    this->cities  = new  map<string, vector<string>*> ();
    this->coordinations = new  map<string, string>();
}
void FileReader::read()
{
    ifstream file;
    //    unordered_set<string> states;
    //    map<string, string> coordinations;
    //    map<string, vector<string>*> cities;
    file.open("../../../../project/uscities2.csv", ios::out);
    if(!file) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    string buff;
    string location;
    string coordination;
    getline(file, buff);
    while(!file.eof() && getline(file,buff)){
        vector<string> result;
        stringstream s_stream(buff); //create string stream from the string
        while(s_stream.good()) {
            string substr;
            getline(s_stream, substr, ','); //get first string delimited by comma
            result.push_back(substr);
        }
        if(states->count(result[1]) == 0){
            states->insert(result[1]);
            vector<string>* temps = new vector<string>();
            temps->push_back(result[0]);
            cities->insert({result[1],temps});
        }
        auto itr = cities->find(result[1]);
        itr->second->push_back(result[0]);
        location = result[0] + "," + result[1];
        coordination = result[2] + "," + result[3];
        coordinations->insert({location, coordination});
        result.clear();
        // break;
    }
    file.close();
}

vector<string>* FileReader::getCitiesByState(string state)
{
    auto itr = cities->find(state);
    return itr->second;
}
/**
  the following distance calculation part is copied from
  https://stackoverflow.com/questions/10198985/calculating-the-distance-between-2-latitudes-and-longitudes-that-are-saved-in-a,
  which is base on Haversine_formula
  */

// This function converts decimal degrees to radians
double FileReader::deg2rad(double deg) {
  return (deg * M_PI / 180);
}

//  This function converts radians to decimal degrees
double FileReader::rad2deg(double rad) {
  return (rad * 180 / M_PI);
}

string FileReader::getCoordinationByAddress(string address){
    for (auto itr = coordinations->begin(); itr != coordinations->end(); itr++ ){
        if(itr->first == address){
            return itr->second;
        }
    }
    return "";
}
/**
 * Returns the distance between two points on the Earth.
 * Direct translation from http://en.wikipedia.org/wiki/Haversine_formula
 * @param lat1d Latitude of the first point in degrees
 * @param lon1d Longitude of the first point in degrees
 * @param lat2d Latitude of the second point in degrees
 * @param lon2d Longitude of the second point in degrees
 * @return The distance between the two points in kilometers
 */
double FileReader::distanceEarth(string address1, string address2) {
  double lat1d, lon1d, lat2d, lon2d;
  vector<string> temp;
  vector<string> temp2;
  stringstream s_stream(getCoordinationByAddress(address1)); //create string stream from the string
  while(s_stream.good()) {
      string substr;
      getline(s_stream, substr, ','); //get first string delimited by comma
      temp.push_back(substr);
  }
  lat1d = stod(temp[0]);
  lon1d = stod(temp[1]);
  temp.clear();
  stringstream s_stream2(getCoordinationByAddress(address2)); //create string stream from the string
  while(s_stream2.good()) {
      string substr;
      getline(s_stream2, substr, ','); //get first string delimited by comma
      temp2.push_back(substr);
  }

  lat2d = stod(temp2[0]);
  lon2d = stod(temp2[1]);

  double lat1r, lon1r, lat2r, lon2r, u, v;
  lat1r = deg2rad(lat1d);
  lon1r = deg2rad(lon1d);
  lat2r = deg2rad(lat2d);
  lon2r = deg2rad(lon2d);
  u = sin((lat2r - lat1r)/2);
  v = sin((lon2r - lon1r)/2);
  return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

void FileReader::generateCitiesAndStatesFiles()
{

    ofstream oFile;

    oFile.open("states.txt"); // opens the file
    if( !oFile ) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }

    for(auto it = states->begin(); it != states->end(); it++ ){
        oFile << *it << endl;
    }
    oFile.close();

    oFile.open("cities.txt"); // opens the file
    if( !oFile ) { // file couldn't be opened
        cerr << "Error: file could not be opened" << endl;
        exit(1);
    }
    int count;
    int add = 0;
    int max = 0;
    for(auto it = cities->begin(); it != cities->end(); it++ ){
        oFile << "======================" << endl;
        oFile << it->first << endl;
        count = 0;
        for(unsigned int i = 0; i < it->second->size(); i++){
            oFile << (*it->second)[i] << endl;
            count++;
            add++;
        }
        if(count > max){
            max = count;
        }
    }
    cout << "add: " << add<< endl;
    cout << "max: " << max<< endl;
    oFile.close();
}
