//
// Created by Ahmed Mohiy on 10/05/2023.
//

#include "Chapter3.h"

using std::string;

Chapter3::Chapter3() {

}


void Chapter3::resize() {
    string path = "../res/license_plates/img/Arizona.jpg";
    cv::Mat img = cv::imread(path);
    cv::Mat img_resized, img_scaled;

    cv::resize(img, img_resized, cv::Size(640, 400));
    cv::resize(img, img_scaled, cv::Size(), 2, 2);

    cv::imshow("image ", img);
    cv::imshow("image resized ", img_resized);
    cv::imshow("image scaled", img_scaled);
    cv::waitKey(0);
}


void Chapter3::crop() {
    string path = "../res/license_plates/img/Arizona.jpg";
    cv::Mat img = cv::imread(path);

    cv::Rect roi(100,100, 100, 100);
    cv::Mat img_crop = img(roi);

    cv::imshow("image ", img);
    cv::imshow("image cropped", img_crop);
    cv::waitKey(0);
}

int Chapter3::run() {
//    resize();
    crop();
    return 0;
}