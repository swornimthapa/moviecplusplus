#include<iostream>
#include<conio.h>
#include<fstream>
#include<cstring>
#include<string>
#include<iomanip>
using namespace std;

struct login {
	char username[20];
	char password[20];
}l;
int movielistcount=0;
int upcommingmovielistcount=0;
void login();
void adminpanel();
string customerfile;

int numberofdetailsinfile;
//void movies_list();
int seat[50] = { 0 };
class movie
{
	string moviename;
	int price;
	int code;
	string time1;
	string time2;
	string time3;
	string time4;
	string date1;
	string date2;
	string date3;
	string date4;
public:
	movie()
	{
	
	}
	void addmoviedetails();
	void write(int index);
	void display(int index);
	void display(char index);
	void displayshowtime(int index);
	template <typename T>
	void readmovielist(T index);
	void addnewupcommingmovies();
	~movie()
	{

	}

};
class customer
{
	string firstname;
	string secondname;
	double number;
	int seatnumber;
public:
	customer()
	{

	}
	void bookticket();
	void countnumberofdetails();
	void hall();
	~customer()
	{

	}


};

void customer::bookticket()
{
	ofstream file;
	char ch;
	cout << endl << numberofdetailsinfile;
	do
	{
		
		cout << "\n\tENTER THE PHONE NUMBER OF PERSON:";
		cin >> number;
		fflush(stdin);
		
		cout << "\n\tENTER THE SEAT NUMBER:";
		cin >> seatnumber;
		fflush(stdin);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		

		cout << "\n\tENTER THE FIRST NAME OF PERSON:";
		getline(cin, firstname);
		fflush(stdin);
		
		cout << "\n\tENTER THE LAST NAME OF PERSON:";
		getline(cin, secondname);
		fflush(stdin);

		file.open(customerfile, ios::app | ios::out | ios::binary);
		if (!file)
		{
			cout << "file not opened";
		}
		else
		{
			file.write((char*)this, sizeof(*this));
		}
		file.close();

		cout << "Do you want to add another record? (press y for yes an n for no) : ";
		cin >> ch;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		fflush(stdin);
		} while (ch == 'y' || ch == 'Y');
}

void movie::display(int index)
{
	
	int spacecount = 0;
	int stringcount = 0;
	if (index == 1)
	{
		stringcount = moviename.length();
		spacecount = 47 - stringcount - 19;
		cout << endl << "\t\t" << movielistcount + 1 << ". " << moviename;
		cout.width(spacecount);
		cout << code << "\t\t" << price;
		//spacecount = 7;
		//cout.width(spacecount);
		cout <<"\t"<< date1 << "," << date2 << ","  << date3 << "," << date4;
		cout<< "\t\t" <<time1 << "," << time2 << ","  << time3 << "," << time4;
		movielistcount++;
	}
	else if (index == 3)
	{
		//cout << endl << "\t\t" << upcommingmovielistcount + 1 << ". " << moviename;
		stringcount = moviename.length();
		spacecount = 78 - stringcount - 19;
		cout << endl << "\t\t" << upcommingmovielistcount + 1 << ". " << moviename;
		cout.width(spacecount);
		cout << date1;
		upcommingmovielistcount++;
	}
}

void movie::display(char index)
{
	//char ch;
	int spacecount = 0;
	int stringcount = 0;
	stringcount = moviename.length();
	spacecount = 79 - stringcount - 19;
	cout << endl << "\t\t" << movielistcount + 1 << ". " << moviename;
	cout.width(spacecount);
	cout << code << "\t\t\t\t" << price;
	//spacecount = 7;
	//cout.width(spacecount);
	//cout << "\t" << date1 << "," << date2 << "," << date3 << "," << date4;
	//cout << "\t\t" << time1 << "," << time2 << "," << time3 << "," << time4;
	movielistcount++;
	
/**	switch (ch)
	{
		case 1:
			system("cls");
			cout << "\t\t================================================================================================";
			cout << "\n\t\t\t\t\t\t\t MOVIE TICKET BOOKING \n";
			cout << "\t\t================================================================================================";
			cout << "\n\t\tDATE \t\t\tTIME ";
			cout << endl << "\t\tTHE TIMING FOR THE " << moviename << " ARE : ";
			cout << endl << "1." << date1 << "\t\t\t" << time1;
			cout << endl << "2." << date1 << "\t\t\t" << time1;
			cout << endl << "3." << date1 << "\t\t\t" << time1;

	}*/
	

}

