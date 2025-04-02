# Use ROS 2 Humble base image for ARM architecture
FROM arm64v8/ros:humble

# Install required packages
RUN apt-get update && apt-get install -y \
    x11vnc \
    fluxbox \
    xterm \
    xvfb \
    wget \
    && rm -rf /var/lib/apt/lists/*

# Set environment variables for ROS
ENV DISPLAY=:1
ENV VNC_PASSWORD=vncpassword

# Expose the VNC port
EXPOSE 5901

# Copy startup script
COPY start.sh /start.sh
RUN chmod +x /start.sh

# Run the startup script
CMD ["/start.sh"]
