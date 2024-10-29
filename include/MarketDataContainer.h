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
			return a->exchange > b->exchange;
		}
		else
		{
			int year1,mon1,day1,hr1,min1,sec1,milli1;
			int year2,mon2,day2,hr2,min2,sec2,milli2;

			sscanf(a->timestamp.c_str(),"%4d-%2d-%2d %2d:%2d:%2d.%3d", &year1, &mon1, &day1, &hr1, &min1, &sec1, &milli1);
			sscanf(b->timestamp.c_str(),"%4d-%2d-%2d %2d:%2d:%2d.%3d", &year2, &mon2, &day2, &hr2, &min2, &sec2, &milli2);

			return  year1 > year2 ? true :
					mon1 > mon2 ? true :
					day1 > day2 ? true :
					hr1 > hr2 ? true :
					min1 > min2 ? true :
					sec1 > sec2 ? true :
					milli1 > milli2 ? true : false;

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

	static MarketDataContainer* getInstance()
	{
		//Multithreading Protection
		lock_guard<mutex> lock(mtx);
		if(obj == nullptr) {
			obj = new MarketDataContainer();
		}
		return obj;
	}

	void pushToContainer(MarketDataTick *tick_);
	void popFromContainer();
};

#endif /* MARKETDATACONTAINER_H_ */
