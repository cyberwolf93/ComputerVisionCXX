//
// Created by Ahmed Mohiy on 14/05/2023.
//

#include "Draw.h"

Draw::Draw(vector<vector<int>> *points, Color color): color(color) {
    this->points = points;
}

Draw::~Draw() {
    delete points;
}

void Draw::draw(cv::Mat &img) {
    for(int i = 0; i < points->size(); i++) {
        cv::circle(img, cv::Point((*points)[i][0], (*points)[i][1]), 25, color.get_color_for((*points)[i][2]), cv::FILLED);
    }
}