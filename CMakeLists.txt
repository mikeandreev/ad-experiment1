cmake_minimum_required (VERSION 3.20)
project (prototype) 

# TODO: move this path to CMakePresets
set(LLVM_DIR /usr/lib/llvm-18/cmake)

file(GLOB_RECURSE CALC_SRC src/calc/*.cpp)
file(GLOB_RECURSE ADCALC_SRC src/adcalc/*.cpp)

add_subdirectory(ext/Enzyme/enzyme)

# adcalc_lib: calculation using AD
add_library(adcalc_lib ${ADCALC_SRC})
target_include_directories(adcalc_lib PRIVATE src)
target_compile_features(adcalc_lib PRIVATE cxx_std_20)
target_link_libraries(adcalc_lib PRIVATE LLDEnzymeFlags)

# calc_lib : some calculation tools without AD, can use adcalc_lib
add_library(calc_lib ${CALC_SRC})
target_link_libraries(calc_lib  PRIVATE adcalc_lib)
target_include_directories(calc_lib PRIVATE src)
target_compile_features(calc_lib PRIVATE cxx_std_20)

# wrap everithing together
add_executable(prototype src/main.cpp)

target_compile_features(prototype PRIVATE cxx_std_20)
target_include_directories(prototype PRIVATE src)
target_link_libraries(prototype PRIVATE calc_lib adcalc_lib)
#target_link_libraries(prototype PRIVATE ClangEnzymeFlags)


