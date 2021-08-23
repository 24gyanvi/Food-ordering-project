/*#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
using namespace std;

/* sample database
itemcode   cuisine code  item name price rank
101             1       noodles         40      0
102             2       dal makhani     100     0
*/
//char disp_cus[5][]={"1. chinese 2. "}*/
char cuisine_name[5][40]={"chinese","punjab","south indian","north indian","Thai"};
class cuisine{
	int itemcod;
	int ccode;
	char itemname[80];
	float price;
	int rank;
	public:
		cuisine(){rank=0;}
		void getcuisi(){
			cout<<"enter itemcode :";
			cin>>itemcod;cout<<"\n";
			cout<<"enter ccode :";
			cin>>ccode;cout<<"\n";
			cout<<"enter item name :";
			cin.ignore();cin.getline(itemname,80);cout<<"\n";
			cout<<"enter price :";
			cin>>price;cout<<"\n";
			
		}
		void putcuisi(){
			cout<<"itemcode is:"<<itemcod;cout<<"\n";
			cout<<"code is:"<<ccode;cout<<"\n";
			cout<<"item name is:"<<itemname;cout<<"\n";
			cout<<"price is:"<<price;cout<<"\n";
			
		}
	
	char *ret_itemname()
	{
		return itemname;
	}
	int ret_itemcod()
	{
	       return itemcod;
	}
	float ret_price()
	{
		return price;
	}
	int ret_ccode()
	{
		return ccode;
	}

	void inc_cusine_rank()
	{
		rank++;
	}

};
void read_from_file1()
{ifstream fin("cusi.dat",ios::binary);
cuisine c1;
while(fin.read((char*)&c1,sizeof(c1)))
	{
	c1.putcuisi();
cout<<"\n";
	}
fin.close();getch();
}
void write_to_file1()
{ofstream fout("cusi.dat",ios::binary|ios::out|ios::app);
cuisine c1;
char choice='y';
do{
	c1.getcuisi();
 fout.write((char*)&c1,sizeof(c1));
	cout<<"add more records? :";
	cin>>choice;
}
	while(choice=='y');
	fout.close();
}
void srch_by_itemcode(int icod)
{system("cls");
ifstream fin("cusi.dat",ios::binary);
cuisine c1;
int qty,found=0,amt=0;
char ch;
while(fin.read((char*)&c1,sizeof(c1)))
	{
		if(c1.ret_itemcod()==icod)
	{

	found=1;
	c1.putcuisi();
	cout<<"want to order?:";
	cin>>ch;
	if(ch=='y'){cout<<"enter quantity:";
	cin>>qty;
	amt=amt+(qty*c1.ret_price());
	cout<<"your final amount is:"<<amt;
	getch();
	}
else{continue;}	 }
	}
fin.close();
if(!found)
{
cout<<"item not found"; getch();
}
}


class restaurent{
	int rcode;
	char rname[20];
	char location[30];
	int cuisine_code;  //1. chinese 2. punjab 3. south indian 4. north indian 5. Thai
	int rrank;
	int order;
	
	public:
		restaurent(){
			rrank=order=0;
		}
	void inc_rest_rank()
	{
		rrank++;
	}
	void getdata(){
		cout<<"\n enter rcode =";
		cin>>rcode;

		cout<<"\n enter rname = ";
		cin>>rname;

		cout<<"\n enter location = ";
		cin>>location;

		//cusi:

		cout<<"\n enter cuisine code (1. chinese 2. punjabi 3.S indian 4.N indian 5. thai ) = ";
		cin>>cuisine_code;

 	}
	void putdata(){
		cout<<"rcode:"<<rcode<<endl;
		cout<<"name:"<<rname<<endl;
		cout<<"location:"<<location<<endl;
		cout<<"Cuisine Code "<<cuisine_code<<endl;
		cout<<"cuisine name:";
		cout<<cuisine_name[cuisine_code-1]<<endl;
	}
	char *ret_rname()
	{
		return rname;
	}
	char *ret_location()
	{
		return location;	}
	int ret_rcode()
	{
		return rcode;
	}
	int ret_cuisicode()
	{
		return cuisine_code;
	}
	


};


void write_to_file()
{ofstream fout("restin.dat",ios::binary|ios::out|ios::app);
restaurent r1;
char choice;
do{
	r1.getdata();
 fout.write((char*)&r1,sizeof(r1));
 cout<<"hello";
	cout<<"add more records? :";
	cin>>choice;
}
	while(choice=='y');
	fout.close();
}

void read_from_file()
{ifstream fin("restin.dat",ios::out|ios::binary);
restaurent r1;
while(fin.read((char*)&r1,sizeof(r1)))
	{
	r1.putdata();
	}
	cout<<"\n";
fin.close();
}


void srch_by_rname()
{ifstream fin("restin.dat",ios::binary);
restaurent r1;
int found=0;
char uname[40];
cout<<"enter restaurant to search "; cin>>uname;
while(fin.read((char*)&r1,sizeof(r1)))
	{
		if(strstr(r1.ret_rname(),uname))
	{
		
	found=1;
	r1.putdata(); break;}
	}
fin.close();
if(!found)
{
cout<<"restaurant not found"; getch();
}
}


void srch_by_loc()
{ifstream fin("restin.dat",ios::binary);
restaurent r1;
int found=0;
char uloc[40];
cout<<"enter location to search ";cin>>uloc; 
while(fin.read((char*)&r1,sizeof(r1)))
	{
		if(strcmpi(r1.ret_location(),uloc)==0)
	{

	found=1;
	r1.putdata(); }
	}
fin.close();
if(!found)
{
cout<<"restaurant not found"; getch();
}
}


/*main()
{/*write_to_file();
read_from_file();
srch_by_loc();
srch_by_rname();
read_from_file1();
srch_by_itemname();*/


