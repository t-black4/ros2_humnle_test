cmake_minimum_required(VERSION 3.8)
project(my_robot)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

# Add executables for both publisher and subscriber
add_executable(my_node src/talker.cpp)
ament_target_dependencies(my_node rclcpp std_msgs)

add_executable(my_listener src/listener.cpp)
ament_target_dependencies(my_listener rclcpp std_msgs)

# Install executables
install(TARGETS my_node my_listener DESTINATION lib/${PROJECT_NAME})

ament_package()
