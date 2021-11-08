cmake_minimum_required (VERSION 3.1.0)
project (Build)

file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/Render/*.c
    ${CMAKE_SOURCE_DIR}/Render/components/*.c
    ${CMAKE_SOURCE_DIR}/Render/components/static/*.c
    ${CMAKE_SOURCE_DIR}/Render/ComponentManagers/*.c
    ${CMAKE_SOURCE_DIR}/GH/*.c)

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOURCE_DIR}/Header Files/*.h
    ${CMAKE_SOURCE_DIR}/Render/*.h
    ${CMAKE_SOURCE_DIR}/Render/components/*.h
    ${CMAKE_SOURCE_DIR}/Render/components/static/*.h
    ${CMAKE_SOURCE_DIR}/Render/ComponentManagers/*.h
    ${CMAKE_SOURCE_DIR}/Resource Files/*.h
    ${CMAKE_SOURCE_DIR}/GH/*.h)

link_directories(${CMAKE_SOURCE_DIR}/Dependencies/libs)

include_directories(
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/Dependencies/includes"
    "${CMAKE_SOURCE_DIR}/Resource Files"
    "${CMAKE_SOURCE_DIR}/Header Files"
    "${CMAKE_SOURCE_DIR}/Render"
    "${CMAKE_SOURCE_DIR}/Render/components"
    "${CMAKE_SOURCE_DIR}/Render/components/static"
    "${CMAKE_SOURCE_DIR}/Render/ComponentManagers"
    "${CMAKE_SOURCE_DIR}/GH"
)
configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)

find_package(OpenGL REQUIRED)

set(LIBS opengl32)

ADD_EXECUTABLE(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} ${LIBS})
