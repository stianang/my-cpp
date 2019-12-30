#!/bin/bash

g++ my_string_test.cpp catch.cpp -o test_my_string -std=c++17 -Wall -Wextra
./test_my_string
