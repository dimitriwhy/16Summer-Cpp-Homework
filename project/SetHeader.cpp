#include <bits/stdc++.h>
#include "sha1.h"
#include "FileTag.hpp"
#include "SetHeader.hpp"
#include "Convert.hpp"
using namespace std;

SetHeader :: SetHeader() :fileSize(0),maxFileNumber(0){
	for (int i = 0;i < 4;i++)
		setMark[i] = constMark[i];
	memset(checksum,0,sizeof(checksum));
	//(FileTag*) = NULL;
}
SetHeader :: SetHeader(char* bytes) {
	bytes2object(bytes);
}
SetHeader :: SetHeader(int maxFileNumberOfNewSet){
	maxFileNumber = maxFileNumberOfNewSet;
	fileSize = 0;
	for (int i = 0;i < 4;i++)
		setMark[i] = constMark[i];
	memset(checksum, 0, sizeof(checksum));
	fileTagsList = new FileTag*[maxFileNumber];
	for (int i = 0;i < maxFileNumber; i++)
		fileTagsList[i] = new FileTag();

}

SetHeader :: ~SetHeader(){
	delete []fileTagsList;//not sure
}

char* SetHeader :: getSetMark(){
	return setMark;
}
void SetHeader :: setSetMark(char* newMark){
	for (int i = 0;i < 4;i++)
		setMark[i] = newMark[i];
}

__int64 SetHeader :: getFileSize(){
	return fileSize;
}
void SetHeader :: setFileSize(__int64 newFileSize){
	fileSize = newFileSize;
}

int SetHeader :: getMaxFileNumber(){
	return maxFileNumber;
}
void SetHeader :: setMaxFileNumber(int newSetMaxNumber){
	maxFileNumber = newSetMaxNumber;
}

char* SetHeader :: getChecksum(){
	return checksum;
}
void SetHeader :: setChecksum(char* newChecksum){
	for (int i = 0;i < 16;i++)
		checksum[i] = newChecksum[i];
}

FileTag** SetHeader :: getFileTagsList(){
	return fileTagsList;
}
void SetHeader :: setFileTagsList(FileTag* *newFileTags){
	fileTagsList = newFileTags;
}

char * SetHeader :: object2bytes(){
	char* result = new char[32 + maxFileNumber * 288];
	memset(result,0,32 + maxFileNumber * 288);
	char* bytes;
	memcpy(result,setMark,4);
	memcpy(result + 4,(bytes = long2bytes(fileSize)),8);
	delete[] bytes;
	memcpy(result + 12,(bytes = int2bytes(maxFileNumber)),4);
	delete[] bytes;
	memcpy(result + 16,checksum,16);
	
	for (int i = 0;i < maxFileNumber;i ++){
		char* fileTags2bytes = fileTagsList[i]->object2bytes();
		memcpy(result + 32 + i * 288, fileTags2bytes, 288);
		delete []fileTags2bytes;
	}
	return result;
}
int SetHeader :: lengthOfObject2bytes(){
	return 32 + maxFileNumber * 288;
}
void SetHeader :: bytes2object(char* bytes){
	memcpy(setMark,bytes,4);
	char * cutBytes;
	fileSize = bytes2long((cutBytes = strsub(bytes, 4, 8)));
	delete [] cutBytes;
	maxFileNumber = bytes2int((cutBytes = strsub(bytes, 12, 4)));
	delete [] cutBytes;
	memcpy(checksum, bytes + 16, 16);
	
	fileTagsList = new FileTag*[maxFileNumber];
	for (int i = 0;i < maxFileNumber; i++){
		fileTagsList[i] = new FileTag((cutBytes = strsub(bytes, 32 + 288 * i, 288)));
		delete [] cutBytes;
	}
}

void SetHeader :: refresh(){
	char* bytes = object2bytes();
	char* cutBytes = strsub(bytes, 32, 288 * maxFileNumber);
		
	SHA1* sha1 = new SHA1();
	sha1->addBytes(cutBytes, 288 * maxFileNumber);
	char* digest = (char*) sha1->getDigest();
	setChecksum(digest);
	
	delete sha1;
	free(digest);
	delete[] cutBytes;
	delete[] bytes;
	
}
