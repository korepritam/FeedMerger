/*
 * MeraketDataContainer.cpp
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#include "MarketDataContainer.h"
#include "FileManager.h"

extern FileManager *fm;

MarketDataContainer* MarketDataContainer::obj = nullptr;
mutex MarketDataContainer::mtx;

void MarketDataContainer::pushToContainer(MarketDataTick *tick_)
{
	mtx.lock();
	PQ.push(tick_);
	mtx.unlock();
}

MarketDataContainer::MarketDataContainer()
{

}


MarketDataContainer::~MarketDataContainer()
{

}

void MarketDataContainer::displayContainer()
{
	while(PQ.size())
	{
		MarketDataTick *tick= PQ.top();
		PQ.pop();
		cout << "timestamp:" << tick->timestamp << " symbol:" << tick->symbol << " sourceFileIndex:" << tick->fileMetaData.filename << " Offset:" << tick->fileMetaData.fileOffset << " Data:" << tick->data;
		delete tick;
	}
}

void MarketDataContainer::popFromContainer()
{
	while(PQ.size())
	{
		MarketDataTick *tick= PQ.top();
		PQ.pop();
		fm->writeToFile(tick);
		delete tick;
	}
}
