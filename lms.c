      #include <conio.h>
		#include <windows.h>
		#include <stdio.h>
		#include <stdlib.h>
		#include <string.h>
		#include <dos.h>
      	#include <time.h>

      #define RETURNTIME 15

		void programer();
      		void search();
		void sourcecode();
		void menu();
		void heading();
		void add();
		void searchbook();
		void display();
		void modify();
		void delbook();
      		void delstudent();
      		void del();
		void searchstudent();
      		void bookissue();
      		void bookreceive();
		struct time t;
		struct date d;
      struct myDate
			{
			int mm,dd,yy;
			};


		struct book
		{
		char name[30],auth_name[30],un_id[30],s_name[30];
      int book;
      struct myDate issued;
		struct myDate duedate;
		}b;

		struct student
		{
  		char name[30],unq_id[30],facul[30],sem[30];
		}s;

      int i,book=0;;
      char id[30];
      char tryagain;
      char name[30];

  		FILE *stu;
  		FILE *lib;
      FILE *issue;
      FILE *temp;


		void main()
			{
      	system("cls");
			menu();
			getch();
			}

void menu()
		{
		int choice;
		char ch;

		clrscr();

		heading();

		textcolor(12);
		gotoxy(30,10);
   	cprintf("!!!!~~~~MENU~~~~!!!!\n" );
      textcolor(15);
		printf("\n\t\t 1> Add New INFO                 		  ");
		printf("\n\t\t 2> Search                				");
		printf("\n\t\t 3> Display Complete Information 			");
		printf("\n\t\t 4> MOdify a book information    			");
		printf("\n\t\t 5> Delete record                		  ");
      printf("\n\t\t 6> Issue record					");
      printf("\n\t\t 7> Recieve record					");
		printf("\n\t\t 8> Source code ....        			");
		printf("\n\t\t 9> Programer's information      			");
		printf("\n\t\t10> Exit from the program             			");
		gotoxy(30,24);
      textcolor(30);

		cprintf("Choice : -          ");

		gotoxy(40,24);
    	scanf("%d",&choice);


    	switch (choice)
    	{
      case 1:
      	add();
            break;
      case 2:
      	search();
            break;
      case 3:
      	display();
            break;
      case 4:
      	modify();
            break;
      case 5:
      	del();
         	break;
      case 6:
      	bookissue();
      		break;
		case 7:
      	bookreceive();
      		break;
      case 10:
			printf("\n\n\t\tTHANK YOU....!!!PLease visit again ");
         	sleep(3);
    		 	  	exit(0);
        		break;

      case 9:
      	programer();
      		break;
      case 8:
      	sourcecode();
      		break;
      default:
      	printf("\n\n\t\t!!!!! wrong choice....!!!!\n");
         	sleep(3);
         menu();
         	break;
      }

}


		void heading()
		{

		int i,j,k=1,m;
      textcolor(6);
          printf("\t");
          printf("\a");
		for(i=0;i<=61;i++)
		cprintf("*");

		for(j=1;j<7;j++)
		{
      gotoxy(9,j);
		cprintf("*");
		printf("\n");

		}
		textcolor(LIGHTGREEN);
		gotoxy(16,3);

      cprintf("<<!!! WELCOME TO LIBRARY MANAGEMENT SYSTEM !!!>> ");
		gotoxy(21,4);
      cprintf("Dhnagadhi Engineering College (NAST)");
   	gotoxy(29,5);
      cprintf("DHANGADHI-KAILALI, NEPAL");
    	printf("\n");
		for(m=0;m<6;m++)
		{
      textcolor(1);
		gotoxy(71,k);
		cprintf("*");
		printf("\n");
		k++;
		}
		printf("\t");
		for(k=0;k<=62;k++)
		cprintf("*");
		getdate(&d);
		gettime(&t);
      textcolor(LIGHTRED);
		gotoxy(5,8);
		cprintf("\TIME :%d:%d:%d",t.ti_hour,t.ti_min,t.ti_sec);
   	gotoxy(61,8);
   	cprintf("DATE :%d:%d:%d\n",d.da_day,d.da_mon,d.da_year);
		}


	  	void add()
		{
      int choice;
      char tryagain='y';
      clrscr();
      heading();
      printf("\n\n\t\t*********** ADD info section ***********\n");
      printf("\n\n\t 1) Add Book info		");
      printf("\n\n\t 2) Add Student info		");
      printf("\n\n\t 3) Return to the main menu");

      printf("\n\n\n\n\t\tChoice   :- ");
      scanf("%d",&choice);

      switch(choice)
      {
      case 1:
       {
		clrscr();
		heading();


		lib=fopen("lib.txt","ab+");


      while(tryagain=='y' || tryagain=='Y')
      {
      clrscr();
      	heading();
      gotoxy(4,10);
      printf("Unique id of The Book");
      gotoxy(35,10);
    	printf("Name of The Book");
      gotoxy(63,10);
    	printf("Name of Author");
      gotoxy(10,12);
      fflush(stdin);
      gets(b.un_id);
      gotoxy(40,12);
      fflush(stdin);
      gets(b.name);
      gotoxy(68,12);
       fflush(stdin);
   	gets(b.auth_name);
    	fwrite(&b,sizeof(b),1,lib);
      gotoxy(20,15);
      book++;

      textcolor(GREEN);
		cprintf("New Book has been Added Successfully...");
      gotoxy(15,18);
    	printf("Want to add another record.........( y / n ) :-  ");
      fflush(stdin);
      tryagain=getche();
      }
 		fclose(lib);
      break;
      }


      case 2:

      tryagain='y';
      clrscr();
      heading();

    		stu=fopen("stu.txt","ab+");

		while(tryagain=='y' || tryagain=='Y')
    	  {
      clrscr();
      heading();

      gotoxy(4,11);
      printf("STUDENT NAME");
      gotoxy(25,11);
      printf("STUDENT ID");
      gotoxy(46,11);
    	printf("PROGRAM");
      gotoxy(67,11);
      printf("SEMESTER");
      gotoxy(5,13);
       fflush(stdin);
      gets(s.name);
      gotoxy(26,13);
       fflush(stdin);
      gets(s.unq_id);
      gotoxy(47,13);
       fflush(stdin);
      gets(s.facul);
      gotoxy(68,13);
      fflush(stdin);
      gets(s.sem);
      fflush(stdin);
      fwrite(&s,sizeof(s),1,stu);
      gotoxy(20,16);
      textcolor(GREEN);
  		cprintf("New student's information has been Added Successfully...");
      gotoxy(15,18);fflush(stdin);
    	printf("\aWant to add another record.........( y / n ) :-  ");

      fflush(stdin);
      tryagain=getche();
      }
      fclose(stu);
      break;


      case 3:
      menu();
      break;

      default:
      printf("\n\n\n\t\t\t\a Wrong choice !!!!");
      }
      sleep(1);
	add();

}

    	void searchbook()
      {
      char name[30];
    	int found=0,i=0;
      system("cls");
      heading();

      gotoxy(10,11);
      printf("Name of the book:");
      gotoxy(40,11);
      fflush(stdin);
      gets(name);
      lib=fopen("lib.txt","rb+");
      if(lib==NULL)
      printf("\n\n\tTHE File is empty.. .!!!");
      else
      {
      rewind(lib);
      while(fread(&b,sizeof(b),1,lib)==1)
      	{
      	if(strcmpi(b.name,(name))==0)
      		{
      system("cls");
      heading();
      gotoxy(30,9);
      textcolor(GREEN);
      cprintf("THE BOOK IS AVAILABLE");
      gotoxy(4,11);
      printf("Book id");
      gotoxy(5,13);
      printf("%s",b.un_id);
      gotoxy(35,11);
      fflush(stdin);
      printf("Book name");
      gotoxy(36,13);
      printf("%s",b.name);
      gotoxy(63,11);
      printf("Authour name");
      gotoxy(65,13);
      printf("%s",b.auth_name);
      found++;
      i++;
      }
       } printf("\n\n\tThere are %d books of this name",i);
      if(found==0)
      {
      system("cls");
      heading();
      gotoxy(15,16);
      textcolor(RED);
      cprintf("\n\aThe book you want to search is not available....");
      }

      gotoxy(20,18);
      printf("\n\t\aWant to another search ........( y / n ) :-  ");
      fflush(stdin);
      tryagain=getche();
      if(tryagain=='y'||tryagain=='Y')
      searchbook();
      else
      getche();
    	search();
      fclose(lib);
      }
		}


void modify()
   	{
      int choice=0;
      clrscr();
      heading();

      printf("\n\n\t\t*************** Modify Menu ****************");
      printf("\n\n\t\t\t 1>  Edit Book's info ");
      printf("\n\t\t\t 2>  Edit Student's info ");
      printf("\n\t\t\t 3>  Return in main menu ");

      printf("\n\n\n\t\tChoice    :-");
      scanf("%d",&choice);
      switch(choice)
      {
      case 1:
      {

	char d[30];
	int c=0;
	char another='y';

	clrscr();
   heading();

	gotoxy(30,10);
	printf("****Edit Books Section****");

	while(another=='y' || another=='Y')
		{
		printf("\n\n\tBook Id to be edited  : - ");
      fflush(stdin);
			gets(d);
		lib=fopen("lib.txt","rb+");
		while(fread(&b,sizeof(b),1,lib)==1)
		{
			if(strcmp(b.un_id,d)==0)
			{
				printf("\n\n\tThe book is availble");
				printf("\n\tThe Book ID:=%s",b.un_id);
				printf("\n\n\tNew name :- ");
            fflush(stdin);
            gets(b.name);
				printf("\n\tNew Author :-");
            fflush(stdin);
            gets(b.auth_name);

				printf("\n\n\tNew ID");
            fflush(stdin);
            gets(b.un_id);
				printf("\n\tThe record is modified");
				fseek(lib,ftell(lib)-sizeof(b),0);
            fflush(stdin);
				fwrite(&b,sizeof(b),1,lib);
				fclose(lib);
				c++;
			}
		}
      if(c==0)
				printf("\n\n\tNo record found");

		printf("\n\n\n\t\tModify another Record?(Y/N)");
		fflush(stdin);

		another=getche();
      modify();
      }

	}
   break;

   case 2:
   {
	int d[30],e;
	int c=0;
	char another='y';
	clrscr();
   heading();
	gotoxy(20,10);
	printf("****Edit student's info Section****");
	while(another=='y' || another=='Y')
	{
		clrscr();
		heading();

		printf("\n\n\tStudent Id to be edited :- ");
      fflush(stdin);
		gets(d);
		stu=fopen("stu.txt","rb+");
		while(fread(&s,sizeof(b),1,stu)==1)
		{
			if(strcmp(s.unq_id,(d))==0)
			{
				printf("\n\t\tThe student is availble");
				printf("\n\tThe Student ID:=%s",s.unq_id);
				printf("\n\n\tNew name:");
            fflush(stdin);
            gets(s.name);
				printf("\n\tNew programme:");
            fflush(stdin);
            gets(s.facul);
				printf("\n\tNew ID");
            fflush(stdin);
            gets(s.unq_id);
				printf("\n\tNew semester");
            gets(s.sem);
				printf("\n\n\t\tThe record is modified");
				fseek(stu,ftell(stu)-sizeof(b),0);
            fflush(stdin);
				fwrite(&s,sizeof(b),1,stu);
				fclose(stu);
				c++;
			}
		}
      if(c==0)
				printf("\n\n\t\tNo record found");

		printf("\n\n\n\t\tModify another Record?(Y/N)");
		fflush(stdin);
		another=getche();

      }
	}
   break;


   case 3:
   	menu();
      	break;

   default:
   	printf("\n\n\t\tWrong Choice .........\n\n\t\t");
      	system("PAUSE");
         	break;
 	}

   modify();

}


