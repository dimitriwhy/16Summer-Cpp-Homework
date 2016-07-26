#include <bits/stdc++.h>
using namespace std;
#include "Management.hpp"
#include "Convert.hpp"
#include "sha1.h"
#include "FileSet.hpp"
Management :: Management(): fileSet(NULL) {}
Management :: ~Management(){
	delete fileSet;
}

bool Management :: createFileSet(char* filePath, int maxFileNumberOfNewSet){
	fileSet = new FileSet(filePath, maxFileNumberOfNewSet);

	return 1;
}

bool Management :: openFileSet(char* filePath){
	FILE* fp = fopen(filePath, "rb+");
	char headData[32],mark[4];
	fread(headData, sizeof(char), 32, fp);
	memcpy(mark, headData, 4);
	if (strcmp(mark,constMark) != 0){
		fclose(fp);return 0; //check setMark
	}
	char * cutBytes;
	int fileSize = bytes2long((cutBytes = strsub(headData, 4, 8)));
	delete[] cutBytes;
	int maxFileNumber = bytes2int((cutBytes = strsub(headData, 12, 4)));
	delete[] cutBytes;
	char checksum[16];
	memcpy(checksum, headData + 16, 16);
	
	//check sha1
	char* bytes = new char[maxFileNumber * 288];
	fread(bytes, sizeof(char), maxFileNumber * 288, fp);
	SHA1 * sha1 = new SHA1();
	sha1->addBytes(bytes, maxFileNumber * 288);
	char * digest = (char*)sha1->getDigest();
	int o = 0;
	for (int i = 0;i < 16;i++)
		if (digest[i] != checksum[i]) {o = 1;break;}
	delete sha1;
	free(digest);
	delete[] bytes;
	if (o) return 0;
	
	//create SetHeader and File...
	fseek(fp, 0, SEEK_SET);
	bytes = new char[32 + maxFileNumber * 288];
	fread(bytes, sizeof(char), maxFileNumber * 288 + 32, fp);
	fileSet = new FileSet();
	fileSet->setFilePoint(fp);
	SetHeader* newHeader = new SetHeader(bytes);
	fileSet->setHeader(newHeader);
	delete[] bytes;
	return 1;
}

bool Management :: addFileToFileSet(char* filePath){
	//get the context of the file
	FILE* fp = fopen(filePath, "rb+");
	fseek(fp, 0, SEEK_END);
	int length = ftell(fp);
	fseek(fp, 0, SEEK_SET);
	char bytes[length];
	fread(bytes, sizeof(char), length, fp);
	fclose(fp);

	//Find position in fileTagsList
	SetHeader* header = fileSet->getHeader();
	int num = -1;
	FileTag** fileTagsList = header->getFileTagsList();
	for (int i = 0; i < header->getMaxFileNumber(); i++){
		FileTag* fileTag = fileTagsList[i];
		if (fileTag->getFileFlag() == 0){
			num = i;break;
		}else if (fileTag->getFileFlag() == 2 && length <= fileTag->getFileSize()){
			num = i;break;
		}
	}
	if (num == -1) return 0;

	//rewrite the document file	
	fp = fileSet->getFilePoint();
	FileTag* fileTag = fileTagsList[num];
	fileTag->setFileName(filePath);
	fileTag->setFileSize(length);
	SHA1* sha1 = new SHA1();
	sha1->addBytes(bytes, length);
	char* digest = (char *)sha1->getDigest();
	fileTag->setChecksum(digest);
	delete sha1;
	free(digest);
	
	if (fileTag->getFileFlag() == 0){
		if (num == 0){
			fileTag->setFileOffset(header->lengthOfObject2bytes());
		}else fileTag->setFileOffset(header->getFileSize());
	}
	
	fseek(fp, fileTag->getFileOffset(), SEEK_SET);
	fwrite(bytes, sizeof(char), length, fp);
	if (fileTag->getFileFlag() == 0){
		fseek(fp, 0, SEEK_END);
		int length = ftell(fp);
		header->setFileSize(length);
	}
	fileTag->setFileFlag(1);

	//refresh header!!!
	header->refresh();
	return 1;
}

bool Management :: deleteFileFromFileSet(char* fileName){
	SetHeader* header = fileSet->getHeader();
	FileTag** fileTagsList = header->getFileTagsList();
	int pos = -1;
	for (int i = 0;i < header->getMaxFileNumber(); i++){
		FileTag* fileTag = fileTagsList[i];
		if (strcmp(fileName,fileTag->getFileName()) == 0){
			fileTag->setFileFlag(2);
			pos = i;
			break;
		}
	}

	if (pos == -1) return 0;
	header->refresh();
	return 1;
}

bool Management :: fetchFileFromFileSet(char* fileName, char* newPathAndName){
	FileTag** fileTagsList = fileSet->getHeader()->getFileTagsList();
	int maxFileNumber = fileSet->getHeader()->getMaxFileNumber();
	int pos = -1, sha1Check = 1;
	for (int i = 0; i <  maxFileNumber; i++){
		FileTag * fileTag = fileTagsList[i];
		if (strcmp(fileTag->getFileName(), fileName) == 0){
			pos = i;
			FILE * fp = fileSet->getFilePoint();
			char bytes[fileTag->getFileSize()];
			memset(bytes,0,sizeof(bytes));
			fseek(fp, fileTag->getFileOffset(), SEEK_SET);
			fread(bytes, sizeof(char), fileTag->getFileSize(), fp);
			
			//check sha1
			SHA1* sha1 = new SHA1();
			sha1->addBytes(bytes, fileTag->getFileSize());
			char* digest = (char*) sha1->getDigest();
			for (int j = 0;j < 16;j++)
				if (digest[i] != fileTag->getChecksum()[i]){
					sha1Check = 0;
					break;
				}
			free(digest);
			delete sha1;
			if (sha1Check == 0) break;

			//write new file
			fp = fopen(newPathAndName, "wb");
			fwrite(bytes, sizeof(char), fileTag->getFileSize(), fp);
			fclose(fp);
			break;
		}
	}
	if (pos == -1) return 0;
	else if (sha1Check == 0) return 0;
	return 1;
}

bool Management :: printFileListInFileSet(){
	FileTag** fileTagsList = fileSet->getHeader()->getFileTagsList();
	int maxFileNumber = fileSet->getHeader()->getMaxFileNumber();
	
	for (int i = 0;i < maxFileNumber; i++)
		if (fileTagsList[i]->getFileFlag() == 1){
			cout << "File Name: " << fileTagsList[i]->getFileName() << endl;
			cout << "File Size: " << fileTagsList[i]->getFileSize() << endl;
			cout << "File Offset: " << fileTagsList[i]->getFileOffset() << endl;
			cout << endl;
		}
	
	return 1;
}

bool Management :: closeFileSet(){
	char* bytes = fileSet->getHeader()->object2bytes();
	FILE* fp = fileSet->getFilePoint();
	fseek(fp, 0, SEEK_SET);
	fwrite(bytes, sizeof(char), fileSet->getHeader()->lengthOfObject2bytes(), fp);
	fclose(fp);
	return 1;
}
