#include <stdio.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <opencv/cxcore.h>

using namespace cv;

int main() {
    Mat image = imread("mandrill.jpg", 1);

    Mat greyscale;
    cvtColor(image, greyscale, CV_BGR2GRAY);

    for (int y = 0; y < image.rows; y++){
        for (int x = 0; x < image.cols; x++) {
            uchar pixel = greyscale.at<uchar>(y, x);
            if (pixel > 130) {
                greyscale.at<uchar>(y, x) = 255;
            }
            else greyscale.at<uchar>(y, x) = 0;
        }
    }

    // threshold(image,greyscale, 127, 255, THRESH_BINARY);


    imwrite("mythr.jpg", greyscale);
    return 0;
}

