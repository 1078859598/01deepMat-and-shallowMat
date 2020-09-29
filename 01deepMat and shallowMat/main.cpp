#include <opencv2/opencv.hpp>
#include <iostream>

using namespace cv;
using namespace std;
int main()
{
	cv::Mat srcMat = imread("C:/Users/HS/Desktop/2.jpg");
	cv::Mat deepMat;
	cv::Mat shallowMat;
    
	shallowMat = srcMat;
	srcMat.copyTo(deepMat);


	int height = srcMat.rows;
	int width = srcMat.cols;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < width; i++)
		{
			uchar threshold = 100;
			uchar average = (srcMat.at<Vec3b>(j, i)[0] + srcMat.at<Vec3b>(j, i)[1] + srcMat.at<Vec3b>(j, i)[2]) / 3;
			if (average > threshold)
				average = 255;
			else
				average = 0;
			srcMat.at<Vec3b>(j, i)[0] = average;
			srcMat.at<Vec3b>(j, i)[1] = average;
			srcMat.at<Vec3b>(j, i)[2] = average;
		}
	}

	std::cout << "srcMat =" << std::endl;
	imshow("srcMat", srcMat);
	std::cout << "shallowMat =" << std::endl;
	imshow("shallowMat", shallowMat);
	std::cout << "deepMat =" << std::endl;
	imshow("deepMat", deepMat);
	waitKey(0);

	return 0;
}