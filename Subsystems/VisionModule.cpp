#include "VisionModule.h"
#include "Commands/TeleopStream.h"


VisionModule::VisionModule() : Subsystem("VisionModule") {
	camera = CameraServer::GetInstance()->StartAutomaticCapture();
	camera.SetResolution(640, 480);
	cvSink = CameraServer::GetInstance()->GetVideo();
	outputStreamStd = CameraServer::GetInstance()->PutVideo("Raw", 640, 480);
}

void VisionModule::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleopStream());
}

cv::Mat VisionModule::GetRawStream(){
	cv::Mat source;
	cvSink.GrabFrame(source);
	return source;
}

void VisionModule::OutputRawStream(){
	cv::Mat source = GetRawStream();
	outputStreamStd.PutFrame(source);
}

float VisionModule::GetCenterX(){
	cv::Mat source = GetRawStream();
	if (!source.empty()){
		gp.Process(source);
		std::vector<cv::KeyPoint>* blobs = gp.GetFindBlobsOutput();
		if (blobs->size()==1)
			return blobs->at(0).pt.x;
	}
	return -1;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
