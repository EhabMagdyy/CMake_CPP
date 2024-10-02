# specifies the minimum version of CMake required to build the project.
cmake_minimum_required(VERSION 3.26)

# name given to this project.
PROJECT(CMakeCPP)

# SRC_FILES --(Raplcaed by)-> (main.cpp src/calc.cpp)
set(SRC_FILES 
    main.cpp 
    src/calc.cpp)

# Checks if main.cpp exists in your directory
if(EXISTS ${CMAKE_SOURCE_DIR}/main.cpp)
    message(STATUS "File Exists")
else()
    message(FATAL_ERROR"File Not Exists")
endif()

# adds another CMake from subdirectory (acts more like text replacemnt)
add_subdirectory(${CMAKE_SOURCE_DIR}/lib)

# Output file name (output.exe) generates after compiling 
add_executable(output ${SRC_FILES})

# include header files (includes files in inc folder) & lib/
target_include_directories(output PUBLIC inc/ lib/)

# checks if there is wifi_lib
if(TARGET wifi_lib)
    # links wifi_lib with your executable
    target_link_libraries(output PUBLIC wifi_lib)
else()
    message(WARNING"wifi_lib not found")
endif()
