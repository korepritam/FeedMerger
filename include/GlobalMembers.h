/*
 * GlobalMembers.h
 *
 *  Created on: 26 Oct 2024
 *      Author: pritam
 */

#ifndef GLOBALMEMBERS_H_
#define GLOBALMEMBERS_H_

#include "FileManager.h"
#include "ThreadWorker.h"

void InitializeGlobalMembers();
FileManager* GetFileManager();
void SpawnThreadWorkers();
void DestroyGlobalMembers();
void DumpFeed();

#endif /* GLOBALMEMBERS_H_ */
