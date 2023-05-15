//
// Created by Ahmed Mohiy on 13/05/2023.
//

#include "Chapter5.h"

using std::string;

Chapter5::Chapter5() {

}

void Chapter5::warp_images() {
    string path = "../res/cards/2.png";
    cv::Mat img = cv::imread(path);

    float w {200};
    float h {300};
    cv::Mat matrix, img_k_heart_warp, img_k_diamond_warp, img_k_club_warp, img_k_spades_warp, img_q_diamond_warp, img_q_heart_warp;
    const int _size {4};
    cv::Point2f dest[_size] = {{0.0f,0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};


    // king of heart
    cv::Point2f src_k_heart[_size] = {{50,30}, {168, 15}, {65, 160}, {185, 141}};
    matrix = cv::getPerspectiveTransform(src_k_heart, dest);
    cv::warpPerspective(img, img_k_heart_warp, matrix, cv::Point(w, h));
    // king of diamond
    cv::Point2f src_k_diamond[_size] = {{207,35}, {325, 16}, {232, 162}, {355, 145}};
    matrix = cv::getPerspectiveTransform(src_k_diamond, dest);
    cv::warpPerspective(img, img_k_diamond_warp, matrix, cv::Point(w, h));
    // king of clubs
    cv::Point2f src_k_clubs[_size] = {{370,38}, {488, 18}, {405, 170}, {529, 150}};
    matrix = cv::getPerspectiveTransform(src_k_clubs, dest);
    cv::warpPerspective(img, img_k_club_warp, matrix, cv::Point(w, h));
    // king of spades
    cv::Point2f src_k_spades[_size] = {{530,53}, {645, 35}, {573, 187}, {693, 167}};
    matrix = cv::getPerspectiveTransform(src_k_spades, dest);
    cv::warpPerspective(img, img_k_spades_warp, matrix, cv::Point(w, h));
    // queen of diamond
    cv::Point2f src_q_diamond[_size] = {{128,200}, {280, 173}, {150, 367}, {315, 344}};
    matrix = cv::getPerspectiveTransform(src_q_diamond, dest);
    cv::warpPerspective(img, img_q_diamond_warp, matrix, cv::Point(w, h));
    // queen of heart
    cv::Point2f src_q_heart[_size] = {{366,200}, {510, 174}, {412, 379}, {562, 352}};
    matrix = cv::getPerspectiveTransform(src_q_heart, dest);
    cv::warpPerspective(img, img_q_heart_warp, matrix, cv::Point(w, h));


    for(int i=0; i<_size; i++) {
        cv::circle(img, src_k_heart[i], 10, cv::Scalar(0,0,255), cv::FILLED);
        cv::circle(img, src_k_diamond[i], 10, cv::Scalar(0,0,255), cv::FILLED);
        cv::circle(img, src_k_clubs[i], 10, cv::Scalar(0,0,255), cv::FILLED);
        cv::circle(img, src_k_spades[i], 10, cv::Scalar(0,0,255), cv::FILLED);
        cv::circle(img, src_q_diamond[i], 10, cv::Scalar(0,0,255), cv::FILLED);
        cv::circle(img, src_q_heart[i], 10, cv::Scalar(0,0,255), cv::FILLED);
    }

    cv::imshow("Image", img);
    cv::imshow("Warped image 1", img_k_heart_warp);
    cv::imshow("Warped image 2", img_k_diamond_warp);
    cv::imshow("Warped image 3", img_k_club_warp);
    cv::imshow("Warped image 4", img_k_spades_warp);
    cv::imshow("Warped image 5", img_q_diamond_warp);
    cv::imshow("Warped image 6", img_q_heart_warp);



    cv::waitKey(0);
}

int Chapter5::run() {
    warp_images();
    return 0;
}