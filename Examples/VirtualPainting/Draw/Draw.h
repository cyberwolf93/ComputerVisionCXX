//
// Created by Ahmed Mohiy on 14/05/2023.
//

#ifndef VIRTUALPAINTING_DRAW_H
#define VIRTUALPAINTING_DRAW_H
#include <opencv2/opencv.hpp>
#include <vector>
#include "../Color/Color.h"
using std::vector;

class Draw {
private:
    vector<vector<int>> *points;
    Color color;
public:
    Draw(vector<vector<int>> *, Color color);
    ~Draw();
    void draw(cv::Mat &);
};


#endif //VIRTUALPAINTING_DRAW_H