void movie::displayshowtime(int index)
{
	ifstream file;
	int ch;
	//customer count;
	file.open("records\\moviedetails.txt", ios::in | ios::binary);
	if (!file)
	{
		cout << "file not opened";
	}
	else
	{
		for (int i = 0; i < index; i++)
		{
			file.read((char*)this, sizeof(*this));

		}
		//moviename ya aaayo
		system("cls");
		cout << "\t\t================================================================================================";
		cout << "\n\t\t\t\t\t\t\t MOVIE TICKET BOOKING \n";
		cout << "\t\t================================================================================================";
		cout << endl << "\t\tTHE TIMING FOR THE " << moviename << " ARE : ";
		cout << "\n\t\tDATE \t\t\tTIME ";
		cout << endl << "\t\t1." << date1 << "\t\t\t" << time1;
		cout << endl << "\t\t2." << date2 << "\t\t\t" << time2;
		cout << endl << "\t\t3." << date3 << "\t\t\t" << time3;
		cout << endl << "\t\t4." << date4 << "\t\t\t" << time4;
		//file.close();
		label:
		cout << "\n\t\tENTER YOU APPROPRIATE TIMING : ";
		cin>> ch;
		
		switch (ch)
		{
			case 1:
				customerfile = "records\\" + moviename + date1 + time1 + ".txt";
				
				break;
			case 2:
				customerfile = "records\\" + moviename + date2 + time2 + ".txt";
				
				break;
			case 3:
				customerfile = "records\\" + moviename + date3 + time3 + ".txt";
				
				break;
			case 4:
				customerfile = "records\\" + moviename + date4 + time4 + ".txt";
				
				break;
			default:
				cout << "\n\n\t\tINVALID INPUT";
				goto label;
		}
		//customerfile = "records\\" + moviename + date1 + time1 + ".txt";
		file.close();


	}
}



void customer::countnumberofdetails()
{
	ifstream file;
	file.open(customerfile, ios::in | ios::binary);
	if (!file)
	{
		cout << "file not opened";
	}
	else
	{

		file.read((char*)this, sizeof(*this));
		while (!file.eof())
		{
			file.read((char*)this, sizeof(*this));
			numberofdetailsinfile++;
		}
		file.close();
	}
	
}


void movie::write(int index)
{
	ofstream file;
	if (index == 1)
	{
		file.open("records\\moviedetails.txt", ios::app | ios::out | ios::binary);
	}
	else if (index == 2)
	{
		file.open("records\\upcommingmoviedetails.txt", ios::app | ios::out | ios::binary);
	}
	if (!file)
	{
		cout << "file not opened";
	}
	else
	{
		file.write((char*)this, sizeof(*this));

	}
	file.close();
}

