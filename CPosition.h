#pragma once
class CPosition
{
private:
	float _x, _y, _w, _h, _a, _b;
	float _dpx, _dpy;
	int _direct;
public:
	CPosition(float x, float y, float w, float h, float a, float b, float dp);
	float calx();
	float caly();
	CPoint getPos();
	int getDirect();
};

