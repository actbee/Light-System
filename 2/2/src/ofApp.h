#pragma once

#include "ofMain.h"
#include"circle.h"
#include"snack.h"
#include"target.h"

//#define num_circles 150
const ofColor BLACK(0, 0, 0);
const ofColor WHITE(255, 255, 255);
const ofColor RED(255, 1, 52);
const ofColor YELLOW(250, 240, 20);
const ofColor GREEN(2, 233, 3);

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		void draw_snack();
		void draw_target();
		void beback();
		void check_snack_and_target();

		circle mycircles[15][10];
		snack mysnack;
		target mytarget;

		//game system

		int score;
		string game_state;
		void resetall();


};
