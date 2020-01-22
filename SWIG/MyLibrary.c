/* MyLibrary.c
*/
#include<math.h>
double myvar = 3.14 ;

float calcArea(float width, float height)
{
	return (width*height);
}

float calcVolume(float raduis)
{
	return(myvar*raduis*raduis);
}

int getVersion()
{
	return 123;
}

int getMode()
{
	return 1;
}