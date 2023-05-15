cmake_minimum_required(VERSION 3.25)
project(CVOpencvYoutube)
set(CMAKE_CXX_STANDARD 17)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(CVOpencvYoutube main.cpp chapter_1/Chapter1.cpp chapter_2/Chapter2.cpp chapter_3/Chapter3.cpp chapter_4/Chapter4.cpp  chapter_5/Chapter5.cpp chapter_6/Chapter6.cpp chapter_7/Chapter7.cpp chapter_8/Chapter8.cpp )

target_link_libraries(CVOpencvYoutube ${OpenCV_LIBS})