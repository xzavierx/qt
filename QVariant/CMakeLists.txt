cmake_minimum_required(VERSION 3.14)

project(QVariant LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core Gui)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS LinguistTools)

qt_add_translations(QVariant TS_FILES zh_CN.ts)
install(FILES ${qm_files} DESTINATION ${INSTALL_EXAMPLEDIR)

add_executable(QVariant
  main.cpp
)
target_link_libraries(QVariant Qt${QT_VERSION_MAJOR}::Core Qt${QT_VERSION_MAJOR}::Gui)

include(GNUInstallDirs)
install(TARGETS QVariant
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
