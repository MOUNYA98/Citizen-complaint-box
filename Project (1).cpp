#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
#include <iomanip>

using namespace std;

void show_notice();

class CSVRow
{
    public:
        const string & operator[](int index) const
        {
            return m_data[index];
        }
        void readNextRow(istream& str)
        {
            string         line;
            getline(str, line);

            stringstream   lineStream(line);
            string         cell;

            m_data.clear();
            while(getline(lineStream, cell, ','))
            {
                m_data.push_back(cell);
            }
        }
    private:
        vector<string>    m_data;
};

istream& operator >>(istream& str, CSVRow& data)
{
    data.readNextRow(str);
    return str;
}

class Registration
{
public:
	string first_name,last_name,locality,city,district,contact,name;
	string email,username,password;
	static string new_id;

//Constructor of this class
	
	Registration()
	{
	}

	Registration(string &s)
	{
		new_id = s;
	}

//Functions of this class

	void display_Details(string &);
	bool account_Existence(string &,string &);
	bool account_Existence(string &);
	bool account_Existence(string &,int );
	//int findLastFile();
	int findLastFile(string );
	void menu(); //show the menu
	void return_to_menu();
	
};

string Registration::new_id;

void Registration::return_to_menu()
{
	char ch;
	save:
	try
	{
		cout << "\n Press S to continue." ;
		cin >> ch;

		if(!cin)
		{
			cin.clear();
			cin.ignore(100,'\n');
			throw 1000;
		}
		if(ch=='s'||ch=='S')
		{
			menu();
		}
		else
		{
			throw 100;
		}
	}
	catch(int a)
	{
		cout <<"Invalid input" << endl;
		cin.ignore(100,'\n');
		goto save;
	}
}

bool Registration::account_Existence(string& username,string& email)
{
	ifstream ifs;
	ifs.open("Registration.csv",ios::in);
	
	CSVRow row;
	
	int counter=0,j=0;
	bool status=false;	

	while(ifs >> row)
	{
		counter++;
		if(counter == 1)
		{
			while(row[j++] !="CustomerId")  //Traversing till the last column
			{
			}
		}
		else
		{
			if(row[j-3]==username || row[j-4]==email)  //checking the existence
			{
				status = true;
				break;
			}
		}	
	}
	return status;	
}

bool Registration::account_Existence(string& username)
{
	ifstream ifs;
	ifs.open("Registration.csv",ios::in);
	
	CSVRow row;
	
	int counter=0,j=0;
	bool status=false;	

	while(ifs >> row)
	{
		counter++;
		if(counter == 1)
		{
			while(row[j++] !="CustomerId")  //Traversing till the last column
			{
			}
		}
		else
		{
			if(row[j-3]==username)  //checking the existence of username
			{
				status = true;
				break;
			}
		}	
	}
	return status;	
}

bool Registration::account_Existence(string& email,int a)
{
	ifstream ifs;
	ifs.open("Registration.csv",ios::in);
	
	CSVRow row;
	
	int counter=0,j=0;
	bool status=false;	

	while(ifs >> row)
	{
		counter++;
		if(counter == 1)
		{
			while(row[j++] !="CustomerId")  //Traversing till the last column
			{
			}
		}
		else
		{
			if(row[j-4]==email)  //checking the existence of username
			{
				status = true;
				break;
			}
		}	
	}
	return status;	
}

//Operator overloading to add string object with an integer

string  operator + (string &s,int i)
{
	int t = stoi(s);
	
	t+=i;
	string s4=to_string(t);

	return s4;
}

int Registration::findLastFile(string file)
{
	ifstream ifs;
	ifs.open(file,ios::in);
	
	CSVRow row;
	int count=0;
	
	while( ifs >> row)
	{
		count++;
	}
	ifs.close();
	return count;
}     

