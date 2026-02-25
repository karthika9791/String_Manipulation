String Manipulation Program

C program for executing different c functionalities

Description:-

This project is a c program that implements three different funcitons for 
converting the string that is given by the user to various forms. The entry poi-
nt is the main function in the main.c file, which calls the string manipulation 
caller function strMnpCaller. The strMnpCaller function is defined in the 
string_ma-nipulation.c file. The user is provided by various options that can be 
performed on the input stirng. The options are defined as an enum Option. Depen-
ding upon the user input, the particular funciton is called. The function 
strMnpUpperLower is used to convert the uppercase letters in the string to lower
case. The user can input the stirng on this function. The funciton iterates thr-
ough each characters of the string and if an uppercase is found the value 32 is 
added to the char to get the ascii value of the particular lowercase character. 
The function strMnpLowerUpper is used to convert the lowercase letters in the st
ring to upper case. The user can input the stirng on this function. The funciti-
on iterates through each charaters of the string and if a lowercase is found the
value 32 is subtracted to the char to get the ascii value of the particular uppe
rcase character. The function strMnpConcatenate is used to concatenete two strin
gs that is given by the user. The user is provided to input the first string fol
lowed by the second stirng, the first string iterated till the last element, the
second string is added to the first after that. If the user inputs the last opt-
ion the program exits.

The c library functions and function declarations are added in the main.h 
file. The program is compiled using gcc compiler. A makefile is created which cr
eates the executable file string_operation. The code is executed using the 
command: make

Program Execution: The executable file is created using : make The generated 
file can be run using : ./executable file name.