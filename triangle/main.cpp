#include <iostream>
#include <cmath> // necessario per usare SRQT (SQUARE ROOT , radice quadrata)
#include <cstdlib> 
#include <ctime> // colori casuali
#include <windows.h> // per usare i colori

using namespace std;

// colori ANSI
string coloreAnsi(int colore) {
    switch (colore) {
        case 1: return "\033[31m"; // Rosso
        case 2: return "\033[32m"; // Verde
        case 3: return "\033[33m"; // Giallo
        case 4: return "\033[34m"; // Blu
        case 5: return "\033[35m"; // Magenta
        case 6: return "\033[36m"; // Ciano
        case 7: return "\033[37m"; // Bianco
    }
}

// Verifica se i lati possono formare un triangolo
bool verificaTriangolo(float a, float b, float c) {
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Determina il tipo di triangolo
string tipologiaTriangolo(float a, float b, float c) {
    if (a == b && b == c) {
        return "Equilatero";
    } else if (a == b || b == c || a == c) {
        return "Isoscele";
    } else {
        return "Scaleno";
    }
}

// Disegna il triangolo con le opzioni di colore
void disegnaTriangolo(float a, float b, float c, int sceltaColore) {
    string tipo = tipologiaTriangolo(a, b, c);
    string colore;
    
    // Gestione della scelta del colore unico
    if (sceltaColore == 1) {
        cout << "Scegli il colore (1-Rosso, 2-Verde, 3-Giallo, 4-Blu, 5-Magenta, 6-Ciano, 7-Bianco): ";
        int indiceColore;
        cin >> indiceColore;
        colore = coloreAnsi(indiceColore);
    }
    
    cout << "\nEcco la rappresentazione del triangolo " << tipo << ":\n\n";
    
    if (tipo == "Equilatero") { // equilatero
    int altezza = a; // Si usa la lunghezza del lato come altezza del triangolo.
    for (int i = 0; i < altezza; i++) {    
        // Stampa spazi iniziali per centrare il triangolo
        for (int j = 0; j < altezza - i; j++) {
            cout << " ";
        }
        // Stampa gli asterischi per ogni livello del triangolo
        for (int j = 0; j <= i * 2; j++) {
            switch (sceltaColore) {
                case 0: cout << "*"; break;  // Nessun colore
                case 1: cout << colore << "*"; break;  // Colore unico
                case 2: cout << coloreAnsi(rand() % 7 + 1) << "*"; break;  // Colore casuale fisso
                case 3: cout << coloreAnsi(rand() % 7 + 1) << "*"; break;  // Colori casuali diversi
            }
        }
        cout << "\033[0m" << endl; // Resetta il colore e va a capo
    }
} 
else if (tipo == "Isoscele") { // isoscele
    int altezza = max(max(a, b), c); // Usa il lato più lungo per determinare l'altezza
    for (int i = 0; i < altezza; i++) {    
        // Stampa spazi iniziali per centrare il triangolo
        for (int j = 0; j < altezza - i; j++) {
            cout << " ";
        }
        // Stampa gli asterischi per ogni livello del triangolo
        for (int j = 0; j <= i * 2; j++) {
            switch (sceltaColore) {
                case 0: cout << "*"; break;  // Nessun colore
                case 1: cout << colore << "*"; break;  // Colore unico
                case 2: cout << coloreAnsi(rand() % 7 + 1) << "*"; break;  // Colore casuale fisso
                case 3: cout << coloreAnsi(rand() % 7 + 1) << "*"; break;  // Colori casuali diversi
            }
        }
        cout << "\033[0m" << endl; // Resetta il colore e va a capo
    }
}
else {  // Scaleno
    cout << "Conosci gli angoli del triangolo scaleno? (s/n): ";
    char sceltaAngoli;
    cin >> sceltaAngoli;

    float angolo1, angolo2, angolo3;

    if (sceltaAngoli == 's') {
        cout << "Inserisci i tre angoli del triangolo scaleno in gradi: ";
        cin >> angolo1 >> angolo2 >> angolo3;
    } else {
        // Genera angoli casuali che sommano a 180
        angolo1 = 30 + (rand() % 60);  // 30-90 gradi
        angolo2 = 30 + (rand() % (int)(90 - angolo1)); // Assicura spazio per angolo3
        angolo3 = 180 - angolo1 - angolo2;  // Completa a 180

        cout << "Angoli generati casualmente:\n";
        cout << "Angolo 1: " << angolo1 << "gradi \n";
        cout << "Angolo 2: " << angolo2 << "gradi \n";
        cout << "Angolo 3: " << angolo3 << "gradi \n\n";
    }

    if (angolo1 + angolo2 + angolo3 == 180) {
        int altezza = max(max(a, b), c);
        int spaziBase = altezza / 2;

        for (int i = 0; i < altezza; i++) {    
            // Calcola gli spazi iniziali basandosi sugli angoli
            int spaziSinistra = spaziBase - (i * angolo1 / 60);

            for (int k = 0; k < spaziSinistra; k++) {
                cout << " ";
            }

            // Stampa gli asterischi per ogni livello del triangolo
            for (int j = 0; j <= i; j++) {
                switch (sceltaColore) {
                    case 0: cout << "* "; break;  // Nessun colore
                    case 1: cout << colore << "* "; break;  // Colore unico
                    case 2: cout << coloreAnsi(rand() % 7 + 1) << "* "; break;  // Colore casuale fisso
                    case 3: cout << coloreAnsi(rand() % 7 + 1) << "* "; break;  // Colori casuali diversi
                }
            }
            cout << "\033[0m" << endl; // Resetta il colore e va a capo
        }
    } else {
        cout << "Gli angoli devono sommare a 180 gradi!\n";
    }
    }    
}

// Calcola il perimetro del triangolo
float calcolaPerimetro(float a, float b, float c) {
    return a + b + c;
}

// Calcola l'area del triangolo usando la formula di Erone
float calcolaArea(float a, float b, float c) {
    float semiperimetro = calcolaPerimetro(a, b, c) / 2;
    return sqrt(semiperimetro * (semiperimetro - a) * (semiperimetro - b) * (semiperimetro - c));
}

int main() {
    srand(time(0)); 
    char continua = 's';

    while (continua == 's') {
        cout << "Inserisci le tre misure dei lati del triangolo: ";
        float a, b, c;
        cin >> a >> b >> c;

        if (verificaTriangolo(a, b, c)) {
            cout << "Le misure inserite formano un triangolo.\n";
            cout << "Il triangolo e': " << tipologiaTriangolo(a, b, c) << endl;

            cout << "\nScegli l'opzione di colore:\n";
            cout << "0. Nessun colore\n";
            cout << "1. Colore unico\n";
            cout << "2. Colore casuale per tutto il triangolo\n";
            cout << "3. Colori casuali diversi\n";
            
            int sceltaColore;
            cin >> sceltaColore;
            
            disegnaTriangolo(a, b, c, sceltaColore);

            cout << "Vuoi calcolare il perimetro e l'area del triangolo? (s/n): ";
            char scelta;
            cin >> scelta;

            if (scelta == 's') {
                cout << "Perimetro: " << calcolaPerimetro(a, b, c) << endl;
                cout << "Area: " << calcolaArea(a, b, c) << endl;
            }
        } else {
            cout << "Le misure inserite non formano un triangolo.\n";
        }

        cout << "Vuoi usare ancora il programma? (s/n): ";
        cin >> continua;
    }

    cout << "Alla prossima!\n";
    return 0;
}
