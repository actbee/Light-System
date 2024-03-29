#include"Depthimage.h"

bool depthimage::InitialKinectV2() {
	bodyframereader = nullptr;
	BodyData = nullptr;
	iBodyCount = 0;
	bodyframesource = nullptr;
	kinectsensor = nullptr;
	maxdepth = 2;
	mindepth = 0;
	maxwidth= 0.6;

	depth = maxdepth;
	pos = 10;
	up_open = true;

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

void depthimage::detect_body() {

	depth = maxdepth;
	pos = 10;
	height = 10;
	up_open =true;

	IBodyFrame* bodyframe = nullptr;
	if (bodyframereader->AcquireLatestFrame(&bodyframe) == S_OK) {
		if (bodyframe->GetAndRefreshBodyData(iBodyCount, BodyData) == S_OK) {
			for (int i = 0; i < iBodyCount; i++) {
				IBody* body = BodyData[i];
				BOOLEAN track = false;
				if ((body->get_IsTracked(&track) == S_OK) && track) {
					Joint joints[JointType::JointType_Count];
					if (body->GetJoints(JointType::JointType_Count, joints) == S_OK) {
						float check_depth = joints[JointType_Head].Position.Z;
						float check_pos = joints[JointType_Head].Position.X;
						//		cout << check << " , " << pos << endl;
						if (check_depth > mindepth&&check_depth < maxdepth&&abs(check_pos) < maxwidth) {
							depth = check_depth;
							pos = check_pos;
							height= joints[JointType_Head].Position.Y;

							HandState left_hand;
							HandState right_hand;
							if (body->get_HandLeftState(&left_hand) == S_OK&&body->get_HandRightState(&right_hand)==S_OK) {
								//	cout << "check!!!" << endl;
								float head_y = joints[JointType_Head].Position.Y;
								float left_y = joints[JointType_HandLeft].Position.Y;
								float right_y = joints[JointType_HandRight].Position.Y;
								if ((left_hand == HandState_Closed && left_y > head_y)||(right_hand == HandState_Closed && right_y > head_y)) {
									up_open = false;
								}
							}
							else {
								cout << "wrong" << endl;
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
}

int depthimage::get_elbow_direction(string	words) {
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

						float check = joints[JointType_Head].Position.Z;
						float pos = joints[JointType_Head].Position.X;
						if(check>mindepth&&check<maxdepth&&abs(pos)<maxwidth){
							float x1, x2, y1, y2;
							if (words == "LEFT") {
								x1 = joints[JointType_ElbowLeft].Position.X;
								y1 = joints[JointType_ElbowLeft].Position.Y;
								x2 = joints[JointType_HandLeft].Position.X;
								y2 = joints[JointType_HandLeft].Position.Y;
							}
							else {
								x1 = joints[JointType_ElbowRight].Position.X;
								y1 = joints[JointType_ElbowRight].Position.Y;
								x2 = joints[JointType_HandRight].Position.X;
								y2 = joints[JointType_HandRight].Position.Y;
							}
							if (x2 == x1) {
								goto jmp;
							}
							float k = (y2 - y1) / (x2 - x1);
							//	std::cout << "k is " << k << std::endl;
							if (k < 1.0&&k >= -1.0) {
								if (x2 > x1) {
									//	std::cout << "right" << std::endl;
									direction = 1;
								}
								else if (x2 < x1) {
									//	std::cout << "left" << std::endl;
									direction = 3;
								}
							}
							else {
							jmp:
								if (y2 > y1) {
									//		std::cout << "up" << std::endl;
									direction = 2;
								}
								else if (y2 <= y1) {
									//		std::cout << "down" << std::endl;
									direction = 4;
								}
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
	return depth;
}

float depthimage::get_pos() {
	return pos;
}

string depthimage::choose_hand() {
	string hand="NO";
	IBodyFrame* bodyframe = nullptr;
	if (bodyframereader->AcquireLatestFrame(&bodyframe) == S_OK) {
		if (bodyframe->GetAndRefreshBodyData(iBodyCount, BodyData) == S_OK) {
			for (int i = 0; i < iBodyCount; i++) {
				IBody* body = BodyData[i];
				BOOLEAN track = false;
				if ((body->get_IsTracked(&track) == S_OK) && track) {
					Joint joints[JointType::JointType_Count];
					if (body->GetJoints(JointType::JointType_Count, joints) == S_OK) {

						float check = joints[JointType_Head].Position.Z;
						float pos = joints[JointType_Head].Position.X;
				//		cout << check << " , " << pos<< endl;
						if(check>mindepth&&check<maxdepth&&abs(pos)<maxwidth){
							float left_x1, left_x2, left_y1, left_y2;
							left_x1 = joints[JointType_ElbowLeft].Position.X;
							left_y1 = joints[JointType_ElbowLeft].Position.Y;
							left_x2 = joints[JointType_HandLeft].Position.X;
							left_y2 = joints[JointType_HandLeft].Position.Y;
							float right_x1, right_x2, right_y1, right_y2;
							right_x1 = joints[JointType_ElbowRight].Position.X;
							right_y1 = joints[JointType_ElbowRight].Position.Y;
							right_x2 = joints[JointType_HandRight].Position.X;
							right_y2 = joints[JointType_HandRight].Position.Y;

							if (left_x2 == left_x1) {
								goto left_jmp;
							}
							float left_k = (left_y2 - left_y1) / (left_x2 - left_x1);
							if (left_k < 1.0&&left_k >= -1.0) {
								hand = "LEFT";
							}
							else {
							left_jmp:
								if (left_y2 > left_y1) {
									hand = "LEFT";
								}
							}
							if (hand == "NO") {
								if (right_x2 == right_x1) {
									goto right_jmp;
								}
								float right_k = (right_y2 - right_y1) / (right_x2 - right_x1);
								if (right_k < 1.0&&right_k >= -1.0) {
									hand = "RIGHT";
								}
								else {
								right_jmp:
									if (right_y2 > right_y1) {
										hand = "RIGHT";
									}
								}
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
	return hand;
}

bool depthimage::openhand() {
	return up_open;
}

float depthimage::get_height() {
	return height;
}

void depthimage::exit() {
	delete[] BodyData;
	bodyframereader->Release();
	bodyframereader = nullptr;
	//depthframereader->Release();
	//depthframereader = nullptr;
	
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

