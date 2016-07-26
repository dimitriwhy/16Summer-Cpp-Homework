#ifndef HITMANAGEMENT
#define HITMANAGEMENT
#include "FileSet.hpp"
class Management{
public:
	Management();
	~Management();
	
	bool createFileSet(char* filePath, int maxFileNumberOfNewSet);
	bool openFileSet(char* filePath);
	bool addFileToFileSet(char* filePath);
	bool deleteFileFromFileSet(char* fileName);
	bool fetchFileFromFileSet(char* fileName, char* newPathAndName);
	bool printFileListInFileSet();
	bool closeFileSet();

private:
	FileSet* fileSet;
};
#endif
