cmake_minimum_required(VERSION 3.26)

message("Hello from lib cmake!")

# generate lib file if Wifi.cpp & Wifi.hpp
add_library(wifi_lib 
            Wifi.cpp
            Wifi.hpp)