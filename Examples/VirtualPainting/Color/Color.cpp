//
// Created by Ahmed Mohiy on 14/05/2023.
//

#include "Color.h"

Color::Color() {
    limits.push_back({0, 179, 57, 172, 255, 255});
//    limits.push_back({85, 179, 156, 255, 127, 255});

//    colors.push_back(cv::Scalar(96, 9, 235)); // pink
    colors.push_back(cv::Scalar(181, 96, 31)); //blue
}

vector<cv::Mat> Color::find(cv::Mat &img) {
    cv::Mat imgHSV;
    cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

    vector<cv::Mat> v_mask;
    for (auto color: limits) {
        cv::Scalar lower(color[0], color[1], color[2]);
        cv::Scalar upper(color[3], color[4], color[5]);

        cv::Mat mask;
        cv::inRange(imgHSV, lower, upper, mask);
        v_mask.push_back(mask);
    }

    return v_mask;
}

cv::Scalar Color::get_color_for(int index) {
    return colors[index];
}