#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber() : Node("minimal_subscriber")
  {
    // Create a subscription to the "topic"
    subscription_ = this->create_subscription<std_msgs::msg::String>(
      "topic", 10,
      std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1)
    );
  }

private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const
  {
    // Print the received message
    RCLCPP_INFO(this->get_logger(), "Received: '%s'", msg->data.c_str());
  }

  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
  // Initialize the ROS 2 system
  rclcpp::init(argc, argv);

  // Create an instance of the MinimalSubscriber class
  rclcpp::spin(std::make_shared<MinimalSubscriber>());

  // Shutdown ROS 2 when finished
  rclcpp::shutdown();
  return 0;
}
