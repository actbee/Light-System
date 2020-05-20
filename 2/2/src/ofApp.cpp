#include "ofApp.h"
#include"make_dll.h"
void ofApp::change_status(string new_status) {
	if (new_status == "START") {
		game_state = "START";
		ofSetFrameRate(60);

		score = 0;
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
		mytarget.setup(random_x, random_y, BLUE);
	//	hand = "RIGHT";
		/*
		string newchoose = myKinect.choose_hand();
		while(newchoose == "NO") {
			newchoose = myKinect.choose_hand();
		}
		cout << newchoose<<endl;
		hand = newchoose;
		*/
	}
	else if (new_status == "READY") {
		time = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				my_img[i][j] = BLACK;
			}
		}
		game_state = "READY";
		mypixels.changesize(1, 10, 15);
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				mypixels.setpixels(0, i, j,LR[i][j]);
			}
		}
		ofSetFrameRate(5);
		mypixels.settopleft(0, 0);
		mypixels.setboard(0, 0, 0, 0);
		mypixels.change_v(0, 0, 1);
	}
	else if (new_status == "FOLLOW") {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				my_img[i][j] = BLACK;
			}
		}
		game_state = "FOLLOW";
		ofSetFrameRate(10);
	}
	else if (new_status == "OVER") {
		game_state = "OVER";
		time = 0;
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
	else if (new_status == "TEST") {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			my_img[i][j] = BLACK;
		}
	}
	    game_state = "TEST";
		create_pixel_fly(mypixels);
		ofSetFrameRate(3);
		mypixels.settopleft(player_center.x,1);
		mypixels.setboard(2, 2, 3, 3);
		mypixels.change_v(0, 0,1);
}
	else if (new_status == "TEST2") {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			my_img[i][j] = BLACK;
		}
	}
	    game_state = "TEST2";
		create_pixel_alien(mypixels);
		ofSetFrameRate(3);
		mypixels.settopleft(player_center.x, 1);
		mypixels.setboard(0, 0, 2, 2);
		mypixels.change_v(0, 1, 1);
}
	else if (new_status == "TEST3") {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			my_img[i][j] = BLACK;
		}
	}
	    game_state = "TEST3";
	     create_pixel_bubble(mypixels);
		 ofSetFrameRate(3);
		 mypixels.settopleft(player_center.x,1);
		 mypixels.setboard(0, 0, 2, 2);
		 mypixels.change_v(0,0,1);
}
	else if (new_status == "TEST4") {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			my_img[i][j] = BLACK;
		}
	}
	   game_state = "TEST4";
	   create_pixel_acaleph(mypixels);
	   ofSetFrameRate(10);
	   mypixels.settopleft(player_center.x,1);
	   mypixels.setboard(1, 1, 2, 2);
	   mypixels.change_v(1, 0, 5);
}
	else if (new_status == "GAME OF LIFE") {
	   game_state = "GAME OF LIFE";
	   ofSetFrameRate(5);
     }
	else if (new_status == "WAVE") {
	  game_state = "WAVE";
	  for (int i = 0; i < 10; i++) {
		  for (int j = 0; j < 15; j++) {
			  int choice = j % 3;
			  if (choice == 0) {
				  my_img[i][j] = RED;
			  }
			  else if (choice == 1) {
				  my_img[i][j] = PURPLE;
			  }
			  else {
				  my_img[i][j] = BLUE;
			  }
		  }
	  }
	   ofSetFrameRate(5);
     }
}
//--------------------------------------------------------------

bool ofApp::body_info(int&row,int&col) {
	float pos = myKinect.get_pos();
	float height = myKinect.get_height();
	if (pos > 0.6&&pos != 10) {
		pos = 0.6;
	}
	else if (pos < -0.6) {
		pos = -0.6;
	}
	if (height > 0.4) {
		height = 0.4;
	}
	else if (height < -0.1) {
		height = -0.1;
	}
	if (pos != 10) {
		float remap_x = ofMap(pos, -0.6, 0.6, 0, 17);      //define the width of the check area
		float remap_y = ofMap(height, -0.1, 0.4, 9, 0);   //define the height of the check area
		col = (int)remap_x;
		row = (int)remap_y;
		if (col >14) col = 14;
		if (row >9) row = 9;
		return true;
	}
	else {
		return false;
	}
}

