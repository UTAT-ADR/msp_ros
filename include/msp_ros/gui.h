#pragma once

#include <ros/ros.h>
#include <std_msgs/Empty.h>
#include <std_msgs/Float64.h>
#include <dynamic_reconfigure/server.h>
#include <msp_ros/gui.h>
#include <msp_ros/guiConfig.h>

#include <math.h>
#include <mutex>

namespace gui {

class DynConfig {
 public:
  DynConfig();
  ~DynConfig();

  void InitializeNode();
  void startServices();

 private:
  void dynamicReconfigureCallback(gui::guiConfig& config,
                                  uint32_t level);

 private:
  /* ROS Utils */
  ros::NodeHandle nh_;
  ros::NodeHandle pnh_;
  ros::Publisher ratio_pub_;

  /* Reconfigure */
  dynamic_reconfigure::Server<gui::guiConfig>* server_ = nullptr;
  gui::guiConfig rqt_param_config_;
  boost::recursive_mutex config_mutex_;


};

}  // namespace tune