void Registration::display_Details(string &st)
{
	ifstream ifs;
	CSVRow row;
	int counter=0,j=0;
	ifs.open("Registration.csv",ios::in);

	cout << "Displaying your details:" << endl;
	while(ifs >> row)
	{
		counter++;
		if(counter == 1)
		{
			while(row[j++] !="CustomerId")
			{
			}
		}
		else
		{
			if(row[j-1]==st)
			{
				cout <<"Name:"<< row[j-9] << endl;
				cout <<"Locality:"<< row[j-8] << endl;
				cout <<"City:"<< row[j-7] << endl;
				cout <<"District:" << row[j-6] << endl;
				cout <<"Contact:" << row[j-5] << endl;
				cout <<"Email:" << row[j-4] << endl;
				cout <<"UserName:" << row[j-3] << endl;
				//cout <<"Password:" << row[j-2] << endl;
				cout <<"Customer Id:" << row[j-1] << endl;
			}
		}	
	}
	ifs.close();
	
	char ch;
	cin.ignore();
	
	return_to_menu();
} 

class Complaint:public Registration
{
public:
	static string username,password,customerid;
	static string name_of_user,email_of_user,locality,city,district,contact;
	static int position ;
	string problem,status,comment,prob_id;

	Complaint()
	{
	}

//Functions of this class
	void send();
	void Login();
	void change_password();
	void post_complaint();
	void add_Details();
	void check_status();
	string find_District();
	void update_profile();
};

string Complaint::username;
string Complaint::contact;
string Complaint::password;
string Complaint::customerid;
string Complaint::name_of_user;
string Complaint::email_of_user;
string Complaint::locality;
string Complaint::city;
string Complaint::district;
int Complaint::position;

void Complaint::send()
{
	Registration rg(customerid);
}

void Complaint::change_password()
{
	string name,id,pass;

	bool stats=false;
	int counter=0,j=0;
	m:
	cout << "\nYour user_name:";
	cin >> name;
	cout << "\nCustomer Id:";
	cin >> id;
		
	cout << "\nNew Password:";
	cin >> pass;
	
	ifstream ifs;
	ifs.open("Registration.csv",ios::in);

	ofstream ofs;
	ofs.open("test.csv",ios::out);

	CSVRow row;

	while(ifs >> row)
	{
		counter++;
		if(counter ==1)
		{
			while(row[j++]!="CustomerId")
			{
			}
			for(int i=0;i<9;i++)
			{
				ofs << row[i] << "," ;
			}
			ofs << endl;
		}
		else
		{
			if(row[j-1]==id && row[j-3]==name)
			{
				for(int i=0;i<7;i++)
				{
					ofs << row[i] << ",";
				}
				ofs << pass << "," << row[8] << endl;
				stats=true;
			}
			else
			{
				for(int i=0;i<9;i++)
				{
					ofs << row[i] << ",";
				}
				ofs << endl;
			}
		}	
	}
	ifs.close();
	ofs.close();
	
	if(!stats)
	{
		cout << "\nInvalid Details!!";
		goto m;
	}

	int num=remove("Registration.csv");
	int a=rename("test.csv","Registration.csv");
	//cout << "a=" << a << endl;
 
	cout << "\nUpdating..." << endl;
	//sleep(5);
	
	if(a==0)	
		cout << "Password Changed Successfully" << endl;
	else
		cout << "Try again." << endl;
	
	cout << "\n Login to continue" << endl;
	Login();	
}

string Complaint::find_District()
{
	ifstream ifs;
	ifs.open("Registration.csv",ios::in);

	CSVRow row;
	int counter=0,j=0;
	
	while(ifs >> row)
	{
		counter++;
		if(counter==1)
		{
			while(row[j++]!="CustomerId")
			{
			}
		}
		else
		{
			if(row[j-3]==username)
			{
				district = row[j-6];
				break;
			}
		}
	}
	ifs.close();
	return district;
}

