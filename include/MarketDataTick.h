/*
 * MarketDataTick.h
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#ifndef MARKETDATATICK_H_
#define MARKETDATATICK_H_

#include "StandardIncludes.h"

struct MarketDataTick {
    string timestamp;
    string symbol;
    string data;
    int sourceFileIndex = 0; // Track which file this entry came from
    long fileOffset = 0;

public:
	MarketDataTick(string timestamp_, string symbol_, string data_, int sourceFileIndex_, long offset_);
	virtual ~MarketDataTick();

	friend int compare(const MarketDataTick *a, const MarketDataTick *b);
};

#endif /* MARKETDATATICK_H_ */
