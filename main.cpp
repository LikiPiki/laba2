#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string filename = "text.txt";

bool checkSentence(string &line, string &word);
bool goodRune(char rune);

int main() {
    cout << "Enter a finding world" << endl;
    string word;
    cin >> word;

    ifstream file;
    file.open(filename, ios_base::in);

    string line;
    string phrase = "";
    while (getline(file, line)) {
        for (char i : line) {
            if (i == '.') {
                cout << "phrase" << phrase << endl;
                if (checkSentence(phrase, word)) {
                    cout << "finded" << phrase << endl;
                }
                phrase = "";
            }
            else {
                phrase += i;
            }

        }
    }


    file.close();
    return 0;
}

bool checkSentence(string &line, string &word) {
    // do something here
    istringstream st(line);
    string subWord;

    while (true) {
        st >> subWord;
        if (st.eof()) {
            break;
        }
        string copy = "";
        int k = 0;
        for (char i : subWord) {
            cout << "copying" << i << endl;
            if (goodRune(i)) {
                copy = copy + i;
                k++;
            }
        }

        cout << "\t\t" << copy << endl;
        if (copy == word) {
            return true;
        }
    }
    return false;
}

bool goodRune(char rune) {
    string unexpectedSymbols = ",.-=&^%$#@!";
    for (char unexpectedSymbol : unexpectedSymbols) {
        if (rune == unexpectedSymbol) {
            return false;
        }
    }
    return true;
}