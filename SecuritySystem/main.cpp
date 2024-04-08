#include <iostream>


using namespace std;

string generateLetter(char symbol) {
    switch(symbol) {

    case 'A':
    return
           "/\\"
          "/  \\"
         "/    \\"
        "/------\\"
       "/        \\"
      "/          \\";
    }
}

int main()
{
    cout << generateLetter('A') << endl;

    return 0;
}
