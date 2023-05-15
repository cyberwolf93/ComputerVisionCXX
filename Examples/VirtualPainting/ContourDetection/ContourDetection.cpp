//
// Created by Ahmed Mohiy on 14/05/2023.
//

#include "ContourDetection.h"

ContourDetection::ContourDetection(vector<vector<int>> * points) {
    this->points = points;
}

ContourDetection::~ContourDetection() {
    delete points;
}

void ContourDetection::clear_all() {
    contours.clear();
    hierarchy.clear();
    edges.clear();
    bound_rect.clear();
}

void ContourDetection::get_contours(cv::Mat &img, cv::Mat &mask, int color_index) {
    clear_all();
    cv::findContours(mask, contours, hierarchy, cv::RETR_EXTERNAL, cv::CHAIN_APPROX_SIMPLE);
    edges.resize(contours.size());
    bound_rect.resize(contours.size());


    for(int i=0; i < contours.size(); i++) {
        if (cv::contourArea(contours[i]) > 1000) {
            float peri = cv::arcLength(contours[i], true);
            cv::approxPolyDP(contours[i], edges[i], 0.02*peri, true);
            bound_rect[i] = cv::boundingRect(edges[i]);
//            cv::drawContours(img, edges, i, cv::Scalar(255, 0 , 255));
//            cv::rectangle(img, bound_rect[i].tl(), bound_rect[i].br(),cv::Scalar(0,255,0),3);

            cv::Point point(bound_rect[i].x + bound_rect[i].width / 2, bound_rect[i].y);
            if (point.x > 0 && point.y > 0) {
                points->push_back({point.x, point.y, color_index});
            }

        }
    }



}