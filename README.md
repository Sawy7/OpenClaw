# OpenClaw - Captain Claw (1997) reimplementation

 - This project is a multiplatform C++ reimplementation of original Captain Claw (1997) platformer game
 - Whole codebase was written from scratch
 - Game uses assets from original game archive (CLAW.REZ)

**Level 1 youtube playthrough:**

[![OpenClaw - Level 1](https://img.youtube.com/vi/ikXQNV_aw68/0.jpg)](https://www.youtube.com/watch?v=ikXQNV_aw68)

# Build status

### Windows:

[![Build Status](https://ci.appveyor.com/api/projects/status/github/pjasicek/OpenClaw?svg=true)](https://ci.appveyor.com/project/pjasicek/captainclaw)

### Linux (debian):

[![Build Status](https://travis-ci.org/pjasicek/OpenClaw.svg?branch=master)](https://travis-ci.org/pjasicek/OpenClaw)

### Static analysis / Code coverage:

[![Static analysis](https://scan.coverity.com/projects/12422/badge.svg?flat=1)](https://scan.coverity.com/projects/pjasicek-captainclaw)

# Tech

  - SDL2 Libraries (SDL2, SDL_Image, SDL_TTF, SDL_Mixer, SDL2_Gfx) for graphics, input, font and audio
  - Box2D Library for Physics
  - Tinyxml library for data-driven approach

# Building and running
For all platforms you will need original CLAW.REZ game archive from original game
### Windows
  - Project contains VS2017 solution with all libraries and include directories preset
  - Box2D is generated by CMake and it hardcodes the file paths. If you want to compile it on your own, you must run CMake on the CMakeLists.txt in the Box2D root directory
  - Do not try to use different versions of SDL libraries than the ones which are already included in the Build_Release folder

### Linux
  **Prerequisites for Ubuntu 16.04 (should be almost identical for Fedora/CentOS/*):**
  
  `sudo apt install libsdl2-dev  libsdl2-image-dev libsdl2-mixer-dev libsdl2-ttf-dev libsdl2-gfx-dev libtinyxml-dev` 
  
  **Compilation:**
  - `git clone https://github.com/pjasicek/OpenClaw.git`
  - `cd OpenClaw/Build_Release`
  - CLAW.REZ iz required from original game in the OpenClaw/Build_Release folder
  - `make` (it's going to use all threads to compile, edit Makefile in Build_Release folder to whatever number of simultaneous threads you want it on your machine to run)

 **Remarks:**

  - For hearing background music play, you need to install **timidity (or timidity++)** and **freepats**. Some linux distributions come with it by default, some do not (fedora, archlinux)
  - Dooes not work with SDL 2.0.6 - if you have the latest one from repository, you should be fine
  
### Android
  
  - Compilation / Deployment steps will be updated in near future, game itself is successfully running on Android
 
# In-game images
  -  **TODO** - add screenshots

# Claw Launcher

  - Precompiled for Windows natively and for Linux use thorugh Mono runtime
  - Locates Claw binary and corresponding config.xml file
  - Provides GUI to modify configuration (Video/Audio/Assets)

### For Linux

  **Prerequisites for Ubuntu 16.04 (should be almost identical for Fedora/CentOS/*):**
  
  `sudo apt install mono-runtime libmono-system4.0-cil libmono-system-windows-forms4.0-cil` 
  
  **Then run it like this:**
  
  `~/OpenClaw/Build_Release$ mono ClawLauncher.exe`
 
-  **TODO** - add screenshots
