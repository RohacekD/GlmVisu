set(LIBRARY_NAME "GlmVisu")


find_package(glm)
find_package(Qt5 COMPONENTS Core Gui Widgets)


if(NOT TARGET Qt5::Widgets)
   return()
endif()

set(HEADER_PATH src)
set(SOURCE_PATH src)
set(INSTALL_CMAKE_DIR ${CMAKE_INSTALL_PREFIX}/lib/${LIBRARY_NAME}/CMake/GlmVisu)
set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/${LIBRARY_NAME})
set(INSTALL_LIBRARY_DIR ${CMAKE_INSTALL_PREFIX}/lib/${LIBRARY_NAME})

get_filename_component(src_abs ${SOURCE_PATH} ABSOLUTE)

set(INCLUDE_FILES_LIB
	src/TransformSettings.h
	src/Mat4.h
)
set(SOURCE_FILES_LIB
   src/TransformSettings.h src/TransformSettings.cpp src/TransformSettings.ui
   src/Mat4.h src/Mat4.cpp src/Mat4.ui
	)

add_library(
    ${LIBRARY_NAME}
    STATIC
    ${SOURCE_FILES_LIB}
    ${INCLUDE_FILES_LIB}
)
target_compile_definitions(${LIBRARY_NAME} PRIVATE GLM_VISU_EXPORT)






install(FILES ${INCLUDE_FILES_LIB} DESTINATION include/${LIBRARY_NAME})
install(TARGETS ${LIBRARY_NAME} 
  EXPORT GlmVisuTargets 
  DESTINATION lib/${LIBRARY_NAME})
install(EXPORT GlmVisuTargets DESTINATION
  lib/${LIBRARY_NAME})


target_link_libraries(${LIBRARY_NAME} Qt5::Widgets Qt5::Core Qt5::Gui glm)

#target_include_directories(${LIBRARY_NAME} PUBLIC "src/")
set_property(TARGET ${LIBRARY_NAME} PROPERTY FOLDER "${examples_folder_name}")

export(TARGETS ${LIBRARY_NAME}
  FILE "${PROJECT_BINARY_DIR}/GlmVisuTargets.cmake")
export(PACKAGE ${APP_NAME}) 

file(RELATIVE_PATH REL_INCLUDE_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_INCLUDE_DIR}")
file(RELATIVE_PATH REL_LIBRARY_DIR "${INSTALL_CMAKE_DIR}"
   "${INSTALL_LIBRARY_DIR}")


# ... for the install tree
set(CONF_INCLUDE_DIRS "\${GlmVisu_CMAKE_DIR}/${REL_INCLUDE_DIR}")
set(CONF_LIBRARY_DIRS "\${GlmVisu_CMAKE_DIR}/${REL_LIBRARY_DIR}")

configure_file(GlmVisuConfig.cmake.in
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/GlmVisuConfig.cmake" @ONLY)

configure_file(GlmVisuConfigVersion.cmake.in
  "${PROJECT_BINARY_DIR}/GlmVisuConfigVersion.cmake" @ONLY)
 
install(FILES
  "${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/GlmVisuConfig.cmake"
  DESTINATION "${INSTALL_CMAKE_DIR}" COMPONENT dev)

message(${PROJECT_BINARY_DIR}${CMAKE_FILES_DIRECTORY}/GlmVisu.cmake)
 
# Install the export set for use with the install-tree
install(EXPORT GlmVisuTargets DESTINATION
  "${INSTALL_CMAKE_DIR}")