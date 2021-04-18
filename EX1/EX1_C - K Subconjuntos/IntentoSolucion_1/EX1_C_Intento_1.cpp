// Domingo, 18 ABRIL 2021 [04:46PM]
// REQUERIMOS VECTOR DE VECTORES PARA GUARDAR LOS ELEMENTOS QUE YA SE HAYAN
// COMBINADO.
// 
// [06:04PM] <- NO LOGRÉ TERMINARLO Y SE ME ACABÓ EL TIEMPO DEL EXAMEN.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cin;
using std::cout;
using std::ios_base;
using std::string;
using std::vector;
// Ordenar los caracteres.
using std::sort;
using std::count;

vector<char> sortString(string stringToSort);
int factorial(int number);
bool **allocateMatrix(int rows, int cols);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Cadena de caracteres.
    string charsString;
    // Vector con los caracteres ordenados.
    vector<char> sortedChars;
    // Subconjuntos.
    // Vector en donde guardaremos las cadenas que ya se hicieron para cada
    // caracter.
    // a[0][0] = {"ab"}
    // alreadyCombined[0][1] = true
    // alreadyCombined[1][0] = true
    vector<string> combinations;

    // Número de caracteres de la cadena, longitud de cada subconjunto.
    int charsNum, kLength;

    cin >> charsNum >> kLength;
    cin >> charsString;

    charsNum = charsString.size();
    // SUBCONJUNTOS de LONGITUD "k" cadena de longitud "n".
    // (n!) / (k! * (n - k)!)
    int subconjuntos = (factorial(charsNum)) / (factorial(kLength) * factorial(charsNum - kLength));

    // Caracteres ordenados en vector.
    sortedChars = sortString(charsString);

    makeSubsets(charsString);

    return 0;
}

// Crear los subconjuntos
vector<string> makeSubsets(string chars, int k) {
    // Combinaciones ya realizadas.
    vector< vector<char> > combinations;
    bool canCreateSubsets = true;
    int currentChar = 0;

    for (int i = 0; i < chars.size(); i++) {
        currentChar = 0;
        // Mientras se puedan seguir haciendo combinaciones.
        while (canCreateSubsets) {
            // Agregamos el caracter correspondiente a su índice.
            combinations.push_back(chars[i]);
            for (int j = currentChar; j < chars.size(); j++) {
                // Si el caracter ya se había combinado con el actual, no combinar.
                if (!count(combinations[j].begin(), combinations[j].end(), chars[i])) {
                    // Ya combinamos el caracter i con el j.
                    combinations[i].push_back(chars[j]);
                }
            }
            // Si el caracter
            if (currentChar + k >= chars.size()) {
                currentChar++;
                canCreateSubsets = false;
            }
        }
    }

}

// Ingresar los caracteres a un vector y utlizar la función "sort()".
vector<char> sortString(string stringToSort) {
    vector<char> aux;
    for (int i = 0; i < stringToSort.size(); i++)
        aux.push_back(stringToSort[i]);
    return aux;
}

// FACTORIAL
int factorial(int number) {
    if (number == 0) return 0;
    return (number == 1) ? 1: number * (factorial(number - 1));
}

// RESERVAR MEMORIA PARA ARREGLO DINÁMICO.
bool **allocateMatrix(int rows, int cols) {
    bool** matrix = new bool*[rows];
    for (int i = 0; i < rows; ++i)
        matrix[i] = new bool[cols];
    return matrix;
}
