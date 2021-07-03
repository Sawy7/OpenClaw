cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
  if(DEFINED ENV{VITASDK})
    set(CMAKE_TOOLCHAIN_FILE "$ENV{VITASDK}/share/vita.toolchain.cmake" CACHE PATH "toolchain file")
  else()
    message(FATAL_ERROR "Please define VITASDK to point to your SDK path!")
  endif()
endif()

# Build options
option(Extern_Config "Do not embed config file" ON)

set(VITA_APP_NAME "openclaw")
set(VITA_TITLEID  "SAWY00007")
set(VITA_VERSION  "01.00")

project(openclaw)
include("${VITASDK}/share/vita.cmake" REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -g -std=gnu++11")

# CMake compiled directories with dependencies
add_subdirectory(Box2D)
add_subdirectory(libwap)
add_subdirectory(./ThirdParty/Tinyxml)

# Directories with headers
include_directories(./Box2D/)
include_directories(./libwap/)
include_directories(./ThirdParty/)
include_directories(./ThirdParty/Tinyxml/)

# Directories with libs
link_directories(./libwap)
link_directories(./Box2D)

# set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../Build_Release)
# set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ../android/libs/armeabi-v7a)

# Cmake target definitions
add_executable(openclaw "")

add_subdirectory(OpenClaw)

target_link_libraries(openclaw
    libwap
    tinyxml
    Box2D
    avformat
    vorbisfile
    vorbis
    ogg
    FLAC
    png
    z
    jpeg
    mikmod
    freetype
    SDL2_mixer
    SDL2_ttf
    SDL2_image
    SDL2_gfx
    SDL2
    stdc++
    m
    SceAppMgr_stub
    SceAppUtil_stub
    SceAudio_stub
    SceCommonDialog_stub
    SceCtrl_stub
    SceDisplay_stub
    SceGxm_stub
    SceHid_stub
    SceShaccCg_stub
    SceSysmodule_stub
    SceMotion_stub
    SceTouch_stub
    mpg123
    webp
    pthread
)

vita_create_self(${PROJECT_NAME}.self ${PROJECT_NAME})
vita_create_vpk(${PROJECT_NAME}.vpk ${VITA_TITLEID} ${PROJECT_NAME}.self
  VERSION ${VITA_VERSION}
  NAME ${VITA_APP_NAME}
  FILE sce_sys/icon0.png sce_sys/icon0.png
  FILE sce_sys/livearea/contents/bg.png sce_sys/livearea/contents/bg.png
  FILE sce_sys/livearea/contents/startup.png sce_sys/livearea/contents/startup.png
  FILE sce_sys/livearea/contents/template.xml sce_sys/livearea/contents/template.xml
)