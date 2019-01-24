#include "cluster.h"
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>
#include <vector>

char charCheckForEscKey;

int main() {
	std::vector<point_3d> point_list;
	point_list.push_back(point_3d(230, 132, 4));
	point_list.push_back(point_3d(13, 23, 30));
	point_list.push_back(point_3d(24, 24, 24));
	point_list.push_back(point_3d(124, 20, 67));
	point_list.push_back(point_3d(120, 14, 60));
	point_list.push_back(point_3d(20, 20, 20));
	point_list.push_back(point_3d(200, 100, 3));
	point_list.push_back(point_3d(205, 131, 20));
	point_list.push_back(point_3d(25, 27, 13));
	point_list.push_back(point_3d(135, 17, 87));
	point_list.push_back(point_3d(110, 20, 75));
	point_list.push_back(point_3d(214, 112, 1));
	point_list.push_back(point_3d(213, 120, 8));
	point_list.push_back(point_3d(128, 14, 64));
	point_list.push_back(point_3d(36, 10, 35));


	for (int i = 0; i < 10; i++)
	{
		std::vector<std::vector<point_3d>> clusters = k_mean_3d(point_list, 3, 0, 255);
		print_clusters(clusters);
		std::cout << "FINISHED" << std::endl;
	}
}

//int main() {
//	cv::VideoCapture capture(0);
//	int height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
//	int width = capture.get(CV_CAP_PROP_FRAME_WIDTH);
//
//	/* Create the window */
//	cv::namedWindow("Rubix Solver", CV_WINDOW_AUTOSIZE);
//
//	/* Frame container */
//	cv::Mat frame;
//
//	/* Global loop */
//	while (charCheckForEscKey != 27)
//	{
//		/* Capture the frame from the webcam */
//		capture >> frame;
//		if (frame.empty())
//			break;
//
//		/* Show the result */
//		cv::imshow("Rubix Solver", frame);
//
//		/* Wait some milliseconds */
//		charCheckForEscKey = cv::waitKey(1);
//	}
//	return(0);
//}

