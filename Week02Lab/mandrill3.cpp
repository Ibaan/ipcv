#include <stdio.h>
#include <opencv/cv.h>        //you may need to
#include <opencv/highgui.h>   //adjust import locations
#include <opencv/cxcore.h>    //depending on your machine setup

using namespace cv;

int main() {
    Mat image = imread("mandrill3.jpg", 1);
    cvtColor(image, image, CV_HSV2BGR);

    imwrite("mandrill3_fixed.jpg", image);
}