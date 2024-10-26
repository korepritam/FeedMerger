/*
 * MarketDataTick.h
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#ifndef MARKETDATATICK_H_
#define MARKETDATATICK_H_

#include "StandardIncludes.h"

class MarketDataTick {
    string timestamp;
    string symbol;
    string data;
    int sourceFileIndex = 0; // Track which file this entry came from
    long fileOffset = 0;

public:
	MarketDataTick(string timestamp_, string symbol_, string data_, int sourceFileIndex_);
	virtual ~MarketDataTick();

	friend int compare(const MarketDataTick *a, const MarketDataTick *b);
};

// Comparator for the priority queue
int compare(const MarketDataTick *a, const MarketDataTick *b) {

	const char* timestamp_a = a->timestamp.c_str();
	const char* timestamp_b = b->timestamp.c_str();
	const char* symbol_a = a->symbol.c_str();
	const char* symbol_b = b->symbol.c_str();

    if (strcmp(timestamp_a, timestamp_b) == 0) {
        return strcmp(symbol_a, symbol_b); // Sort by symbol on ties
    }
    return strcmp(timestamp_a, timestamp_b);
}

#endif /* MARKETDATATICK_H_ */
