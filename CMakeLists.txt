cmake_minimum_required(VERSION 3.0.2)
project(msp_ros)

find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  dynamic_reconfigure
)

generate_dynamic_reconfigure_options(
  cfg/gui.cfg
)

catkin_package()

###########
## Build ##
###########

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)
add_executable(gui_node src/gui_node.cpp
                        src/gui.cpp)
add_dependencies(gui_node msp_ros_gencfg)

target_link_libraries(
  gui_node
  ${catkin_LIBRARIES}
)