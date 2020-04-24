#include "ofApp.h"

void ofApp::create_pixel_fly() {
	mypixels.changesize(6, 8, 11);
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(0, i, j, pixel_fly_one[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(1, i, j, pixel_fly_two[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(2, i, j, pixel_fly_three[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(3, i, j, pixel_fly_four[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(4, i, j, pixel_fly_five[i][j]);
		}
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 11; j++) {
			mypixels.setpixels(5, i, j, pixel_fly_six[i][j]);
		}
	}
}

//--------------------------------------------------------------
void ofApp::check_snack_and_target() {
	int sx = mysnack.get_head().x;
	int sy = mysnack.get_head().y;
	int tx = mytarget.get_x();
	int ty = mytarget.get_y();
	if (sx == tx && sy == ty) {
		cout << "eat one! " << endl;
		mysnack.addlength();
		score += 1;
		int random_x = (int)ofRandom(0, 15);
		int random_y = (int)ofRandom(0, 10);
		while (mysnack.in_body(random_x, random_y) == true) {
			random_x = (int)ofRandom(0, 15);
			random_y = (int)ofRandom(0, 10);
		}
		mytarget.setup(random_x, random_y, BLUE);
	}
}

//--------------------------------------------------------------
void ofApp::beback() {
	for (int x0 = 0; x0 < 15; x0++) {
		for (int y0 = 0; y0 < 10; y0++) {
			mycircles[x0][y0].setcolor(BLACK);
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw_snack() {
	ofColor color = mysnack.getcolor();
	for(int i=0;i<mysnack.getlength();i++){
	  int posx = mysnack.body.front().x;
	  int posy = mysnack.body.front().y;
	  mycircles[posx][posy].setcolor(color);
	  mysnack.body.push(mysnack.body.front());
	  mysnack.body.pop();
	}
	int xx = mysnack.get_head().x;
	int yy = mysnack.get_head().y;
	mycircles[xx][yy].setcolor(RED);
}

//--------------------------------------------------------------

void ofApp::draw_target() {
	ofColor color = mytarget.get_color();
	int posx = mytarget.get_x();
	int posy = mytarget.get_y();
	mycircles[posx][posy].setcolor(color);
}

//--------------------------------------------------------------
void ofApp::setup(){
	game_state = "TEST";
	for (int x0 = 0; x0 < 15; x0++) {
		for (int y0 = 0; y0 < 10; y0++) {
			float x = (x0 + 1)*ofGetWidth() / 16;
			float y = (y0 + 1)*ofGetHeight() / 11;
			mycircles[x0][y0].setup(x, y);
		}
	}
	resetall();
	create_pixel_fly();
}

//------------------------------------------------------------

void ofApp::resetall() {
	ofSetFrameRate(60);

	score =0;
	time = 0;

	mycharacters.clear();
	character my_character;
	my_character.reset();
	mycharacters.push_back(my_character);

	mysnack.setup(7, 5, 8, PURPLE);
	int random_x = (int)ofRandom(0, 15);
	int random_y = (int)ofRandom(0, 10);
	while (mysnack.in_body(random_x, random_y) == true) {
		random_x = (int)ofRandom(0, 15);
		random_y = (int)ofRandom(0, 10);
	}
	mytarget.setup(random_x, random_y,BLUE);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			my_img[i][j] =BLACK;
		}
	}
}


//--------------------------------------------------------------
void ofApp::update() {
	/*for (int i = 0; i < num_circles; i++) {
		mycircles[i].update();
	}*/
	//myKinect.UpdateKinectV2();

	if (game_state == "START")
	{
		if (score < 3) {
			ofSetFrameRate(3);
		}
		else if (score < 6) {
			ofSetFrameRate(6);
		}
		else if (score < 9) {
			ofSetFrameRate(9);
		}
		else if (score < 12) {
			ofSetFrameRate(12);
		}
		else {
			ofSetFrameRate(15);
		}
		int control=myKinect.get_elbow_direction();
		//cout << control << endl;
		//control = 1;
		switch (control) {
		case 1:
			keyPressed(OF_KEY_RIGHT);
			break;
		case 2:
			keyPressed(OF_KEY_UP);
			break;
		case 3:
			keyPressed(OF_KEY_LEFT);
			break;
		case 4:
			keyPressed(OF_KEY_DOWN);
			break;
		}

		check_snack_and_target();
	}
	else if (game_state == "OVER") {
		ofSetFrameRate(5);
		time += 1;
		int before = 0;
		for (vector<character>::iterator iter = mycharacters.begin(); iter != mycharacters.end(); iter++) {
			iter->move(ofPoint(15 - time + before * 5, 2));
			before++;
		}
		ofPoint topright = mycharacters.back().get_topright();
		if (topright.x < 0) {
		//	resetall();
			game_state = "TEST";
		}
	}
	/*else if (game_state == "TEST") {
		ofSetFrameRate(3);
		time += 1;
		time = time % 18;
		int move = time - 4;
		if (move > 4) {
			move = 9 - move;
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				my_img[i][j] = BLACK;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				if (i + move < 11 && i + move >= 0) {
					int num;
					if (time % 6 == 0 || time % 6 == 2 || time % 6 == 4 || time % 6 == 5) {
						num = pixel_alien[i + move][j];
					}
					else if (time % 6 == 1) {
						num = pixel_alien_l[i + move][j];
					}
					else if (time % 6 == 3) {
						num = pixel_alien_r[i + move][j];
					}
					switch (num) {
					case 0: {
						my_img[i][j] = BLACK;
						break;
					}
					case 1: {
						my_img[i][j] = RED;
						break;
					}
					case 2: {
						my_img[i][j] = PURPLE;
						break;
					}
					default: {
						cout << "something is wrong!" << endl;
					}
					}
				}
			}
		}
	}  */
	else if (game_state == "TEST") {
		ofSetFrameRate(3);
		time += 1;
		if (time > 10) {
			time = 1;
		}
		int time0 = 11 - time;
		int t;
		if (time0 > time) {
			t = time;
		}
		else {
			t = time0;
		}
		mypixels.setboard(2, 2, 1, 1);
		mypixels.change_v(1, 1);
		mypixels.update();
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				int check = mypixels.getposition(t, j, i);
				if (check == 0) {
					my_img[i][j] = BLACK;
				}
				else if (check == 1) {
					my_img[i][j] = PURPLE;
				}
			}
		}
		/*
		for (int i = 1; i < 9; i++) {
			for (int j = 3; j < 14; j++) {
				int num=0;
				if (time == 1 || time == 12) {
					num = mypixels.getpixels(0,i-1,j-3);
				}
				else if (time == 2 || time == 11) {
					num = mypixels.getpixels(1, i - 1, j - 3);
				}
				else if (time == 3|| time == 10) {
					num = mypixels.getpixels(2, i - 1, j - 3);
				}
				else if (time == 4 || time == 9) {
					 num = mypixels.getpixels(3, i - 1, j - 3);
				}
				else if (time == 5 || time == 8) {
					 num = mypixels.getpixels(4, i - 1, j - 3);
				}
				else if (time == 6 || time == 7) {
					num = mypixels.getpixels(5, i - 1, j - 3);
				}
				switch (num) {
				case 0: {
					my_img[i][j] = BLACK;
					break;
				}
				case 1: {
					my_img[i][j] = PURPLE;
					break;
				}
				default: {
					cout << "something is wrong!" << endl;
				}
				}
			}
		}
		*/

		float point = myKinect.get_depth();
		if (point > 0.2) {
			resetall();
			game_state = "START";
			cout << "start game" << endl;
		}
	} 

	
}

//--------------------------------------------------------------
void ofApp::draw(){
	//myKinect.display.draw(0,0);
	
	ofBackground(50);
	ofSetColor(255);
	ofFill();
	beback();
	if (game_state == "START") {
		draw_target();
		draw_snack();
		for (int x0 = 0; x0 < 15; x0++) {
			for (int y0 = 0; y0 < 10; y0++) {
				mycircles[x0][y0].draw();
			}
		}
	}
	else if (game_state == "OVER") {
		vector<ofPoint> select;
		for (vector<character>::iterator iter = mycharacters.begin(); iter != mycharacters.end(); iter++) {
			for (int i = 0; i < 7; i++) {
				for (int j = 0; j < 4; j++) {
					if (iter->words[i][j] == 1) {
						int posx = j + iter->get_topleft().x;
						int posy = i + iter->get_topleft().y;
						ofPoint add(posx, posy);
						select.push_back(add);
					}
				}
			}

			for (int x0 = 0; x0 < 15; x0++) {
				for (int y0 = 0; y0 < 10; y0++) {

					for (vector<ofPoint>::iterator it = select.begin(); it != select.end(); it++) {    //to find if there is only circles under the view
						if ((it->x == x0) && (it->y == y0)) {
							mycircles[x0][y0].setcolor(BLACK);
							goto dp;
						}
					}
					mycircles[x0][y0].setcolor(RED);
				dp:
					mycircles[x0][y0].draw();

				}
			}
		}
	}
	else if (game_state == "TEST") {
		for (int x0 = 0; x0 < 15; x0++) {
			for (int y0 = 0; y0 < 10; y0++) {
				mycircles[x0][y0].setcolor(my_img[y0][x0]);
				mycircles[x0][y0].draw();
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (game_state == "START") {
		if (key == OF_KEY_LEFT) {
			int nextx = mysnack.get_head().x - 1;
			if (nextx == -1) {
				mysnack.add(14, 0);
			}
			else {
				mysnack.add(-1, 0);
			}
		}
		else if (key == OF_KEY_RIGHT) {
			int nextx = mysnack.get_head().x + 1;
			if (nextx == 15) {
				mysnack.add(-14, 0);
			}
			else {
				mysnack.add(1, 0);
			}
		}
		else if (key == OF_KEY_UP) {
			int nexty = mysnack.get_head().y - 1;
			if (nexty == -1) {
				mysnack.add(0, 9);
			}
			else {
				mysnack.add(0, -1);
			}
		}
		else if (key == OF_KEY_DOWN) {
			int nexty = mysnack.get_head().y + 1;
			if (nexty == 10) {
				mysnack.add(0, -9);
			}
			else {
				mysnack.add(0, 1);
			}
		}
		cout << "now head is : " << mysnack.get_head().x << " , " << mysnack.get_head().y << endl;
		if (mysnack.dead() == true) {
			game_state = "OVER";
			cout << "your score is: " << score << endl;
			mycharacters.clear();
			int oo[7][4];
			if (score == 0) {
				character my_character;
				for (int i = 0; i < 7; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = zero[i][j];
					}
				}
				my_character.change(oo, 7);
				mycharacters.push_back(my_character);
			}
			else {
				stack<int> numbers;
				int myscore = score;
				while (myscore != 0) {
					int wei = myscore % 10;
					numbers.push(wei);
					myscore /= 10;
				}
				while (numbers.size() != 0) {
					int number = numbers.top();
					numbers.pop();
					switch (number) {
					case 1:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = one[i][j];
							}
						}
						break;
					case 2:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = two[i][j];
							}
						}
						break;
					case 3:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = three[i][j];
							}
						}
						break;
					case 4:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = four[i][j];
							}
						}
						break;
					case 5:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = five[i][j];
							}
						}
						break;
					case 6:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = six[i][j];
							}
						}
						break;
					case 7:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = seven[i][j];
							}
						}
						break;
					case 8:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = eight[i][j];
							}
						}
						break;
					case 9:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = nine[i][j];
							}
						}
						break;
					default:
						for (int i = 0; i < 7; i++) {
							for (int j = 0; j < 4; j++) {
								oo[i][j] = zero[i][j];
							}
						}
						break;
					}
					character my_character;
					my_character.change(oo, 7);
					mycharacters.push_back(my_character);
				}
			}
		}
	}
	else if (game_state == "OVER") {
		resetall();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == 0) {
		cout << "mouse: " << x << "," << y << endl;
		for (int x0 = 0; x0 < 15; x0++) {
			for (int y0 = 0; y0 < 10; y0++) {
				if (abs(x -mycircles[x0][y0].getx()) <= mycircles[x0][y0].getdim() && abs(y - mycircles[x0][y0].gety()) <= mycircles[x0][y0].getdim()) {
					ofColor current = mycircles[x0][y0].getcolor();
					if(current== BLACK){
						mycircles[x0][y0].setcolor(RED);
					}
					else if (current == RED) {
						mycircles[x0][y0].setcolor(YELLOW);
					}
					else if (current == YELLOW) {
						mycircles[x0][y0].setcolor(GREEN);
					}
					else if (current == GREEN) {
						mycircles[x0][y0].setcolor(BLACK);
					}
					else {
						cout << "something is wrong!" << endl;
						mycircles[x0][y0].setcolor(BLACK);
					}
				}
			}
		}
	}
	else if (button == 2) {
		for (int x0 = 0; x0 < 15; x0++) {
			for (int y0 = 0; y0 < 10; y0++) {
				mycircles[x0][y0].setcolor(BLACK);
			}
		}
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
