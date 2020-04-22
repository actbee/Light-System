#include"Depthimage.h"

bool depthimage::InitialKinectV2() {
	bodyframereader = nullptr;
	BodyData = nullptr;
	iBodyCount = 0;
	bodyframesource = nullptr;
	kinectsensor = nullptr;


	if (GetDefaultKinectSensor(&kinectsensor) != S_OK) {
		std::cout << "can not get sensor" << std::endl;
		return false;
	}
	if (kinectsensor->Open() != S_OK) {
		std::cout << "can not open sensor" << std::endl;
		return false;
	}

	if (kinectsensor->get_BodyFrameSource(&bodyframesource) != S_OK) {
		std::cout << "cant get body frame source" << std::endl;
		return false;
	}
	if (bodyframesource->get_BodyCount(&iBodyCount) != S_OK) {
		std::cout << "can not get body count" << std::endl;
		return false;
	}
//	std::cout << "can trace" <<iBodyCount<< std::endl;
	BodyData = new IBody*[iBodyCount];
	for (int i = 0; i < iBodyCount; i++) {
		BodyData[i] = nullptr;
	}
	if (bodyframesource->OpenReader(&bodyframereader) != S_OK) {
		std::cout << "can not get body frame reader" << std::endl;
		return false;
	}
	bodyframesource->Release();
	bodyframesource = nullptr;
	return true;
}

void depthimage::UpdateKinectV2() {
	if (!depthframereader) {
		return;
	}
	HRESULT hr;
	IDepthFrame* depthframe = nullptr;
	hr = depthframereader->AcquireLatestFrame(&depthframe);
	if (SUCCEEDED(hr)) {
		UINT depthbuffersize = 0;
		UINT16* depthbuffer = nullptr;
		int depthwidth = 0;
		int depthheight = 0;
		USHORT usmindepth = 0;
		USHORT usmaxdepth = USHRT_MAX;

		IFrameDescription* depthframedescription = nullptr;
		depthframe->get_FrameDescription(&depthframedescription);
		depthframedescription->get_Width(&depthwidth);
		depthframedescription->get_Height(&depthheight);
		depthframe->get_DepthMinReliableDistance(&usmindepth);
		depthframe->get_DepthMaxReliableDistance(&usmaxdepth);
		depthframe->AccessUnderlyingBuffer(&depthbuffersize, &depthbuffer);

		ofPixels tmpdisplay;
		tmpdisplay.allocate(depthwidth, depthheight, ofImageType::OF_IMAGE_GRAYSCALE);
		unsigned char* acdisplay = tmpdisplay.getPixels();

		for (int i = 0; i < depthbuffersize; i++) {
			acdisplay[i] = 0xff * (float)depthbuffer[i] / usmaxdepth;
		}
		display.setFromPixels(acdisplay, depthwidth, depthheight, OF_IMAGE_GRAYSCALE);
		if (depthframe != nullptr) {
			depthframe->Release();
		}
	}
}

int depthimage::get_elbow_direction() {
	int direction = 0; //1 means left, 2 up, 3 right, 4 down
	
	IBodyFrame* bodyframe = nullptr;
	if (bodyframereader->AcquireLatestFrame(&bodyframe) == S_OK) {
		if (bodyframe->GetAndRefreshBodyData(iBodyCount, BodyData) == S_OK) {
			for (int i = 0; i < iBodyCount; i++) {
				IBody* body = BodyData[i];
				BOOLEAN track = false;
				if ((body->get_IsTracked(&track) == S_OK) && track) {
					Joint joints[JointType::JointType_Count];
					if (body->GetJoints(JointType::JointType_Count, joints) == S_OK) {
						float x1 = joints[JointType_ElbowRight].Position.X;
						float y1 = joints[JointType_ElbowRight].Position.Y;
						float x2 = joints[JointType_HandRight].Position.X;
						float y2 = joints[JointType_HandRight].Position.Y;
						if (x2 == x1) {
							goto jmp;
						}
						float k = (y2 - y1) / (x2 - x1);
						std::cout << "k is " << k << std::endl;
						if (k < 1.0&&k>=-1.0) {
							if (x2 > x1) {
								std::cout << "right" << std::endl;
								direction = 1;
							}
							else if (x2 < x1) {
								std::cout << "left" << std::endl;
								direction = 3;
							}
						}
						else {
jmp:
							if (y2 > y1) {
								std::cout << "up" << std::endl;
								direction = 2;
							}
							else if (y2 <= y1) {
								std::cout << "down" << std::endl;
								direction = 4;
							}
						}
					}
					else {
						std::cout << "can not read body data" << std::endl;
					}
				}
			}
		}
		else {
			std::cout << "can not update body frame" << std::endl;
		}
		bodyframe->Release();
	}
	/*else {
		std::cout << "can not read body frame" << std::endl;
	}
	std::cout << "finish update" << std::endl;*/
	return direction;
}

float depthimage::get_depth() {
	float depth = 0;
	IBodyFrame* bodyframe = nullptr;
	if (bodyframereader->AcquireLatestFrame(&bodyframe) == S_OK) {
		if (bodyframe->GetAndRefreshBodyData(iBodyCount, BodyData) == S_OK) {
			for (int i = 0; i < iBodyCount; i++) {
				IBody* body = BodyData[i];
				BOOLEAN track = false;
				if ((body->get_IsTracked(&track) == S_OK) && track) {
					Joint joints[JointType::JointType_Count];
					if (body->GetJoints(JointType::JointType_Count, joints) == S_OK) {
						depth = joints[JointType_Head].Position.X;
					}
					else {
						std::cout << "can not read body data" << std::endl;
					}
				}
			}
		}
		else {
			std::cout << "can not update body frame" << std::endl;
		}
		bodyframe->Release();
	}
	/*else {
		std::cout << "can not read body frame" << std::endl;
	}
	std::cout << "finish update" << std::endl;*/
	std::cout << "depth:" << depth << std::endl;
	return depth;
}

void depthimage::exit() {
	delete[] BodyData;
	bodyframereader->Release();
	bodyframereader = nullptr;
	depthframereader->Release();
	depthframereader = nullptr;
	
	kinectsensor->Close();
	kinectsensor->Release();
	
}

depthimage::depthimage() {
	if (!InitialKinectV2()) {
		std::cout << "error!!" << std::endl;
	}
}

depthimage::~depthimage() {
	exit();
}

