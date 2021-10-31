# Lab-01 | Implementing own library
As a part of this lab you need to implement your own library. Main goal is to get practical experience with functions in C and organize project via using different implementations of given header file. You also need to create a Makefile that provides commands to build, clean and run driver program that runs your library.

## Feedback
Great job in the implementations! 👏 

However, you used a single .h file and added all implementations there. It's not a good practice to put implementation into header file. Also we loose the whole point of organization of project and capability of separating definition of library from its implementation. 

Next time try to keep your header and implementations in sepaarate .h and .c files