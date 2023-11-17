#include "PacketSniffer.h"
#include <signal.h>
#include <iostream>

void signalHandler(int signum)
{
    std::cout << "\nInterrupt signal (" << signum << ") received.\n";
    exit(signum);
}

void MainMenu()
{
    using namespace COLORS;

    std::cout << "\n=====================================\n";
    std::cout << GREEN << "       Welcome to Packet Sniffer!\n" << RESET;
    std::cout << "=====================================\n";
    std::cout << YELLOW << "1. Start Sniffing\n" << RESET;
    std::cout << YELLOW << "2. Help\n" << RESET;
    std::cout << YELLOW << "3. Exit\n" << RESET;
    std::cout << "\n" << CYAN << "Please select an option: " << RESET;
}

int GetProtocol() 
{
    using namespace COLORS;

    int protocolChoice;
    std::cout << GREEN << "Select protocol to sniff:\n" << RESET;
    std::cout << YELLOW << "1. IP\n";
    std::cout << "2. TCP\n";
    std::cout << "3. UDP\n";
    std::cout << "4. ICMP\n";
    std::cout << "5. IMGP\n " << RESET;
    std::cout << "\nPlease choose a protocol: ";
    std::cin >> protocolChoice;

    switch (protocolChoice) {
        case 1:
            return IPPROTO_IP;
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

void ShowHelp() {
    std::cout << "\nHelp Information:\n";
    std::cout << "1. Start Sniffing: Choose a protocol (IP, TCP, UDP, ICMP, IGMP) and begin sniffing.\n";
    std::cout << "2. Stop Sniffing: Stops the current packet sniffing process if active.\n";
    std::cout << "3. Help: Displays this help information.\n";
    std::cout << "4. Exit: Closes the Packet Sniffer application.\n";
    // Add protocol descriptions here
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
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
        continue; 
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
            {
                ShowHelp();
                break;
            }
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