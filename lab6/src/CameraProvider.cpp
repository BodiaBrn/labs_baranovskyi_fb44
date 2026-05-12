#include "CameraProvider.hpp"
#include <iostream>

CameraProvider::CameraProvider() {
    cap.open(0); // standart web cam
    if (!cap.isOpened()) {
        std::cerr << "Can't open camera." << std::endl;
        exit(-1);
    }
}

CameraProvider::~CameraProvider() {
    cap.release();
}

cv::Mat CameraProvider::getFrame() {
    cv::Mat frame;
    cap >> frame;
    return frame;
}
