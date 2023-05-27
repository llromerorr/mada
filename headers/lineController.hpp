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