FILE(GLOB_RECURSE srcs include/*.h* src/*.c*)
add_library(Vendor OBJECT ${srcs})
target_include_directories(Vendor PUBLIC include)