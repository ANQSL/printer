cmake_minimum_required(VERSION 3.10.0)
project(printer VERSION 1.1.0)
#使能qt的moc,ui,rcc功能
set(CMAKE_AUTOMOC NO)
set(CMAKE_AUTORCC NO)
set(CMAKE_AUTOUIC NO)
#设置Qt5_DIR的路径
set(Qt5_DIR "D:/Qt5.14.2/5.14.2/mingw73_64/lib/cmake/Qt5")
find_package(Qt5 COMPONENTS Core network printsupport REQUIRED)
#设置运行文件输出路径
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "bin")

add_subdirectory(data)
add_subdirectory(server)
aux_source_directory(. src)
add_executable(printer ${src})
target_link_libraries(printer  Qt5::Core  server encodedecode)
