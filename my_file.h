#include <fstream>
#include <string>
#include <optional>

namespace my::file
{
    class Reader
    {
        public:
            Reader(const std::string& filepath)
                : readStream_(filepath)
            {
            }

            ~Reader()
            {
                readStream_.close();
            }

            bool isOpen()
            {
                return readStream_.is_open();
            }

            std::optional<std::string> readLine()
            {
                std::string line;
                std::getline(readStream_, line);

                if (line.empty())
                {
                    return {};
                }

                return line;
            }

        private:
            std::ifstream readStream_;
    };

    class Writer
    {
        public:
            Writer(const std::string& filepath)
                : writeStream_(filepath)
            {
            }

            ~Writer()
            {
                writeStream_.close();
            }

            bool isOpen()
            {
                return writeStream_.is_open();
            }

            void writeLine(const std::string& line)
            {
                writeStream_ << line << "\n";
            }
            
        private:       
            std::ofstream writeStream_;     
    };

    class Appender
    {
        public:
            Appender(const std::string& filepath)
                : writeStream_(filepath, std::ios::app)
            {
            }

            ~Appender()
            {
                writeStream_.close();
            }

            bool isOpen()
            {
                return writeStream_.is_open();
            }

            void appendLine(const std::string& line)
            {
                writeStream_ << line << "\n";
            }
            
        private:       
            std::ofstream writeStream_;     
    };
}