#include <iostream>
using namespace std;
#include <string.h>

class String{

    private:
        char *itsString;

    public:
        String();
        String(const char *str){
            itsString = const_cast<char *>(str);
        }

        ~String() = default;

        // перегруженные операторы
        
        friend ostream &operator << ( ostream& theStream, String& theString);
        friend istream &operator >> ( istream& theStream, String& theString);

};

    


ostream &operator << ( ostream& theStream,String& theString){
    theStream << theString.itsString;
    return theStream;
};

istream &operator >> ( istream& theStream,String& theString){
    char *ch = new char;
    theStream >> ch;

    theString.itsString = ch;
    return theStream;
}


int main(){

    String theString("Hellow world");

    cout << theString << endl;

    cin >> theString;
    cout << theString << endl;

    
    

    return 0;

}
