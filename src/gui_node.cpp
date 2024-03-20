#include <ros/ros.h>

#include "msp_ros/gui.h"

int main(int argc, char **argv) {
  ros::init(argc, argv, "gui_node");

  ROS_INFO("Run GUI");
  gui::DynConfig dyn_config;

  ros::spin();

  return 0;
}