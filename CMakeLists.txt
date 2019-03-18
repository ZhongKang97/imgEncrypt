cmake_minimum_required(VERSION 2.8.12)

project(Robocon_opencv)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(BOOST_ROOT "D:\\CODEing\\boost_1_69_0")
#set(OpenCV_DIR"D:\\CODEing\\Opencv\\Opencv320\\install\\")
find_package(Qt5Core)
find_package(OpenCV REQUIRED)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIRS}
#  D:\CODEing\boost_1_69_0\stage\lib
  )
add_executable(${PROJECT_NAME}  "181114_lineTracker.cpp" "181124_skelextractor.cpp")
 

target_link_libraries(${PROJECT_NAME} Qt5::Core)
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS} )
target_link_libraries(${PROJECT_NAME} ${Boost_LIBS} )
