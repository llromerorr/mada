#pragma once

#include <map>
#include <iostream>
#include "../headers/keywords.hpp"

using namespace std;

map<string, int*> variables_entero;
map<string, float*> variables_real;
map<string, bool*> variables_logico;
map<string, char*> variables_caracter;
map<string, string*> variables_cadena;
map<string, string> tipos;

bool variables_declarar_entero(string identificador);
bool variables_declarar_real(string identificador);
bool variables_declarar_logico(string identificador);
bool variables_declarar_caracter(string identificador);
bool variables_declarar_cadena(string identificador);
bool variables_existe(string identificador);

bool variables_declarar(string identificador, string tipo){
    bool operacion_exitososa = true;

    if(tipo == ENTERO)
        operacion_exitososa = variables_declarar_entero(identificador);
    else if(tipo == REAL)
        operacion_exitososa = variables_declarar_real(identificador);
    else if(tipo == LOGICO)
        operacion_exitososa = variables_declarar_logico(identificador);
    else if(tipo == CARACTER)
        operacion_exitososa = variables_declarar_caracter(identificador);
    else if(tipo == CADENA)
        operacion_exitososa = variables_declarar_cadena(identificador);
    else
        operacion_exitososa = false;

    return operacion_exitososa;
}

// guarda en 'variables_entero' un par identificador:valor
bool variables_declarar_entero(string identificador){
    // esta variable es para verificar si operacion fue exitosa
    bool operacion_exitososa = true;

    // asignar espacio de memeria a 'variables_entero[identificador]'
    variables_entero[identificador] = new int;
    // agregar a tipos[] el identificador con su respectivo tipo de dato,
    // esto es util para asociar los identificadores a su correspondiente
    // tipo de dato.
    tipos[identificador] = ENTERO;

    // si 'variables_entero[identificador]' es NULL es porque no el operador
    // new no pudo asignar la memoria, por lo tanto fallo la declaracion
    // y la operacion no fue exitosa. 
    if(variables_entero[identificador] == NULL)
        operacion_exitososa = false;
    
    // retornar el estado de la operacion.
    return operacion_exitososa;
}

// guarda en 'variables_real' un par identificador:valor
bool variables_declarar_real(string identificador){
    // esta variable es para verificar si operacion fue exitosa
    bool operacion_exitososa = true;

    // asignar espacio de memeria a 'variables_real[identificador]'
    variables_real[identificador] = new float;
    // agregar a tipos[] el identificador con su respectivo tipo de dato,
    // esto es util para asociar los identificadores a su correspondiente
    // tipo de dato.
    tipos[identificador] = REAL;

    // si 'variables_real[identificador]' es NULL es porque no el operador
    // new no pudo asignar la memoria, por lo tanto fallo la declaracion
    // y la operacion no fue exitosa. 
    if(variables_real[identificador] == NULL)
        operacion_exitososa = false;
    
    // retornar el estado de la operacion.
    return operacion_exitososa;
}

// guarda en 'variables_logico' un par identificador:valor
bool variables_declarar_logico(string identificador){
    // esta variable es para verificar si operacion fue exitosa
    bool operacion_exitososa = true;

    // asignar espacio de memeria a 'variables_logico[identificador]'
    variables_logico[identificador] = new bool;
    // agregar a tipos[] el identificador con su respectivo tipo de dato,
    // esto es util para asociar los identificadores a su correspondiente
    // tipo de dato.
    tipos[identificador] = LOGICO;

    // si 'variables_logico[identificador]' es NULL es porque no el operador
    // new no pudo asignar la memoria, por lo tanto fallo la declaracion
    // y la operacion no fue exitosa. 
    if(variables_logico[identificador] == NULL)
        operacion_exitososa = false;
    
    // retornar el estado de la operacion.
    return operacion_exitososa;
}

// guarda en 'variables_caracter' un par identificador:valor
bool variables_declarar_caracter(string identificador){
    // esta variable es para verificar si operacion fue exitosa
    bool operacion_exitososa = true;

    // asignar espacio de memeria a 'variables_caracter[identificador]'
    variables_caracter[identificador] = new char;
    // agregar a tipos[] el identificador con su respectivo tipo de dato,
    // esto es util para asociar los identificadores a su correspondiente
    // tipo de dato.
    tipos[identificador] = CARACTER;

    // si 'variables_caracter[identificador]' es NULL es porque no el operador
    // new no pudo asignar la memoria, por lo tanto fallo la declaracion
    // y la operacion no fue exitosa. 
    if(variables_caracter[identificador] == NULL)
        operacion_exitososa = false;
    
    // retornar el estado de la operacion.
    return operacion_exitososa;
}

// guarda en 'variables_cadena' un par identificador:valor
bool variables_declarar_cadena(string identificador){
    // esta variable es para verificar si operacion fue exitosa
    bool operacion_exitososa = true;

    // asignar espacio de memeria a 'variables_cadena[identificador]'
    variables_cadena[identificador] = new string;
    // agregar a tipos[] el identificador con su respectivo tipo de dato,
    // esto es util para asociar los identificadores a su correspondiente
    // tipo de dato.
    tipos[identificador] = CADENA;

    // si 'variables_cadena[identificador]' es NULL es porque no el operador
    // new no pudo asignar la memoria, por lo tanto fallo la declaracion
    // y la operacion no fue exitosa. 
    if(variables_cadena[identificador] == NULL)
        operacion_exitososa = false;
    
    // retornar el estado de la operacion.
    return operacion_exitososa;
}


/* obtiene de 'variables_entero' un par identificador:valor y
retorna true si fue exitoso, y false si no existe el identificador*/
bool variables_obtener_entero(string identificador, int* variable){
    
    bool operacionExitosa = true;

    if(variables_entero.contains(identificador))
        *variable = *variables_entero[identificador];
    else
        operacionExitosa = false;

    return operacionExitosa;
}

/* obtiene de 'variables_real' un par identificador:valor y
retorna true si fue exitoso, y false si no existe el identificador*/
bool variables_obtener_real(string identificador, float* variable){
    
    bool operacionExitosa = true;

    if(variables_real.contains(identificador))
        *variable = *variables_entero[identificador];
    else
        operacionExitosa = false;

    return operacionExitosa;
}

// esta funcion retorna true si la variable fue declarada
bool variables_existe(string identificador){
    return tipos.contains(identificador);
}