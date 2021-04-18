// - Domingo, 18 de abril del 2021 [01:30PM - 03:25PM]
// [2020-2021/B]
// - [EXAMEN 1 - A] Las Ilusiones de Volpina
// 
// - [03:06PM]: Como el pasado imprimía basura, mejor lo hice con VECTORES.
//
// - TYPES OF VALUES
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
// https://www.cplusplus.com/reference/string/to_string/
#include <string> // to_string
#include <vector>

using std::ios_base;
using std::cin;
using std::cout;
using std::vector;
// <string>
using std::to_string;

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
    // [person = a] en el ejercicio, pero así se me hace más significativo.
    
    vector<int> person; // ME IMPRIME BASURA EL ARREGLO. LO CAMBIARÉ POR VECTOR.

    for (int i = 0, personAux; i < n; i++) {
        cin >> personAux;
        person.push_back(personAux);
    }

    // VALOR ABSOLUTO PRODUCTO de los n números es menor o igual a 4*(10^18)
    // [producto n números <= 4*(10^18])]
/* -------------------------------------------------------------------------- */
    //
    //  https://www.mathsisfun.com/calculator-precision.html
    // 
    // CUATRILLÓN: Conjunto de un millón de trillones; se representa por un
    // seguido de veinticuatro ceros.
    // 
/* -------------------------------------------------------------------------- */
    // 1 SEGUIDO DE 21 CEROS: 
    // SEXTILLION en inglés
    // MIL TRILLONES
/* -------------------------------------------------------------------------- */
    // 
    // 1 SEGUIDO DE 18 CEROS: 
    // - SEGÚN LA RAE:
    // [TRILLÓN: MILLÓN DE BILLONES.]
    // 
    // [4*10^18 = 40,000,000,000,000,000,000 = 40T]
    // [40 SEGUIDO DE 18 CEROS]
    // 
    // [long long = __int64]:
    // [-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807]
    // [-9T <-> 9T]
    // 
    // [9*(10^18): 9 SEGUIDO DE 18 CEROS]
/* -------------------------------------------------------------------------- */

    // NÚMERO DE CADA PERSONA:
    // PRODUCTO DE LOS VALORES DE CADA PERSONA EXCEPTUANDO LA DEL ÍNDICE ACTUAL.
    // 
    // [personNumber = a_j en el ejercicio]
    // 
    // INICIALIZAMOS VECTOR CON n VALORES y TODOS SON = 1.
    vector<long long> personNumber(n, 1);

    // CALCULAR EL VALOR DE CADA PERSONA.
    for (int i = 0; i < n; i++)
        // Inicializando "personNumber[i]" en 1 no tendremos problemas al
        // multiplicar.
        // personNumber.push_back(1);
        for (int j = 0; j < n; j++)
            // NO HACER PRODUCTO DEL MISMO ÍNDICE QUE ESTÁ MULTIPLICANDO.

            // IDEA INICIAL:
            //  if (i == j) continue;
            // personNumber[i] *= person[j];

            // MEJOR UTILIZANDO OPERADORES TERNARIOS:
            // Si [i == j] -> MULTIPLICAR "personNumber[i]" por 1.
            // Si no -> MULTIPLICAR "personNumber[i]" por "person[j]"
            personNumber[i] *= (i == j) ? 1 : person[j];

    cout << "\n";

    // SALIDA: n números: Producto de todos los números a excepción del de
    // posición.
    // for (int number : person)
    for (int i = 0; i < n; i++) {
        // i != ÚLTIMO VALOR -> IMPRIMIR "personNumber[i]" + espacio en blanco.
        // Si no, imprimir solo el número sin el espacio.
        cout << ((i == (n - 1)) ? to_string(personNumber[i]) : to_string(personNumber[i]) + " ");
        // if (i == n - 1)
        //     cout << to_string(personNumber[i]);
        // else
        //     cout << to_string(personNumber[i]) + " ";

    }

    // cout << "\nTAMAÑO VECTORES: " << person.size() << "\n";
    // for (int i = 0; i < n; i++) {
    //     cout << "\n-> [person[" + to_string(i) + "] = " + to_string(person[i]) + "]\n";
    //     cout << "-> [personNumber[" + to_string(i) + "] = " + to_string(personNumber[i]) + "]\n";
    // }

    return 0;
}
