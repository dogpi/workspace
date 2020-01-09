#include "camera.h"


Camera::Camera():window_name("ShowImage"),camera_indx(0)
{

}
Camera::~Camera()
{
    cv::destroyAllWindows();
    std::cout<<"destroy \""<<window_name<<"\" window"<<std::endl;
}

void Camera::set_window_name(std::string name)
{
    if(name.empty()){
        name = "ShowImage";
    }
    window_name = name;
}

void Camera::set_camera_indx(int indx)
{
    if(indx<0){
        indx = 0;
    }
    camera_indx = indx;
}


int Camera::open_camera(bool revers,int revers_style)
{
    cv::namedWindow(window_name,cv::WINDOW_AUTOSIZE);
    cap.open(camera_indx);
    if(!cap.isOpened()) return -1;
    while (1) {
        cap>>frame_camera;
        if(frame_camera.empty()) return -1;
        if(revers){
            revers_image(frame_camera,revers_style);
        }
        cv::imshow(window_name,frame_camera);
        if(cv::waitKey(33)=='q'){
            break;
        }
    }
    return 0;
}

void Camera::record_void(path_fps data)
{
  record_video_(data.path,data.fps);

}

void Camera::revers_image(cv::Mat &image,int revers_style)
{
    if(image.empty()) std::cout<<"revers's image is empty"<<std::endl;
    cv::flip(image,image,revers_style);
}

void Camera::record_video_(std::string path,double fps)
{
    if(!cap.isOpened()) cap.open(camera_indx);
    cv::namedWindow("video",cv::WINDOW_AUTOSIZE);
    cap>>frame_video;
    cv::GaussianBlur(frame_video,frame_video,cv::Size(3,3),0);
    cv::fastNlMeansDenoising(frame_video,frame_video);
    cv::Size size(frame_video.cols,frame_video.rows);
    record.open(path,CV_FOURCC('M','J','P','G'),fps,size);
    while(1){
        cap>>frame_video;
        if(frame_video.empty()) break;
        if(!record.isOpened()) break;
        record.write(frame_video);
        imshow("video",frame_video);
        if(cv::waitKey(1)=='r')
        {
            break;
        }
    }
}
