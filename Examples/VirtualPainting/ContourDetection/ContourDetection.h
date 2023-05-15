//
// Created by Ahmed Mohiy on 14/05/2023.
//

#ifndef VIRTUALPAINTING_CONTOURDETECTION_H
#define VIRTUALPAINTING_CONTOURDETECTION_H
#include <vector>
#include <opencv2/opencv.hpp>

using std::vector;

class ContourDetection {
private:
    vector<vector<cv::Point>> contours;
    vector<cv::Vec4i> hierarchy;
    vector<vector<cv::Point>> edges;
    vector<cv::Rect> bound_rect;
    vector<vector<int>> *points;

public:
    ContourDetection(vector<vector<int>> *);
    ~ContourDetection();
    void get_contours(cv::Mat &, cv::Mat &, int);
    void clear_all();
};


#endif //VIRTUALPAINTING_CONTOURDETECTION_H
