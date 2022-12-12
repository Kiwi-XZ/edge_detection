#include "../include/edge_detection/EdgeDetector.hpp"

using namespace edge_detection;

#include <iostream>
using namespace std;
using namespace cv;

// Your class methods definition goes here
cv::Mat EdgeDetector::gaussian_blur(cv::Mat img) {
    // Convert to grayscale
    cv::Mat img_gray;
    cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    // Blur the image for better edge detection
    cv::Mat img_blur;
    cv::GaussianBlur(img_gray, img_blur, cv::Size(3,3), 0);
    return img_blur;
}

cv::Mat EdgeDetector::merge_img(cv::Mat img_1, cv::Mat img_2) {
    cv::Mat result_img;
    cv::addWeighted(img_1, 0.5, img_2, 0.5, 0, result_img);
    return result_img;
}

cv::Mat EdgeDetector::sobel(cv::Mat img) {
    // Sobel edge detection
    cv::Mat img_blur = gaussian_blur(img);
    cv::Mat sobelxy, result_img;
    cv::Sobel(img_blur, sobelxy, CV_64F, 1, 1, 5);
    result_img = merge_img(img, sobelxy);
    return result_img;
}

cv::Mat EdgeDetector::canny(cv::Mat img) {
    // Canny edge detection
    cv::Mat img_blur = gaussian_blur(img);
    cv::Mat edges, result_img;
    cv::Canny(img_blur, edges, 100, 200, 3, false);
    cout << "edges size" << edges.size() << endl;
    cout << "img size" << img.size() << endl;
    result_img = merge_img(img, edges);
    return result_img;
}

cv::Mat EdgeDetector::direct_detect(cv::Mat img) {
    cv::Mat thresh;
    cv::Mat img_gray;
    // convert original rgb image to gray image
    cvtColor(img, img_gray, cv::COLOR_BGR2GRAY);
    threshold(img_gray, thresh, 150, 255, THRESH_BINARY);
    // detect the contours on the image using CHAIN_APPROX_NONE
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(thresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_NONE);
    // draw contours on the original image
    Mat img_copy = img.clone();
    drawContours(img_copy, contours, -1, Scalar(0, 255, 0), 2);
    return img_copy;
}


int main()
{
    // Reading image
    string image_path;
    cout << "Please enter the path for a image: " << endl;
    cin >> image_path;
    cv::Mat img = cv::imread(image_path);

    if (img.empty())
    {
        cout << "Could not read the image: " << endl;
        return 1;
    }

    edge_detection::EdgeDetector detector;
    cv::imshow("Edge in green", detector.direct_detect(img));
    cv::waitKey(0);
    cv::destroyAllWindows();
    return 0;
}
