#pragma once

#include <map>
#include <iostream>
#include "../headers/keywords.hpp"

using namespace std;

map<string, int*> variables_entero;
map<string, float*> variables_real;
map<string, string> tipos;

// guarda en 'variables_entero' un par identificador:valor
void variables_declarar_entero(string identificador){
    variables_entero[identificador] = new int;
    tipos[identificador] = ENTERO;
    // cout << variables_entero[identificador] << endl;
}

// guarda en 'variables_real' un par identificador:valor
// void variables_declarar_real(string identificador){
//     variables_real[identificador] = new float;
//     tipos[identificador] = REAL;
//     cout << variables_entero[identificador] << endl;
// }

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
// bool variables_obtener_real(string identificador, float* variable){
    
//     bool operacionExitosa = true;

//     if(variables_real.contains(identificador))
//         *variable = *variables_entero[identificador];
//     else
//         operacionExitosa = false;

//     return operacionExitosa;
// }