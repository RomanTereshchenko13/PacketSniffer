#include "PacketSniffer.h"
#include <thread>
#include <signal.h>
#include <iostream>

void signalHandler(int signum)
{
    std::cout << "\nInterrupt signal (" << signum << ") received.\n";
    exit(signum);
}

void MainMenu()
{
    std::cout << "\n=====================================\n";
    std::cout << "       Welcome to Packet Sniffer!\n";
    std::cout << "=====================================\n";
    std::cout << "1. Start Sniffing - Begin packet sniffing on a selected protocol\n";
    std::cout << "2. Help - Display help information about the tool\n";
    std::cout << "3. Exit - Close the application\n";
    std::cout << "\nPlease select an option: ";
}

int GetProtocol() 
{
    int protocolChoice;
    std::cout << "Select protocol to sniff:\n";
    std::cout << "1. IP\n";
    std::cout << "2. TCP\n";
    std::cout << "3. UDP\n";
    std::cout << "4. ICMP\n";
    std::cout << "5. IMGP\n ";
    std::cout << "\nPlease choose a protocol: ";
    std::cin >> protocolChoice;

    switch (protocolChoice) {
        case 1:
            return -1;
        case 2:
            return IPPROTO_TCP;
        case 3:
            return IPPROTO_UDP;
        case 4:
            return IPPROTO_ICMP;
        case 5:
            return IPPROTO_IGMP;
        default:
            std::cout << "Invalid choice. Please try again.\n";
            return GetProtocol();
    }
}

int main(int argc, const char** argv) 
{
    signal(SIGINT, signalHandler);

    std::thread snifferThread;
    bool isRunning = false;
    PacketSniffer sniffer;

    while (!isRunning) {
        MainMenu();
        int menuChoice;
        std::cin >> menuChoice;

        if(std::cin.fail()) {
        std::cin.clear(); // Clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore bad input
        continue; // Skip the rest of the loop iteration
        }

        switch (menuChoice) {
            case 1:
            {
                int protocol = GetProtocol();
                isRunning = true;
                snifferThread = std::thread(&PacketSniffer::Start, &sniffer, protocol);
                break;
            }
            case 2:
                std::cout << "Help: Choose 1 to start sniffing, 2 to stop, 3 for help, and 4 to exit.\n\n";
                break;
            case 3:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    }

    sniffer.Stop();
    if (snifferThread.joinable()) {
        snifferThread.join();

    }

    return 0;
}