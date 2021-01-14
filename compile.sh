#!/bin/bash
rm build -rf
mkdir build
cd build
cmake -DMCU_TYPE=MM32F031 -D CROSS_COMPILER_PATH=/home/niexuzhong/gcc-arm-none-eabi-8-2019-q3-update ..
make
