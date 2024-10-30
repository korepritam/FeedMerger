cmake_minimum_required(VERSION 3.20)

project(FeedMerger CXX)
set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX FLAGS ${CMAKE_CXX_FLAGS} -std=c++17)
set(CMAKE_CURRENT_SOURCE_DIR $ENV{HOME}/git/FeedMerger)

add_executable(${PROJECT_NAME})

target_sources (FeedMerger
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/CommonStructures.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/ConfigReader.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/ThreadWorker.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MarketDataTick.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GlobalMembers.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/FileManager.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/MarketDataContainer.cpp
)

target_include_directories(FeedMerger
	PUBLIC
	${CMAKE_CURRENT_SOURCE_DIR}/src/
	${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(${PROJECT_NAME}
	PUBLIC
	-pthread
)