void delbook()
	{
	char another='y',id[30];
   int found=0;


   clrscr();

   heading();

   lib=fopen("lib.txt","ab+");
   temp=fopen("temp.txt","ab+");

               if(lib==NULL)
               	printf("\n\nNo records are found in the file...........");

               else
               	{
               		printf("\n\nBook ID which you want to delete...... :- ");
								fflush(stdin);
                  			gets(id);

               		while(fread(&b,sizeof(b),1,lib)==1)
               				{
                  		if(strcmp(b.un_id,id)!=0)
                  			fwrite(&b,sizeof(b),1,temp);
                           }
                  }

               fclose(lib);
               fclose(temp);

               remove("lib.txt");
               rename("temp.txt","lib.txt");



         printf("\n\n\a\aRecord successfully deleted..........\n\n");

         system("PAUSE");

       del();
       }


void delstudent()
	{
	char another='y',id[30];
   int found=0;

   clrscr();

   heading();

   stu=fopen("stu.txt","ab+");
   temp=fopen("temp1.txt","ab+");

               if(stu==NULL)
               	printf("\n\nNo records are found in the file...........");

               else
               	{
               		printf("\n\nStudent ID to be deleted    :-   ");
								fflush(stdin);
                  			gets(id);

               		while(fread(&s,sizeof(s),1,lib)==1)
               				{
                  		if(strcmp(s.unq_id,id)!=0)
                  			fwrite(&s,sizeof(s),1,temp);
                           }
                  }

               fclose(stu);
               fclose(temp);

               remove("stu.txt");
               rename("temp1.txt","stu.txt");



         printf("\n\n\a\aRecord successfully deleted..........\n\n");

         system("PAUSE");

       del();

   }


      void display()
      {
      int i=0,choice=0,j=13;

      system("cls");

      heading();

      gotoxy(25,10);
   	printf("!!!!~~~~~~DISPLAY MENU~~~~~~!!!!\n" );
		printf("\n\n\t\t1> Display all Book's info              ");
		printf("\n\n\t\t2> Display all student's info           ");
      printf("\n\n\t\t3> Return to main menu          	");
      gotoxy(30,24);
		printf("Choice : -          ");
		gotoxy(40,24);
    		scanf("%d",&choice);

    	switch (choice)
    	{
      case 1:
      {
      int j=13;
      clrscr();
      heading();
      lib=fopen("lib.txt","ab+");
      if(lib==NULL)
      printf("\n\n\n\t\aThe file is Empty");
      else
      {
      textcolor(GREEN);
      gotoxy(23,10);
      cprintf("!!!!!!!!!! BOOK'S INFO !!!!!!!!!!");
      printf("\n\n\tNAME\t\t\tunique ID\t\tAUTHor name");
      while(fread(&b,sizeof(b),1,lib)==1)
      {
      gotoxy(5,j);
        printf("%s",b.name);
      gotoxy(33,j);
      	printf("%s",b.un_id);
      gotoxy(55,j);
      	printf("%s",b.auth_name);

      printf("\n");

      i++;
      j++;
      }

        printf ("\n\n\t\t\a THERE are %d Books in the stock",i);

        	printf("\n\n\t\aPress any key to return on menu");
         	fclose(lib);
        			getch();
      }
      break;
      }


   case 2:
      {
      int i=0,j=13;
      clrscr();
      heading();
      stu=fopen("stu.txt","ab+");
      if(stu==NULL)
      printf("\n\n\n\tThe file is Empty");
      else
      {
      textcolor(GREEN);
      gotoxy(23,9);
      cprintf("!!!!!!!!!!Student's INFO!!!!!!!!!!");
      printf("\n\n\tNAME\t\t\tUNIQUE ID\t\PROGRAM\t\tSEMESTER");
      while(fread(&s,sizeof(s),1,stu)==1)
       {
       gotoxy(2,j);
        printf("%s",s.name);
        gotoxy(33,j);
      printf("%s",s.unq_id);
      gotoxy(48,j);
      printf("%s",s.facul);
      gotoxy(65,j);
      printf("%s",s.sem);
      printf("\n");
      j++;

        } printf("\n\n\n\t\apress any key to return on menu");
        }
      fclose(stu);
      getch();
      break;
      }

      case 3:
      menu();

      default :
      		printf("\n\n\t\tERROR...!! please input a valid choice\n\n\t");
            system("PAUSE");
            	break;
      }

      display();

      }


      void searchstudent()
      {
    	int found=0,i=0;
      char name[30];
      system("cls");
      heading();
      gotoxy(10,11);
      printf("ENter NAme of student : -  ");
      	gotoxy(40,11);
      		fflush(stdin);
      			gets(name);

      stu=fopen("stu.txt","ab+");

      if(stu==NULL)
      	printf("\n\n\a THe file is empty...!!!");

      else
      	{
      	rewind(stu);

      	while(fread(&s,sizeof(s),1,stu)==1)
      		{
      		if(strcmpi(s.name,(name))==0)
      			{
      			system("cls");
               heading();
      			gotoxy(30,10);
      			textcolor(GREEN);

      				cprintf("STUDENT'S INFO");
      					gotoxy(4,11);
                  printf("Student id");
      					gotoxy(5,13);
      				printf("%s",s.unq_id);
      					gotoxy(26,11);
      				printf("student name");
      					gotoxy(27,13);
      				printf("%s",s.name);
      					gotoxy(47,11);
      				printf("Faculty");
      					gotoxy(48,13);
      				printf("%s",s.facul);
      					gotoxy(68,11);
      				printf("semester");
      					gotoxy(69,13);
      				printf("%s",s.sem);
               found++;
      			i++;
      			}
      		}
       printf("\n\n\t There are %d student of this name",i);

      if(found==0)
      	{
      	system("cls");
     	 		heading();
         gotoxy(15,14);
      		textcolor(RED);
      			cprintf("\nThe student's info, you want to search is not available....");
      	}
   	}
		gotoxy(20,16);
      	printf("\n\t\aDO you want to another search ........( y / n ) :-  ");
      		fflush(stdin);
   	tryagain=getche();
   		if(tryagain=='y'||tryagain=='Y')
      		searchstudent();
      	else
      		getche();

      search();

      fclose(stu);
      getch();
   }


   void search()
			{
      int choice;
      clrscr();
      heading();
      gotoxy(19,10);
      textcolor(RED);
      cprintf("!!!!!!!!!!!!!!! SEARCH MENU !!!!!!!!!!!!!!!");
      printf("\n\n\n\t\t\t 1>Book Search				");
      printf("\n\n\t\t\t 2>stdudent Search			");
      printf("\n\n\t\t\t 3>Return to main menu			");
      gotoxy(30,20);
      printf("choice		: -  ");
      scanf("\t%d",&choice);
      if(choice==1)
      	{
      	searchbook();
      		search();
      	}
      else if(choice==2)
      		{
      searchstudent();
      search();
      		}
      else if(choice==3)
		menu();

      else
      {
      printf("\awrong data input");
      search();
      }
	}



      void bookissue()
   		{
       int choice=0,k=0;
       char t[30],sname[30],id[10],copy[30];
       FILE *ftem;
       	getdate(&d);
		gettime(&t);

    clrscr();
    heading();
    gotoxy(5,10);
    printf("********************************ISSUE SECTION**************************");
    gotoxy(10,13);
    printf("1. Issue a Book");
    gotoxy(10,15);
    printf("2. View Issued Book");
    gotoxy(10,17);
    printf("3. Return in main menu");
    gotoxy(10,20);
    printf("Choice    : -  ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
    {
      struct dosdate_t d;
      int count;
    clrscr();
    heading();
			gotoxy(15,15);
			printf("**********Issue Book section**********");

			lib=fopen("lib.txt","ab+");
         stu=fopen("stu.txt","ab+");
			issue=fopen("issue.txt","ab+");
         ftem=fopen("templib.txt","ab+");

         gotoxy(10,17);
         printf("Book Id  :-  ");
         fflush(stdin);
			gets(t);
         rewind(lib);
         while(fread(&b,sizeof(b),1,lib)==1)
         if(strcmpi(b.un_id,t)==0)
			{
         clrscr();
         heading();
				 gotoxy(10,10);
				 printf("The book record is available");
				 gotoxy(10,14);
				 printf("The name of book is %s",b.name);
				 gotoxy(10,16);
				 printf("Student name   : - ");
             fflush(stdin);
				 gets(sname);
             gotoxy(10,18);
             printf("Student ID    : - ");
             fflush(stdin);
             gets(id);

			     _dos_getdate(&d);
			     b.issued.dd=d.day;
			     b.issued.mm=d.month;
			     b.issued.yy=d.year;


			     b.duedate.dd=b.issued.dd+RETURNTIME;   //for return date
			     b.duedate.mm=b.issued.mm;
			     b.duedate.yy=b.issued.yy;
			     if(b.duedate.dd>30)
			     {
				 	b.duedate.mm+=b.duedate.dd/30;
				 	b.duedate.dd-=30;
			     }
			     if(b.duedate.mm>12)
			     {
				b.duedate.yy+=b.duedate.mm/12;
				b.duedate.mm-=12;

			     }



             while(fread(&s,sizeof(s),1,stu)==1)
             	if(strcmpi(s.name,sname)==0 && strcmpi(s.unq_id,id)==0)
             		{
               		strcpy(b.s_name,s.name);
              		printf("\nThe BOOK of ID %s is issued",b.un_id);

               		gotoxy(10,24);
			     		printf("To be return:%d-%d-%d\n\n",b.duedate.dd,b.duedate.mm,b.duedate.yy);

              		fwrite(&b,sizeof(b),1,issue);
                		count=10;
            		}

             if (count==10)
             	{
               rewind(lib);

            		while(fread(&b,sizeof(b),1,lib)==1)
            			{
               		if(strcmpi(b.un_id,t)!=0)
               			fwrite(&b,sizeof(b),1,ftem);
               		}
                  fclose(lib);
                  fclose(ftem);

         			remove("lib.txt");
         			rename("templib.txt","lib.txt");
                  }


               else
               	printf("ERROR ......\n\n");




         fclose(stu);
       	fclose(issue);


         system("PAUSE");

    		}



    }break;

    case 2:
    	{
		int j=14;
		struct dosdate_t d;
		clrscr();
               heading();
               gotoxy(3,10);
		printf("******************************Issued book list*****************************\n");
		gotoxy(2,12);
		printf(" BOOK NAME   ID 	STUDENT NAME    ISSUED DATE    RETURN DATE");

		   issue=fopen("issue.txt","ab+");
         stu=fopen("stu.txt","ab+");

		while(fread(&b,sizeof(b),1,issue)==1)
		{

			gotoxy(2,j);
			printf("%s",b.name);
			gotoxy(18,j);
			printf("%s",b.un_id);
			gotoxy(30,j);
			printf("%s",b.s_name);
         gotoxy(40,j);
			printf("%d-%d-%d",b.issued.dd,b.issued.mm,b.issued.yy );
			gotoxy(55,j);
			printf("%d-%d-%d",b.duedate.dd,b.duedate.mm,b.duedate.yy);


			_dos_getdate(&d);
			gotoxy(50,25);
			printf("Current date=%d-%d-%d",d.day,d.month,d.year);
			j++;

		}
		fclose(lib);
		gotoxy(1,25);
		getch();
	}
	break;
  case 3:

    menu();
    break;
         }

      }


