class visitor {
	public:
		static void visitorMenu();
		static void about();
}

void visitor::visitorMenu() {

    int opt,flag;char ex;
	do {
        flag=0;
        student s;
        faculty f;
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
				course::listCourses();
				break;
			case 2: s.addStudent();	break;
			case 3: f.addFaculty();	break;
			case 4: about();
				flag=1;
				break;
			case 5: return;
			case 6:cout<<"Exiting....";
				delay(500);
				exit(0);
				break;
			default:cout<<"\nNo such choice exists.";
		}
		if(flag!=1) {
			cout<<"\nDo you want to continue ? :";
			cin>>ex;
		}
		else
			ex='y';
	}while(ex=='y'||ex=='Y');
	return;
}


void visitor::about() {
    int opt;char ex;
	do {
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
		switch(opt) {
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
