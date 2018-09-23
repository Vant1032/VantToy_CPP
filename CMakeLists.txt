cmake_minimum_required(VERSION 3.9)
project(Linux)

set(CMAKE_CXX_STANDARD 17)

add_executable(Linux main.cpp test/Testable.cpp test/Testable.h test/SystemTest.cpp test/SystemTest.h test/ForkTest.cpp test/ForkTest.h test/LambdaTest.cpp test/LambdaTest.h test/PrintDirTest.cpp test/PrintDirTest.h utils/File.cpp utils/File.h)