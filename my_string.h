#include <algorithm>
#include <string>
#include <sstream>
#include <vector>

namespace my
{
    namespace string
    {
        void replace(std::string& s, const std::string& from, const std::string& to)
        {
            size_t start_pos = 0;
            while((start_pos = s.find(from, start_pos)) != std::string::npos) {
                s.replace(start_pos, from.length(), to);
                start_pos += to.length(); // Handles case where 'to' is a substring of 'from'
            }
        }
        
        void replace(std::string& s, char from, char to)
        {
            std::replace( s.begin(), s.end(), from, to);
        }
        
        void replaceRange(std::string& s, std::size_t from, std::size_t to, const std::string& word)
        {
            s = s.replace(from, to-from, word);
        }
        
        void insert(std::string& s, std::size_t index, const std::string& word)
        {
            if (index > s.size())
            {
                index = s.size();
            }
           
            s = s.replace(index, 0, word);
        }
        

        std::vector<std::string> split(std::string s, std::string delimiter = " ")
        {
            std::vector<std::string> lines;
            
            size_t last = 0; 
            size_t next = 0; 
            
            while ((next = s.find(delimiter, last)) != std::string::npos) 
            { 
                lines.push_back(s.substr(last, next-last)); 
                last = next + 1; 
                
            } 
            lines.push_back(s.substr(last));

            return lines;
        }
        
        template<typename T>
        std::string join(const std::vector<T>& list, std::string delimiter = " ")
        {
            std::stringstream ss;
            
            for (size_t i = 0; i < list.size(); ++i)
            {
                ss << list.at(i);
                
                if (i < list.size() - 1)
                {
                    ss << delimiter;
                }
            }
            
            return ss.str();
        }
        
        bool contains(const std::string& s, const std::string& word)
        {
            return s.find(word) != std::string::npos;
        }
        
        bool beginsWith(const std::string& s, const std::string& word)
        {
            if (word.size() > s.size())
            {
                return false;
            }
            
            return s.substr(0, word.size()) == word;
        }
        
        bool endsWith(const std::string& s, const std::string& word)
        {
            if (word.size() > s.size())
            {
                return false;
            }
            
            return s.substr(s.size() - word.size(), word.size()) == word;
        }
        
        void trimEnd(std::string& s)
        {
            s.erase(find_if_not(s.rbegin(),s.rend(),[](int c)
                                                    {
                                                        return isspace(c);
                                                    }).base(), s.end());
        }
        
        void trimStart(std::string& s)
        {
            s.erase(s.begin(), std::find_if_not(s.begin(),s.end(),[](int c)
                                                                  {
                                                                      return isspace(c);
                                                                  }));
        }
        
        void trim(std::string& s)
        {
            trimStart(s);
            trimEnd(s);
        }
        
        int toInt(const std::string& s)
        {
            return std::stoi(s);
        }

        double toDouble(const std::string& s)
        {
            return std::stod(s);
        }
        
        template <typename T>
        std::string toString(const T& val)
        {
            return std::to_string(val);
        }
        
        std::string substring(const std::string &s, size_t len)
        {
            if (len > s.size())
            {
                return s;
            }
            
            return s.substr(0, len);
        }
        
        std::string substring(const std::string &s, size_t start, size_t end)
        {
            if (end > s.size())
            {
                end = s.size();
            }
            
            if (end < start)
            {
                end = start;
            }
            
            size_t len = end - start;
            
            return s.substr(start, len);
        }
        
        size_t findIndex(const std::string& s, const std::string& word, size_t startIndex = 0)
        {
            return s.find(word, startIndex);
        }
    }
}