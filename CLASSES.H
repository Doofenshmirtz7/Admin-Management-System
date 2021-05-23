class student  {                   //Managing student data
	int id;
	char pass[20];
	public:
		void studentLogin();
		void studentMenu(int);
		void getStudent(int);
		void studentList();
		void studentSearch();
		void setStudent(int);
		void getStudentTimeTable(int);
		void getStudentCourse(int);
		void setStudentPassword(int);
		void setStudentName(int);
		void setStudentEmail(int);
		void setStudentClass(int);
		void setStudentUniv(int);
		void setStudentCourse(int);
};

class faculty {                     //Managing faculty data
	int id;
	char pass[20];
	public:
		void facultyLogin();
		void facultyMenu(int);
		void getFaculty(int);
		void facultyApplication();
		void facultyList();
		void setFaculty(int);
		void facultySearch();
		void getFacultyTimeTable(int);
		void deleteApplication();
		void setFacultyPassword(int);
		void setFacultyName(int);
		void setFacultyContact(int);
		void setFacultyEmail(int);
		void setFacultyCourse(int);
};

class admin {                       //Managing admin data
	char admid[5];
	char admpass[15];
	public:
		void adminLogin();
		void adminMenu();
		void searchRecord();
		void getCourses();
		void viewRecords();
		void deleteRecords();
		void receivedApplication();
		void viewTimeTables();
		void addStudentTimeTable();
		void addFacultyTimeTable();
		void deleteStudentTimeTable();
		void deleteFacultyTimeTable();
		void deleteStudent();
		void deleteFaculty();
		void modStudentTimeTable();
		void modFacultyTimeTable();
		void listStudentTimeTable();
		void listFacultyTimeTable();
};

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

class course {                 //Managaing courses
    int no;
	char cor[30];
	public:
		void addCourse();
		void deleteCourse();
		void listCourses();
		void enterCourseName(int r)
		{       no=r;
			cout<<"Enter course name : ";
			gets(cor);
		}
		void displayCourse()
		{
			cout<<no;
			cout<<" ";
			cout<<cor;
		}
		char *retCourse();
		int retCourseNo()
		{	return no;}

};

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
