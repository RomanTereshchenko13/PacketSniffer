#include "PacketSniffer.h"
#include <thread>
#include <signal.h>

int main(int argc, const char** argv) 
{
    PacketSniffer sniffer;

    std::thread t(&PacketSniffer::Start, &sniffer);

    while (sniffer.IsRunning()) {
        auto [receivedBytes, sentBytes] = sniffer.GetTotalBytes();
        std::cout << "Total Sent: " << sentBytes << " bytes, Total Received: " << receivedBytes << " bytes\n";
        std::this_thread::sleep_for(std::chrono::seconds(3));
    }

    sniffer.Stop();
    t.join();

    return 0;
}