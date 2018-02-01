#pragma once
#include "vision/VisionPipeline.h"

#include <opencv2/objdetect/objdetect.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/features2d.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <vector>
#include <string>
#include <math.h>

namespace grip {

/**
* TestPipeline class.
* 
* An OpenCV pipeline generated by GRIP.
*/
class TestPipeline : public frc::VisionPipeline {
	private:
		cv::Mat cvResizeOutput;
		cv::Mat hsvThresholdOutput;
		cv::Mat cvErodeOutput;
		cv::Mat maskOutput;
		std::vector<cv::KeyPoint> findBlobsOutput;
		void cvResize(cv::Mat &, cv::Size &, double , double , int , cv::Mat &);
		void hsvThreshold(cv::Mat &, double [], double [], double [], cv::Mat &);
		void cvErode(cv::Mat &, cv::Mat &, cv::Point &, double , int , cv::Scalar &, cv::Mat &);
		void mask(cv::Mat &, cv::Mat &, cv::Mat &);
		void findBlobs(cv::Mat &, double , double [], bool , std::vector<cv::KeyPoint> &);

	public:
		TestPipeline();
		void Process(cv::Mat& source0) override;
		cv::Mat* GetCvResizeOutput();
		cv::Mat* GetHsvThresholdOutput();
		cv::Mat* GetCvErodeOutput();
		cv::Mat* GetMaskOutput();
		std::vector<cv::KeyPoint>* GetFindBlobsOutput();
};


} // end namespace grip


