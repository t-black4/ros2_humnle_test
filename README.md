# ROS 2 DOCKER 


* Docker that allows GUI 

# Start


```bash
docker-compose up -d
```


# RUN VNC in container 
```bash
Xvfb :1 -screen 0 1920x1080x24 &
fluxbox &
x11vnc -display :1 -usepw -forever -loop -passwd vncpassword
```


The above command starts the vnc to the docker image

use RealVNC to access the GUI 


VNC at <ip>:Port not just the IP 

# rviz2


To start rviz2 commands

```bash
source /opt/ros/humble/setup.bash
sudo apt-get update
sudo apt-get install ros-humble-rviz2 -y 
source /opt/ros/humble/setup.bash
```

the last source has to be done on the VNC GUI terminal 

To build test project 

```bash
cd ~/ros2_ws
rm -rf build install log
colcon build
source install/setup.bash

ros2 run my_robot my_node
ros2 run my_robot my_listener

```