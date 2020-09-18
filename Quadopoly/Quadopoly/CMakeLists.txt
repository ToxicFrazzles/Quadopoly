cmake_minimum_required (VERSION 3.8)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)


include_directories(${SDL2_INCLUDE_DIRS} ${SDL2_IMAGE_INCLUDE_DIRS} "${CMAKE_CURRENT_LIST_DIR}/include")
add_executable (Quadopoly "Quadopoly.cpp")
target_link_libraries(Quadopoly ${SDL2_LIBRARIES} ${SDL2_IMAGE_LIBRARIES})

if(${CMAKE_BUILD_TYPE} STREQUAL Release)
	set_target_properties(Quadopoly PROPERTIES
		LINK_FLAGS /SUBSYSTEM:WINDOWS
	)
else()
	add_definitions(-DDEBUG)
endif()

set(REQUIREMENTS 
	${SDL2_DLL}
	${SDL2_IMAGE_DLL}
)

foreach(requirement IN ITEMS ${REQUIREMENTS})
	configure_file(${requirement} "${CMAKE_BINARY_DIR}/Quadopoly" COPYONLY)
endforeach()