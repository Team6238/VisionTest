//#define _GLIBCXX_USE_CXX11_ABI 0
#include <Robot.h>
#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <vector>

static void VisionThread(){

	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
	camera.SetResolution(640, 480);
	cs::CvSink cvSink = CameraServer::GetInstance()->GetVideo();
	cs::CvSource outputStreamStd = CameraServer::GetInstance()->PutVideo("Raw", 640, 480);

	while(1) {
		cv::Mat source;
		cvSink.GrabFrame(source);
		outputStreamStd.PutFrame(source);
		if (!source.empty()){
			grip::TestPipeline gp;
			gp.Process(source);
			std::vector<cv::KeyPoint>* blobs = gp.GetFindBlobsOutput();
			std::cout << "blobs found: " << blobs->size() << " " ;
			for (unsigned int i = 0; i < blobs->size(); i++){
				float f = blobs->at(i).pt.x;
				std::cout << "blob: " << i << ", center x: " <<  f << " ";
			}
			std::cout << "\n";
			//cv::Mat mask = gp.GetMaskOutput();
			//outputStreamStd.PutFrame(mask);
		}
		Wait(1);
	}
}

void Robot::RobotInit(){
	std::thread visionThread(VisionThread);
	visionThread.detach();
}

/*
	 * This function is called once each time the robot enters Disabled mode.
	 * You can use it to reset any subsystem information you want to clear when
	 * the robot is disabled.
	 */


	/**
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to the
	 * chooser code above (like the commented example) or additional comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void Robot::AutonomousInit()  {

	}

	void Robot::AutonomousPeriodic()  {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit() {

	}

	void Robot::TeleopPeriodic()  {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestPeriodic() {

	}


START_ROBOT_CLASS(Robot)