void bookreceive()
  			{

         char id[10];
         FILE *ftemp;

         clrscr();
         heading();

         gotoxy(15,15);

			printf("**********Recieve Book section**********");

			lib=fopen("lib.txt","ab+");
			issue=fopen("issue.txt","ab+");
         ftemp=fopen("templib1.txt","ab+");


         	gotoxy(10,17);
         printf("Book Id    : - ");
         fflush(stdin);
			gets(id);

         while(fread(&b,sizeof(b),1,issue)==1)
         	{
         	if(strcmpi(b.un_id,id)!=0)
		         fwrite(&b,sizeof(b),1,ftemp);
            else
            	fwrite(&b,sizeof(b),1,lib);
            }

			fclose(lib);
         fclose(issue);
         fclose(ftemp);

         remove("issue.txt");
         rename("templib1.txt","issue.txt");



         printf("The book has  received .THANK YOU\n\n");

         system("PAUSE");


                    main();
  }

      void programer()
      {
      clrscr();
      printf("please wait ....");
             sleep(5);
             clrscr();
      heading();
      textcolor(GREEN);
      gotoxy(2,9);
      cprintf("-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_ programer's info -_-_-_-_-_-_-_-_-_-_-_-_-_-_-_");

      textcolor(9);
      gotoxy(5,11);
      cprintf("NAME");
      gotoxy(30,11);
      cprintf("CONTACT no");
      gotoxy(56,11);
      cprintf("E-mail ID");
      textcolor(10);
      gotoxy(2,13);  sleep(1);
      cprintf("\aSrijana Gupta");
      gotoxy(30,13);
      cprintf("9814634494");
      gotoxy(52,13);
      cprintf("redrose_1638@yahoo.com");
      gotoxy(2,15);            sleep(1);
      cprintf("\aGokul Kunwar");
      gotoxy(30,15);
      cprintf("9848467762");
      gotoxy(52,15);
      cprintf("knwrgokul@rocketmail.com");
      gotoxy(2,17);             sleep(1);
      cprintf("\aJanak Bist");
      gotoxy(30,17);
      cprintf("9868444438");
      gotoxy(52,17);
      cprintf("zanakbist@yahoo.com");
      gotoxy(2,19);            sleep(3);
      cprintf("\aRoman poudel");
      gotoxy(30,19);
      cprintf("9812630308");
      gotoxy(52,19);
      cprintf("roman_poudel@ymail.com");
      gotoxy(2,21);          sleep(1);
      cprintf("\aBishnu joshi");
      gotoxy(30,21);
      cprintf("9848415508");
      gotoxy(52,21);
      cprintf("joshibishanu@yahoo.com");
      gotoxy(2,23);            sleep(1);
      cprintf("\aLal Bahadur Chaudhary");
      gotoxy(30,23);
      cprintf("9848754201");
      gotoxy(52,23);
      cprintf("not available");
      gotoxy(2,25);           sleep(1);
      cprintf("\aMahesh Chaudhary");
      gotoxy(30,25);
      cprintf("9848471417");
      gotoxy(52,25);
      cprintf("maheshlov_s143@yahoo.com");
      gotoxy(25,27);            sleep(1);
      printf("Press any key to return on main menu");
      getche();
      menu();
      }

      void sourcecode()
		{
    	FILE *fp;
		char c;
      int i=0;
    	clrscr();
    	heading();
    	fp = fopen("lms.c","r");



      do
    	{
         c = getc(fp);
         putchar(c);
       i++;
       if(i%300==0)
         getch();
      }
    	while(c!=EOF);
      if(i%200==0)
         getch();

      fclose(fp);

    	getche();    clrscr();

            main();
		}


void del()
{
int choice;

clrscr();
heading();

printf("\n\n\t**********************Welcome to Delete menu********************");

printf("\n\n\t\t 1. Delete book");
printf("\n\t\t 2. Delete student");
printf("\n\t\t 3. Return to main menu");

printf("\n\n\t\tChoice\t:-");
		scanf("%d",&choice);

switch(choice)
	{
   case 1:
   	delbook();
   		break;
   case 2:
   	delstudent();
      	break;
   default:
   	printf("\n\n\n\t\tWrong Choice selected ..................\n\n\t\t ");
      	system("PAUSE");
      		break;
   }

del();
}
