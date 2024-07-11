# CMakeList.txt : Fx.Multidimensional
#
cmake_minimum_required(VERSION 3.8)

project("Fx.Multidimensional")

add_library(
	"Fx.Multidimensional" STATIC
	"./src/fx/multidimensional/array.cpp"
	"./src/fx/multidimensional/map.cpp"
)
target_include_directories("Fx.Multidimensional" PUBLIC
	"./include"
	"Fx.Standard"
)
target_link_libraries("Fx.Multidimensional" PUBLIC 
	"Fx.Standard"
)