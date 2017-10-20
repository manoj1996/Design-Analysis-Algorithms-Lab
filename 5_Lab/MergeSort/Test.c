/*
#include <stdio.h>
struct student{
    char name[50];
    int roll;
    float marks;
};
int main(){
    struct student s;
    printf("Enter information of students:\n\n");
    printf("Enter name: ");
    scanf("%s",s.name);
    printf("Enter roll number: ");
    scanf("%d",&s.roll);
    printf("Enter marks: ");
    scanf("%f",&s.marks);
    printf("\nDisplaying Information\n");
    printf("Name: %s\n",s.name);
    printf("Roll: %d\n",s.roll);
    printf("Marks: %.2f\n",s.marks);
    return 0;
}
*/
#include<stdio.h>
#include<math.h>

struct Student
{
	char srn[6];	//includes the '\0', hence size + 1
	char name[15];
	float gpa;	//should be upto 2 decimal places
};

int main()
{
	struct Student s;
	scanf("%s", s.srn);
	scanf("%s", s.name);
	scanf("%f", &s.gpa);
	
	printf("%s %s %.2f\n", s.srn, s.name, s.gpa);//db
	
	return 0;
}
