#include <iostream>

using namespace std;

string getString(string generatedLetter1, string generatedLetter2) {
    string output;
    int i;
    int index1 = 0;
    int index2 = 0;
    string buffer;
    for(i =0; i < 6; i++) {
        while(index1 < generatedLetter1.size() && generatedLetter1[index1] != '\n') {
            output = output + generatedLetter1[index1];
            index1++;
        }
        output = output + "   ";
        index1++;

        while(index2 < generatedLetter2.size() && generatedLetter2[index2] != '\n') {
            output = output + generatedLetter2[index2];
            index2++;
        }
        output = output + "   ";
        index2++;
    }
    return output;
}


string generateLetter(char symbol) {
    switch(symbol) {

    case 'A':
        return
            "     /\\\n"
            "    /  \\\n"
            "   /    \\\n"
            "  /------\\\n"
            " /        \\\n"
            "/          \\\n";
    case 'B':
        return
            "|^^^\\\n"
            "|    |\n"
            "|___/\n"
            "|   \\\n"
            "|    |\n"
            "|___/\n";
    }
}

int main()
{
    cout << generateLetter('A') << endl;
    cout << generateLetter('B') << endl;

    return 0;
}
