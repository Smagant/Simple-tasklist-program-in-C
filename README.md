# Terminal based Tasklist using C
## Version 1.0
Here is a simple implementation of a tasklist in C displayed in the terminal. You can add, delete or modify each task on the list.

### Requirements
Install the compiler GCC

Then open your terminal and go to the "src" file.
Compile the program with this command
```bash
gcc main.c tasklist.c -o tasklist
```
Then open the application with this command
```bash
./tasklist
```

### Commands:
- a content = add a new task to the tasklist
- d number = delete a specific task of the tasklist using its number in the list
- m number = modify a specific task of the tasklist using its number in the list
- h = help
- q = quit the application
