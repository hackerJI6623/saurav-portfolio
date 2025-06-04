#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the student structure
struct Student
{
    int rollNo;
    char name[50];
    float marks;
};

// Function to add student
void addStudent()
{
    struct Student s;
    FILE *fptr = fopen("student.txt", "ab"); // Open file in append binary mode

    if (fptr == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &s.rollNo);

    printf("Enter Name: ");
    getchar(); // To consume leftover newline
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = 0; // Remove trailing newline

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fwrite(&s, sizeof(struct Student), 1, fptr);
    fclose(fptr);
    printf("Student record added successfully!\n");
}

// Function to display all students
void displayStudents()
{
    struct Student s;
    FILE *fptr = fopen("student.txt", "rb");

    if (fptr == NULL)
    {
        printf("No records found!\n");
        return;
    }

    printf("\nAll Student Records:\n");
    printf("----------------------------\n");

    while (fread(&s, sizeof(struct Student), 1, fptr))
    {
        printf("Roll No: %d\n", s.rollNo);
        printf("Name   : %s\n", s.name);
        printf("Marks  : %.2f\n", s.marks);
        printf("----------------------------\n");
    }

    fclose(fptr);
}

// Function to search a student by roll number
void searchStudent()
{
    int roll;
    int found = 0;
    struct Student s;

    printf("Enter roll number to search: ");
    scanf("%d", &roll);

    FILE *fptr = fopen("student.txt", "rb");

    if (fptr == NULL)
    {
        printf("File not found!\n");
        return;
    }

    while (fread(&s, sizeof(struct Student), 1, fptr))
    {
        if (s.rollNo == roll)
        {
            printf("\nStudent Found:\n");
            printf("Roll No: %d\n", s.rollNo);
            printf("Name   : %s\n", s.name);
            printf("Marks  : %.2f\n", s.marks);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }

    fclose(fptr);
}

// Function to delete a student record
void deleteStudent()
{
    int roll;
    int found = 0;
    struct Student s;

    FILE *fptr = fopen("student.txt", "rb");
    FILE *temp = fopen("temp.txt", "wb");

    if (fptr == NULL || temp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    printf("Enter roll number to delete: ");
    scanf("%d", &roll);

    while (fread(&s, sizeof(struct Student), 1, fptr))
    {
        if (s.rollNo == roll)
        {
            found = 1;
        }
        else
        {
            fwrite(&s, sizeof(struct Student), 1, temp);
        }
    }

    fclose(fptr);
    fclose(temp);

    if (remove("student.txt") != 0)
    {
        printf("Error deleting original file.\n");
        return;
    }
    if (rename("temp.txt", "student.txt") != 0)
    {
        printf("Error renaming temp file.\n");
        return;
    }

    if (found)
    {
        printf("Student record deleted successfully.\n");
    }
    else
    {
        printf("Student not found.\n");
    }
}

int main()
{
    int choice;

    while (1)
    {
        printf("\n====== Student Record System ======\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student by Roll No\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addStudent();
            break;
        case 2:
            displayStudents();
            break;
        case 3:
            searchStudent();
            break;
        case 4:
            deleteStudent();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
