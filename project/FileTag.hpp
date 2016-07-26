#ifndef FILETAG
#define FILETAG
class FileTag{
public:
	FileTag();
	FileTag(char * bytes);
	~FileTag();

	char* getFileName();
	void setFileName(char* newFileName);

	int getFileFlag();
	void setFileFlag(int newFileFlag);
	
	int getFileSize();
	void setFileSize(int newFileSize);

	__int64 getFileOffset();
	void setFileOffset(__int64 newFileOffset);

	char* getChecksum();
	void setChecksum(char* newChecksum);

	char* object2bytes();

private:
	char fileName[256];
	int fileFlag;
	int fileSize;
	int maxFileSize;
	__int64 fileOffset;
	char checksum[16];
};
#endif
