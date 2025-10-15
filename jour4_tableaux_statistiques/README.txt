# Jour 4 – Tableaux et statistiques simples (version complète)

Ce programme permet de **saisir une série de nombres**, puis de calculer :  
- la **somme totale**  
- la **moyenne**  
- le **minimum**  
- le **maximum**  
- la **variance**  
- l’**écart-type**

Ce projet introduit la **manipulation de données numériques** en C++  
et prépare à des applications plus avancées en **analyse de données** 📈

---

## Objectifs pédagogiques

- Savoir **utiliser un tableau** pour stocker des données
- Parcourir un ensemble de valeurs avec une **boucle `for`**
- Calculer les **indicateurs statistiques** de base
- Apprendre la **variance** et l’**écart-type**
- Valider la saisie utilisateur

---

## Code source principal

```cpp
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

    // Calcul de la variance
    double variance = 0;
    for (int i = 0; i < n; i++) {
        variance += pow(tableau[i] - moyenne, 2);
    }
    variance /= n; // (pour un échantillon : variance /= n - 1)

    // Calcul de l'écart-type
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
   Exemple d’exécution

=== STATISTIQUES SUR UN TABLEAU DE NOMBRES ===
Combien de valeurs voulez-vous saisir ? 10

--- Saisie des valeurs ---
Valeur 1 : 56
Valeur 2 : 0.5
Valeur 3 : 79
Valeur 4 : 3
Valeur 5 : 56
Valeur 6 : 27
Valeur 7 : 2
Valeur 8 : 6.5
Valeur 9 : 99
Valeur 10 : 60

--- RESULTATS ---
Somme = 389
Moyenne = 38.9
Minimum = 0.5
Maximum = 99
Variance = 1156.64
Ecart-type = 34.0094

Fin du programme.