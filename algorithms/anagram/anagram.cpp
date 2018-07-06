#include <iostream>
#include <fstream>

using namespace std;

#define ALPHABETS_LENGTH 26

int anagram[ALPHABETS_LENGTH];

int main () {
    ifstream fin("./anagram_input");
    if (!fin) {
        cout << "Input file not found.";
        return 1;
    }

    char ch;

    for (int i = 0 ; i < ALPHABETS_LENGTH ; i++)
        anagram[i] = 0;

    do {
        fin.get(ch);
        if (fin.eof())
            break;

        if (ch >= 'a' && ch <= 'z') {
            anagram[static_cast<int>(ch) - static_cast<int>('a')]++;
        }		
    } while (true);

    for (int i = 0 ; i < ALPHABETS_LENGTH ; i++) {
        if (anagram[i] == 0)
            continue;
        cout << "Occurance of " << static_cast<char>(i + 'a') 
             << " is " << anagram[i] << (anagram[i] > 1 ? " times." : " time.") << endl;
    }

    if (fin)
        fin.close();

    return 0;
}
