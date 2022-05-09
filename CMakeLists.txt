cmake_minimum_required(VERSION 3.23.1 FATAL_ERROR)

project("Game Idea Generator")

set(CMAKE_CXX_STANDARD 11)

set(GENERATOR_SOURCE

${CMAKE_CURRENT_LIST_DIR}/src/GetCreature.h
${CMAKE_CURRENT_LIST_DIR}/src/GetCreature.cpp
${CMAKE_CURRENT_LIST_DIR}/src/GetEmotion.h
${CMAKE_CURRENT_LIST_DIR}/src/GetEmotion.cpp
${CMAKE_CURRENT_LIST_DIR}/src/GetGenre.h
${CMAKE_CURRENT_LIST_DIR}/src/GetGenre.cpp
${CMAKE_CURRENT_LIST_DIR}/src/GetName.h
${CMAKE_CURRENT_LIST_DIR}/src/GetName.cpp
${CMAKE_CURRENT_LIST_DIR}/src/GetPersonalityTrait.h
${CMAKE_CURRENT_LIST_DIR}/src/GetPersonalityTrait.cpp
${CMAKE_CURRENT_LIST_DIR}/src/GetViewType.h
${CMAKE_CURRENT_LIST_DIR}/src/GetViewType.cpp
)

add_library(generator STATIC ${GENERATOR_SOURCE})

set(PROGRAM_SOURCE ${CMAKE_CURRENT_LIST_DIR}/src/Generator.cpp)

add_executable(program ${PROGRAM_SOURCE})

target_link_libraries(program generator)