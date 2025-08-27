#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 100

// Define the structure for a student
typedef struct Student {
    char name[MAX_NAME_LENGTH];
    int id;
    float marks;
    struct Student* next;
} Student;

// Function to add a new student to the database
void addStudent(Student** head) {
    Student* newStudent = (Student*) malloc(sizeof(Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter student name: ");
    fgets(newStudent->name, MAX_NAME_LENGTH, stdin);
    newStudent->name[strcspn(newStudent->name, "\n")] = 0; // Remove newline character

    printf("Enter student ID: ");
    scanf("%d", &newStudent->id);
    getchar(); // Consume newline left in input buffer

    printf("Enter student marks: ");
    scanf("%f", &newStudent->marks);
    getchar(); // Consume newline left in input buffer

    newStudent->next = *head;
    *head = newStudent;
}

int main() {
    Student* head = NULL;
    addStudent(&head);
    // ... (other operations or printing the list)
    return 0;
}