template <typename T>
 void movie::readmovielist(T index)
{
	system("cls");  //to clear screen for displaing movie list
	movielistcount = 0;
	upcommingmovielistcount = 0;
	ifstream file;
	if (index == 1)
	{
		index = 1;
		cout << "\t\t================================================================================================";
		cout << "\n\t\t\t\t\t\t\t MOVIE TICKET BOOKING \n";
		cout << "\t\t================================================================================================";
		cout << "\n\t\tMOVIES LIST\t\t     CODE \tPRICE \tDATE \t\t\t\tTIME";
		file.open("records\\moviedetails.txt", ios::in | ios::binary);
		if (!file)
		{
			cout << "file not opened";
		}
		else
		{
			file.read((char*)this, sizeof(*this));
			while (!file.eof())
			{
				display(index);
				file.read((char*)this, sizeof(*this));
			}
			file.close();
		}
	}
	else if (index == 'b')
	{
		index = 'b';
		int ch;
		cout << "\t\t================================================================================================";
		cout << "\n\t\t\t\t\t\t\t MOVIE TICKET BOOKING \n";
		cout << "\t\t================================================================================================";
		cout << "\n\t\tMOVIES LIST\t\t\t\t\t\t     CODE \t\t\tPRICE ";
		file.open("records\\moviedetails.txt", ios::in | ios::binary);
		if (!file)
		{
			cout << "file not opened";
		}
		else
		{
			file.read((char*)this, sizeof(*this));
			while (!file.eof())
			{
				display(index);
				file.read((char*)this, sizeof(*this));
			}
			file.close();
			cout << endl << "\t\tEnter the SN to view the show  timing : ";
			cin >> ch;
			displayshowtime(ch);
			
		}
	}
	else if (index == 3)
	{
		index = 3;
		cout << "\t\t=======================================================================================";
		cout << "\n\t\t\t\t MOVIE TICKET BOOKING \n";
		cout << "\t\t=======================================================================================";
		cout << "\n\t\tMOVIES LIST\t\t\t\t\tRELSEASING DATE ";
		file.open("records\\upcommingmoviedetails.txt", ios::in | ios::binary);
		if (!file)
		{
			cout << "file not opened";
		}
		else
		{
			file.read((char*)this, sizeof(*this));
			while (!file.eof())
			{
				display(index);
				file.read((char*)this, sizeof(*this));
			}
			file.close();
		}
	}
	
	

}


void movie::addmoviedetails()
{
	char ch = 0;
	string filename1;
	string filename2;
	string filename3;
	string filename4;
	ofstream file;
	do 
	{
		cout << "Enter the code of the movie: ";
		cin >> code;
		fflush(stdin);
		
		cout << "Enter the price of the movie: ";
		cin >> price;
		fflush(stdin);
		cin.ignore();

		cout << "Enter the name of the movie: ";
		getline(cin, moviename);
		fflush(stdin);

		cout << "Enter the 1st time of the movie: ";
		getline(cin, time1);
		fflush(stdin);

		cout << "Enter the 2nd time of the movie: ";
		getline(cin, time2);
		fflush(stdin);

		cout << "Enter the 3rd time of the movie: ";
		getline(cin, time3);
		fflush(stdin);

		cout << "Enter the 4th time of the movie: ";
		getline(cin, time4);
		fflush(stdin);

		
		cout << "Enter the 1st date of the movie: ";
		getline(cin, date1);
		fflush(stdin);

		cout << "Enter the 2nd date of the movie: ";
		getline(cin, date2);
		fflush(stdin);

		cout << "Enter the 3rd date of the movie: ";
		getline(cin, date3);
		fflush(stdin);

		cout << "Enter the 4th date of the movie: ";
		getline(cin, date4);
		fflush(stdin);
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		write(1);
		cout << "Do you want to add another record? (press y for yes an n for no) : ";
		cin >> ch;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		fflush(stdin);
		filename1 = "records\\"+moviename + date1 + time1 + ".txt";
		filename2 = "records\\" + moviename + date2 + time2 + ".txt";
		filename3 = "records\\" + moviename + date3 + time3 + ".txt";
		filename4 = "records\\" + moviename + date4 + time4 + ".txt";
		file.open(filename1, ios::app | ios::out | ios::binary);
		if (!file)
		{
			cout << "file could not be created";
		}
		else
		{
			file.close();
		}
		file.open(filename2, ios::app | ios::out | ios::binary);
		if (!file)
		{
			cout << "file could not be created";
		}
		else
		{
			file.close();
		}
		file.open(filename3, ios::app | ios::out | ios::binary);
		if (!file)
		{
			cout << "file could not be created";
		}
		else
		{
			file.close();
		}
		file.open(filename4, ios::app | ios::out | ios::binary);
		if (!file)
		{
			cout << "file could not be created";
		}
		else
		{
			file.close();
		}

	} while (ch == 'y' || ch == 'Y');
}


void movie::addnewupcommingmovies()
{
	char ch = 0;
	do
	{
		
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Enter the name of the movie: ";
		getline(cin, moviename);
		//cin.sync();
		//fflush(stdin);
		cout << "Enter tha releasing date of the movie: ";
		getline(cin, date1);
		//fflush(stdin);
		//cin.ignore();
		write(2);
		cout << "Do you want to add another record? (press y for yes an n for no) : ";
		cin >> ch;
		
		//fflush(stdin);
	} while (ch == 'y' || ch == 'Y');
}



