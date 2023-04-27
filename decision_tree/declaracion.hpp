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

using namespace std;

bool declaracionSimple(string linea, int numero_linea){
    bool esValida = true;
    string identificador = fullStrip(linea.substr(0, linea.find(':')));
    string tipoDeDato = fullStrip(linea.substr(linea.find(':') + 1, linea.length()));

    // verificar si el identificador es valido
    if(regex_match(identificador, IDENTIFICADOR)){
        
        // verificar si el tipo de dato es valido
        if(isDataType(tipoDeDato)){
            // declarar variable, pero en caso de que retorne false
            // se mostrara un error
            if(!variables_declarar(identificador, tipoDeDato)){
                
            }
            
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