project(Vendor LANGUAGES C CXX)
FILE(GLOB_RECURSE srcs include/*.h* src/*.c*)
add_library(${PROJECT_NAME} OBJECT ${srcs})
target_include_directories(${PROJECT_NAME} PUBLIC include)