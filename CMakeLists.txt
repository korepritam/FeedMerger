cmake_minimum_required(VERSION 3.20)

project(FeedMerger CXX)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)
set(PROJECT_PATH $ENV{HOME}/git/FeedMerger)

add_executable(${PROJECT_NAME})

target_sources (FeedMerger
	PUBLIC
	${PROJECT_PATH}/src/CommonStructures.cpp
	${PROJECT_PATH}/src/ConfigReader.cpp
	${PROJECT_PATH}/src/ThreadWorker.cpp
	${PROJECT_PATH}/src/MarketDataTick.cpp
	${PROJECT_PATH}/src/main.cpp
	${PROJECT_PATH}/src/GlobalMembers.cpp
	${PROJECT_PATH}/src/FileManager.cpp
	${PROJECT_PATH}/src/MarketDataContainer.cpp
)

target_include_directories(FeedMerger
	PUBLIC
	${PROJECT_PATH}/src/
	${PROJECT_PATH}/include
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
	-pthread
)
