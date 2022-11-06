cmake_minimum_required(VERSION 3.10.0)
project(service)
aux_source_directory(. src)
add_library(service ${src})