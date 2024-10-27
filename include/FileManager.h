/*
 * FileManager.h
 *
 *  Created on: 27 Oct 2024
 *      Author: pritam
 */

#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_

#include "CommonStrctures.h"

class FileManager {
	vector<FilesMetadata> StocksFileList;

public:
	FileManager();
	~FileManager();
	void insertStockFiles(int stockFilesCount_, char** stockFilesList_);
	int readStockFiles();
	int readFile(FilesMetadata fileMetaData);

	inline const int GetStockFileListSize()			 		const {return StocksFileList.size();}
	inline const vector<FilesMetadata>& getStocksFileList() const {return StocksFileList;}
	inline FilesMetadata getFileName(int num) 				const {return StocksFileList[num];}
};

#endif /* FILEMANAGER_H_ */
