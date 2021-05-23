class info {                     //Managing student/faculty details
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
		char *retPass() {
			return p;
		}
		void fac_dispname() {
			cout<<name;
		}
		void setEmail();
		void setPassword();
		void setName() {
			cout<<"\nEnter new name :";
			gets(name);
		}
		void setContact();
		void setClass();
		void setUniv() {
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

int info::one(int l) {
	if(n==l)
		return 1;
	else
		return 0;
}

int info::stu_modifycor() {
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
	c.listCourses();
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
	z=c.retCourseNo();
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
		{       p1=c.retCourse();
			if(n==c.retCourseNo())
			{
				strcpy(str[i],p1);
				break;
			}
		}
	}
	f.close();
	return 0;
}

int info::fac_modifycor() {

	char *p1=NULL; int t,z;
	course c;	fstream f;
	clrscr();
	gotoxy(1,2);
	c.listCourses();
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
	z=c.retCourseNo();
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
	{       p1=c.retCourse();
		if(n==c.retCourseNo())
		{	 strcpy(str[0],p1);
			 break;
		}
	}
	f.close();
	return 0;
}
void info::setClass()
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
void info::setPassword()
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

void info::setContact()
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

void info::setEmail()
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
	c.listCourses();
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
	z=c.retCourseNo();
	f.seekg(0,ios::end);
	if(f.tellg()==0)
	{	cout<<"\n No course available. Try again later.";
		getch();
		f.close();
		visitorMenu.visitorMenu();
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
		{       p1=c.retCourse();
			if(n==c.retCourseNo())
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
	c.listCourses();
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
	z=c.retCourseNo();
	f.seekg(0,ios::end);
	if(f.tellg()==0)
	{	cout<<"\n No course available. Try again later.";
		getch();
		f.close();
		visitorMenu.visitorMenu();
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
	{       p1=c.retCourse();
		if(n==c.retCourseNo())
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
