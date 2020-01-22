/*SWIG Interface file*/
/* name of module to use in Python */
%module Mylibraray


%{
	/*Every thing in this file is beingc copied in 
	 wrapper file. We include the C header file necessary
	 to compile the interface */

	#include "MyLibrary.h"
	/* variable decalration */
	double myvar;
%}


int calcArea(int width, int height);
int calcVolume(int raduis);

%include "MyLibrary.h"

