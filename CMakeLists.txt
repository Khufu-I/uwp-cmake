cmake_minimum_required(VERSION 3.16)

# Cross compilation variables for Windows Store (UWP) needs
# to be set before project call
set(CMAKE_SYSTEM_NAME WindowsStore)
set(CMAKE_SYSTEM_VERSION 10.0)

project(uwp-cmake LANGUAGES CXX VERSION 1.0)
# Set Visual Studio startup project
set_directory_properties(PROPERTIES VS_STARTUP_PROJECT ${PROJECT_NAME})

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)

# Import asset files
include(${PROJECT_SOURCE_DIR}/assets/CMakeLists.txt)
# Set appxmanifest
set(CONTENT_FILES package.appxmanifest)
set_source_files_properties(${CONTENT_FILES} PROPERTIES VS_DEPLOYMENT_CONTENT 1)

#-------------------
# Main executable
#-------------------
add_executable(${PROJECT_NAME} WIN32 main.cpp ${CONTENT_FILES} ${ASSET_FILES})
# Include header files
include(${CMAKE_CURRENT_LIST_DIR}/include/CMakeLists.txt)
# Include source files
include(${CMAKE_CURRENT_LIST_DIR}/src/CMakeLists.txt)

# Enable all warnings and treat them as errors
target_compile_options(${PROJECT_NAME} PRIVATE  /W4 /WX /permissive- /EHsc)
# Enable edit and continue in Visual Studio
target_compile_options(${PROJECT_NAME} PRIVATE "$<$<CONFIG:DEBUG>:/ZI>")
target_link_options(${PROJECT_NAME} 
  PRIVATE "$<$<CONFIG:DEBUG>:/OPT:NOICF>" "$<$<CONFIG:DEBUG>:/OPT:NOREF>")

# Set minimum Windows SDK version
set_target_properties(${PROJECT_NAME} 
  PROPERTIES VS_WINDOWS_TARGET_PLATFORM_MIN_VERSION 10.0.18362.0)