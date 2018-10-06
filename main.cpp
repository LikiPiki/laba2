#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const string filename = "text.txt";

bool checkSentence(string line, string word);
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
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == '.') {
                if (checkSentence(phrase, word)) {
                    cout << phrase << endl;
                }
                phrase = "";
            }
            else {
                phrase += line[i];
            }

        }
    }


    file.close();
    return 0;
}

bool checkSentence(string line, string word) {
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
        for (int i = 0; i < subWord.size(); ++i) {
            if (goodRune(subWord[i])) {
                copy[k] = subWord[i];
                k++;
            }
        }

        if (copy == word) {
            return true;
        }
    }
    return false;
}

bool goodRune(char rune) {
    string unexpectedSymbols = ",.-=&^%$#@!";
    for (int i = 0; i < unexpectedSymbols.size(); ++i) {
        if (rune == unexpectedSymbols[i]) {
            return false;
        }
    }
    return true;
}