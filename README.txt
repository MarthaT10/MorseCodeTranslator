***README***

Files included: gen8.c, morse.c, gen8.h, morse.h, m.txt
------

The gen8.c program contains the helper functions and it outputs the translated form of the morse code passed from the morse.c program. 

The morse.c program contains the functions for the prompt and it inputs the morse code in the m.txt file and calls the helper function that is defined in the gen8.c file 
to translate it. It also contain the function that recursively free the binary tree.

-------

Compilation instructions: 

--Example 1 (running both gen8.c and morse.c(that includes a main function that calls the function translated_printer() only)): 

$ gcc gen8.c morse.c -o x
$ x
---Reading in
---Translating...
What file to save to?morse.txt
Saved to file! 
$


(Make sure m.txt is in the same directory since it is used directly in .c files with the same exact name and the morse code in m.txt can be changed)






