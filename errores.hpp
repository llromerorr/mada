#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include "regexExpresions.hpp"

using namespace std;

void error_tipoDeDato_invalido(string tipo_dato, int numero_linea){
    cout 
        << "Error en linea "
        << numero_linea + 1
        << ", debido a que '"
        << tipo_dato 
        << "' no es tipo de dato valido.\n\n" <<
    endl;
}

void error_identificador_invalido(string identificador, int numero_linea){
    cout 
        << "Error en linea "
        << numero_linea + 1
        << ", debido a que '"
        << identificador 
        << "' no es indenficador valido.\n\n"
        << "El mismo debe empezar con una letra o un guion bajo, "
        << "no debe contener espacios ni caracteres especiales, y no ser una palabra "
        << "reservada del lenguaje." << 
    endl;
}

void error_identificador_redeclaracion(string identificador, int numero_linea){
    cout 
        << "Error en linea "
        << numero_linea + 1
        << ", debido a que '"
        << identificador 
        << "' ha sido redeclarado.\n\n"
        << "Sugerencia: usa identificadores únicos y distintos para evitar errores." <<
    endl;
}

void error_linea_invalida(string linea, int numero_linea){
    cout 
        << "Error en linea "
        << numero_linea + 1
        << ", debido a que '"
        << linea 
        << "' no es instruccion valida.\n\n"
        << "Revise si la sintaxis de la instrucción es correcta. Al hacerlo verifique que los paréntesis"
        << "y los signos de puntuación estén bien colocados y que no haya caracteres extraños o "
        << "faltantes. Consulte la documentación del lenguaje o un manual de referencia "
        << "para ver ejemplos de cómo escribir correctamente las instrucciones." << 
    endl;
}

void error_memoria_insuficiente(string identificador, string tipoDeDato, int numero_linea){
    cout 
        << "Error de insuficiencia de memoria, al ejecutar la linea "
        << numero_linea + 1
        << ", debido a que no se pudo asignar memoria a '"
        << identificador
        << "', que es una variable de tipo '"
        << tipoDeDato
        << "'." << 
    endl;
}
