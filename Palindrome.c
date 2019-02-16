#=============================================================================
 #|   Assignment:  
 #|
 #|       Author:  TWOKOKO CHAW
 #|     Language:  C (Compiler used: MinGW.org GCC-6.3.0-1)
 #|   To Compile:  Makefile was used to compile
 #|        Class:  CS 150-L01
 #|   Instructor: 
 #|     Due Date:  01 NOVEMBER 2018
 #|
 #+-----------------------------------------------------------------------------
 #|
 #|  Description:  The program reads a list of strings for a file and for each
 #                string, it indicates whether it's a palindrome or not. It then
 #|				  writes the string in PalindromeOut.txt if the string is a
 |				  palindrome or in QuotesOut.txt if the string is a quote.
 |                Chapter 12. Programming Project 2. Page number 275-276.
 |
 |        Input:  A text file named palindrome.txt that has a list of strings.
 |
 |       Output:  A list of messages for each string read from the file
 |                indicating whether a string is palindrome or not.
 |
 |    Algorithm:  1. Read a string from file
 |				  2. Assign pointer to the start and end of the string
 |				  3. Compare the values
 |				  4. If values are same then
 |				  	A. Move the start pointer towards right
 |					B. Move the end pointer towards left
 |				  5. Repeat step 4 while end pointer is greater than start ptr
 |
 |   Known Bugs:  None. Only the double quotes is not displayed correctly on
 |				  screen printf. They get written correctly in files though.
 |
 *===========================================================================*/

//======== Begin of Headers ========
/*=========
 | ctype.h is used for the tolower(), isalpha() functions
 | stdbool.h supports the boolean variables
 | stdio.h supports the file input output tasks
 | string.h supports sterln()
 | stdlib.h supports exit()
 *========*/
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "DieWithError.c"
//======== End of Headers ========

//======== Begin of Constants ========
/*=========
 | BUF_SIZE is the maximum length string that can be read from file
 *========*/
#define BUF_SIZE 500
//======== End of Constants ========

bool isPalindrome(char *);
void writeOutput(const char *, char *,int);
char * formatInput(char []);
//=========== Begin of Main ==============

int main(int argc, char *argv[]) {

	if (argc > 1){
		DieWithError("Too many arguments");
	}
	if (argc < 1){
		DieWithError("Insufficient arguments");
	}


    char inputline[BUF_SIZE];
    FILE *inputfile;
    int totallines = 0;
    int totalquotes = 0;
    int totalpalindromes = 0;
    char * formattedline;


    inputfile = fopen("Palindrome.txt", "r");

    if (inputfile == NULL) {
    	DieWithError("Can't open input file! ");
    }
    else {
    	// check if file is empty
    	fseek (inputfile, 0, SEEK_END); // goto end of file
	    int size = ftell(inputfile);

	    if (size == 0) { // file is empty
	        DieWithError("File is empty! ");
	    }
	    else{
    		fseek(inputfile, 0, SEEK_SET); // goto begin of file
	    	while(fgets(inputline, BUF_SIZE, inputfile)) {
				// format input line
				formattedline = formatInput(inputline);

		        printf(formattedline);


		        // Process the line
	            bool result = isPalindrome(formattedline);
	            if (result){
	                printf("...is a Palindrome\n...................\n");
	                totalpalindromes++;
	                if (totalpalindromes > 1)
		                writeOutput("palindromesOut.txt",inputline,0); // file exists
	                else
	              	    writeOutput("palindromesOut.txt",inputline,1);
	            }
	            else{
	                printf("...is a Quote\n...................\n");
	                totalquotes++;
	                if (totalquotes > 1)
		                writeOutput("quotesOut.txt",inputline,0); // file exists
	                else
	                	writeOutput("quotesOut.txt",inputline,1); // file does not exist
	            }

		        totallines++;
	    	}
	    }

	    printf("\nTotal Lines: %d \n",totallines);
	    printf("Total Palindromes: %d \n",totalpalindromes);
	    printf("Total Quotes: %d \n",totalquotes);

    }
    return 0;
}
//=========== End of Main ==============

