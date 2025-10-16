#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <cmath>
#include <windows.h>
using namespace std;

struct Animal {
    string espece;
    double poids;
    int age;
    double temperature;
    string produit;
};

struct Stats {
    double somme_poids = 0;
    double somme_temp = 0;
    double somme_poids_carre = 0;
    double somme_temp_carre = 0;
    double somme_poids_temp = 0;
    int nb = 0;
    double min_poids = 1e9, max_poids = 0;
    double min_temp = 1e9, max_temp = 0;
};

int main() {
    SetConsoleOutputCP(65001);

    ifstream fichier("animaux.csv");
    if (!fichier) {
        cout << "Erreur : fichier 'animaux.csv' introuvable !" << endl;
        return 1;
    }

    vector<Animal> data;
    string ligne;
    getline(fichier, ligne); // ignorer l’en-tête

    while (getline(fichier, ligne)) {
        stringstream ss(ligne);
        Animal a;
        string tmp;

        getline(ss, tmp, ','); // id
        getline(ss, a.espece, ',');
        getline(ss, tmp, ','); a.poids = stod(tmp);
        getline(ss, tmp, ','); a.age = stoi(tmp);
        getline(ss, tmp, ','); a.temperature = stod(tmp);
        getline(ss, a.produit, ',');

        data.push_back(a);
    }
    fichier.close();

    if (data.empty()) {
        cout << "Aucune donnée trouvée !" << endl;
        return 0;
    }

    // 🔹 Calcul statistiques par espèce
    map<string, Stats> stats;
    for (auto &a : data) {
        auto &s = stats[a.espece];
        s.nb++;
        s.somme_poids += a.poids;
        s.somme_temp += a.temperature;
        s.somme_poids_carre += a.poids * a.poids;
        s.somme_temp_carre += a.temperature * a.temperature;
        s.somme_poids_temp += a.poids * a.temperature;
        s.min_poids = min(s.min_poids, a.poids);
        s.max_poids = max(s.max_poids, a.poids);
        s.min_temp = min(s.min_temp, a.temperature);
        s.max_temp = max(s.max_temp, a.temperature);
    }

    // 🔹 Analyse et corrélation
    ofstream out("analyse_complete.txt");
    out << "=== ETUDE STATISTIQUE ET CORRELATION ANIMALE ===\n\n";
    cout << "=== ETUDE STATISTIQUE ET CORRELATION ANIMALE ===\n\n";

    for (auto &p : stats) {
        string espece = p.first;
        Stats s = p.second;
        double moy_poids = s.somme_poids / s.nb;
        double moy_temp = s.somme_temp / s.nb;

        double var_poids = (s.somme_poids_carre / s.nb) - pow(moy_poids, 2);
        double var_temp = (s.somme_temp_carre / s.nb) - pow(moy_temp, 2);
        double cov = (s.somme_poids_temp / s.nb) - (moy_poids * moy_temp);
        double corr = cov / (sqrt(var_poids * var_temp));

        cout << "Espèce : " << espece << endl;
        cout << " - N : " << s.nb << endl;
        cout << " - Poids (moy/min/max) : " << moy_poids << " / " << s.min_poids << " / " << s.max_poids << " kg" << endl;
        cout << " - Température (moy/min/max) : " << moy_temp << " / " << s.min_temp << " / " << s.max_temp << " °C" << endl;
        cout << " - Corrélation poids-température : " << corr << endl << endl;

        out << "Espèce : " << espece << "\n";
        out << " - Nombre : " << s.nb << "\n";
        out << " - Poids moyen : " << moy_poids << " kg\n";
        out << " - Température moyenne : " << moy_temp << " °C\n";
        out << " - Corrélation poids-température : " << corr << "\n\n";
    }

    // 🔹 Détection des anomalies
    cout << "=== ANIMAUX AVEC VALEURS ANORMALES ===" << endl;
    out << "=== ANIMAUX AVEC VALEURS ANORMALES ===\n";

    for (auto &a : data) {
        if (a.temperature > 39.5 || a.temperature < 37 || a.poids <= 0) {
            cout << a.espece << " (" << a.produit << ") - T°: " << a.temperature << "°C, Poids: " << a.poids << " ⚠️" << endl;
            out << a.espece << " (" << a.produit << ") - T°: " << a.temperature << "°C, Poids: " << a.poids << "\n";
        }
    }

    cout << "\nRésultats complets enregistrés dans 'analyse_complete.txt' ✅" << endl;
    out.close();
    return 0;
}
