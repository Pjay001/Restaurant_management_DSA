import java.util.*;

interface m{
    void main_menu();
    void cust_menu(Func j);
    void adm_menu();
}

class odr_list{
    String food[]=new String[10];
    int price[]=new int[10];
    int bill[]=new int[10];
    int f=0;
    void odr_list(){
        System.out.println("_________________ORDER MENU_________________\n");
        for(int i=0;i<f;i++){
            System.out.println((i+1)+". "+food[i]+" --------------- "+price[i]);
        }
        System.out.println("____________________________________________\n");
    }
    void odr_list(Func j){
        System.out.println("_________________ BILL _________________\n");
        for(int i=0;i<10;i++) {
            if (bill[i] != 0) {
                System.out.println((i + 1) + ". " + food[i] + " ------------------------ " + price[i] + " X "+bill[i]);
            }
        }
        System.out.println("TOTAL ------------------------ "+j.total);
        System.out.println("5% GST ------------------------ "+j.total*0.05);
        System.out.println("NET TOTAL ------------------------ "+j.total*1.05);
        System.out.println("________________________________________\n");
    }
}
class menu extends odr_list implements m{

    Scanner sc=new Scanner(System.in);
    public void main_menu(){
        System.out.println("_____________________________________________\n\n");
        System.out.println("1.Register");
        System.out.println("2.Login");
        System.out.println("3.Exit");
    }
    public void cust_menu(Func j){
        int k;
        while(true){
            System.out.println("\n");
            System.out.println("1.Place Order");
            System.out.println("2.Generate bill");
            System.out.println("3.Exit");
            System.out.println("Enter your response : ");
            k=sc.nextInt();
            if(k==1){
                int g=1,q;
                if(f==0){
                    System.out.println("Admin has not added any food items yet !!!");
                }
                else{
                    odr_list();

                    while(g!=0){
                        System.out.println("Enter the Sr. number of item you want to order ( Enter [0] to Exit)  : ");

                        while(true){
                            g=sc.nextInt();
                            if(g>=0&&g<f+1)break;
                            System.out.println("Enter a valid input :");
                        }
                        if(g==0){break;}
                        else{
                            System.out.println("Enter the quantity of item you want to order : ");
                            while(true){
                                q=sc.nextInt();
                                if(q>0)break;
                                System.out.println("Enter a valid input :");
                            }
                            bill[g-1]+=q;
                            j.total+=q*price[g-1];
                        }
                    }
                }
            }
            if(k==2){
                odr_list(j);
            }
            if(k==3){
                break;
            }
        }
    }
    public void adm_menu(){
        System.out.println("\n");
        System.out.println("1.Add Item");
        System.out.println("2.Delete Item");
        System.out.println("3.View order list");
        //System.out.println("4.View total user");
        System.out.println("4.Exit");
        int k=0,c=0;
        do{
            System.out.println("Enter your response : ");
            k=sc.nextInt();
            if(k==1){
                if(f==10){
                    System.out.println("\nItem list full !");
                    adm_menu();
                }
                sc.nextLine();
                System.out.println("Name of Item");
                food[f]=sc.nextLine();
                System.out.println("Price of Item");
                price[f]=sc.nextInt();
                f++;
                System.out.println("Item added Successfully !");
                adm_menu();
            }
            if(k==2){
                if(f==0){
                    System.out.println("\nItem list is empty !");
                    adm_menu();
                }
                sc.nextLine();
                odr_list();
                System.out.println("Enter the index of item you want to delete :");
                int l;
                l=sc.nextInt();
                for(int i=l-1;i<f-1;i++){
                    food[i]=food[i+1];
                    price[i]=price[i+1];
                }
                f--;
                System.out.println("Item deleted Successfully !");
                adm_menu();
            }
            if(k==3){
                odr_list();
                adm_menu();
            }
            if(k==4){
                break;
            }
        }while(k!=5);
    }
}

abstract class data extends menu{
    String name;
    int m_number;
    String password;
    int total;
}

class Func extends data{   //INHERITANCE

    public Func set_user(String s,String i,int m)    //RETURNS OBJECT
    {
        Func temp=new Func();
        temp.name=s;
        temp.password=i;
        temp.m_number=m;
        return temp;
    }
}
public class oop_class
{
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Func admin=new Func();
        Func curr;
        Func[] user;
        user=new Func[10];
        for(int i=0;i<10;i++)user[i]=new Func();
        menu m=new menu();
        String s,p;
        int n=0,r,p1,mn;
        System.out.println("_____________SET ADMIN_____________\n");
        System.out.println("Enter Username : ");
        s=sc.nextLine();
        System.out.println("Enter Password : ");
        p=sc.nextLine();
        admin=admin.set_user(s,p,0);
        System.out.println("ADMIN SET SUCCESSFULLY ! ");
        while(true){
            m.main_menu();
            System.out.println("Enter your response : ");
            r=sc.nextInt();
            if(r==1){
                System.out.println("_____________ADD NEW USER_____________\n");
                sc.nextLine();
                System.out.println("Enter Username : ");
                s=sc.nextLine();
                System.out.println("Enter your contact number : ");
                mn=sc.nextInt();
                System.out.println("Enter Password : ");
                p=sc.nextLine();
                user[n]=user[n].set_user(s,p,mn);
                n++;
                System.out.println("USER ADDED SUCCESSFULLY ! ");
            }
            else if(r==2){
                s=sc.nextLine();
                System.out.println("\nEnter Username : ");
                s=sc.nextLine();
                System.out.println("Enter Password : ");
                p=sc.nextLine();
                if(s.equals(admin.name)&&p.equals(admin.password))m.adm_menu();
                else{
                    for(int i=0;i<n;i++){
                        if(s.equals(user[i].name)&&p.equals(user[i].password)){
                            curr=user[i];
                            m.cust_menu(curr);
                        }
                    }
                }
            }
            else if(r==3)break;
        }
    }

}
