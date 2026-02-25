//*************************** String Manipulation ******************************
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// File    : main.c
// Summary : Entry point to the user function 
// Note    : None
// Author  : Karthika V T
// Date    : 20-02-2026
// 
//******************************************************************************

//******************************* Include Files ********************************
#include "stringManipulation.h"

//******************************* Local Types ********************************** 

//***************************** Local Constants ******************************** 

//***************************** Local Variables ******************************** 

//****************************** Local Functions *******************************

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : It calls the function that implements the string manipulation logic
//Inputs  : None
//Outputs : Calls user intertface function to perform string manipulation
//Return  : returns 0 
//Notes   : None
//****************************************************************************** 
int main()
{	
	if(!strManipUserInterface())
	{
		printf("Program failed\n");
		return 0;
	}
	return 0;
}


// EOF
