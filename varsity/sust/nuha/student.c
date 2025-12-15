#include <stdio.h>
#include <math.h>

typedef struct course {
    char name[50];
    int credit;
    int marks;
    double gpa;
}course; 

typedef struct student {
    char name[50];
    int  reg;
    char dept[10];
    int ccount;
    course courses[15];
} student;

double getGpa(int marks) {
    double gpa = 0;
    if(marks >= 80) return 4.00;
    else return 4.00 - (ceil(((double) ((80 - marks)+1) / 5.00)) * 0.25);
}



int main() {
    printf("Enter the number of students: ");
    int student_count;
    scanf("%d", &student_count);

    student stds[student_count];

    for(int i = 0; i < student_count; i++) {
        printf("Enter the name of no %d student: ", i+1);
        scanf("%s", stds[i].name);
        
        printf("Enter his reg no: ");
        scanf("%d", &stds[i].reg);

        printf("Enter his dept: ");
        scanf("%s", stds[i].dept);
        
        printf("Enter the number of his courses: ");
        scanf("%d", &stds[i].ccount);

        for(int j = 0; j < stds[i].ccount; j++) {
            printf("Enter the name of no %d course: ", j+1);
            scanf("%s", stds[i].courses[j].name);

            printf("Enter the amount of credit of this course: ");
            scanf("%d", &stds[i].courses[j].credit);

            printf("Enter his obtained marks: ");
            scanf("%d", &stds[i].courses[j].marks);

            stds[i].courses[j].gpa = getGpa(stds[i].courses[j].marks);
        }
    }

    // WRITE
    FILE* fw = fopen("student_data.dat", "w");
    if(fw == NULL) {
        fprintf(stderr, "Error: couldn't open file.\n");
        return 0;
    }

    for(int i = 0; i < student_count; i++) {
        fprintf(fw, "Name: %s\n",stds[i].name);
        fprintf(fw, "Dept: %s\n",stds[i].dept);
        fprintf(fw, "Reg: %d\n",stds[i].reg);
        
        fprintf(fw, "\nCOURSES\n\n");
        for(int j = 0; j < stds[i].ccount; j++) {
            fprintf(fw, "Course name: %s\n", stds[i].courses[j].name);
            fprintf(fw, "Credit: %d\n", stds[i].courses[j].credit);
            fprintf(fw, "Marks: %d\n", stds[i].courses[j].marks);
            fprintf(fw, "Gpa: %lf\n", stds[i].courses[j].gpa);
        }
    }

    fclose(fw);

    FILE* fr = fopen("student_data.dat", "r");
    if(fr == NULL) {
        fprintf(stderr, "Error: couldn't open file.\n");
        return 0;
    }
    
    for(int i = 0; i < student_count; i++) {
        student cur_std;

        fscanf(fr, "%s",stds[i].name);
        fscanf(fr, "%s",stds[i].dept);
        fscanf(fr, "%d",&stds[i].reg);
        
        for(int j = 0; j < stds[i].ccount; j++) {
            fscanf(fr, "%s", stds[i].courses[j].name);
            fscanf(fr, "%d", &stds[i].courses[j].credit);
            fscanf(fr, "%d", &stds[i].courses[j].marks);
            fscanf(fr, "%lf", &stds[i].courses[j].gpa);
        }
        
        
        printf("Student no %d\n", i+1);
        printf("Name: %s\n", cur_std.name);
        printf("Dept: %s\n", cur_std.dept);
        printf("registration no: %d\n", cur_std.reg);
        printf("\nCOURSES:\n");

        double sum = 0;
        for(int j = 0; j < cur_std.ccount; j++) {
            printf("Course no %d\n", j+1);
            printf("Name: %s", cur_std.courses[j].name);
            printf("Credit: %d", cur_std.courses[j].credit);
            printf("Obtained marks: %d", cur_std.courses[j].marks);
            sum += cur_std.courses[j].credit;
        }
        double cgpd = sum / cur_std.ccount;
    }
}