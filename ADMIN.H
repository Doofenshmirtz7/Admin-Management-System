class admin {                       //Managing admin data
	const static int admid;
	const static char admpass[5];
	static void addStudentTimeTable();
	static void deleteStudentTimeTable();
	static void addFacultyTimeTable();
	static void deleteFacultyTimeTable();
	static void deleteStudent();
	static void deleteFaculty();
	static void deleteApplication();

	public:
		static void adminLogin();
		static void adminMenu();
		static void getCourses();
		static void viewTimeTables();
		static void listStudentTimeTable();
		static void listFacultyTimeTable();
		static void modStudentTimeTable();
		static void modFacultyTimeTable();
		static void searchRecord();
		static void viewRecords();
		static void deleteRecords();
		static void receivedApplication();
};
const int admin::admid = 1957;
const char admin::admpass[] = "doof";

void admin::adminLogin() {

	int i,j,flag=0,r;
	for(j=0;j<3;j++) {
		clrscr();
		int id;
		char password[5];
		gotoxy(27,8);
		cout<<"A D M I N    L O G I N";
		gotoxy(30,10);
		cout<<"Enter ID : ";
		cin>>id;
		if(id!=admid) {
			if(j==2)
				break;
			gotoxy(30,11);
			cout<<"Invalid ID. Please try again.";
			delay(1000);
			continue;
		}
		gotoxy(30,12);
		cout<<"Enter password : ";
		for(i=0;i<4;i++) {
			password[i]=getche();
			delay(150);
			gotoxy(48+i,12);
			cout<<"\b*";
		}
		password[i]='\0';
		getch();
		r=strcmp(password,admpass);
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
		MainMenu();
	}
	else
	admin::adminMenu();
}

void admin::adminMenu()
{       int cho,flag,t;
	char opt,ex;
	do
	{
		clrscr();
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
			case 1: admin::getCourses();
				flag=1;	break;
			case 2:admin::viewTimeTables();
				flag=1;	break;
			case 3:admin::searchRecord();
				flag=1;	break;
			case 4:admin::viewRecords();
				flag=1;	break;
			case 5:admin::deleteRecords();
				flag=1;	break;
			case 6:admin::receivedApplication(); break;
			case 7:clrscr();
				gotoxy(28,10);
				cout<<"LOGGING OUT. Please wait...";
				delay(1200);
				clrscr();
				flag=1;
				t=1;	break;
			case 8:cout<<"\nExiting......";
				getch();
				exit(0);
			default:cout<<"\nNo such choice exists.";
		}
		if(flag==0) {
			cout<<"\nDo you want to continue ? :";
			cin>>opt;
		} else if (t==1)
			opt='n';
		else
			opt='y';
	}while(opt=='y'||opt=='Y');

	if(t==1) {
		clrscr();
		MainMenu();
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
		admin::adminMenu();
}

void admin::getCourses() {
	int cho;char opt;
	do {
		clrscr();
		cout<<"\n  1.View courses.";
		cout<<"\n  2.Add a course.";
		cout<<"\n  3.Delete a course.";
		cout<<"\n  4.Return to Admin menu ";
		cout<<"\nEnter your choice :";
		cin>>cho;
		switch(cho) {
			case 1: clrscr();
				cout<<"\n\t\tAvailable courses : ";
				course::listCourses();
				break;
			case 2:course::addCourse();	break;
			case 3:course::deleteCourse();	break;
			case 4:	return;
			default: cout<<"\nNo such choice exists.";
		}
		cout<<"\nDo you want to continue ? :";
		cin>>opt;
	}while(opt=='y'||opt=='Y');
	admin::adminMenu();
}

