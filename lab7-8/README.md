# Lab-07/08 | File IO and preprocessor

## File IO

1. Write a program to create a copy of text files. Your program should take 2 command line arguments (path_to_file_to_copy, path_where_to_copy)
2. Write a program that reads n first/last lines of given file (n and last/first should be supplied from command line)
3. assume you have a file called `students.txt` which simply contains a bunch of student names, one name per line. Your goal is to write two functions:
- `add_student` - accepts a parameter of `first_name` and writes to a file called `students.txt`.
- `find_student` - accepts a parameter of `first_name` and returns the first student found

> Not Required. Additional note for 3rd task: Write add_student that inserts into list and keeps sorted order. Find_student should use a binary search to find the name.

### Preprocessor

1. You can add debugging output (logs) to your previous programs  (some printf functions) and using `#ifdef DEBUG` preprocessor enable/disable debug logs in your resulting program.
2. One of the best reasons to use Macros is that macros give you really fun capabilities, such as the ability to turn some code into a string. For example, here is a macro you might find useful.

```c
#define TEST(EXP,RESULT) if (EXP != RESULT) { ++errors; printf ("Did not get expected result for %s.\n", #EXP); }
```

Check whether the macro works as you expect. 
>This exercise is just for learning. No need to submit it.