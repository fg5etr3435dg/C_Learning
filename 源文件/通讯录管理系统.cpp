#include <iostream>
#include "string"
#define MAX 1000

using namespace std;

struct  Person
{
    int     m_Sex;
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

void addPerson (Addressbooks *abs)
{
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
}

int main ()
{
    int select =0;
    
   //创建一个通讯录的结构体变量1

   Addressbooks abs;
   abs.m_Size=0;
   //初始化通讯录中的结构体
   showMenu();
   cin >>select;
   while (1)
    {
        switch (select)
        {
        case 1:
        addPerson(&abs);
        showMenu();
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

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