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
class student                                   //Managing student data
{
	int id;
	char pass[20];
	public:
		void stulog();
		void studata(int);
		void stu_display(int);
		void stu_listrec();
		void stu_searchrec();
		void stu_modifyrec(int);
		void list_stutime(int);
		void stu_dispcor(int);
		void stu_modpass(int);
		void stu_modname(int);
		void stu_modemail(int);
		void stu_modclass(int);
		void stu_modinst(int);
		void stu_modcor(int);
};
class faculty                                 //Managing faculty data
{
	int id;
	char pass[20];
	public:
		void faclog();
		void facdata(int);
		void fac_display(int);
		void fac_listapp();
		void fac_listrec();
		void fac_modifyrec(int);
		void fac_searchrec();
		void list_factime(int);
		void fac_delrecs();
		void fac_modpass(int);
		void fac_modname(int);
		void fac_modcont(int);
		void fac_modemail(int);
		void fac_modcor(int);
};
class admin                                   //Managing admin data
{
	char admid[5];
	char admpass[15];
	public:
		void adminlog();
		void admdata();
		void search();
		void courses();
		void view();
		void delent();
		void job();
		void timetab();
		void stu_addtime();
		void fac_addtime();
		void stu_deltime();
		void fac_deltime();
		void stu_delrec();
		void fac_delrec1();
		void modify_stutime();
		void modify_factime();
		void list_stutimereo();
		void list_factimereo();
};
class info                               //Managing student/faculty details
{
	int serial;
	char p[5];
	char name[20];
	int grade;
	int learn;
	int n;
	int age;
	int exp;
	char cont[15];
	char univ[20];
	char email[40];
	char str[5][25];
	public:
		void display(int);
		void enter(int);
		void facenter(int);
		void mycor();
		void facdisplay(int);
		int one(int);
		char *retpass();
		void fac_dispname();
		void modemail();
		void modpass();
		void modname()
		{
			cout<<"\nEnter new name :";
			gets(name);
		}
		void modcont();
		void modclass();
		void modinst()
		{
			cout<<"\nEnter new school name :";
			cin>>univ;
		}
		int stu_modifycor();
		int fac_modifycor();
		int retid()
		{	return serial;  }
		int retcl()
		 {	return grade;   }
		 int retn()
		 {      return n;    }

};
class course                             //Managaing courses
{       int no;
	char cor[30];
	public: void addcor();
		void deletecor();
		void listcor();
		void cor_enter(int r)
		{       no=r;
			cout<<"Enter course name : ";
			gets(cor);
		}
		void cor_display()
		{
			cout<<no;
			cout<<" ";
			cout<<cor;
		}
		char *retcor();
		int retno()
		{	return no;}

};
class timetable
{
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

int helo=2;
int hi=2;


void visit();              //Functions for time table modification
void about();

void fac_addrec();
void stu_addrec();

int autogeneration();
int autogen();
int autogener();                  //Functions for autogeneration

char* course::retcor()
{	return cor;
}
char* timetable::retday()
{	return day;
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
	z=c.retno();
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
	c.listcor();
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
		{       p1=c.retcor();
			if(c.retno()==cno)
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
	z=c.retno();
	f.close();
	clrscr();
	cout<<"\n\t\tAvailable Courses ";
	c.listcor();
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
		{       p1=c.retcor();
			if(c.retno()==cno)
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

void course::addcor()
{
	int r;
	r=autogeneration();
	fstream f;
	f.open("cour.dat",ios::app|ios::binary);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	cor_enter(r);
	f.write((char*)this,sizeof(course));
	cout<<"\nCourse added.";
	f.close();
}

void course::listcor()
{          fstream f;  int i=1,j=3;
	f.open("cour.dat",ios::in|ios::binary|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	course c;
	cout<<endl;
	while(f.read((char*)&c,sizeof(c)))
	{       if(i<0)
		{	gotoxy(35,j);
			j++;
		}
		c.cor_display();
		i*=-1;
		if(i>0)
			cout<<endl;
	}
	int n=f.tellg();
	if(n==0)
	{
		cout<<"\nNo course available !";
		getch();
	}
	f.close();
}

void course::deletecor()
{
	fstream f1,f2; course c; int i,flag=0;
	f1.open("cour.dat",ios::in|ios::out|ios::binary);
	if(f1.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("stemp.dat",ios::out|ios::binary);
	if(f2.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	cout<<"\nEnter course number to be deleted :";
	cin>>i;
	while(f1.read((char*)&c,sizeof(c)))
	{
		if(i==c.retno())
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nNo such course exists.";
		delay(2000);
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&c,sizeof(c)))
	{
		if(i!=c.retno())
		f2.write((char*)&c,sizeof(c));
	}
	cout<<"\nCourse has been deleted.";
	getch();
	f1.close();
	f2.close();
	remove("cour.dat");
	rename("stemp.dat","cour.dat");
}

int autogeneration()
{
	fstream f;int r,z;course c;
	f.open("cour.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile cannot be opened successfully.";
		getch();
		exit(0);
	}
	f.seekg(0,ios::end);
	int n=f.tellg();
	f.clear();
	z=sizeof(c);
	if(n==0)
		r=1;
	else
	{       f.seekg(-z,ios::end);
		f.read((char*)&c,z);
		r=c.retno();
		++r;
	}
	f.close();
	return r;
}

int autogener()
{
	fstream f,f1;
	int r,z,n,n1,i;
	info a;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile cannot be opened successfully.1";
		getch();
		exit(0);
	}
	f1.open("faculty1.dat",ios::binary|ios::in|ios::out);
	if(f1.fail())
	{
		cerr<<"\nFile cannot be opened successfully.2";
		getch();
		exit(0);
	}
	z=sizeof(a);
	f.seekg(0,ios::end);
	n=f.tellg();
	if(n==0)
	{
		f1.seekg(0,ios::end);
		n1=f1.tellg();
		if(n1==0)
			r=1;
		else
		{       f1.clear();
			f1.seekg(-z,ios::end);
			f1.read((char*)&a,z);
			r=a.retid();
			++r;
		}
	}
	else
	{       f.clear();
		f.seekg(-z,ios::end);
		f.read((char*)&a,z);
		r=a.retid()+1;
	}
	f.close();
	f1.close();
	return r;
}

int autogen()
{
	fstream f;
	int r,z;      info a;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile cannot be opened successfully.";
		getch();
		exit(0);
	}
	f.seekg(0,ios::end);
	int n=f.tellg();
	f.clear();
	z=sizeof(a);
	if(n==0)
		r=1;
	else
	{       f.seekg(-z,ios::end);
		f.read((char*)&a,z);
		r=a.retid();
		++r;
	}
	f.close();
	return r;
}
void info::fac_dispname()
{
	cout<<name;
}
int info::one(int l)
{
	if(n==l)
	return 1;
	else
	return 0;
}

int info::stu_modifycor()
{
	int i,z,t;    course c;
	fstream f;  char *p1=NULL;
	a:
	gotoxy(1,10);
	cout<<"\nHow many courses do you want to learn : ";
	cin>>learn;
	if(learn>5)
	{
		cout<<"\nMaximum courses that can be allotted is 5.";
		delay(2000);
		gotoxy(1,11);
		clreol();
		gotoxy(1,10);
		clreol();
		goto a;
	}
	clrscr();
	cout<<"\n\tCourses available to choose from  ";
	c.listcor();
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	t=sizeof(c);
	f.seekg(-t,ios::end);
	f.read((char*)&c,t);
	z=c.retno();
	f.seekg(0,ios::end);
	if(f.tellg()==0)
	{	cout<<"\n No course available. Try again later.";
		getch();
		f.close();
		return 1;
	}
	f.clear();
	cout<<endl;
	for(i=0;i<learn;i++)
	{
		d:
		gotoxy(1,12+i);
		cout<<"Enter course("<<i+1<<") no: ";
		cin>>n;
		if(n>z)
		{
			cout<<"Course not available. Please enter again.\n";
			delay(1000);
			gotoxy(1,13+i);
			clreol();
			gotoxy(1,12+i);
			clreol();
			goto d;
		}
		f.clear();
		f.seekg(0,ios::beg);
		while(f.read((char*)&c,t))
		{       p1=c.retcor();
			if(n==c.retno())
			{
				strcpy(str[i],p1);
				break;
			}
		}
	}
	f.close();
	return 0;
}

int info::fac_modifycor()
{       char *p1=NULL; int t,z;
	course c;	fstream f;
	clrscr();
	gotoxy(1,2);
	c.listcor();
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	t=sizeof(c);
	f.seekg(-t,ios::end);
	f.read((char*)&c,t);
	z=c.retno();
	f.seekg(0,ios::end);
	if(f.tellg()==0)
	{	cout<<"\n No course available. Try again later.";
		getch();
		f.close();
		return 1;
	}
	f.clear();
	i:
	gotoxy(1,9);
	cout<<"Enter course number: ";
	cin>>n;
	if(n>z)
	{
		cout<<"Course not available. Please enter again.\n";
		delay(1000);
		gotoxy(1,9);
		clreol();
		gotoxy(1,10);
		clreol();
		goto i;
	}
	f.seekg(0,ios::beg);
	while(f.read((char*)&c,t))
	{       p1=c.retcor();
		if(n==c.retno())
		{	 strcpy(str[0],p1);
			 break;
		}
	}
	f.close();
	return 0;
}
void info::modclass()
{
	d:
	gotoxy(1,10);
	{
		cout<<"\nEnter new class :";
		cin>>grade;
	}
	if(grade>12||grade<11)
	{
		cout<<"\nPlease enter correct class.";
		delay(1000);
		gotoxy(1,10);
		clreol();
		gotoxy(1,11);
		clreol();
		goto d;
	}
}
void info::modpass()
{       char h[6];    int i,c=0,t=0;
	d:
	gotoxy(1,10);
	cout<<" Enter new password ( 4 characters )  : ";
	gets(p);
	cout<<"Confirm new password ( 4 characters ) : ";
	gets(h);
	for(i=0;p[i]!='\0';i++)
		c++;
	for(i=0;h[i]!='\0';i++)
		t++;
	if(strcmpi(p,h)!=0||c!=4||t!=4)
	{       cout<<"Enter re-enter password!";
		delay(1000);
		gotoxy(1,10);
		clreol();
		gotoxy(1,11);
		clreol();
		gotoxy(1,13);
		clreol();
		goto d;
	}
}

void info::modcont()
{       int i,c=0;
	g:
	gotoxy(1,9);
	cout<<"\nEnter new contact no :";
	cin>>cont;
	for(i=0;cont[i]!='\0';i++)
	c++;
	if(c!=10)
	{
		cout<<"Please enter correct contact number.";
		delay(1000);
		gotoxy(1,9);
		clreol();
		gotoxy(1,10);
		clreol();
		goto g;
	}
}

void info::modemail()
{       int fl,i;
	m:
	gotoxy(1,10);
	cout<<"Enter new email :";
	cin>>email;
	for(i=0;email[i]!='\0';i++)
	{	if(email[i]=='@')
		{	fl=1;
			break;
		}
	}
	if(fl==0)
	{
		cout<<"\tPlease enter correct email id ! ";
		delay(1000);
		gotoxy(1,11);
		clreol();
		gotoxy(1,10);
		clreol();
		goto m;
	}
}

void info::enter(int l)
{
	int i,z,t,fl=0; course c;
	fstream f;   char *p1=NULL;
	serial=l;
	cout<<"Enter your name : ";
	gets(name);
	gotoxy(1,6);
	s:
	cout<<"Enter your class :";
	cin>>grade;
	if(grade>12||grade<11)
	{
		cout<<"Please enter correct class.";
		delay(1000);
		gotoxy(1,7);
		clreol();
		gotoxy(1,6);
		clreol();
		goto s;
	}
	cout<<"Enter school name : ";
	gets(univ);
	m:
	gotoxy(1,8);
	cout<<"Enter your email id :";
	cin>>email;
	for(i=0;email[i]!='\0';i++)
	{	if(email[i]=='@')
		{	fl=1;
			break;
		}
	}
	if(fl==0)
	{
		cout<<"\tPlease enter correct email id ! ";
		delay(1000);
		gotoxy(1,8);
		clreol();
		gotoxy(1,9);
		clreol();
		goto m;
	}
	a:
	gotoxy(1,9);
	cout<<"\nHow many courses are you interested in learning ? :";
	cin>>learn;
	if(learn>5)
	{
		cout<<"Maximum courses that can be allotted is 5.";
		delay(1000);
		gotoxy(1,10);
		clreol();
		gotoxy(1,11);
		clreol();
		goto a;
	}
	clrscr();
	cout<<"\tCourses available to choose from :\n";
	c.listcor();
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	t=sizeof(c);
	f.seekg(-t,ios::end);
	f.read((char*)&c,t);
	z=c.retno();
	f.seekg(0,ios::end);
	if(f.tellg()==0)
	{	cout<<"\n No course available. Try again later.";
		getch();
		f.close();
		visit();
	}
	f.clear();
	for(i=0;i<learn;i++)
	{       d:
		gotoxy(1,10+i);
		cout<<"Enter course("<<i+1<<") no: ";
		cin>>n;
		if(n>z||n<1)
		{
			cout<<"Course not available. Please enter again.\n";
			delay(1000);
			gotoxy(1,10+i);
			clreol();
			gotoxy(1,11+i);
			clreol();
			goto d;
		}
		f.clear();
		f.seekg(0,ios::beg);
		while(f.read((char*)&c,t))
		{       p1=c.retcor();
			if(n==c.retno())
			{
				strcpy(str[i],p1);
				break;
			}
		}
	}
	int j,r; char k,x;
	cout<<"ID : "<<serial;
	cout<<"\nPassword  : ";
	randomize();
	for(j=0;j<=3;j++)
	{
		r=random(27)%26;
		k='a'+r;
		cout<<k;
		p[j]=k;
		p[4]='\0';
	}
	cout<<"   (Please note the ID and password for future reference) \n\n";
	f.close();
}

void info::display(int l)
{       int i;
	if(l%2==0)
	{
		cout<<"\nID : "<<retid();
		cout<<"\nPassword : "<<p;
		cout<<"\nName : "<<name;
		cout<<"\nClass :"<<grade;
		cout<<"\nSchool name :"<<univ;
		cout<<"\nEmail id :"<<email;
		cout<<"\nCourses taken: ";
		for(i=0;i<learn;i++)
		{       cout<<endl;
			cout<<str[i];
		}
	}
	else
	{
		gotoxy(45,helo++);
		cout<<"ID : "<<retid();
		gotoxy(45,helo++);
		cout<<"Password : "<<p;
		gotoxy(45,helo++);
		cout<<"Name : "<<name;
		gotoxy(45,helo++);
		cout<<"Class :"<<grade;
		gotoxy(45,helo++);
		cout<<"School name :"<<univ;
		gotoxy(45,helo++);
		cout<<"Email id :"<<email;
		gotoxy(45,helo++);
		cout<<"Courses taken: ";
		for(i=0;i<learn;i++)
		{       gotoxy(45,helo++);
			cout<<str[i];
		}
	helo+=1;
	}
       cout<<endl;
}

void info::mycor()
{
	for(int i=0;i<learn;i++)
	{	cout<<str[i];
		cout<<"      ";
		if(i==2)
		cout<<"\n\n\t\t";
	}
}


void info::facenter(int l)
{
	int z,t,fl=0,s=0,i;   course c;
	fstream f; char *p1=NULL;
	serial=l;
	cout<<"Name : ";
	gets(name);
	l:
	gotoxy(1,6);
	cout<<"Age : ";
	cin>>age;
	if(age>60||age<20)
	{
		cout<<"Please enter correct age.";
		delay(1000);
		gotoxy(1,6);
		clreol();
		gotoxy(1,7);
		clreol();
		goto l;
	}
	g:
	gotoxy(1,7);
	cout<<"Work experience :";
	cin>>exp;
	if(exp>age-15)
	{
		cout<<"Enter correct experience!";
		delay(1000);
		gotoxy(1,7);
		clreol();
		gotoxy(1,8);
		clreol();
		goto g;
	}
	zz:
	gotoxy(1,8);
	cout<<"Email id :";
	cin>>email;
	for(i=0;email[i]!='\0';i++)
	{	if(email[i]=='@')
		{	fl=1;
			break;
		}
	}
	if(fl==0)
	{
		cout<<"\tPlease enter correct email id ! ";
		delay(1000);
		gotoxy(1,8);
		clreol();
		gotoxy(1,9);
		clreol();
		goto zz;
	}
	h:
	gotoxy(1,9);
	cout<<"Contact number :";
	gets(cont);
	for(i=0;cont[i]!='\0';i++)
		s++;
	cout<<s;
	if(s!=10)
	{
		cout<<"Please enter correct contact number.";
		delay(1000);
		gotoxy(1,9);
		clreol();
		gotoxy(1,10);
		clreol();
		goto h;
	}
	clrscr();
	cout<<"\tEnter your course no from the below courses :\n";
	c.listcor();
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	t=sizeof(c);
	f.seekg(-t,ios::end);
	f.read((char*)&c,t);
	z=c.retno();
	f.seekg(0,ios::end);
	if(f.tellg()==0)
	{	cout<<"\n No course available. Try again later.";
		getch();
		f.close();
		visit();
	}
	f.clear();
	cout<<endl;
	i:
	gotoxy(1,9);
	cout<<"Enter course number: ";
	cin>>n;
	if(n>z||n<1)
	{
		cout<<"Course not available. Please enter again.\n";
		delay(1000);
		gotoxy(1,9);
		clreol();
		gotoxy(1,10);
		clreol();
		goto i;
	}
	f.seekg(0,ios::beg);
	while(f.read((char*)&c,t))
	{       p1=c.retcor();
		if(n==c.retno())
		{	 strcpy(str[0],p1);
			 break;
		}
	}
	int j,r; char k,x;
	cout<<"ID : "<<serial;
	cout<<"\nPassword  : ";
	randomize();
	for(j=0;j<=3;j++)
	{
		r=random(27)%26;
		k='a'+r;
		cout<<k;
		p[j]=k;
		p[4]='\0';
	}
	cout<<"   (Please note the ID and password for future reference) \n\n";
	f.close();
}

void info::facdisplay (int l)
{
	int i;
	if(l%2==0)
	{
	cout<<"\nID : "<<retid();
	cout<<"\nPassword : "<<p;
	cout<<"\nName : "<<name;
	cout<<"\nAge :"<<age;
	cout<<"\nWork experience : "<<exp;
	cout<<"\nEmail id :"<<email;
	cout<<"\nContact number :"<<cont;
	cout<<"\nSubject: "<<str[0];
	}
	else
	{
		gotoxy(45,hi++);
		cout<<"ID : "<<retid();
		gotoxy(45,hi++);
		cout<<"Password : "<<p;
		gotoxy(45,hi++);
		cout<<"Name : "<<name;
		gotoxy(45,hi++);
		cout<<"Age :"<<age;
		gotoxy(45,hi++);
		cout<<"Work experience :"<<exp;
		gotoxy(45,hi++);
		cout<<"Email id :"<<email;
		gotoxy(45,hi++);
		cout<<"Contact number : "<<cont;
		gotoxy(45,hi++);
		cout<<"Subject : "<<str[0];
		hi+=1;
	}
       cout<<endl;
}

void stu_addrec()
{       clrscr();
	int r;
	fstream f;  info a;
	cout<<"\n\t\t\tREGISTRATION";
	cout<<"\nSign up in Zertech Academy for free.";
	cout<<" Please fill up your following credentials : \n";
	r=autogen();
	a.enter(r);
	f.open("course.dat",ios::binary|ios::app);
	if(f.fail())
	{
		cerr<<"File not opened successfully";
		getch();
		exit(1);
	}
	f.write((char*)&a,sizeof(a));
	f.close();
	cout<<"Congratulations. Your profile has been added.";
}

void fac_addrec()
{       clrscr();
	int r;
	fstream f;  info a;
	cout<<"\n\t\t\tJOB APPLICATION";
	cout<<"\nSign up in Zertech Academy for free.";
	cout<<" Please fill up your following credentials : \n";
	r=autogener();
	a.facenter(r);
	f.open("faculty1.dat",ios::binary|ios::app);
	if(f.fail())
	{
		cerr<<"File not opened successfully";
		getch();
		exit(1);
	}
	f.write((char*)&a,sizeof(a));
	f.close();
	cout<< "Thank you for registering. Our company executives will review your resume\n and get in touch with you shortly. ";
}

void SHOWDATE()
{
	char z[12][20]={"January","February","March","April","May","June","July","August","September","October","November","December"};
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

void gidaf()
{       int ch,flag=0;char opt,ex;student s;   int i,b,j;
	admin a;    faculty f;
	do
	{       flag=0;
		clrscr();
		textcolor(YELLOW);
		     SHOWDATE();
		gotoxy(27,3);
		cprintf("M A I N  ---  M E N U");
		cout<<endl;
		gotoxy(27,4);
		cprintf("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");
		 gotoxy(30,7);
		cprintf("1.   Visitor");
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
		switch(ch)
		{
			case 1: textcolor(LIGHTRED);
				visit();
				flag=1;
				break;
			case 2: textcolor(LIGHTCYAN);
				s.stulog();
				flag=1;
				break;
		      case 3:textcolor(LIGHTMAGENTA);
				f.faclog();
				flag=1;
				break;
			case 4: textcolor(LIGHTGREEN);
				a.adminlog();
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
		if(flag!=1)
		{       cout<<"\n\t\t\t\t";
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
       if(ex=='y'||ex=='Y')
       {
		cout<<"Exiting in 3";delay(1000);
		cout<<"\b2";delay(1000);
		cout<<"\b1";delay(1000);
		exit(0);
	}
}
void main()
{	int i,j;
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
   for(i=0;i<4;i++)
   {  cleardevice();
	for(j=10;j<=midx;j+=10)
	{
	   setcolor(YELLOW);
		line(j,0,0,midy*2+150);
	}
	 for(;j<=midx*2;j+=10)
		line(j,0,midx*2,midy*2+150);
	// select the text style
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
   gidaf();
}

void admin::adminlog()
{
	int i,j,flag=0,r;
	for(j=0;j<3;j++)
	{       clrscr();
		gotoxy(27,8);
		cout<<"A D M I N    L O G I N";
		gotoxy(30,10);
		cout<<"Enter ID : ";
		gets(admid);
		if(strcmp(admid,"1957")!=0)
		{       if(j==2)
			break;
			gotoxy(30,11);
			cout<<"Invalid ID. Please try again.";
			delay(1000);
			continue;
		}
		gotoxy(30,12);
		cout<<"Enter password : ";
		for(i=0;i<4;i++)
		{
			admpass[i]=getche();
			delay(150);
			gotoxy(48+i,12);
			cout<<"\b*";
		}
		admpass[i]='\0';
		getch();
		r=strcmp(admpass,"doof");
		if(r==0)
		{       gotoxy(27,14);
			cout<<"Please wait while we log you in......";
			delay(3000);
			flag=1;
			break;
		}
		if(r!=0)
		{       if(j==2)
			break;
			gotoxy(30,14);
			cout<<"Invalid password.Try again in ";
			cout<<"3";delay(1000);
			cout<<"\b2";delay(1000);
			cout<<"\b1";delay(1000);
		}
		clrscr();
	 }
	if(flag==0)
	{
		cout<<"\nToo many attempts. Redirecting you to main menu";
		delay(2000);
		gidaf();
	}
	else
	admdata();
}

void admin::admdata()
{       int cho,flag,t;
	char opt,ex;
	do
	{    clrscr();
	t=0;
	flag=0;
	cout<<"\n\t\t\t\tA D M I N    M E N U";
	cout<<"\n\n  1.Courses ";
	cout<<"\n  2.Time table";
	cout<<"\n  3.Search details";
	cout<<"\n  4.View student/faculty details.";
	cout<<"\n  5.Delete entry";
	cout<<"\n  6.Job applications";
	cout<<"\n  7.Return to main menu";
	cout<<"\n  8.Exit";
	cout<<"\n\n  Enter your choice :";
	cin>>cho;
	switch(cho)
	{
		case 1: courses();
			flag=1;
			break;
		case 2:timetab();
			flag=1;
			break;
		case 3:search();
			flag=1;
			break;
		case 4:view();
			flag=1;
			break;
		case 5:delent();
			flag=1;
			break;
		case 6:job();
			break;
		case 7:clrscr();
			gotoxy(28,10);
			cout<<"LOGGING OUT. Please wait...";
			delay(1200);
			clrscr();
			flag=1;
			t=1;
			break;
		case 8:cout<<"\nExiting......";
			getch();
			exit(0);
		default:cout<<"\nNo such choice exists.";
	}
	if(flag==0)
	{
		cout<<"\nDo you want to continue ? :";
		cin>>opt;
	}
	else
	opt='y';
	if(t==1)
		opt='n';
	}while(opt=='y'||opt=='Y');
	if(t==1)
	{	clrscr();
		gidaf();
	}
	cout<<"\nAre you sure you want to EXIT the program ? (y,Y) : ";
       cin>>ex;
       if(ex=='y'||ex=='Y')
       {
		cout<<"Exiting program in 3";delay(1000);
		cout<<"\b2";delay(1000);
		cout<<"\b1";delay(1000);
		exit(0);
	}
	else
	admdata();
}

void admin::courses()
{
	course c;
	int cho;char opt;
	do
	{
	clrscr();
	cout<<"\n  1.View courses.";
	cout<<"\n  2.Add a course.";
	cout<<"\n  3.Delete a course.";
	cout<<"\n  4.Return to Admin menu ";
	cout<<"\nEnter your choice :";
	cin>>cho;
	switch(cho)
	{
		case 1: clrscr();
			cout<<"\n\t\tAvailable courses : ";
			c.listcor();
			break;
		case 2:c.addcor();
			break;
		case 3:c.deletecor();
			break;
		case 4:return;
		default:cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? :";
	cin>>opt;
	}while(opt=='y'||opt=='Y');
	admdata();
}

void admin::search()
{       int cho;char opt;         faculty f;
	student s;
	do
	{
	clrscr();
	cout<<"\n  1.Search Student details.";
	cout<<"\n  2.Search Faculty details.";
	cout<<"\n  3.Return to Admin menu ";
	cout<<"\n  Enter your choice :";
	cin>>cho;
	switch(cho)
	{
		case 1:s.stu_searchrec();
			break;
		case 2:f.fac_searchrec();
			break;
		case 3:return;
		default:cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? :";
	cin>>opt;
	}while(opt=='y'||opt=='Y');
	admdata();
}

void admin::timetab()
{
	 clrscr();
	int cho; char opt;
	cout<<"\n  1.Display Student Time Table";
	cout<<"\n  2.Modify Student Time Table";
	cout<<"\n  3.Display Faculty Time Table";
	cout<<"\n  4.Modify Faculty Time Table";
	cout<<"\n  5.Return to Admin menu";
	cout<<"\n  Enter your choice :";
	cin>>cho;
	switch(cho)
	{
		case 1:list_stutimereo();
			break;
		case 2:modify_stutime();
			break;
		case 3:list_factimereo();
			break;
		case 4:modify_factime();
			break;
		case 5:return;
		default:cout<<"\nChoice does not exist.";
	}
	if(cho==1||cho==3||cho>5)
	{	cout<<"\nDo you want to continue ? :";
		cin>>opt;
	}
	else
	opt='y';
	if(opt=='y'||opt=='Y')
	timetab();
	admdata();
}

void admin::list_stutimereo()
{       clrscr();
	fstream f;
	f.open("time.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	timetable t;
	while(f.read((char*)&t,sizeof(t)))
		t.stu_display();
	int n=f.tellg();
	if(n==0)
		cout<<"\nTime table not created.";
	f.close();
}

void admin::stu_addtime()
{       clrscr();
	fstream f; timetable t;
	t.stu_input();
	f.open("time.dat",ios::binary|ios::app);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	f.write((char*)&t,sizeof(t));
	f.close();
}

void admin::modify_stutime()
{       int cho,flag;
	char opt;

	do
	{       clrscr();
		flag=0;
		cout<<"\n  1.Add to time table ";
		cout<<"\n  2.Delete from time table ";
		cout<<"\n  3.Return to Time table menu";
		cout<<"\nEnter choice :";
		cin>>cho;
		switch(cho)
		{
			case 1:stu_addtime();
				flag=1;
				break;
			case 2:stu_deltime();
				break;
			case 3:return;
			default:cout<<"\nNo such choice exists.";
		}
		if(flag==0)
		{
		cout<<"\nDo you want to continue ? :";
		cin>>opt;
		}
		else
		opt='y';
	}while(opt=='y'||opt=='Y');
	admdata();
}

void admin::stu_deltime()
{
	fstream f1,f2; timetable t;
	 int flag=0; char i[10];
	char *p2=NULL;
	f1.open("time.dat",ios::in|ios::out|ios::binary);
	if(f1.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("tempo.dat",ios::out|ios::binary);
	if(f2.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	cout<<"\nEnter day to be deleted :";
	gets(i);
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&t,sizeof(t)))
	{        p2=t.retday();
		if(strcmpi(i,p2)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\Day does not exist.";
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&t,sizeof(t)))
	{       p2=t.retday();
		if(strcmpi(i,p2)!=0)
		f2.write((char*)&t,sizeof(t));
	}
	cout<<"\nDay has been deleted.";
	f1.close();
	f2.close();
	remove("time.dat");
	rename("tempo.dat","time.dat");
}
void admin::list_factimereo()
{       clrscr();
	fstream f;
	f.open("factime.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	timetable t;
	while(f.read((char*)&t,sizeof(t)))
			t.fac_display();
	if(f.tellg()==0)
		cout<<"\nTime table not created.";
	f.close();
}

void admin::modify_factime()
{       int cho,flag;
	char opt;

	do
	{       clrscr();
		flag=0;
		cout<<"\n  1.Add to time table ";
		cout<<"\n  2.Delete from time table ";
		cout<<"\n  3.Return to Time table menu";
		cout<<"\nEnter choice :";
		cin>>cho;
		switch(cho)
		{
			case 1:fac_addtime();
				flag=1;
				break;
			case 2:fac_deltime();
				break;
			case 3:return;
			default:cout<<"\nNo such choice exists.";
		}
		if(flag==0)
		{
		cout<<"\nDo you want to continue ? :";
		cin>>opt;
		}
		else
		opt='y';
	}while(opt=='y'||opt=='Y');
	admdata();
}

void admin::fac_addtime()
{       clrscr();
	fstream f; timetable t;
	f.open("factime.dat",ios::binary|ios::app);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	t.fac_input();
	f.write((char*)&t,sizeof(t));
	f.close();
}

void admin::fac_deltime()
{
	fstream f1,f2; timetable t;
	 int flag=0; char i[10]; char *p2=NULL;
	f1.open("factime.dat",ios::in|ios::out|ios::binary);
	if(f1.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("tempo.dat",ios::out|ios::binary);
	if(f2.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	cout<<"\nEnter day to be deleted :";
	gets(i);
	while(f1.read((char*)&t,sizeof(t)))
	{       p2=t.retday();
		if(strcmpi(i,p2)==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\Day does not exist.";
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&t,sizeof(t)))
	{       p2=t.retday();
		if(strcmpi(i,p2)!=0)
		f2.write((char*)&t,sizeof(t));
	}
	cout<<"\nDay has been deleted.";
	f1.close();
	f2.close();
	remove("factime.dat");
	rename("tempo.dat","factime.dat");
}

void admin::view()
{
	int cho;char opt;
	student s;
	faculty f;
	do
	{
	clrscr();
	cout<<"\n  1.View Student details.";
	cout<<"\n  2.View Faculty details.";
	cout<<"\n  3.Return to Admin menu ";
	cout<<"\nEnter your choice :";
	cin>>cho;
	switch(cho)
	{
		case 1: clrscr();
			s.stu_listrec();
			break;
		case 2:f.fac_listrec();
			break;
		case 3:return;
		default:cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? :";
	cin>>opt;
	}while(opt=='y'||opt=='Y');
	admdata();
}

void admin::delent()
{       int cho;char opt;
	student s;
	faculty f;
	do
	{
	clrscr();
	cout<<"\n  1.Delete Student entry.";
	cout<<"\n  2.Delete Faculty entry.";
	cout<<"\n  3.Return to Admin menu ";
	cout<<"\nEnter your choice :";
	cin>>cho;
	switch(cho)
	{
		case 1:stu_delrec();
			break;
		case 2:fac_delrec1();
			break;
		case 3:return;
		default:cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? :";
	cin>>opt;
	}while(opt=='y'||opt=='Y');
	admdata();
}

void admin::stu_delrec()
{
	fstream f1,f2; info a;
	int flag=0;
	f1.open("course.dat",ios::binary|ios::in);
	if(f1.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("temp.dat",ios::binary|ios::out);
	if(f2.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	int r;
	cout<<"\nEnter ID to be deleted :";
	cin>>r;
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(r==a.retid())
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nNo such profile exists.";
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(a.retid()!=r)
		f2.write((char*)&a,sizeof(a));
	}
	cout<<"\nProfile deleted.";
	f1.close();
	f2.close();
	remove("course.dat");
	rename("temp.dat","course.dat");
}

void admin::fac_delrec1()
{
	fstream f1,f2; info a;
	int flag=0,r;
	f1.open("faculty.dat",ios::binary|ios::in);
	if(f1.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("temp.dat",ios::binary|ios::out);
	if(f2.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	cout<<"\nEnter ID to be deleted : ";
	cin>>r;
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(r==a.retid())
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		cout<<"\nNo such profile exists.";
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(a.retid()!=r)
		f2.write((char*)&a,sizeof(a));
	}
	cout<<"\nProfile deleted.";
	f1.close();
	f2.close();
	remove("faculty.dat");
	rename("temp.dat","faculty.dat");
}

void admin::job()
{
	faculty f;
	clrscr();
	f.fac_listapp();
}

void student::stulog()
{       clrscr();
	int i,j,flag=0,r=0,z;
	fstream f;      char *p1=NULL;
	info a;
	f.open("course.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cout<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	for(j=0;j<3;j++)
	{        z=0;
		clrscr();
		gotoxy(28,7);
		cout<<"S T U D E N T     L O G I N";
		gotoxy(30,10);
		cout<<"Enter your student ID :";
		cin>>id;
		f.clear();
		f.seekg(0,ios::beg);
		while(f.read((char*)&a,sizeof(a)))
		{
			if(a.retid()==id)
			{	z=1;
				gotoxy(30,12);
				cout<<"Enter password : ";
				for(i=0;i<4;i++)
				{
					pass[i]=getch();
					cout<<"*";
				}
				pass[4]='\0';
				getch();
				p1=a.retpass();
				r=strcmpi(pass,p1);
				if(r==0)
				{
					gotoxy(28,14);
					cout<<"Please wait while we log you in......";
					delay(3000);
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
		break;
		if(r!=0||z==0)
		{       if(j==2)
			break;
			gotoxy(25,14);
			cout<<"Invalid username or password.Try again in ";
			cout<<"3";delay(1000);
			cout<<"\b2";delay(1000);
			cout<<"\b1";delay(1000);
		}
	}
	f.close();
	if(flag==0)
	{
		gotoxy(20,16);
		cout<<"\nToo many attempts.Redirecting you to main menu.";
		delay(2000);
		gidaf();
	}
	else
	studata(id);
}

char* info::retpass()
{
	return p;
}

void student::studata(int d)
{       int ch,flag=0; char opt,ex;
	info a;
	do
	{
	flag=0;
	clrscr();
	cout<<"\n\t\t\t\tSTUDENT MENU";
	cout<<"\n\n  1.My Courses";
	cout<<"\n  2.View profile";
	cout<<"\n  3.Edit profile";
	cout<<"\n  4.Time-table";
	cout<<"\n  5.Return to main menu";
	cout<<"\n  6.Exit";
	cout<<"\n\n  Enter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:stu_dispcor(d);
			flag=1;
			break;
		case 2:stu_display(d);
			flag=1;
			break;
		case 3:stu_modifyrec(d);
			break;
		case 4:list_stutime(d);
			break;
		case 5: clrscr();
			gotoxy(28,10);
			cout<<"LOGGING OUT. Please wait...";
			delay(1200);
			clrscr();
			return;
		case 6:cout<<"\nExiting.........";
			getch();
			exit(0);
		default:cout<<"\nNo such choice exists.";
	}
	if(flag==1)
	{	cout<<"\nDo you want to continue ? : ";
		cin>>opt;
	}
	else
	opt='y';
	}while(opt=='y'||opt=='Y');
	       cout<<"\nAre you sure you want to EXIT the program ? (y,Y) :";
       cin>>ex;
       if(ex=='y'||ex=='Y')
       {
		cout<<"Exiting in 3";delay(1000);
		cout<<"\b2";delay(1000);
		cout<<"\b1";delay(1000);
		exit(0);
	}
	else
	gidaf();
}

void student::stu_dispcor(int d)
{
	fstream f;
	info a; int i;
	f.open("course.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	cout<<"\nCourses taken: ";
	f.seekg(0,ios::beg);
	while(f.read((char*)&a,sizeof(a)))
	{
		if(d==a.retid())
			a.mycor();
	}
	f.close();
}

void student::stu_display(int d)
{
	fstream f;        info a;
	f.open("course.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	clrscr();
	while(f.read((char*)&a,sizeof(a)))
	{
		if(d==a.retid())
			a.display(0);
	}
	f.close();
}

void student::stu_modifyrec(int d)
{
	fstream f;
	info a;
	int ch; char opt;
	do
	{
	clrscr();
	cout<<"\n  1.Modify password";
	cout<<"\n  2.Modify name";
	cout<<"\n  3.Modify school name";
	cout<<"\n  4.Modify class";
	cout<<"\n  5.Modify email id";
	cout<<"\n  6.Modify courses";
	cout<<"\n  7.Return to student menu";
	cout<<"\n  Enter choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:stu_modpass(d);
			break;
		case 2:stu_modname(d);
			break;
		case 3:stu_modinst(d);
			break;
		case 4:stu_modclass(d);
			break;
		case 5:stu_modemail(d);
			break;
		case 6:stu_modcor(d);
			break;
		case 7:return;
		default:cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? : ";
	cin>>opt;
	}while(opt=='y'||opt=='Y');
	if(opt!='y')
	studata(d);
}

void student::stu_modpass(int d)
{       int z;
	fstream f;   info a;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modpass();
			f.write((char*)&a,z);
			cout<<"\nPassword has been changed.";
			break;
		}
	}
	f.close();
}

void student::stu_modname(int d)
{
	int z;	info a;
	fstream f;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modname();
			f.write((char*)&a,z);
			cout<<"\nName has been updated.";
			break;
		}
	}
	f.close();
}

void student::stu_modinst(int d)
{
	int z;	info a;
	fstream f;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modinst();
			f.write((char*)&a,z);
			cout<<"\nInstitute has been updated.";
			break;
		}
	}
	f.close();
}

void student::stu_modclass(int d)
{
	int z;	info a;
	fstream f;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modclass();
			f.write((char*)&a,z);
			cout<<"\nClass has been updated.";
			break;
		}
	}
	f.close();
}

void student::stu_modemail(int d)
{
	int z;	info a;
	fstream f;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modemail();
			f.write((char*)&a,z);
			cout<<"\nEmail has been updated.";
			break;
		}
	}
	f.close();
}

void student::stu_modcor(int d)
{
	int z; info a;
	fstream f;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.stu_modifycor();
			f.write((char*)&a,z);
			cout<<"\nCourses has been updated.";
			break;
		}
	}
	f.close();
}

void student::stu_listrec ()
{
	fstream f;    info a;  int i=0;
	f.open("course.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	while(f.read((char*)&a,sizeof(a)))
	{
		a.display(i);
		i++;
	}
	if(f.tellg()==0)
	{
		cout<<"\nNo ID created.";
		getch();
		f.close();
		return;
	}
	helo=2;
	f.close();
}

void student::stu_searchrec()
{       int r,flag=0;info a;
	fstream f;
	f.open("course.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nFile not opned successfully.";
		getch();
		exit(1);
	}
	cout<<"Enter ID to be searched : ";
	cin>>r;
	while(f.read((char*)&a,sizeof(a)))
	{
		if(r==a.retid())
		{
			flag=1;
			a.display(0);
			break;
		}
	}
	if(flag==0)
	cout<<"Account not in database.";
	f.close();
}

void student::list_stutime(int d)
{       clrscr();
	fstream f,f1;      int r,flag=0,j;
	info a;
	f.open("time.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	f1.open("course.dat",ios::binary|ios::in);
	if(f1.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(d==a.retid())
		{	flag=1;
			j=a.retcl();
			break;
		}
	}
	flag=0;
	timetable t;
	yay=0;
	while(f.read((char*)&t,sizeof(t)))
	{
		r=t.fun(j);
		if(r==1)
		{       flag=1;
			t.stu_displayee1();
		}
	}
	if(flag==0)
	cout<<"\nYour time table yet to be created.";
	getch();
	f.close();
	f1.close();
}

int timetable::fun(int j)
{
	if(j==grade)
		return 1;
	else
		return 0;
}

void faculty::faclog()
{       clrscr();
	int i,j,flag=0,r=0,z,y;
	fstream f;  char *p1=NULL;
	info a;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cout<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	for(j=0;j<3;j++)
	{        z=0;
		clrscr();
		gotoxy(28,7);
		cout<<"F A C U L T Y     L O G I N";
		gotoxy(30,10);
		cout<<"Enter your faculty ID :";
		cin>>id;
		f.clear();
		f.seekg(0,ios::beg);
		while(f.read((char*)&a,sizeof(a)))
		{
			if(a.retid()==id)
			{	z=1;
				gotoxy(30,12);
				cout<<"Enter password : ";
				for(i=0;i<4;i++)
				{
					pass[i]=getch();
					cout<<"*";
				}
				pass[4]='\0';
				getch();
				p1=a.retpass();
				r=strcmpi(pass,p1);
				if(r==0)
				{
					gotoxy(28,14);
					cout<<"Please wait while we log you in......";
					delay(3000);
					flag=1;
					break;
				}
			}
		}
		if(flag==1)
		break;
		if(r!=0||z==0)
		{       if(j==2)
			break;
			gotoxy(30,15);
			cout<<"Incorrect username or password.Try again in ";
			cout<<"3";delay(1000);
			cout<<"\b2";delay(1000);
			cout<<"\b1";delay(1000);
		}
	}
	f.close();
	if(flag==0)
	{
		gotoxy(30,16);
		cout<<"\nToo many attempts. Redirecting you to main menu. Please wait...";
		delay(3000);
		gidaf();
	}
	else
	facdata(id);
}

void faculty::facdata(int d)
{       int ch;char opt,ex;
	do
	{
	clrscr();
	cout<<"\n\t\t\t\tF A C U L T Y   M E N U";
	cout<<"\n\n  1.View profile";
	cout<<"\n  2.Edit profile";
	cout<<"\n  3.Time-table";
	cout<<"\n  4.Return to main menu";
	cout<<"\n  5.Exit";
	cout<<"\n\n  Enter your choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:fac_display(d);
			break;
		case 2:fac_modifyrec(d);
			break;
		case 3:list_factime(d);
			break;
		case 4: clrscr();
			gotoxy(28,10);
			cout<<"LOGGING OUT. Please wait...";
			delay(1200);
			clrscr();
			return;
		case 5:cout<<"\nExiting.........";
			getch();
			exit(0);
		default:cout<<"\nNo such choice exists.";
	}
	if(ch!=2)
	{	cout<<"\nDo you want to continue ? : ";
		cin>>opt;
	}
	else
	opt='y';
	}while(opt=='y'||opt=='Y');
       cout<<"\nAre you sure you want to EXIT the program ? (y,Y) :";
       cin>>ex;
       if(ex=='y'||ex=='Y')
       {
		cout<<"Exiting in 3";delay(1000);
		cout<<"\b2";delay(1000);
		cout<<"\b1";delay(1000);
		exit(0);
	}
	else
	gidaf();
}

void faculty::fac_display(int d)
{
	fstream f;        info a;
	int i,n;
	f.open("faculty.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	clrscr();
	while(f.read((char*)&a,sizeof(a)))
	{
		if(d==a.retid())
			a.facdisplay(0);
	}
	n=f.tellg();
	if(n==0)
	{
		cout<<"\nNo account created.";
		getch();
	}
	f.close();
}

void faculty::fac_modifyrec(int d)
{
	fstream f;
	info a;
	int ch; char opt;
	do
	{
	clrscr();
	cout<<"\n  1.Modify password";
	cout<<"\n  2.Modify name";
	cout<<"\n  3.Modify email id";
	cout<<"\n  4.Modify contact no";
	cout<<"\n  5.Modify subject";
	cout<<"\n  6.Return to faculty menu";
	cout<<"\nEnter choice : ";
	cin>>ch;
	switch(ch)
	{
		case 1:fac_modpass(d);
			break;
		case 2:fac_modname(d);
			break;
		case 3:fac_modemail(d);
			break;
		case 4:fac_modcont(d);
			break;
		case 5:fac_modcor(d);
			break;
		case 6:return;
		default:cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? : ";
	cin>>opt;
	}while(opt=='y'||opt=='Y');
	if(opt!='y')
	facdata(d);
}

void faculty::fac_modpass(int d)
{       int z;
	fstream f;   info a;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modpass();
			f.write((char*)&a,z);
			cout<<"\nPassword has been changed.";
			break;
		}
	}
	f.close();
}

void faculty::fac_modname(int d)
{
	int z;	info a;
	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modname();
			f.write((char*)&a,z);
			cout<<"\nName has been updated.";
			break;
		}
	}
	f.close();
}

void faculty::fac_modemail(int d)
{
	int z;	info a;
	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modemail();
			f.write((char*)&a,z);
			cout<<"\nEmail has been updated.";
			break;
		}
	}
	f.close();
}

void faculty::fac_modcont(int d)
{
	int z;	info a;
	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.modcont();
			f.write((char*)&a,z);
			cout<<"\nContact no has been updated.";
			break;
		}
	}
	f.close();
}

void faculty::fac_modcor(int d)
{
	int z; info a;
	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	z=sizeof(a);
	while(f.read((char*)&a,z))
	{
		if(a.retid()==d)
		{
			f.seekp(-z,ios::cur);
			a.fac_modifycor();
			f.write((char*)&a,z);
			cout<<"\nCourses has been updated.";
			break;
		}
	}
	f.close();
}

void faculty::fac_listapp()
{
	fstream f,f1;    info a;
	char re; int z,i;
	f.open("faculty1.dat",ios::in|ios::binary|ios::out);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	f1.open("faculty.dat",ios::app|ios::binary);
	if(f.fail())
	{	cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	 f.seekg(0,ios::beg);
	 f1.seekg(0,ios::end);
	while(f.read((char*)&a,sizeof(a)))
	{       clrscr();
		a.facdisplay(0);
		cout<<"\nDo you want to recruit : ";
		cin>>re;
		if(re=='y'||re=='Y')
			f1.write((char*)&a,sizeof(a));
	}
	f.clear();
	if(f.tellg()==0)
	{	cout<<"\n\nNo applications received.";
		getch();
	}
	f1.close();
	f.close();
	fac_delrecs();
}

void faculty::fac_listrec()
{
	fstream f;    info a;
	char re;   int i=0;
	f.open("faculty.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	clrscr();
	f.seekg(0,ios::beg);
	while(f.read((char*)&a,sizeof(a)))
	{
		a.facdisplay(i);
		cout<<endl;
		i++;
	}
	if(f.tellg()==0)
		cout<<"\nNo account created.";
	hi=2;
	f.close();
}

void faculty::fac_searchrec()
{       int r;info a;   int flag=0;
	fstream f;
	f.open("faculty.dat",ios::in|ios::binary);
	if(f.fail())
	{
		cerr<<"\nFile not opned successfully.";
		getch();
		exit(1);
	}
	cout<<"Enter ID to be searched : ";
	cin>>r;
	while(f.read((char*)&a,sizeof(a)))
	{
		if(r==a.retid())
		{
			flag=1;
			a.facdisplay(0);
			break;
		}
	}
	if(flag==0)
	cout<<"Account not in database.";
	f.close();
}

void faculty::fac_delrecs()
{
	fstream f1,f2; info a;
	f1.open("faculty1.dat",ios::binary|ios::in);
	if(f1.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("temp.dat",ios::binary|ios::out);
	if(f2.fail())
	{
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f1.close();
	f2.close();
	remove("faculty1.dat");
	rename("temp.dat","faculty1.dat");
}

void faculty::list_factime(int d)
{       clrscr();
	fstream f,f1; int j,flag=0,r;   info a;
	f.open("factime.dat",ios::binary|ios::in);
	if(f.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	f1.open("faculty.dat",ios::binary|ios::in);
	if(f1.fail())
	{
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	timetable t;
	while(f1.read((char*)&a,sizeof(a)))
	{
		if(d==a.retid())
		{	flag=1;
			j=a.retn();
		}
	}
	flag=0;
	while(f.read((char*)&t,sizeof(t)))
	{
		r=t.yoyo(j);
		if(r==1)
		flag=1;
	}
	if(flag==0)
		cout<<"\nTime table not created.";
	f.close();
	f1.close();
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
void visit()
{       int opt,flag;char ex;
	course c;
	do
	{       flag=0;
		clrscr();
		cout<<"\n\t\t\tV I S I T O R   M E N U";
		cout<<"\n\n  1.Popular courses ";
		cout<<"\n  2.Student registration";
		cout<<"\n  3.Submit Job application";
		cout<<"\n  4.About Us";
		cout<<"\n  5.Return to Main Menu";
		cout<<"\n  6.Exit";
		cout<<"\n\n  Please enter your choice :";
		cin>>opt;
		switch(opt)
		{
			case 1: clrscr();
				cout<<"\n\t\tAvailable courses ";
				c.listcor();
				break;
			case 2:stu_addrec();
				break;
			case 3:fac_addrec();
				break;
			case 4: about();
				flag=1;
				break;
			case 5:return;
			case 6:cout<<"Exiting....";
				delay(500);
				exit(0);
				break;
			default:cout<<"\nNo such choice exists.";
		} if(flag!=1)
		{
			cout<<"\nDo you want to continue ? :";
			cin>>ex;
		}
		else
		ex='y';
	}while(ex=='y'||ex=='Y');
	return;
}
void about()
{       int opt;char ex;
	do
	{
	clrscr();
	cout<<"\n\t\t\t\tAbout Us";
	cout<<"\n  1.Mission and story";
	cout<<"\n  2.Leadership";
	cout<<"\n  3.Our supporters";
	cout<<"\n  4.Customer care";
	cout<<"\n  5.Return to menu";
	cout<<"\n  6.Exit";
	cout<<"\n  Enter your choice :";
	cin>>opt;
	clrscr();
	switch(opt)
	{
		case 1:cout<<"\n\t\t\t\tMission and Story";
		      cout<<"\nOur mission is to provide a free, world-class education to anyone,anywhere.";
		      cout<<"        Advance teaching and learning through research.";
		      cout<<"\nZertech was created in 2019 by the toil and vision of Mr.Alvin Joseph, a high"<<"   school student from Fr.Agnel School,Delhi.";
		      cout<<" We started to leave an indelible mark on the students who have undergone Zertech training.";
		      cout<<"\nToday, aiming for the unachievable and continuosly raising the bar has become a part of Zertech DNA.For us, our journey is itself the destination.";
		      cout<<"\nZertech is a 501(c)(7) nonprofit organisation.\n";
			   break;
		case 2:cout<<"\n\t\t\t\tLeadership";
			cout<<"\n  1. ALVIN JOSEPH";
			cout<<"\n  Founder and CEO";
			cout<<"\n\n  2. HARSHIT SHARMA";
			cout<<"\n  President and co-CEO";
			cout<<"\n\n  3.CHAMANJEET SINGH";
			cout<<"\n  Secretary and HOD\n";
			break;
		case 3:cout<<"\n\t\t\t\tOur supporters";
			cout<<"\nOur founder partners :";
			cout<<"\n\n Bank of India\n Google\n Bill and Melinda Gates Foundation \n The O'Sullivan Foundation";
			cout<<"\n The Walt Disney Company \n AT&T\n Hyatt Hotel Corporation";
			cout<<endl;
			break;
		case 4:cout<<"\n\t\t\t\tContact Us";
			cout<<"\n\nContact numbers : 8998778910, 9835672222, 011-26911672";
			cout<<"\nOr please contact us through our email id : csproject@mailinator.com";
			break;
		case 5:return;
		case 6:cout<<"\nExiting .......";
			getch();
			exit(0);
		default:cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? :";
	cin>>ex;
	}while(ex=='y'||ex=='Y');
	return;
}