void Complaint::add_Details()
{
	char local[100];
	memset(local,0,100);

	cout << "\nEnter your first name:";
	cin >> first_name;

	cin.ignore(100,'\n');

	cout << "\nEnter your last name:";
	cin >> last_name;
	
	string name = first_name + " " +last_name;

	cin.ignore(10,'\n');
	
	lo:
	cout << "\nEnter your locality(Please avoid use of comma(,)):";
	cin.getline(local,100);

	for(int i=0;i<=strlen(local);i++)
	{
		if(local[i]==',')
		{
			cout << "\n Invalid locality!!!" << endl;
			goto lo;
		}
	}
	string locality = local;
	
	cout << "\n Enter your city:";
	cin >> city;
	
	cout << "\nEnter your district:";
	cin >> district;
	
	a:
	cout << "\nEnter your contact number:";
	cin >> contact;

	if(contact.length()!=10)
	{
		cout << "Invalid Contact Detail." << endl;
		cout << "Enter your details again." << endl;
		goto a;
	}

	em:
	cout << "\nEnter Email-Id:";
	cin >> email;

	cout << "\nEnter your username:";
	cin >> username;

	cout << "\nEnter your password:";
	cin >> password;

	string new_id;

	bool check = account_Existence(username,email); //Checking the existence of account

	if(check)
	{
		cout << "Email-id or user name already exists." << endl;
		cout << "Please enter your contact details again"<< endl;
		//sleep(3);
		cout << "\n\n";
		goto em;
		//add_Details();
	}
	else
	{
		string test;
		ifstream file;
		CSVRow row;
	
		int row_counter= findLastFile("Registration.csv");//It counts the number of rows present in the file
		int column_counter=0,c=0,k=0;
		string id;
	
		file.open("Registration.csv",ios::in);

		while(file >> row )
		{
			c++;
			if(c==1)
			{
				while(row[column_counter++] != "CustomerId")
				{
				}
			}
			else if(c == row_counter)
			{
				id = row[column_counter-1];  //Hold the previous id
			}
			
		}
	
		//Preapring to generate the new Id

		if(row_counter==1)
		{
			new_id="100cst";
			cout << "Your id:"<< new_id << endl;
		}
		else
		{
			int len = id.length();
			len = len -3;
			
			string str=id.substr(0,len);//Finding the substring of the string containing only the int part
			
			new_id = str + 1;//Operator + is overloaded which add string with integer
			
			const string ss = "cst";
			new_id = new_id + ss;  //string concatenation so that we can get our actual format
			
			cout << "Your id:" << new_id << endl;	//new id is generated	
		}	
					
			file.close();
	//writing data into the file	
	
	//cout << "Id:"<< new_id << endl;

	ofstream ofs;
	ofs.open("Registration.csv",ios::app);
	ofs << name <<"," << locality << "," << city << ","<< district <<","<< contact <<"," << email <<","<< username <<"," ;           
        ofs << password <<"," << new_id << endl;
	
	//cout << "Id:" << new_id << endl;
	customerid = new_id;
	//cout << "CustomerId:" << customerid << endl;
	ofs.close();
	cout<<"Successful account creation"<<endl;
	
	}
	  send();  //Trying to pass the customerid to Registration class
	  
	  cout << "\n\nPlease Login again to use our service." << endl ;
	  //sleep(5);
	  Login();

}


void Complaint::Login()
{
	cout << "\n Enter your details to login" << endl;

	cout << "\nEnter your username:";
	cin >> username;
	cout << "\nEnter your password:";
	cin >> password;
	cout << "\nEnter your customerid:";
	cin >> customerid;
	
	ifstream ifs;
	ifs.open("Registration.csv",ios::in);
	
	CSVRow row;
	int counter=0,j=0;
	bool status=false;
	
	while(ifs >> row)
	{
		counter++;
		//cout << "counter=" << counter << endl;
		if(counter==1)
		{
			while(row[j++]!="CustomerId")
			{
			}
		}
		else
		{
			if(row[j-1]==customerid && row[j-2]==password && row[j-3]==username)
			{
				position = counter;
				name_of_user=row[j-9];
				email_of_user=row[j-4];
				status=true;
				break;
			}
		}
	}
	ifs.close();
	
	send();     //Trying to send customer id to the Registration class
	
	if(status)
	{
		menu();
	}
	else
	{
		cout <<"\n Invalid entry.Try again."<< endl;
		//cout <<"\n Preparing to take input again." << endl;
		//sleep(5);
		Login();
	}
	//return status;
}

