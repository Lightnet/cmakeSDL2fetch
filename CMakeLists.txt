cmake_minimum_required(VERSION 3.20) # FetchContent is available in 3.11+

project(sdl2app VERSION 0.0.1)
message("START OF CMAKELIST...")
set(SDL_VERSION release-2.0.14) # SDL GIT RELEASE TAG
set(ENTRYPOINT sdl2window.cpp) # entry point file.cpp

# config IDE ext 
include(CTest)
enable_testing()

message("CMAKE_SYSTEM_NAME == " ${CMAKE_SYSTEM_NAME})

if (CMAKE_SYSTEM_NAME STREQUAL "Windows")
  #target_compile_options(myApp PRIVATE /W4)
  #message("WINDOW")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Linux")
  #target_compile_options(myApp PRIVATE -Wall -Wextra -Wpedantic)
  #message("Linux")
elseif (CMAKE_SYSTEM_NAME STREQUAL "Darwin")
  # other macOS-specific flags for Clang
  #message("Darwin")
endif()

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#set(ENTRYPOINT main.cpp) # variable
#set(ENTRYPOINT sdl2window.cpp) # variable
message("ENTRYPOINT: ${ENTRYPOINT}") # console log

# Set this to the minimal version you want to support
# find_package(SDL2 3.5.0 QUIET) # Requires at least version 2.5.0
# https://www.voyagingmind.com/posts/cmake-and-sdl2/
if (NOT SDL2_FOUND) # If there's none, fetch and build raylib
  include(FetchContent)
  FetchContent_Declare(
    SDL2
    GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
    GIT_TAG ${SDL_VERSION}
  )
  FetchContent_GetProperties(SDL2)
  if (NOT SDL2_POPULATED) # Have we downloaded raylib yet?
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(SDL2)
    #add_library(SDL2 INTERFACE) #nope
    FetchContent_MakeAvailable(SDL2)
    message("SDL2_SOURCE_DIR: " ${SDL2_SOURCE_DIR})
    message("SDL2_BINARY_DIR: " ${SDL2_BINARY_DIR})
    # build SDL2
    add_subdirectory(${SDL2_SOURCE_DIR} ${SDL2_BINARY_DIR})
    #find_library(LIBRARY_SDL SDL2)
    #message("SUB LIBRARY_SDL: " ${LIBRARY_SDL})
  endif()
endif()

#find_library(LIBRARY_SDL SDL2)
#message("LIBRARY_SDL: " ${LIBRARY_SDL})
#if (LIBRARY_SDL)
  #target_link_libraries(myApp PRIVATE ${LIBRARY_SDL})
  #message("LIBRARY_SDL: " ${LIBRARY_SDL})
#else()
  # throw an error or enable compilation without the library
#endif()

add_executable(${PROJECT_NAME} ${ENTRYPOINT})

#target_link_libraries(${PROJECT_NAME} SDL2main SDL2-static)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2main SDL2-static)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_SOURCE_DIRS}/include external/glad/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
message("END OF CMAKELIST...")