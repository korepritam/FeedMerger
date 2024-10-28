/*
 * GlobalMembers.cpp
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#include "ConfigReader.h"
#include "GlobalMembers.h"
#include "MarketDataContainer.h"

FileManager *fm = nullptr;
ThreadWorker **threadWorkers = nullptr;
int threadCount = 0;

void InitializeGlobalMembers()
{
	ConfigReader::getInstance("FeedMerger.cfg");
	fm = new FileManager();
	threadCount = ConfigReader::getInstance()->getInt("THREAD_WORKERS");

	if(threadCount <= 0) {
		cout << "Thread Count cannot be <= 0" << endl;
		abort();
	}

	threadWorkers = new ThreadWorker*[threadCount];
}

FileManager* GetFileManager()	{return fm;}

void SpawnThreadWorkers()
{
	for(int thead_idx = 0; thead_idx < threadCount; thead_idx++)
	{
		ThreadWorker *t = new ThreadWorker(thead_idx);
		threadWorkers[thead_idx] = t;
	}

	int file_batch_size = ConfigReader::getInstance()->getInt("BATCH_FILE_SIZE");
	for(int i=0; i<fm->GetStockFileListSize(); i+=file_batch_size)
	{
		for(int j=0; j<file_batch_size && (i+j) < fm->GetStockFileListSize(); j++)
		{
			threadWorkers[(i+j) % threadCount]->insertStockFiles(fm->getFileName(i+j));
		}

		//Run threadCount threads
		for(int thread_idx = 0; thread_idx < threadCount; thread_idx++)
		{
			threadWorkers[thread_idx]->Initialize();
		}

		//wait for the 16 threads to complete
		for(int thread_idx = 0; thread_idx < threadCount; thread_idx++)
		{
			if(threadWorkers[thread_idx]->thread_obj.joinable()) {
				threadWorkers[thread_idx]->thread_obj.join();
			}
		}

		for(int thread_idx = 0; thread_idx < threadCount; thread_idx++)
		{
			threadWorkers[thread_idx]->clearStockFiles();
		}

	}

//	MarketDataContainer::getInstance()->displayContainer();
}

void DumpFeed()
{
	MarketDataContainer::getInstance()->popFromContainer();
}

void DestroyGlobalMembers()
{
	delete fm; fm = nullptr;

	for(int thread_idx = 0; thread_idx < threadCount; thread_idx++)
	{
		delete threadWorkers[thread_idx];
		threadWorkers[thread_idx] = nullptr;
	}
	threadWorkers = nullptr;
	cout << "Global Member Destroyed Successfully" << endl;
}
