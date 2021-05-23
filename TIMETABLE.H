class timetable {
	int cno;
	char day[10];
	char sub[5][25];
	int y[3];
	int grade;
	int stan[3];
	public:
		void stu_display();
		void fac_display();
		void stu_input();
		void fac_input();
		int fun(int);
		int yoyo(int);
		char *retday();
		void fac_displayee1(int);
		void stu_displayee1();
		void listfacname(int);

};


char* timetable::retday()
{	return day;
}

int timetable::fun(int j)
{
	if(j==grade)
		return 1;
	else
		return 0;
}

int timetable::yoyo(int j)
{
	int i,flag=0;
	for(i=0;i<3;i++)
	{
		if(y[i]==j)
		{       flag=1;
			fac_displayee1(i);
		}
	}
	if(flag==0)
		return 0;
	else
		return 1;
}

void timetable::stu_input()
{       int i,z,t,j;            info a;
	course c;  char *p1=NULL;
	fstream f;
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFILE NOT OPENED SUCCESSFULLY.";
		getch();
		exit(1);
	}
	cout<<"\nDay : ";
	gets(day);
	t=sizeof(c);
	f.seekg(-t,ios::end);
	f.read((char*)&c,t);
	z=c.retCourseNo();
	f.close();
	d:
	cout<<"\nEnter class : ";
	cin>>grade;
	if(grade>12||grade<11)
	{
		cout<<"\nPlease enter correct class. !";
		gotoxy(1,11);
		clreol();
		gotoxy(1,12);
		clreol();
		gotoxy(1,13);
		clreol();
		goto d;
	}
	clrscr();
	cout<<"\n\t\tAvailable Courses ";
	c.listCourses();
	if(z%2==0)
	{	cout<<endl;
		cout<<z+1<<". Nil\n";
	}
	else
	cout<<"\t"<<z+1<<".Nil\n";
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFILE NOT OPENED SUCCESSFULLY.";
		getch();
		exit(1);
	}
	for(i=0;i<3;i++)
	{       jj:
		gotoxy(2,12+i);
		cout<<"Enter course number for period "<<i+1<<": ";
		cin>>cno;
		if(z+1<cno||cno<1)
		{	cout<<"Course not available";
			delay(1000);
			gotoxy(1,12+i);
			clreol();
			gotoxy(1,13+i);
			clreol();
			goto jj;
		}
		y[i]=cno;
		if(cno==z+1)
		{
			 strcpy(sub[i],"NIL");
			 y[i]=0;
			 continue;
		}
		f.clear();
		f.seekg(0,ios::beg);
		while(f.read((char*)&c,t))
		{       p1=c.retCourse();
			if(c.retCourseNo()==cno)
			strcpy(sub[i],p1);
		}
	}
	f.close();
}

void timetable::fac_input()
{       int i,z,t,j;            info a;
	course c;   fstream f;  char *p1=NULL;
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFILE NOT OPENED SUCCESSFULLY.";
		getch();
		exit(1);
	}
	cout<<"\nDay : ";
	gets(day);
	t=sizeof(c);
	f.seekg(-t,ios::end);
	f.read((char*)&c,t);
	z=c.retCourseNo();
	f.close();
	clrscr();
	cout<<"\n\t\tAvailable Courses ";
	c.listCourses();
	cout<<endl;
	cout<<z+1<<". Nil\n";
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFILE NOT OPENED SUCCESSFULLY.";
		getch();
		exit(1);
	}
	for(i=0;i<3;i++)
	{       jj:
		gotoxy(2,12+i);
		cout<<"Enter course number for period "<<i+1<<": ";
		cin>>cno;
		if(z+1<cno||cno<1)
		{	cout<<"Course not available";
			delay(1000);
			gotoxy(1,12+i);
			clreol();
			gotoxy(1,13+i);
			clreol();
			goto jj;
		}
		y[i]=cno;
		if(cno==z+1)
		{
			 strcpy(sub[i],"NIL              ");
			 y[i]=0;
			 stan[i]=100;
			 continue;
		}
		aa:
		gotoxy(1,13+i);
		cout<<"Enter class : ";
		cin>>stan[i];
		if(stan[i]>12||stan[i]<11)
		{
			cout<<"Incorrect class entered !";
			delay(1000);
			gotoxy(1,13+i);
			clreol();
			gotoxy(1,14+i);
			clreol();
			goto aa;
		}
		f.clear();
		f.seekg(0,ios::beg);
		while(f.read((char*)&c,t))
		{       p1=c.retCourse();
			if(c.retCourseNo()==cno)
			strcpy(sub[i],p1);
		}
	}
	f.close();
}

void timetable::stu_display()
{
	int i,z;
	cout<<"\nDay :"<<day<<"\tClass : "<<grade<<endl;
	for(i=0;i<3;i++)
	{

		cout<<"Period "<<i+1<<" : \t";
		cout<<"Course :"<<sub[i];
		cout<<setw(15)<<" by ";
		listfacname(y[i]);
		if(y[i]==0)
		cout<<"---";
		cout<<endl;
	}
}
int yay=0;
void timetable::stu_displayee1()
{
	int i,z;
	cout<<"\nDay :"<<day<<endl;
	for(i=0;i<3;i++,yay++)
	{
		cout<<"Period "<<i+1<<" : \t";
		cout<<"Course :"<<sub[i];
		gotoxy(50,3+yay);
		cout<<" by ";
		listfacname(y[i]);
		if(y[i]==0)
		cout<<"---";
		cout<<endl;
	}
	yay+=2;
}

void timetable::fac_display()
{
	int i,z;       info a;
	cout<<"\nDay :"<<day;
	for(i=0;i<3;i++)
	{

		cout<<"\nPeriod "<<i+1<<" : \t";
		cout<<"Course :"<<sub[i];
		cout<<setw(15)<<"Class : ";
		if(stan[i]==100)
		cout<<"---";
		else
		{       cout<<stan[i];
			cout<<" by ";
			listfacname(y[i]);
		}
	}
}

void timetable::fac_displayee1(int i)
{
	cout<<"\nDay :"<<day<<"\t Class : ";
	if(stan[i]==100)
	cout<<"---";
	else
	{       cout<<stan[i];
		cout<<"\nPeriod "<<i+1<<" : \t";
		cout<<"Course :"<<sub[i];
	}
	cout<<endl;
	getch();
}

void timetable::listfacname(int l)
{       fstream f;    int flag=0,r;
	info a;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully1.";
		getch();
		exit(1);
	}
	while(f.read((char*)&a,sizeof(a)))
	{
		r=a.one(l);
		if(r==1&&flag==1)
		{
			cout<<"/ ";
			a.fac_dispname();
			continue;
		}
		if(r==1)
		{       a.fac_dispname();
			flag=1;
			continue;
		}
	}
	f.close();
	if(l==0)
	return;
	if(flag==0)
		cout<<"--- ";

}
