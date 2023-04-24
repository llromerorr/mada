#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "regexExpresions.hpp"
#include "errores.hpp"
#include "keywords.hpp"


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

bool posibleDeclaracionSimple(string linea, int numero_linea){
    bool esValida = true;
    string identificador = fullStrip(linea.substr(0, linea.find(':')));
    string tipoDeDato = fullStrip(linea.substr(linea.find(':') + 1, linea.length()));

    // verificar si el identificador es valido
    if(regex_match(identificador, IDENTIFICADOR)){
        
        // verificar si el tipo de dato es valido
        if(isDataType(tipoDeDato)){
            cout << tipoDeDato << " es valido" << endl;
        }

        // El tipo de dato es valido
        else {
            error_tipoDeDato_invalido(tipoDeDato, numero_linea);
            esValida = false;
        }
    }

    // El identificador no es valido
    else {
        error_identificador_invalido(identificador, numero_linea);
        esValida = false;
    }

    return esValida;
}

// Identifica segun un patron REGEX que tipo de instruccion podria ser la linea
bool indentificarLinea(string linea, int numero_linea){

    bool esValida = true;

    // Declaracion siemple de una variable
    if(regex_match(linea, POSIBLE_DECLARACION_SIMPLE)){
        esValida = posibleDeclaracionSimple(linea, numero_linea);
    }
    
    // La linea no contiiene una instruccion valida
    else {
        error_linea_invalida(linea, numero_linea);
        esValida = false;
    }

    return esValida;
}