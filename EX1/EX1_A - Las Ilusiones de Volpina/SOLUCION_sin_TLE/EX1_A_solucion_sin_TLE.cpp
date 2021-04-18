// - Domingo, 18 de abril del 2021 [03:51PM - 04:09PM]
// - [EXAMEN 1 - A] Las Ilusiones de Volpina
// 
// Hago este nuevo archivo para implementar una solución diferente y optimizda,
// porque al subir el ejercicio siempre me sale un TLE (Time Limit Exceeded).
//
//  - TYPES OF VALUES
// 
// [10^9 = 1,000,000,000] <- [1B = 1KM] <- It is in [int] range of numbers
// [10^7 = 10,000,000] <- [10M]
// 
// SOURCE OF RANGE IN TYPES OF NUMBERS:
// https://docs.microsoft.com/en-us/cpp/cpp/data-type-ranges?view=msvc-160
// 
// [int] range of values:
// [-2,147,483,648 to 2,147,483,647]
// 
// [unsigned int] range of values:
// [0 to 4,294,967,295]
// 

#include <iostream> // cin, cout

using std::ios_base;
using std::cin;
using std::cout;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // [1 < n < 10^7]
    // [10^7 = 10,000,000]
    // unsigned int: [0 to 4,294,967,295]
    unsigned int n;

    cin >> n;

    // n numbers [-10^9 <= a_i <= 10^9]
    // [10^9 = 1,000,000,000 = 1B]
    // int: [-2,147,483,648 to 2,147,483,647]
    // int: -2B <-> 2B
    // 
    // [persons = a] en el ejercicio, pero así se me hace más significativo.
    
    // https://stackoverflow.com/questions/51006518/using-cin-to-input-array-values/51006673
    // 
    // "The important parts are creating the array dynamically, using the
    // statement and passing the wished size."
    int *persons = new int[n];

    // VALOR ABSOLUTO PRODUCTO de los n números es menor o igual a 4*(10^18)
    // [producto n números <= 4*(10^18])]
    // NÚMERO DE CADA PERSONA:
    // PRODUCTO DE LOS VALORES DE CADA PERSONA EXCEPTUANDO LA DEL ÍNDICE ACTUAL.
    // 
    // [personNumber = a_j en el ejercicio]
    long long *personNumber = new long long[n];

    // Inicializamos arreglo con 1 para poder multiplicar.
    for (int i = 0; i < n; i++)
        personNumber[i] = 1;

    for (int i = 0; i < n; i++) {
        cin >> persons[i];
        // Multiplicamos el número de cada persona por el valor actual de la persona.
        for (int j = 0; j < n; j++)
            personNumber[j] *= (i == j) ? 1 : persons[i];
    }

    cout << "\n";

    // SALIDA: n números: Producto de todos los números a excepción del de
    // posición.
    for (int i = 0; i < n; i++)
        // i != ÚLTIMO VALOR -> IMPRIMIR "personNumber[i]" + espacio en blanco.
        // Si no, imprimir solo el número sin el espacio.
        cout << personNumber[i] << ((i == (n - 1)) ? "" : " ");

    // cout << "\nTAMAÑO VECTORES: " << persons.size() << "\n";
    // for (int i = 0; i < n; i++) {
    //     cout << "\n-> [persons[" + to_string(i) + "] = " + to_string(persons[i]) + "]\n";
    //     cout << "-> [personNumber[" + to_string(i) + "] = " + to_string(personNumber[i]) + "]\n";
    // }

    return 0;
}
