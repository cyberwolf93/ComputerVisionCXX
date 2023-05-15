cmake_minimum_required(VERSION 3.25)
project(VirtualPainting)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
set(CMAKE_INSTALL_PREFIX "/Users/amohiy/Projects/ComputerVisionCXX/Examples/VirtualPainting/build")

add_executable(VirtualPainting main.cpp Color/Color.cpp ContourDetection/ContourDetection.cpp Draw/Draw.cpp)

target_link_libraries(VirtualPainting ${OpenCV_LIBS})

install(TARGETS VirtualPainting DESTINATION rel CONFIGURATIONS Release)

include(InstallRequiredSystemLibraries)
set(CPACK_PROJECT_NAME "${PROJECT_NAME}")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set(CPack_PACKAGE_VERSION_MAJOR "1")
set(CPack_PACKAGE_VERSION_MINOR "0")
include(CPack)