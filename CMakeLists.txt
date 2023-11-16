cmake_minimum_required(VERSION 3.16)
project(PacketSniffer)

set(CMAKE_CXX_STANDARD 17)

set(HEADERS
    src/RawSocket.h
    src/PacketSniffer.h
    src/PacketProcessor.h
)

set(SOURCES
    src/main.cpp
    src/RawSocket.cpp
    src/PacketSniffer.cpp
    src/PacketProcessor.cpp
)

add_executable(PacketSniffer ${HEADERS} ${SOURCES})


