# Add this folder to the include lookup directories
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
# Use precompiled header to optimize compilation of rarely changing
# Windows header files
target_precompile_headers(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/pch.h)
# Include header files
target_sources(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_LIST_DIR}/App.h)