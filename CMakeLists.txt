


cmake_minimum_required (VERSION 2.6)

project (testmm32)

set(MY_TARGET testmm32)



# debug build?
set(DEBUG  "1") 
# optimization
set(OPT  "-Og")


ENABLE_LANGUAGE(ASM)


set(CMAKE_SYSTEM Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

if(!CROSS_COMPILER_PATH)
   message(FATAL_ERROR,"please use -CROSS_COMPILER_PATH=xxxx in command line")
endif()

# cross compiler
# set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
#set(CROSS_COMPILER_PATH "/home/niexuzhong/gcc-arm-none-eabi-8-2019-q3-update")

set(CMAKE_C_COMPILER "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-gcc")
MESSAGE(STATUS,"compiler is ${CMAKE_C_COMPILER}")
set(CMAKE_ASM_COMPILER "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-g++")
set(CMAKE_CXX_COMPILER "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-gcc")
set(CMAKE_OBJCOPY "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-objcopy")
set(CMAKE_OBJDUMP "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-objdump" )
set(CMAKE_SIZE "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-size" )
set(CMAKE_NM "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-nm" )
set(CMAKE_DEBUGER "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-gdb")
set(CMAKE_CPPFILT "${CROSS_COMPILER_PATH}/bin/arm-none-eabi-c++filt" )
set(CMAKE_FIND_ROOT_PATH "${CROSS_COMPILER_PATH}")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)







# set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

message("++++++++++++++Start Build+++++++++++++++++")

# header folder
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/CMSIS)
include_directories(${PROJECT_SOURCE_DIR}/include/HALINCLUDE)




# source file
aux_source_directory(${PROJECT_SOURCE_DIR}/src USRSRC)
aux_source_directory(${PROJECT_SOURCE_DIR}/mm32f003 HALSRC)
# the hal source is same for kinds of m32f00 for cortex-m0 machine


# cpu
set(CPU  "-mcpu=cortex-m0")
# fpu
#set(FPU  "-mfpu=fpv4-sp-d16")
# float-abi
#set(FLOAT-ABI  "-mfloat-abi=hard")
# mcu
set(MCU  "${CPU} -mthumb")
set(DEPFLAGS "-MMD -MP")
if(MCU_TYPE STREQUAL "MM32F003")
     add_compile_definitions(MM32F003_q)
elseif(MCU_TYPE STREQUAL "MM32F031")
     add_compile_definitions(MM32F031_q)
else()
     message(FATAL_ERROR,"please use -DMCU_TYPE=xxxx in command line")
endif()

add_compile_definitions(USE_STDPERIPH_DRIVER)
set(CMAKE_C_FLAGS "${MCU} -fno-builtin ${OPT}  -Wall -O0 -g3 -std=gnu99 -fdata-sections -ffunction-sections ${DEPFLAGS}")
set(CMAKE_CXX_FLAGS "${MCU} -fno-builtin ${OPT} -Wall -O0 -g3 -std=c++11 -fdata-sections -ffunction-sections ${DEPFLAGS}")
#set(CMAKE_ASM_FLAGS "-x assembler-with-cpp ${MCU}")


set(CMAKE_ASM_FLAGS "${MCU} -x assembler")



set(CMAKE_SHARED_LIBRARY_LINK_C_FLAGS "")
set(CMAKE_SHARED_LIBRARY_LINK_CXX_FLAGS "")



set(LIBS "-lc -lm -lnosys" )


if(MCU_TYPE STREQUAL "MM32F003")
   set(LDSCRIPT "${PROJECT_SOURCE_DIR}/mm32f003.ld")       
elseif(MCU_TYPE STREQUAL "MM32F031")
   set(LDSCRIPT "${PROJECT_SOURCE_DIR}/mm32f031.ld")
else()
      message(FATAL_ERROR,"please select mcu type")
endif()



set(CMAKE_EXE_LINKER_FLAGS "${MCU} -specs=nano.specs -specs=nosys.specs -T${LDSCRIPT} -Wl,-Map=${PROJECT_BINARY_DIR}/${MY_TARGET}.map,--cref -Wl,--gc-sections")


if(MCU_TYPE STREQUAL "MM32F003")
    add_executable(${MY_TARGET}.elf ${USRSRC} ${HALSRC}
       ${PROJECT_SOURCE_DIR}/device/startup_mm32f003.s 
       ${PROJECT_SOURCE_DIR}/device/system_MM32F003_q.c)
elseif(MCU_TYPE STREQUAL "MM32F031")
     add_executable(${MY_TARGET}.elf ${USRSRC} ${HALSRC}
        ${PROJECT_SOURCE_DIR}/device/startup_mm32f031x4x6_q.s 
        ${PROJECT_SOURCE_DIR}/device/system_MM32F031x4x6_q.c)
else()
      message(FATAL_ERROR,"please select mcu type")
endif()





target_link_libraries(${MY_TARGET}.elf ${LIBS})
set_target_properties(${MY_TARGET}.elf PROPERTIES LINK_DEPENDS ${LDSCRIPT})

add_custom_command(
    TARGET  ${MY_TARGET}.elf   
    COMMAND ${CMAKE_OBJCOPY} -O ihex ${MY_TARGET}.elf ${MY_TARGET}.hex)
add_custom_command(
    TARGET  ${MY_TARGET}.elf
    POST_BUILD COMMAND ${CMAKE_OBJCOPY} -O binary ${MY_TARGET}.elf ${MY_TARGET}.bin)


add_custom_command(OUTPUT ${PROJECT_NAME}.lst
    DEPENDS ${PROJECT_NAME}
    COMMAND ${CMAKE_OBJDUMP} -S ${PROJECT_NAME} > ${PROJECT_NAME}.lst)

add_custom_command(
    TARGET  ${MY_TARGET}.elf
    POST_BUILD COMMAND ${CMAKE_SIZE}  ${MY_TARGET}.elf )

    add_custom_command(
        TARGET  ${MY_TARGET}.elf
        POST_BUILD COMMAND ${CMAKE_OBJDUMP} -S -l ${PROJECT_NAME}.elf  > ${PROJECT_NAME}.lst )    