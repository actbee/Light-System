const int one[7][4] = {
	{0,0,1,0},
	{1,1,1,0},
	{0,0,1,0},
	{0,0,1,0},
	{0,0,1,0},
	{0,0,1,0},
	{1,1,1,1}
};

const int two[7][4] = {
	{1,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{1,1,1,1},
	{1,0,0,0},
	{1,0,0,0},
	{1,1,1,1}
};

const int three[7][4] = {
	{1,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{1,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{1,1,1,1}
};

const int four[7][4] = {
	{1,0,0,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{0,0,0,1}
};

const int five[7][4] = {
	{1,1,1,1},
	{1,0,0,0},
	{1,0,0,0},
	{1,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{1,1,1,1}
};

const int six[7][4] = {
	{1,1,1,1},
	{1,0,0,0},
	{1,0,0,0},
	{1,1,1,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,1,1,1}
};

const int seven[7][4] = {
	{1,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{0,0,0,1},
	{0,0,0,1},
	{0,0,0,1},
	{0,0,0,1}
};

const int eight[7][4] = {
	{1,1,1,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,1,1,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,1,1,1}
};

const int nine[7][4] = {
	{1,1,1,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,1,1,1},
	{0,0,0,1},
	{0,0,0,1},
	{1,1,1,1}
};


const int zero[7][4] = {
	{1,1,1,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,0,0,1},
	{1,1,1,1}
};

const int pixel_alien[11][16] = {
			{0,0,0,0,2,2,2,2,2,2,0,0,0,0,0},
			{0,0,0,2,0,0,0,0,0,0,2,0,0,0,0},
			{0,0,2,0,0,1,1,1,1,0,0,2,0,0,0},
			{0,0,2,0,1,1,1,1,1,1,0,2,0,0,0},
			{0,2,2,1,1,0,1,1,0,1,1,2,2,0,0},
			{0,2,2,1,1,0,1,1,0,1,1,2,2,0,0},
			{0,2,2,1,1,1,1,1,1,1,1,2,2,0,0},
			{0,0,2,0,1,1,1,1,1,1,0,2,0,0,0},
			{0,0,0,1,0,0,1,1,0,0,1,0,0,0,0},
			{0,0,0,1,0,1,0,0,1,0,1,0,0,0,0},
			{0,0,0,1,0,0,0,0,0,0,1,0,0,0,0},
};

const int pixel_alien_l[11][16] = {
	        {0,0,0,0,2,2,2,2,2,2,0,0,0,0,0},
			{0,0,0,2,0,0,0,0,0,0,2,0,0,0,0},
			{0,0,2,0,0,1,1,1,1,0,0,2,0,0,0},
			{0,0,2,0,1,1,1,1,1,1,0,2,0,0,0},
			{0,2,2,1,1,0,1,1,0,1,1,2,2,0,0},
			{0,2,2,1,1,0,1,1,0,1,1,2,2,0,0},
			{0,2,2,1,1,1,1,1,1,1,1,2,2,0,0},
			{0,0,2,0,1,1,1,1,1,1,0,2,0,0,0},
			{0,0,0,1,0,0,1,1,0,0,1,0,0,0,0},
			{0,0,0,1,0,1,0,0,1,0,1,0,0,0,0},
			{0,0,1,0,0,0,0,0,0,1,0,0,0,0,0},
};

const int pixel_alien_r[11][16] = {
	        {0,0,0,0,2,2,2,2,2,2,0,0,0,0,0},
			{0,0,0,2,0,0,0,0,0,0,2,0,0,0,0},
			{0,0,2,0,0,1,1,1,1,0,0,2,0,0,0},
			{0,0,2,0,1,1,1,1,1,1,0,2,0,0,0},
			{0,2,2,1,1,0,1,1,0,1,1,2,2,0,0},
			{0,2,2,1,1,0,1,1,0,1,1,2,2,0,0},
			{0,2,2,1,1,1,1,1,1,1,1,2,2,0,0},
			{0,0,2,0,1,1,1,1,1,1,0,2,0,0,0},
			{0,0,0,1,0,0,1,1,0,0,1,0,0,0,0},
			{0,0,0,1,0,1,0,0,1,0,1,0,0,0,0},
			{0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
};

const int pixel_fly_one[8][11] = {
	{0,0,1,0,0,0,0,0,1,0,0},
	{1,0,0,1,0,0,0,1,0,0,1},
	{1,0,1,1, 1,1, 1,1, 1,0,1},
	{1,1, 1,0,1,1, 1,0,1, 1,1},
	{1,1, 1, 1,1,1, 1,1,1, 1, 1},
    {0,1,1, 1,1,1, 1,1,1, 1,0},
    {0,0,1,0,0,0,0,0,1,0,0}, 
    {0,1,0,0,0,0,0,0,0,1,0}
};

const int pixel_fly_two[8][11] = {
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,0,1,0,0,0},
	{1,0,1,1, 1,1, 1,1, 1,0,1},
	{1,1, 1,0,1,1, 1,0,1, 1,1},
	{1,1, 1, 1,1,1, 1,1,1, 1, 1},
	{0,1,1, 1,1,1, 1,1,1, 1,0},
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,1,0,0,0,0,0,0,0,1,0}
};

const int pixel_fly_three[8][11] = {
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,0,1,0,0,0},
	{0,0,1,1, 1,1, 1,1, 1,0,0},
	{1,1, 1,0,1,1, 1,0,1, 1,1},
	{1,1, 1, 1,1,1, 1,1,1, 1, 1},
	{0,1,1, 1,1,1, 1,1,1, 1,0},
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,0,1,0,0,0,0,0,1,0,0}
};

const int pixel_fly_four[8][11] = {
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,0,1,0,0,0},
	{0,0,1,1, 1,1, 1,1, 1,0,0},
	{0,1, 1,0,1,1, 1,0,1, 1,0},
	{1,1, 1, 1,1,1, 1,1,1, 1, 1},
	{0,1,1, 1,1,1, 1,1,1, 1,0},
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,0,1,0,0,0}
};

const int pixel_fly_five[8][11] = {
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,0,1,0,0,0},
	{0,0,1,1, 1,1, 1,1, 1,0,0},
	{0,1, 1,0,1,1, 1,0,1, 1,0},
	{1,1, 1, 1,1,1, 1,1,1, 1, 1},
	{1,0,1, 1,1,1, 1,1,1, 0,1},
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,1,1,0,1,1,0,0,0}
};

