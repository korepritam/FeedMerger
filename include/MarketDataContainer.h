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
			int year1,month1,day1,hr1,min1,sec1,milli1;
			int year2,month2,day2,hr2,min2,sec2,milli2;
//			2021-03-05 10:00:00.134
			sscanf(a->timestamp.c_str(),"%d-%d-%d %d:%d:%d.%d", &year1, &month1, &day1, &hr1, &min1, &sec1, &milli1);
			sscanf(b->timestamp.c_str(),"%d-%d-%d %d:%d:%d.%d", &year2, &month2, &day2, &hr2, &min2, &sec2, &milli2);

			return  year1 > year2 ? true :
					month1 > month2 ? true :
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
		if(obj == nullptr) {
			obj = new MarketDataContainer();
		}
		return obj;
	}

	void pushToContainer(MarketDataTick *tick_);
	void displayContainer();
	void popFromContainer();
};

#endif /* MARKETDATACONTAINER_H_ */
