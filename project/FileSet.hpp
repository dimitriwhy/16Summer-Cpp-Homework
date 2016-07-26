#ifndef FILESET
#define FILESET
#include "SetHeader.hpp"
class FileSet{
public:
	FileSet();
	FileSet(char* bytes);
	FileSet(char* filePath, int maxFileNumberOfNewSet);
	~FileSet();
	
	SetHeader * getHeader();
	void setHeader(SetHeader * newHeader);

	FILE* getFilePoint();
	void setFilePoint(FILE* newFilePoint);

	int getHeaderLength();
	void setHeaderLength(int newHeaderLength);

private:
	SetHeader * header;
	int headerLength;
	FILE* fp;
};
#endif

