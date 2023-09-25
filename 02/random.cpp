#include <iostream>
#include <random>
#include <chrono>
#include <fstream>

#include "vector.h"  // Uncomment this for testing vector performance
// #include "list.h"  // Uncomment this for testing list performance

int main(int argc, char **argv) {
    if(argc != 2) {
        std::cout << "random: must specify number" << std::endl;
        return (404);
    }
    int number = atoi(argv[1]);

    List list;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> randint(1, 100);

    std::ofstream outputFile("performance_data.csv", std::ios_base::app);

    //if file is empty, add header
    outputFile.seekp(0, std::ios::end);
    if (outputFile.tellp() == 0) {
        outputFile << "Input Size,Data Structure,Insertion Time (ms),Deletion Time (ms)\n";
    }    
    // Start timing the insertions at both ends
    auto startInsert = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < number; ++i) {    
        int value = randint(gen);
        if (i % 2 == 0) {
            list.insertFront(value);
        } else {
            list.insertBack(value);
        }
    }

    auto endInsert = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedInsert = endInsert - startInsert;

    // Start timing the deletions from both ends
    auto startDelete = std::chrono::high_resolution_clock::now();

    while (!list.isEmpty()) {
        if (randint(gen) % 2 == 0) {
            list.removeFront();
        } else {
            list.removeBack();
        }
    }

    auto endDelete = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedDelete = endDelete - startDelete;

    std::cout << "Time taken for insertions: " << elapsedInsert.count() << "ms" << std::endl;
    std::cout << "Time taken for deletions: " << elapsedDelete.count() << "ms" << std::endl;

    //  outputFile << number << ",List," << elapsedInsert.count() << "," << elapsedDelete.count() << "\n";
    // outputFile.close();

    outputFile << number << ",Vector," << elapsedInsert.count() << "," << elapsedDelete.count() << "\n";
    outputFile.close();

    return 0;
}
