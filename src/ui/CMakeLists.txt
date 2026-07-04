add_library(dawn_ui STATIC)
add_library(dawn::ui ALIAS dawn_ui)

target_include_directories(dawn_ui PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../src
        ${CMAKE_CURRENT_SOURCE_DIR}/../../resources
        ${CMAKE_BINARY_DIR}/generated
)

target_sources(dawn_ui PRIVATE
        dawn_window.h
        dawn_window.cpp
)

add_subdirectory(
        components
        controls
)

target_link_libraries(dawn_ui PRIVATE juce::juce_gui_basics)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(dawn_ui PRIVATE -Wno-c23-extensions)
endif()
