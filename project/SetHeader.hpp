#ifndef SETHEADER
#define SETHEADER
#include "FileTag.hpp"
class SetHeader{
public:
	SetHeader();
	SetHeader(char* bytes);
	SetHeader(int maxFileNumberOfNewSet);
	~SetHeader();

	char* getSetMark();
	void setSetMark(char* newMark);
	
	__int64 getFileSize();
	void setFileSize(__int64 newFileSize);
	
	int getMaxFileNumber();
	void setMaxFileNumber(int newSetMaxNumber);

	char* getChecksum();
	void setChecksum(char* newChecksum);
	
	FileTag** getFileTagsList();
	void setFileTagsList(FileTag** newFileTags);
	
	char* object2bytes();
	int lengthOfObject2bytes();
	void bytes2object(char* bytes);

	void refresh();
private:
	char setMark[4];
	__int64 fileSize;
	int maxFileNumber;
	char checksum[16];
	FileTag* (*fileTagsList);
};

#endif
