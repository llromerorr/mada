#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

vector<string> fileToVector(char * file_name){
    ifstream file(file_name);
    string line;
    vector<string> allLines;

    while(getline(file, line)){
        allLines.push_back(line);
    }

    file.close();
    return allLines;
}
