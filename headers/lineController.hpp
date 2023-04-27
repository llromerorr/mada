#pragma once

#include <iostream>


using namespace std;

// Eliminar todos los spacios y tabs de un string
const string fullStrip(string input){
    size_t index = -1;

    while((index = input.find(' ')) != string::npos){
        input.erase(index, 1);
    }

    while((index = input.find('\t')) != string::npos){
        input.erase(index, 1);
    }

    return input;
}