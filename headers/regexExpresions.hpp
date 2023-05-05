#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

// POSIBLES TIPOS DE LINEAS
const regex POSIBLE_DECLARACION_SIMPLE("^[ \t]*([^ \t]*)[ \t]*:[ \t]*([^ \t]*)[ \t]*$");
const regex POSIBLE_DECLARACION_MULTIPLE("^[\t ]*[^,]+([\t ]*,[\t ]*[a-z]+)+[\t ]*:([^:]*)$");

// identificador de variables, constantes, etc...
const regex IDENTIFICADOR("^[a-zA-Z_][a-zA-Z0-9_]*$");