#include "pch.h"
#include "CPosition.h"

//

CPosition::CPosition(float x, float y, float w, float h, float a, float b, float dp)
	: _x(x), _y(y), _w(w), _h(h), _a(a), _b(b), _dpx(dp), _dpy(dp)
{
	if (_x < _a) {
		_x = _a;
		_direct = 1;
	}
	if (_x > _w - _a) {
		_x = _w - _a;
		_direct = -1;
	}
	if (_y < _b) _y = _b;
	if (_y > _h - _b) _y = _h - _b;

}

float CPosition::calx()
{
	if (_x < 0 && _dpx < 0) {
		_dpx = -1 * _dpx;
		_direct = 1;
	}
	if ((_x) > (_w - _a) && _dpx > 0) {
		_dpx = -1 * _dpx;
		_direct = -1;
	}
	_x += _dpx;
	return _x;
}
float CPosition::caly()
{
	if ((_y) < 0 && _dpy < 0) {
		_dpy = -1 * _dpy;
	}
	if ((_y) > (_h - _b) && _dpy > 0) {
		_dpy = -1 * _dpy;
	}
	_y += _dpy;
	return _y;
}

CPoint CPosition::getPos()
{
	return CPoint(_x, _y);
}

int CPosition::getDirect()
{
	return int(_direct);
}
