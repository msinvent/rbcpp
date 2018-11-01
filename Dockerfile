# This is an auto generated Dockerfile for ros:ros-base
# generated from docker_images/create_ros_image.Dockerfile.em
FROM ros:kinetic-ros-core

# install ros packages
RUN apt-get update -y
RUN apt-get install -y ros-kinetic-ros-base
RUN apt-get install -y ros-kinetic-rosbridge-suite
RUN apt-get install -y build-essential valgrind
RUN apt-get install -y ros-kinetic-rosbridge-server
