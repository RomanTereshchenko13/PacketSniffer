# Packet Sniffer

## Overview
Packet Sniffer is a network analysis tool designed to capture and display the contents of packets on a network. It is useful for network debugging and analysis.

## System Requirements
- Linux-based operating system
- C++ compiler with C++11 support
- Root privileges for raw socket operations
- CMake for building the project

## Installation
Compile the source code using a C++ compiler. Ensure you have the necessary permissions to create and use raw sockets.

## Usage
Run the Packet Sniffer executable. The application provides a simple text-based user interface with multiple options:
1. **Start Sniffing**: Begin capturing packets on the network.
2. **Help**: Display help information.
3. **Exit**: Close the application.

## Main Components

### `RawSocket` Class
RAII implementation of socket. Manages the raw socket for packet capturing. It initializes the socket with the specified protocol and provides methods to receive packets.

### `PacketSniffer` Class
The main class for the application. It interfaces with the RawSocket and PacketProcessor classes to capture and process network packets.

### `PacketProcessor` Class
Processes captured packets. It parses different headers (Ethernet, IP, TCP, UDP, ICMP, IGMP) and prints packet information.

## Protocols Supported
- IP
- TCP
- UDP
- ICMP
- IGMP
- 
## Installation
### Building with CMake
1. Clone the repository:
   git clone https://github.com/RomanTereshchenko13/PacketSniffer.git
2. Navigate to the cloned directory:
   cd PacketSniffer
3. Create a build directory and navigate into it:
   mkdir build && cd build
4. Run CMake to configure the project and generate a Makefile:
   cmake ..
5. Compile the project:
   make

## Example Usage
1. Run the Packet Sniffer.
2. Choose `1. Start Sniffing`.
3. Select the desired protocol to sniff.
4. Observe the packet information on the console.

## Troubleshooting
- Ensure you have root privileges to use raw sockets.
- If you encounter input errors, the program will prompt you to re-enter your choice.

## Limitations
- Compatible only with Linux-based systems.
- Does not support packet capturing on encrypted networks.

## Future Enhancements
- Adding support for more protocols.
- Implementing a graphical user interface.
