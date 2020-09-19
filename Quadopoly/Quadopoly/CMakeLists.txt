cmake_minimum_required (VERSION 3.8)

find_package(SDL2 REQUIRED HINTS $ENV{SDL2})
find_package(SDL2_image REQUIRED HINTS $ENV{SDL_image})

include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} "${CMAKE_CURRENT_LIST_DIR}/include")
add_executable (Quadopoly "Quadopoly.cpp")
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