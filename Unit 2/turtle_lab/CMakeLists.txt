cmake_minimum_required(VERSION 3.0.0)
project(turtle_lab VERSION 0.1.0)

include(CTest)
enable_testing()

FILE(GLOB TURTLE_LAB_FILES
        "src/*.h"
        "src/*.c"
        "src/**/*.h"
        "src/**/*.c"
)

INCLUDE_DIRECTORIES(turtle_lab PRIVATE "/usr/local/include")
LINK_LIBRARIES("/usr/local/lib/libSDL2.dylib")

MESSAGE("Source files: ${TURTLE_LAB_FILES}")

add_executable(turtle_lab ${TURTLE_LAB_FILES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
