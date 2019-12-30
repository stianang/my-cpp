#include <vector>
#include <algorithm>
#include <string>

namespace my
{
    namespace vector
    {
        bool contains(const std::vector<std::string>& list, const char* item)
        {
            return std::find(list.cbegin(), list.cend(), item) != list.cend();
        }

        template<typename T>
        bool contains(const std::vector<T>& list, const T item)
        {
            return std::find(list.cbegin(), list.cend(), item) != list.cend();
        }

        template<typename T>
        bool insert(std::vector<T>& list, size_t index, const T& item)
        {
            if (index > list.size())
            {
                return false;
            }
            
            typename std::vector<T>::iterator it;
            it = list.begin() + index;
            list.insert(it, item);

            return true;
        }

        bool remove(std::vector<std::string>& list, const char* elem)
        {
            auto elemCopy = std::string(elem);
            
            auto i = std::find(list.begin(), list.end(), elemCopy);

            if ( i != list.end())
            {
                list.erase(i);
                return true;
            }

            return false;
        }

        template<typename T>
        bool remove(std::vector<T>& list, const T& elem)
        {
            auto i = std::find(list.begin(), list.end(), elem);

            if ( i != list.end())
            {
                list.erase(i);
                return true;
            }

            return false;
        }
    }
}