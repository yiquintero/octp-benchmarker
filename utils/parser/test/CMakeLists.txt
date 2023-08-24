cmake_minimum_required(VERSION 3.14)
project(tests)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Fetch and download Google Test
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/b796f7d44681514f58a683a3a71ff17c94edb0c1.zip
)
# Windows: Prevent overriding the parent project's compiler/linker settings
# Currently no parent CMake project, but good to keep for the future
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Enable testing in CMake
enable_testing()

include_directories(
    ${CMAKE_SOURCE_DIR}/../
)

add_executable(
    tests
    testfileparser.cpp
    testfilewriter.cpp
    testbenchmarkdata.cpp
    ${CMAKE_SOURCE_DIR}/../fileparser.cpp
    ${CMAKE_SOURCE_DIR}/../filewriter.cpp
)

target_link_libraries(
    tests
    GTest::gtest_main
)

# Enable CMake’s test runner to discover the tests included in the binary,
# using the GoogleTest CMake module.
include(GoogleTest)
gtest_discover_tests(tests)
