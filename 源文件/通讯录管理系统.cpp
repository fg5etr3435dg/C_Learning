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

//ͨѶ¼�ṹ��
struct  Addressbooks
{
    //ͨѶ¼�������ϵ������
    struct Person personArray[MAX]; //ͨѶ¼������
    
    int m_Size;
};

void showMenu()
{
    cout<<"**************************"<<endl;
    cout<<"*****  1.�����ϵ��  *****"<<endl;
    cout<<"*****  2.��ʾ��ϵ��  *****"<<endl;
    cout<<"*****  3.ɾ����ϵ��  *****"<<endl;
    cout<<"*****  4.������ϵ��  *****"<<endl;
    cout<<"*****  5.�����ϵ��  *****"<<endl;
    cout<<"*****  0.�˳���ϵ��  *****"<<endl;
    cout<<"**************************"<<endl;
}

void addPerson (Addressbooks *abs)
{
    //�ж�ͨѶ¼�Ƿ�������������˾Ͳ������
    if (abs->m_Size==MAX)
    {
      cout <<"ͨѶ¼����,�޷����"<<endl;
      return ;
    }
    else
    {
        Person Person_input;
        cout<<"����������:"<<endl;
        cin>>Person_input.m_Name;
        abs->personArray[abs->m_Size].m_Name=Person_input.m_Name;

        cout<<"�������Ա�(0/1):"<<endl;
        cin>>Person_input.m_Sex;
        while (1)
        {
            if (Person_input.m_Sex == 0||Person_input.m_Sex == 1)
            {
                break;
            }
            else
            cout<<"�Ա���������,����������"<<endl;
            cout<<"�����������Ա�(0/1):"<<endl;
            cin>>Person_input.m_Sex;
        }
        abs->personArray[abs->m_Size].m_Sex=Person_input.m_Sex;

        cout<<"����������:"<<endl;
        cin>>Person_input.m_Age;
        abs->personArray[abs->m_Size].m_Age=Person_input.m_Age;

        cout<<"������绰����:"<<endl;
        cin>>Person_input.m_Phone;
        while (1)
        {
            //cout<<Person_input.m_Phone.length()<<endl;
            if (Person_input.m_Phone.length()==11)  //length()��ȡPerson_input.m_Phone���ַ�������
            {
                break;
            }
            cout<<"������������,����������"<<endl;
            cout<<"�������������:"<<endl;
            cin>>Person_input.m_Phone;
        }
        
    abs->personArray[abs->m_Size].m_Phone=Person_input.m_Phone;
    
    int num=0;
    while(1)
    {   
        
        if (num)
        {
           cout<<"����������סַ:"<<endl; 
        }
        else {cout<<"������סַ:"<<endl;}

        cin>>Person_input.m_Addr;
        cout<<"��ȷ����ӵĵ�ַ�Ƿ�Ϊ:"<<Person_input.m_Addr<<"(YES/NO)"<<endl;

          
        while (1)
        {       
            string Deter;
            cin>>Deter;
            for (int i=0; i <Deter.size(); i++)  Deter[i] = toupper(Deter[i]); //ת��Ϊ��д��ĸ
            
            if(Deter=="YES"||Deter=="Y") {goto tiaochu;}
           
            else if(Deter=="NO"||Deter=="N")
            {
                num++;
                break;
            }
            else
            {
                cout<<"������������������;"<<endl;
            }
        }    
    }
tiaochu:
        abs->personArray[abs->m_Size].m_Addr=Person_input.m_Addr;
        
        //����ͨѶ¼������
        abs->m_Size++;
        cout<<"�����ϵ�˳ɹ�;"<<endl;
    }
}

int main ()
{
    int select =0;
    
   //����һ��ͨѶ¼�Ľṹ�����1

   Addressbooks abs;
   abs.m_Size=0;
   //��ʼ��ͨѶ¼�еĽṹ��
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
            cout<<"�˳��ɹ�,��ӭ�´�ʹ��......"<<endl;
            system("pause");
            return 0;

        default:

        cout<<"������������������;"<<endl;
        
        cin>>select;
            break;
        }
    }
    system("pause");
    return 0;

}