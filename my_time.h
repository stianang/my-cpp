#include <chrono>
#include <thread>

namespace my
{
    namespace time
    {
        unsigned long epoch_seconds_now()
        {
            return std::chrono::duration_cast<std::chrono::seconds>
                  (std::chrono::system_clock::now().time_since_epoch()).count();
        }

        unsigned long epoch_milliseconds_now()
        {
            return std::chrono::duration_cast<std::chrono::milliseconds>
                  (std::chrono::system_clock::now().time_since_epoch()).count();
        }

        void sleepForSeconds(uint seconds)
        {
             std::this_thread::sleep_for(std::chrono::seconds(seconds));
        }

        void sleepForMilliseconds(uint milliseconds)
        {
             std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
        }
    }
}