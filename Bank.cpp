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
                                  //string message = remittance[transferCount-1].senderName * use this if this is a problem in the add money to someone function  *
                                  //(4)to set the local time  :  auto now=chrono::system_clock::now();//We bring the local time as time point.
   //  time_t now_time=chrono::system_clock::to_time_t(now);//transform the time_t to be able to print it .
    // cout<<"The local time "<<ctime(&now_time)<<endl; //now print it as history and time will be read.
    
#include<iostream>
#include<string> 
#include<fstream>
#include<cmath>
#include<iomanip>
#include<vector>
#include<cstdlib>
#include<windows.h>
#include <limits>
#include <chrono>
#include <cctype>      //for isalpha()

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
  double theAmountOfMoney;
   string transferingNumber;

 };
 Remittances remittance[maxTransfers];
 int transferCount=0;
 


struct Banks{
  string bankname;
  string place;
  double  BankAccount;
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
double bankAccount;
string  gender;
bool active;
string phoneNumber;
string fantasticNumber;//This is the name of the account 
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

void saveTransaction(string message){

    ofstream file("transactions.txt", ios::app);

    if(!file){
        cout<<"Cannot open transaction file"<<endl;
        return;
    }

    file << message << endl;

    file.close();
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

  void inputBank(){

  string requiredPrefix[4]={"77","78","71","73"};

   if (bankCount >= maxBank) {
        cout<< "Sorry you can not add a new bank account!  you have reached the limit" <<maxBank << ").\n";
    }
    cin.ignore();
    cout<<"Enter the bank name "<<endl;
    getline(cin,bank[bankCount].bankname);
    cout<<"Enter the bank place"<<endl;
    getline(cin,bank[bankCount].place);
    cout<<" Enter your bank account"<<endl;
    cin>>bank[bankCount].BankAccount;
    cin.ignore();
    cout<<" Enter the name or number of the account"<<endl;
    getline(cin,bank[bankCount].theNameOFTheAccount);
    
     int active;
    do{
      
      cout<<"Enter the status of your activity"<<endl;
       cin>>active;
       cin.ignore();
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
    cin>>user[userCount].bankAccount;


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
      bool flag1=false;
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
           flag1=true;
          string uniNumber;
          cout<<"Enter the number of the tranferring "<<endl;
          getline(cin,uniNumber);
          if (bank[i].uinqueNumber!=uniNumber ){

           double addingMoney;
           cout<<"Enter the amount of the money"<<endl;
            cin>>addingMoney;
           bank[i].BankAccount+=addingMoney;
          bank[i].uinqueNumber=uniNumber;
           saveBanks();
            cout<<"The operation was successfully completed"<<endl;
            string message =
            "Bank account " +
             bank[i].theNameOFTheAccount +
             " received " +
            to_string(addingMoney);

           saveTransaction(message);
          }
          else{

            cout<<"This number is entered previously"<<endl;
          }
          
        }
     }
     flag1=false;
   cout<<"Sorry we could not find the bank account"<<endl;

   }

