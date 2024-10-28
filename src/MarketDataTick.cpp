/*
 * MarketDataTick.cpp
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#include "MarketDataTick.h"

MarketDataTick::MarketDataTick(string timestamp_, string symbol_, string data_, FilesMetadata fileMetaData_)
:timestamp(timestamp_),symbol(symbol_),data(data_),fileMetaData(fileMetaData_)
{


}

MarketDataTick::~MarketDataTick()
{

}

// Comparator for the priority queue
int compare(const MarketDataTick *a, const MarketDataTick *b)
{
	const char* timestamp_a = a->timestamp.c_str();
	const char* timestamp_b = b->timestamp.c_str();
	const char* symbol_a = a->symbol.c_str();
	const char* symbol_b = b->symbol.c_str();

    if (strcmp(timestamp_a, timestamp_b) == 0) {
        return strcmp(symbol_a, symbol_b); // Sort by symbol on ties
    }
    return strcmp(timestamp_a, timestamp_b);
}
