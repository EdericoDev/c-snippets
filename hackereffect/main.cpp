#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Funzione per ottenere il codice colore ANSI
string getAnsiColor(int color) {
    switch (color) {
        case 1: return "\033[31m"; // Rosso
        case 2: return "\033[32m"; // Verde
        case 3: return "\033[33m"; // Giallo
        case 4: return "\033[34m"; // Blu
        case 5: return "\033[35m"; // Magenta
        case 6: return "\033[36m"; // Ciano
        case 7: return "\033[37m"; // Bianco
    }
}

int main() {
    srand(time(0));

    char useagain = 's';
    while (useagain == 's') {

    cout << "Scegli un'opzione:\n";
    cout << "1. Colore unico per tutta la stringa\n";
    cout << "2. Colore casuale per tutta la stringa\n";
    cout << "3. Colore casuale per ogni carattere\n";
    int choice;
    cin >> choice;

    cout << "Scrivi una parola: ";
    string phrase;
    cin >> phrase;

    string chars = "!@#$%^&*()_+=-0987654321abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string selectedColor;

    if (choice == 1) {
        cout << "Scegli il colore (1-Rosso, 2-Verde, 3-Giallo, 4-Blu, 5-Magenta, 6-Ciano, 7-Bianco): ";
        int colorIndex;
        cin >> colorIndex;
        selectedColor = getAnsiColor(colorIndex);
    } else if (choice == 2) {
        int randomColor = rand() % 7 + 1; // Colore casuale (da 1 a 7)
        selectedColor = getAnsiColor(randomColor);
    }

    for (int i = 0; i < phrase.length(); i++) {
        for (int j = 0; j < phrase.length(); j++) {
            cout << "\r";
            string temp = phrase;
            for (int k = i + 1; k < phrase.length(); k++) {
                temp[k] = chars[rand() % chars.length()];
            }

            // Mostra il risultato con il colore selezionato
            if (choice == 3) { // Colore casuale per ogni carattere
                for (char c : temp) {
                    int randomColor = rand() % 7 + 1;
                    cout << getAnsiColor(randomColor) << c;
                }
            } else { // Colore unico
                cout << selectedColor << temp;
            }
            cout << "\033[0m" << flush; // Resetta il colore
            Sleep(50);
        }
    }
    cout << endl;
    cout << " vuoi usare il programma di nuovo? (s/n): ";
    cin >> useagain;
    }
    
    return 0;
}

