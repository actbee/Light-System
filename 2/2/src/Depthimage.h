#pragma once
#include"ofMain.h"
#include<Kinect.h>
class depthimage {
public:
	depthimage();
	~depthimage();
	void exit();
	ofImage display;
	void UpdateKinectV2();

private:
	bool InitialKinectV2();
	IKinectSensor* kinectsensor;
	IDepthFrameReader* depthframereader;
};