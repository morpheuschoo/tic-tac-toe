cmake_minimum_required(VERSION 3.26)

project(TIC-TAC-TOE)

set(CMAKE_CXX_STANDARD 20)

add_executable(
    ${PROJECT_NAME}
    headers/fpscounter.hpp
    headers/board.hpp
    headers/player.hpp
    headers/text.hpp
    headers/drawing.hpp
    headers/bot.hpp
    headers/menu.hpp
    headers/game.hpp
    src/main.cpp
    src/fpscounter.cpp
    src/board.cpp
    src/player.cpp
    src/text.cpp
    src/drawing.cpp
    src/bot.cpp
    src/menu.cpp
    src/game.cpp
)

include_directories(headers C:/SFML/include)

set(SFML_ROOT C:/SFML)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics audio)
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif()

file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

if(WIN32)
    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    file(GLOB MINGW_DEP_DLLS "C:/mingw64/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif()