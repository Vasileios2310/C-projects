#include <stdlib.h>
#include <stdio.h>

typedef struct Process {
    int id;
    int priority;   // 1 = high, 2 = low
    int execTime;   // in milliseconds
    struct Process* next;
} Process;

Process* head = NULL;
Process* tail = NULL;
int nextID = 1;

/*
 * Adds a new process to the end of the queue.
 * The user enters the process priority and execution time.
 * The priority must be either 1 for high or 2 for low.
 * The execution time must not be negative.
 */
void addProcess() {
    int priority, execTime;

    do {
        printf("Enter priority (1 = high, 2 = low): ");
        scanf("%d", &priority);
    } while ((priority != 1) && (priority != 2));

    do {
        printf("Enter execution time (ms): ");
        scanf("%d", &execTime);
    } while (execTime < 0);

    Process* newNode = malloc(sizeof(Process));

    if (newNode == NULL) {
        printf("Memory allocation error\n");
        return;
    }

    newNode->id = nextID++;
    newNode->priority = priority;
    newNode->execTime = execTime;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }

    printf("Process with ID = %d was added\n", newNode->id);
}

/*
 * Displays all processes currently stored in the queue.
 * If the queue is empty, an appropriate message is printed.
 */
void displayQueue() {
    if (head == NULL) {
        printf("The queue is empty\n");
        return;
    }

    Process* temp = head;

    while (temp != NULL) {
        printf("ID: %d | Priority: %d | Execution time: %d ms\n",
               temp->id, temp->priority, temp->execTime);

        temp = temp->next;
    }
}

/*
 * Executes one process from the queue based on CPU time availability.
 * First, the function searches for a high-priority process that can be executed.
 * If no high-priority process fits the available CPU time, it searches for a low-priority process.
 * The executed process is removed from the queue and its memory is freed.
 */
void executeProcess() {
    int cpuTime;

    if (head == NULL) {
        printf("The queue is empty\n");
        return;
    }

    printf("Enter available CPU time: ");
    scanf("%d", &cpuTime);

    Process* current;    // current node
    Process* previous;   // previous node

    current = head;
    previous = NULL;

    while (current != NULL) {
        if (current->priority == 1 && current->execTime <= cpuTime) {
            break;
        }

        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        current = head;
        previous = NULL;

        while (current != NULL) {
            if (current->priority == 2 && current->execTime <= cpuTime) {
                break;
            }

            previous = current;
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("No process can be executed\n");
        return;
    }

    if (previous == NULL) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    if (current == tail) {
        tail = previous;
    }

    printf("Executed process:\n");
    printf("ID: %d | Priority: %d | Execution time: %d ms\n",
           current->id, current->priority, current->execTime);

    free(current);
}

int main() {
    int choice;

    system("chcp 65001>nul"); // enables UTF-8 output on Windows console

    do {
        printf("\nMenu:\n");
        printf("1. Add process\n");
        printf("2. Display queue\n");
        printf("3. Execute process\n");
        printf("0. Exit\n");
        printf("Choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProcess();
                break;

            case 2:
                displayQueue();
                break;

            case 3:
                executeProcess();
                break;

            case 0:
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 0);

    /*
     * Frees all remaining nodes in the queue before the program exits.
     */
    while (head) {
        Process* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}