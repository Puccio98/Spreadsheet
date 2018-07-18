cmake_minimum_required(VERSION 3.10)

set(wxWidgets_CONFIGURATION mswu)
find_package(wxWidgets COMPONENTS core base REQUIRED)
include(${wxWidgets_USE_FILE})
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runAllTests runAllTests.cpp TestMySpreadsheet.cpp TestCalculation.cpp)
target_link_libraries(runAllTests ${wxWidgets_LIBRARIES} core)
target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core)