void admin::viewTimeTables() {
	 clrscr();
	int cho; char opt;
	cout<<"\n  1.Display Student Time Table";
	cout<<"\n  2.Modify Student Time Table";
	cout<<"\n  3.Display Faculty Time Table";
	cout<<"\n  4.Modify Faculty Time Table";
	cout<<"\n  5.Return to Admin menu";
	cout<<"\n  Enter your choice :";
	cin>>cho;
	switch(cho) {
		case 1:admin::listStudentTimeTable();	break;
		case 2:admin::modStudentTimeTable();	break;
		case 3:admin::listFacultyTimeTable();	break;
		case 4:admin::modFacultyTimeTable();	break;
		case 5:return;
		default:cout<<"\nChoice does not exist.";
	}
	if(cho==1||cho==3||cho>5) {
		cout<<"\nDo you want to continue ? :";
		cin>>opt;
	}
	else
		opt='y';
	if(opt=='y'||opt=='Y')
		admin::viewTimeTables();
	admin::adminMenu();
}

void admin::listStudentTimeTable()
{       clrscr();
	fstream f;
	f.open("time.dat",ios::binary|ios::in);
	if(f.fail()) {
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


void admin::modStudentTimeTable() {
	int cho,flag;
	char opt;

	do {
		clrscr();
		flag=0;
		cout<<"\n  1.Add to time table ";
		cout<<"\n  2.Delete from time table ";
		cout<<"\n  3.Return to Time table menu";
		cout<<"\nEnter choice :";
		cin>>cho;
		switch(cho) {
			case 1:admin::addStudentTimeTable();
				flag=1;	break;
			case 2:admin::deleteStudentTimeTable();	break;
			case 3:return;
			default:cout<<"\nNo such choice exists.";
		}
		if(flag==0) {
		cout<<"\nDo you want to continue ? :";
		cin>>opt;
		}
		else
			opt='y';
	}while(opt=='y'||opt=='Y');
	admin::adminMenu();
}

void admin::addStudentTimeTable() {
    clrscr();
	fstream f; timetable t;
	t.stu_input();
	f.open("time.dat",ios::binary|ios::app);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	f.write((char*)&t,sizeof(t));
	f.close();
}

void admin::deleteStudentTimeTable()
{
	fstream f1,f2; timetable t;
	int flag=0; char i[10];
	char *p2=NULL;
	f1.open("time.dat",ios::in|ios::out|ios::binary);
	if(f1.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("tempo.dat",ios::out|ios::binary);
	if(f2.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	cout<<"\nEnter day to be deleted :";
	gets(i);
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&t,sizeof(t))) {
		p2=t.retday();
		if(strcmpi(i,p2)==0) {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		cout<<"\nDay does not exist.";
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&t,sizeof(t))) {
		p2=t.retday();
		if(strcmpi(i,p2)!=0)
			f2.write((char*)&t,sizeof(t));
	}
	cout<<"\nDay has been deleted.";
	f1.close();
	f2.close();
	remove("time.dat");
	rename("tempo.dat","time.dat");
}
void admin::listFacultyTimeTable()
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

void admin::modFacultyTimeTable() {

	int cho,flag;
	char opt;
	do {
		clrscr();
		flag=0;
		cout<<"\n  1.Add to time table ";
		cout<<"\n  2.Delete from time table ";
		cout<<"\n  3.Return to Time table menu";
		cout<<"\nEnter choice :";
		cin>>cho;
		switch(cho) {
			case 1: admin::addFacultyTimeTable();
				flag=1;	break;
			case 2: admin::deleteFacultyTimeTable();	break;
			case 3: return;
			default:cout<<"\nNo such choice exists.";
		}
		if(flag==0){
			cout<<"\nDo you want to continue ? :";
			cin>>opt;
		}
		else
			opt='y';
	}while(opt=='y'||opt=='Y');
	admin::adminMenu();
}

void admin::addFacultyTimeTable() {

	clrscr();
	fstream f; timetable t;
	f.open("factime.dat",ios::binary|ios::app);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(1);
	}
	t.fac_input();
	f.write((char*)&t,sizeof(t));
	f.close();
}

void admin::deleteFacultyTimeTable() {

	fstream f1,f2;
	timetable t;
	int flag=0;
	char i[10],*p2=NULL;
	f1.open("factime.dat",ios::in|ios::out|ios::binary);
	if(f1.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("tempo.dat",ios::out|ios::binary);
	if(f2.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	cout<<"\nEnter day to be deleted :";
	gets(i);
	while(f1.read((char*)&t,sizeof(t))) {
		p2=t.retday();
		if(strcmpi(i,p2)==0) {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		cout<<"\nDay does not exist.";
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&t,sizeof(t))) {
		p2=t.retday();
		if(strcmpi(i,p2)!=0)
			f2.write((char*)&t,sizeof(t));
	}
	cout<<"\nDay has been deleted.";
	f1.close();
	f2.close();
	remove("factime.dat");
	rename("tempo.dat","factime.dat");
}

void admin::searchRecord() {
    int cho;char opt;
    faculty f;
	student s;
	do {
		clrscr();
		cout<<"\n  1.Search Student details.";
		cout<<"\n  2.Search Faculty details.";
		cout<<"\n  3.Return to Admin menu ";
		cout<<"\n  Enter your choice :";
		cin>>cho;
		switch(cho) {
			case 1:s.studentSearch();
				break;
			case 2:f.facultySearch();
				break;
			case 3:return;
			default:cout<<"\nNo such choice exists.";
		}
		cout<<"\nDo you want to continue ? :";
		cin>>opt;
	}while(opt=='y'||opt=='Y');
	admin::adminMenu();
}



void admin::viewRecords() {
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
			s.studentList();
			break;
		case 2: f.facultyList();
			break;
		case 3: return;
		default: cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? :";
	cin>>opt;
	}while(opt=='y'||opt=='Y');
	admin::adminMenu();
}

void admin::deleteRecords()
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
		case 1:admin::deleteStudent();
			break;
		case 2:admin::deleteFaculty();
			break;
		case 3:return;
		default:cout<<"\nNo such choice exists.";
	}
	cout<<"\nDo you want to continue ? :";
	cin>>opt;
	}while(opt=='y'||opt=='Y');
	admin::adminMenu();
}