void customer::hall()
{
	int seatcount = 0;
    int count1 = 0;
	count1 = numberofdetailsinfile;
	string name[50];
	string h[51] = {"EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY","EMPTY"};
	int i = 0, j = 0, index = 1;

	ifstream file;
	file.open(customerfile, ios::in | ios::binary);
	if (!file)
	{
		cout << "file not opened";
	}
	else
	{

		file.read((char*)this, sizeof(*this));
		while (!file.eof())
		{

			seat[j] = this->seatnumber;
			name[j]=this->firstname;
			j++;
			file.read((char*)this, sizeof(*this));
			
		}
		file.close();
	}




	system("cls");
	cout<<"      ________________________________________________________________________________________________________________________________________________________________ \n ";
	cout << "    /                                                                    SCREEN                                                                                      \\\n";
	cout << "    /__________________________________________________________________________________________________________________________________________________________________\\\n\n\n\n ";
	j = 0;
	for (i = 0; i < count1; i++)
	{
		h[seat[i]]= name[i];
	}
	for (i = 0; i < 5; i++)
	{

		for (j = 0; j < 10; j++)
		{
			cout <<"\t" <<"0"<< index + j << ". " << h[j + index];
		}
		index = index + 10;
		cout <<endl;
	}
	//printf("\n\t\t\t\t\t\t\t\t\t\t\tAVAILABLE SEAT: %d", 50 - count1);
	//printf("\n\t\t\t\t\t\t\t\t\t\t\tOCCUPIED SEAT: %d", count1);

}


int main()
{
	int ch = 0;
	movie object;
	customer object1;
	cout << "\t\t=======================================================================";
	cout << "\n\t\t\t\t MOVIE TICKET BOOKING \n";
	cout << "\t\t=======================================================================";
	login();
	do
	{
		system("cls");
		cout << "\t\t\t                 Movie Ticket Booking System\n";
		cout << "\t\t\t ==================================================================\n";
		cout << "\t\t\t||             1- VIEW CURRENTLY SHOWING MOVIE LIST               ||\n";
		cout << "\t\t\t||             2- BOOK TICKETS                                    ||\n";
		cout << "\t\t\t||             3- VIEW UPCOMING MOVIE LIST                        ||\n";
		cout << "\t\t\t||             4- BOOKING STATUS                                  ||\n";
		cout << "\t\t\t||             5- CANCEL TICKETS                                  ||\n";
		cout << "\t\t\t||             6- Exit system:                                    ||\n";
		cout << "\t\t\t||================================================================||\n";
		cout << "\n\n\n\t\t\t\tEnter your choice ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			object.readmovielist<int>(1);
			cout << "\n\n\t\ PLEASE NOTE : THE DATE AND TIME ARE CORRESPONDING TO EACH OTHER";
			cout << "\n\n\n\t\t please enter any key to continue.... ";
			_getch();
			break;
		case 2:
			object.readmovielist<char>('b');
			object1.countnumberofdetails();
			object1.hall();
			object1.bookticket();
				cout << "\n\n\n\t\tplease enter any key to continue.... ";
				_getch();
				break;
		case 3:
			object.readmovielist(3);
			cout<<"\n\n\n\t\tplease enter any key to continue.... ";
			_getch();
			break;
	/**					case 4:
							booking_status();
							break;
						case 5:
							cancel();
							printf("\n\n\n\t\tplease enter any key to continue.... ");
							getch();
							break; */
		case 6:
			exit(0);
			break;
		default:
			cout << "\n\tInvalid input";
			cout << "\n\n\n\t\tplease enter any key to continue.... ";
			_getch();
			break;
		}
	} while (1);
	//free(p);    
	return 0;
}

