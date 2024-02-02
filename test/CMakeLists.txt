cmake_minimum_required(VERSION 3.5)
project(TestForQtComponent LANGUAGES CXX)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ROOT_DIR ${CMAKE_CURRENT_LIST_DIR}/..)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets Core5Compat)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Widgets Core5Compat REQUIRED) # Qt COMPONENTS

aux_source_directory(${ROOT_DIR}/test srcs)

# Specify MSVC UTF-8 encoding   
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

add_executable(${PROJECT_NAME}
    # WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs}
)

add_subdirectory(${ROOT_DIR}/component component_dir)

target_include_directories(${PROJECT_NAME} PRIVATE ${ROOT_DIR}/component)
target_link_libraries(${PROJECT_NAME} PRIVATE Qt${QT_VERSION_MAJOR}::Widgets Qt${QT_VERSION_MAJOR}::Core5Compat) # Qt5 Shared Library
target_link_libraries(${PROJECT_NAME} PRIVATE Component)