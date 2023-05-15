//
// Created by Ahmed Mohiy on 13/05/2023.
//

#include "Chapter6.h"

Chapter6::Chapter6() {

}

void Chapter6::color_detection() {
    string path = "../res/cars/orange_porsche.jpeg";
    cv::Mat img_hsv, mask;
    int h_min, s_min , v_min;
    int h_max, s_max, v_max;
    cv::Mat img = cv::imread(path);


    // create track bars to change hue, saturation and value 
    string window_name = "TrackBars";
    cv::namedWindow(window_name, (400, 400));
    cv::createTrackbar("Hue min", window_name, &h_min, 179);
    cv::createTrackbar("Hue max", window_name, &h_max, 179);
    cv::createTrackbar("sat min", window_name, &s_min, 255);
    cv::createTrackbar("sat amx", window_name, &s_max, 255);
    cv::createTrackbar("val min", window_name, &v_min, 255);
    cv::createTrackbar("val amx", window_name, &v_max, 255);

    cv::VideoCapture cam{0};

    while(cam.read(img)) {
        cv::cvtColor(img, img_hsv, cv::COLOR_BGR2HSV);
        cv::Scalar lower(h_min, s_min, v_min);
        cv::Scalar upper(h_max, s_max, v_max);
        cv::inRange(img_hsv, lower, upper, mask);

        cv::imshow("Image", img);
//        cv::imshow("Image HSV", img_hsv);
        cv::imshow("Image hsv mask", mask);
        cv::waitKey(1);
    }

}

int Chapter6::run() {
    color_detection();
    return 0;
}