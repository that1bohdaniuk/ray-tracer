cmake_minimum_required(VERSION 3.31)
project(ray_tracer)

set(CMAKE_CXX_STANDARD 20)

# Optional: if you have a `headers/` directory
include_directories(${PROJECT_SOURCE_DIR}/headers)

# Define the executable using only .cpp files
add_executable(ray_tracer
        main.cpp
        headers/color.h
        headers/ray.h
        # Add other .cpp files here as you expand
)

