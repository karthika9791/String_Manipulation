//**************************** String Manipulation ***************************** 
//  Copyright (c) 2026 Trenser Technology Solutions 
//  All Rights Reserved 
//****************************************************************************** 
// 
// File    : string_manipulation.c
// Summary : File which contains string manipualtion functions
// Note    : None
// Author  : Karthika V T
// Date    : 20-02-2026
// 
//******************************************************************************

//******************************* Include Files ********************************
#include "stringManipulation.h"

//******************************* Local Types **********************************
//enum for various functionality
typedef enum {
	OPTION_UPPER_TO_LOWER = 1,
	OPTION_LOWER_TO_UPPER,
	OPTION_CONCAT,
	OPTION_EXIT
}OPTION_TYPE;

//structure having user entry, corresponding menu label and function pointer
typedef struct {
    OPTION_TYPE eInpOption;
    uint8_t * ucMenuString;
    bool (*pStrFucnHandler) (uint8_t * pucInpStr);
}stStrManipTask;

//***************************** Local Constants ********************************
#define STRMAIP_MIN_UPPER_CASE   ('A')
#define STRMAIP_MAX_UPPER_CASE   ('Z')
#define STRMAIP_MIN_LOW_CASE     ('a')
#define STRMAIP_MAX_LOW_CASE     ('z')
#define STRMAIP_UPPER_LOWER_DIFF (32)
#define STRMAIP_MAX_STR_SIZE     (100)
#define TASK_COUNT (X)           (sizeof(X)/sizeof(X[0]))

//***************************** Local Variables ********************************

//****************************** Local Functions *******************************
static bool strManipDisplay (uint8_t * pucInpStr);
static bool strManipUpperLower (uint8_t * pucInpStr);
static bool strManipLowerUpper (uint8_t * pucInpStr);
static bool strManipConcatenate (uint8_t * pucInpStr);

