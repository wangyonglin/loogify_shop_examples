cmake_minimum_required(VERSION 3.0.0)

# See docs/release_checklist.md
set(MAJOR_VERSION 0)
set(MINOR_VERSION 1)
set(MICRO_VERSION 0)

project(
    loongify
    LANGUAGES C CXX
    VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${MICRO_VERSION}"
)
# project(loongify VERSION 0.1.0 LANGUAGES C CXX)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()




add_subdirectory(modules)
add_subdirectory(tests)
add_subdirectory(examples)