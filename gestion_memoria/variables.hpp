#include <map>
#include <iostream>
#include "../headers/keywords.hpp"

using namespace std;

map<string, int> variables_entero;
map<string, string> tipos;

// guarda en 'variables_entero' un par identificador:valor
void variables_definir_entero(string identificador, int valor){
    variables_entero[identificador] = valor;
    tipos[identificador] = ENTERO;
}

/* obtiene de 'variables_entero' un par identificador:valor y
retorna true si fue exitoso, y false si no existe el identificador*/
bool variables_obtener_entero(string identificador, int* variable){
    
    bool operacionExitosa = true;

    if(variables_entero.contains(identificador))
        *variable = variables_entero[identificador];
    else
        operacionExitosa = false;

    return operacionExitosa;
}