void Complaint::update_profile()
{
	//int k = account_Existence();	
	
	bool check=false;
	cout << "Enter your details again to update your profile." << endl;
	
        cout << "\nEnter your first name:";
	cin >> first_name;

	cin.ignore(100,'\n');

	cout << "\nEnter your last name:";
	cin >> last_name;
	
	string name = first_name + " " +last_name;
	name_of_user = name;
	
	cout << "\nEnter your locality(Please avoid use of comma(,)):";
	cin >> locality;
	
	cout << "\n Enter your city:";
	cin >> city;
	
	cout << "\nEnter your district:";
	cin >> district;
	
	co:
	cout << "\nEnter your contact number:";
	cin >> contact;

	if(contact.length()!=10)
	{
		cout << "Invalid Contact Detail." << endl;
		cout << "Enter your contact number again." << endl;
		goto co;
	}

	e:
	cout << "\nEnter Email-Id:";
	cin >> email;

	string temp = email_of_user;
	string temp_username = username;

	email_of_user = email;

	cout << "\nEnter your username:";
	cin >> username;

	cout << "\nEnter your password:";
	cin >> password;

	if(temp == email_of_user && temp_username == username)
	{
	}
	else if(temp == email_of_user && temp_username!=username)
	{
		check = account_Existence(username);
	}
	else if(temp_username == username && temp!=email_of_user)
	{
		check = account_Existence(email_of_user,10);
	}
	else
	{
		check = account_Existence(username,email); //Checking the existence of account
	}
	if(check)
	{
		cout << "Email-id or user name already exists." << endl;
		cout << "Enter your details again."<< endl;
		cout << "\n\n";
		goto e;
	}
	
	int counter=0;
	
	CSVRow row;
		
	ifstream ifs;
	ifs.open("Registration.csv",ios::in);
	
	ofstream ofs;
	ofs.open("test.csv",ios::out);
	
	while(ifs >> row)
	{
		counter++;
		if(counter == position)
		{
			ofs << name << ","<< locality <<"," << city << "," << district << "," << contact << "," << email << "," << username <<"," << password << "," << customerid << endl;
		}
		else
		{
			for(int i=0;i<8;i++)
			{
				ofs << row[i] <<",";
			}
			ofs << row[8] << endl;
			//ofs << row[0] <<"," << row[1] <<"," << row[2] <<"," << row[3] << "," << row[4] <<endl;
		}
	}
	
	//cout << "New file created." << endl;
	ifs.close();
	ofs.close();

	int num=remove("Registration.csv");
	int a=rename("test.csv","Registration.csv");
	//cout << "a=" << a << endl;
 
	cout << "\nUpdating..." << endl;
	//sleep(5);
	
	if(a==0)	
		cout << "Successfully updated" << endl;
	else
		cout << "Try again." << endl;
	
	return_to_menu();
}

void Complaint::post_complaint()
{
	cin.ignore(); //To avoid anything present in the buffer specially to remove new line characters as getline will take the new line & terminate the statement 
	int i=0,j=0,counter=0;

	int k=findLastFile("complaint.csv");
	
	district = find_District();

	//cout << "k=" << k << endl;	
	string id;

	char message[1000],ch;
	memset(message,0,1000);  //To avoid garbage value

	cout << "\nProblem(Complete Description):";
	cin.getline(message,1000);
	
	while(message[i]!='\0')
	{
		if(message[i] ==',')
		{
			message[i]=';';
		}
		i++;
	}
	
	problem = message;
	//cout << problem << endl;
	
	ifstream ifs;
	ifs.open("complaint.csv",ios::in);
   	CSVRow row;

//Getting the last problem id;

	while(ifs >> row)
	{
		counter++;
		if(counter==1)
		{
			while(row[j++]!="Comment")
			{
			}
		}
		else if(counter==k)
		{
			id =row[j-4];	
		}
	}
	ifs.close();
	
	//cout << "id" << id << endl;
	//Preapring to generate the new Id

		if(counter==1)
		{
			prob_id="100prob";
			cout << "Problem id:"<< prob_id << endl;
		}
		else
		{
			int len = id.length();
			//cout << len << endl;
			len = len -4;
			
			string str=id.substr(0,len);//Finding the substring of the string containing only the int part
			//cout << str << endl;			
			
			prob_id = str + 1;//Operator + is overloaded which add string with integer
			
			const string ss = "prob";
			prob_id = prob_id + ss;  //string concatenation so that we can get our actual format
			
			cout << "Problem id:" << prob_id << endl;	//new id is generated	
		}	
					
	status="pending";
	
	pr:
	cout << "Any Suggestions(Press 1 to post suggestion or Press 2 to register complain):";
	int choice;
	cin >> choice;

	if(!cin)
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\n Invalid Entry!!" << endl;
		goto pr;
	}

	char com[1000];
	memset(com,0,1000);
	
	if(choice ==1)
	{
		cin.ignore();
		cout << "Your Suggestion:" ;
		cin.getline(com,1000);
		int i=0;
		while(com[i]!='\0')
		{
			if(com[i]==',')
			{
				com[i]=';';
			}
			i++;
		}

		comment = com;
	}
	
	else if(choice ==2)
	{
		comment = "No comment";
	}
