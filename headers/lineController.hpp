#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "regexExpresions.hpp"
#include "errores.hpp"


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

    // verificar si el identificador es valido
    if(regex_match(identificador, IDENTIFICADOR)){
        cout << "el identificador: " << identificador << " es valido" << endl;
    }

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