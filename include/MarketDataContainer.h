/*
 * MarketDataContainer.h
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#ifndef MERAKETDATACONTAINER_H_
#define MERAKETDATACONTAINER_H_

#include "CommonStrctures.h"
#include "MarketDataTick.h"

class CompareTick {
public:
	bool operator()(MarketDataTick *a, MarketDataTick *b) {
		if(a->timestamp == b->timestamp)
		{
			return a->symbol>b->symbol;
		}
		else
		{
			return a->timestamp > b->timestamp;
		}
	}
};

class MarketDataContainer {
	priority_queue<MarketDataTick*, vector<MarketDataTick*>, CompareTick> PQ;
	static mutex mtx;
	static MarketDataContainer *obj;

	MarketDataContainer();
	virtual ~MarketDataContainer();

public:
	MarketDataContainer(const MarketDataContainer& obj) = delete;
	void operator=(const MarketDataContainer& obj) = delete;

	static MarketDataContainer* getInstance() {
//		mtx.lock();
		if(obj == nullptr) {
			obj = new MarketDataContainer();
		}
//		mtx.unlock();
		return obj;
	}

	void pushToContainer(MarketDataTick *tick_);
	void displayContainer();
	void popFromContainer();
};

#endif /* MARKETDATACONTAINER_H_ */
