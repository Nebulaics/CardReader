
cmake_minimum_required(VERSION 3.21.1)

option(LINK_INSIGHT "Link Qt Insight Tracker library" ON)
option(BUILD_QDS_COMPONENTS "Build design studio components" ON)

project(CardReaderApp LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}" "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)
set(QML_IMPORT_PATH ${QT_QML_OUTPUT_DIRECTORY}
    CACHE STRING "Import paths for Qt Creator's code model"
    FORCE
)

find_package(Qt6 6.4.2 REQUIRED COMPONENTS Core Gui Widgets Qml Quick QuickTimeline ShaderTools Sql)
qt_standard_project_setup(REQUIRES 6.4.2)

add_library(core STATIC
    ${CMAKE_CURRENT_LIST_DIR}/include/CardParser.h
    ${CMAKE_CURRENT_LIST_DIR}/include/BankDatabase.h

    ${CMAKE_CURRENT_LIST_DIR}/src/CardParser.cpp
    ${CMAKE_CURRENT_LIST_DIR}/src/BankDatabase.cpp
)

target_link_libraries(core PUBLIC Qt6::Core Qt6::Concurrent)


qt_add_executable(${CMAKE_PROJECT_NAME} App/main.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE core Qt6::Sql)

target_include_directories(core
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)
include_directories(${CMAKE_CURRENT_LIST_DIR}/src)

qt_add_resources(${CMAKE_PROJECT_NAME} "configuration"
    PREFIX "/"
    FILES
        qtquickcontrols2.conf)

include(qds)

if (BUILD_QDS_COMPONENTS)
    include(qmlcomponents OPTIONAL)
endif()

if (LINK_INSIGHT)
    include(insight OPTIONAL)
endif ()

include(GNUInstallDirs)
install(TARGETS ${CMAKE_PROJECT_NAME}
  BUNDLE DESTINATION .
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