void admin::deleteStudent()
{
	fstream f1,f2;
	student s;
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
	while(f1.read((char*)&s,sizeof(s))) {
		if(r==s.retid()) {
			flag=1;
			break;
		}
	}
	if(flag==0)	{
		cout<<"\nNo such profile exists.";
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&s,sizeof(s))) {
		if(s.retid()!=r)
			f2.write((char*)&s,sizeof(s));
	}
	cout<<"\nProfile deleted.";
	f1.close();
	f2.close();
	remove("course.dat");
	rename("temp.dat","course.dat");
}

void admin::deleteFaculty() {

	fstream f1,f2;
	faculty f;
	int flag=0,r;
	f1.open("faculty.dat",ios::binary|ios::in);
	if(f1.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("temp.dat",ios::binary|ios::out);
	if(f2.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	cout<<"\nEnter ID to be deleted : ";
	cin>>r;
	while(f1.read((char*)&f,sizeof(f))) {
		if(r==f.retid()) {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		cout<<"\nNo such profile exists.";
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&f,sizeof(f))) {
		if(a.retid()!=r)
			f2.write((char*)&f,sizeof(f));
	}
	cout<<"\nProfile deleted.";
	f1.close();
	f2.close();
	remove("faculty.dat");
	rename("temp.dat","faculty.dat");
}

void admin::receivedApplication()
{
	clrscr();
	fstream f,f1;
	faculty fac;
	char re; int z,i;
	f.open("faculty1.dat",ios::in|ios::binary|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	f1.open("faculty.dat",ios::app|ios::binary);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	f.seekg(0,ios::beg);
	f1.seekg(0,ios::end);
	while(f.read((char*)&fac,sizeof(fac))) {
		clrscr();
		fac.facdisplay(0);
		cout<<"\nDo you want to recruit : ";
		cin>>re;
		if(re=='y'||re=='Y')
			f1.write((char*)&fac,sizeof(fac));
	}
	f.clear();
	if(f.tellg()==0)
	{	cout<<"\n\nNo applications received.";
		getch();
	}
	f1.close();
	f.close();
	admin::deleteApplication();
}

void admin::deleteApplication() {

	fstream f1,f2;
	f1.open("faculty1.dat",ios::binary|ios::in);
	if(f1.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("temp.dat",ios::binary|ios::out);
	if(f2.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f1.close();
	f2.close();
	remove("faculty1.dat");
	rename("temp.dat","faculty1.dat");
}
