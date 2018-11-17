#!/usr/bin/env bash

cd ~/Downloads

git clone --recurse-submodules https://github.com/Microsoft/cpprestsdk && cd cpprestsdk
mkdir build && cd build && cmake .. && make -j8 && sudo make install

cd ~/Downloads
git clone https://github.com/catchorg/Catch2 && cd Catch2
mkdir build && cd build && cmake .. && make -j8 && sudo make install
