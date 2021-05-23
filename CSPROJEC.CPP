#include<fstream.h>
#include<graphics.h>
#include<iomanip.h>
#include<process.h>
#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include<stddef.h>

// class definitions
#include<student.h>
#include<faculty.h>
#include<admin.h>
#include<timetable.h>
#include<course.h>
#include<info.h>
#include<visitor.h>


void main() {
	initial_design();
   	MainMenu();
}

void MainMenu() {

	int ch,flag=0;char opt,ex;student s;   int i,b,j;
	admin a;    faculty f;
	do {
	    flag=0;
		clrscr();
		textcolor(YELLOW);
		SHOWDATE();

		gotoxy(27,3);
		cprintf("M A I N  ---  M E N U");
		cout<<endl;
		gotoxy(27,4);
		cprintf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
		 gotoxy(30,7);
		cprintf("1.   Visitor menu");
		gotoxy(30, 9) ;
		cprintf("2    Student login");
		 gotoxy(30,11);
		cprintf("3.   Faculty login");
		 gotoxy(30,13);
		cprintf("4.   Administrator");
		 gotoxy(30,15);
		cprintf("5.   Exit program");
		  gotoxy(30,17);
		cprintf("Please enter your choice : ");
		cin>>ch;

		switch(ch) {
			case 1: textcolor(LIGHTRED);
				visitor.visitorMenu();
				flag=1;
				break;
			case 2: textcolor(LIGHTCYAN);
				s.studentLogin();
				flag=1;
				break;
		      case 3:textcolor(LIGHTMAGENTA);
				f.facultyLogin();
				flag=1;
				break;
			case 4: textcolor(LIGHTGREEN);
				admin::adminLogin();
				flag=1;
			       break;
			case 5: cout<<"\n\t\t\t\t";
				cprintf("Exiting....");
				getch();
				exit(0);
				break;
		    default:cout<<"\n\t\t\t\t";
			      cprintf("No such choice exists.");
		}
		if(flag!=1) {
			cout<<"\n\t\t\t\t";
			cprintf("Do you want to continue ? :");
			cin>>opt;
		}
		else
		opt='y';
		textcolor(YELLOW);
    }while(opt=='y'||opt=='Y');

    cout<<"\n\t\t";
    cprintf("Are you sure you want to EXIT the program ? (y,Y) : ");
    cin>>ex;
    if(ex=='y'||ex=='Y') {
	cout<<"Exiting in 3";delay(1000);
	cout<<"\b2";delay(1000);
	cout<<"\b1";delay(1000);
	exit(0);
	}
}

void SHOWDATE() {
	char z[12][20]= {"January",
					"February",
					"March",
					"April",
					"May",
					"June",
					"July",
					"August",
					"September",
					"October",
					"November",
					"December"};

	textcolor(YELLOW);
	date d;
	getdate(&d);
	gotoxy(65,1);
	cout<<(int)d.da_day<<" ";
	int l=d.da_mon;
	l=l-1;
	cout<<z[l]<<" ";
	cout<<d.da_year;
}

void initial_design() {
	int i,j;
	char *fname[] = {  "ZERTECH",
			   "ONLINE",
			   "LEARNING",
			   "CLASSES"
			};
	// request auto detection
    int gdriver = DETECT, gmode, errorcode;
    int style, midx, midy;

   	// initialize graphics and local variables
   	initgraph(&gdriver, &gmode, "C:\\Turboc3\\BGI");

   	// read result of initialization
   	errorcode = graphresult();
  	if (errorcode != grOk)                 // an error occurred
   	{
        printf("Graphics error: %s\n", grapherrormsg(errorcode));
        printf("Press any key to halt:");
        getch();
        exit(1); // terminate with an error code
    }
	delay(2000);
	midx = getmaxx() / 2;
	midy = (int)(getmaxy() / 2.5);
	setcolor(YELLOW);
	line(3,5,midx*2-3,5);
	line(3,midy*2+90,midx*2-3,midy*2+90);
	line(3,5,3,midy*2+90);
	line(midx*2-3,5,midx*2-3,midy*2+90);
	settextstyle(3,HORIZ_DIR,10);
	settextjustify(CENTER_TEXT, CENTER_TEXT);
	outtextxy(midx+5,midy-30,"Welcome ");
	outtextxy(midx+160,midy+90,"to..... ");
	delay(1500);
	cleardevice();
  	for(j=10;j<=midx;j+=10)
		line(j,0,0,midy*2+170);
  	for(;j<=midx*2;j+=10)
		line(j,0,midx*2,midy*2+170);
   	for(i=0;i<4;i++) {

   		cleardevice();
		for(j=10;j<=midx;j+=10) {
	   	setcolor(YELLOW);
		line(j,0,0,midy*2+150);
		}
	 	for(;j<=midx*2;j+=10)
			line(j,0,midx*2,midy*2+150);

		// set the text style
	    settextstyle(1, HORIZ_DIR,10);
		setfillstyle(SOLID_FILL,YELLOW);
		bar(5,midy-30,midx*2-5,midy+110);
		setcolor(BLACK);
		line(10,midy-25,midx*2-10,midy-25);
		line(10,midy+105,midx*2-10,midy+105);
		line(10,midy-25,10,midy+105);
		line(midx*2-10,midy-25,midx*2-10,midy+105);

		// output a message
		outtextxy(midx,midy+20, fname[i]);
		if(i==1)
			delay(1000);
	    delay(2000);
   }
   cleardevice();
   closegraph();
}
