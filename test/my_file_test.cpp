#include "../my_file.h"
#include "catch.hpp"

TEST_CASE("my::file::Writer_and_Reader") 
{
    // Write and close
    {
        my::file::Writer writer("my_file_test.txt");

        std::vector<std::string> lines { "Line 1", "Line 2", "Line 3" };

        if (writer.isOpen())
        {
            for (auto line : lines)
            {
                writer.writeLine(line);
            }
        }
    }

    // Append and close
    {
        my::file::Appender appender("my_file_test.txt");
        
        if (appender.isOpen())
        {
            appender.appendLine("Line 4");
        }
    }

    // Read and close
    {
        my::file::Reader reader("my_file_test.txt");

        std::vector<std::string> lines;

        while (auto line = reader.readLine())
        {
            lines.push_back(*line);
        }

        REQUIRE(lines.at(0) == "Line 1");
        REQUIRE(lines.at(1) == "Line 2");
        REQUIRE(lines.at(2) == "Line 3");
        REQUIRE(lines.at(3) == "Line 4");
    }
}
