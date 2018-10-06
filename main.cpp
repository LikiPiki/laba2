#include <iostream>
#include <fstream>

using namespace std;

const string filename = "text.txt";

void checkSentence(string line, string word);

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
                checkSentence(phrase, word);
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

void checkSentence(string line, string word) {
    // do something here
}