CMAKE_MINIMUM_REQUIRED(VERSION 3.3)

project(yaml_cpp_submodule_example)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(yaml-cpp)

include_directories(yaml-cpp/include)
add_executable(yaml_cpp_submodule_example src/main.cpp)
target_link_libraries(yaml_cpp_submodule_example yaml-cpp)
