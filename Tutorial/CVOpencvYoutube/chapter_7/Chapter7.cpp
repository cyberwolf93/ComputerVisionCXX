//
// Created by Ahmed Mohiy on 13/05/2023.
//

#include "Chapter7.h"

Chapter7::Chapter7() {

}

void Chapter7::get_contours(cv::Mat &img, cv::Mat &img_res) {
    vector<vector<cv::Point>> contours;

    vector<cv::Vec4i> hierarchy;

    cv::findContours(img, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    cv::drawContours(img_res, contours, -1, cv::Scalar(255,0,0), 2);

    vector<vector<cv::Point>> edges{contours.size()};
    vector<cv::Rect> rects{contours.size()};

    for (int i = 0; i < contours.size(); i++) {
        // find number of edges to each shape to detect the shape
        // for example 3 => triangle, 4 => Rectangle or square
        float peri = cv::arcLength(contours[i], true);
        cv::approxPolyDP(contours[i], edges[i], 0.02 * peri, true);
        std::cout <<  edges[i].size() << std::endl;

        rects[i] = cv::boundingRect(edges[i]);
        cv::rectangle(img_res, rects[i].tl(), rects[i].br(), cv::Scalar(0,255,0), 5);
    }
}

void Chapter7::detect_shapes() {
    string path = "../res/shapes/2.jpeg";
    cv::Mat img = cv::imread(path);
    cv::Mat img_gray, img_canny, img_dil,img_blur,  kernel;

    // Image preprocessing
    cv::cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    cv::GaussianBlur(img_gray, img_blur, cv::Size(3,3), 3, 0);
    cv::Canny(img_blur, img_canny, 25, 75);
    kernel = cv::getStructuringElement(cv::MORPH_RECT, cv::Size(3, 3));
    cv::dilate(img_canny, img_dil, kernel);

    get_contours(img_dil, img);

    cv::imshow("original image", img);
//    cv::imshow("gray", img_gray);
//    cv::imshow("canny", img_canny);
//    cv::imshow("dilation", img_dil);
    cv::waitKey(0);
}

int Chapter7::run() {
    detect_shapes();
    return 0;
}