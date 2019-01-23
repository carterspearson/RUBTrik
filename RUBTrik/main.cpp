#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<iostream>

char charCheckForEscKey;

int main() {
	cv::VideoCapture capture(0);
	int height = capture.get(CV_CAP_PROP_FRAME_HEIGHT);
	int width = capture.get(CV_CAP_PROP_FRAME_WIDTH);

	/* Create the window */
	cv::namedWindow("Rubix Solver", CV_WINDOW_AUTOSIZE);

	/* Frame container */
	cv::Mat frame;

	/* Global loop */
	while (charCheckForEscKey != 27)
	{
		/* Capture the frame from the webcam */
		capture >> frame;
		if (frame.empty())
			break;

		/* Show the result */
		cv::imshow("Rubix Solver", frame);

		/* Wait some milliseconds */
		charCheckForEscKey = cv::waitKey(1);
	}
	return(0);
}
