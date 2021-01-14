# MM32 project with GNU ARM compiler
  1.the startup assemble file is based on CMSIS_5

  2.the system file is provided by mindmotion

  3.the link script is based on CMSIS_5 too
  ## usage
    It is very simple,just install gnu arm compiler and cmake

    in the project directory,input following command:
    
    mkdir build && cd build

    cmake ..

    make

    then the elf ,hex,bin file can be generated together.

 ## debug
    use jlink and gdb to debug it. the directory of script are scripts to use gdb 
    1.modify JlinkDevices.xml to add support for F003.
    2.create MindMotion directory in Devices directory.add MM32F003 directory in MindMotion directory. 
    3.copy the MM32F003_16.FLM from keil support pack for mm32F003 to the MM32F003 directory

  ## porting for other cortexM0,cortexM3 
    1.modify statupxxx.s and xxx.ld. you can take the file in CMSIS as template. mianly the IRQname and flash,ram size etc
    2.replace the C library with your own MCU
    3.add the file in your projects in CMakeLists.txt.
    4.modify the MCU option in CMakeLists.txt
    5.use Jlink to burn the flash
## add support for MM32F031 and compile script
    modify the compile.sh as your requirment.There are two parameter shoudl be modified: MCU_TYPE and cross compile path .then run it