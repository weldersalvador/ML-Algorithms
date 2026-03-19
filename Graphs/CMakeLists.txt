cmake_minimum_required(VERSION 3.10)

project(GraphsProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Executável
add_executable(main
    main.cpp
    graph.cpp
)