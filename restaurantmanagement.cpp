#include<bits/stdc++.h>

using namespace std;

void order_menu();

void bill();

void total();

struct node{
    string name;
    int odr[10]={0,0,0,0,0,0,0,0,0,0};
    int total=0;
    int  pin;
    struct node *next;
};

int n=1;
struct node *admin;
struct node *curr;

string itm[10];
int price[10];
int top=0;

void push(string i,int p){
    if(top==9)cout<<"\nItem list is full!";
    else{

        itm[top]=i;
        price[top]=p;
        top++;
        cout<<"\nItem added to list successfully!\n";
    }
}

void pop(){
    if(top==0)cout<<"\nItem list is empty!";
    else{
        string s;
        int i,j;
        cout<<"\nEnter name of item to be deleted\n";
        cin>>s;
        for(i=0;i<top;i++){
            if(itm[i]==s){j=i;break;}
            if(i==top-1)i=top+1;
        }
        if(i==top+1)cout<<"\nItem not found!!";
        else{
            for(i=j;i<top;i++){
                itm[i]=itm[i+1];
                price[i]=price[i+1];
            }
            top--;
            cout<<"\nItem deleted successfully";
        }
    }
}

void intro(){
    cout<<"\t\t-----------------------------------------------------------\n";
     cout<<"\t\t***********************************************************\n";
     cout<<"\t\t|\t\tRESTAURANT MANAGEMENT SYSTEM\t\t  |\n";
     cout<<"\t\t|\t\tBY\t\t\t\t\t  |\n\t\t|\t\t21BCE095 --- JAY PANDYA\t\t\t  |\n\t\t|\t\t21BCE094 --- JASANI DEEP\t\t  |\n\t\t|\t\t21BCE093 --- JAISWAL JENIL\t\t  |\n";
     cout<<"\t\t***********************************************************\n";
     cout<<"\t\t-----------------------------------------------------------\n\n\n\n\n";
     
}

void main_menu(){
    cout<<"\n_______________________________________________________";
    printf("\n\n1.Register\n");
    printf("2.Login\n");
    printf("3.Exit\n");
    printf("Your response : ");
}

void menu(){
    label2:
    printf("\n\n1.Place order\n");
    printf("2.Generate bill and exit\n");
    int r;
    cout<<"Enter your response : ";
    cin>>r;
    if(r==1){

        order_menu();
        cout<<"\nPlace order\nEnter [0] to exit\n";
        int k,q;
        while(1==1){
            label:
            cout<<"order item number : ";
            cin>>k;
            if(k==0)goto label2;;
            if(k>top||k<0){cout<<"Enter valid input\n";goto label;}
            cout<<"quantity : ";
            cin>>q;
            if(q<0){cout<<"Enter valid input\n";goto label;}
            (curr->odr[k-1])+=q;
            (curr->total)+=(price[k-1]*q);
        }
    }
    else if(r==2){
        bill();
        //goto l1;
    }
}

void bill(){
    int k=0;
    cout<<"\n____________________________BILL____________________________";
    for(int i=0;i<10;i++){
        if((curr->odr[i])!=0)cout<<"\n"<<++k<<". "<<itm[i]<<"----------- X "<<(curr->odr[i]);
    }
    cout<<"\nTotal ----- "<<curr->total;
    cout<<"\n18% GST ----- "<<((0.18)*(curr->total));
    cout<<"\nGrand total ----- "<<(curr->total+((0.18)*(curr->total)));
    cout<<"\n____________________________________________________________";
}

void order_menu(){
    if(top==0)cout<<"\nno items added by admin to show in menu!!\nplease login as admin and add items in menu";
    else{
    cout<<"\n_________________________________________________________________";
    cout<<"\n*******ORDER LIST*******\n\n\n";
    for(int i=0;i<top;i++){
        cout<<"\n"<<i+1<<". "<<itm[i]<<" -------------------------- "<<price[i];
    }
    cout<<"\n_________________________________________________________________";
    }
}

void admin_menu(){
    printf("\n\n1.Add Item in order menu\n");
    printf("2.Delete Item in order menu\n");
    printf("3.Total Profit\n");
    cout<<"4.View item list\n";
    printf("5.Exit\n");
    int r;
    cout<<"\nEnter your response : ";
    cin>>r;
    if(r==1){
        string s;
        int p;
        cout<<"Enter the item name\n";
        cin>>s;
        cout<<"Enter the price\n";
        cin>>p;
        push(s,p);
        admin_menu();
    }
    else if(r==2){pop();admin_menu();}
    else if(r==3){total();admin_menu();}
    else if(r==4){order_menu();admin_menu();}
    else if(r==5){cout<<"sign out successful";}
}

void total(){
    int i;
    cout<<"\n-----------------Total sales to users-----------------\n";
    struct node *ptr;
    ptr=admin->next;
    for(i=1;i<n;i++){
        cout<<"\n"<<i<<". "<<ptr->name<<" -------- "<<ptr->total;
        ptr=ptr->next;
    }
    cout<<"\n------------------------------------------------------\n";
}

void add_admin(){
    int p;
    string c;
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("*************____SET ADMIN____*************\n\n");
    printf("Enter your name : ");
    cin>>c;
    printf("Enter your pin : ");
    cin>>p;
    ptr->name=c;
    ptr->pin=p;
    admin=ptr;
    printf("ADMIN SET SUCCESSFULLY\n\n");
}

void add_user(){
    int p;
    string c;
    struct node *ptr,*tmp;
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("\n\n_____________Add new user_____________\n\n");
    printf("Enter your name : ");
    cin>>c;
    printf("Enter your pin : ");
    cin>>p;
    ptr->name=c;
    ptr->pin=p;
    tmp=admin;
    for(int i=0;i<n-1;i++){
        tmp=tmp->next;
    }
    tmp->next=ptr;
    n++;
    printf("profile created successfully\n");
}

void login(){
    string k;
    int p,i,j=1;
    printf("Enter your name : ");
    cin>>k;
    printf("Enter your pin : ");
    cin>>p;
    struct node *ptr;
    ptr=admin;
    if(k==ptr->name&&p==ptr->pin)admin_menu();
    else{
    ptr=ptr->next;
    for(i=1;i<n;i++){
        if(k==ptr->name&&p==ptr->pin){curr=ptr;menu();}
        else{ptr=ptr->next;}
        j++;
        }
        if(j==n-1)cout<<"\nInvalid credentials";
    }
}


int main(){
    intro();
    add_admin();
    do{
    main_menu();
    int r;
    cin>>r;
    if(r==1){
        add_user();
    }
    if(r==2){
            login();
    }
    if(r==3)break;
    }while(1==1);
}
