#include <iostream>
#include "DelimTextBuffer.hpp"

int DelimTextBuffer::Pack(const char* str, int size) {
	short len;
	if (size >= 0) len = size;
	else len = strlen(str);
	if (len > strlen(str))
		return false;
	int start = NextByte;
	NextByte += len + 1;
	if (NextByte > MaxBytes) return false;
	memcpy(&buffer[start], str, len);
	buffer[start + len] = Delim;
	BufferSize = NextByte;
	return true;
}

int DelimTextBuffer::Unpack(const char* str) {
	int len = -1;
	int start = NextByte;
	for(int i = start; i < BufferSize; i++)
		if (buffer[i] == Delim) {
			len = i - start;
			break;
		}
	if (len == -1) return false;
	NextByte += len + 1;
}