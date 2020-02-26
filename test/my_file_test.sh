#!/bin/bash

g++ my_file_test.cpp catch.cpp -o test_my_file -std=c++17 -Wall -Wextra
./test_my_file
