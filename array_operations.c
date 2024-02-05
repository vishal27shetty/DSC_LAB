#include <stdio.h>
#include <stdlib.h>

void create();
void display();
void insert();
void delete();

int a[50],n;

int main()
{
	int ch;
	while(1)
	{
		printf("\nSelect required choices");
		printf("\n 1.Create");
		printf("\n 2.Display");
		printf("\n 3.Insert");
		printf("\n 4.Delete");
		printf("\n 5.Exit");

		scanf("%d",&ch);

		switch(ch)
		{
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: insert();
				break;
			case 4: delete();
				break;
			case 5: exit(0);
				break;
			default: printf("Invalid choice \n");
		}
	}
	return 0;
}

void create()
{
	int i;
	printf("Enter number of elements");
	scanf("%d",&n);
	printf("Enter the element \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}

void display()
{
	int i;
        printf("The element are \n");
        for(i=0;i<n;i++)
        {
                printf("%d",a[i]);
        }
}

void insert()
{
	int i,p,el;
	printf("Enter position of element to be inserted \n");
	scanf("%d",&p);
	printf("Enter element to be inserted \n");
	scanf("%d",&el);
	for(i=n-1;i>=p-1;i--)
	{
		a[i+1]=a[i];
	}
	a[p-1]=el;
	n++;
}

void delete()
{
	int i,p;
	printf("Enter the position of element to be deleted \n");
	scanf("%d",&p);
	for(i=p;i<=n;i++)
	{
		a[i-1]=a[i];
	}
	n--;
}