const int pixel_fly_six[8][11] = {
	{0,0,1,0,0,0,0,0,1,0,0},
	{0,0,0,1,0,0,0,1,0,0,0},
	{0,0,1,1, 1,1, 1,1, 1,0,0},
	{0,1, 1,0,1,1, 1,0,1, 1,0},
	{1,1, 1, 1,1,1, 1,1,1, 1, 1},
	{1,0,1, 1,1,1, 1,1,1, 0,1},
	{1,0,1,0,0,0,0,0,1,0,1},
	{0,0,0,1,1,0,1,1,0,0,0}
};

const int pixel_bubble_1[9][9] = {
	{0,0,2,2,2,2,2,0,0},
    {0,2,2,2,2,2,2,2,0},
	{2,2,0,3,2,0,3,2,2},
	{2,2,0,0,2,0,0,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,0,2,2,2,0,2,2},
	{2,0,0,0,2,0,0,0,2}
};

const int pixel_bubble_2[9][9] = {
	{0,0,2,2,2,2,2,0,0},
	{0,2,2,2,2,2,2,2,0},
	{2,2,3,0,2,3,0,2,2},
	{2,2,0,0,2,0,0,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,0,2,2,2,0,2,2},
	{2,0,0,0,2,0,0,0,2}
};

const int pixel_bubble_3[9][9] = {
	{0,0,2,2,2,2,2,0,0},
	{0,2,2,2,2,2,2,2,0},
	{2,2,0,0,2,0,0,2,2},
	{2,2,3,0,2,3,0,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,0,2,2,2,0,2,2},
	{2,0,0,0,2,0,0,0,2}
};

const int pixel_bubble_4[9][9] = {
	{0,0,2,2,2,2,2,0,0},
	{0,2,2,2,2,2,2,2,0},
	{2,2,0,0,2,0,0,2,2},
	{2,2,0,3,2,0,3,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,2,2,2,2,2,2,2},
	{2,2,0,2,2,2,0,2,2},
	{2,0,0,0,2,0,0,0,2}
};

const int pixel_acaleph_1[8][8] = {
	{0,0,0,3,3,0,0,0},
	{0,0,3,3,3,3,0,0},
	{0,3,3,3,3,3,3,0},
	{3,3,0,3,3,0,3,3},
	{3,3,3,3,3,3,3,3},
	{0,0,3,0,0,3,0,0},
	{0,3,0,3,3,0,3,0},
	{3,0,3,0,0,3,0,3},
};

const int pixel_acaleph_2[8][8] = {
	{0,0,0,3,3,0,0,0},
	{0,0,3,3,3,3,0,0},
	{0,3,3,3,3,3,3,0},
	{3,3,0,3,3,0,3,3},
	{3,3,3,3,3,3,3,3},
	{0,0,3,0,0,3,0,0},
	{0,3,0,3,3,0,3,0},
	{0,3,0,0,0,0,3,0},
};

const int pixel_acaleph_3[8][8] = {
	{0,0,0,3,3,0,0,0},
	{0,0,3,3,3,3,0,0},
	{0,3,3,3,3,3,3,0},
	{3,3,0,3,3,0,3,3},
	{3,3,3,3,3,3,3,3},
	{0,0,3,0,0,3,0,0},
	{0,3,0,3,3,0,3,0},
	{0,0,3,0,0,3,0,0},
};

const int LR[10][15] = {
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
	{0,2,0,0,0,0,0,0,0,2,2,2,2,0,0},
	{0,2,0,0,0,0,0,0,0,2,0,0,0,2,0},
	{0,2,0,0,0,0,0,0,0,2,0,0,0,2,0},
	{0,2,0,0,0,0,0,0,0,2,2,2,2,0,0},
	{0,2,0,0,0,0,0,0,0,2,0,2,0,0,0},
	{0,2,0,0,0,0,0,0,0,2,0,0,2,0,0},
	{0,2,2,2,2,2,0,0,0,2,0,0,0,2,0},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
};