//array of string manipulation structure with input option and corresponding fu-
//ction
static stStrManipTask spstStrManiptable[] = {
    {OPTION_UPPER_TO_LOWER, "Uppercase-Lowercase",
        (bool(*)(uint8_t * ))strManipUpperLower},
    {OPTION_LOWER_TO_UPPER, "Lowercase-Uppercase",
        (bool(*)(uint8_t * ))strManipLowerUpper},
    {OPTION_CONCAT, "String concatenate",
		(bool(*)(uint8_t * ))strManipConcatenate}
};

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : This function takes the option for particular string function, stri-
//          ng input and calls the respective function 
//Inputs  : None
//Outputs : corresponding function is called for string manipulation 
//Return  : blReturnFlag - bool value based on execution
//Notes   : None
//****************************************************************************** 
bool strManipUserInterface (void)
{
    bool blReturnFlag = false;
    uint8_t ucIndex = 0;
    uint8_t unInpNum = 0;
    uint8_t pucInpStr[STRMAIP_MAX_STR_SIZE] = {0};
    uint8_t ucStructCount = TASK_COUNT(spstStrManiptable);
    do
    {
        printf ("String Operatrions\n"); 
        printf ("1. Uppercase-Lowercase\n2. Lowercase-Uppercase\n");
        printf ("3. Concatenation\n4. Exit\n");
        scanf ("%hhd",&unInpNum);

        if (OPTION_EXIT != unInpNum)
        {
            printf ("Enter the string\n");
            scanf (" %[^\n]",pucInpStr);
        }
        
        for (ucIndex = 0; ucIndex < ucStructCount; ucIndex++)
        {
            if (spstStrManiptable[ucIndex].eInpOption == unInpNum)
            {
                spstStrManiptable[ucIndex].pStrFucnHandler(pucInpStr);
            }
        }
    }while (OPTION_EXIT != unInpNum);
    blReturnFlag = true;
    return blReturnFlag;
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : This function converts upperccase characters in the string to lower-
//          case
//Inputs  : pucinpStr - User input string
//Outputs : pucinpStr - user input string is converted to lowercase 
//Return  : blReturnFlag - bool value based on execution
//Notes   : checks if the char in the string is uppercase then it is added to 
//          get the corresponding lowercase char
//******************************************************************************
static bool strManipUpperLower (uint8_t * pucInpStr)
{
    static bool blReturnFlag = false;   
    uint8_t *pDisplayAddr = pucInpStr;

    if (NULL != pucInpStr) {

        while ('\0' !=  *pucInpStr)
        {
		    if ((STRMAIP_MIN_UPPER_CASE <= *pucInpStr) && 
                (STRMAIP_MAX_UPPER_CASE >= *pucInpStr))
		    {
			    *pucInpStr += STRMAIP_UPPER_LOWER_DIFF;
		    }
		    pucInpStr++;
	    }

	    strManipDisplay (pDisplayAddr); 
        blReturnFlag = true;        
    }
    return blReturnFlag;   
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : This function converts lowercase characters in the string to upper-
//          case
//Inputs  : pucinpStr - User input string
//Outputs : ucinpStr - user input string is converted to uppercase
//Return  : blReturnFlag - bool value based on execution
//Notes   : checks if the char in the string is lowercase then it is subtracted
//          to get the corresponding uppercase char
//******************************************************************************
static bool strManipLowerUpper (uint8_t * pucInpStr)
{
    static bool blReturnFlag = false;
    static uint8_t *pDisplayAddr = NULL;
    pDisplayAddr = pucInpStr;

    if (NULL != pucInpStr) {

	    while ('\0' != *pucInpStr)
	    {
		    if (STRMAIP_MIN_LOW_CASE <= *pucInpStr && 
                STRMAIP_MAX_LOW_CASE >= *pucInpStr)
		    {
			    *pucInpStr -= STRMAIP_UPPER_LOWER_DIFF;
		    }
		    pucInpStr++;
	    }
	    strManipDisplay (pDisplayAddr);
        blReturnFlag = true;         
    }
    return blReturnFlag;     
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : The function concatanates two strings that is inputted by the user
//Inputs  : pucinpStr - User input string
//Outputs : ucinpStr - user input strings are concatenated
//Return  : blReturnFlag - bool value based on execution
//Notes   : Finds the end of the first and the second string added from the last
//          index for the first string
//******************************************************************************
static bool strManipConcatenate (uint8_t * pucInpStr)
{
    static bool blReturnFlag = false;
    static uint16_t unCatStrIndex = 0;
    static uint16_t unStrIndex = 0;
    static uint8_t pucCatStr[STRMAIP_MAX_STR_SIZE] = {0};
    uint8_t *pucConcatString = NULL;
    uint32_t ulConcatStringLen = 0;

    printf ("Enter the string to be concatenated\n");
    scanf (" %[^\n]",pucCatStr);
    ulConcatStringLen = strlen (pucInpStr) + strlen (pucCatStr);
    pucConcatString = (uint8_t * )malloc (ulConcatStringLen * sizeof(uint8_t));

    if (pucConcatString != NULL)
    {
        strncpy (pucConcatString, pucInpStr, strlen(pucInpStr));
        strncat (pucConcatString, pucCatStr,strlen(pucCatStr));
        strManipDisplay (pucConcatString);
        free (pucConcatString);
        blReturnFlag = true;
    }  
	return blReturnFlag;
}

//****************************** FUNCTION_HEADER ******************************* 
//Purpose : The function is used to display the string that is passed to the fu-
//          nction
//Inputs  : pucinpStr - User input string
//Outputs : ucinpStr - string get printed in the console
//Return  : blReturnFlag - bool value based on execution
//Notes   : Use puts library function to display
//******************************************************************************
static bool strManipDisplay (uint8_t * pucInpStr)
{
    static bool blReturnFlag = false;
    
    if (NULL != pucInpStr) {
        puts (pucInpStr);
        blReturnFlag = true;
    }
    return blReturnFlag;    
}
// EOF