//--------------------------------------------------------------

void ofApp::send_messages() {
	string message;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				ofColor color = mycircles[j][i].getcolor();
				if (color == BLACK) {
					message += "0";
				}
				else if (color == RED) {
					message += "1";
				}
				else if (color == PURPLE) {
					message += "3";
				}
				else if (color == BLUE) {
					message += "2";
				}
			}
		}
	//	cout << message << endl;
		mysender.senddata(message);
}

//--------------------------------------------------------------

void ofApp::check_snack_and_target() {
	int sx = mysnack.get_head().x;
	int sy = mysnack.get_head().y;
	int tx = mytarget.get_x();
	int ty = mytarget.get_y();
	if (sx == tx && sy == ty) {
	//	cout << "eat one! " << endl;
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
	for (int x0 = 0; x0 < 15; x0++) {
		for (int y0 = 0; y0 < 10; y0++) {
			float x = (x0 + 1)*ofGetWidth() / 16;
			float y = (y0 + 1)*ofGetHeight() / 11;
			mycircles[x0][y0].setup(x, y);
		}
	}
	hand = "LEFT";
	open = true;
	player_center =ofPoint (7, 5);
	change_status("READY");
//	create_pixel_fly();
}


//--------------------------------------------------------------
void ofApp::update() {
	/*for (int i = 0; i < num_circles; i++) {
		mycircles[i].update();
	}*/
	//myKinect.UpdateKinectV2();

	if (game_state == "START")
	{
		if (mysnack.dead() != true) {
			if (score < 2) {
				ofSetFrameRate(3);
			}
			else if (score < 9) {
				ofSetFrameRate(6);
			}
			else if (score < 12) {
				ofSetFrameRate(9);
			}
			else if (score < 15) {
				ofSetFrameRate(12);
			}
			else {
				ofSetFrameRate(15);
			}
			int control = myKinect.get_elbow_direction(hand);
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
			/*change_status("OVER");
			update();*/
		}
		else {
			ofSetFrameRate(5);
			time++;
			if (time > 5) {
				mysnack.sublength();
				if (mysnack.getlength() == 0) {
					change_status("OVER");
					update();
					return;
				}
			}
		}
	}
	else if (game_state == "READY") {
		if (time > 7) {
			change_status("START");
			return;
		}
		string newchoose = myKinect.choose_hand();
		if (newchoose == "NO") {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 15; j++) {
					int check = mypixels.getposition(0, j, i);
					if (check == 0) {
						my_img[i][j] = BLACK;
					}
					else if (check == 2) {
						my_img[i][j] = RED;
					}
				}
			}
			time = 0;
		}
		else if (newchoose == hand) {
			int i;
			for (i = 0; i < 10 - (time + 1); i++) {
				for (int j = 0; j < 15; j++) {
					int check = mypixels.getposition(0, j, i);
					if (check == 0) {
						my_img[i][j] = BLACK;
					}
					else if (check == 2) {
						my_img[i][j] = RED;
					}
				}
			}
			for (; i < 10; i++) {
				for (int j = 0; j < 15; j++) {
					int check = mypixels.getposition(0, j, i);
					if (check == 0) {
						my_img[i][j] = BLACK;
					}
					else if (check == 2) {
						if (hand == "LEFT") {
							if (j < 6) {
								my_img[i][j] = BLUE;
							}
							else {
								my_img[i][j] = RED;
							}
						}
						else {
							if (j < 6) {
								my_img[i][j] = RED;
							}
							else {
								my_img[i][j] = BLUE;
							}
						}
					}
				}
			}
			time++;
		}
		else {
			time = 0;
		}
		hand = newchoose;
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

			int random = (int)ofRandom(0, 4);
			switch (random) {
			case 0:
				change_status("TEST");
				break;
			case 1:
				change_status("TEST2");
				break;
			case 2:
				change_status("TEST3");
				break;
			case 3:
				change_status("TEST4");
				break;
			}
		}
	}
	else if (game_state == "FOLLOW") {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 15; j++) {
			my_img[i][j] = BLACK;
		}
	}
	int row = 0;
	int col = 0;
	myKinect.detect_body();
	bool track = body_info(row, col);
	if (track == true) {
		my_img[row][col] = RED;
	}
		else {
			my_img[5][7] = RED;
		}
	}
	else if (game_state == "TEST" || game_state == "TEST2" || game_state == "TEST3" || game_state == "TEST4") {

	   int row = 0;
	   int col = 0;
	   myKinect.detect_body();
	   bool track = body_info(row, col);
		bool open_hand = myKinect.openhand();
		float point = myKinect.get_depth();

		if (point < 1.25) {
			open = true;
			change_status("READY");
			cout << "start game" << endl;
			return;
		}

		if (open == true && open_hand == false) {
			open = open_hand;
			change_status("GAME OF LIFE");
			return;
		}
		open = open_hand;
	refresh:
		time += 1;
		int timemax = mypixels.gettimeflow();
		if (time > 2 * timemax) {
			time = 1;
		}
		int t;
		if (time <= timemax) {
			t = time - 1;
		}
		else if (time > timemax) {
			t = 2 * timemax - time;
		}
		// next is the attract part
		if (track==true) {
			player_center = ofPoint(col, row);
			ofPoint center = mypixels.center();
			int direction = col - center.x;
			if (direction > 0) {
				mypixels.move_right();
			}
			else if (direction < 0) {
				mypixels.move_left();
			}
		}
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
				else if (check == 2) {
					my_img[i][j] = RED;
				}
				else if (check == 3) {
					my_img[i][j] = BLUE;
				}
			}
		}


	}
	else if (game_state == "GAME OF LIFE") {
	   int row = 0;
	   int col = 0;
	   myKinect.detect_body();
	   bool track = body_info(row, col);
		bool open_hand = myKinect.openhand();
		float point = myKinect.get_depth();
		if (point < 1.25) {
			open = true;
			change_status("READY");
			cout << "start game" << endl;
			return;
		}

		if (open_hand == false && open == true) {
			open = open_hand;
			//open = false;
			int random = (int)ofRandom(0, 4);
			switch (random) {
			case 0:
				change_status("TEST");
				break;
			case 1:
				change_status("TEST2");
				break;
			case 2:
				change_status("TEST3");
				break;
			case 3:
				change_status("TEST4");
				break;
			}
		//	update();
			goto refresh;   //not a very good way, but fine, needs to improve here!
			return;
		}
		open = open_hand;


		int check[10][15];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				check[i][j] = 0;
			}
		}
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				int ysub = i - 1;
				int yadd = i + 1;
				int xsub = j - 1;
				int xadd = j + 1;
				if (ysub >= 0 && xsub >= 0) {
					if (my_img[ysub][xsub] != BLACK) {
						check[i][j]++;
					}
				}
				if (ysub >= 0) {
					if (my_img[ysub][j] != BLACK) {
						check[i][j]++;
					}
				}
				if (xadd < 15 && ysub >= 0) {
					if (my_img[ysub][xadd] != BLACK) {
						check[i][j]++;
					}
				}
				if (xsub >= 0) {
					if (my_img[i][xsub] != BLACK) {
						check[i][j]++;
					}
				}
				if (xadd < 15) {
					if (my_img[i][xadd] != BLACK) {
						check[i][j]++;
					}
				}
				if (xsub >= 0 && yadd < 10) {
					if (my_img[yadd][xsub] != BLACK) {
						check[i][j]++;
					}
				}
				if (yadd < 10) {
					if (my_img[yadd][j] != BLACK) {
						check[i][j]++;
					}
				}
				if (xadd < 15 && yadd < 10) {
					if (my_img[yadd][xadd] != BLACK) {
						check[i][j]++;
					}
				}
			}
		}
		bool no = true;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 15; j++) {
				if (check[i][j] == 3) {
					my_img[i][j] = PURPLE;
					no = false;
				}
				else if (check[i][j] < 2 || check[i][j] >= 4) {
					my_img[i][j] = BLACK;
				}
			}
		}

		if (track == true) {
			player_center = ofPoint(col, row);
			int blue_max = (int)ofRandom(2, 5);
			for (int i = 0; i < blue_max; i++) {
				int x_min = col - 2;
				int x_max = col + 2;
				int y_min = row - 2;
				int y_max = row + 2;
				if (x_min < 0) x_min = 0;
				if (x_max > 14) x_max = 14;
				if (y_min < 0) y_min = 0;
				if (y_max > 9) y_max = 9;

				int random_col = (int)ofRandom(x_min, x_max);
				int random_row = (int)ofRandom(y_min, y_max);
				my_img[random_row][random_col] = BLUE;
			}


		}
		else {
			int blue_max = (int)ofRandom(2, 5);
			for (int i = 0; i < blue_max; i++) {
				int random_col = (int)ofRandom(2, 13);
				int random_row = (int)ofRandom(1, 8);
				my_img[random_row][random_col] = BLUE;
			}
		}

		for (int i = 0; i < 3; i++) {
			int lucky_col = (int)ofRandom(0, 15);
			int lucky_row = (int)ofRandom(0, 10);
			my_img[lucky_row][0] = BLACK;
			my_img[0][lucky_col] = BLACK;
		}
		for (int i = 0; i < 3; i++) {
			int lucky_col = (int)ofRandom(0, 15);
			int lucky_row = (int)ofRandom(0, 10);
			my_img[lucky_row][14] = BLACK;
			my_img[9][lucky_col] = BLACK;
		}
		if (no == true) {
			for (int i = 0; i < 10; i++) {
				int random_col = (int)ofRandom(2, 13);
				int random_row = (int)ofRandom(1, 8);
				my_img[random_row][random_col] = PURPLE;
			}
		}
	}
	else if (game_state == "WAVE") {

		myKinect.detect_body();
		int row = 0;
		int col = 0;
		bool track = body_info(row, col);
		if (track ==true) {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < col; j++) {
					my_img[i][j] = BLUE;
				}
			}
			for (int i = 0; i < 10; i++) {
					for (int j = col; j < 15; j++) {
						my_img[i][j] = PURPLE;
					}
				}
			}

		else {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 15; j++) {
					int choice = j % 3;
					if (choice == 0) {
						my_img[i][j] = RED;
					}
					else if (choice == 1) {
						my_img[i][j] = PURPLE;
					}
					else {
						my_img[i][j] = BLUE;
					}
				}
			}
		}
	}

}

//--------------------------------------------------------------
void ofApp::draw(){
	//myKinect.display.draw(0,0);
	
	send_messages();
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
	else if (game_state == "FOLLOW"||game_state=="GAME OF LIFE"||game_state=="WAVE") {
		for (int x0 = 0; x0 < 15; x0++) {
			for (int y0 = 0; y0 < 10; y0++) {
				mycircles[x0][y0].setcolor(my_img[y0][x0]);
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
	else if (game_state=="READY"||game_state == "TEST"||game_state=="TEST2"||game_state=="TEST3"||game_state=="TEST4") {
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
		if (mysnack.dead() == true) {
			return;
		}
		else if (key == OF_KEY_LEFT) {
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
		//cout << "now head is : " << mysnack.get_head().x << " , " << mysnack.get_head().y << endl;
		
	}
	else {
		change_status("START");
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
//--------------------------------------------------------------
ofApp::~ofApp() {
	mysender.~sender();
	myKinect.~depthimage();
}
