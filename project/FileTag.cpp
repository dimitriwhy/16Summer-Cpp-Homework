#include <bits/stdc++.h>
using namespace std;
#include "FileTag.hpp"
#include "Convert.hpp"
FileTag :: FileTag() : fileFlag(0),fileSize(0),fileOffset(0){
	memset(fileName, 0, sizeof(fileName));
	memset(checksum, 0, sizeof(checksum));
}
FileTag :: FileTag(char* bytes){
	memcpy(fileName, bytes, 256);
	char * cutBytes;
	fileFlag = bytes2int((cutBytes = strsub(bytes, 256, 4)));
	delete[] cutBytes;
	fileSize = bytes2int((cutBytes = strsub(bytes, 260, 4)));
	delete[] cutBytes;
	fileOffset = bytes2int((cutBytes = strsub(bytes, 264, 8)));
	delete[] cutBytes;
	memcpy(checksum, bytes + 272, 16);
}
FileTag :: ~FileTag(){}

char* FileTag :: getFileName(){
	return fileName;
}
void FileTag :: setFileName(char* newFileName){
	memset(fileName,0,sizeof(fileName));
	int length = strlen(newFileName);
	for (int i = 0;i < length;i++)
		fileName[i] = newFileName[i];
}
int FileTag :: getFileFlag(){
	return fileFlag;
}
void FileTag :: setFileFlag(int newFileFlag){
	fileFlag = newFileFlag;
}

int FileTag :: getFileSize(){
	return fileSize;
}
void FileTag :: setFileSize(int newFileSize){
	fileSize = newFileSize;
}

__int64 FileTag :: getFileOffset(){
	return fileOffset;
}
void FileTag :: setFileOffset(__int64 newFileOffset){
	fileOffset = newFileOffset;
}

char* FileTag :: getChecksum(){
	return checksum;
}
void FileTag :: setChecksum(char* newChecksum){
	for (int i = 0;i < 16;i++)
		checksum[i] = newChecksum[i];
}

char* FileTag :: object2bytes(){
	char* result = new char[288];
	memset(result, 0, 288);
	
	memcpy(result, fileName, 256);
	char* bytes;
	memcpy(result + 256, (bytes = int2bytes(fileFlag)), 4);
	delete[] bytes;
	memcpy(result + 260, (bytes = int2bytes(fileSize)), 4);
	delete[] bytes;
	memcpy(result + 264, (bytes = long2bytes(fileOffset)), 8);
	delete[] bytes;
	memcpy(result + 272, checksum, 16);
	
	return result;
}
