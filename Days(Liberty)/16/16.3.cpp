#include <iostream>
using namespace std;

int main(){

    char ch;
    cout << "enter a phrase: ";
    while ( cin.get(ch) ){

        // if (ch == '!'){
        //     cin.putback('$' );
        // }
        // else{cout << ch;}
        
        
        // while (cin.peek() == '#'){
        //     cin.ignore(1,'#');
        // }

        switch(ch){
            case '!':{
                cout << '$';
                break;
            }

            case '#':{
                break;
            }

            default:{
                cout <<ch;
                break;
            }
        }
    }

    return 0;

}