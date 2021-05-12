#include <iostream>
#include <fstream>

using namespace std;
bool flag=0;

void Createfile(){
	
	fstream UserNameFile("UserId.txt");
	fstream NextlineFile("nextline.txt");
	
	if(!UserNameFile.is_open()){
		ofstream newfile;
		newfile.open("UserId.txt");
	}
	
	if(!NextlineFile.is_open()){
		ofstream newfile;
		newfile.open("nextline.txt");
		newfile<<0;
	}
	
	UserNameFile.close();
	NextlineFile.close();
}


void Register(){
	
	Createfile();
	
	fstream UserNameFile("UserId.txt");
	fstream NextlineFile("nextline.txt");
	
	int line;
	NextlineFile>>line;
	UserNameFile.seekg(line);
	
	string UserName;
	cout<<"Enter username:";
	cin>>UserName;
	UserNameFile<<UserName;
	
	UserNameFile<<' ';
	
	string Password;
	cout<<"Enter password:";
	cin>>Password;
	UserNameFile<<Password;
	UserNameFile<<endl;
	
	NextlineFile.seekg(0);
	NextlineFile<<UserNameFile.tellg();
	
	UserNameFile.close();
	NextlineFile.close();
}


void Login(){
	Createfile();
	fstream UserNameFile("UserId.txt");
	string UserName;
	cout<<"Enter username:";
	cin>>UserName;
	
	string id,pass;
	flag=0;
	while(!UserNameFile.eof()){
		UserNameFile>>id>>pass;
		if(id==UserName){
			flag=1;
			break;
		}
		if(flag){
			break;
		}
	}
	if(flag){
		string Password;
		cout<<"Enter password:";
		cin>>Password;
		
		if(Password==pass){
			cout<<"welcome "<<UserName<<endl;
		}
		else{
			cout<<"Wrong Password"<<endl;
		}
	}
	else{
		cout<<"Username "<<UserName<<" is not Registered"<<endl;
	}
}


void Help(){
	cout<<"-----------------------------------------------"<<endl;
	cout<<"1. Register	: Press 1 to register"<<endl;
	cout<<"2. Login	: Press 1 to login into system"<<endl;
	cout<<"3. Help		: Press 3 to get help"<<endl;
	cout<<"4. Exit		: Press 4 to exit"<<endl;
	cout<<"-----------------------------------------------"<<endl<<endl;
}



int main(){
	Help();
	string input;
	while(true){
		
		cout<<"User$:";
		cin>>input;
		
		if(input=="1"){
			Register();
		}
		else if(input=="2"){
			Login();
		}
		else if(input=="3"){
			Help();
		}
		else if(input=="4"){
			break;
		}
		else{
			cout<<"Invalid input"<<endl;
		}
		cout<<endl;
	}
}
