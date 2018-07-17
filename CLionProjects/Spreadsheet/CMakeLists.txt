cmake_minimum_required(VERSION 3.10)
project(Spreadsheet)

set(CMAKE_CXX_STANDARD 11)
set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})

add_subdirectory(Test)
set(SOURCE_FILES Subject.h Observer.h MySpreadsheet.cpp MySpreadsheet.h Sum.cpp Sum.h Media.cpp Media.h)
add_executable(Spreadsheet main.cpp main.h)
add_library(core ${SOURCE_FILES})
target_link_libraries(Spreadsheet ${wxWidgets_LIBRARIES} core)
