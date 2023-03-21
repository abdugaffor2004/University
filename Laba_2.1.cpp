#include <iostream>
using namespace std;
#include <cstring>
#include <string>


class String
{
	char *_pChar;
	int _length;

public:
	String(const char *str);
	String(const char &chr);
	~String();


	char* set_pChar(char* value){_pChar = value;};
	char* get_pChar(){return _pChar;};

	char *pChar() { return _pChar; };
	int len() { return _length; };

	void clear();
};





String::String(const char *str)
{
	_pChar = const_cast<char *>(str);
	_length = strlen(str);
}


String::String(const char &chr)
{
	*_pChar = chr;
	_length = 1;
}

String::~String()
{
	_pChar = nullptr;
}

void String::clear()
{
	_pChar = nullptr;
	_length = 0;
}





int main(int argc, char **argv)
{
	String str("Hello");

	cout << str.get_pChar() <<endl;

	str.set_pChar("Hi");

    cout << str.get_pChar() << endl;

	
	return 0;
}
