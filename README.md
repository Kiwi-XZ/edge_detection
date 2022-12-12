# edge_detection

## Introduction
This is a repo for basic edge detection with OpenCV.

## Requirements
This implementation requires the following modules:
-[OpenCV](https://opencv.org/)

## Implementation
Pull the repo, create and change to `build` folder. The compilation is done by cmake and make.
```
mkdir build && cd $_
cmake ..
make
```
Then you should be able to find a binary file named `edge_detection_bin` under `<your path>/edge_detection/build/devel/lib/edge_detection`.

## Possible improvements
- Should be more stable against noise.
- More parameters for algorithm tuning should be exposed.
- Different algorithms for edge detection should be available.
- CMakeLists.txt could be better organized for easy reading and setting path for generated binary file.
