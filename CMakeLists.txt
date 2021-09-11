cmake_minimum_required(VERSION 3.10)

project(Linter)

find_package(LLVM REQUIRED CONFIG)

add_executable(run main.cpp)

include_directories(${LLVM_INCLUDE_DIRS})
add_definitions(${LLVM_DEFINITIONS})

llvm_map_components_to_libnames(llvm_libs support core irreader)




target_include_directories(run PUBLIC "${PROJECT_BINARY_DIR}")
target_link_libraries(run ${llvm_libs})
