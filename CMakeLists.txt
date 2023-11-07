cmake_minimum_required(VERSION 3.10)
project(PacketSniffer)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES
    src/main.cpp
    src/PacketSniffer.cpp

)

add_executable(PacketSniffer ${SOURCES})


