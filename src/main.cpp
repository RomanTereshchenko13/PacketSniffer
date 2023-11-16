#include "PacketSniffer.h"
#include <thread>
#include <signal.h>

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
    std::cout << "2. Stop Sniffing - Terminate the current sniffing session\n";
    std::cout << "3. Help - Display help information about the tool\n";
    std::cout << "4. Exit - Close the application\n";
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
    std::cout << "5. All\n";
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
            return ETH_P_ALL;
        default:
            return ETH_P_ALL;
    }
}


int main(int argc, const char** argv) 
{
    signal(SIGINT, signalHandler);

    PacketSniffer sniffer;
    std::thread snifferThread;
    bool isRunning = false;

    while (!isRunning) {
        MainMenu();
        int menuChoice;
        std::cin >> menuChoice;

        if (std::cin.fail()) {
            std::cin.clear(); // Clears the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discards the input buffer
            continue;
        }

        switch (menuChoice) {
            case 1:
                if (!isRunning) {
                    int protocol = GetProtocol();
                    snifferThread = std::thread(&PacketSniffer::Start, &sniffer, protocol);
                    isRunning = true;
                } else {
                    std::cout << "Sniffer is already running.\n";
                }
                break;
            case 2:
                if (isRunning) {
                    sniffer.Stop();
                    isRunning = false;
                } else {
                    std::cout << "Sniffer is not running.\n";
                }
                break;
            case 3:
                std::cout << "Help: Choose 1 to start sniffing, 2 to stop, 3 for help, and 4 to exit.\n\n";
                break;
            case 4:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "\nInvalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}