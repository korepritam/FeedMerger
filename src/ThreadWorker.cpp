/*
 * ThreadWorker.cpp
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#include "ThreadWorker.h"
#include "FileManager.h"

extern FileManager *fm;

ThreadWorker::ThreadWorker(int tid_):tid(tid_)
{

}

ThreadWorker::~ThreadWorker()
{
	if(thread_obj.joinable())
	{
		thread_obj.join();
	}
}

void ThreadWorker::insertStockFiles(FilesMetadata stockFileMetadata)
{
	stockFiles.push_back(stockFileMetadata);
}

void ThreadWorker::clearStockFiles()
{
	stockFiles.clear();
}

void ThreadWorker::Initialize()
{
	thread_obj = thread(&ThreadWorker::insertIntoMarketDataContainer, this);
}
void ThreadWorker::insertIntoMarketDataContainer()
{
	//read one line from file and insert
//	cout << "***** Started *****" << endl;
	for(auto file:stockFiles)
		fm->readFile(file);
//	cout << "***** Finished *****" << endl;
}
