/*
 * MarketDataTick.h
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#ifndef MARKETDATATICK_H_
#define MARKETDATATICK_H_

#include "CommonStrctures.h"

struct MarketDataTick {
    string timestamp;
    string symbol;
    string data;
    FilesMetadata fileMetaData;

public:
	MarketDataTick(string timestamp_, string symbol_, string data_, FilesMetadata fileMetaData_);
	virtual ~MarketDataTick();

	friend int compare(const MarketDataTick *a, const MarketDataTick *b);
};

#endif /* MARKETDATATICK_H_ */
