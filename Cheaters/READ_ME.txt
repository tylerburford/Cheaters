This program is used to catch cheaters by analyzing a number of documents and 
evaluating similair strings of words between them.
At the time of writing this, the program is works for all three small, medium, and large
document sets. There are no bugs to report. 
To compile and run, with the included makefile, enter "make" into the linux command prompt
and then type "./plagiarismCatcher [path to documents] [size of consecutive word chunks to analyze] 
[minimum amount of similarities before reporting]".

The included files are main.cpp, helper.cpp, helper.h, hasher.cpp, and hasher.h