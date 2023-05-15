//
// Created by Ahmed Mohiy on 14/05/2023.
//

#include "Chapter8.h"

Chapter8::Chapter8() {

}

int Chapter8::run() {

    string path = "../res/faces/brad.jpeg";
    cv::Mat img = cv::imread(path);

    cv::CascadeClassifier faceCascade;
    faceCascade.load("../res/faces/haarcascade_frontalface.xml");

    if (faceCascade.empty()) {
        return 1;
    }

    std::vector<cv::Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for (auto rect: faces) {
        cv::rectangle(img, rect.tl(), rect.br(), cv::Scalar(255, 0, 0), 3);
    }

    cv::imshow("Image", img);
    cv::waitKey(0);

    return 0;
}