//
// Created by Ahmed Mohiy on 09/05/2023.
//

#include "Chapter2.h"
using std::string;

Chapter2::Chapter2() {

}

void Chapter2::to_gray() {
    string path = "../res/license_plates/img/Alaska.jpg";
    cv::Mat img = cv::imread(path);
    cv::Mat img_gray, gaussian_blur;


    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(img, gaussian_blur, cv::Size(7,7), 5, 0);
    cv::imshow("image", img);
    cv::imshow("image gray", img_gray);
    cv::imshow("gaussian blur", gaussian_blur);
    cv::waitKey(0);
}

void Chapter2::edge_detector() {
    string path = "../res/license_plates/img/Alaska.jpg";
    cv::Mat img = cv::imread(path);
    cv::Mat img_blur, img_canny, img_canny_2, img_dilation, img_erosion;

    cv::GaussianBlur(img, img_blur, cv::Size(7, 7), 5, 0);
    cv::Canny(img_blur,img_canny, 50, 150);
    cv::Canny(img_blur,img_canny_2, 50, 100);

    // Dilation means increase the thickness of the edges lines
    cv::Mat kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(5,5));
    cv::dilate(img_canny, img_dilation, kernel);

    // Erosion means decrease the thickness of the edges lines
    cv::Mat kernel_2 = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3,3));
    cv::erode(img_dilation, img_erosion, kernel_2);

    cv::imshow("image canny", img_canny );
    cv::imshow("image canny with dilation", img_dilation );
    cv::imshow("image canny with erosion", img_erosion );
    cv::imshow("image canny 2 ", img_canny_2 );
    cv::waitKey(0);
}

int Chapter2::run() {
//    to_gray();
    edge_detector();
    return 0;
}