cmake_minimum_required (VERSION 3.0)

project(hw4)

find_package(OpenGL REQUIRED)

#compile external dependencies
add_subdirectory(external)

include_directories(
	external/glfw-3.3.8/include/
	external/glm-0.9.9.8/
	external/glew-2.1.0/include/
	external/stb_image/
	.
)

set(ALL_LIBS
	${OPENGL_LIBRARY}
	glfw
	GLEW_210
)

add_definitions(
	-DTW_STATIC
	-DTW_NO_LIB_PRAGMA
	-DTW_NO_DIRECT3D
	-DGLEW_STATIC
	-D_CRT_SECURE_NO_WARNINGS
)

#  main 
add_executable(main 
	main.cpp
	Shader.cpp
	bezierCurve.cpp
	bezierPatch.cpp
	viewer.cpp
	mesh.cpp
	student_code.cpp
)
target_link_libraries(main
	${ALL_LIBS}
)
