//
// Created by Ahmed Mohiy on 10/05/2023.
//

#include "Chapter4.h"

Chapter4::Chapter4() {

}

void Chapter4::draw() {
    cv::Mat img(512, 512, CV_8UC3, cv::Scalar(255,255 , 255));

    cv::circle(img, cv::Point(256, 256), 155, cv::Scalar(0, 69, 255), cv::FILLED);
    cv::rectangle(img, cv::Point(130,226), cv::Point(382, 286), cv::Scalar(255, 255, 255), cv::FILLED);
    cv::line(img, cv::Point(130,290), cv::Point(382, 290), cv::Scalar(255,255,255), 2);

    cv::putText(img, "Stop sign", cv::Point(170, 262), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 69, 255), 2);

    cv::imshow("image", img);
    cv::waitKey(0);
}

int Chapter4::run() {
    draw();
    return 0;
}