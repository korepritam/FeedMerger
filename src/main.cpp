//============================================================================
// Name        : Merger.cpp
// Author      : Pritam Kore
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "GlobalMembers.h"
#include "gtest/gtest.h"
#include "MarketDataContainer_Test.cpp"
#include "FileManager_Test.cpp"

int main(int argc, char** argv) {

	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

//	int stocksCount = argc-2;
//	char** stockFiles = argv+2;
//
//	InitializeGlobalMembers();
//	GetFileManager()->insertStockFiles(stocksCount,stockFiles);
////	GetFileManager()->readStockFiles();
//	SpawnThreadWorkers();
//	DumpFeed();
//	DestroyGlobalMembers();

	cout << "FeedMerger End Successfully :)" << endl;

	return 0;
}
