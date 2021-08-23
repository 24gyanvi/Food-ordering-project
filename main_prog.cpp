#include<iostream>
#include<conio.h>
#include<fstream>
#include<string.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
#include"rest.h"
#include"project.h"
//Function Prototypes
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;
void gotoXY(int x, int y)
{
    CursorPosition.X = x; // Locates column
    CursorPosition.Y = y; // Locates Row
    SetConsoleCursorPosition(console,CursorPosition); // Sets position for next thing to be printed
}


void splash();
void order();
int order_food(int);
int srch_by_cuisine(int);
void user();

void main_menu();
void admin_section();
void rest_maint();
// write to rest_rec
//removing rest_rec
void data_analysis();
void rest_ranking();
//void rest_name_search();
void cust_area_search();
void user_section()
{
    order(); // order food
    //	search_by_area();
}
//rest_ranking();
//rest_name search();
//	void search_by_item();
//void new_user(); // add new user
//void update_info(); // modify information
//void exit_app(); // delete user


void admin_section()
{
    int choice;
    cout<<"what do you want:\n";
    cout<<"1.view records\n";
    cout<<"2.add more records\n";
    cout<<"3.delete records:\n";
    cout<<"4.write to file:\n";
    cout<<"5.write cuisine\n";
    cout<<"6.read cuisine\n";
    cin>>choice;
    if(choice==1)
        {
            read_from_file();
            getch();
        }
    else if(choice==4)
        write_to_file();
    else if(choice==5)
        write_to_file1();
    else if(choice==6)
        read_from_file1();

}


main()
{
    splash();
    system("cls");
    int num;


    cout<<"there are two options available:\n";
    cout<<"1. transaction  2.admin section\n";
    cout <<"Enter your choice: ";
    cin>>num;
    if(num==1)
        user_section();
    else if(num==2)
        {
            admin_section();
        }
    system("cls");
//write_to_file1();
//read_from_file1();
//srch_by_itemname();
    getch();
}

void splash()
{
    system("CLS");
    gotoXY(1000,1000);
    cout<<"A & G services ";
    getch();
}
void order()
{
    int y;
    cout<<"\n menu";
    cout<<"\n 1.login";
    cout<<"\n 2.add new account";
    cout<<"\n Enter your choice: ";
    cin>>y;
    switch(y)
        {

            case 1:
                signin();
                break;
            case 2:
                signup();
                break;
            case 3:
                exit(0);
            default:
                cout<<"\n wrong input"<<endl;
        }
    

    getch();
    system("CLS");
    cout<<"\t\t\twelcome to the world of food\n \n\n\n\n";
    read_from_file();
    getch();
    system("cls");
    int ch1;
    int restcode;
    cout<<"enter the way you want to search the restaurent:";
    cout<<"\n 1. Location wise";
    cout<<"\n 2. Name wise ";
    cout<<"\n Enter ur choice of search: ";

    cin>>ch1;
    if(ch1==1)

        {

            srch_by_loc();
            //getch();
            cout<<"\nEnter restaurant code ";
            fflush(stdin);
            cin>>restcode;
            int i=order_food(restcode);
        }
    else if(ch1==2)
        {
            srch_by_rname();
            cout<<"\nEnter restaurant code ";
            fflush(stdin);
            cin>>restcode;
            int i=order_food(restcode);
        }
    //bill=order_food(rcode);
}



/*	3. select restaurant from list and enter rest code
	4. on the basis of code show restaurant details
	5. ask itemcode and qty to order from that restaurant
	6. calculate total amount
	7. generate text file with name as custcode.txt
	app | out
	8. write data to text file (bill) or
	generate binary file with code , date and total bill
	9. future scope that we can find total order by customer*/




int order_food(int restcode)
{
    ifstream fin("restin.dat",ios::binary);
    restaurent r1;
    int found=0;

    while(fin.read((char*)&r1,sizeof(r1)))
        {
            if(r1.ret_rcode()==restcode)
                {

                    srch_by_cuisine(r1.ret_cuisicode());

                    found=1;
                    break;
                }
        }
    fin.close();
    if(!found)
        {
            cout<<"restaurant not found";
            getch();
        }
}
//while(read rest file)

//srch rcode
//if found

//then display cusine name
// pass cusine code in int srch_cusine(int code)
// inc rankcount by 1


// close file
// call update rank func(rcode)

int srch_by_cuisine(int code)
{

    ifstream fin("cusi.dat",ios::binary);
    cuisine c1;
    char ch;
    int icode,found=0;

    while(fin.read((char*)&c1,sizeof(c1)))
        {
            if(code==c1.ret_ccode())
                {

                    found=1;
                    c1.putcuisi();
                    
                    //break;
                }
        }
        cout<<"itemcode:";
                    cin>>icode;
                    srch_by_itemcode(icode);

    fin.close();
    if(!found)
        {
            cout<<"restaurant not found";
            getch();
        }
}

/*int srch_item(int code)
{
	// open read mode
	int qty, amt=0;
	while(read cusine file)
	{
		if find cusine
		{
			cout ffod item name
			cout price
			do u want to order this
			if ans y
			ask qty
			amt = amt+ qty*price;
			cusine_count by 1
		}
	}
	return amt;
	close the file
	call update cusine func(code)

}
void update_cusine(int c)
{
	//in out
	while (read)
	{
		check code
		call inc func
		go back
		write
		break

	}
}*/
