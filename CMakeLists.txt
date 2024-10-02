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

# ########## Important Variables #########
# message(STATUS "CMAKE_SOURCE_DIR: ${CMAKE_SOURCE_DIR}")
# message(STATUS "CMAKE_CURRENT_SOURCE_DIR: ${CMAKE_CURRENT_SOURCE_DIR}")

# message(STATUS "CMAKE_BINARY_DIR: ${CMAKE_BINARY_DIR}")
# message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")

# message(STATUS "CMAKE_GENERATOR: ${CMAKE_GENERATOR}")

# #message(STATUS "Enviromental variable path: $ENV{PATH}")
# ########################################

# ############ Configure file ############
# # Set PRODUCT_YEAR = "2024"
# set(PRODUCT_YEAR "2024")
# # generates defaultconfig.h from defultconfig.h.in
# configure_file(defultconfig.h.in defaultconfig.h)
# # adds generated header file from build folder to the exe file
# target_include_directories(output PUBLIC ${PROJECT_BINARY_DIR})
# #########################################

# ############ if logic param #############
# # NOT / AND / OR / MATCHES / LESS / GREATER / EQUAL / TARGET
# #########################################

# ################## for ##################
# set(lst E H A B)
# foreach(I IN LISTS lst)
#     message(${I})   # E H A B
# endforeach()
# #########################################

# ################# while #################
# set(VAR 3)
# while(VAR)
#     message(${VAR})         # 3 2 1
#     math(EXPR VAR "${VAR} - 1")
# endwhile()
# #########################################

# ################ Function ###############
# function(myFunc arg1)
#     message(${arg1})        # var
#     message(${${arg1}})     # 13
#     message(${ARGN})        # ehde
#     message(${ARGC})        # 3
# endfunction()
# set(var 1 3)
# myFunc(var eh de)
# #########################################

# ############## store in cache ###########
# option(CVar "BOOL VAR" TRUE)    # stored in CMakeCache.txt
# #########################################

# ######### compiler generated var ########
# target_compile_definitions(output PUBLIC "VAR3=13")
# target_compile_options(output PUBLIC -march=native)
# #########################################

# ##### install (copy files to folders) ###
# # Run this command to generate: cmake --install .
# install(FILES "${CMAKE_BINARY_DIR}/output.exe"
#         DESTINATION "${CMAKE_BINARY_DIR}/executable"
#         )

# install(FILES "${CMAKE_SOURCE_DIR}/inc/calc.hpp"
#               "${CMAKE_SOURCE_DIR}/lib/Wifi.hpp"
#         DESTINATION "${CMAKE_BINARY_DIR}/inc"
#         )
# ###########################################

# ################## Files ##################
# # reads your file in its form
# FILE(READ "main.cpp" MAIN_Text)
# Message("${MAIN_Text}")
# message("---------------------------------------")
# # buffer in one line
# FILE(STRINGS "main.cpp" MAIN_Text)
# Message("${MAIN_Text}")
# message("---------------------------------------")
# # return line that have "int" in given file
# FILE(STRINGS "main.cpp" MAIN_Text REGEX "^int.")
# Message("${MAIN_Text}")
# message("---------------------------------------")
# # All .cpp files directoris
# file(GLOB_RECURSE SRCS "*.cpp")
# message("${SRCS}")
# #############################################

# ################### String ##################
# FILE(READ "main.cpp" MAIN_Text)
# STRING(REGEX REPLACE "int" "void" OUT  ${MAIN_Text})
# message("${OUT}")
# #############################################

# ################### Macro ###################
# set(gloablvariable 10)
# macro(funname x)
#     message("${x}")     # 10
#     message("${${x}}")  # gloablvariable
#     set(gloablvariable 15)
# endmacro()
# # function(funname x)
# #     message("${x}")
# #     message("${${x}}")
# #     set(gloablvariable 15 PARENT_SCOPE)
# # endfunction()

# message("${gloablvariable}")    # 10
# funname(gloablvariable)
# message("${gloablvariable}")    # 15
# ##############################################

# ################ break continue ##############
# while(True)
#     message("hello")
#     #continue()
#     break()
# endwhile()
# ###############################################

# ################ execute_process ##############
# execute_process(COMMAND "ls")   # as if i write "ls" in terminal
# ###############################################