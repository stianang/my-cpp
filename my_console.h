#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>

namespace my
{
    namespace console
    {
        
        std::string readInput()
        {
            std::string text;
            std::string line;
            
            while(getline(std::cin, line))
            {
                text +=line;
            }
            return text;
        }
        
        std::string readInputLine()
        {
            std::string line;
            getline(std::cin, line);
            return line;
        }
        
        template<typename T>
        void readInputLine(T& value)
        {
            std::stringstream ss;
            ss << readInputLine();
            ss >> value;
        }
        
        std::vector<std::string> readInputLines()
        {
            std::vector<std::string> lines;
            std::string line;
            
            while(getline(std::cin, line))
            {
                lines.push_back(line);
            }
            return lines;
        }
        
        template<typename ...Args>
        void printLine(Args&&... args) 
        {
            (std::cout <<  ... <<  std::forward<Args>(args)) << '\n';
        }
        
        template<typename T>
        void print(const std::vector<T>& list, std::string delimiter = "\n")
        {
            for (size_t i = 0; i < list.size(); ++i)
            {
                std::cout << list.at(i) << delimiter;
            }
        }
        
        template<typename TKey, typename TValue>
        void print(const std::map<TKey, TValue>& m, std::string keyValueDelimiter = " : ", std::string delimiter = "\n")
        {
            size_t i = 0;
            for (const auto[key, value] : m)
            {
                std::cout << key << keyValueDelimiter << value
                          << delimiter;
                ++i;
            }
        }

        
        std::vector<std::string> readArguments(int argc, char** argv)
        {
            std::vector<std::string> arguments;
            
            for (int i = 0; i < argc; ++i) 
            {
                arguments.push_back(argv[i]);
            }

            return arguments;
        }

        std::map<std::string,std::string> readArgumentsToMap(int argc, char** argv, const char delimiter = '-')
        {
            std::map<std::string, std::string> arguments;

            for (int i = 0; i < argc; ++i) 
            {
                std::string argKey(argv[i]);
 
                if (argKey[0] == delimiter && (i+1 < argc))
                {
                    std::string argKey(argv[i]);
                    
                    arguments[argKey] += argv[i+1];
                }
            } 

            return arguments;
        }
    }
}
