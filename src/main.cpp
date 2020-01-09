#include <iostream>
#include "camera.h"


using namespace std;
void hello(path_fps data){
    cout<<data.path<<" "<<data.fps<<endl;
}
int main()
{
    path_fps data={"myvideo.avi",8.0};
    Camera c;
    c.set_camera_indx(0);
//    c.set_window_name("open camera");
//    std::thread t1(&Camera::open_camera,&c,true,1);
    std::thread t2(&Camera::record_void,&c,data);
//    t1.join();
    t2.join();
    return 0;
}
