class Student : public Person {

	int learn;
	int grade;
	char univ[20];
	char str[5][25];
	static int space;
	static int createStudentID();
	void setStudentPassword();
	void setStudentClass();
	void setStudentEmail();
	void setStudentUniv();
	void setStudentCourse();
	void setStudentName();
	void modStudentCourse();

	public:
		static void studentLogin();
		void studentMenu();
		void addStudent();
		void enterCredentials();
		void displayCredentials(int);
		void viewStudent();
		void studentList();
		void studentSearch();
		void editStudent();
		void getStudentTimeTable();
		void getStudentCourse();

};

int Student::space=2;

void student::studentLogin() {

    clrscr();
	int i,j,flag=0;
	fstream f;
	char *p1=NULL;
	student s;
	f.open("course.dat",ios::binary|ios::in);
	if(f.fail()) {
		cout<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}

	for(j=0;j<3;j++) {
		clrscr();
		gotoxy(28,7);
		cout<<"S T U D E N T     L O G I N";
		gotoxy(30,10);
		cout<<"Enter your student ID :";
		cin>>id;
		f.clear();
		f.seekg(0,ios::beg);
		while(f.read((char*)&s,sizeof(s))) {
			if(s.retid()==id)
			{
				gotoxy(30,12);
				cout<<"Enter password : ";
				for(i=0;i<4;i++) {
					pass[i]=getch();
					cout<<"*";
				}
				pass[4]='\0';
				getch();
				p1=s.retPass();
				if(strcmpi(pass,p1) == 0) {
					gotoxy(28,14);
					cout<<"Please wait while we log you in......";
					delay(3000);
					flag=1;
					s.studentMenu();
					break;
				}
			}
		}
		if (flag==1||j==2)
			break;
		else if(j<2) {
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
		MainMenu();
	}
}

void student::studentMenu()	{

	int ch,flag=0; char opt,ex;
	do {
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
		switch(ch) {
			case 1:getStudentCourse();
				flag=1;	break;
			case 2:viewStudent();
				flag=1;	break;
			case 3:editStudent();	break;
			case 4:getStudentTimeTable();	break;
			case 5: clrscr();
				gotoxy(28,10);
				cout<<"LOGGING OUT. Please wait...";
				delay(1200);
				clrscr();	return;
			case 6:cout<<"\nExiting.........";
				getch();
				exit(0);
			default:cout<<"\nNo such choice exists.";
		}
		if(flag==1)	{
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


void student::getStudentCourse() {

	fstream f;
	student s;
	f.open("course.dat",ios::in|ios::binary);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	cout<<"\nCourses taken: ";
	f.seekg(0,ios::beg);
	while(f.read((char*)&s,sizeof(s))) {
		if(s.retid()==id) {
			for(int i=0;i<learn;i++) {
				cout<<str[i];
				cout<<"      ";
				if(i==2)
					cout<<"\n\n\t\t";
			}
		}
	}
	f.close();
}

void student::viewStudent() {

	fstream f;
	student s;
	f.open("course.dat",ios::in|ios::binary);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	clrscr();
	while(f.read((char*)&s,sizeof(s))) {
		if(s.retid()==id)
			displayCredentials();
	}
	f.close();
}

void student::editStudent() {
	fstream f;
	int ch; char opt;
	do {
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
		switch(ch) {
			case 1:setStudentPassword();
				break;
			case 2:setStudentName();
				break;
			case 3:setStudentUniv();
				break;
			case 4:setStudentClass();
				break;
			case 5:setStudentEmail();
				break;
			case 6:setStudentCourse();
				break;
			case 7:return;
			default:cout<<"\nNo such choice exists.";
		}
		cout<<"\nDo you want to continue ? : ";
		cin>>opt;
	}while(opt=='y'||opt=='Y');
	if(opt!='y')
	studentMenu(d);
}

void student::setStudentPassword() {

	fstream f;
	student s;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(s);
	while(f.read((char*)&s,z)) {
		if(id==s.retid()) {
			f.seekp(-z,ios::cur);
			setPassword();
			f.write((char*)&s,z);
			cout<<"\nPassword has been changed.";
			break;
		}
	}
	f.close();
}

void student::setStudentName() {

	fstream f;
	student s;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(s);
	while(f.read((char*)&s,z)) {
		if(id==s.retid()) {
			f.seekp(-z,ios::cur);
			cout<<"\nEnter new name :";
			gets(name);
			f.write((char*)&s,z);
			cout<<"\nName has been updated.";
			break;
		}
	}
	f.close();
}

void student::setStudentUniv() {

	fstream f;
	student s;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(s);
	while(f.read((char*)&s,z)) {
		if(id==s.retid()) {
			f.seekp(-z,ios::cur);
			cout<<"\nEnter new school name :";
			cin>>univ;
			f.write((char*)&s,z);
			cout<<"\nInstitute has been updated.";
			break;
		}
	}
	f.close();
}

void student::setStudentClass() {
	fstream f;
	student s;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(s);
	while(f.read((char*)&s,z)) {
		if(id==s.retid()) {
			f.seekp(-z,ios::cur);
			cout<<"\nEnter new class :";
			cin>>grade;
			f.write((char*)&s,z);
			cout<<"\nClass has been updated.";
			break;
		}
	}
	f.close();
}

void student::setStudentEmail() {

	fstream f;
	student s;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(s);
	while(f.read((char*)&s,z)) {
		if(id==s.retid())
		{
			f.seekp(-z,ios::cur);
			cout<<"Enter new email :";
			cin>>email;
			f.write((char*)&s,z);
			cout<<"\nEmail has been updated.";
			break;
		}
	}
	f.close();
}

void student::setStudentCourse() {

	fstream f;
	student s;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened.";
		getch();
		exit(1);
	}
	int z=sizeof(s);
	while(f.read((char*)&s,z)) {
		if(id==s.retid()) {
			f.seekp(-z,ios::cur);
			modStudentCourse();
			f.write((char*)&s,z);
			cout<<"\nCourses has been updated.";
			break;
		}
	}
	f.close();
}

void student::studentList () {

	fstream f;     int i=0;
	student s;
	f.open("course.dat",ios::in|ios::binary);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	while(f.read((char*)&s,sizeof(s))) {
		displayCredentials(i);
		i++;
	}
	if(f.tellg()==0) {
		cout<<"\nNo ID created.";
		getch();
		f.close();
		return;
	}
	space=2;
	f.close();
}

void student::studentSearch() {

    int r,flag=0;
    student s;
	fstream f;
	f.open("course.dat",ios::in|ios::binary);
	if(f.fail()) {
		cerr<<"\nFile not opned successfully.";
		getch();
		exit(1);
	}
	cout<<"Enter ID to be searched : ";
	cin>>r;
	while(f.read((char*)&s,sizeof(s))) {
		if(r==id) {
			flag=1;
			displayCredentials(0);
			break;
		}
	}
	if(flag==0)
		cout<<"Account not in database.";
	f.close();
}

void student::getStudentTimeTable() {

	clrscr();
	fstream f,f1;
	student s;
	int r,flag=0,j;
	f.open("time.dat",ios::binary|ios::in);
	f1.open("course.dat",ios::binary|ios::in);
	if(f.fail()||f1.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	while(f1.read((char*)&s,sizeof(s))) {
		if(s.retid()==id) {
			flag=1;
			j=grade;
			break;
		}
	}
	flag=0;
	timetable t;
	yay=0;
	while(f.read((char*)&t,sizeof(t))) {
		r=t.fun(j);
		if(r==1) {
			flag=1;
			t.stu_displayee1();
		}
	}
	if(flag==0)
		cout<<"\nYour time table yet to be created.";
	getch();
	f.close();
	f1.close();
}
void student::displayCredentials(int j) {

	int i;
	if(j%2==0) {
		cout<<"\nID : "<<id;
		cout<<"\nPassword : "<<p;
		cout<<"\nName : "<<name;
		cout<<"\nClass :"<<grade;
		cout<<"\nSchool name :"<<univ;
		cout<<"\nEmail id :"<<email;
		cout<<"\nCourses taken: ";
		for(i=0;i<learn;i++){
			cout<<endl;
			cout<<str[i];
		}
	} else {
		gotoxy(45,space++);
		cout<<"ID : "<<id;
		gotoxy(45,space++);
		cout<<"Password : "<<p;
		gotoxy(45,space++);
		cout<<"Name : "<<name;
		gotoxy(45,space++);
		cout<<"Class :"<<grade;
		gotoxy(45,space++);
		cout<<"School name :"<<univ;
		gotoxy(45,space++);
		cout<<"Email id :"<<email;
		gotoxy(45,space++);
		cout<<"Courses taken: ";
		for(i=0;i<learn;i++) {
			gotoxy(45,space++);
			cout<<str[i];
		}
		space+=1;
	}
    cout<<endl;
}

void student::addStudent() {

    clrscr();
	fstream f;
	student s;
	cout<<"\n\t\t\tREGISTRATION";
	cout<<"\nSign up in Zertech Academy for free.";
	cout<<" Please fill up your following credentials : \n";
	int r= student::createStudentID();
	s.enterCredentialsr);
	f.open("course.dat",ios::binary|ios::app);
	if(f.fail()) {
		cerr<<"File not opened successfully";
		getch();
		exit(1);
	}
	f.write((char*)&s,sizeof(s));
	f.close();
	cout<<"Congratulations. Your profile has been added.";
}

int student::createStudentID() {

	fstream f;
	int r;
	student s;
	f.open("course.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile cannot be opened successfully.";
		getch();
		exit(0);
	}
	f.seekg(0,ios::end);
	int n=f.tellg();
	f.clear();
	int z=sizeof(student);
	if(n==0)
		r=1;
	else {
	    f.seekg(-z,ios::end);
		f.read((char*)&s,z);
		r=s.retid()+1;
	}
	f.close();
	return r;
}

void student::enter() {

	course c;
	fstream f;
	char *cour=NULL;
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}

	cout<<"Enter your name : ";
	gets(name);
	gotoxy(1,6);
	cout<<"Enter your class :";
	cin>>grade;
	cout<<"Enter school name : ";
	gets(univ);
	gotoxy(1,8);
	cout<<"Enter your email id :";
	cin>>email;
	while(1) {
		cout<<"\nHow many courses are you interested in learning ? :";
		cin>>learn;
		if(learn>5) {
			cout<<"Maximum courses that can be allotted is 5.";
			delay(1000);
		}
		else
			break;
	}
	clrscr();
	cout<<"\tCourses available to choose from :\n";
	course::listCourses();
	int last = course::lastCourse();
	if (last == 1)
		visitor::visitorMenu();
	int i=0;
	while (i<learn) {
		cout<<"Enter course no: ";
		cin>>n;
		if (n>last) {
			cout<<"Course not available. Please enter again.\n";
			delay(1000);
			i-=1;
			continue;
		}
		f.seekg(0,ios::beg);
		while(f.read((char*)&c,size)) {
			cour=c.retCourse();
			if(n==c.retCourseNo()) {
				strcpy(str[i],cour);
				break;
			}
		}
		i++;
	}
	cout<<"ID : "<<id;
	passwordGenerate();
	cout<<"\nPassword  : "<<pass;
	cout<<"   (Please note the ID and password for future reference) \n\n";
	f.close();
}

int student::modStudentCourse() {

	course c;
	fstream f;
	char *cour=NULL;
	f.open("cour.dat",ios::binary|ios::in);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}

	while(1) {
		cout<<"\nHow many courses do you want to learn : ";
		cin>>learn;
		if (learn>5) {
			cout<<"Maximum courses that can be allotted is 5. \n";
			delay(2000);
		}
		else
			break;
	}
	clrscr();
	cout<<"\n\tCourses available to choose from  ";
	course::listCourses();
	cout<<endl;
	int last = course::lastCourse();
	int i=0;
	while(i<learn) {
		cout<<"Enter course no: ";
		cin>>n;
		if (n>last) {
			cout<<"Course not available. Please enter again.\n";
			delay(1000);
			i-=1;
			continue;
		}
		f.seekg(0,ios::beg);
		while(f.read((char*)&c,sizeof(c))) {
			cour=c.retCourse();
			if(n==c.retCourseNo()) {
				strcpy(str[i],cour);
				break;
			}
		}
		i++;
	}
	f.clear();
	f.close();
}
