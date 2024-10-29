#ifndef COMMONSTRUCTURES_H_
#define COMMONSTRUCTURES_H_

#include "StandardIncludes.h"

#define MAX_LINE_LEN 1024
#define EXCHANGE_LEN 15
#define TIMESTAMP_LEN 30
//#define TIMESTAMP_LEN 13

struct FilesMetadata {
	string filename;
	int fileNo;
	long fileOffset = 0;

	FilesMetadata(string filename_, int fileNo_):filename(filename_),fileNo(fileNo_) {}
};

#endif /* COMMONSTRUCTURES_H_ */
