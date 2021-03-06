"segmentation violation," it means your program has attempted to access an area of memory that it is not allowed to access. 
In other words, it attempted to stomp on memory ground that is beyond the limits that the operating system (e.g., Unix) has allocated for your program. 

#Segmentation Fault Scenario:
--------------------------------
MyFunc.c
--------
int myFunc(void)
{
	extern int myVal;
  /*Segmentation Fault happens here as you are trying to overwrite a constant variable*/
	myVal=50;
	return myVal; 
}
-------------------------------
main.c
-------
#include <stdio.h>

int myFunc(void);

/*Stored in Data Memory (intialized Data memory seg.)=> R/W Segemnt*/
const int myVal=9;

typedef long int uint32;

#define BIT_A (0x01)

int main(void)
{
	printf("Test Global Var: %d\n" ,myFunc());
	return 0;
}
=================================================================================================================
*Unitialized Static Variables are intialized with ZERO by default.

static int A; /* A is stored in Unitialized Read/Write Data Memory Segement With 0 as intial value */
