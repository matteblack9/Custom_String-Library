#include <iostream>

using namespace std;

class DelimTextBuffer
{
public:
	DelimTextBuffer(char Delim = '|', int maxBytes = 1000);
	int Read(istream& file);
	int Write(ostream& file) const;
	int Pack(const char*, int size = -1);
	int Unpack(const char *);
private:
	char Delim;
	char* buffer;
	int BufferSize;
	int MaxBytes;
	int NextByte;
};
