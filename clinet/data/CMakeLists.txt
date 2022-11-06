cmake_minimum_required(VERSION 3.10.0)
project(encodedecode)
aux_source_directory(. data_src)
add_library(encodedecode ${data_src})