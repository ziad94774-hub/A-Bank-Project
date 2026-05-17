                     //(1):
          //  To change the color of the console screen through using this :
                           //HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                      //    SetConsoleTextAttribute(hConsole,color ); 
                      //then you can after write this codes , write the code that you want it to be styled after those code. at the end write 
                      //system(" pause") to stop styling .
                      //you have colors from 0-14[black,blue,green,light blue,red,purple,yellow ,white ,gray,light green,light blue ,light red,
					  // light purple ,light yellow ]
                      
                      //(2):
                      //here through these codes you can change the background of the console screen :
                      //  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                      //    SetConsoleTextAttribute(hConsole,color+(the color of the background*16)); 
                      //The color of the background the same as the colors of the fonts just from(0-7).
                       //system(" pause") to stop styling .
                       //(3)://To change the position pf the cursor (The output):
                           //  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
                             //    COORD coord={15,5};
                        //     SetConsoleCursorPosition(hConsole, coord); 
                               //    std::cout << "Hello, World!" << std::endl;
                                  //system(" pause") to stop styling .
                                  
#include<iostream>
#include<string> 
#include<fstream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<cstdlib>
using namespace std;

const int arraySize=100;
const int maxBank=100;
const int maxTransfers=200;

 struct Remittances
 {
   string recipientName;//The name of the man who receives the money
   string senderName;//The name of the man who sends the money
   string recipientNumber;
   string senderNumber;
   string theAmountOfMoney;
   string transferingNumber;

 };
 Remittances remittance[maxTransfers];
 int transferCount=0;
 


struct Banks{
  string bankname;
  string place;
  string BankAccount;
  string theNameOFTheAccount;
  bool isActive;
  string PhoneNum;
  string uinqueNumber;
};

Banks bank[maxBank];
int bankCount=0;

