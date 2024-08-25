#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

string joinLetters(string generatedLetter1, string generatedLetter2) {
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

string generateSymbol(char letter) {
    switch(letter) {

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
            "|^^^^\\   \n"
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

    case 'F':
        return
            " ______ \n"
            "|       \n"
            "|       \n"
            "|------ \n"
            "|       \n"
            "|       \n";

    case 'G':
        return
            " ______   \n"
            "|         \n"
            "|         \n"
            "|   ----| \n"
            "|       | \n"
            "|_______| \n";


    case 'H':
        return
            "|       | \n"
            "|       | \n"
            "|       | \n"
            "|-------| \n"
            "|       | \n"
            "|       | \n";


    case 'I':
        return
            "  ____  \n"
            "   ||   \n"
            "   ||   \n"
            "   ||   \n"
            "   ||   \n"
            "  ----  \n";
    case 'J':
        return
            "       | \n"
            "       | \n"
            "       | \n"
            "       | \n"
            "       / \n"
            " _____/  \n";
    case 'K':
        return
            "|      /\n"
            "|    /  \n"
            "|  /    \n"
            "|  \\    \n"
            "|    \\  \n"
            "|      \\ \n";
    case 'L':
        return
            "|       \n"
            "|       \n"
            "|       \n"
            "|       \n"
            "|       \n"
            "|______ \n";

    default:
        return "Error";

    }
}

string introduceNoise(string generatedSymbol) {
    int index;
    for(int i = 0; i < 4; i++) {
        do {
            index = rand() % (generatedSymbol.size());
        }while(generatedSymbol[index] == '\n');
        generatedSymbol[index] = 'X';
    }
    return generatedSymbol;
}

string generateBlurredCode(string code) {
    string alreadyConnected = introduceNoise(generateSymbol(code[0]));
    string newLetter;
    int i;
    for(i=1; i < code.size(); i++) {
        newLetter = introduceNoise(generateSymbol(code[i]));
        alreadyConnected = joinLetters(alreadyConnected, newLetter);
    }
    return alreadyConnected;
}

string randomizeCode(int minLength = 4, int maxLength = 8) {
    string code;
    const char lastLetterAvailable = 'L';
    int length = rand() % (maxLength - minLength + 1) + minLength;
    for(int i = 0; i < length; i++) {
        char letter = rand() % (lastLetterAvailable - 'A' + 1) + 'A';
        code = code + letter;
    }
    return code;
}

bool confirmHumainity(string correctCode) {
    string userCode;
    const int changingLowerCaseToUpperCase = 32;
    cout << "Please enter the code above: ";
    cin >> userCode;
    int i;
    for(i =0; i < userCode.length(); i++) {
        if(userCode[i] <= 'z' && userCode[i] >= 'a') {
            userCode[i] = userCode[i] - changingLowerCaseToUpperCase;
        }
    }
    return userCode == correctCode;
}

int main()
{
    srand(time(NULL));
    string code = randomizeCode();
    string output = generateBlurredCode(code);
    cout << output << endl;
    if(confirmHumainity(code)) {
        cout << "Access granted" << endl;
    }else {
        cout << "Access denied" << endl;
    }
    return 0;
}
