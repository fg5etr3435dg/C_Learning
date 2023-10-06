#include <iostream>
#include "string"
#include "iomanip"
#define MAX 1000

using namespace std;

struct  Person
{
    int    m_Sex;
    int    m_Age;
    string m_Name;
    string m_Phone;
    string m_Addr;
};

//通讯录结构体
struct  Addressbooks
{
    //通讯录保存的联系人数组
    struct Person personArray[MAX]; //通讯录保留的
    
    int m_Size;
};

void addPerson  (Addressbooks *abs);
void showPerson (Addressbooks *abs);
void findPerson (Addressbooks *abs);
void deletePerson (Addressbooks *abs);
void newPerson (Addressbooks *abs,int num);

int isExist (Addressbooks *abs,string name);
void showMenu  ( );

int main ()
{
    int select =0;
   //创建一个通讯录的结构体变量
   Addressbooks abs;
   abs.m_Size=0;//初始化通讯录中的结构体
   
   while (1)
    { 
        showMenu();
        cin >>select;
        switch (select)
        {
        case 1:
        addPerson(&abs);
            break;
        case 2:
        showPerson(&abs);
            break; 
        case 3:
        deletePerson(&abs);
            break;
        case 4:
        findPerson(&abs);
            break;

        case 5:

            break;
        case 0:
            cout<<"退出成功,欢迎下次使用......"<<endl;
            system("pause");
            return 0;

        default:

        cout<<"输入有误，请重新输入;"<<endl;
        
        cin>>select;
            break;
        }
    }
    system("pause");
    return 0;

}
void showMenu()
{
    cout<<"**************************"<<endl;
    cout<<"*****  1.添加联系人  *****"<<endl;
    cout<<"*****  2.显示联系人  *****"<<endl;
    cout<<"*****  3.删除联系人  *****"<<endl;
    cout<<"*****  4.查找联系人  *****"<<endl;
    cout<<"*****  5.清空联系人  *****"<<endl;
    cout<<"*****  0.退出联系人  *****"<<endl;
    cout<<"**************************"<<endl;
} 
void showPerson (Addressbooks *abs)
{
    if (abs->m_Size==0)
    {
        cout<<"当前通讯录为空."<<endl;
        system("pause");
        system("cls");
    }
    else
    {
       system("cls");
       cout<<left <<setw(8)<<"序号"<< setw(8)<<"姓名"<< setw(8)<<"性别"<< setw(8)<<"年龄"<< setw(15)<<"电话号码"<< setw(20)<<"家庭地址"<<endl;
       for ( int i = 0; i < abs->m_Size; i++)
       {
        string str;
        abs->personArray->m_Sex? str="女":str="男";
        cout<<left <<setw(8)<<i<< setw(8)<<abs->personArray->m_Name<< setw(8)<<str<< setw(8)<<abs->personArray->m_Age<< setw(15)<<abs->personArray->m_Phone<< setw(20)<<abs->personArray->m_Addr<<endl;
       }       
        system("pause");
        system("cls");
    }
}
void deletePerson (Addressbooks *abs)
{
    string name;
    cout<<"请输入需要删除联系人的姓名:"<<endl;
    cin>>name;
    int num =isExist(abs,name);
    if(num==-1)
    {
        cout<<"查无此人！"<<endl;
        system("pause");
        system("cls");
    }    
    else
    {
        system("cls");
        string str;
        cout<<"请问是否要删除联系人:"<<name<<"(YES/NO)"<<endl;
        while (1)
        {       
            string Deter;
            cin>>Deter;
            for (int i=0; i <Deter.size(); i++)  Deter[i] = toupper(Deter[i]); //转换为大写字母
            
            if(Deter=="YES"||Deter=="Y") 
            { 
                newPerson (abs,num);
                cout<<"联系人  "<<name<<"  删除成功"<<endl;
                system("pause");
                system("cls");
                break;
            }
            else if(Deter=="NO"||Deter=="N")
            {
                system("pause");
                system("cls");
                break;
            }
            else
            {
                cout<<"输入有误！请重新输入;"<<endl;
            }
        }   
       
    }
}
void findPerson (Addressbooks *abs)
{
        string name;
        cout<<"请输入需要查找联系人的姓名:"<<endl;
        cin>>name;
        if(isExist(abs,name)==-1)
        {
             cout<<"查无此人！"<<endl;
        }    
}
int isExist (Addressbooks *abs,string name)  //检测输入的姓名是否存在
{
    for (int i = 0; i < abs->m_Size; i++)
    {
        if(abs->personArray->m_Name==name) 
        {
            system("cls");
            string str;
            abs->personArray->m_Sex? str="女":str="男";
            cout<<left <<setw(8)<<"序号"<< setw(8)<<"姓名"<< setw(8)<<"性别"<< setw(8)<<"年龄"<< setw(15)<<"电话号码"<< setw(20)<<"家庭地址"<<endl;
            cout<<left <<setw(8)<<i<< setw(8)<<abs->personArray->m_Name<< setw(8)<<str<< setw(8)<<abs->personArray->m_Age<< setw(15)<<abs->personArray->m_Phone<< setw(20)<<abs->personArray->m_Addr<<endl;
            system("pause");
            return i;
        }
    }
    return -1;
}
void addPerson  (Addressbooks *abs){
    //判断通讯录是否已满，软管满了就不再添加
    if (abs->m_Size==MAX)
    {
      cout <<"通讯录已满,无法添加"<<endl;
      return ;
    }
    else
    {
        Person Person_input;
        cout<<"请输入姓名:"<<endl;
        cin>>Person_input.m_Name;
        abs->personArray[abs->m_Size].m_Name=Person_input.m_Name;

        cout<<"请输入性别(0/1):"<<endl;
        cout<<"0---男   1---女"<<endl;
        cin>>Person_input.m_Sex;
        while (1)
        {
            if (Person_input.m_Sex == 0||Person_input.m_Sex == 1)
            {
                break;
            }
            else
            cout<<"性别输入有误,请重新输入"<<endl;
            cout<<"请重新输入性别(0/1):"<<endl;
            cout<<"0---男   1---女"<<endl;
            cin>>Person_input.m_Sex;
        }
        abs->personArray[abs->m_Size].m_Sex=Person_input.m_Sex;

        cout<<"请输入年龄:"<<endl;
        cin>>Person_input.m_Age;
        abs->personArray[abs->m_Size].m_Age=Person_input.m_Age;

        cout<<"请输入电话号码:"<<endl;
        cin>>Person_input.m_Phone;
        while (1)
        {
            //cout<<Person_input.m_Phone.length()<<endl;
            if (Person_input.m_Phone.length()==11)  //length()获取Person_input.m_Phone的字符串长度
            {
                break;
            }
            cout<<"号码输入有误,请重新输入"<<endl;
            cout<<"请重新输入号码:"<<endl;
            cin>>Person_input.m_Phone;
        }
        
    abs->personArray[abs->m_Size].m_Phone=Person_input.m_Phone;
    
    int num=0;
    while(1)
    {   
        
        if (num)
        {
           cout<<"请重新输入住址:"<<endl; 
        }
        else {cout<<"请输入住址:"<<endl;}

        cin>>Person_input.m_Addr;
        cout<<"请确定添加的地址是否为:"<<Person_input.m_Addr<<"(YES/NO)"<<endl;

          
        while (1)
        {       
            string Deter;
            cin>>Deter;
            for (int i=0; i <Deter.size(); i++)  Deter[i] = toupper(Deter[i]); //转换为大写字母
            
            if(Deter=="YES"||Deter=="Y") {goto tiaochu;}
           
            else if(Deter=="NO"||Deter=="N")
            {
                num++;
                break;
            }
            else
            {
                cout<<"输入有误！请重新输入;"<<endl;
            }
        }    
    }
tiaochu:
        abs->personArray[abs->m_Size].m_Addr=Person_input.m_Addr;
        
        //更新通讯录的人数
        abs->m_Size++;
        cout<<"添加联系人成功;"<<endl;
    }
    system ("pause");
    system ("cls");
}
void newPerson (Addressbooks *abs,int num)  //删除人员之后，将重新排序
{
    for (int i = num; i < abs->m_Size; i++)
    {
        abs->personArray[i]=abs->personArray[i+1];
        //abs->personArray[abs->m_Size]=nup;
     }
     abs->m_Size--;
    
}
