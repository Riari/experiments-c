cmake_minimum_required(VERSION 3.20)
project("FlecsExperiments")

include(FetchContent)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED YES)
set(CMAKE_CXX_EXTENSIONS NO)

FetchContent_Declare(
    flecs
    GIT_REPOSITORY https://github.com/SanderMertens/flecs
    GIT_TAG v2.4.8
)

FetchContent_MakeAvailable(flecs)

include_directories(src)

add_executable(${PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME}
    flecs
)

if(WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:flecs>
            $<TARGET_FILE_DIR:${PROJECT_NAME}>)
endif()