//writing into the file

	ofstream ofs;
	ofs.open("complaint.csv",ios::app);
	
	ofs << district<<"," << username << "," << customerid << "," << prob_id << "," << problem << "," << status <<"," << comment << endl;
	
	ofs.close();
	cout <<"Complaint registered successfully." << endl;

	return_to_menu();	
				
}

void Complaint::check_status()
{
	ifstream ifs;
	ifs.open("complaint.csv",ios::in);
	
	bool stat=false;
	CSVRow row;
	//cout << customerid <<"\t" << username << endl;
	
	int j=0,count=0;; 

	while(ifs >> row)
	{
		count++;
		if(count==1)
		{
			while(row[j++]!="Comment")
			{
			}
		}
		//cout << j << endl;
		if(row[j-5]==customerid && row[j-6]==username)
		{
			stat=true;
			cout << "Problem id:"<< row[j-4] << endl;
			cout << "Problem:" << row[j-3] << endl;
			cout << "status:" << row[j-2] << endl;
			cout << endl;
		}
	}
	ifs.close();
	//cout << stat << endl;
	if(!stat)
	{
		cout << "\n You have not registered any complaint yet." << endl;
	}
	return_to_menu();
}

void Registration::menu()
{
	cin.ignore(100,'\n');

	z:
	cout << "\n\t\t\t Welcome to the Public Works Department,Odisha" << endl;
	cout << "\n\t\t 1.Post complaint" << endl;
	cout << "\n\t\t 2.Check status of complaint" << endl;
	cout << "\n\t\t 3.My Profile" << endl;
	cout << "\n\t\t 4.Update your profile" << endl;
	cout << "\n\t\t 5.Logout" << endl;

	int choice;
	cout << "Your Choice:";
	cin >> choice ;
	
	if(!cin)
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\n Enter valid input." << endl;
		goto z;
	}
	
	if(choice ==1)
	{
		Complaint cp;
		cp.post_complaint();
	}
	else if(choice == 2)
	{
		Complaint cp;
		cp.check_status();
	}
	else if(choice ==3)
	{
		Registration rg;
		rg.display_Details(new_id);
	}
	else if(choice ==4)
	{
		Complaint cp;
		cp.update_profile();
	}
	else if(choice ==5)	
	{
		cout << "\n Thank you for using our service." << endl;
		exit(0);
	}
	else
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\nEnter valid details." << endl;
		goto z;
	}
      
}


class Admin
{
public:
	string username,admin_id,password;
	
	void login();
	void menu();
	void check_problems();
	void check_problems(string);
	void view_problem();
	void view_problem(int);
	void update_status();
	void show_UserProfile();
	string last_problem();
	int problem_Existence();
	void returnToAdminMenu();
	void add_notice();
};

void Admin::returnToAdminMenu()
{
	char ch;
	adm:
	try
	{
		cout << "\n Press S to continue or Q to quit." ;
		cin >> ch;

		if(!cin)
		{
			cin.clear();
			cin.ignore(100,'\n');
			throw 1000;
		}
		
		if(ch == 'S' || ch =='s')
		{
			menu();
		}
		else if(ch == 'Q' || ch =='q')
		{
			cout << "\n Thank you for using our service." << endl;
			exit(0);
		}
		else
		{
			throw 100;
		}
	}
	catch(int a)
	{
		cout <<"Invalid input" << endl;
		cin.ignore(100,'\n');
		goto adm;
	}
}

void Admin::add_notice()
{
	char note[1000];
	memset(note,0,1000);
	
	cout << "\nNotice:" << endl;
	cin.ignore();
	cin.getline(note,1000);

	string notice = note;
	
	ofstream ofs;
	ofs.open("Notice.csv",ios::app);

	ofs << __DATE__ << "," << notice << endl;
	
	ofs.close();
	cout << "\n New notice added." << endl;
	
	returnToAdminMenu();	
}

