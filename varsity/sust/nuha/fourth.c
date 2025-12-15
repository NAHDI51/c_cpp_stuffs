#include <stdio.h>
#include <stdlib.h>

#define SIZE 512

typedef struct {
    int marks;
	char code[20];
	double gpa;
} crs;

typedef struct {
	char name[SIZE];
	double gpa;
	int cnt;
	int marks;
    crs *crss;
} std;

int main() {
	int n;
	scanf("Number of students: %d", &n);

	std *stds = (std*)malloc(sizeof(std) * n);

	for (int i = 0; i < n; i++) {
        printf("Name: ");
		scanf("[^\n]", stds[i].name);
		printf("Course: ");
		scanf("%d", &stds[i].cnt);

		stds[i].crss = (crs*)malloc(sizeof(crs) * stds[i].cnt);

		double total_gpa = 0;
		for (size_t j = 0; j < stds[i].cnt; j++) {
			printf("Code: ");
			scanf("%s", stds[i].crss[j].code);

			double marks;
			printf("Mark: ");
			scanf("%lf", &marks);

			if (marks >= 80) {
				stds[i].crss[j].gpa = 4.00;
			} else if (marks >= 75) {
				stds[i].crss[j].gpa = 3.75;
			} else if (marks >= 70) {
				stds[i].crss[j].gpa = 3.5;
			} else if (marks >= 65) {
				stds[i].crss[j].gpa = 3.25;
			} else if (marks >= 60) {
				stds[i].crss[j].gpa = 3.00;
			} else if (marks >= 55) {
				stds[i].crss[j].gpa = 2.75;
			} else if (marks >= 50) {
				stds[i].crss[j].gpa = 2.5;
			} else if (marks >= 45) {
				stds[i].crss[j].gpa = 2.25;
			} else if (marks >= 40) {
				stds[i].crss[j].gpa = 2.0;
			}

			stds[i].crss[j].marks = marks;
			total_gpa += stds[i].crss[j].gpa;
		}

		stds[i].gpa = total_gpa / stds[i].cnt;
	}

	for (int i = 0; i < n; i++) {
		printf("Name: %s\n", stds[i].name);
		printf("Marks: %d\n", stds[i].marks);
		printf("GPA: %f\n", stds[i].gpa);
		for (int j = 0; j < stds[i].cnt; j++) {
			printf("Course code: %s\n", stds[i].crss[j].code);
			printf("Course marks: %lf\n", stds[i].crss[j].marks);
			printf("Course gpa: %lf\n", stds[i].crss[j].gpa);
		}
	}

	return 0;
}