#include <iostream>
#include <string>

using namespace std;
int main() {

    int failTry = 10;
    int tries = 0;
    int knownChars = 0;
    string word;

    string input;
    cout << "Bitte waehle ein Wort, welches erraten werden soll: ";
    cin >> input;

    //Eingabe in Großbuchstaben umwandeln
    for(int index=0; index < input.size(); index++) {
        word += toupper(input[index]);
    }

    short wordSize = word.size();
    string guessedWord;
    for(int i=0;i<wordSize;i++)
    {
        guessedWord.append("_");
    }

    while (failTry > 0 && knownChars < wordSize) {
        cout << "Welches Wort suchen wir? " << guessedWord << endl;
        cout << "Errate nun einen Buchstaben " << failTry << " Versuche hast du noch!" << endl;

        char tryLetter;
        cin >> tryLetter;
        tryLetter = toupper(tryLetter);
        tries++;

        if(word.find(tryLetter) == string::npos) {
            cout << "Dieser Buchstabe war leider falsch. Probiere es nochmal!" << endl;
            failTry--;
        }
        else {
            for (int i = 0; i < wordSize; i++) {
                if (word.find(tryLetter, i) != string::npos) {
                    guessedWord[word.find(tryLetter, i)] = tryLetter;
                    i = word.find(tryLetter, i);
                    knownChars++;
                } else {
                    break;
                }
            }
        }
    }
    if(knownChars == wordSize) {
        cout << "Sehr gut gemacht. Du hast das Wort " << word << " richtig erraten!" << endl << "Du hast das " << tries << " Versuche gebraucht!";
    }
    else {
        cout << "Leider verloren. Probiere es erneut!" << endl;
    }
    return 0;
}
