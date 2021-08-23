/*#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include <windows.h>
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y) 
{ 
CursorPosition.X = x; // Locates column
CursorPosition.Y = y; // Locates Row
SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed 
}

using namespace std;*/

class reg;
void chk(char *n, char *p);
class reg
{   private:
		char number[11];
		char name[40];
		char emailid[40];
		char address[40];
		char pwd[20];
		char location[60];
    public:	

	void getdata()
	{
	        /*cin.ignore();
		gotoXY(40,22);*/

		cout<<"\n enter your name = ";
	        cin>>name;
	        cin.ignore();
		
		/*cin.ignore();
		gotoXY(40,24);*/
		cout<<"\n enter your number = ";
		cin.getline(number,11);
		cin.ignore();
	
		/*cin.ignore();
		gotoXY(40,26);*/
		cout<<" \n enter your email id =";
		cin.getline(emailid,40);
		cin.ignore();
     
		/*cin.ignore();
		gotoXY(40,28);*/
		cout<<"\n enter your address = ";
		cin.getline(address,40);
		cin.ignore();
	
		/*cin.ignore();
		gotoXY(40,30);*/
         	cout<<"\n enter your password = ";
		cin.getline(pwd,40);
		cin.ignore();
	
	}


void putdata()
{
system("CLS");
cout<<"\n Name = "<<name;
cout<<"\n Registered Mobile Number = "<<number;
cout<<"\n Email id = "<<emailid;
cout<<"\n Address = "<<address;
}

char *ret_number()
{return number;}

char *ret_pwd()
{ return pwd;}

char *ret_location()
{
	return location;}

char *ret_name()
{return name;}
};



void read_fromfile()
{
	ifstream fileobj("cus.dat",ios::binary);	
	reg r;
	while(fileobj.read((char*)&r,sizeof(r)))
	{r.putdata();
}
	fileobj.close();
}

void signup()
{ ofstream fileobj("cus.dat",ios::binary|ios::out|ios::app);
  reg r;
  r.getdata();
  fileobj.write((char*)&r,sizeof(r));
  fileobj.close();
}

void signin()
 { char n[30]; char p[30];
  cout<<"\n Enter your registered mobile number: ";
  cin>>n;
  cout<<"\n Enter your password: ";
  cin>>p;
  chk(n,p);

}

void chk(char n[], char p[])
{
	reg r;
	ifstream fileobj("cus.dat",ios::binary);
	int found=0;
	//cout<<n<<p;
 	while(fileobj.read((char*)&r,sizeof(reg)))
	{  if(((strcmp(r.ret_number(),n))==0)&&(strcmp(r.ret_pwd(),p)==0))
	     {found =1;
	          r.putdata();
	           return ;
	       }
       }
       if(!found)
       {cout<<" \n not found";
	exit(0);
       }
       
}
/*main()
{  int y ;
cout<<"\n welcome to :"<<endl;
cout<<"\n menu";
cout<<"\n 1.login";
cout<<"\n 2.add new account";
cout<<"\n enter your choice";
cin>>y;
switch(y)
{
	
	case 1: signin();
		break;
		case 2: signup();
		break;
		case 3:exit(0);
		default:cout<<"\n wrong input"<<endl;
}
 
getch();
return 0;
}*/