struct User{
string name;
string password;
string role;
string bankAccount;
string  gender;
bool active;
string phoneNumber;
string fantasticNumber;
};
User user[arraySize];
int userCount=0;


  bool userFoundPreviously(const string &userName){
     for( int i=0;i<userCount;i++){
     if (user[i].name==userName){

             return false;
         }

     }
    	return true;

  }

  void inputBank(){

  string requiredPrefix[4]={"77","78","71","73"};

   if (bankCount >= maxBank) {
        cout << "Sorry you can not add a new bank account!  you have reached the limit" <<maxBank << ").\n";
    }
    cin.ignore();
    cout<<"Enter the bank name "<<endl;
    getline(cin,bank[bankCount].bankname);
    cout<<"Enter the bank place"<<endl;
    getline(cin,bank[bankCount].place);
    cout<<" Enter your bank account"<<endl;
    getline(cin,bank[bankCount].BankAccount);
    cout<<" Enter the name or number of the account"<<endl;
    getline(cin,bank[bankCount].theNameOFTheAccount);
    
     int active;
    do{
      
      cout<<"Enter the status of your activity"<<endl;
       cin>>active;

    }while(active!=0  &&  active!=1);

   bank[bankCount].isActive=active;

    bool validPhone=false;
    string phone;
    
   do{
      cout<<"Enter your phone number"<<endl;
      getline( cin,phone);
     if (phone.length()==9){
     string prefix=phone.substr(0,2);
     if(prefix=="77" || prefix=="73" || prefix=="78" || prefix=="71"){
     validPhone=true;
     bank[bankCount].PhoneNum=phone;
          } 
      }
      if (!validPhone){
     cout<<"Wrong Number! ,The number must be 9 digits and starts with (77/73/78/71)"<<endl;
      }
    }while(!validPhone);
    
      bankCount++; //here we add a new bank account to the array.
	  
	  saveBanks();
    cout<<"The operation was  added succesfully "<<endl;
    cout<<"--------------------------------------"<<endl;
  }

  void saveTransfer(){
   ofstream myFile("transfer.txt");
   if(!myFile){
    cout<<"We could not find or open the file"<<endl;
    return;
   }
   for(int i=0;i<transferCount;i++){
     myFile<<remittance[i].recipientName<<"    "<<remittance[i].senderName<<"    "<<remittance[i].recipientNumber<<"   "<<remittance[i].senderNumber<<"     "<<remittance[i].theAmountOfMoney<<"    "<<remittance[i].transferingNumber<<endl;
   }
 myFile.close();
  }

  void loadTransfer(){
  ifstream myFile("transfer.txt");
    if(!myFile){
     return ;
    }

    while (myFile>>remittance[transferCount].recipientName>>remittance[transferCount].senderName>>remittance[transferCount].recipientNumber>>remittance[transferCount].senderNumber>>remittance[transferCount].theAmountOfMoney>>remittance[transferCount].transferingNumber){
      transferCount++;
       if (transferCount>maxTransfers){
      cout<<"Sorry !,you have reached the limit"<<endl;
     break;
    }
  }
  myFile.close();

}

  void saveBanks(){
   ofstream myFile("bank.txt");
   if(!myFile){
     return;
   }

   for(int i=0;i<bankCount;i++){
     myFile<<bank[i].bankname<<"    "<<bank[i].place<<"   "<<bank[i].PhoneNum<<"   "<<bank[i].theNameOFTheAccount<<"   "<<bank[i].BankAccount<<"   "<<bank[i].isActive<<"   "<<bank[i].uinqueNumber<<endl;

   }
    myFile.close();

  }
  void bankLoad(){
    ifstream myFile("bank.txt");
    if(!myFile){
     return ;
    }

    while (myFile>>bank[bankCount].bankname>>bank[bankCount].place>>bank[bankCount].PhoneNum>>bank[bankCount].theNameOFTheAccount>>bank[bankCount].BankAccount>>bank[bankCount].isActive>>bank[bankCount].uinqueNumber)
    {
       bankCount++;
       if(bankCount>maxBank)break;
    }
    
   myFile.close();
  }

 
 void loadUser(){
   ifstream myFile("user.txt");
  
        if(!myFile){

       return;
       }
       
   while (myFile>>user[userCount].name>>user[userCount].password>>user[userCount].role>>user[userCount].gender>>user[userCount].bankAccount>>user[userCount].active>>user[userCount].phoneNumber>>user[userCount].fantasticNumber)
   {
       userCount++;
        if(userCount>=arraySize) break;
   }
   cout<<"The download for the "<<userCount<<" Users is done"<<endl;
    myFile.close();
   }
   

   
   void saveUser(){
   ofstream myFile("user.txt");
     if(!myFile){
    cerr<<"The File Could Not Opened "<<endl;
      exit(EXIT_FAILURE); 
     }
  
      for(int i=0;i<userCount;i++){
      myFile<<"  "<<user[i].name<<"   "<<user[i].password<<"    "<<user[i].role<<"  "<<user[i].gender<<"  "<<user[i].bankAccount<<"  "<<user[i].active<<"  "<<user[i].phoneNumber<<"  "<<user[i].fantasticNumber<<endl;
    }
 
    myFile.close();
   }

    void inputUser(){
      
  	string requiredPrefix[4]={"77","78","71","73"};

   if (userCount >= arraySize) {
        cout << "Sorry you can not add a new user you have reached the limit  " << arraySize << ").\n";
    }
    cin.ignore();

    cout<<"Enter your name"<<endl;
    getline(cin,user[userCount].name);
  
    cout<<"Enter your password"<<endl;
     getline(cin,user[userCount].password);
     //specifing the type  of the  user.
     
    do {
      
    	   cout<<"Enter the type of the user(client/employee/admin)."<<endl;
    	   getline(cin,user[userCount].role);
    	
	   }while(user[userCount].role!="client" &&  user[userCount].role!="employee" && user[userCount].role!="admin");
     
    cout<<"Enter your gender"<<endl;
    getline(cin,user[userCount].gender);

    bool validPhone=false;
    string phone;
    
    do{


      cout<<"Enter your phone number"<<endl;
      getline( cin,phone);
     if (phone.length()==9){
     string prefix=phone.substr(0,2);
     if(prefix=="77" || prefix=="73" || prefix=="78" || prefix=="71"){
     validPhone=true;
     user[userCount].phoneNumber=phone;

     } 

      }
      if (!validPhone){

     cout<<"Wrong Number! ,The number must be 9 digits and starts with (77/73/78/71)"<<endl;
      }

    }while(!validPhone);
     
    int active;
    do{
      
      cout<<"Enter the status of your activity"<<endl;
       cin>>active;
       cin.ignore();
    }while(active!=0  &&  active!=1);

    user[userCount].active=active;

     cout<<" Enter your bank account"<<endl;
     getline(cin,user[userCount].bankAccount);


      userCount++;//here we add a new book to the array.
	  
	  saveUser();
    cout<<"The operation was  added succesfully "<<endl;
    cout<<"--------------------------------------"<<endl;
  }
  void showBankAccount(){//Showing  the account of the client .

    string name;
    string password;
    bool flag=false;
    cout<<"Please Enter the name"<<endl;
    getline( cin,name);
     cout<<"Please Enter the password"<<endl;
    getline( cin,password);
   for(int i=0;i<userCount;i++){
    if(name==user[i].name && password==user[i].password){
        flag=true;

        cout<<"The bank account for the client "
            <<user[i].name<<" : "
            <<user[i].bankAccount<<endl;
        break;
    }
}

if(!flag){
    cout<<"There is no bank account with this name and password"<<endl;
}

  }
   void addMoneyToBank(){
     string phoneNumber;
     string accountName;
     cout<<"Phone number:"<<endl;
     getline(cin,phoneNumber);
     cout<<"The  bank account"<<endl;
     getline(cin,accountName);

     for( int i=0;i<bankCount;i++){
        if(bank[i].PhoneNum==phoneNumber && bank[i].theNameOFTheAccount==accountName){
          if(!bank[i].isActive){
             cout<<"The bank  account is stopped"<<endl;
             return;
          }

          string uniNumber;
          cout<<"Enter the number of the tranferring "<<endl;
          getline(cin,uniNumber);
          if (bank[i].uinqueNumber!=uniNumber ){

           string addingMoney;
           cout<<"Enter the amount of the money"<<endl;
           getline(cin,addingMoney);
           bank[i].BankAccount+=addingMoney;
          bank[i].uinqueNumber=uniNumber;
           saveBanks();
            cout<<"The operation was successfully completed"<<endl;
          }
          else{

            cout<<"This number is entered previously"<<endl;
          }
          
        }
     }
     
   cout<<"Sorry we could not find the bank account"<<endl;

   }


    void addMoneyToYourAccount(){
     string userName;
     string password;
     cout<<"Enter Your Name"<<endl;
     getline (cin,userName);
     cout<<"Enter YourPassword"<<endl;
     getline (cin,password);
     for (int  i = 0; i <userCount; i++)
     {
      if (userName==user[i].name &&  password==user[i].password)
      {
        string amount;
        cout<<"Enter the amount of the money"<<endl;
        cin>>amount;
        user[i].bankAccount+=amount;
        cout<<"The name :"<<user[i].name<<"Your account is :"<<user[i].bankAccount<<endl;
       saveUser();
      }
      
     }
     cout<<"Sorry we could not find your account"<<endl;

    }
    void addMoneyToSomeOne(){
     cout<<"Enter the name of the receiver"<<endl;
     getline(cin,remittance[transferCount].recipientName);
      cout<<"Enter the phone number of the receiver"<<endl;
     getline(cin,remittance[transferCount].recipientNumber);
      cout<<"Enter the name of the sender"<<endl;
     getline(cin,remittance[transferCount].senderName);
      cout<<"Enter the phone number of the sender"<<endl;
     getline(cin,remittance[transferCount].senderNumber);
     cout<<"Enter the amount of the mouney"<<endl;
     getline(cin,remittance[transferCount].theAmountOfMoney);

     string name1;
     bool flag;
     do{
       flag=false;
     cout<<"Enter the number of the transfer"<<endl;
     getline(cin,name1);
    for(int i=0;i<transferCount;i++){
        if(remittance[i].transferingNumber == name1){
            flag = true;
            cout<<"Number already exists"<<endl;
            break;
        }
    }


     }while(flag);
     remittance[transferCount].transferingNumber = name1;
    transferCount++;
    saveTransfer();
    }

    // void takeTheMoneyFromTransfer(){
    //   string tranNum;
    //   string name21;
    //   string name22;
    //   cout<<"Enter the number of the transfer"<<endl;
    //   getline(cin,tranNum);
    //   cout<<"Enter the name of the receiver"<<endl;
    //   getline(cin,name21);
    //  cout<<"Enter the phone number of the sender"<<endl;
    //   getline(cin,name22);

    //   for(int i=0;i<transferCount;i++){
    //    if(tranNum!=remittance[i].transferingNumber){
    //     cout<<"Sorry we could not find this one "<<endl;
    //     return;
    //   }
    //   else{
    //      remittance[i].theAmountOfMoney-=remittance[i].theAmountOfMoney;
    //     transferCount--;
    //     saveTransfer();}
    //   }

    // }

  int  loginPage(){


    cout<<"********/ Login page /********"<<endl;

   string UserName;
   string Password;

   do{
     cout<<"Enter your name"<<endl;
    getline(cin,UserName);
    cout<<"Enter your password"<<endl;
    getline(cin,Password);

    for(int i=0;i<userCount;i++){
     if(UserName==user[i].name  &&  Password==user[i].password){
      if(!user[i].active){
        	cout<<"User is inactive.contact admin"<<endl;

        		return-1;  //THIS SHOWS THE FAILING OF THE OPERATION
      }
      cout<<"Login successful welcome :"<<user[i].name<<endl;
      return i; //because the i is the address of the user inside the  array
        	// without the i ,I cannot know who is the current user (admin /user/employee)
     }
    }
     	
    	cout<<"Login failed ,Incorrect username or password"<<endl;
    	
    	return -1;
    
    	cout<<"------------------------------------------------"<<endl;

   }while (UserName!=user[userCount].name  &&  Password!=user[userCount].password);
  }



  int main(){
     string ziad=" Ruheef";
     cout<<ziad.length();
   	 return 0;
   }
