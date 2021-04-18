// ESTA ES LA SOLUCIÓN QUE ENVIÉ A OmegaUp como respuesta de la pregunta en el
// examen.
// 
// LA SUBÍ A LAS [03:29PM] <- ME DIO [TLE - Time Limit Exceded]

#include <iostream> // cin, cout
// #include <string> // to_string
#include <vector>

using std::ios_base;
using std::cin;
using std::cout;
using std::vector;
// // <string>
// using std::to_string;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned int n;
    vector<int> person;

    cin >> n;

    for (int i = 0, personAux; i < n; i++) {
        cin >> personAux;
        person.push_back(personAux);
    }

    vector<long long> personNumber(n, 1);
    for (int i = 0; i < n; i++)
        // Inicializando "personNumber[i]" en 1 no tendremos problemas al
        // multiplicar.
        for (int j = 0; j < n; j++)
            personNumber[i] *= (i == j) ? 1 : person[j];

    cout << "\n";

    for (int i = 0; i < n; i++)
        cout << personNumber[i] << ((i == (n - 1)) ? "" : " ");

    return 0;
}
