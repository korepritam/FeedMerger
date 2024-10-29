/*
 * MarketDataTick.cpp
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#include "MarketDataTick.h"

MarketDataTick::MarketDataTick(string timestamp_, string exchange_, string data_, FilesMetadata fileMetaData_)
:timestamp(timestamp_),exchange(exchange_),data(data_),fileMetaData(fileMetaData_)
{

}

MarketDataTick::~MarketDataTick()
{

}
