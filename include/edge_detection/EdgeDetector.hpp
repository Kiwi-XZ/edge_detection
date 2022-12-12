#pragma once
#include <opencv2/opencv.hpp>

namespace edge_detection
{
class EdgeDetector
{
public:
    
    cv::Mat sobel(cv::Mat img);
    cv::Mat canny(cv::Mat img);
    cv::Mat direct_detect(cv::Mat img);

protected:
    cv::Mat gaussian_blur(cv::Mat img);
    cv::Mat merge_img(cv::Mat img_1, cv::Mat img_2);
};

}