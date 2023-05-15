//
// Created by Ahmed Mohiy on 08/05/2023.
//

#include "Chapter1.h"

using std::string;
Chapter1::Chapter1() {

}

void Chapter1::load_image() {
    string path = "../res/license_plates/img/Alabama.jpg";
    cv::Mat img = cv::imread(path);
    cv::imshow("Image", img);

    cv::waitKey(0);
}

void Chapter1::load_video() {
    string path = "../res/license_plates/video/cars.mp4";
    cv::VideoCapture cap{path};

    cv::Mat img;

    while(cap.read(img)) {
        cv::imshow("Cars" , img);
        cv::waitKey(1);
    }
}

void Chapter1::capture_webcam() {
    cv::VideoCapture cam {0};
    cv::Mat img;

    while(cam.read(img)) {
        cv::imshow("Cam", img);
        cv::waitKey(1);
    }
}

int Chapter1::run() {
//    load_image();
//    load_video();
    capture_webcam();
    return 0;
}
