#include <bits/stdc++.h>
using namespace std;
#include "Convert.hpp"
const char constMark[] = "_HIT";
char* strsub(char* bytes,int pos,int length){
	char* result = new char[length];
	memcpy(result, bytes + pos, length);
	return result;
}
__int64 bytes2long(char *bytes){
	__int64 result = 0;
	memcpy(&result, bytes, 8);
	return result;
}
char* long2bytes(__int64 num){
	char* result = new char[8];
	memcpy(result, &num, 8);
	return result;
}

int bytes2int(char *bytes){
	int result = 0;
	memcpy(&result, bytes, 4);
	return result;
}
char* int2bytes(int num){
	char* result = new char[4];
	memcpy(result, &num, 4);
	return result;
}
