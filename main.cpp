// clear && g++ main.cpp -std=c++20 -o a.out && ./a.out ./examples/1.mc && rm ./a.out

#include <iostream>
#include <vector>
#include "headers/fileController.hpp"
#include "headers/lineController.hpp"
#include "headers/regexExpresions.hpp"
#include "gestion_memoria/variables.hpp"
#include "decision_tree/identificarLinea.hpp"
#include <cstdlib>

int main(int argc, char *argv[])
{
    // Vector que contiene todas las lineas del archivo .mc
    vector<string> lineas = fileToVector(argv[1]);

    for (int i = 0; i < lineas.size(); i++)
        // si se encuentra algun error detener el interprete
        if (!indentificarLinea(lineas[i], i))
            break;

    return EXIT_SUCCESS;
}