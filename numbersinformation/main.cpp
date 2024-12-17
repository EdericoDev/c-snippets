#include <iostream>

using namespace std;

int multipli (int numero) {
    cout << "multipli\n";
    for (int i = 1; i <= 10; i++) {
        cout << numero * i << endl;
    }
}

int divisori (int numero) {
    cout << "divisori\n";
    for (int i = 1; i <= numero; i++) {
        if (numero % i == 0) {
            cout << i << endl;
        }
    }
}

bool primo(int numero) {
    cout << "e' primo?\n";
    if (numero <= 1) {
        cout << "1 o meno di 0 non si considerano come primi" << endl;
        return false;
    }
    for (int i = 2; i < numero; i++) {
        if (numero % i == 0) {
            cout << "non e' primo" << endl;
            return false;
        }
    }
    cout << "e' primo" << endl;
    return true;
}

string romano (int numero) {
    string romano;

    if (numero < 1 || numero > 10) {
        cout << "per scrivere tutti i numeri romani e' un parto , ringrazia che l'ho fatto fino a 10. \n" << endl;
    }

    switch (numero) {
        case 1:
            romano = "I";
            break;
        case 2:
            romano = "II";
            break;
        case 3:
            romano = "III";
            break;
        case 4:
            romano = "IV";
            break;
        case 5:
            romano = "V";
            break;
        case 6:
            romano = "VI";
            break;
        case 7:
            romano = "VII";
            break;
        case 8:
            romano = "VIII";
            break;
        case 9:
            romano = "IX";
            break;
        case 10:
            romano = "X";
            break;
        }
}

int main () {
    int numero;
    cout << "scrivi un numero INTERO e ti daro' tutte le informazioni circa multipli fino al decimo , divisori , se e' primo o no , come si scrive in numero romano. ";
    cin >> numero;

    multipli (numero); //ritorna i multipli
    divisori (numero); // ritorna i divisori 
    primo (numero); // ritorna se è primo o no.
    romano (numero); // numero romano da 1 a 10.
    

    return 0;
}