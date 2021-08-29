#!/bin/sh

cd Resumake/
qmake Resumake.pro
make clean
make
./Resumake