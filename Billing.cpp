#include<iostream>
#include<fstream>

using namespace std;

class shopping{
    private:
        int pcode;
        float price;
        float dis;
        string pname;
    public:
        void menu();
        void administrator();
        void buyer();
        void add();
        void edit();
        void rem();
        void list();
        void receipt();
};
void shopping :: menu(){
    
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t______________________________________________\n";
    cout<<"\t\t\t\t                                              \n";
    cout<<"\t\t\t\t           SuperMarket Main Menu              \n";
    cout<<"\t\t\t\t                                               \n";
    cout<<"\t\t\t\t_______________________________________________\n";
    cout<<"\t\t\t\t|          1)Adminstrator                      |\n";
    cout<<"\t\t\t\t|                                             |\n";
    cout<<"\t\t\t\t|          2)Buyer                            |\n";
    cout<<"\t\t\t\t|                                             |\n";
    cout<<"\t\t\t\t|          3)Exit                             |\n";
    cout<<"\n\t\t\t Please Select ";
    cin>>choice;
    switch(choice){
        case 1:
            cout<<"Please Enter Email:-\t";
            cin>>email;
            cout<<"Please Enter Password:\t";
            cin>>password;
            if(email == "admin123@gmail.com" && password =="123")
                administrator();
            else
                cout<<"Please Enter Correct Email or Password \n";
            break;
        case 2:
            buyer();
            break;
        case 3:
            exit(0);
        default :
            cout<<"Please enter an Vaild Choice";
             
    }
    goto m;
}
void shopping :: administrator(){
    m:
    int choice;
    cout<<"\n\n\n\t\t\tAdministrator Menu";
    cout<<"\n\t\t\t|_____1) Add The Product_____________|";
    cout<<"\n\t\t\t|                                    |";
    cout<<"\n\t\t\t|_____2) Modify The Product__________|";
    cout<<"\n\t\t\t|                                    |";
    cout<<"\n\t\t\t|_____3) Delete The Product__________|";  
    cout<<"\n\t\t\t|                                    |";
    cout<<"\n\t\t\t|_____4) Back Menu___________________|";   


    cout<<"\nPlease Enter The Choice: ";
    cin>>choice;
    switch(choice){
        case 1:
            add();
            break;
        case 2:
            edit();
            break;
        case 3:
            rem();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"invalid Choice";
    }   
    goto m;
}
void shopping ::buyer(){
    m:
    int choice;
    cout<<"\t\t\tBuyer   \n";
    cout<<"\t\t\t__________\n";
    cout<<"\t\t\t           \n";
    cout<<"\t\t\t1) Buy Product   \n";
    cout<<"\t\t\t           \n";
    cout<<"\t\t\t2) Go Back\n";
    cout<<"\t\t\t           \n";
    cout<<"Please Enter Choice: ";
    cin>>choice;
    switch(choice){
        case 1:
            receipt();
            break;
        case 2:
            menu();
            break;
        default:
            cout<<"Invalid Choice";
    }
    goto m;
}
void shopping :: add(){
    m:
    fstream data;
    int c;
    int token = 0;
    float p;
    float d;
    string n;
    cout<<"\n\n\t\t\t Add new Product";
    cout<<"\n\n\tProduct Code of The Product:\t";
    cin>>pcode;
    cout<<"\n\n\tEnter Product name:\t";
    cin>>pname;
    cout<<"\n\n\tEnter Product price:\t";
    cin>>price;
    cout<<"\n\n\tEnter Product Discount:\t";
    cin>>dis;
    data.open("database.txt",ios::in);
    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    else{
        data>>c>>n>>p>>d;
        while(!data.eof()){
            if(c == pcode)
                token++;
            data>>c>>n>>p>>d;
        }
        data.close();
        if(token==1){
            goto m;
        }
        else{
            data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
        }
    }
    cout<<"\n\n\tRecord inserted";
}
void shopping :: edit(){
    fstream data,data1;
    int pkey;
    int token = 0;
    int c;
    float p;
    float d;
    string n;
    cout<<"\n\t\t\tModify the Record";
    cout<<"\n\t\t\tProduct Code";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n File Doesn't Exist";
            }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\tEnter Product New Code";
                cin>>c;
                cout<<"\n\t\t Name of product";
                cin>>n;
                cout<<"\n\t\tPrice";
                cin>>p;
                cout<<"\n\t\tDiscount";
                cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"Record Editted";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.txt");
        remove("database1.txt");
        if(token==0){
            cout<<"\n\nRecord Not Found !";
        }
    }
}
void shopping::rem(){
    fstream data,data1;
    int pkey;
    int token = 0;
    cout<<"\n\n\t Delete a Product";
    cout<<"\n\n\t Enter The Product Code:";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\nFile Doesn't Exist";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
            if(pcode==pkey){
                cout<<"\n\n\tProduct Deleted Successfully";
                token++;
            }
            else{
                data1<<" "<<pcode<<" "<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();
        remove("database.tx");
        rename("database1.txt","database.txt");
        if(token == 0){
            cout<<"\n\nRecord Not found";
        }
    }
}
void shopping::list(){
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|______________________________________\n";
    cout<<"ProNo\t\tName\t\tPrice\n";
    cout<<"\n\n|______________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof()){
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    }
    data.close();
}
void shopping::receipt(){
    fstream data;
    m:
    int arrc[100];
    int arrq[100];
    char choice;
    int c = 0;
    float amount = 0;
    float dis = 0;
    float total = 0;
    cout<<"\n\n\t\t\t\t Recipt";
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n Empty Database";
    }
    else{
        data.close();
        list();
        cout<<"\n_______________________________\n";
        cout<<"\n|                              \n";
        cout<<"\n       please place Order      \n";
        cout<<"\n|                              \n";
        cout<<"\n_______________________________\n";
        do{
            cout<<"\n\nEnter The Product code: ";
            cin>>arrc[c];
            cout<<"\n\nEnter Product Quantity: ";
            cin>>arrq[c];
            for(int i = 0;i<c;i++){
                if(arrc[c]==arrc[i]){
                    cout<<"\n\nDuplicate Product code.Please reenter";
                    goto m;
                }
            }
            c++;
            cout<<"\n\n Do you want to buy another Product ? if yes then press y else n : ";
            cin>>choice;
        }
        while(choice=='y');
        cout<<"\n\n\t\t________________________________Receipt__________________________________\n";
        cout<<"\nProduct No\t Product Name\t Product Quantity\t Price\t Amount\t Amount with discount\n";
        for(int i =0 ;i<c;i++){
            data.open("database.txt",ios::in);
            data>>pcode>>pname>>price>>dis;
            while(!data.eof()){
                if(pcode== arrc[i]){
                    amount = price*arrq[i];
                    dis = amount-(amount*dis/100);
                    total= total+dis;
                    cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t"<<amount<<"\t\t"<<dis;
                }
                data>>pcode>>pname>>price>>dis;
            }
        }
        data.close();
    }
    cout<<"\n\n________________________________________";
    cout<<"\n Total Amount :"<<total;
}
int main(){
    shopping s;
    s.menu();
}