// v.1.0.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
// v.1.0.cpp : Defines the entry point for the console application.
//


#include "stdafx.h"
#include "opencv/highgui.h"
#include <opencv/cv.h>
#include "opencv2/highgui/highgui.hpp" 
#include "stdio.h"

int g_thresh = 100;


int _tmain(int argc, _TCHAR* argv[])
{
    
    CvCapture* kameraku;
	kameraku=cvCreateCameraCapture(1);
    assert(kameraku!=NULL);
    IplImage* framemurah;//=cvQueryFrame(kameraku);
    IplImage* framegray;//=cvCreateImage(cvSize( framemurah->width, framemurah->height ), IPL_DEPTH_8U, 1 );
	//cvCvtColor(framemurah,framegray,CV_RGB2GRAY );

    
    while(1){
        framemurah=cvQueryFrame(kameraku);
        //if(!framemurah) break;
		cvNamedWindow("Kamera1", CV_WINDOW_AUTOSIZE);
        cvShowImage("Kamera1", framemurah);
        char c = cvWaitKey(33);


		framegray=cvCreateImage(cvSize( framemurah->width, framemurah->height ), IPL_DEPTH_8U, 1 );
		cvCvtColor(framemurah,framegray,CV_RGB2GRAY);//konvert RGB to Gray
		//cvThreshold(framemurah,framegray, g_thresh, 255, CV_THRESH_BINARY);
		cvThreshold(framegray,framegray, 50, 255, CV_THRESH_BINARY);
		cvNamedWindow("Kamera2", CV_WINDOW_AUTOSIZE);
		cvShowImage("Kamera2", framegray);
		char v = cvWaitKey(33);
        //if(c==27) break;
    }
    cvReleaseCapture(&kameraku);
    cvDestroyWindow("Kamera1");
	cvDestroyWindow("Kamera2");
}