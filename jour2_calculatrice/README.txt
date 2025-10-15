# Jour 2 – Calculatrice simple

Ce programme est une **calculatrice basique en C++** qui effectue les opérations suivantes :  
➕ Addition  
➖ Soustraction  
✖️ Multiplication  
➗ Division  

---

## Objectifs pédagogiques
- Manipuler les **entrées utilisateur** avec `cin`
- Utiliser les **conditions et le switch**
- Gérer les **erreurs de division par zéro**
- Structurer un programme interactif simple

---

## Code source principal

```cpp
#include <iostream>
using namespace std;

int main() {
    double a, b;
    char op;

    cout << "=== CALCULATRICE SIMPLE ===" << endl;
    cout << "Entrez le premier nombre : ";
    cin >> a;

    cout << "Entrez l'operateur (+, -, *, /) : ";
    cin >> op;

    cout << "Entrez le second nombre : ";
    cin >> b;

    cout << "----------------------------" << endl;

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
            cout << "Operateur invalide." << endl;
    }

    cout << "----------------------------" << endl;
    cout << "Fin du programme." << endl;
    return 0;
}

   Exemple d’exécution

=== CALCULATRICE SIMPLE ===
Entrez le premier nombre : 8
Entrez l'operateur (+, -, *, /) : /
Entrez le second nombre : 2
----------------------------
8 / 2 = 4
----------------------------
Fin du programme.
