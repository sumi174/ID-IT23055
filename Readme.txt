Introduction

This is a simple console-based To-Do List program written in C++. The program allows users to manage their tasks by adding, displaying, deleting, marking tasks as completed, and editing them. Tasks are saved to a file (tasks.txt) to maintain persistence across program sessions.

Features

1.Add Task: Users can add new tasks to the list. Each task is initialized as incomplete.
2.Display Tasks: All tasks in the list are displayed along with their completion status
(complete/incomplete).
3.Delete Task: Users can delete a task by specifying its number from the displayed list.
4.Mark Task as Completed: Users can mark tasks as completed by selecting them from the displayed list.
5.Edit Task: Users can edit the name of any task in the list.
6.File Persistence: The list of tasks is saved to a file (tasks.txt) and reloaded when the program restarts.

How it Works

1. Task Structure
Tasks are stored as structures, where each task has a name and a completion status (completed). The tasks are stored in an array, with a maximum limit of 100 tasks.
struct Task
{
    string name;
    bool completed;
};

2. File Persistence

Tasks are saved to a file (tasks.txt) to maintain persistence across program executions. When the program starts, it loads any existing tasks from the file. Upon adding, deleting, or modifying tasks, the updated list is saved back to the file.

•Tasks are saved in the format:
Task name | complete/incomplete

3. Menu Navigation

The program operates based on a simple menu system that guides users through the various options available for managing their tasks.

4. Task Management Functions

•Add Task: Adds a new task to the array.
•Display Tasks: Prints all tasks and their status.
•Delete Task: Removes a task based on its position in the list.
•Mark Task as Completed: Marks a task as completed by setting the completed flag to true.
•Edit Task: Allows users to rename a task.

5. File Operations

The file operations are handled by two functions:
•loadTasksFromFile: Loads tasks from tasks.txt when the program starts.
•saveTasksToFile: Saves the current tasks to the file whenever a task is added, deleted, or modified.

How to Compile and Run

1. Compiling the Program
To compile the program, use a C++ compiler like g++. Assuming the program is saved in a file called todo.cpp, we can compile it as follows:
g++ todo.cpp -o todo

2. Running the Program
Once compiled, we can run the program using:
./todo
File: tasks.txt
This file will be created or updated automatically by the program to store our tasks. Each line in the file represents a task in the format:
Task Name | complete/incomplete
•When a task is marked as completed, the text complete appears next to the task name.
•When a task is incomplete, the text incomplete appears.

Example Run
---------- To-Do List Menu -----------
1. Add Task
2. Display Tasks
3. Delete Task
4. Mark Task as Completed
5. Edit Task
6. Exit
-----------------------------------------
Enter choice: 1
Enter New Task: Buy groceries
Task added successfully!

Enter choice: 2
Tasks:
1. Buy groceries (Incomplete)

Enter choice: 4
Enter the task number to mark as completed: 1
Task marked as completed!

Enter choice: 2
Tasks:
1. Buy groceries (Complete)

Enter choice: 6
Exiting program. Bye!

Conclusion
This program is a basic but functional To-Do List that uses file-based persistence to store tasks. It demonstrates the use of arrays, structures, file I/O, and basic console interaction in C++.