void Admin::login()
{
	cout << "\nUserName:";
	cin >> username;
	cout << "\nPassword:";
	cin >> password;
	cout << "\nAdmin Id:";
	cin >> admin_id;

	int count=0,j=0;
	bool status=false;

	CSVRow row;
	ifstream ifs;
	ifs.open("admin.csv",ios::in);
	
	while(ifs >> row)
	{
		count++;
		if(count ==1)
		{
			while(row[j++]!="AdminId")
			{
			}
		}
		if(row[j-3]==username && row[j-2]==password && row[j-1]==admin_id)
		{
			status=true;
			break;
		}
	}

	ifs.close();

	if(status)
	{
		cout << "Successfully logged in." << endl;
		menu();
	}
	else
	{
		cout <<"\nInvalid details"<< endl;
		ad:
		cout <<"\nPress 1 to give details again or Press 2 to quit" << endl;
		int ch;
		cout << "Choice:" ;
		cin >> ch;
		if(!cin)
		{
			cout << "\nInvalid entry!!!" << endl;
			cin.clear();
			cin.ignore(100,'\n');
			goto ad;
		}
		if(ch==1)
		{
			login();
		}		
		else if(ch==2)
		{
			exit(0);
		}
		else
		{
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\n Invalid Entry!!!" << endl;
			goto ad;
		}
	}
}
int Admin::problem_Existence()
{
	ifstream ifs;

	ifs.open("complaint.csv",ios::in);
	
	CSVRow row;
	int counter=0,i=0,j=0;
	bool stat=false;
	
	while(ifs >> row)
	{
		counter++;
	}
	
	ifs.close();
	if(counter==1)
		return 1;
	else
		return 2;
}
string Admin::last_problem()
{
	ifstream ifs;

	ifs.open("complaint.csv",ios::in);
	
	CSVRow row;
	int counter=0,i=0,j=0;
	string problem_id;
	
	while(ifs >> row)
	{
		counter++;
	}
	
	ifs.close();
	
	ifs.open("complaint.csv",ios::in);
	
	while(ifs >> row)
	{
		i++;
		if(i==1)
		{
			while(row[j++] !="Comment")
			{
			}
		}
		else if(i==counter)
		{
			problem_id = row[j-4];
		}
		
	}

	ifs.close();
	return problem_id;
}

void Admin::view_problem()
{
	int counter=0,j=0;
	bool stat=false;
	ifstream ifs;
	ifs.open("complaint.csv",ios::in);

	CSVRow row;
	
	while(ifs >> row)
	{
		counter++;
		if(counter==1)
		{
			while(row[j++]!="Comment")
			{
			}
		}
		else
		{
			if(row[j-2]=="Completed")
			{
				stat=true;
				cout << row[j-4] << ":" << row[j-3] << endl;
			}
			//cout << endl;
		}	
	}
	ifs.close();
	if(!stat)
	{
		cout << "\n No completed works." << endl;
	}
}

void Admin::view_problem(int a)
{
	int counter=0,j=0;
	bool stat=false;
	
	ifstream ifs;
	ifs.open("complaint.csv",ios::in);

	CSVRow row;
	
	while(ifs >> row)
	{
		counter++;
		if(counter==1)
		{
			while(row[j++]!="Comment")
			{
			}
		}
		else
		{
			if(row[j-2]=="pending")
			{
				stat=true;
				cout << row[j-4] << ":" << row[j-3] << endl;
			}
			//cout << endl;
		}	
	}
	ifs.close();
	if(!stat)
	{
		cout << "\n No pending works." << endl;
	}
}

