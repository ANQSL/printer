cmake_minimum_required(VERSION 3.10.0)
project(printclinet)
#设置库
set(Qt5_DIR "D:/Qt5.14.2/5.14.2/mingw73_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS core widgets network REQUIRED)
#设置执行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")
#设置头文件路径
include_directories(clinet)
include_directories(data)
include_directories(ui)
#添加子目录
add_subdirectory(data)
add_subdirectory(clinet)
add_subdirectory(ui)

aux_source_directory(. src)
add_executable(printclinet ${src})
target_link_libraries(printclinet ui clinet encodedecode)