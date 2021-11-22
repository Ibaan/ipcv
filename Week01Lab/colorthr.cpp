#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>

using namespace cv;

int main() {
    Mat image = imread("mandrillRGB.jpg", 1);

    for(int y=0; y<image.rows; y++) {
        for(int x=0; x<image.cols; x++) {
            uchar pixelBlue = image.at<Vec3b>(y,x)[0];
            uchar pixelGreen = image.at<Vec3b>(y,x)[1];
            uchar pixelRed = image.at<Vec3b>(y,x)[2];
            if (pixelBlue>128) {
                image.at<Vec3b>(y,x)[0]=255;
                image.at<Vec3b>(y,x)[1]=255;
                image.at<Vec3b>(y,x)[2]=255;
            }
            else {
                image.at<Vec3b>(y,x)[0]=0;
                image.at<Vec3b>(y,x)[1]=0;
                image.at<Vec3b>(y,x)[2]=0;
            }
        }
    }

    imwrite("colorthr.jpg", image);

    return 0;
}