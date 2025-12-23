# Versión mínima de CMake
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(TinyRenderer)

# Especificar el estándar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar todos los archivos .cpp y .h (opcional, pero limpio)
set(SOURCES 
    Rasterization/main.cpp 
    Rasterization/tgaimage.cpp 
    Rasterization/tgaimage.h
)

# Crear el ejecutable
add_executable(tiny_renderer ${SOURCES})