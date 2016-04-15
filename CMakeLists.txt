cmake_minimum_required(VERSION 2.8)

# Project name without spaces or special characters
project("fumaroos")

# set env vars
set(ENV{CPP3DS} "/opt/devkitpro/cpp3ds")
set(ENV{DEVKITPRO} "/opt/devkitpro/")
set(ENV{DEVKITARM} "/opt/devkitpro/devkitARM")

set(APP_TITLE "Fumaroos")
set(APP_DESCRIPTION "A pet raising simulation game")
set(APP_AUTHOR "krruzic")
set(APP_ICON ${PROJECT_SOURCE_DIR}/res/app/icon.png)

# CIA settings
set(APP_UNIQUE_ID 0xfeece) # This must be unique for your CIA project
set(APP_PRODUCT_CODE ${PROJECT_NAME})
set(BANNER_IMAGE ${PROJECT_SOURCE_DIR}/res/app/banner.png)
set(BANNER_SOUND ${PROJECT_SOURCE_DIR}/res/app/banner.wav)
set(CIA_CONFIG ${PROJECT_SOURCE_DIR}/res/app/cia.rsf)

# Include cpp3ds cmake module
set(CPP3DS $ENV{CPP3DS})
if(NOT CPP3DS)
    message(FATAL_ERROR "You need to set the env variable CPP3DS before compiling.")
endif()
set(CMAKE_MODULE_PATH "${CPP3DS}/cmake" ${CMAKE_MODULE_PATH})
include(cpp3ds)

# Use either nihstro or picasso for your shader scripts
set(SHADER_AS nihstro)

include_directories(
        ${PROJECT_SOURCE_DIR}/external/tween-engine/include
)
# Variables used by template: SOURCE_FILES & SHADER_FILES
FILE(GLOB_RECURSE TWEEN_ENGINE_SOURCE ${PROJECT_SOURCE_DIR}/external/tween-engine/src/*.cpp)
set(SOURCE_FILES
        ${TWEEN_ENGINE_SOURCE}
        ${PROJECT_SOURCE_DIR}/src/TweenTransformable.cpp
        ${PROJECT_SOURCE_DIR}/src/main.cpp
        ${PROJECT_SOURCE_DIR}/src/Fumaroos.cpp
        ${PROJECT_SOURCE_DIR}/src/TextureManager.cpp
        ${PROJECT_SOURCE_DIR}/src/Pet.cpp
        ${PROJECT_SOURCE_DIR}/src/Animation.cpp
        ${PROJECT_SOURCE_DIR}/src/AnimatedSprite.cpp
        ${PROJECT_SOURCE_DIR}/src/States/State.cpp
        ${PROJECT_SOURCE_DIR}/src/States/StateStack.cpp
        ${PROJECT_SOURCE_DIR}/src/States/TitleState.cpp
        ${PROJECT_SOURCE_DIR}/src/States/CreatePet.cpp
        ${PROJECT_SOURCE_DIR}/src/Keyboard/Keyboard.cpp
        ${PROJECT_SOURCE_DIR}/src/Keyboard/tinyxml2.cpp
        ${PROJECT_SOURCE_DIR}/src/GUI/NineSliceButton.cpp
        ${PROJECT_SOURCE_DIR}/src/GUI/NinePatch.cpp
        ${PROJECT_SOURCE_DIR}/src/GUI/Button.cpp
        )
FILE(GLOB_RECURSE SHADER_FILES ${PROJECT_SOURCE_DIR}/res/romfs/shaders/[^.]*.vsh)

##################################################
# Don't usually need to change anything below
##################################################
set(CPP3DS_ARM_FLAGS "-g -O2 -fno-rtti -fno-exceptions -march=armv6k -mtune=mpcore -mfloat-abi=hard -mtp=soft -std=c++11")
set(CPP3DS_EMU_FLAGS "-g -O0")

set(CPP3DS_ARM_LIBS cpp3ds-window cpp3ds-graphics cpp3ds-audio cpp3ds-network cpp3ds-system citro3d mbedtls mbedx509 mbedcrypto ctru freetype png z vorbisenc vorbisfile vorbis ogg bz2)
set(CPP3DS_EMU_LIBS cpp3ds-emu sfml-graphics sfml-window sfml-system sfml-network sfml-audio openal GLEW GL jpeg freetype vorbisenc vorbisfile vorbis ogg mbedtls mbedx509 mbedcrypto pthread Qt5Widgets)

add_subdirectory(${CPP3DS}/cmake/template_arm build/arm)
add_subdirectory(${CPP3DS}/cmake/template_emu build/emu)
