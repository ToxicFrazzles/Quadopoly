cmake_minimum_required (VERSION 3.8)

if(WIN32)
	find_package(SDL2 REQUIRED HINTS $ENV{SDL2})
	find_package(SDL2_image REQUIRED HINTS $ENV{SDL_image})
else()
	INCLUDE(FindPkgConfig)
	PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)
	PKG_SEARCH_MODULE(SDL2_IMAGE REQUIRED SDL2_image>=2.0.0)
endif()


include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} "${CMAKE_CURRENT_LIST_DIR}/include")
add_executable (Quadopoly 
		"src/Quadopoly.cpp"
		"src/RenderWindow.cpp"
		"src/FPSCounter.cpp"
		"src/Scene.cpp")
target_link_libraries(Quadopoly ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

if(${CMAKE_BUILD_TYPE} STREQUAL Debug)
	add_definitions(-DDEBUG)
else()
	set_target_properties(Quadopoly PROPERTIES
		LINK_FLAGS /SUBSYSTEM:WINDOWS
	)
endif()

set(REQUIREMENTS 
	${SDL2_DLL}
	${SDL2_IMAGE_DLL}
	"${CMAKE_CURRENT_LIST_DIR}/test.png"
)

foreach(requirement IN ITEMS ${REQUIREMENTS})
	configure_file(${requirement} "${CMAKE_BINARY_DIR}/Quadopoly/" COPYONLY)
endforeach()

add_custom_command(
	TARGET Quadopoly POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Quadopoly/res ${CMAKE_BINARY_DIR}/Quadopoly/res)