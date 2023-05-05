#pragma once

#include <iostream>
#include <vector>

using namespace std;

// Eliminar todos los spacios y tabs de un string
const string fullStripString(string input)
{
    size_t index = -1;

    // econtrar y eliminar espacios
    while ((index = input.find(' ')) != string::npos)
    {
        input.erase(index, 1);
    }

    // econtrar y eliminar tabs
    while ((index = input.find('\t')) != string::npos)
    {
        input.erase(index, 1);
    }

    return input;
}

// hace un split de un string en base al separador y
// retorna un vector que contiene todos los elementos
vector<string> splitString(string text, char separator)
{
    vector<string> items;
    bool looping = true;

    while (looping)
    {
        // si text contiene el separador agregar lo que esta antes del mismo al vector
        if (text.find(separator) != -1)
        {
            items.push_back(text.substr(0, text.find_first_of(separator)));
            text = text.substr(text.find_first_of(separator) + 1, text.size());
        }

        // si no contiene el separador agregar text al vector
        else
        {
            items.push_back(text);
            looping = false;
        }
    }

    return items;
}