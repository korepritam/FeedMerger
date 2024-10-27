/*
 * FileManager.cpp
 *
 *  Created on: 27 Oct 2024
 *      Author: pritam
 */

#include "FileManager.h"
#include "MarketDataContainer.h"

FileManager::FileManager()
{

}

FileManager::~FileManager()
{

}

void FileManager::insertStockFiles(int stockFilesCount_, char** stockFilesList_)
{
	for(int i=0; i<stockFilesCount_; i++)
	{
		StocksFileList.push_back({stockFilesList_[i],i});
	}
	cout << "argc:" << stockFilesCount_ << " size:" << StocksFileList.size() << endl;
}

int FileManager::readStockFiles()
{
	for(int i=0; i<StocksFileList.size(); i++)
	{
        FILE* files = fopen(StocksFileList[i].filename.c_str(), "r");
        if (!files) {
            perror("Failed to open file");
            return EXIT_FAILURE;
        }
        // Set line buffering
        setvbuf(files, NULL, _IOLBF, 0);
        char LINE[1024];
        fgets(LINE, sizeof(LINE), files);
        memset(LINE,'\0',1024);

        if (fgets(LINE, sizeof(LINE), files) != NULL)
        {
        	cout << LINE;
        }
	}
	return EXIT_SUCCESS;
}

int FileManager::readFile(FilesMetadata fileMetaData)
{
    FILE* file = fopen(fileMetaData.filename.c_str(), "r");
    if (!file) {
        perror("Failed to open file");
        return EXIT_FAILURE;
    }
    // Set line buffering
    setvbuf(file, NULL, _IOLBF, 0);
    char LINE[1024];
    fgets(LINE, sizeof(LINE), file);
    memset(LINE,'\0',1024);

    if (fgets(LINE, sizeof(LINE), file) != NULL) {
    	int sourceFileIndex = fileMetaData.fileNo;
    	char timestamp[13];
		char symbol[10];
		char data[1024];

    	//2021-03-05 10:00:00.123, 228.5, 120, NYSE, Ask
		sscanf(LINE, "%*10s %12s, %*f, %*d, %9s, %*4s", timestamp, symbol);
//    	sscanf(LINE, "%c, %*c, %*c, %c, %*c", timestamp, symbol);
    	strcpy(data,LINE);

//    	cout << LINE << endl;
    	MarketDataTick *tick = new MarketDataTick(timestamp,symbol,data,sourceFileIndex,ftell(file));
    	MarketDataContainer::getInstance()->pushToContainer(tick);
    }

    fclose(file);
	return EXIT_SUCCESS;
}
