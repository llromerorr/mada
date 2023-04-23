#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "regexExpresions.hpp"

using namespace std;

void error_identificador_invalido(string identificador, int numero_linea){
    cout 
        << "Error en linea "
        << numero_linea + 1
        << ", debido a que '"
        << identificador 
        << "' no es indenficador valido.\n\n"
        << "Asegúrese de que el nombre empiece con una letra o un guion bajo, "
        << "no contenga espacios ni caracteres especiales, y no sea una palabra "
        << "reservada del lenguaje." << 
    endl;
}

void error_linea_invalida(string linea, int numero_linea){
    cout 
        << "Error en linea "
        << numero_linea + 1
        << ", debido a que '"
        << linea 
        << "' no es instruccion valida.\n\n"
        << "Revise la escritura de la instrucción y asegúrese de que se siguen las "
        << "reglas del lenguaje. Verifique que los paréntesis, las comillas y los "
        << "comas y los puntos están bien colocados y que no hay caracteres extraños o "
        << "faltantes. Consulte la documentación del lenguaje o un manual de referencia "
        << "para ver ejemplos de cómo escribir correctamente las instrucciones." << 
    endl;
}