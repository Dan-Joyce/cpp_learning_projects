#include <iostream>
#include <fstream>   // pour lire et écrire des fichiers
#include <sstream>   // pour découper les lignes CSV
#include <vector>
#include <cmath>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(65001); // Force la console à UTF-8

    vector<double> valeurs;
    string ligne, cellule;
    double nombre;

    cout << "=== ANALYSE DE DONNEES CSV ===" << endl;

    ifstream fichier("donnees.csv");
    if (!fichier) {
        cout << "Erreur : le fichier 'donnees.csv' est introuvable !" << endl;
        return 1;
    }

    // 🔹 Lecture du fichier ligne par ligne
    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        while (getline(ss, cellule, ',')) {
            try {
                nombre = stod(cellule);
                valeurs.push_back(nombre);
            } catch (...) {
                // ignore les valeurs non numériques
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
    variance /= n;
    double ecart_type = sqrt(variance);

    // 🔹 Affichage console
    cout << "\n--- RESULTATS ---" << endl;
    cout << "Nombre de valeurs : " << n << endl;
    cout << "Somme = " << somme << endl;
    cout << "Moyenne = " << moyenne << endl;
    cout << "Minimum = " << min << endl;
    cout << "Maximum = " << max << endl;
    cout << "Variance = " << variance << endl;
    cout << "Ecart-type = " << ecart_type << endl;

    // 🔹 Sauvegarde dans un fichier texte
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
