#include"Depthimage.h"

bool depthimage::InitialKinectV2() {
	HRESULT hr_;
	hr_ = GetDefaultKinectSensor(& kinectsensor);
	if (FAILED(hr_)) {
		ofLog(OF_LOG_ERROR, "Get Kinect sensor failed!");
		return false;
	}
	if (kinectsensor) {
		hr_ = kinectsensor->Open();
		IDepthFrameSource* depthframesource = nullptr;
		if (SUCCEEDED(hr_)) {
			hr_ = kinectsensor->get_DepthFrameSource(&depthframesource);
		}
		if (SUCCEEDED(hr_)) {
			hr_ = depthframesource->OpenReader(&depthframereader);
		}
		if (depthframesource != nullptr) {
			depthframesource->Release();
		}
	}
	if (!kinectsensor || FAILED(hr_)) {
		ofLog(OF_LOG_ERROR, "Initial failed!");
		return false;
	}
	else {
		return true;
	}
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

void depthimage::exit() {
	kinectsensor->Release();
	depthframereader->Release();
}

depthimage::depthimage() {
	if (!InitialKinectV2()) {
		std::cout << "error!!" << std::endl;
	}
}

depthimage::~depthimage() {
	exit();
}