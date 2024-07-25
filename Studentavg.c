#include <stdio.h>

#define MATH_COEFFICIENT 5
#define ENGLISH_COEFFICIENT 5
#define OPTIONAL_SUBJECT_COEFFICIENT 3
#define TOTAL_SUBJECTS 4
#define MAX_MARK 20

typedef struct {
    char name[50];
    float math;
    float english;
    float optional1;
    float optional2;
    float weighted_average;
} Student;

void calculate_weighted_average(Student *student) {
    student->weighted_average = (
        (student->math * MATH_COEFFICIENT) +
        (student->english * ENGLISH_COEFFICIENT) +
        (student->optional1 * OPTIONAL_SUBJECT_COEFFICIENT) +
        (student->optional2 * OPTIONAL_SUBJECT_COEFFICIENT)
    ) / (MATH_COEFFICIENT + ENGLISH_COEFFICIENT + 2 * OPTIONAL_SUBJECT_COEFFICIENT);
}

void display_results(Student students[], int total_students) {
    printf("\nStudent Position and Average\n");
    printf("-------------------------------------------------\n");
    printf("| Position |    Name    | Average |\n");
    printf("-------------------------------------------------\n");

    for (int i = 0; i < total_students; i++) {
        printf("|    %d     | %10s |      %6.2f       |\n", i + 1, students[i].name, students[i].weighted_average);
    }

    printf("-------------------------------------------------\n");
}

float get_valid_mark(const char* subject_name) {
    float mark;
    while (1) {
        printf("%s score: ", subject_name);
        scanf("%f", &mark);
        if (mark >= 0 && mark <= MAX_MARK) {
            break;
        } else {
            printf("Invalid mark. Please enter a mark between 0 and %d.\n", MAX_MARK);
        }
    }
    return mark;
}

int main() {
    int total_students;

    printf("Enter the total number of students: ");
    scanf("%d", &total_students);

    Student students[total_students];

    for (int i = 0; i < total_students; i++) {
        printf("\nEnter student information %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].name);
        students[i].math = get_valid_mark("Math");
        students[i].english = get_valid_mark("English");
        students[i].optional1 = get_valid_mark("ENTER MARKS FOR 3RD SUBJECT");
        students[i].optional2 = get_valid_mark("ENTER MARKS FOR 4TH SUBJECT");

        calculate_weighted_average(&students[i]);
    }

    display_results(students, total_students);

    return 0;
}
HJ
