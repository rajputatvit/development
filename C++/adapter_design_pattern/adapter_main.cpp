// Adapter design pattern 
/*
Discussion. LegacyRectangle's interface is not compatible with the system that would like to reuse it. 
An abstract base class is created that specifies the desired interface. 
An "adapter" class is defined that publicly inherits the interface of the abstract class, 
and privately inherits the implementation of the legacy component. This adapter class "maps" or 
"impedance matches" the new interface to the old implementation.
*/
#include <iostream>
using namespace std;

class rectangle
{
public:
	virtual void draw() = 0;
};

class legacy_rectangle
{
	int _x1;
	int _y1;
	int _x2;
	int _y2;

public:
	legacy_rectangle(int x1, int y1, int x2, int y2)
	{
		_x1 = x1;
		_y1 = y1;
		_x2 = x2;
		_y2 = y2;

		cout << "Create legacy rectangle with: " << "(" << _x1 << ", " << _y1 << ") => (" << _x2 << ", " << _y2 << ")" << endl;
	}

	void old_draw()
	{
		cout << "draw legacy rectangle with: " << "(" << _x1 << ", " << _y1 << ") => (" << _x2 << ", " << _y2 << ")" << endl;
	}
};

typedef int cordinate;
typedef int dimension;

class adapter_rectangle : public rectangle, private legacy_rectangle
{
	int _x;
	int _y;
	int _height;
	int _width;
public:
	adapter_rectangle(cordinate x, cordinate y, dimension w, dimension h) :legacy_rectangle(x, y, x + w, y + h)
	{
		_x = x;
		_y = y;
		_height = h;
		_width = w;

		cout << "Create adapter rectangle with: " << "(" << _x << ", " << _y << ") Width: " << _width << " " << "height: " << _height << ")" << endl;
	}

	void draw()
	{
		cout << "drawing adapter rectangle with: " << endl;
		old_draw();
	}
};

int main()
{
	rectangle* rect = new adapter_rectangle(10, 20, 2, 3);
	rect->draw();

	return 0;
}