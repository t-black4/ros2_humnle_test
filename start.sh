#!/bin/bash

# Start X virtual framebuffer
Xvfb :1 -screen 0 1920x1080x24 &

# Wait for Xvfb to start
sleep 2

# Start Fluxbox window manager
fluxbox &

# Wait for Fluxbox to start
sleep 2

# Start VNC server
x11vnc -display :1 -usepw -forever -loop -passwd $VNC_PASSWORD

