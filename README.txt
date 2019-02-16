PROJECT 1 

== Description ==

This program reads a list of strings for a file and for each string, it indicates whether it's a palindrome or not. It then writes the string in PalindromeOut.txt if the string is a 
palindrome or in QuotesOut.txt if the string is a quote.
Chapter 12. Programming Project 2. Page number 275-276.

Input:   A text file named palindrome.txt that has a list of strings.

Output:  A list of messages for each string read from the file
	 indicating whether a string is palindrome or not.

Algorithm:  	1. Read a string from file
		2. Assign pointer to the start and end of the string
 		3. Compare the values
 		4. If values are same then 
 			A. Move the start pointer towards right
 			B. Move the end pointer towards left
 		5. Repeat step 4 while end pointer is greater than start ptr
Known Bugs:  None. Only the double quotes is not displayed correctly on
             screen printf. They get written correctly in files though.

== Headers ==

 - ctype.h is used for the tolower(), isalpha() functions
 - stdbool.h supports the boolean variables
 - stdio.h supports the file input output tasks
 - string.h supports sterln()
 - stdlib.h supports exit()

== USER DEFINE == 

BUF_SIZE is the maximum length string that can be read from file 

define BUF_SIZE 500

== How To Compile == 

To compile use Makefile. Example: make -f Makefile. 
Complilation can be also done using gcc from the terminal. 
To compile using gcc, use "gcc Palindrome.c -o Palindrome" (Refere to GCC manual for more information).  

						== END ==
