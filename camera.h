#ifndef CAMERA_H
#define CAMERA_H

#include <iostream>
#include <string>
#include <opencv2/opencv.hpp>
#include <thread>


struct path_fps{
    std::string path;
    double fps;
};

class Camera
{
public:
    Camera();
    ~Camera();
    void set_window_name(std::string name);
    void set_camera_indx(int indx);
    int open_camera(bool revers=false,int revers_style=1);
    void record_void(path_fps data);

protected:
    void revers_image(cv::Mat &image,int revers_style);
    void record_video_(std::string path,double fps);

private:
    std::string window_name;
    int camera_indx;
    cv::Mat frame_camera;
    cv::Mat frame_video;
    cv::VideoCapture cap;
    cv::VideoWriter record;
};

#endif // CAMERA_H
