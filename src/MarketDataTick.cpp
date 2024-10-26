/*
 * MarketDataTick.cpp
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#include "MarketDataTick.h"

MarketDataTick::MarketDataTick(string timestamp_, string symbol_, string data_, int sourceFileIndex_)
:timestamp(timestamp_),symbol(symbol_),data(data_),sourceFileIndex(sourceFileIndex_),fileOffset(0)
{


}

MarketDataTick::~MarketDataTick() {

}

