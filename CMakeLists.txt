cmake_minimum_required (VERSION 3.20)
project (prototype) 

set(LLVM_DIR /usr/lib/llvm-18/cmake)

add_subdirectory(ext/Enzyme/enzyme)

add_executable(prototype src/main.cpp)

target_link_libraries(prototype PRIVATE ClangEnzymeFlags)