void adminpanel()
{
	int ch = 0;
	int i = 0,num=0;
	movie object;
	do
	{
		system("cls");
		cout << "\t\t\t                 Movie Ticket Booking System\n";
		cout << "\t\t\t ==================================================================\n";
		cout << "\t\t\t||             1- ADD MOVIE DETAILS                               ||\n";
		cout << "\t\t\t||             2- ADD NEW UPCOMING MOVIE                          ||\n";
		cout << "\t\t\t||             3- DELETE MOVIE DETAILS                            ||\n";
		cout << "\t\t\t||             4- Exit system:                                    ||\n";
		cout << "\t\t\t||================================================================||\n";
		cout << "\n\n\n\t\t\t\tEnter your choice ";
		cin >> ch;
		switch (ch)
		{
			case 1:
				object.addmoviedetails();
				break;
			case 2:
				object.addnewupcommingmovies();
				break;
			
			case 4:
				login();
				break;
			default:
				cout << "\n\tInvalid input";
				cout << "\n\n\n\t\tplease enter any key to continue.... ";
				_getch();
				break;
		}
	} while (1);
}



void login()
{
	system("cls");
	cout << "\t\t=======================================================================";
	cout << "\n\t\t\t\t MOVIE TICKET BOOKING \n";
	cout << "\t\t=======================================================================";
	cout << "\n\t\t\t\t LOGIN";
	int t = 0, i = 0, choice = 0;
	char username[20]{};
	char password[20]{};
	char pw, space = ' ';
	fstream file;
	cout << "\n\t[1]. CREATE A NEW ACCOUNT";
	cout << "\n\t[2]. LOGIN";
	cout << "\n\t[3]. EXIT";
flag5:
	cout << "\n\tENTER THE CHOICE:";
	cin >> choice;
	switch (choice)
	{
	case 1:
		 file.open("records\\login.txt", ios::out |ios ::binary);
		if (!file)
		{
			cout << "ERROR!!...FILE COULDNOT BE OPENED";
			exit(0);
		}
		cout << "\n\tENTER THE NEW USERNAME:";
		cin >> l.username;
		//scanf("%s",&l.username);
		cout << "\tENTER THE NEW PASSWORD:";
		while ((pw = _getch()) != 13)  // 13 is the ASCII of enter.. this loop hides the password.
		{
			l.password[i] = pw;
			i++;
			cout << "*";
		}
		l.password[i] = '\0';
		file.write((char*)&l, sizeof(l));
		file.close();
		goto flag;
		break;
	case 2:
		flag:
			i = 0;
			cout << "\n\tENTER THE DETAILS FOR LOGIN:";
		again:
			cout << "\n\tENTER THE USERNAME:";
			//scanf("%s",username);
			cin >> username;
			cout << "\tENTER THE PASSWORD:";
			while ((pw = _getch()) != 13)  // 13 is the ASCII of enter.. this loop hides the password.
			{
				password[i] = pw;
				i++;
				cout << "*";
			}
			password[i] = '\0';
			if (strcmp(username, "admin") == 0 && strcmp(password, "password") == 0)
			{
				cout << "\n\t LOGIN SUCESSFULL....WELCOME ADMIN";
				cout << "\n\tpress any key to continue........";
				_getch();  // holds the console
				adminpanel();
			}
			else
			{
				file.open("records\\login.txt", ios::in | ios::binary);
				if (!file)
				{
					cout << "ERROR!!...FILE COULD NOT BE OPENED";
					exit(0);
				}
				file.read((char*)&l, sizeof(l));
				//while (!file.eof())
				//{
				//file.read((char*)&l, sizeof(l));
				if (strcmp(username, l.username) == 0)
				{
					if (strcmp(password, l.password) == 0)
					{
						cout << "\n\t LOGIN SUCESSFULL....WELCOME USER";
						cout << "\n\tpress any key to continue........";
						_getch();  // holds the console
					}
				}
			    if(strcmp(username, l.username) != 0 || strcmp(password, l.password) != 0)
				{
					i = 0;
					if (t < 1)
					{
						cout << "\n\tINVALID USERNAME OR PASSWORD...TRY AGAIN:";
					}
					t++;
					if (t == 2)
					{
						cout << "\n\tSORRY!!..you have entered wrong username and password for 2 times!!";
						exit(0);
					}
					goto again;
				}
				file.close();
			}
			//_getch();
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "INVALID INPUT";
			goto flag5;

	}
	
}