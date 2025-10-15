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

    cout << "\nMerci d'avoir utilisé la calculatrice !" << endl;
    cout << "Fin du programme." << endl;

    return 0;
}
