# Jour 3 – Calculatrice améliorée

Ce projet améliore la calculatrice du **Jour 2** en la rendant **interactive** et **plus robuste**.  
Le programme permet d’enchaîner plusieurs calculs sans quitter,  
et gère les erreurs comme la **division par zéro** ou un **opérateur invalide**.

---

## Objectifs pédagogiques

- Découvrir la **boucle `do … while`**  
- Gérer la **validation des entrées utilisateur**  
- Créer un **programme interactif** et ergonomique  
- Consolider l’utilisation du `switch` et des conditions imbriquées

---

## Code source principal

```cpp
#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;
    char choix;

    cout << "=== CALCULATRICE AMELIOREE ===" << endl;

    do {
        cout << "\nEntrez le premier nombre : ";
        cin >> a;

        cout << "Entrez l'operateur (+, -, *, /) : ";
        cin >> op;

        cout << "Entrez le second nombre : ";
        cin >> b;

        cout << "------------------------------" << endl;

        switch (op) {
            case '+':
                cout << a << " + " << b << " = " << a + b << endl;
                break;
            case '-':
                cout << a << " - " << b << " = " << a - b << endl;
                break;
            case '*':
                cout << a << " * " << b << " = " << a * b << endl;
                break;
            case '/':
                if (b != 0)
                    cout << a << " / " << b << " = " << a / b << endl;
                else
                    cout << "Erreur : division par 0 impossible !" << endl;
                break;
            default:
                cout << "Operateur invalide. Utilisez +, -, *, ou /" << endl;
        }

        cout << "------------------------------" << endl;
        cout << "Voulez-vous faire un autre calcul ? (o/n) : ";
        cin >> choix;

    } while (choix == 'o' || choix == 'O');

    cout << "\nMerci d'avoir utilise la calculatrice !" << endl;
    cout << "Fin du programme." << endl;

    return 0;
}


   Exemple d’exécution

=== CALCULATRICE AMELIOREE ===

Entrez le premier nombre : 8
Entrez l'operateur (+, -, *, /) : *
Entrez le second nombre : 3
------------------------------
8 * 3 = 24
------------------------------
Voulez-vous faire un autre calcul ? (o/n) : o

Entrez le premier nombre : 10
Entrez l'operateur (+, -, *, /) : /
Entrez le second nombre : 0
------------------------------
Erreur : division par 0 impossible !
------------------------------
Voulez-vous faire un autre calcul ? (o/n) : n

Merci d'avoir utilise la calculatrice !
Fin du programme.
