#include "../my_console.h"

int main(int argc, char **argv)
{
    auto arguments = my::console::readArgumentsToMap(argc, argv);
    my::console::print(arguments);


    my::console::printLine("Input letter 'c':");
    auto letter = my::console::readInputLine();
    
    my::console::printLine("Input number '123':");
    int number;
    my::console::readInputLine(number);


    std::vector<int> numberList {1,2,3,4,5};
    my::console::print(numberList, " ");
    my::console::printLine();

    my::console::printLine("This is a number: ", 234, ", and so is this: ", 1.232);
    
}