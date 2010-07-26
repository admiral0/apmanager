project(apmanager)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})

set(apmanager_SRCS apmanager.cpp main.cpp)
qt4_automoc(${apmanager_SRCS})
add_executable(apmanager ${apmanager_SRCS})
target_link_libraries(apmanager ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
