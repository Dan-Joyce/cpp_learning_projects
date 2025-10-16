#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int main() {
    srand(time(0));

    ofstream fichier("animaux.csv");
    if (!fichier) {
        cout << "Erreur lors de la création du fichier CSV !" << endl;
        return 1;
    }

    fichier << "id,espece,poids_kg,age_ans,temperature,produit\n";

    vector<string> especes = {"Chien", "Chat", "Cheval", "Vache", "Lapin"};
    vector<string> produits = {"Produit A", "Produit B", "Produit C", "Produit D", "Produit E"};

    for (int i = 1; i <= 2000; i++) {
        string espece = especes[rand() % especes.size()];
        string produit = produits[rand() % produits.size()];

        double poids = 0, temperature = 0;
        int age = rand() % 15 + 1;

        if (espece == "Chien") {
            poids = 8 + rand() % 20 + (rand() % 100) / 100.0;
            temperature = 37.5 + (rand() % 35) / 10.0;
        } else if (espece == "Chat") {
            poids = 2.5 + rand() % 5 + (rand() % 100) / 100.0;
            temperature = 38.0 + (rand() % 25) / 10.0;
        } else if (espece == "Cheval") {
            poids = 400 + rand() % 200 + (rand() % 100) / 10.0;
            temperature = 37.0 + (rand() % 25) / 10.0;
        } else if (espece == "Vache") {
            poids = 450 + rand() % 300 + (rand() % 100) / 10.0;
            temperature = 37.0 + (rand() % 20) / 10.0;
        } else if (espece == "Lapin") {
            poids = 1.0 + rand() % 4 + (rand() % 100) / 100.0;
            temperature = 38.5 + (rand() % 25) / 10.0;
        }

        fichier << i << "," << espece << "," << poids << "," << age << "," << temperature << "," << produit << "\n";
    }

    fichier.close();
    cout << " Fichier 'animaux.csv' généré avec succès (2000 lignes) !" << endl;
    return 0;
}
