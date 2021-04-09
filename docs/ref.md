https://github.com/pvallet/gourdin/blob/master/CMakeLists.txt
https://internalpointers.com/post/modern-cmake-beginner-introduction
https://alandefreitas.github.io/moderncpp/utilities/networking/build-script/
https://dev.to/noah11012/using-sdl2-opening-a-window-79c
https://lazyfoo.net/tutorials/SDL/01_hello_SDL/index2.php









https://www.voyagingmind.com/posts/cmake-and-sdl2/
```
# cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -GNinja ..

cmake_minimum_required(VERSION 3.13 FATAL_ERROR)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)


# Pulling down SDL2
include(FetchContent)

FetchContent_Declare(
        SDL2
        GIT_REPOSITORY "https://github.com/SDL-mirror/SDL.git"
        GIT_TAG release-2.0.10
)

FetchContent_GetProperties(SDL2)
if (NOT sdl2_POPULATED)
    FetchContent_Populate(SDL2)
    add_subdirectory(${sdl2_SOURCE_DIR} ${sdl2_BINARY_DIR})
endif ()

project(game1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

#
#  Pong
#
add_executable(pong
        src/main.c
        src/input.c
        src/rand.c
        src/gfx.c
        src/text.c
        src/texture.c
        src/time.c
        src/base/arena.c
        src/base/hash_table.c
        src/base/implementations.c
        )

target_link_libraries(pong SDL2main SDL2-static m)
target_compile_options(pong PRIVATE -Wall -Wextra)
# TODO eventually remove this
target_include_directories(pong PRIVATE ${sdl2_SOURCE_DIRS}/include external/glad/include)
```












