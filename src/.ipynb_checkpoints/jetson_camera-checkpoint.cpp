#include <ros/ros.h>
#include <nodelet/loader.h>

int main(int argc, char **argv){
    ros::init(argc, argv, "jetson_camera_node");
    nodelet::Loader nodelet;
    nodelet::M_string remap(ros::names::getRemappings());
    nodelet::V_string nargv;
    std::string nodelet_name = ros::this_node::getName();
    nodelet.load(nodelet_name, "jetson_camera/JetsonCameraNodelet", remap, nargv);
    ROS_INFO("[CAM] CSI Camera driver initialized");
    ros::spin();

    return 0;
}
