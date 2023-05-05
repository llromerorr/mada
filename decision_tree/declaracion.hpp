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

bool declaracionSimple(string linea, int numero_linea)
{
    bool esValida = true;
    string identificador = fullStripString(linea.substr(0, linea.find(':')));
    string tipoDeDato = fullStripString(linea.substr(linea.find(':') + 1, linea.length()));

    // verificar si el identificador es valido
    if (regex_match(identificador, IDENTIFICADOR))
    {
        // verificar si el identificador pertenece a una variable ya existente
        if(!variables_existe(identificador))
        {
            // verificar si el tipo de dato es valido
            if (isDataType(tipoDeDato))
            {
                // En caso de no poder asignar el espacio de memoria
                // para almacenar la variable, 'variables_declarar()'
                // retorna falso y a continuacion se muestra un error
                if (!variables_declarar(identificador, tipoDeDato))
                {
                    error_memoria_insuficiente(identificador, tipoDeDato, numero_linea);
                    esValida = false;
                }
            }

            // El tipo de dato es valido
            else
            {
                error_tipoDeDato_invalido(tipoDeDato, numero_linea);
                esValida = false;
            }
        }

        // mostrar error de redeclaracion porque el identificador ya esta en uso
        else
        {
            error_identificador_redeclaracion(identificador, numero_linea);
            esValida = false;
        }
    }

    // El identificador no es valido
    else
    {
        error_identificador_invalido(identificador, numero_linea);
        esValida = false;
    }

    return esValida;
}

// ESTA FUNCION NO ESTA COMPLETADA
bool declaracionMultiple(string linea, int numero_linea)
{
    bool esValida = true;
    vector<string> identificadores = splitString(fullStripString(linea.substr(0, linea.find(':'))), ',');
    string tipoDeDato = fullStripString(linea.substr(linea.find(':') + 1, linea.length()));

    for (size_t i = 0; i < identificadores.size(); i++)
    {
        // verificar si el identificador es valido
        if (regex_match(identificadores[i], IDENTIFICADOR))
        {
            // verificar si el identificador pertenece a una variable ya existente
            if(!variables_existe(identificadores[i]))
            {
                // verificar si el tipo de dato es valido
                if (isDataType(tipoDeDato))
                {
                    // En caso de no poder asignar el espacio de memoria
                    // para almacenar la variable, 'variables_declarar()'
                    // retorna falso y a continuacion se muestra un error
                    if (!variables_declarar(identificadores[i], tipoDeDato))
                    {
                        error_memoria_insuficiente(identificadores[i], tipoDeDato, numero_linea);
                        esValida = false;
                        break;
                    }
                }

                // El tipo de dato es valido
                else
                {
                    error_tipoDeDato_invalido(tipoDeDato, numero_linea);
                    esValida = false;
                    break;
                }
            }

            // mostrar error de redeclaracion porque el identificador ya esta en uso
            else
            {
                error_identificador_redeclaracion(identificadores[i], numero_linea);
                esValida = false;
            }
        }

        // El identificador no es valido
        else
        {
            error_identificador_invalido(identificadores[i], numero_linea);
            esValida = false;
            break;
        }
    }

    return esValida;
}