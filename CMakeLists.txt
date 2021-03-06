#
# CMake file to build NetworkManagerCpp.
# Mark Grimes (mark.grimes@rymapt.com)
# 06/Oct/2017
# copyright 2017 Rymapt Ltd
# Licence to be decided
#

project( NetworkManagerCpp )

cmake_minimum_required(VERSION 2.8)

if( NOT MSVC ) # Microsoft Visual Studio is C++11 by default and doesn't recognise this flag
	add_definitions( "-std=c++11" )
endif()


# Create the file that has the version information and git hash
execute_process( COMMAND git describe --dirty --always --tags WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} OUTPUT_VARIABLE NetworkManagerCpp_GIT_DESCRIBE OUTPUT_STRIP_TRAILING_WHITESPACE )
execute_process( COMMAND git log -1 --pretty=format:%H WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} OUTPUT_VARIABLE NetworkManagerCpp_GIT_HASH OUTPUT_STRIP_TRAILING_WHITESPACE )
add_custom_target( ${PROJECT_NAME}_CreateVersionFile ALL ${CMAKE_COMMAND} -E touch "${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in" ) # Make sure the git hash is always checked (not just at configure time)
configure_file( "${CMAKE_CURRENT_SOURCE_DIR}/src/version.cpp.in" "${PROJECT_BINARY_DIR}/src/version.cpp" )

option( LIBNM_MOCK_CLASSES "Build unit tests" OFF )
if( LIBNM_MOCK_CLASSES )
	# Build mock code that doesn't do anything, but can be compiled and used without libnm C library
	# for when developing the other parts of an application.
	message( WARNING "*WARNING* LIBNM_MOCK_CLASSES has been set to ON, which means no functional "
		"code will be produced. This is only useful for development on machines without "
		"NetworkManager installed." )
	include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/mock/include" )
	aux_source_directory( "${CMAKE_CURRENT_SOURCE_DIR}/mock/src" library_sources )
	add_library( ${PROJECT_NAME} STATIC ${library_sources} "${PROJECT_BINARY_DIR}/src/version.cpp" )
	set( ${PROJECT_NAME}_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/mock/include" PARENT_SCOPE )
else()
	include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/include" )
	aux_source_directory( "${CMAKE_CURRENT_SOURCE_DIR}/src" library_sources )

	# Project dependencies
	find_package(PkgConfig REQUIRED)
	pkg_check_modules(LibNM REQUIRED libnm)

	add_library( ${PROJECT_NAME} STATIC ${library_sources} "${PROJECT_BINARY_DIR}/src/version.cpp" )
	set( ${PROJECT_NAME}_INCLUDES "${CMAKE_CURRENT_SOURCE_DIR}/include" PARENT_SCOPE )
	target_link_libraries( ${PROJECT_NAME} ${LibNM_LIBRARIES})
	target_include_directories( ${PROJECT_NAME} PUBLIC ${LibNM_INCLUDE_DIRS})
	target_compile_options( ${PROJECT_NAME} PUBLIC ${LibNM_CFLAGS_OTHER})

	install( TARGETS ${PROJECT_NAME} DESTINATION lib )
	install( DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/include/" DESTINATION include )

	option( BUILD_UNITTESTS "Build unit tests" ON )
	message( STATUS "BUILD_UNITTESTS: ${BUILD_UNITTESTS}" )
	if( BUILD_UNITTESTS )
		# Fix the test configuration file to have the correct paths
		configure_file( "${PROJECT_SOURCE_DIR}/tests/src/testinputs.cpp.in" "${PROJECT_BINARY_DIR}/tests/src/testinputs.cpp" @ONLY )
		include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/tests/include" )
		aux_source_directory( "${CMAKE_CURRENT_SOURCE_DIR}/tests/src" unittests_sources )
		add_executable( ${PROJECT_NAME}Tests ${unittests_sources} "${PROJECT_BINARY_DIR}/tests/src/testinputs.cpp" )
		target_link_libraries( ${PROJECT_NAME}Tests ${PROJECT_NAME} )
	endif()

	option( BUILD_EXAMPLES "Build examples" ON )
	message( STATUS "BUILD_EXAMPLES: ${BUILD_EXAMPLES}" )
	if( BUILD_EXAMPLES )
		file( GLOB CPP_FILES "examples/*.cpp" )
		foreach( CPP_FILE ${CPP_FILES} )
			get_filename_component( EXECUTABLE_NAME ${CPP_FILE} NAME_WE )
			add_executable( ${EXECUTABLE_NAME} ${CPP_FILE} )
			target_link_libraries( ${EXECUTABLE_NAME} ${PROJECT_NAME} )
		endforeach()
	endif()
endif()