  void bankTakesMoneyFromItsAccount(){
  string name17;
  string name18; 
  cout<<"Enter the name of the bank"<<endl; 
  getline(cin,name17);
  cout<<"Enter the name of the account"<<endl; 
  getline(cin,name18);
  
   for(int i=0;i<bankCount;i++){
    if(name17==bank[i].bankname && name18==bank[i].theNameOFTheAccount){
    cout<<"We found the account of the bank"<<endl;
    if (!bank[i].isActive){
     cout<<"Sorry, the bank account is not active"<<endl;
       return;
    }

    else{
     double money;
     cout<<"Enter the amount of the money"<<endl;
     cin>>money;
     if (money>bank[i].BankAccount){
      cout<<"Sorry, insufficient funds"<<endl;
      return;
     }
      bank[i].BankAccount-=money;
      saveBanks();
      string message =
      "Bank account :" +bank[i].bankname +" with this account name :" +
       bank[i].theNameOFTheAccount +
       " withdrew " +
       to_string(money);

       saveTransaction(message);
       cout<<"The operation was successfully completed"<<endl;
       }
      }

     }
   }
    void addMoneyToYourAccount(){
     string userName;
     string fantaNumber;
     cout<<"Enter Your Name"<<endl;
     getline (cin,userName);
     cout<<"Enter YourPassword"<<endl;
     getline (cin,fantaNumber);
     for (int  i = 0; i <userCount; i++)
     {
      if (userName==user[i].name &&  fantaNumber==user[i].fantasticNumber)
      {
        double amount;
        cout<<"Enter the amount of the money"<<endl;
        cin>>amount;
        user[i].bankAccount+=amount;
         saveUser();
        string message =
        user[i].name + " deposited " + to_string(amount);
        cout<<"The name :"<<user[i].name<<"Your account is :"<<user[i].bankAccount<<endl;
        cout<<"Deposit completed successfully"<<endl;
           saveTransaction(message);
            break;
      }
      
    }  
     cout<<"Sorry we could not find your account"<<endl;

    }
    void takeMoneyFromYourAccount(){
    string name14;
    string name15;
    double name16;

    cout<<"Enter the name"<<endl;
     getline (cin,name14);
     cout<<"Enter the  Password"<<endl;
     getline (cin,name15);
     for(int i=0;i<userCount;i++){
     if (name14==user[i].name &&  name15==user[i].password){
      if(!user[i].active) {
        cout<<"Sorry this account is not active"<<endl;
        return;
      }
       cout<<"The bank account of this client: "<<user[i].name<< "is :  "<<user[i].bankAccount<<endl;
       cout<<"Enter how much do you want"<<endl;
       cin>>name16;
       cout<<endl;

      if (name16 > user[i].bankAccount){
        cout<<"Insufficient funds"<<endl;
        return;
      }
       user[i].bankAccount-=name16;
       saveUser();
       string message =
       user[i].name +
        " withdrew " +
         to_string(name16);

      saveTransaction(message);
     }
     else{
      cout<<"Sorry we could not find this account "<<endl;
     }
   }
 }

    void addMoneyToSomeOne(){
      double money;
     cout<<"Enter the name of the receiver"<<endl;
     getline(cin,remittance[transferCount].recipientName);
      cout<<"Enter the phone number of the receiver"<<endl;
     getline(cin,remittance[transferCount].recipientNumber);
      cout<<"Enter the name of the sender"<<endl;
     getline(cin,remittance[transferCount].senderName);
      cout<<"Enter the phone number of the sender"<<endl;
     getline(cin,remittance[transferCount].senderNumber);
     cout<<"Enter the amount of the mouney"<<endl;
     cin>>money;
     cin.ignore();
     remittance[transferCount].theAmountOfMoney=money;

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
     string message =
     remittance[transferCount-1].senderName +
     " transferred money to " +
     remittance[transferCount-1].recipientName +
     " amount " +
     to_string(money);

     saveTransaction(message);
    }

    void takeTheMoneyFromTransfer(){
      string tranNum;
      string name21;
      string name22;
      cout<<"Enter the number of the transfer"<<endl;
      getline(cin,tranNum);
      cout<<"Enter the name of the receiver"<<endl;
      getline(cin,name21);
     cout<<"Enter the phone number of the receiver"<<endl;
      getline(cin,name22);
        bool found=false;
      for(int i=0;i<transferCount;i++){
       if(tranNum!=remittance[i].transferingNumber){
        cout<<"Sorry we could not find this one "<<endl;
        return;
      }
      else{
        found=true;
       cout<<"the name of the receiver "<<remittance[i].recipientName<<"    the number of the receiver   "<<remittance[i].recipientNumber<<endl; 
       cout<<"the name of the sender   "<<remittance[i].senderName<<"  the number of the sender  "<<remittance[i].senderNumber<<endl;
       cout<<"The amount of the money   "<<remittance[i].theAmountOfMoney<<endl;
       cout<<"The number of the transfer   "<<remittance[i].transferingNumber<<endl;
       cout<<"Enter an update value to this one "<<endl;
        cin>>remittance[i].theAmountOfMoney;
        transferCount--;
        saveTransfer();
        string message =
      "The receiver  " +remittance[i].recipientName +" his number "+remittance[i].recipientNumber+" has delivered the money  from the  sender " +remittance[i].senderName +" his number "+remittance[i].senderNumber + " amount "+ to_string(remittance[i].theAmountOfMoney) + " with the transfer number " + remittance[i].transferingNumber;
        saveTransaction(message);
       cout<<"The operation was successfully completed"<<endl;

      }
      }

    }
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

  
void showTransactions(){
   ifstream file("transactions.txt"); 
   if(!file){ 
    cout<<"No transactions found"<<endl; 
    return; 
  } string line;
   while(getline(file, line))
   { 
    cout << line << endl;
   }
    file.close();
 } 
  void activeUser(){
   string name45;
   cout<<"Enter the name "<<endl;
   getline(cin,name45);
   for(int i=0;i<userCount;i++){
     if(user[i].name==name45){
      if(user[i].active){
     cout<<"The user is originally active "<<endl;
      cout<<"*****************************"<<endl;
       return;
      }
      if (!user[i].active){
      user[i].active=true;
      saveUser();
      cout<<"The opration was successfully completed"<<endl;
       cout<<"*****************************"<<endl;
      }
     }
     else{
      cout<<"Sorry ,there is no user with this  name"<<endl;
      cout<<"*****************************"<<endl;
     }
   }

  }

