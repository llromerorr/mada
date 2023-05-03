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

/*  
    Reemplazar Substring
    Parametros: (STRING, SUBSTRING A MODIFICAR, SUBSTRING OBJETIVO)
*/
void replaceAll(std::string& str, const std::string& from, const std::string& to) {
    if(from.empty())
        return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like replacing 'x' with 'yx'
    }
}