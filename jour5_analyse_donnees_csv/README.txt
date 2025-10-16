# Jour 5 – Analyse de données CSV (lecture, statistiques, export)

Ce programme lit un fichier **CSV** contenant des valeurs numériques,  
calcule automatiquement plusieurs **indicateurs statistiques**,  
et enregistre les résultats dans un fichier texte (`resultats.txt`).

---

##  Objectifs pédagogiques

- Manipuler les fichiers texte (`ifstream`, `ofstream`)
- Découper les lignes CSV avec `stringstream`
- Utiliser des **tableaux dynamiques (`vector`)**
- Calculer des statistiques descriptives :
  - Somme
  - Moyenne
  - Minimum / Maximum
  - Variance
  - Écart-type
- Corriger les problèmes d’**encodage UTF-8** pour afficher les accents en console

---

## Code source principal

```cpp
#include <iostream>
#include <fstream>   // lecture/écriture de fichiers
#include <sstream>   // découpage des lignes CSV
#include <vector>
#include <cmath>
#include <windows.h> // pour corriger l'affichage UTF-8
using namespace std;

int main() {
    SetConsoleOutputCP(65001); // Active l'encodage UTF-8 dans la console

    vector<double> valeurs;
    string ligne, cellule;
    double nombre;

    cout << "=== ANALYSE DE DONNEES CSV ===" << endl;

    ifstream fichier("donnees.csv");
    if (!fichier) {
        cout << "Erreur : le fichier 'donnees.csv' est introuvable !" << endl;
        return 1;
    }

    //  Lecture du fichier ligne par ligne
    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        while (getline(ss, cellule, ',')) {
            try {
                nombre = stod(cellule);
                valeurs.push_back(nombre);
            } catch (...) {
                // Ignore les valeurs non numériques
            }
        }
    }
    fichier.close();

    int n = valeurs.size();
    if (n == 0) {
        cout << "Aucune donnée valide trouvée dans le fichier !" << endl;
        return 0;
    }

    double somme = 0, min = valeurs[0], max = valeurs[0];
    for (double v : valeurs) {
        somme += v;
        if (v < min) min = v;
        if (v > max) max = v;
    }

    double moyenne = somme / n;
    double variance = 0;
    for (double v : valeurs) {
        variance += pow(v - moyenne, 2);
    }
    variance /= n; // Pour une population entière
    double ecart_type = sqrt(variance);

    //  Affichage console
    cout << "\n--- RESULTATS ---" << endl;
    cout << "Nombre de valeurs : " << n << endl;
    cout << "Somme = " << somme << endl;
    cout << "Moyenne = " << moyenne << endl;
    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;
    cout << "Variance = " << variance << endl;
    cout << "Ecart-type = " << ecart_type << endl;

    //  Sauvegarde dans un fichier texte
    ofstream sortie("resultats.txt");
    sortie << "=== STATISTIQUES DES DONNEES CSV ===\n";
    sortie << "Nombre de valeurs : " << n << "\n";
    sortie << "Somme = " << somme << "\n";
    sortie << "Moyenne = " << moyenne << "\n";
    sortie << "Minimum = " << min << "\n";
    sortie << "Maximum = " << max << "\n";
    sortie << "Variance = " << variance << "\n";
    sortie << "Ecart-type = " << ecart_type << "\n";
    sortie.close();

    cout << "\nLes résultats ont été enregistrés dans 'resultats.txt' ✅" << endl;

    return 0;
}

  Exemple d’exécution

=== ANALYSE DE DONNEES CSV ===

--- RESULTATS ---
Nombre de valeurs : 25
Somme = 234
Moyenne = 9.36
Minimum = 4
Maximum = 15
Variance = 7.9104
Ecart-type = 2.81254

Les résultats ont été enregistrés dans 'resultats.txt' ✅

