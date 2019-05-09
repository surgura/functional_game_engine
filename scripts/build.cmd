ECHO OFF
CLS
IF NOT EXIST "build" mkdir build
cd build
cmake -G "Visual Studio 15 2017 Win64" -D "BULLET_ROOT=C:/bullet3-2.87" -D "SFML_ROOT=C:/SFML-2.4.1" -D "CMAKE_BUILD_TYPE=Debug" ..
cmake --build .