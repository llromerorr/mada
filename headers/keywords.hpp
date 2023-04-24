#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// estructuras
const string ALGORITMO = "algoritmo";
const string TIPOS = "constantes";
const string CONSTANTES = "constantes";
const string VARIABLES = "variables";
const string INICIO = "inicio";
const string FIN = "fin";

// tipos de datos
const string ENTERO = "entero";
const string REAL = "real";
const string LOGICO = "logico";
const string CADENA = "cadena";
const string ARCHIVO = "archivo";
const string ARREGLO = "arreglo";

// acciones nominadas
const string FUNCION = "funcion";
const string FIN_FUNCION = "ffuncion";
const string PROCEDIMIENTO = "procedimiento";
const string FIN_PROCEDIMIENTO = "fprocedimiento";

// Vector que contiene los tipos de datos basicos
vector<string> dataTypes {
    ENTERO,
    REAL,
    LOGICO
};

// Vector que contiene las palabras reservadas
vector<string> keywords = {
    // ESTRUCTURAS
    ALGORITMO,
    TIPOS,
    CONSTANTES,
    VARIABLES,
    INICIO,
    FIN,

    // TIPOS DE DATOS
    ENTERO,
    REAL,
    LOGICO,
    CADENA,
    ARCHIVO,
    ARREGLO,

    // ACCIONES NOMINADAS
    FUNCION,
    FIN_FUNCION,
    PROCEDIMIENTO,
    FIN_PROCEDIMIENTO
};

// Recibe un string 'dataType' y busca en los tipos de
// datos vector<string> dataTypes y determia si es un
// tipo de dato valido.
bool isDataType(string data_type){
    bool esValido = true;
    vector<string>::iterator it = find(dataTypes.begin(), dataTypes.end(), data_type);

    if(it == dataTypes.end())
        esValido = false;

    return esValido;
}