//============================================================================
// Name        : Merger.cpp
// Author      : Pritam Kore
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GlobalMembers.h"

int main(int argc, char** argv) {

	int stocksCount = argc-2;
	char** stockFiles = argv+2;

	InitializeGlobalMembers();
	GetFileManager()->insertStockFiles(stocksCount,stockFiles);
//	GetFileManager()->readStockFiles();
	SpawnThreadWorkers(2);


	DestroyGlobalMembers();
	return 0;
}
