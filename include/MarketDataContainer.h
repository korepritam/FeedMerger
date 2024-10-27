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
		const char* timestamp_a = a->timestamp.c_str();
		const char* timestamp_b = b->timestamp.c_str();
		const char* symbol_a = a->symbol.c_str();
		const char* symbol_b = b->symbol.c_str();

	    if (strcmp(timestamp_a, timestamp_b) == 0) {
	        return strcmp(symbol_a, symbol_b); // Sort by symbol on ties
	    }
	    return strcmp(timestamp_a, timestamp_b);
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
};

#endif /* MARKETDATACONTAINER_H_ */
