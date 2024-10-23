#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks
const string FILENAME = "tasks.txt"; // File to store tasks

// Structure to store a task
struct Task
{
    string name;
    bool completed;
};

// Function prototypes
void displayMenu();
void addTask(Task tasks[], int& taskCount);
void displayTasks(const Task tasks[], int taskCount);
void deleteTask(Task tasks[], int& taskCount);
void markTaskCompleted(Task tasks[], int taskCount);
void editTask(Task tasks[], int taskCount);
void loadTasksFromFile(Task tasks[], int& taskCount);
void saveTasksToFile(const Task tasks[], int taskCount);

int main()
{
    Task tasks[MAX_TASKS];
    int taskCount = 0;

    // Load tasks from the file when the program starts
    loadTasksFromFile(tasks, taskCount);

    int choice;
    do
    {
        displayMenu();
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addTask(tasks, taskCount);
            break;
        case 2:
            displayTasks(tasks, taskCount);
            break;
        case 3:
            deleteTask(tasks, taskCount);displayTasks(tasks, taskCount);
            break;
        case 4:
            markTaskCompleted(tasks, taskCount);
            break;
        case 5:
            editTask(tasks, taskCount);
            break;
        case 6:
            cout << "Exiting program. Bye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again!" << endl;
        }
    }
    while (choice != 6);

    return 0;
}

void displayMenu()
{
    cout << "\n---------- To-Do List Menu -----------\n";
    cout << "1. Add Task\n";
    cout << "2. Display Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Mark Task as Completed\n";
    cout << "5. Edit Task\n";
    cout << "6. Exit\n";
    cout << "-----------------------------------------\n";
}

void addTask(Task tasks[], int& taskCount)
{
    if (taskCount >= MAX_TASKS)
    {
        cout << "Task list is full! Cannot add more tasks." << endl;
        return;
    }

    cout << "Enter New Task: ";
    cin.ignore(); // Ignore leftover newline from previous input
    getline(cin, tasks[taskCount].name);
    tasks[taskCount].completed = false;

    taskCount++;
    cout << "Task added successfully!" << endl;
    saveTasksToFile(tasks, taskCount);
}
void displayTasks(const Task tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "No tasks to display!" << endl;
        return;
    }

    cout << "Tasks:" << endl;
    for (int i = 0; i < taskCount; ++i)
    {
        cout << i + 1 << ". " << tasks[i].name << " ("
             << (tasks[i].completed ? "Complete" : "Incomplete") << ")" << endl;
    }
}
void deleteTask(Task tasks[], int& taskCount)
{
    if (taskCount == 0)
    {
        cout << "No tasks to delete!" << endl;
        return;
    }

    displayTasks(tasks, taskCount);
    cout << "Enter the task number to delete: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= taskCount)
    {
        for (int i = taskNumber - 1; i < taskCount - 1; ++i)
        {
            tasks[i] = tasks[i + 1];
        }
        taskCount--;
        cout << "Task deleted successfully!" << endl;
        saveTasksToFile(tasks, taskCount);
    }
    else
    {
        cout << "Invalid task number!" << endl;
    }
}



void markTaskCompleted(Task tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "No tasks to mark as completed!" << endl;
        return;
    }

    displayTasks(tasks, taskCount);
    cout << "Enter the task number to mark as completed: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= taskCount)
    {
        tasks[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
        saveTasksToFile(tasks, taskCount);
    }
    else
    {
        cout << "Invalid task number!" << endl;
    }
}

void editTask(Task tasks[], int taskCount)
{
    if (taskCount == 0)
    {
        cout << "No tasks to edit!" << endl;
        return;
    }

    displayTasks(tasks, taskCount);
    cout << "Enter the task number to edit: ";
    int taskNumber;
    cin >> taskNumber;

    if (taskNumber >= 1 && taskNumber <= taskCount)
    {
        cout << "Enter new task name (current: " << tasks[taskNumber - 1].name << "): ";
        cin.ignore(); // Ignore leftover newline from previous input
        getline(cin, tasks[taskNumber - 1].name);

        cout << "Task updated successfully!" << endl;
        saveTasksToFile(tasks, taskCount);
    }
    else
    {
        cout << "Invalid task number!" << endl;
    }
}

void loadTasksFromFile(Task tasks[], int& taskCount)
{
    ifstream file(FILENAME);
    if (file.is_open())
    {
        string line;
        while (getline(file, line) && taskCount < MAX_TASKS)
        {
            size_t delimiterPos = line.find(" | ");
            if (delimiterPos != string::npos)
            {
                string name = line.substr(0, delimiterPos);
                string status = line.substr(delimiterPos + 3);
                tasks[taskCount].name = name;
                tasks[taskCount].completed = (status == "complete");
                taskCount++;
            }
        }
        file.close();
    }
}

void saveTasksToFile(const Task tasks[], int taskCount)
{
    ofstream file(FILENAME);
    if (file.is_open())
    {
        for (int i = 0; i < taskCount; ++i)
        {
            file << tasks[i].name << " | "
                 << (tasks[i].completed ? "complete" : "incomplete") << endl;
        }
        file.close();
    }
}
