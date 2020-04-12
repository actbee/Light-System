#include "ofApp.h"
extern const int one[5][4];

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
		mytarget.setup(random_x, random_y, YELLOW);
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
	mycircles[xx][yy].setcolor(WHITE);
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
	ofSetFrameRate(60);
	for (int x0 = 0; x0 < 15; x0++) {
		for (int y0 = 0; y0 < 10; y0++) {
			float x = (x0 + 1)*ofGetWidth() / 16;
			float y = (y0 + 1)*ofGetHeight() / 11;
			mycircles[x0][y0].setup(x, y);
		}
	}
	resetall();
}

//------------------------------------------------------------

void ofApp::resetall() {
	ofSetFrameRate(60);
	game_state = "START";
	score = 0;
	time = 0;
	mycharacter.reset();
	mysnack.setup(7, 5, 8, RED);
	int random_x = (int)ofRandom(0, 15);
	int random_y = (int)ofRandom(0, 10);
	while (mysnack.in_body(random_x, random_y) == true) {
		random_x = (int)ofRandom(0, 15);
		random_y = (int)ofRandom(0, 10);
	}
	mytarget.setup(random_x, random_y, YELLOW);
}


//--------------------------------------------------------------
void ofApp::update() {
	/*for (int i = 0; i < num_circles; i++) {
		mycircles[i].update();
	}*/
	if (game_state == "START")
	{
		check_snack_and_target();
	}
	else if (game_state == "OVER") {
		ofSetFrameRate(5);
		time += 1;
		ofPoint topright= mycharacter.get_topright();
		if (topright.x< 0) {
			resetall();
			game_state == "START";
		}
		else {
			mycharacter.move(ofPoint(15 - time, 2));
		}
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
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
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 4; j++) {
				if (mycharacter.words[i][j] == 1) {
					int posx = j + mycharacter.get_topleft().x;
					int posy = i + mycharacter.get_topleft().y;
					ofPoint add(posx, posy);
					select.push_back(add);
				}
			}
		}

		for (int x0 = 0; x0 < 15; x0++) {
			for (int y0 = 0; y0 < 10; y0++) {

				for (vector<ofPoint>::iterator it = select.begin(); it != select.end();it++) {    //to find if there is only circles under the view
					if((it->x==x0)&&(it->y==y0)){
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
			int oo[5][4];

			switch (score) {
			case 1:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = one[i][j];
					}
				}
				break;
			case 2:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = two[i][j];
					}
				}
				break;
			case 3:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = three[i][j];
					}
				}
				break;
			case 4:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = four[i][j];
					}
				}
				break;
			case 5:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = five[i][j];
					}
				}
				break;
			case 6:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = six[i][j];
					}
				}
				break;
			case 7:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = seven[i][j];
					}
				}
				break;
			case 8:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = eight[i][j];
					}
				}
				break;
			case 9:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = nine[i][j];
					}
				}
				break;
			default:
				for (int i = 0; i < 5; i++) {
					for (int j = 0; j < 4; j++) {
						oo[i][j] = zero[i][j];
					}
				}
				break;
			}
			mycharacter.change(oo, 5);
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
