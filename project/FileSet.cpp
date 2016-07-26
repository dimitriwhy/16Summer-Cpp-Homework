#include<bits/stdc++.h>
using namespace std;
#include "Convert.hpp"
#include "FileTag.hpp"
#include "SetHeader.hpp"
#include "FileSet.hpp"

FileSet :: FileSet() : header(NULL),headerLength(288),fp(0) {}
FileSet :: FileSet(char* bytes){
	header = new SetHeader(bytes);
}
FileSet :: FileSet(char* filePath, int maxFileNumberOfNewSet){
	fp = fopen(filePath,"wb+");
	header = new SetHeader(maxFileNumberOfNewSet);

	header->refresh();

	char* bytesHeader = header->object2bytes();
	fwrite(bytesHeader, sizeof(char), header->lengthOfObject2bytes(), fp);
}
FileSet :: ~FileSet() {
	delete header;
	fclose(fp);
}

SetHeader* FileSet :: getHeader(){
	return header;
}
void FileSet :: setHeader(SetHeader* newHeader){
	header = newHeader;
}

FILE* FileSet :: getFilePoint(){
	return fp;
}
void FileSet :: setFilePoint(FILE* newFilePoint){
	fclose(fp);
	fp = newFilePoint;
}

int FileSet :: getHeaderLength(){
	return headerLength;
}
void FileSet :: setHeaderLength(int newHeaderLength){
	headerLength = newHeaderLength;
}
