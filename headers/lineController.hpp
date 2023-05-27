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

void transformar_string(string *expresion){
    string ops_pseudo[]={"**","div", "mod","~", "¬"};
    string ops_reales[]={"^","/", "%", "not"};

    //TRANSFORMAR EXPONENCIACION
    replaceAll(*expresion,ops_pseudo[0],ops_reales[0]);
    
    //TRANSFORMAR OPERADOR DIV
        //BUSCAR Y REEMPLAZAR CON REGEX_REPLACE
        regex regexp("[[ ]div[ ]"); 
        std::string output = std::regex_replace(*expresion, regexp, "/");
        *expresion=output;

    //TRANSFORMAR OPERADOR MOD
        //BUSCAR Y REEMPLAZAR CON REGEX_REPLACE
        regex regexp2("[[ ]mod[ ]"); 
        std::string output2 = std::regex_replace(*expresion, regexp2, "%");
        *expresion=output2;

    //TRANSFORMAR OPERADOR NOT
    replaceAll(*expresion,ops_pseudo[3],ops_reales[3]);
    replaceAll(*expresion,ops_pseudo[4],ops_reales[3]);
}