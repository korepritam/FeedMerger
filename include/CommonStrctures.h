#ifndef COMMONSTRUCTURES_H_
#define COMMONSTRUCTURES_H_

#include "StandardIncludes.h"

struct FilesMetadata {
	string filename;
	int fileNo;
	long fileOffset = 0;

	FilesMetadata(string filename_, int fileNo_):filename(filename_),fileNo(fileNo_) {}
};

#endif /* COMMONSTRUCTURES_H_ */
