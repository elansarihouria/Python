/*SWIG Interface file*/
/* name of module to use in Python */
%module Mylibrary


%{
	/*Every thing in this file is being copied in 
	 wrapper file. We include the C header file necessary
	 to compile the interface */

	#include "MyLibrary.h"
	/* variable decalration */
	double myvar;
%}

/*explicitly list function and variable to be interfaced*/
/*double myvar;
int calcArea(int width, int height);
int calcVolume(int raduis);*/

/* or if we want to interface all function then we can simply include header file like this*/
%include "MyLibrary.h"

