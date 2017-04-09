#include <iostream>
#include <stdlib.h>

using namespace std;

class String {
public:
	//default constructor
	String();
	//copy constructor
	String(const String&);
	//create from C string
	String(const char*);
	//destructor
	~String();
	//assginment
	String& operator = (const String &);
	//less than
	int operator < (const String &) const;
	//grater than
	int operator > (const String &) const;
	//less than or equal
	int operator <= (const String &) const;
	//grater than or equl
	int operator >= (const String &) const;
	//inequality
	int operator != (const String &) const;
	//equality
	int operator == (const String &) const;
	//return a copy of string
	char* str() const;
	//conversion to char*
	operator char* ();
protected:
	char* string;
	unsigned int MaxLength;
	friend ostream& operator << (ostream& stream, String& str);
};

/*For the reason why Stream name is It has to output in the case that
the previous thing out*/

ostream& operator << (ostream& stream, String& str);

inline ostream& operator << (ostream& stream, String& str) {
	stream << str.string;
	return stream;
}

inline int String::operator > (const String& str) const {
	return !(*this <= str);
}

inline int String::operator >= (const String& str) const {
	return !(*this < str);
}

inline int String::operator != (const String& str) const {
	return !(*this == str);
}

String::String() {
	string = new char[20];
	MaxLength = 0;
}

String::String(const String& str) {
	string = new char[strlen(str.string) + 1];
	strcpy(string, str.string);
	MaxLength = strlen(string);
}

String::String(const char* str) {
	string = new char[strlen(str) + 1];
	strcpy(string, str);
	MaxLength = strlen(string);
}

String::~String() {
	if (string != 0) delete string;
	MaxLength = 0;
	string = 0;
}

String::operator char*() {
	cout << "operator char*()::" << string << endl;
	return string;
}

String& String::operator = (const String& str) {
	if (strlen(str.string) >= MaxLength) {
		delete string;
		string = new char[strlen(str.string) + 1];
		strcpy(string, str.string);
		MaxLength = strlen(string);
	}
	cout << "operator = () is called" << "::string = " << string << endl;
	strcpy(string, str.string);
	return *this;
}

int String::operator < (const String& str) const {
	return strcmp(string, str.string) < 0;
}

int String::operator <= (const String& str) const {
	return strcmp(string, str.string) <= 0;
}

int String::operator == (const String& str) const {
	return strcmp(string, str.string) <= 0;
}

char* String::str() const {
	return string;
}

int main() {
	String s1("Hello");
	String s4("I'm fine");
	String s2;
	char str[10];
	cout << "strcpy(str, s1) is called" << endl;
	strcpy(str, s1);
	strcpy(str, s4);
	cout << "s2 = s1 is called" << endl;
	s2 = s1;
	String s3 = s2;
	cout << "s3 = str is called::" << endl;
	s3 = str;
	s3 = str;
	system("pause");
}