/*------------------------------------------------- isPalindrome -----
         |  Function isPalindrome
         |
         |  Purpose:  Tells if a string is palindrome or not
         |
         |  Parameters:
         |      str (IN) -- string to check
         |
         |  Returns:  True if the string is a palindrome
         |			  False if the string is not a palindrome
         *-------------------------------------------------------------------*/
//=========== Begin of Function isPalindrome ==============

    // A function to check if a string str is palindrome
bool isPalindrome(char * str)
{
	char *ptr_right = str;
	char *ptr_left = str;

	// set the right pointer to end of string
    //ptr_right = str;
    while (*ptr_right != '\n') {
        ++ptr_right;
    }

  	// set the left pointer to the start
  	//ptr_left = str;

  	while(ptr_right > ptr_left){
	  	// Get characters to compare
	  	bool validCharRead = false;
	    char leftChar, rightChar;

  		// read left char
        while (!validCharRead){
            if (isalpha(*ptr_left)){
                leftChar = tolower(*ptr_left);
                validCharRead = true;
            }
            else
            	++ptr_left;
        }

        validCharRead = false;
        // read righ char
        while (!validCharRead){
            if (isalpha(*ptr_right)){
                rightChar = tolower(*ptr_right);
                validCharRead = true;
            }
            else
            	--ptr_right;
        }

        if (leftChar != rightChar)
        {
            return false;
        }
        else{
            ++ptr_left;
            --ptr_right;
        }
  	}
	return true;
}
//=========== End of Function isPalindrome ==============

/*------------------------------------------------- writeOutput -----
         |  Function writeOutput
         |
         |  Purpose:  Opens the output file and writes a string to it.
         |
         |  Parameters:
         |      outputfile (IN) -- output file name
         |      inputline (IN) -- array that needs to be written
         |      createMode (IN) -- 1 (open file in write mode)
	     |						   0 (open file in append mode)
         |
         |  Returns:  None.
         *-------------------------------------------------------------------*/
//=========== Begin of Function writeOutput ==============

void writeOutput(const char * outputfile, char * inputline, int createMode){
	FILE * file;
	if (createMode == 1){// create file
		file = fopen(outputfile, "w");
	}
	else{
		file = fopen(outputfile, "a");
	}

 	if (file == NULL) {
  		DieWithError("Can't open output file! ");
    }
  	else{
   		fprintf (file, inputline);
  	}
}
//=========== End of Function formatInput ==============

/*------------------------------------------------- formatInput -----
         |  Function formatInput
         |
         |  Purpose:  Capitalizes the character in the start of a word and lowers
         |			  the remaining letters of a word.
         |
         |  Parameters:
         |      inputline (IN) -- char array that needs to be formatted
         |
         |  Returns:  Pointer to the modified version of the array inputline
         |
         *-------------------------------------------------------------------*/
//=========== Begin of Function formatInput ==============

char * formatInput(char inputline[]){
	//capitalize first character of words
	int index;
	for(index=0; inputline[index]!='\0'; index++){
		//check first character is lowercase alphabet
		if(index==0){
			if(islower(inputline[index]))
				inputline[index] = toupper(inputline[index]); //subtract 32 to make it capital
			continue; //continue to the loop
		}
		if(inputline[index]==' '){//check space
			//if space is found, check next character
			++index;
			//check next character is lowercase alphabet
			if(islower(inputline[index])){
				inputline[index] = toupper(inputline[index]); //subtract 32 to make it capital
				continue; //continue to the loop
			}
		}
		else{
			//all other uppercase characters should be in lowercase
			if(isupper(inputline[index]))
				inputline[index] = tolower(inputline[index]); //subtract 32 to make it small/lowercase
		}
	}
	return inputline;
}
//=========== End of Function formatInput ==============
