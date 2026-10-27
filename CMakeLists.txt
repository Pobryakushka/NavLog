cmake_minimum_required(VERSION 3.16)

project(NavLog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(NavLog main.cpp
    point.h
    haversinus.h haversinus.cpp
    pathdistance.h pathdistance.cpp
    point.cpp)

include(GNUInstallDirs)
install(TARGETS NavLog
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
