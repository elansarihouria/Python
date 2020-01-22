from distutils.core import setup, Extension

def main():
	setup(name="fputs",
		version="1.0.0",
		description="Python interface for the fputs C library",
		author="<ELANSARI Houria>",
		author_email="elansarihouria@gmail.com",
		ext_modules=[Extension("fputs",["fputsmodule.c"])])

if __name__=="__main__" :
	main()
		