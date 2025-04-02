#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using std::placeholders::_1;

class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher() : Node("minimal_publisher")
  {
    // Create a publisher for the topic "topic"
    publisher_ = this->create_publisher<std_msgs::msg::String>("topic", 10);

    // Set up a timer to call the timer_callback function every 500 milliseconds
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(500),
      std::bind(&MinimalPublisher::timer_callback, this)
    );
  }

private:
  void timer_callback()
  {
    // Create a message to publish
    auto message = std_msgs::msg::String();
    message.data = "Hello, ROS 2!";

    // Publish the message to the "topic"
    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    publisher_->publish(message);
  }

  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  // Initialize the ROS 2 system
  rclcpp::init(argc, argv);

  // Create an instance of the MinimalPublisher class
  rclcpp::spin(std::make_shared<MinimalPublisher>());

  // Shutdown ROS 2 when finished
  rclcpp::shutdown();
  return 0;
}