void Admin::update_status()
{
	bool stat=false;
		
	int p = problem_Existence();
	if(p==1)
	{
		cout << "\n Currently no problems available to update status." << endl;
		returnToAdminMenu(); 
	}
	
	cout << "First problem id: 100prob"<< endl;

	string last_id= last_problem() ;
	
	cout << "Last problem id:" << last_id << endl;
	
	pm:
	cin.clear();
	cin.ignore(1000,'\n');
	cout << "\nEnter C to see the completed works & P to see the pending works:";
	char ch;
	cin >> ch;
		
	if(!cin)	
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\n Invalid Entry!!!" << endl;
		goto pm;
	}
	
	else if(ch=='C'||ch=='c')
	{
		view_problem();
	}
	
	else if(ch=='P'||ch=='p')
	{
		view_problem(10);
	}
	
	else
	{
		cout << "\nInvalid Entry!!!" << endl;
		goto pm;	
	}
	
	pn:
	cout << "\nEnter the problem id to view & change it's status:";
	
	string problem_id;
	
	cin >> problem_id;

	check_problems(problem_id);
	
	const string status="Completed";
	int count=0,j=0;

	CSVRow row;
	
	ifstream ifs;
	ifs.open("complaint.csv",ios::in);

	ofstream ofs;
	ofs.open("temporary.csv",ios::out);
	
	while(ifs >> row)
	{
		count++;
		if(count==1)
		{
			while(row[j++] !="Comment")
			{
			}
		        for(int k=0;k<7;k++)
			{
				ofs << row[k] << "," ;
			}
			ofs << endl;
			
		}
		else 
		{
		  if(row[j-4]==problem_id)
		   {
		        stat=true;
			ofs << row[j-7] <<"," << row[j-6] << "," << row[j-5] <<	"," << row[j-4] << "," << row[j-3] << "," << status << "," << 
row[j-1]<< endl;
		   }
		   else
		   {
			for(int k=0;k<7;k++)
			{
				ofs << row[k] << "," ;
			}
			ofs << endl;
		   }		
		}
	}
	ifs.close();
	ofs.close();

	if(!stat)
	{
		cout << "\nNo problem available for this id." << endl;
		goto pn;
	}
	int b=remove("complaint.csv");
	int a= rename("temporary.csv","complaint.csv");	
	if(a==0)
	{
		cout << "Status updated successfully" << endl;
	}
	else
	{
		cout << "Status not updated" << endl;
	}

	returnToAdminMenu();
}

void Admin::show_UserProfile()
{
	ifstream ifs;
	CSVRow row;
	int counter=0,j=0;
	
	string st;
	cout << "\n Enter the customerid to view user details:";
	cin >> st;
	
	cin.ignore();

	ifs.open("Registration.csv",ios::in);
	
	cout << "Displaying User details:" << endl;

	while(ifs >> row)
	{
		counter++;
		if(counter == 1)
		{
			while(row[j++] !="CustomerId")
			{
			}
		}
		else
		{
			if(row[j-1]==st)
			{
				cout <<"Name:"<< row[j-9] << endl;
				cout <<"Locality:"<< row[j-8] << endl;
				cout <<"City:"<< row[j-7] << endl;
				cout <<"District:" << row[j-6] << endl;
				cout <<"Contact:" << row[j-5] << endl;
				cout <<"Email:" << row[j-4] << endl;
				cout <<"UserName:" << row[j-3] << endl;
				cout <<"Password:" << row[j-2] << endl;
				cout <<"Customer Id:" << row[j-1] << endl;
			}
		}	
	}
	ifs.close();
	
	returnToAdminMenu();
}

void Admin::check_problems(string pid)
{
	
	bool stat=false;
	ifstream ifs;
	ifs.open("complaint.csv",ios::in);
	CSVRow row;


	int counter=0,j=0;

	while(ifs >> row)
	{
		counter++;
		if(counter==1)
		{
			while(row[j++]!="Comment")
			{
			}
		}
		else
		{
			if(row[j-4]==pid)
		      {
			stat=true;
			cout <<"Problem id:" << row[j-4] << endl;
			cout <<"Problem:" << row[j-3] << endl;
			cout <<"Status:" << row[j-2] << endl;
			cout <<"Comment:" << row[j-1] << endl; 
		      }
		}
		
		cout << endl;
	}

	ifs.close();
	
	if(!stat)
	{
		cout << "\n Problem not available for this id!!" << endl;
	}

	//returnToAdminMenu();
}

void Admin::check_problems()
{
	int p = problem_Existence();
	if(p==1)
	{
		cout << "\n Currently no problems available." << endl;
		returnToAdminMenu(); 
	}

	ifstream ifs;
	ifs.open("complaint.csv",ios::in);
	CSVRow row;


	int counter=0,j=0;

	while(ifs >> row)
	{
		counter++;
		if(counter==1)
		{
			while(row[j++]!="Comment")
			{
			}
		}
		else
		{
			cout <<"Problem id:" << row[j-4] << endl;
			cout <<"Problem:" << row[j-3] << endl;
			cout <<"Status:" << row[j-2] << endl;
			cout <<"Comment:" << row[j-1] << endl; 
		}
		
		cout << endl;
	}

	ifs.close();

	returnToAdminMenu();
}

