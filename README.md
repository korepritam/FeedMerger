# FeedMerger

FeedMerger is a C++ program designed to efficiently merge market data from multiple files into a single output file. It handles billions of entries while maintaining sorted order based on timestamps and symbols. Leveraging multithreading, FeedMerger improves performance and reduces processing time when handling large datasets.

## Features

- **Efficient Merging**: Utilizes a priority queue to merge data while minimizing memory usage.
- **Multithreading Support**: Processes multiple input files concurrently, significantly speeding up the merge operation.
- **Handles Large Data Sets**: Designed to work with large numbers of files (up to 10,000) and entries.
- **Sorted Output**: Ensures that the final output is sorted by timestamp, with ties broken by symbol.

## Requirements

- **C++11 or higher**: The code is written in modern C++ and requires a compatible compiler.
- **Standard Libraries**: The program uses standard libraries like `<iostream>`, `<cstdio>`, `<cstring>`, `<vector>`, `<queue>`, `<thread>`, and the **pthread** library for multithreading.
  
## Installation

1. Clone the repository:
   ```bash
   git clone https://github.com/yourusername/FeedMerger.git
   cd FeedMerger
