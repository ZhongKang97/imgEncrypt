cmake_minimum_required( VERSION 2.8 )
project ( ImgEncryption )

set( CMAKE_BUILD_TYPE "Release" )
#set( CMAKE_BUILD_TYPE "Debug" )
set( CMAKE_CXX_FLAGS "-std=c++11 " )

set( EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin )
set( LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib )

############### dependencies ######################
# OpenCV
find_package( OpenCV REQUIRED )
if(NOT OpenCV_FOUND)
  message(FATAL_ERROR "OpenCV not found in ${OpenCV_DIR}")
endif(NOT OpenCV_FOUND)
include_directories( ${OpenCV_INCLUDE_DIRS} )

set( THIRD_PARTY_LIBS 
    ${OpenCV_LIBS}
)
############### source and test ######################
include_directories(${PROJECT_SOURCE_DIR}/include )
#添加含有CMakeLists文件的子文件夹
add_subdirectory( src )
