#include<stdio.h>
#include<string.h>
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
struct ride
{
	char pickup[50],drop[50];
	int cabno;
	char empname[50];
	char phoneno[11];
	char vehtype[20];
	char vehregno[12];
	char vehname[20];
	char vehcolor[20];
};
	float kms,fare;
	struct taxi a[50];
	struct ride b[50];
	int dist(int);
	int cost(int);
main()
{
	int i,j=1,m,c=0,cno,count=1,can=1,z,lflag=0,review,no,mflag=0;
	do
	{
		printf("\n\t\tWELCOME TO CIT TAXI");
		printf("\n\t\t------------------------");
		printf("\nThe Process you want to continue....\n 1.Book Taxi\n 2.Cancel Booking\n 3.Check the Status\n 4.Check the Location\n 5.Write a Review\n 6.Log out");
		printf("\nEnter the operations to be performed: ");
		scanf("%d",&m);
		lflag=0;
		mflag=0;
		switch(m)
		{
			case 1:
				printf("\n\t\tBOOK A RIDE");
				printf("\nAvailable Vehicle Types: \nMicro \nMini \nSedan \nLuxury");
				printf("\nEnter the Vehicle Type:");
				scanf("%s",b[j].vehtype);
				printf("\nCAB Available from the following places:\n1.Gandhipuram \n2.RailwayStation \n3.Airport \n4.Ukkadam \n5.Singanallur \n6.Brookefields \n7.RSPuram \n8.Thudiyalur");
				printf("\nEnter the Pickup location:");
				scanf("%s",b[j].pickup);
				printf("\nCAB Available to the following places:\n1.Gandhipuram \n2.RailwayStation \n3.Airport \n4.Ukkadam \n5.Singanallur \n6.Brookefields \n7.RSPuram \n8.Thudiyalur");
				printf("\nEnter the Dropping location:");
				scanf("%s",b[j].drop);
				if(strcmp(b[j].pickup,b[j].drop)==0)
				{
					printf("\nEnter other location....");
					printf("\nEnter the Dropping location:");
					scanf("%s",b[j].drop);
				}
				FILE *fp;
				fp=fopen("Taxiemployees.bin","rb");
				for(i=1;i<=40;i++)
				{
					fread(&a[i],sizeof(struct taxi),1,fp);
				}
				for(i=1;i<=40;i++)
				{
					if(strcmp(b[j].pickup,a[i].location)==0 && a[i].status==0 && strcmp(b[j].vehtype,a[i].vehtype)==0)
					{
						dist(j);
						cost(j);
						printf("\nYOUR TAXI HAS BEEN BOOKED");
						printf("\nTHE CAB NO.: %d",a[i].cabno);
						printf("\nTAXI DRIVER: %s",a[i].empname);
						printf("\nDRIVER CONTACT NO.: %s",a[i].phoneno);
						printf("\nVEHICLE NAME: %s",a[i].vehname);
						printf("\nVEHICLE COLOR: %s",a[i].vehcolor);
						printf("\nVEHICLE REG. NO.: %s",a[i].vehregno);
						printf("\nThe Fare for Travel: %f",fare);
						a[i].status=1;
						strcpy(a[i].location,b[j].drop);
						b[j].cabno=a[i].cabno;
						strcpy(b[j].empname,a[i].empname);
						strcpy(b[j].phoneno,a[i].phoneno);
						strcpy(b[j].vehname,a[i].vehname);
						strcpy(b[j].vehcolor,a[i].vehcolor);
						strcpy(b[j].vehregno,a[i].vehregno);
						lflag=1;
					}
					if(strcmp(b[j].pickup,a[i].location)!=0 && a[i].status!=0 && strcmp(b[j].vehtype,a[i].vehtype)!=0)
					{
						count++;
					}
					if(count==10)
					{
						printf("\nNO TAXI NEARBY THE LOCATION.....");
					}
					if(lflag==1)
						break;
				}
				fclose(fp);
				FILE *rs;
				rs=fopen("Taxiemployees.bin","wb");
				for(i=1;i<=40;i++)
				{
					fwrite(&a[i],sizeof(struct taxi),1,rs);
				}
				fclose(rs);
				j++;
				break;
			case 2:
				printf("\nEnter the Cab No.:");
				scanf("%d",&cno);
				FILE *rm;
				rm=fopen("Taxiemployees.bin","rb");
				for(i=1;i<=40;i++)
				{
					fread(&a[i],sizeof(struct taxi),1,rm);
				}
				for(i=1;i<=40;i++)
				{
					for(z=1;z<=20;z++)
					{
						if(cno==b[z].cabno && a[i].status==1)
						{
							a[i].status=0;
							printf("\nTHE TAXI HAS BEEN CANCELLED...");
							strcpy(a[i].location,b[z].pickup);
							mflag=1;
						}
						if(mflag==1)
						{
							break;
						}
						if(cno!=b[z].cabno && a[i].status!=1)
						{
							can++;
						}		
					}
					if(can==100)
					{
						printf("\nERROR OCCURRED IN THE PROCESS........PLEASE ENTER A VALID CAB NO. ......");
					}
					if(mflag==1)
					{
						break;
					}
				}
				fclose(rm);
				FILE *fm;
				fm=fopen("Taxiemployees.bin","wb");
				for(i=1;i<=40;i++)
				{
					fwrite(&a[i],sizeof(struct taxi),1,fm);
				}
				fclose(fm);
				break;
			case 3:
				printf("\n\t\tCIT TAXI DRIVER'S STATUS");
				printf("\n\t\t-----------------------------");
				FILE *fr;
				fr=fopen("Taxiemployees.bin","rb");
				for(i=1;i<=40;i++)
				{
					fread(&a[i],sizeof(struct taxi),1,fr);
				}
				printf("\nTHE TAXI STATUS : 0.FOR HIRE \t1.HIRED");
				for(i=1;i<=40;i++)
				{
					printf("\nThe Driver No.: %d 's STATUS is: %d",i,a[i].status);
				}
				fclose(fr);
				break;
			case 4:
				printf("\n\t\tCIT TAXI DRIVER'S LOCATION");
				printf("\n\t\t-----------------------------");
				FILE *kl;
				kl=fopen("Taxiemployees.bin","rb");
				for(i=1;i<=40;i++)
				{
					fread(&a[i],sizeof(struct taxi),1,kl);
				}
				for(i=1;i<=40;i++)
				{
					printf("\nThe Driver No.: %d 's LOCATION is: %s",i,a[i].location);
				}
				fclose(kl);
				break;
			case 5:
				printf("\n\tWrite a Review");
				printf("\nEnter the Cab No.:");
				scanf("%d",&no);
				for(i=1;i<=40;i++)
				{
					if(no==a[i].cabno)
					{
						printf("\nREVIEWS of %s",a[i].empname);
						printf("\nReviews: 1.POOR\t 2.NOT GOOD\t 3.SATISFACTORY\t 4.GOOD\t 5.EXCELLENT");
						printf("\nGive Review:");
						scanf("%d",&review);
						printf("\nTHANK YOU FOR GIVING YOUR VALUABLE COMMENTS");
					}
				}
				break;
			case 6:
				printf("\n\t\tCIT TAXI SERVICES");
				printf("\n\t\t------------------------");
				printf("\nYou've been successfully logged out");
				for(i=1;i<=40;i++)
				{
					a[i].status=0;
				}
				FILE *d;
				d=fopen("Taxiemployees.bin","wb");
				for(i=1;i<=40;i++)
				{
					fwrite(&a[i],sizeof(struct taxi),1,d);
				}
				fclose(d);
				break;
			default:
				printf("\nERROR.........Enter a valid process");
		}
	}
	while(m!=6);
}
	int dist(int j)
	{
						if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"RailwayStation")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"RailwayStation")==0))
						{
							kms=3;
						}
						else if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"Airport")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"Airport")==0))
						{
							kms=8;
						}
						else if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"Ukkadam")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"Ukkadam")==0))
						{
							kms=5;
						}
						else if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"Singanallur")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"Singanallur")==0))
						{
							kms=10;
						}
						else if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"Brookefields")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"Brookefields")==0))
						{
							kms=3.5;
						}
						else if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"RSPuram")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"RSPuram")==0))
						{
							kms=4.5;
						}
						else if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"Thudiyalur")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"Thudiyalur")==0))
						{
							kms=10;
						}
						else if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"Saravanampatti")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"Saravanampatti")==0))
						{
							kms=8;
						}
						else if((strcmp(b[j].pickup,"Gandhipuram")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"Gandhipuram")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=17;
						}
						else if((strcmp(b[j].pickup,"RailwayStation")==0 && strcmp(b[j].drop,"Airport")==0) || (strcmp(b[j].drop,"RailwayStation")==0 && strcmp(b[j].pickup,"Airport")==0))
						{
							kms=10;
						}
						else if((strcmp(b[j].pickup,"RailwayStation")==0 && strcmp(b[j].drop,"Ukkadam")==0) || (strcmp(b[j].drop,"RailwayStation")==0 && strcmp(b[j].pickup,"Ukkadam")==0))
						{
							kms=2;
						}
						else if((strcmp(b[j].pickup,"RailwayStation")==0 && strcmp(b[j].drop,"Singanallur")==0) || (strcmp(b[j].drop,"RailwayStation")==0 && strcmp(b[j].pickup,"Singanallur")==0))
						{
							kms=7;
						}
						else if(strcmp(b[j].pickup,"RailwayStation")==0 && strcmp(b[j].drop,"Brookefields")==0)
						{
							kms=3;
						}
						else if(strcmp(b[j].drop,"RailwayStation")==0 && strcmp(b[j].pickup,"Brookefields")==0)
						{
							kms=1.5;
						}
						else if((strcmp(b[j].pickup,"RailwayStation")==0 && strcmp(b[j].drop,"RSPuram")==0) || (strcmp(b[j].drop,"RailwayStation")==0 && strcmp(b[j].pickup,"RSPuram")==0))
						{
							kms=3;
						}
						else if((strcmp(b[j].pickup,"RailwayStation")==0 && strcmp(b[j].drop,"Thudiyalur")==0) || (strcmp(b[j].drop,"RailwayStation")==0 && strcmp(b[j].pickup,"Thudiyalur")==0))
						{
							kms=9;
						}
						else if((strcmp(b[j].pickup,"RailwayStation")==0 && strcmp(b[j].drop,"Saravanampatti")==0) || (strcmp(b[j].drop,"RailwayStation")==0 && strcmp(b[j].pickup,"Saravanampatti")==0))
						{
							kms=11;
						}
						else if((strcmp(b[j].pickup,"RailwayStation")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"RailwayStation")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=12;
						}
						else if((strcmp(b[j].pickup,"Airport")==0 && strcmp(b[j].drop,"Ukkadam")==0) || (strcmp(b[j].drop,"Airport")==0 && strcmp(b[j].pickup,"Ukkadam")==0))	
						{
							kms=12;
						}
						else if((strcmp(b[j].pickup,"Airport")==0 && strcmp(b[j].drop,"Singanallur")==0) || (strcmp(b[j].drop,"Airport")==0 && strcmp(b[j].pickup,"Singanallur")==0))
						{
							kms=5;
						}
						else if((strcmp(b[j].pickup,"Airport")==0 && strcmp(b[j].drop,"Brookefields")==0) || (strcmp(b[j].drop,"Airport")==0 && strcmp(b[j].pickup,"Brookefields")==0))
						{
							kms=9;
						}
						else if((strcmp(b[j].pickup,"Airport")==0 && strcmp(b[j].drop,"RSPuram")==0) || (strcmp(b[j].drop,"Airport")==0 && strcmp(b[j].pickup,"RSPuram")==0))
						{
							kms=10;
						}
						else if((strcmp(b[j].pickup,"Airport")==0 && strcmp(b[j].drop,"Thudiyalur")==0) || (strcmp(b[j].drop,"Airport")==0 && strcmp(b[j].pickup,"Thudiyalur")==0))
						{
							kms=18;
						}
						else if((strcmp(b[j].pickup,"Airport")==0 && strcmp(b[j].drop,"Saravanampatti")==0) || (strcmp(b[j].drop,"Airport")==0 && strcmp(b[j].pickup,"Saravanampatti")==0))
						{
							kms=10;
						}
						else if((strcmp(b[j].pickup,"Airport")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"Airport")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=25;
						}
						else if((strcmp(b[j].pickup,"Ukkadam")==0 && strcmp(b[j].drop,"Singanallur")==0) || (strcmp(b[j].drop,"Ukkadam")==0 && strcmp(b[j].pickup,"Singanallur")==0))
						{
							kms=9;
						}
						else if((strcmp(b[j].pickup,"Ukkadam")==0 && strcmp(b[j].drop,"Brookefields")==0) || (strcmp(b[j].drop,"Ukkadam")==0 && strcmp(b[j].pickup,"Brookefields")==0))
						{
							kms=4;
						}
						else if((strcmp(b[j].pickup,"Ukkadam")==0 && strcmp(b[j].drop,"RSPuram")==0) || (strcmp(b[j].drop,"Ukkadam")==0 && strcmp(b[j].pickup,"RSPuram")==0))
						{
							kms=5;
						}
						else if((strcmp(b[j].pickup,"Ukkadam")==0 && strcmp(b[j].drop,"Thudiyalur")==0) || (strcmp(b[j].drop,"Ukkadam")==0 && strcmp(b[j].pickup,"Thudiyalur")==0))
						{
							kms=10;
						}
						else if((strcmp(b[j].pickup,"Ukkadam")==0 && strcmp(b[j].drop,"Saravanampatti")==0) || (strcmp(b[j].drop,"Ukkadam")==0 && strcmp(b[j].pickup,"Saravanampatti")==0))
						{
							kms=12;
						}
						else if((strcmp(b[j].pickup,"Ukkadam")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"Ukkadam")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=12;
						}
						else if((strcmp(b[j].pickup,"Singanallur")==0 && strcmp(b[j].drop,"Brookefields")==0) || (strcmp(b[j].drop,"Singanallur")==0 && strcmp(b[j].pickup,"Brookefields")==0))
						{
							kms=9;
						}
						else if((strcmp(b[j].pickup,"Singanallur")==0 && strcmp(b[j].drop,"RSPuram")==0) || (strcmp(b[j].drop,"Singanallur")==0 && strcmp(b[j].pickup,"RSPuram")==0))
						{
							kms=10;
						}
						else if((strcmp(b[j].pickup,"Singanallur")==0 && strcmp(b[j].drop,"Thudiyalur")==0) || (strcmp(b[j].drop,"Singanallur")==0 && strcmp(b[j].pickup,"Thudiyalur")==0))
						{
							kms=20;
						}
						else if((strcmp(b[j].pickup,"Singanallur")==0 && strcmp(b[j].drop,"Saravanampatti")==0) || (strcmp(b[j].drop,"Singanallur")==0 && strcmp(b[j].pickup,"Saravanampatti")==0))
						{
							kms=11;
						}
						else if((strcmp(b[j].pickup,"Singanallur")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"Singanallur")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=12;
						}
						else if((strcmp(b[j].pickup,"Brookefields")==0 && strcmp(b[j].drop,"RSPuram")==0) || (strcmp(b[j].drop,"Brookefields")==0 && strcmp(b[j].pickup,"RSPuram")==0))
						{
							kms=2;
						}
						else if((strcmp(b[j].pickup,"Brookefields")==0 && strcmp(b[j].drop,"Thudiyalur")==0) || (strcmp(b[j].drop,"Brookefields")==0 && strcmp(b[j].pickup,"Thudiyalur")==0))
						{
							kms=7;
						}
						else if((strcmp(b[j].pickup,"Brookefields")==0 && strcmp(b[j].drop,"Saravanampatti")==0) || (strcmp(b[j].drop,"Brookefields")==0 && strcmp(b[j].pickup,"Saravanampatti")==0))
						{
							kms=10;
						}
						else if((strcmp(b[j].pickup,"Brookefields")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"Brookefields")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=16;
						}
						else if((strcmp(b[j].pickup,"RSPuram")==0 && strcmp(b[j].drop,"Thudiyalur")==0) || (strcmp(b[j].drop,"RSPuram")==0 && strcmp(b[j].pickup,"Thudiyalur")==0))	
						{
							kms=7;
						}
						else if((strcmp(b[j].pickup,"RSPuram")==0 && strcmp(b[j].drop,"Saravanampatti")==0) || (strcmp(b[j].drop,"RSPuram")==0 && strcmp(b[j].pickup,"Saravanampatti")==0))
						{
							kms=12;
						}
						else if((strcmp(b[j].pickup,"RSPuram")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"RSPuram")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=17;
						}
						else if((strcmp(b[j].pickup,"Thudiyalur")==0 && strcmp(b[j].drop,"Saravanampatti")==0) || (strcmp(b[j].drop,"Thudiyalur")==0 && strcmp(b[j].pickup,"Saravanampatti")==0))
						{
							kms=8.8;
						}		
						else if((strcmp(b[j].pickup,"Thudiyalur")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"Thudiyalur")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=24;
						}
						else if((strcmp(b[j].pickup,"Saravanampatti")==0 && strcmp(b[j].drop,"Podanur")==0) || (strcmp(b[j].drop,"Saravanampatti")==0 && strcmp(b[j].pickup,"Podanur")==0))
						{
							kms=32;
						}		
	}
	int cost(int j)
	{
		if(strcmp(b[j].vehtype,"Micro")==0)
		{
			fare=kms*11;
		}
		else if(strcmp(b[j].vehtype,"Mini")==0)
		{
			fare=kms*13;
		}
		else if(strcmp(b[j].vehtype,"Sedan")==0)
		{
			fare=kms*15;
		}
		else if(strcmp(b[j].vehtype,"Luxury")==0)
		{
			fare=kms*18;
		}
		if(fare<50)
		{
			fare=50;
		}
		return fare;
	}

