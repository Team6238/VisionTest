#ifndef VisionModule_H
#define VisionModule_H

#include <Commands/Subsystem.h>
#include <wpilib.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "Commands/TestPipeline.h"
#include <vector>

class VisionModule : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	cs::UsbCamera camera;
	cs::CvSink cvSink;
	cs::CvSource outputStreamStd;
	grip::TestPipeline gp;


public:
	VisionModule();
	void InitDefaultCommand();
	cv::Mat GetRawStream();
	float GetCenterX();
	void OutputRawStream();
};

#endif  // VisionModule_H
