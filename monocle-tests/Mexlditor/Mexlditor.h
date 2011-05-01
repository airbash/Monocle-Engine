
#include <iostream>
#include <vector>
#include <list>

class MColor
{
public:
	char r,g,b,a;

	MColor(char _r,char _g,char _b,char _a): r(_r),g(_g),b(_b),a(_a)
	{
	}
};

class MexCanvas
{
public:
	bool CreateCanvas(int width, int height);
	bool PixelModify(int x, int y, MColor color);

	void Rand();

	std::vector<MColor> buffer;
};


class MexEditor
{
public:
	std::list<MexCanvas> canvas_list;
};