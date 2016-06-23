#pragma once
class CpenStyle
{
public:
	CpenStyle();
	~CpenStyle();
	int shape;
	int pen_weight;
	int pen_style;
	int color_R, color_G, color_B;
private:

};

CpenStyle::CpenStyle()
{
	shape = 1;
	pen_style = 1;
	pen_weight = 1;
	color_R = 0;
	color_G = 0;
	color_B = 0;
}

CpenStyle::~CpenStyle()
{
}