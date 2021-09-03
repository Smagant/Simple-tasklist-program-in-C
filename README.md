# Terminal based Tasklist using C
## Version 1.0
Here is a simple implementation of a tasklist in C displayed in the terminal. You can add, delete or modify each task on the list.

### Requirements
1 - Install a compiler for the C language (for example GCC)
2 - Open your terminal and go to the "src" file.
3 - Compile the program with this command (if you're using gcc)
```bash
gcc main.c tasklist.c -o tasklist
```
4 - Open the application with this command
```bash
./tasklist
```
The application works by using commands directly in your terminal

### Commands:
- a content = add a new task to the tasklist
- d number = delete a specific task of the tasklist using its number in the list
- m number = modify a specific task of the tasklist using its number in the list
- p = print the tasklist
- h = help
- q = quit the application
