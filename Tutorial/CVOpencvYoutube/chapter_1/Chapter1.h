//
// Created by Ahmed Mohiy on 08/05/2023.
//

#ifndef CVOPENCVYOUTUBE_CHAPTER1_H
#define CVOPENCVYOUTUBE_CHAPTER1_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>


class Chapter1 {
public:
    Chapter1();
    void load_image();
    void load_video();
    void capture_webcam();
    int run();
};

#endif //CVOPENCVYOUTUBE_CHAPTER1_H
