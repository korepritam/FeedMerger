#include <gtest/gtest.h>
#include "MarketDataContainer.h"

class ComparatorTest : public ::testing::Test {
public:
     CompareTick comp;
};

TEST_F(ComparatorTest, CompareLesserThan) {
	CompareTick comp;
	FilesMetadata fmd1 ("MSFT.txt", 1);

	MarketDataTick mdt1 ("2021-05-23 10:00:00.123", "NYKAA", "data", fmd1);
	MarketDataTick mdt2 ("2021-05-23 10:00:00.23", "NYKAA", "data", fmd1);
	MarketDataTick mdt3 ("2021-05-23 10:00:00.23", "APPLE", "data", fmd1);

	EXPECT_TRUE(comp(&mdt1, &mdt2)); // 1 > 2 so it should return true
	EXPECT_FALSE(comp(&mdt2, &mdt1)); // 2 > 1, so it should return false
	EXPECT_TRUE(comp(&mdt2, &mdt3)); // 2 < 3, should return true
}

TEST_F(ComparatorTest, PriorityQueueBehavior) {
	priority_queue<MarketDataTick*, vector<MarketDataTick*>, CompareTick> pq;

	FilesMetadata fmd1 ("OneFile.txt", 1);
	pq.push(new MarketDataTick("2024-05-21 10:00:00.123", "AXIS", "data", fmd1));
	pq.push(new MarketDataTick("2024-05-21 10:00:00.23", "NYKAA", "data", fmd1));
	pq.push(new MarketDataTick("2024-05-21 10:00:00.23", "APPLE", "data", fmd1));

	// The largest item based on value should be on top
	EXPECT_EQ(pq.top()->timestamp, "2024-05-21 10:00:00.23");
	EXPECT_EQ(pq.top()->symbol, "APPLE");
	pq.pop();
	pq.push(new MarketDataTick("2024-05-21 10:00:00.27", "APPLE", "data", fmd1));

	EXPECT_EQ(pq.top()->timestamp, "2024-05-21 10:00:00.23");
	EXPECT_EQ(pq.top()->symbol, "NYKAA");
	pq.pop();
	pq.push(new MarketDataTick("2024-05-21 10:00:00.127", "NYKAA", "data", fmd1));

	EXPECT_EQ(pq.top()->timestamp, "2024-05-21 10:00:00.27");
	EXPECT_EQ(pq.top()->symbol, "APPLE");
	pq.pop();

	EXPECT_EQ(pq.top()->timestamp, "2024-05-21 10:00:00.123");
	EXPECT_EQ(pq.top()->symbol, "AXIS");
	pq.pop();

	EXPECT_EQ(pq.top()->timestamp, "2024-05-21 10:00:00.127");
	EXPECT_EQ(pq.top()->symbol, "NYKAA");
	pq.pop();

    // Clean up allocated memory
    while (!pq.empty()) {
        delete pq.top();
        pq.pop();
    }
}
