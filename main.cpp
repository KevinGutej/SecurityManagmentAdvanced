#include <iostream>
#include <time.h>
#include <stdlib.h>

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
        output = output + '\n';
        index2++;
    }
    return output;
}

string generateLetter(char symbol) {
    switch(symbol) {

    case 'A':
        return
            "     /\\     \n"
            "    /  \\    \n"
            "   /    \\   \n"
            "  /------\\  \n"
            " /        \\ \n"
            "/          \\\n";
    case 'B':
        return
            "|^^^\\ \n"
            "|    |\n"
            "|___/ \n"
            "|   \\ \n"
            "|    |\n"
            "|___/ \n";
    case 'C':
        return
            "  _____  \n"
            " /       \n"
            "/        \n"
            "|        \n"
            "\\        \n"
            " \\_____  \n";
    case 'D':
        return
            " _____   \n"
            "|     \\  \n"
            "|      \\ \n"
            "|      / \n"
            "|      / \n"
            "|_____/  \n";
    case 'E':
        return
            " ______ \n"
            "|       \n"
            "|       \n"
            "|------ \n"
            "|       \n"
            "|______ \n";


    }
}

string generateUnblurredCode(string code) {
    int i;
    string alreadyConnected = generateLetter(code[0]);
    string newLetter;
    for(i=1; i < code.size(); i++) {
        newLetter = generateLetter(code[i]);
        alreadyConnected = getString(alreadyConnected, newLetter);
    }
    return alreadyConnected;
}

string randomizeCode(int minLength = 4, int maxLength = 8) {
    string code;
    int length = rand() % (maxLength - minLength + 1) + minLength;
    for(int i = 0; i < length; i++) {
        char letter = rand() % (69 - 65 + 1) + 65;
        code = code + letter;
    }
    return code;
}


int main()
{
    srand(time(NULL));
    string code = randomizeCode();
    string output = generateUnblurredCode(code);
    cout << output << endl;
    return 0;
}
