#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
        return (std::cerr << "Error: need args to work" << std::endl, 1);
    try {
        RPN::doTheThing(argv[1]);
    } catch (const std::exception& e) {
        return (std::cerr << e.what() << std::endl, 1);
    }
    return (0);
}
