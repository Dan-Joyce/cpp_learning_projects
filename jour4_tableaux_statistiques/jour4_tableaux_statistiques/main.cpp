#include <iostream>
#include <cmath> // pour sqrt() et pow()
using namespace std;

int main() {
    int n;

    cout << "=== STATISTIQUES SUR UN TABLEAU DE NOMBRES ===" << endl;
    cout << "Combien de valeurs voulez-vous saisir ? ";
    cin >> n;

    if (n <= 0) {
        cout << "Le nombre de valeurs doit etre positif !" << endl;
        return 0;
    }

    double tableau[n];
    double somme = 0;
    double min, max;

    cout << "\n--- Saisie des valeurs ---" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Valeur " << i + 1 << " : ";
        cin >> tableau[i];
        somme += tableau[i];

        if (i == 0) {
            min = max = tableau[i];
        } else {
            if (tableau[i] < min) min = tableau[i];
            if (tableau[i] > max) max = tableau[i];
        }
    }

    double moyenne = somme / n;

    // 🔹 Calcul de la variance
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += pow(tableau[i] - moyenne, 2);
    }
    variance /= n; // variance pour la population entière (si échantillon, utiliser n-1)

    // 🔹 Calcul de l'écart-type
    double ecart_type = sqrt(variance);

    cout << "\n--- RESULTATS ---" << endl;
    cout << "Somme = " << somme << endl;
    cout << "Moyenne = " << moyenne << endl;
    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;
    cout << "Variance = " << variance << endl;
    cout << "Ecart-type = " << ecart_type << endl;

    cout << "\nFin du programme." << endl;
    return 0;
}
