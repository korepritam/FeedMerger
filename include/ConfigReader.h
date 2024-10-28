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

	std::string getValueString(const std::string& key) const;
	int getInt(const std::string& key) const;
	float getFloat(const std::string& key) const;
	void displayConfig() const;
	virtual ~ConfigReader();
};

#endif /* CONFIGREADER_H_ */
