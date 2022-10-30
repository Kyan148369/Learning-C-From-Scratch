#include <stdio.h>
#include <stdlib.h>
struct Student{
        int rollnumber;
        int grade;
    };
int main() {
    struct Student Student1;
        Student1.rollnumber = 13;
        Student1.grade = 89;
      struct Student* ptr = malloc(sizeof(struct Student));
    ptr->rollnumber = 17;
    ptr->grade = 76;

    printf("using direct ref to the structure: %d\n", Student1.grade);

    printf("Using a pointer to this structure: %d\n", ptr->grade);
    printf("using a pointer to the structure: %d\n", (*ptr).grade);   
   

    return 0;
}