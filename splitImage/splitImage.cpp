#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>  
#include<string>

//Cut an image into 2 patch
void splitImage(cv::Mat binocular_image, std::vector<cv::Mat>& monocular_image)
{
	int rows = binocular_image.rows;
	int cols = binocular_image.cols / 2;

	for (int j = 0; j < 2; j++)
	{
		//Roi means "region of interest" algorithm
		cv::Mat roi;
		cv::Rect rect(j * cols, 0 * rows, cols, rows);
		binocular_image(rect).copyTo(roi);
		monocular_image.push_back(roi);
	}
}

int main()
{

	cv::Mat image = cv::imread("C://Users//14309//Desktop//openCV///20.jpg", 1);
	cv::imshow("stereo_image", image);

	std::vector<cv::Mat> imageList;
	splitImage(image, imageList);

	imshow("roi_imageL", imageList[0]);
	imshow("roi_imageR", imageList[1]);
	imwrite("C://Users//14309//Desktop//openCV///R9.jpg", imageList[0]);
	imwrite("C://Users//14309//Desktop//openCV///L9.jpg", imageList[1]);
	imageList.clear();
	cvWaitKey(0);

	return 0;
}