  void disactiveUser(){
   string name54;
   cout<<"Enter the name"<<endl;
   getline(cin,name54);
   for(int i=0;i<userCount;i++){
    if(name54==user[i].name){
     if(!user[i].active){
       cout<<"The user is originally disactive "<<endl;
         cout<<"*****************************"<<endl;
       return;
     }
    if (user[i].active){
      user[i].active=false;
      saveUser();
      cout<<"The opration was successfully completed"<<endl;
        cout<<"*****************************"<<endl;
      }

    }
    else{
      cout<<"Sorry ,there is no user with this name "<<endl;
        cout<<"*****************************"<<endl;
    }
   }
  }

  void deleteUser(){
     string name700;
     cout<<"Enter the user name to delete"<<endl;
     getline(cin,name700);
     for(int i=0;i<userCount;i++){
      if (name700==user[i].name){
      for(int j=i;j<userCount-1;j++){
      user[j]=user[j+1];
      userCount--;
      saveUser();
       cout<<"The user was deleted successfully"<<endl;
			 cout<<"--------------------------------------"<<endl;
				 return;
      }
    }
  }
  	cout<<"the user is not found"<<endl;  
		cout<<"--------------------------------------"<<endl;
}

 void showUsers(){
   cout<<"THE VIWEING MENU"<<endl;
   cout<<left<<setw(15)<<"the name"<<setw(15)<<"the role"<<setw(15)<<"the gender"<<setw(15)<<"the phone number "<<setw(10)<<"status"<<endl;
	 for(int i=0;i<userCount;i++){
   cout<<left<<setw(15)<<user[i].name<<setw(15)<<user[i].role<<setw(15)<<user[i].gender<<setw(15)<<user[i].phoneNumber<<setw(10)<<( user[i].active ? "avaliable" :"disavaliable")<<endl;
   }	
 }
 void searchTheUserByFantasticNumber(){
    string name600;
    cout<<"Enter the fantastic number to search"<<endl;
    getline(cin,name600);
    bool ziad=false;
    for(int i=0;i<userCount;i++){
    if(name600==user[i].fantasticNumber){
     ziad=true;
      cout<<left<<setw(15)<<"the name"<<setw(15)<<"the role"<<setw(15)<<"the gender"<<setw(15)<<"the phone number "<<setw(10)<<"status"<<endl;
      cout<<left<<setw(15)<<user[i].name<<setw(15)<<user[i].role<<setw(15)<<user[i].gender<<setw(15)<<user[i].phoneNumber<<setw(10)<<( user[i].active ? "avaliable" :"disavaliable")<<endl;
    }
    }
    
	   if(!ziad)
	   cout<<"The book is not found"<<endl;
	   cout<<"**************************************"<<endl;
 }
 void numbersOfUsers(){
  if(userCount>0){
       	cout<<"the number of the users"<<userCount<<endl;
       	cout<<"**************************************"<<endl;
  }
  else{
    	cout<<"there are no users yet"<<endl;
     	cout<<"**************************************"<<endl;
  }
 }

 void createPillForClientAndEmployeeAndAdmin(){
    string name121;
    string name122;
    cout<<"Enter Your name"<<endl;
    getline(cin,name121);
    cout<<"Enter Your fantastic number"<<endl;
    getline(cin,name122);
    bool ziad2=false;
    for(int i=0;i<userCount;i++){
     if(name121==user[i].name &&  name122==user[i].fantasticNumber){
		    	ziad2=true;//for checking from the successful operation
       addMoneyToYourAccount();
     }

    }


 }
//I am ziad Alasadi
  int main(){
     auto now=chrono::system_clock::now();//We bring the local time as time point.
     time_t now_time=chrono::system_clock::to_time_t(now);//transform the time_t to be able to print it .
     cout<<"The local time "<<ctime(&now_time)<<endl; //now print it as history and time will be read.
   	 return 0;
   }
