# ROS 2 DOCKER GUIDE

## Setup Instructions

### Prerequisites
- Docker
- Docker Compose
- ROS 2 Humble
- RealVNC

### Description
This guide will help you set up a ROS 2 environment in a Docker container.
You will be able to run ROS 2 nodes and use ROS 2 tools in a GUI environment.

### Starting the Docker Container
```bash
docker-compose up -d
```
**Note:** must be in the root directory of the project


### Setting Up VNC in Container
Run these commands to set up the VNC server:
```bash
Xvfb :1 -screen 0 1920x1080x24 &
fluxbox &
x11vnc -display :1 -usepw -forever -loop -passwd vncpassword
```
**Note:** The resolution 1920x1080 depends on your screen size and Dockerfile

**Access Instructions:**
- Use RealVNC to connect to the GUI
- Connect to `<ip>:<port>` (not just the IP address)
- Password: vncpassword

### Setting Up RViz2
Run these commands to install and prepare RViz2:
```bash
source /opt/ros/humble/setup.bash
sudo apt-get update
sudo apt-get install ros-humble-rviz2 -y
source /opt/ros/humble/setup.bash
```
**Note:** The last source command must be executed in the VNC GUI terminal.

### Building Test Project
```bash
cd ~/ros2_ws
rm -rf build install log
colcon build
source install/setup.bash
ros2 run my_robot my_node
ros2 run my_robot my_listener
```