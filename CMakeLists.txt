cmake_minimum_required(VERSION 3.9)
project(Linux)

set(CMAKE_CXX_STANDARD 17)

add_executable(Linux main.cpp test/Testable.cpp test/Testable.h test/SystemTest.cpp test/SystemTest.h test/ForkTest.cpp test/ForkTest.h test/LambdaTest.cpp test/LambdaTest.h test/PrintDirTest.cpp test/PrintDirTest.h utils/File.cpp utils/File.h test/FileTest.cpp test/FileTest.h test/UnameTest.cpp test/UnameTest.h test/OptTest.cpp test/OptTest.h test/EnvironTest.cpp test/EnvironTest.h test/TimeTest.cpp test/TimeTest.h)
add_executable(Linux2 main2.cpp)
add_executable(TestFork TestFork.cpp)