//
// Created by Ahmed Mohiy on 14/05/2023.
//

#ifndef VIRTUALPAINTING_COLOR_H
#define VIRTUALPAINTING_COLOR_H
#include <vector>
#include <opencv2/opencv.hpp>
using std::vector;

class Color {
private:
    vector<vector<int>> limits;
    vector<cv::Scalar> colors;

public:
    Color();
    cv::Scalar get_color_for(int);
    vector<cv::Mat> find(cv::Mat &);
};


#endif //VIRTUALPAINTING_COLOR_H
