#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

int main() {
    srand(time(0));
    
    char lang[2];
    GetLocaleInfoA(LOCALE_USER_DEFAULT, LOCALE_SISO639LANGNAME, lang, 2);
    
    string phrase;
    if (lang[0] == 'i')      
        phrase = "l'informatica e' bellissima";
    else if (lang[0] == 'f') 
        phrase = "Bonjour monde";
    else if (lang[0] == 'd') 
        phrase = "Hallo Welt";
    else                     
        phrase = "ICT is goated";
    
    string chars = "!@#$%^&*()_+=-0987654321abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    
    for (int i = 0; i < phrase.length(); i++) {
        for (int j = 0; j < 10; j++) {
            cout << "\r";
            string temp = phrase;
            for (int k = i + 1; k < phrase.length(); k++) {
                temp[k] = chars[rand() % chars.length()];
            }
            cout << temp << flush;
            Sleep(50);
        }
    }
    cout << endl;
    return 0;
}
