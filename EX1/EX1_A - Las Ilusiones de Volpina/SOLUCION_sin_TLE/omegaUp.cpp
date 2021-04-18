// [04:22PM] No logré resolverlo sin el TLE-

#include <iostream> // cin, cout

using std::ios_base;
using std::cin;
using std::cout;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    unsigned int n;

    cin >> n;

    int *persons = new int[n];
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

    for (int i = 0; i < n; i++)
        cout << personNumber[i] << ((i == (n - 1)) ? "" : " ");

    return 0;
}
