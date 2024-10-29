/*
 * ThreadWorker.cpp
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#include "ThreadWorker.h"
#include "FileManager.h"

extern FileManager *fm;

ThreadWorker::ThreadWorker(int tid_):thrId(tid_)
{
	cout << "ThreadWorker Created [" << thrId << "]" << endl;
}

ThreadWorker::~ThreadWorker()
{
	if(thread_obj.joinable())
	{
		thread_obj.join();
	}
	cout << "ThreadWorker Destroyed [" << thrId << "]" << endl;
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
	for(auto file:stockFiles)
	{
		fm->readFile(file);
	}
}
