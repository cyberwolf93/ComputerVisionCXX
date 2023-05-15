#include <iostream>
#include <vector>
#include <opencv2/opencv.hpp>
#include "Color/Color.h"
#include "ContourDetection/ContourDetection.h"
#include "Draw/Draw.h"

int main() {
    std::vector<vector<int>> points;
    Color c;
    ContourDetection c_detection{&points};
    Draw draw{&points, c};

    cv::VideoCapture cam{0};
    cv::Mat img;
    cv::namedWindow("Image");

    while(cam.read(img)) {
        auto mask_vec = c.find(img);
        for (auto mask: mask_vec) {
            c_detection.get_contours(img, mask, 0);
        }
        draw.draw(img);
        cv::flip(img, img,1);
        cv::resizeWindow("Image", 1920, 1080);
        cv::imshow("Image", img);
        cv::waitKey(1);
    }


    return 0;
}
