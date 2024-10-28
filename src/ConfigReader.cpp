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

      // Read the config file line by line
      while (std::getline(configFile, line)) {
          // Find the position of '='
          size_t pos = line.find('=');
          if (pos != std::string::npos) {
              std::string key = line.substr(0, pos);
              std::string value = line.substr(pos + 1);

              // Trim whitespace (optional)
              key.erase(key.find_last_not_of(" \n\r\t") + 1);
              value.erase(0, value.find_first_not_of(" \n\r\t"));

              // Store the key-value pair in the hashmap
              configMap[key] = value;
          }
      }

      // Close the config file
      configFile.close();
      displayConfig();
}

// Function to retrieve value as string
std::string ConfigReader::getValueString(const std::string& key) const {
    auto it = configMap.find(key);
    if (it != configMap.end()) {
        return it->second; // Return the value if found
    } else {
        return ""; // Return empty string if key is not found
    }
}

// Function to convert value to int
int ConfigReader::getInt(const std::string& key) const {
    std::string value = getValueString(key);
    return value.empty() ? 0 : std::stoi(value); // Default to 0 if not found
}

// Function to convert value to float
float ConfigReader::getFloat(const std::string& key) const {
    std::string value = getValueString(key);
    return value.empty() ? 0.0f : std::stof(value); // Default to 0.0f if not found
}

ConfigReader::~ConfigReader() {

}

void ConfigReader::displayConfig() const {
	cout << "[" << configFileName << "] =>" << endl;
    for (const auto& pair : configMap) {
        cout << pair.first << " = " << pair.second << endl;
    }
    cout << endl;
}
