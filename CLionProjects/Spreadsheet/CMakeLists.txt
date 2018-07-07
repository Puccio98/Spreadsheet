cmake_minimum_required(VERSION 3.10)
project(Spreadsheet)

set(CMAKE_CXX_STANDARD 11)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_executable(Spreadsheet main.cpp main.h MyFrame.cpp MyFrame.h)
target_link_libraries(Spreadsheet ${wxWidgets_LIBRARIES})