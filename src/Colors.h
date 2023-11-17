#ifndef COLORS_H
#define COLORS_H

#include <string>

namespace COLORS
{
    // ANSI escape codes for colors
    const std::string RED = "\033[31m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string BLUE = "\033[34m";
    const std::string MAGENTA = "\033[35m";
    const std::string CYAN = "\033[36m";
    const std::string PURPLE = "\033[38;5;129m";
    const std::string RESET = "\033[0m";
}

#endif // !COLORS_H

