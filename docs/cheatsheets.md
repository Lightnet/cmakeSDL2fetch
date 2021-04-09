

```cmake
add_executable(random random.cpp)

FetchContent_Declare(pcg-cpp GIT_REPOSITORY https://github.com/imneme/pcg-cpp.git GIT_TAG v0.98.1)
FetchContent_GetProperties(pcg-cpp)
if (NOT pcg-cpp_POPULATED)
    FetchContent_Populate(pcg-cpp)
    add_library(pcg-cpp INTERFACE)
    target_include_directories(pcg-cpp INTERFACE ${pcg-cpp_SOURCE_DIR}/include)
endif ()
add_executable(pcg pcg.cpp)
target_link_libraries(pcg pcg-cpp)

```






```cmake
#######################################################
### External Libraries                              ###
#######################################################
FetchContent_Declare(asio GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git GIT_TAG asio-1-18-1)
FetchContent_GetProperties(asio)
if (NOT asio_POPULATED)
    FetchContent_Populate(asio)
    add_library(asio INTERFACE)
    target_include_directories(asio INTERFACE ${asio_SOURCE_DIR}/asio/include)
    target_compile_definitions(asio INTERFACE ASIO_STANDALONE ASIO_NO_DEPRECATED)
    target_link_libraries(asio INTERFACE Threads::Threads)
endif ()

#######################################################
### Networking                                      ###
#######################################################
add_executable(network network.cpp)
target_link_libraries(network asio)

add_executable(network_async network_async.cpp)
target_link_libraries(network_async asio)

add_subdirectory(server)
```