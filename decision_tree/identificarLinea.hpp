#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "../headers/regexExpresions.hpp"
#include "../headers/errores.hpp"
#include "../headers/keywords.hpp"
#include "../headers/lineController.hpp"
#include "../gestion_memoria/variables.hpp"
#include "../decision_tree/declaracion.hpp"

using namespace std;

// Identifica segun un patron REGEX que tipo de instruccion podria ser la linea
bool indentificarLinea(string linea, int numero_linea){

    bool esValida = true;

    // Declaracion siemple de una variable
    if(regex_match(linea, POSIBLE_DECLARACION_SIMPLE)){
        esValida = declaracionSimple(linea, numero_linea);
    }
    
    // La linea no contiiene una instruccion valida
    else {
        error_linea_invalida(linea, numero_linea);
        esValida = false;
    }

    return esValida;
}