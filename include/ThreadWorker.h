/*
 * ThreadWorker.h
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#ifndef THREADWORKER_H_
#define THREADWORKER_H_

#include "CommonStrctures.h"

class ThreadWorker {
	int thrId;
	vector<FilesMetadata> stockFiles;

public:
	thread thread_obj;
	ThreadWorker(int tid_);
	virtual ~ThreadWorker();
	void insertStockFiles(FilesMetadata stockFile);
	void clearStockFiles();
	void Initialize();
	void insertIntoMarketDataContainer();

};

#endif /* THREADWORKER_H_ */
