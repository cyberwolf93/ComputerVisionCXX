//
// Created by Ahmed Mohiy on 13/05/2023.
//

#ifndef CVOPENCVYOUTUBE_CHAPTER7_H
#define CVOPENCVYOUTUBE_CHAPTER7_H
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

using std::string;
using std::vector;

class Chapter7 {
public:
    Chapter7();
    void get_contours(cv::Mat &, cv::Mat &);
    void detect_shapes();
    int run();
};


#endif //CVOPENCVYOUTUBE_CHAPTER7_H
