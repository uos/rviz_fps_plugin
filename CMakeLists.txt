
## This CMakeLists.txt file for rviz_label_tool
##
## First start with some standard ROS stuff.
cmake_minimum_required(VERSION 2.4.6)
include($ENV{ROS_ROOT}/core/rosbuild/rosbuild.cmake)
rosbuild_init()

set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}  -std=c++0x" )

## This plugin includes Qt widgets, so we must include Qt like so:
find_package(Qt4 COMPONENTS QtCore QtGui REQUIRED)
include(${QT_USE_FILE})

## I prefer the Qt signals and slots to avoid defining "emit", "slots",
## etc because they can conflict with boost signals, so define QT_NO_KEYWORDS here.
add_definitions(-DQT_NO_KEYWORDS)

## Here we specify which header files need to be run through "moc",
## Qt's meta-object compiler.
qt4_wrap_cpp(MOC_FILES
  include/fps_motion_view_controller.h
  include/fps_motion_config_widget.h
  include/fps_motion_tool.h
)

# Here we specify the list of source files, including the output of
## the previous command which is stored in ``${MOC_FILES}``.
set(SOURCE_FILES
  src/fps_motion_view_controller.cpp
  src/fps_motion_config_widget.cpp
  src/fps_motion_tool.cpp
  ${MOC_FILES}
)

## Set the default path for built libraries to the "lib" directory
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# add postgis_control so
#link_directories(/usr/lib ${postgis_control_PACKAGE_PATH}/lib)

## An rviz plugin is just a shared library, so here we declare the
## library to be called ``${PROJECT_NAME}`` 
rosbuild_add_library(${PROJECT_NAME} ${SOURCE_FILES})

## Link the library with whatever Qt libraries have been defined by
## the ``find_package(Qt4 ...)`` line above.
target_link_libraries(${PROJECT_NAME} ${QT_LIBRARIES})
