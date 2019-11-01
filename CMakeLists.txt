cmake_minimum_required(VERSION 3.14)
project(Autocomplete)

set(CMAKE_CXX_STANDARD 17)

add_executable(Autocomplete autocomplete_test.cpp term.hpp term.cpp binary_search_deluxe.hpp binary_search_deluxe.cpp autocomplete.hpp autocomplete.cpp)