#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <string>

//TODO: Specify what type of data your set will store
std::set<TYPE> mySet; 
//TODO: Specify what type of data your map will store: remember, they can be two different or the same type.
std::map<KEY_TYPE, VALUE_TYPE> myMap;

void readCSV(std::string fileName) {
    std::ifstream data;
    std::string line;

    data.open(fileName);
    while (std::getline(data, line)){
        // TODO: Implement your code to insert the appropriate data into mySet and myMap. See: https://replit.com/@VictoriaChvez/full-csv-reading
        
        /*
            HINT 1: You can remove the first row of your CSV file if it's a header row (just make sure to keep track of  column titles on your own!)
            HINT 2: If you only care about, say column 1 and 3, you can keep track of which column you're on via a counter. See: https://replit.com/@VictoriaChvez/full-csv-reading
        */    
    }

    data.close();
}

int main(){
    readCSV("YOUR FILE NAME HERE");
    //TODO: Use some of the built-in functions for std::set and std::map to answer the two questions about your dataset
    // Refer to https://www.cplusplus.com/reference/map/map/ and https://www.cplusplus.com/reference/set/set/ as needed
}