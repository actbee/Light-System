#pragma once
#include"ofMain.h"
#include<Kinect.h>
class depthimage {
public:
	void exit();
private:
	bool InitialKinectV2();
	void UpdateKinectV2();
	ofImage display;
	IKinectSensor* kinectsensor;
	IDepthFrameReader* depthframereader;
};