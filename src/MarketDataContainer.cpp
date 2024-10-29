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
	//Multithreading Protection
	lock_guard<mutex> lock(mtx);
	PQ.push(tick_);
}

MarketDataContainer::MarketDataContainer()
{

}


MarketDataContainer::~MarketDataContainer()
{

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
