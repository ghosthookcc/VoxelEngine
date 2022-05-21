cmake_minimum_required (VERSION 3.1.0)
project (Build LANGUAGES C)

set(CMAKE_SYSTEM_NAME WindowsStore)
set(CMAKE_SYSTEM_VERSION 10.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options("/Z7")
add_link_options("/DEFAULTLIB:ws2_32.lib")
add_link_options("/DEFAULTLIB:Bcrypt.lib")
add_link_options("/DEFAULTLIB:userenv.lib")

file(GLOB_RECURSE SOURCE_FILES
    ${CMAKE_SOURCE_DIR}/src/*.c
    ${CMAKE_SOURCE_DIR}/Render/*.c
    ${CMAKE_SOURCE_DIR}/Render/components/*.c
    ${CMAKE_SOURCE_DIR}/Render/components/static/*.c
    ${CMAKE_SOURCE_DIR}/Render/ComponentManagers/*.c
    ${CMAKE_SOURCE_DIR}/GH/*.c
    ${CMAKE_SOURCE_DIR}/GHEnvironment/*.c)

file(GLOB_RECURSE HEADER_FILES
    ${CMAKE_SOURCE_DIR}/src/*.h
    ${CMAKE_SOURCE_DIR}/Render/*.h
    ${CMAKE_SOURCE_DIR}/Render/components/*.h
    ${CMAKE_SOURCE_DIR}/Render/components/static/*.h
    ${CMAKE_SOURCE_DIR}/Render/ComponentManagers/*.h
    ${CMAKE_SOURCE_DIR}/GH/*.h
    ${CMAKE_SOURCE_DIR}/GHEnvironment/*.h

    ${CMAKE_SOURCE_DIR}/Header Files/*.h
    ${CMAKE_SOURCE_DIR}/Resource Files/*.h)

include_directories(
    "${CMAKE_SOURCE_DIR}"
    "${CMAKE_SOURCE_DIR}/src"
    "${CMAKE_SOURCE_DIR}/Dependencies/includes"
    "${CMAKE_SOURCE_DIR}/Resource Files"
    "${CMAKE_SOURCE_DIR}/Header Files"
    "${CMAKE_SOURCE_DIR}/Render"
    "${CMAKE_SOURCE_DIR}/Render/components"
    "${CMAKE_SOURCE_DIR}/Render/components/static"
    "${CMAKE_SOURCE_DIR}/Render/ComponentManagers"
    "${CMAKE_SOURCE_DIR}/GH"
    "${CMAKE_SOURCE_DIR}/GHEnvironment"
)
configure_file(src/helpers/RootDir.h.in src/helpers/RootDir.h)
link_directories(${CMAKE_SOURCE_DIR}/Dependencies/libs LIBS)

find_package(OpenGL REQUIRED)

include(GenerateExportHeader)

set(DLLS_PATH ${CMAKE_SOURCE_DIR}/Dependencies/dlls)

file(COPY parse_json.lib DESTINATION ${CMAKE_SOURCE_DIR}/Debug/)
file(COPY Sol_2_body.json DESTINATION ${CMAKE_SOURCE_DIR}/Debug/)
file(COPY Sol_6_body.json DESTINATION ${CMAKE_SOURCE_DIR}/Debug/)
file(COPY Sol_Full.json DESTINATION ${CMAKE_SOURCE_DIR}/Debug/)

file(GLOB EXTERNALDLLS
    ${CMAKE_SOURCE_DIR}/GHEnvironment/GH_*.c
    ${CMAKE_SOURCE_DIR}/GHEnvironment/GH_.*h)

add_library(modules SHARED ${CMAKE_SOURCE_DIR}/GHEnvironment/GH_TestFile.c
                           ${CMAKE_SOURCE_DIR}/GHEnvironment/GH_TestFile.h)

add_library(parse_json parse_json.lib)
set_target_properties(parse_json PROPERTIES LINKER_LANGUAGE C)

set(LIBS opengl32 parse_json)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} PRIVATE ${LIBS})
