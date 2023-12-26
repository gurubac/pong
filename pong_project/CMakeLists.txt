cmake_minimum_required(VERSION 3.25)
project(pong)
set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES "src/*.cpp")

# add folders in resources to the build directory
file(COPY src/resources DESTINATION ${CMAKE_BINARY_DIR})

# add the executable from sources
add_executable(${PROJECT_NAME} ${SOURCES})

# find and link SDL2 using built in cmake modules (error with the specialized one)
find_package(SDL2 REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_LIBRARIES})

# apply special module path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake/sdl2)

# Find and link SDL2_ttf using the specialized modules
find_package(SDL2_ttf REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_TTF_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_TTF_LIBRARIES})

# Find and link SDL2_mixer using the specialized modules
find_package(SDL2_mixer REQUIRED)
target_include_directories(${PROJECT_NAME} PRIVATE ${SDL2_MIXER_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} ${SDL2_MIXER_LIBRARIES})