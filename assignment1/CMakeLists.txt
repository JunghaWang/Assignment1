cmake_minimum_required(VERSION 3.0.2)
project(assignment1)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  message_generation
  roscpp
  roslaunch
  rospy
  std_msgs
)

roslaunch_add_file_check(launch)


# Generate messages in the 'msg' folder
add_message_files(
  FILES
  msg.msg
)

## Generate added messages and services with any dependencies listed here
generate_messages(
  DEPENDENCIES
  geometry_msgs
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
  LIBRARIES Assignment1
  CATKIN_DEPENDS geometry_msgs message_generation roscpp roslaunch rospy std_msgs message_runtime
  # DEPENDS system_lib
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(cmd_vel src/cmd_vel.cpp)
add_executable(pub_turtlesim src/cpub_turtlesim.cpp)

add_dependencies(cmd_vel ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
add_dependencies(pub_turtlesim ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

target_link_libraries(cmd_vel
  ${catkin_LIBRARIES}
)
target_link_libraries(pub_turtlesim
  ${catkin_LIBRARIES}
)