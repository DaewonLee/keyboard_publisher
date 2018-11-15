cmake_minimum_required(VERSION 2.8.3)
project(keyboard_publisher)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  std_msgs
  roscpp
  rospy
)


catkin_package(
  INCLUDE_DIRS include
  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
)


###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(keyboard_publisher_node
  src/main.cpp 
)
target_link_libraries(keyboard_publisher_node
   ${catkin_LIBRARIES}
)

#add_dependencies(kinova_driver ${catkin_EXPORTED_TARGETS})
#add_dependencies(kinova_arm_driver ${catkin_EXPORTED_TARGETS})
#add_dependencies(kinova_tf_updater ${catkin_EXPORTED_TARGETS})
#target_link_libraries(kinova_driver ${catkin_LIBRARIES} dl)
#target_link_libraries(kinova_arm_driver ${catkin_LIBRARIES} kinova_driver)
#target_link_libraries(kinova_tf_updater ${catkin_LIBRARIES})














