#include "../my_time.h"
#include <iostream>

int main()
{
    auto start = my::time::epoch_milliseconds_now();

    my::time::sleepForMilliseconds(1000);

    auto end = my::time::epoch_milliseconds_now();

    std::cout << "Elapsed time: " << (end-start) << std::endl;
}