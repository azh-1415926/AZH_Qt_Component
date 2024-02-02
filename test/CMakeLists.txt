project(TestForQtComponent LANGUAGES CXX)

aux_source_directory(./src srcs)

add_executable(${PROJECT_NAME}
    # WIN32 # If you need a terminal for debug, please comment this statement 
    ${srcs}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets 
    Qt${QT_VERSION_MAJOR}::Core5Compat
    Qt${QT_VERSION_MAJOR}::AxContainer
    AZH_QT_Component
) # Qt5 Shared Library