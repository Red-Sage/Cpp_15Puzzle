cmake_minimum_required(VERSION 3.14)
project(Cpp_15Puzzle VERSION 0.1.0)

# gtest stuff
#------------------------------------------------------------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
#------------------------------------------------------------------------------

include(CTest)
enable_testing()

add_executable(Cpp_15Puzzle main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

add_executable(board_test ./test/board_test.cc)
target_link_libraries(board_test GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(board_test)
