project(apmanager)
cmake_minimum_required(VERSION 2.6)
find_package(Qt4 REQUIRED)

include_directories(${QT_INCLUDES} ${CMAKE_CURRENT_BINARY_DIR})
set(apmanager_SRCS apwizard.cpp apmanager.cpp main.cpp)
set(apmanager_MOCS apmanager.h apwizard.h)
qt4_wrap_cpp(MOCS ${apmanager_MOCS})
set(apmanager_UIS main.ui wizard.ui)
qt4_wrap_ui(UIS ${apmanager_UIS})
if(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
  add_definitions( -DDEBUG )
endif(${CMAKE_BUILD_TYPE} STREQUAL "Debug")
configure_file (
  "${apmanager_SOURCE_DIR}/config.h.in"
  "${apmanager_BINARY_DIR}/config.h"
  )
add_executable(apmanager ${apmanager_SRCS} ${UIS} ${MOCS})
target_link_libraries(apmanager ${QT_QTCORE_LIBRARY} ${QT_QTGUI_LIBRARY})
