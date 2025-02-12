#include<chrono>
#include<thread>

// ASCII loader. Takes input in seconds
void loader(int seconds) {
    const char spinner[] = { '|', '/', '-', '\\' };
    int i = 0;
    int totalIterations = seconds * 2; 

    for (int j = 0; j < totalIterations; ++j) {
        std::cout << "\r " << spinner[i];
        std::cout.flush();
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        i = (i + 1) % 4;  
    }
    std::cout<< "\r           \r\n";
}