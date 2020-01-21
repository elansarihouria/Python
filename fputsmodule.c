#include<Python.h>
/*******moification test for git********/
static PyObject *StringTooShortError = NULL;/*Raising Custom Exeption*/

/*******the core functionality of my Python C extension************/



static PyObject *method_fputs(PyObject *self, PyObject *args)/*PyObject is an object structure that you use to define object types for Python.*/
{
	char *str,*filename=NULL;
	int bytes_copied = -1;

	/* Parse arguments */
	/*PyArg_ParseTuple() parses the arguments you’ll receive from your Python program into local variables*/

	if(!PyArg_ParseTuple(args/*are of type PyObject.*/,"ss"/* the data type of the arguments to parse.*/
	,&str, &filename/*pointers to local variables to which the parsed values will be assigned.*/
	)){
		return NULL;

	}

	/******* Raising Exceptions from C code ***********/


	if(strlen(str)<10){
		PyErr_SetString(StringTooShortError," String length must be greater than 10 ");
		return NULL;
	}

	FILE * fp = fopen(filename,"w");
	bytes_copied=fputs(str,fp);
	fclose(fp);

	return PyLong_FromLong(bytes_copied);/*PyLong_FromLong() returns a PyLongObject, which represents an integer object in Python.*/

}


/****************  meta information about my module     ****************/



	/*information about the methods in your Python C extension */

static PyMethodDef FputsMethods[] = 
{   

	{"fputs"/* the name the user would write to invoke this particular function.*/
	, method_fputs /*the name of the C function to invoke.*/
	, METH_VARARGS/*flag that tells the interpreter that the function will accept two arguments of type PyObject*:
   					 1.self is the module object.
    				2.args is a tuple containing the actual arguments to your function*/

	,"Python interface for fputs C library function"/*value to represent the method docstring.*/
	},

	{NULL,NULL,0,NULL}
};



 /*information about your module itself*/

static struct PyModuleDef fputsmodule = {
	PyModuleDef_HEAD_INIT,/*member of type PyModuleDef_Base*/
	"fputs",/* name of your Python C extension module*/
	"Python interface for the fputs C library function",/*docstring*/
	-1,  /* the amount of memory needed to store your program state. 
					It’s helpful when your module is used in multiple sub-interpreters,
					 and it can have the following values:

				    A negative value indicates that this module doesn’t have support for sub-interpreters.
				    A non-negative value enables the re-initialization of your module. 
				    It also specifies the memory requirement of your module to be allocated on each sub-interpreter session.*/

	FputsMethods   /* PyMethodDef structs you defined PyMethodDef structs you defined*/
};




PyMODINIT_FUNC PyInit_fputs(void){

	/* Assign module value */
	PyObject *module=PyModule_Create(&fputsmodule);

	/*Initialize new exception object*/
	StringTooShortError =PyErr_NewException("fputs.StringTooShortError",NULL,NULL);

	/* Add exception object to your module*/
	PyModule_AddObject(module,"StringTooShortError",StringTooShortError);

	/* 	Add int constant by name */
	PyModule_AddIntConstant(module,"FPUTS_FLAG",64);

	/*Define int macro */
	#define FPUTS_MACRO 256

	/* Add macro to module */
	PyModule_AddIntMacro(module,FPUTS_MACRO);

	return module;

}

