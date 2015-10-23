#include "acllib.h"
#include <stdio.h>

int Setup()// Like main() previously... 
{
	//Show the terminal...
	initConsole();
	//Get the width...
	printf("输入宽度：");
	int width;
	scanf("%d",&width);
	//Show the window...
	initWindow("test",default,default,width,width);//Default means  arbitrary...
	//Paiting row between begin & end...
	beginPaint();
	//Drawing line...
	line(20,20,width-20,width-20);

	//Drawing special line...
	setPenColor(BLUE);
	setPenWidth();
	setPenStyle(PEN_STYLE_DASHDOTDOT);
	//Drawing dot...
	putPixel(100,150,RGB(255,0,255));
	/*
	void putPixel(int x,int y,ACL_Color color);
	ACL_Color getPixel(int x,int y);
	*/
	endPaint();

	return 0;
}
