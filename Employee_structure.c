#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct emp
{
    char name[50];
    int id;
    char dep[50];
    float sal;
};
void depsal(struct emp *ptr,int n);

int main() 
{
    struct emp *ptr;
    int i,n;
    printf("Enter no of employee\n");
    scanf("%d",&n);
    ptr = (struct emp*)malloc(n*sizeof(struct emp));
    printf("Enter the employee details for %d employee\n",n);
    for(i=0;i<n;i++)
    {
        printf("\n Enter the name of %d. employee:",i+1);
        scanf("%s",(ptr+i)->name);
        printf("\n Enter the ID of %d. employee:",i+1);
        scanf("%d",&(ptr+i)->id);
        printf("\n Enter the dept of %d. employee:",i+1);
        scanf("%s",(ptr+i)->dep);
        printf("\n Enter the salary of %d. employee:",i+1);
        scanf("%f",&(ptr+i)->sal);
    }
    printf("The employee details are : \n");
    for(i=0;i<n;i++)
    {
        printf("%d. Employee name: %s \n",i+1,(ptr+i)->name);
        printf("%d. Employee id: %d \n",i+1,(ptr+i)->id);
        printf("%d. Employee dept: %s \n",i+1,(ptr+i)->dep);
        printf("%d. Employee salary: %f \n",i+1,(ptr+i)->sal);
    }
    depsal(ptr,n);
    return 0;
}

void depsal(struct emp *ptr,int n)
{
    int i;
    char d[50];
    float total=0;
    printf("Enter the department name\n");
    scanf("%s",d);
    for(i=0;i<n;i++)
    {
        if(strcmp((ptr+i)->dep,d)==0)
        {
            total=total+((ptr+i)->sal);
        }
    }
    printf("The total salary of the %s department is %f\n",d,total);
}
