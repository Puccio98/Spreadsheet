cmake_minimum_required(VERSION 3.10)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(runAllTests runAllTests.cpp TestMySpreadsheet.cpp TestResultCalculation.cpp)
target_link_libraries(runAllTests ${GTEST_BOTH_LIBRARIES} core)