void Admin::menu()
{
	cin.ignore(10,'\n');
	am:
	cout << "\n\t\t\t Welcome to the Public Works Department,Odisha" << endl;
	cout << "\n\t\t 1.Check problems" << endl;
	cout << "\n\t\t 2.Update status" << endl;
	cout << "\n\t\t 3.User Profile" << endl;
	cout << "\n\t\t 4.Add Notice" << endl;
	cout << "\n\t\t 5.Logout" << endl;

	int choice;
	cout << "Your Choice:";
	cin >> choice ;

	if(!cin)
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\n Invalid Input!!!" << endl;
		goto am;
	}
	
	if(choice ==1)
	{
		Admin ad;
		ad.check_problems();
	}
	else if(choice == 2)
	{
		Admin ad;
		ad.update_status();
	}
	else if(choice ==3)
	{
		Admin ad;
		ad.show_UserProfile();
	}
	else if(choice ==4)
	{
		Admin ad;
		ad.add_notice();
	}
	else if(choice ==5)	
	{
		cout << "\n Thank you for using our service" << endl;
		exit(0);
	}
	else
	{
		cin.clear();
		cin.ignore(1000,'\n');
		cout << "\nEnter valid details." << endl;
		goto am;
	}
      
}

int main()
{	
	ma:
	int choice,c;
	cout << "\n\t\tWelcome to the Public Works Department,Odisha" << endl;
	cout << "\n\t\t   Enter By logging into your account." << endl;
	cout << "\n\t\t 1.Admin mode \n\t\t 2.User mode \n\t\t 3.Notice \n\t\t 4.Exit" << endl;	
		
	
	try{	
		cout << "Your choice:";
		cin >> choice;
		
		if(!cin)
		{
			cin.clear();
			throw 200;
		}
		if(choice==1)
		{
			cout << "\n\t\tWelcome to the Admin Mode of PWD Department" << endl;
			cout << "\n Login to continue" << endl;
			Admin ad;
			ad.login();
		}
		else if(choice==2)
		{
			p:
			cout << "\n\t\t\tWelcome to the User Mode of PWD Department" << endl;
			cout << "\n\t\t 1.Sign Up \n\t\t 2.LogIn \n\t\t 3.Forgot Password?" << endl;
			cout << "\nYour choice:";
			cin >> c;
				
			if(!cin)
			{
				cin.clear();
				cin.ignore(100,'\n');
				cout << "\n Enter valid entry" << endl;
				goto p;	
			}			
			if(c==1)
			{
				Complaint cp;
				cp.add_Details();
			}
			else if(c==2)
			{
				Complaint cp;
				cp.Login();
			}
			else if(c==3)
			{
				Complaint cp;
				cp.change_password();
			}
			else
			{
				cin.clear();
				cin.ignore(1000,'\n');
				cout << "\n Invalid Input!!" << endl;
				goto p;
			}
		}

		else if(choice ==3)
		{
			show_notice();
		}
		else if(choice==4)
		{
			cout << "\n Thank you for using our service." << endl;
			exit(0);
		}
		else
		{
			//cout << "Please choose the correct option." << endl;
			throw 100;
		}
	    }
	catch(int a)	
	{
		cin.ignore(100,'\n');
		cout << "Please choose the correct option." << endl;
		goto ma;
	}
	return 0;	
}

void show_notice()
{
	ifstream ifs;
	ifs.open("Notice.csv",ios::in);

	CSVRow row;
	int counter=0;
	bool status = true;
	while(ifs >> row)
	{
		//cout << ifs.tellg() << endl;
		counter++;
		if(counter!=0)
		{
			status=false;
			for(int i=0;i<2;i++)
			{
				cout << row[i];
				cout << endl;
			}
		cout << endl;
		}
	}
	//cout << counter << endl;
	ifs.close();
	
	if(status)
	{
		cout << "\nNo notices to show" << endl;
	}
	dh:
	char ch;
	cout << "\n Press S to Continue:" ;
	cin >> ch;
	if(!cin)
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\n Invalid Entry!!" << endl;
		goto dh;
	}
	else if(ch =='s' || ch=='S')
	{
		int p=main();
	}
	else
	{
		cin.clear();
		cin.ignore(100,'\n');
		cout << "\n Invalid Entry!!" << endl;
		goto dh;
	}
}

