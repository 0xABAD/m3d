@echo off
setlocal enableextensions

set CXXFLAGS=-O2 -nologo -MT -Zi -FC -Oi -GR- -Gm- -EHsc ^
    -DM3D_DEFINE_MAIN ^
    -W4 -wd4201 -wd4189

if not exist %CD%\build (mkdir %CD%\build)
pushd %CD%\build

cl %CXXFLAGS% ../test_bench.cpp -Fe:m3d.exe -link -SUBSYSTEM:CONSOLE

if exist m3d.exe (cmd /C m3d.exe)

popd
