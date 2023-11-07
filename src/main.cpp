#include "PacketSniffer.h"
#include <thread>
#include <signal.h>

bool running = true;

void signalHandler(int signum) 
{
    running = false;
}

int main(int argc, const char** argv) 
{
    signal(SIGINT, signalHandler);

    PacketSniffer sniffer;

    std::thread t(&PacketSniffer::Start, &sniffer);

    while (running) {
        //TODO
    }

    sniffer.Stop();
    t.join();

    return 0;
}