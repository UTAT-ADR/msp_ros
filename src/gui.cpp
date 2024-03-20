#include "msp_ros/gui.h"

namespace gui {

DynConfig::DynConfig() {
  InitializeNode();
  startServices();
}

DynConfig::~DynConfig() {}

void DynConfig::InitializeNode() {
  nh_ = ros::NodeHandle("");
  pnh_ = ros::NodeHandle("~");

  ratio_pub_ = nh_.advertise<std_msgs::Float64>("ratio", 1);
}

void DynConfig::startServices() {
  // set up Dynamic Reconfigure Server
  server_ =
      new dynamic_reconfigure::Server<gui::guiConfig>(
          config_mutex_, ros::NodeHandle("~"));
  dynamic_reconfigure::Server<
      gui::guiConfig>::CallbackType f;
  f = boost::bind(&DynConfig::dynamicReconfigureCallback, this, _1,
                  _2);
  server_->setCallback(f);
}

void DynConfig::dynamicReconfigureCallback(
    gui::guiConfig& config, uint32_t level) {
  rqt_param_config_ = config;

  const double ratio = config.ratio;
  std::cout << "ratio: " << ratio << std::endl;

  std_msgs::Float64 msg;
  msg.data = ratio;
  ratio_pub_.publish(msg);
}

}  // namespace tune
