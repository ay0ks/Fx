# CMakeList.txt : Fx.Standard
#
cmake_minimum_required(VERSION 3.8)

project("Fx.Standard")

add_library("Fx.Standard" STATIC
	"./src/fx/standard/vector.cpp"
)
target_include_directories("Fx.Standard" PUBLIC "./include")
