cmake_minimum_required(VERSION 3.16)

project("DeliriumStudioV" VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS Widgets Gui Core Qml Quick REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_BINARY_DIR})

set (SOURCES mainwindow.h mainwindow.cpp resourceloader.h resourceloader.cpp views/arrangement.h views/arrangement.cpp components/toolbar.h components/toolbar.cpp api.h)

link_libraries(Qt6::Widgets Qt6::Core Qt6::Gui Qt6::Qml Qt6::Quick)

qt6_add_resources(RES res.qrc)

add_library(libgui SHARED ${SOURCES} ${RES})

add_library(libgui_s STATIC ${SOURCES} ${RES})
set_target_properties(libgui_s PROPERTIES OUTPUT_NAME libgui)

if (${PLATFORM} MATCHES "win")
target_compile_definitions(libgui PRIVATE WIN_EXPORT)
endif()