/*
 * ConfigReader.cpp
 *
 *  Created on: 28 Oct 2024
 *      Author: pritam
 */

#include "ConfigReader.h"

ConfigReader* ConfigReader::obj = nullptr;

ConfigReader::ConfigReader(string filename) {
	configFileName = filename;

    std::ifstream configFile(configFileName);
      std::string line;

      // Check if the file is open
      if (!configFile.is_open()) {
          std::cerr << "Could not open the config file: " << configFileName << std::endl;
          abort();
      }

      while (std::getline(configFile, line)) {
          size_t pos = line.find('=');
          if (pos != std::string::npos) {
              std::string key = line.substr(0, pos);
              std::string value = line.substr(pos + 1);

              key.erase(key.find_last_not_of(" \n\r\t") + 1);
              value.erase(0, value.find_first_not_of(" \n\r\t"));

              configMap[key] = value;
          }
      }

      configFile.close();
      displayConfig();
}

string ConfigReader::getValueString(string key) {
    auto it = configMap.find(key);
    if (it != configMap.end()) {
        return it->second;
    } else {
        return "";
    }
}

int ConfigReader::getInt(string key) {
    std::string value = getValueString(key);
    return value.empty() ? 0 : std::stoi(value);
}

float ConfigReader::getFloat(string key) {
    std::string value = getValueString(key);
    return value.empty() ? 0.0f : std::stof(value);
}

void ConfigReader::displayConfig() {
	cout << "[" << configFileName << "] =>" << endl;
    for (const auto& pair : configMap) {
        cout << pair.first << " = " << pair.second << endl;
    }
    cout << endl;
}

ConfigReader::~ConfigReader() {

}
