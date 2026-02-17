#include <iostream>
#include <vector>
#include <cstring>
#include <thread>
#include <chrono>

int main() {
    
    const size_t BLOCK_SIZE = 1024 * 100 * 1024; 
    
    std::vector<char*> memory_blocks;

    std::cout << "Memoria Stressz Teszt inditasa..." << std::endl;
    std::cout << "Nyomj Ctrl+C-t a kilepeshez!" << std::endl;

    try {
        long long total_allocated = 0;
        
        while (true) {
            char* buffer = new char[BLOCK_SIZE];
            std::memset(buffer, 0, BLOCK_SIZE);
            memory_blocks.push_back(buffer);
            total_allocated += BLOCK_SIZE;
            std::cout << "Lefoglalva: " << (total_allocated / (1024 * 1024)) << " MB" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    } catch (const std::bad_alloc& e) {
        std::cout << "Hiba: A memoria megtelt! (" << e.what() << ")" << std::endl;
    }
    
    return 0;
}
