set(LIBRARY_NAME "GlmVisu")


find_package(glm)
find_package(Qt5 COMPONENTS Core Gui Widgets Designer)


if(NOT TARGET Qt5::Widgets)
   return()
endif()

set(QT_USE_QTDESIGNER TRUE)

set(QT_PLUGINS_DIR "${Qt5Core_DIR}/../../../plugins")

add_definitions(${QT_DEFINITIONS})


set(HEADER_PATH src)
set(SOURCE_PATH src)
set(INSTALL_CMAKE_DIR ${CMAKE_INSTALL_PREFIX}/lib/${LIBRARY_NAME}/CMake/GlmVisu)
set(INSTALL_INCLUDE_DIR ${CMAKE_INSTALL_PREFIX}/include/${LIBRARY_NAME})
set(INSTALL_LIBRARY_DIR ${CMAKE_INSTALL_PREFIX}/lib/${LIBRARY_NAME})
set(INSTALL_BIN_DIR ${CMAKE_INSTALL_PREFIX}/bin/${LIBRARY_NAME})

get_filename_component(src_abs ${SOURCE_PATH} ABSOLUTE)

set(INCLUDE_FILES_LIB
	src/TransformSettings.h
	src/Mat4.h
  src/GlmVisu.h
  src/AngleSlider.h
  src/RotationInput.h
)

file(GLOB_RECURSE PLUGIN_FILES "${SOURCE_PATH}/plugins/*.*")
message(${PLUGIN_FILES})

set(SOURCE_FILES_LIB
   src/GlmVisu.h
   src/TransformSettings.h src/TransformSettings.cpp src/TransformSettings.ui
   src/Mat4.h src/Mat4.cpp src/Mat4.ui
   src/AngleSlider.h src/AngleSlider.cpp
   src/RotationInput.h src/RotationInput.cpp
	)



add_library(
    ${LIBRARY_NAME}
    SHARED
    ${SOURCE_FILES_LIB}
    ${INCLUDE_FILES_LIB}
    ${PLUGIN_FILES}
)
target_link_libraries(${LIBRARY_NAME} Qt5::Widgets Qt5::Core Qt5::Gui Qt5::Designer glm)
source_group("plugins" FILES ${PLUGIN_FILES})

target_compile_definitions(${LIBRARY_NAME} PRIVATE GLM_VISU_EXPORT)
target_compile_definitions(${LIBRARY_NAME} PRIVATE GLMVISU_GROUP="GlmVisu widgets")




#QT plugin export
install(TARGETS ${LIBRARY_NAME}
    DESTINATION ${QT_PLUGINS_DIR}/designer
)


install(FILES ${INCLUDE_FILES_LIB} DESTINATION include/${LIBRARY_NAME})

install(TARGETS  ${LIBRARY_NAME}
  # IMPORTANT: Add the foo library to the "export-set"
  EXPORT GlmVisuTargets
  RUNTIME DESTINATION "${INSTALL_LIBRARY_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIBRARY_DIR}" COMPONENT shlib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/foo"
    COMPONENT dev)


export(TARGETS ${LIBRARY_NAME}
  FILE "${INSTALL_LIBRARY_DIR}/GlmVisuTargets.cmake")
export(PACKAGE ${APP_NAME}) 

target_include_directories(${LIBRARY_NAME} PUBLIC  
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>  
    $<INSTALL_INTERFACE:include/${LIBRARY_NAME}>  # <prefix>/include/mylib
)



set_property(TARGET ${LIBRARY_NAME} PROPERTY FOLDER "${examples_folder_name}")



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
 
# Install the export set for use with the install-tree
install(EXPORT GlmVisuTargets DESTINATION
  "${INSTALL_CMAKE_DIR}")