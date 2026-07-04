add_library(dawn_core STATIC)
add_library(dawn::core ALIAS dawn_core)

target_include_directories(dawn_core PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/../../src
        ${CMAKE_CURRENT_SOURCE_DIR}/../../resources
        ${CMAKE_BINARY_DIR}/generated
)

target_sources(dawn_core PRIVATE
        logger.h

        resource/resource_cache.h

        resource/resource_loader.h

        resource/resource_manager.h
        resource/resource_manager.cpp
)

target_link_libraries(dawn_core PRIVATE juce::juce_graphics juce::juce_core)

if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(dawn_core PRIVATE -Wno-c23-extensions)
endif()