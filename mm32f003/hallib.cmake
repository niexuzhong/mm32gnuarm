# EFM32 Emlib CMake file
#
# Configures the emlib and adds it to the build

##### Files #####

# Headers
include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../include/HALINCLDUE)
include_directories(${CMAKE_CURRENT_LIST_DIR}/../include/CMSIS)

# Source files
FILE(GLOB HALLIB_SOURCES ${CMAKE_CURRENT_LIST_DIR}/*.c)

##### Outputs #####

# Create emlib library
add_library(hallib ${HALLIB_SOURCES})

# Add library to build
set(LIBS ${LIBS} hallib)
