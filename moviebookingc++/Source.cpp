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
int movielistcount;
void login();
void adminpanel();
//void movies_list();
class movie
{
	string moviename;
	int price;
	int code;
	string time;
	int date;
public:
	movie()
	{
	
	}
	void addmoviedetails();
	void write();
	void display();
	void readmovielist();
	~movie()
	{

	}

};

void movie::display()
{
	
	int spacecount = 0;
	int stringcount = 0;
	stringcount = moviename.length();
	spacecount = 52 - stringcount-19;
	cout << endl<<"\t\t"<<movielistcount+1<<". "<<moviename;
	cout.width(spacecount);
	cout << code<<"\t\t"<<time<<"\t\t"<<date<<"\t\t"<<price;
	movielistcount++;
	

}

void movie::write()
{
	ofstream file;
	file.open("records\\moviedetails.txt", ios::app | ios::out | ios::binary);
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


void movie::readmovielist()
{
	system("cls");  //to clear screen for displaing movie list
	cout << "\t\t=======================================================================================";
	cout << "\n\t\t\t\t MOVIE TICKET BOOKING \n";
	cout << "\t\t=======================================================================================";
	cout << "\n\t\tMOVIES LIST\t\t\t CODE \t\tTIME \t\tDATE \t\tPRICE";
	ifstream file;
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
			display();
			file.read((char*)this, sizeof(*this));
		}
		file.close();
	}

}


void movie::addmoviedetails()
{
	char ch = 0;
	do 
	{
		cout << "Enter the code of the movie: ";
		cin >> code;
		fflush(stdin);
		cout << "Enter tha date of the movie: ";
		cin >> date;
		fflush(stdin);
		cout << "Enter the price of the movie: ";
		cin >> price;
		fflush(stdin);
		cin.ignore();
		cout << "Enter the name of the movie: ";
		getline(cin, moviename);
		fflush(stdin);
		cout << "Enter the time of the movie: ";
		getline(cin, time);
		fflush(stdin);
		
		
		write();
		cout << "Do you want to add another record? (press y for yes an n for no) : ";
		cin >> ch;
		fflush(stdin);
	} while (ch == 'y' || ch == 'Y');
}


int main()
{
	int ch = 0;
	movie object;
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
			object.readmovielist();
			printf("\n\n\n\t\tplease enter any key to continue.... ");
			_getch();
			break;
			/*			case 2:
							book_ticket();
							free(p);
							break;
						case 3:
							upcomming_movies();
							break;
						case 4:
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
		cout << "\t\t\t||             2- DELETE MOVIE DETAILS                            ||\n";
		cout << "\t\t\t||             3- ADD NEW UPCOMING MOVIE                          ||\n";
		cout << "\t\t\t||             4- Exit system:                                    ||\n";
		cout << "\t\t\t||================================================================||\n";
		cout << "\n\n\n\t\t\t\tEnter your choice ";
		cin >> ch;
		switch (ch)
		{
			case 1:
				object.addmoviedetails();
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
			break;
		case 3:
			exit(0);
			break;
		default:
			cout << "INVALID INPUT";
			goto flag5;

	}
}