#!/bin/bash

g++ my_vector_test.cpp catch.cpp -o test_my_vector -std=c++17 -Wall -Wextra
./test_my_vector