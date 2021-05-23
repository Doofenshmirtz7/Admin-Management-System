class Faculty : public Person {
	int age;
	int exp;
	int n;
	char cont[15];
	static int createFacultyID();
	static void facultyLogin();
	static void facultyMenu(int);
	void setFacultyPassword(int);
	void setFacultyName(int);
	void setFacultyContact(int);
	void setFacultyEmail(int);
	void setFacultyCourse(int);
	void fac_modifycor(int);

	public :
		void addFaculty();
		void facenter(int);
		void facdisplay(int);
		void getFaculty(int);
		void facultyList();
		void setFaculty(int);
		void facultySearch();
		void getFacultyTimeTable(int);
};

void faculty::facultyLogin() {

	clrscr();
	int i,j,flag=0,r=0,z,y;
	fstream f;
	char *p1=NULL;
	faculty fac;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cout<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	for(j=0;j<3;j++) {
	    z=0;
		clrscr();
		gotoxy(28,7);
		cout<<"F A C U L T Y     L O G I N";
		gotoxy(30,10);
		cout<<"Enter your faculty ID :";
		cin>>id;
		f.clear();
		f.seekg(0,ios::beg);
		while(f.read((char*)&fac,sizeof(fac))) {
			if(fac.retid()==id) {
				z=1;
				gotoxy(30,12);
				cout<<"Enter password : ";
				for(i=0;i<4;i++) {
					pass[i]=getch();
					cout<<"*";
				}
				pass[4]='\0';
				getch();
				p1=fac.retPass();
				r=strcmpi(pass,p1);
				if(r==0) {
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
		if(r!=0||z==0) {
		    if(j==2)
				break;
			gotoxy(30,15);
			cout<<"Incorrect username or password.Try again in ";
			cout<<"3";delay(1000);
			cout<<"\b2";delay(1000);
			cout<<"\b1";delay(1000);
		}
	}
	f.close();
	if(flag==0) {
		gotoxy(30,16);
		cout<<"\nToo many attempts. Redirecting you to main menu. Please wait...";
		delay(3000);
		MainMenu();
	}
	else
		faculty::facultyMenu(id);
}

void faculty::facultyMenu(int d){
    int ch;char opt,ex;
	do {
		clrscr();
		cout<<"\n\t\t\t\tF A C U L T Y   M E N U";
		cout<<"\n\n  1.View profile";
		cout<<"\n  2.Edit profile";
		cout<<"\n  3.Time-table";
		cout<<"\n  4.Return to main menu";
		cout<<"\n  5.Exit";
		cout<<"\n\n  Enter your choice : ";
		cin>>ch;
		switch(ch) {
			case 1:getFaculty(d);	break;
			case 2:setFaculty(d);	break;
			case 3:getFacultyTimeTable(d);	break;
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
		if(ch!=2) {
			cout<<"\nDo you want to continue ? : ";
			cin>>opt;
		}
		else
			opt='y';
	}while(opt=='y'||opt=='Y');
    cout<<"\nAre you sure you want to EXIT the program ? (y,Y) :";
    cin>>ex;
    if(ex=='y'||ex=='Y') {
	cout<<"Exiting in 3";delay(1000);
	cout<<"\b2";delay(1000);
	cout<<"\b1";delay(1000);
	exit(0);
	}
	else
	MainMenu();
}

void faculty::getFaculty(int d) {
	fstream f;
	int i,n;
	f.open("faculty.dat",ios::in|ios::binary);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	clrscr();
	while(f.read((char*)this,sizeof(faculty))) {
		if(d==id)
			this.facdisplay(0);
	}
	n=f.tellg();
	if(n==0) {
		cout<<"\nNo account created.";
		getch();
	}
	f.close();
}

void faculty::setFaculty(int d)
{
	fstream f;
	int ch; char opt;
	do {
		clrscr();
		cout<<"\n  1.Modify password";
		cout<<"\n  2.Modify name";
		cout<<"\n  3.Modify email id";
		cout<<"\n  4.Modify contact no";
		cout<<"\n  5.Modify subject";
		cout<<"\n  6.Return to faculty menu";
		cout<<"\nEnter choice : ";
		cin>>ch;
		switch(ch) {
			case 1: setFacultyPassword(d);	break;
			case 2: setFacultyName(d);	break;
			case 3: setFacultyEmail(d);	break;
			case 4: setFacultyContact(d);	break;
			case 5: setFacultyCourse(d);	break;
			case 6: return;
			default: cout<<"\nNo such choice exists.";
		}
		cout<<"\nDo you want to continue ? : ";
		cin>>opt;
		}while(opt=='y'||opt=='Y');
	if(opt!='y')
	faculty::facultyMenu(d);
}

void faculty::setFacultyPassword(int d){
	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(faculty);
	while(f.read((char*)this,z))
	{
		if(this.id==d)
		{
			f.seekp(-z,ios::cur);
			this.setPassword();
			f.write((char*)this,z);
			cout<<"\nPassword has been changed.";
			break;
		}
	}
	f.close();
}

void faculty::setFacultyName(int d) {

	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(faculty);
	while(f.read((char*)this,z)) {
		if(this.id==d) {
			f.seekp(-z,ios::cur);
			cout<<"\nEnter new name :";
			gets(name);
			f.write((char*)this,z);
			cout<<"\nName has been updated.";
			break;
		}
	}
	f.close();
}

void faculty::setFacultyEmail(int d) {
	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(faculty);
	while(f.read((char*)this,z)) {
		if(this.id==d) {
			f.seekp(-z,ios::cur);
			cout<<"Enter new email :";
			cin>>email;
			f.write((char*)this,z);
			cout<<"\nEmail has been updated.";
			break;
		}
	}
	f.close();
}

void faculty::setFacultyContact(int d) {
	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(faculty);
	while(f.read((char*)this,z)) {
		if(this.id==d) {
			f.seekp(-z,ios::cur);
			cout<<"\nEnter new contact no :";
			cin>>cont;
			f.write((char*)this,z);
			cout<<"\nContact no has been updated.";
			break;
		}
	}
	f.close();
}

void faculty::setFacultyCourse(int d) {
	fstream f;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(faculty);
	while(f.read((char*)this,z)) {
		if(this.id==d) {
			f.seekp(-z,ios::cur);
			this.fac_modifycor();
			f.write((char*)this,z);
			cout<<"\nCourses has been updated.";
			break;
		}
	}
	f.close();
}

void faculty::getFacultyTimeTable(int d) {
	clrscr();
	fstream f,f1; int j,flag=0,r;
	f.open("factime.dat",ios::binary|ios::in);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	f1.open("faculty.dat",ios::binary|ios::in);
	if(f1.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	timetable t;
	while(f1.read((char*)this,sizeof(faculty))) {
		if(d==this.id)
		{	flag=1;
			j=n;
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


int faculty::createFacultyID() {
	fstream f,f1;
	int r,n,n1,i;
	f.open("faculty.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile cannot be opened successfully.1";
		getch();
		exit(0);
	}
	f1.open("faculty1.dat",ios::binary|ios::in|ios::out);
	if(f1.fail()) {
		cerr<<"\nFile cannot be opened successfully.2";
		getch();
		exit(0);
	}
	int z=sizeof(faculty);
	f.seekg(0,ios::end);
	n=f.tellg();
	if(n==0) {
		f1.seekg(0,ios::end);
		n1=f1.tellg();
		if(n1==0)
			r=1;
		else {
		    f1.clear();
			f1.seekg(-z,ios::end);
			f1.read((char*)this,z);
			r=this.id;
			++r;
		}
	}
	else {
	    f.clear();
		f.seekg(-z,ios::end);
		f.read((char*)this,z);
		r=this.id+1;
	}
	f.close();
	f1.close();
	return r;
}

void faculty::addFaculty() {
    clrscr();
	fstream f;
	cout<<"\n\t\t\tJOB APPLICATION";
	cout<<"\nSign up in Zertech Academy now for FREE!\n";
	int r=createFacultyID();
	facenter(r);
	f.open("faculty1.dat",ios::binary|ios::app);
	if(f.fail()) {
		cerr<<"File not opened successfully";
		getch();
		exit(1);
	}
	f.write((char*)this,sizeof(faculty));
	f.close();
	cout<< "Thank you for registering. Our company executives will review your resume\n and get in touch with you shortly. ";
}

void faculty::facenter(int l)
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
	}
	cout<<"   (Please note the ID and password for future reference) \n\n";
	f.close();
}

int Faculty::fac_modifycor() {

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

void faculty::facdisplay(int l) {
	int i;
	if(l%2==0) {
		cout<<"\nID : "<<id;
		cout<<"\nPassword : "<<p;
		cout<<"\nName : "<<name;
		cout<<"\nAge :"<<age;
		cout<<"\nWork experience : "<<exp;
		cout<<"\nEmail id :"<<email;
		cout<<"\nContact number :"<<cont;
		cout<<"\nSubject: "<<str[0];
	} else {
		gotoxy(45,hi++);
		cout<<"ID : "<<id;
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
