#include <iostream>
#include <vector>
#include "headers/fileController.hpp"
#include "headers/lineController.hpp"
#include "headers/regexExpresions.hpp"
#include "gestion_memoria/variables.hpp"
#include <regex>
#include <map>

using namespace std;

int main(int argc, char * argv[]){
    vector<string> lineas = fileToVector(argv[1]);

    for (int i = 0; i < lineas.size(); i++){
        if(!indentificarLinea(lineas[i], i)){
            break;
        }
    }

    return 0;
}