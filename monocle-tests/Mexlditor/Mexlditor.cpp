
#include "Mexlditor.h"

bool MexCanvas::CreateCanvas(int width, int height)
{
	for(int i=0;i<width*height;i++)
	{
		buffer.push_back( MColor(rand()%255,rand()%255,rand()%255,1) );
	}

	return true;
}


void MexCanvas::Rand()
{
	for(int i=0;i<buffer.size();i++)
	{
		buffer[i]= MColor(rand()%255,rand()%255,rand()%255,1);
	}
}

