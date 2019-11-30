#include<stdio.h>
#include<conio.h>
struct taxi
{
	int empno;
	char empname[50];
	char phoneno[11];
	char vehregno[12];
	char vehname[20];
	char vehcolor[20];
	char vehtype[20];
	int cabno;
	int status;
	char location[20];
};
main()
{
	int i,n;
	struct taxi a[50];
	printf("\nEnter the No. of Employees:");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		printf("\nEMPLOYEE:%d",i);
		printf("\nEnter the Employee No.:");
		scanf("%d",&a[i].empno);
		printf("\nEnter the Employee Name:");
		scanf("%s",a[i].empname);
		printf("\nEnter the Employee's Phone No.:");
		scanf("%s",a[i].phoneno);
		printf("\nEnter the Cab No.:");
		scanf("%d",&a[i].cabno);
		printf("\nEnter the Vehicle Type:");
		scanf("%s",a[i].vehtype);
		printf("\nEnter the Vehicle Name:");
		scanf("%s",a[i].vehname);
		printf("\nEnter the Vehicle Color:");
		scanf("%s",a[i].vehcolor);
		printf("\nEnter the Vehicle Reg. No.:");
		scanf("%s",a[i].vehregno);
		printf("\nEnter the location of the Cab:");
		scanf("%s",a[i].location);
		printf("STATUS OF DRIVER: \t 0.FOR HIRE\t 1.HIRED");
		printf("\nEnter the Driver's Status:");
		scanf("%d",&a[i].status);
	}
	FILE *fp;
	fp=fopen("Taxiemployees.bin","wb");
	for(i=1;i<=n;i++)
	{
		fwrite(&a[i],sizeof(struct taxi),1,fp);
	}	
	fclose(fp);
}
