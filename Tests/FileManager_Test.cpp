#include <gtest/gtest.h>
#include "FileManager.h"
#include "MarketDataContainer.h"

class FileManagerTest : public ::testing::Test {
protected:
    FileManager* fileManager;

    void SetUp() override {
        fileManager = new FileManager();
        FILE* testFile = fopen("MSFT.txt", "w");
        if (testFile) {
            fputs("2021-03-05 10:00:00.123, 228.5, 120, NYSE, Ask\n", testFile);
            fclose(testFile);
        }
    }

    void TearDown() override {
        delete fileManager;
        remove("MSFT.txt"); // Clean up the mock file
        remove("MultiPlexedFile.txt"); // Clean up the output file if it exists
    }
};

TEST_F(FileManagerTest, InsertStockFiles) {
    int stockFilesCount = 1;
    char* stockFilesList[] = { "MSFT.txt" };

    fileManager->insertStockFiles(stockFilesCount, stockFilesList);

    EXPECT_EQ(fileManager->GetStockFileListSize(), 1);
    EXPECT_EQ(fileManager->getFileName(0).filename, "MSFT.txt");
}

TEST_F(FileManagerTest, ReadStockFiles) {
    int stockFilesCount = 1;
    char* stockFilesList[] = { "MSFT.txt" };

    fileManager->insertStockFiles(stockFilesCount, stockFilesList);

    EXPECT_EQ(fileManager->readStockFiles(), EXIT_SUCCESS);
}

TEST_F(FileManagerTest, WriteToFile) {

	FilesMetadata metaData{"MSFT.txt", 0};
    MarketDataTick* tick = new MarketDataTick("2021-03-05 10:00:00.123", "AAPL",
    		"2021-03-05 10:00:00.123, 228.5, 120, NYSE, Ask", metaData);

    fileManager->writeToFile(tick);

    FILE* outputFile = fopen("MultiPlexedFile.txt", "r");
    ASSERT_NE(outputFile, nullptr);

    char buffer[256];
    fgets(buffer, sizeof(buffer), outputFile);
    EXPECT_STRNE(buffer, "");

    fclose(outputFile);
    delete tick;
}

TEST_F(FileManagerTest, ReadFileNonExistent) {
    FilesMetadata metaData{"non_existent_file.txt", 0};
    EXPECT_EQ(fileManager->readFile(metaData), EXIT_FAILURE);
}
