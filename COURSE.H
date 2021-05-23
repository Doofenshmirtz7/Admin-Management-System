class course {                 //Managing courses
    int no;
	char cor[30];
	static int createCourseNo();

	public:
		static void addCourse();
		static void deleteCourse();
		static void listCourses();
		static void enterCourseName(int r) {
	        no=r;
			cout<<"Enter course name : ";
			gets(cor);
		}
		static int lastCourse();
		void displayCourse() {
			cout<<no;
			cout<<" ";
			cout<<cor;
		}
		char *retCourse() {
			return cor;
		}
		int retCourseNo() {
		return no;
		}
};

int course::createCourseNo() {

	fstream f;
	int r;
	f.open("cour.dat",ios::binary|ios::in|ios::out);
	if(f.fail()) {
		cerr<<"\nFile cannot be opened successfully.";
		getch();
		exit(0);
	}
	f.seekg(0,ios::end);
	int n=f.tellg();
	f.clear();
	int z=sizeof(course);
	if(n==0)
		r=1;
	else {
        f.seekg(-z,ios::end);
		f.read((char*)this,z);
		r=this->retCourseNo() + 1;
	}
	f.close();
	return r;
}


void course::addCourse() {

	int r=course::createCourseNo();
	fstream f;
	course c;
	f.open("cour.dat",ios::app|ios::binary);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	c.enterCourseName(r);
	f.write((char*)&c,sizeof(c));
	cout<<"\nCourse added.";
	f.close();
}


void course::deleteCourse() {

	fstream f1,f2;
	course c;
	int i,flag=0;
	f1.open("cour.dat",ios::in|ios::out|ios::binary);
	if(f1.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	f2.open("stemp.dat",ios::out|ios::binary);
	if(f2.fail()) {
		cerr<<"\nFile not opened successfully .";
		getch();
		exit(0);
	}
	cout<<"\nEnter course number to be deleted :";
	cin>>i;
	while(f1.read((char*)&c,sizeof(c))) {
		if(i==c.retCourseNo()) {
			flag=1;
			break;
		}
	}
	if(flag==0) {
		cout<<"\nNo such course exists.";
		delay(2000);
		return;
	}
	f1.seekg(0,ios::beg);
	while(f1.read((char*)&c,sizeof(c))) {
		if(i!=c.retCourseNo())
			f2.write((char*)&c,sizeof(c));
	}
	cout<<"\nCourse has been deleted.";
	getch();
	f1.close();
	f2.close();
	remove("cour.dat");
	rename("stemp.dat","cour.dat");
}

void course::listCourses() {

    fstream f;
	course c;
    int i=1,j=3;
	f.open("cour.dat",ios::in|ios::binary|ios::out);
	if(f.fail()) {
		cerr<<"\nFile not opened successfully.";
		getch();
		exit(0);
	}
	cout<<endl;
	while(f.read((char*)&c,sizeof(c))) {
        if(i<0) {
			gotoxy(35,j);
			j++;
		}
		c.displayCourse();
		i*=-1;
		if(i>0)
			cout<<endl;
	}
	int n=f.tellg();
	if(n==0) {
		cout<<"\nNo course available !";
		getch();
	}
	f.close();
}

int course::lastCourse() {
	int last;
	f.open("course.dat", ios::binary|ios::in);
	if (f.fail()) {
		cerr<<"\nFile not opened successfully";
		getch();
		exit(0);
	}
	size=sizeof(c);
	f.seekg(-size,ios::end);
	f.read((char*)&c,size);
	last=c.retCourseNo();
	f.seekg(0,ios::end);
	if(f.tellg()==0) {
		cout<<"\n No course available. Try again later.";
		getch();
		f.close();
		return 1;
	} else {
		return last;
	}
}
