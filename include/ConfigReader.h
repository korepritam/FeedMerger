/*
 * ConfigReader.h
 *
 *  Created on: 28 Oct 2024
 *      Author: pritam
 */

#ifndef CONFIGREADER_H_
#define CONFIGREADER_H_

#include "StandardIncludes.h"

class ConfigReader {
	string configFileName;
	unordered_map<string,string> configMap;

	static ConfigReader* obj;
	ConfigReader(string filename);
public:
	static ConfigReader* getInstance(string filename="") {
		if(obj==nullptr) {
			obj = new ConfigReader(filename);
		}
		return obj;
	}

	string getValueString(string key);
	int getInt(string key);
	float getFloat(string key);
	void displayConfig();
	virtual ~ConfigReader();
};

#endif /* CONFIGREADER_H_ */
