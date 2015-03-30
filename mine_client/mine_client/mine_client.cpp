#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;

#include <WINSOCK2.H>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

#include <WINSOCK2.H>
#include <stdio.h>
#pragma comment(lib,"ws2_32.lib")

class normal                //��ͨ������Ա�� 
{
      public:
            normal():age(0),power(0),wages(0){}        //���캯�� 
            ~normal();        //�������� 
            void SetName(string na); //������������ 
            string GetName();//��ȡ�������� 
            void SetAge(int ag);//�������亯��
            int  GetAge();//��ȡ���亯��
            void SetPower(int po);//������������ 
            int  GetPower();//��ȡ��������
            void SetWages(int wa);//������н����
            int GetWages();//��ȡ��н���� 
            normal AddNormal();
      private:                     //˽�����ݳ�Ա 
              string name;
              int age;                                                   
              int power;
              int wages;
};
normal::~normal(){}
void normal::SetName(string na)    {   name=na;        }
string normal::GetName()           {   return name;    }
void normal::SetAge(int ag)        {   age=ag;         }
int normal::GetAge()               {   return age;     }
void normal::SetPower(int po)      {   power=po;       }
int normal::GetPower()             {   return power;   }
void normal::SetWages(int wa)      {   wages=wa;       }
int normal::GetWages()             {   return wages;   } 
normal normal::AddNormal()   //���һ��������Ա
{
     string na;
     int ag;
     int po;
     int wa;
     normal N;
     cout<<"����:  ";
     cin>>na;
     N.SetName(na);
     cout<<"����:  ";
     cin>>ag;
     N.SetAge(ag);
     cout<<"����:(1�������̣�2������������3�������): ";
     cin>>po;
     N.SetPower(po);
     cout<<"��н:  ";
     cin>>wa;
     N.SetWages(wa);
     return N;
}

class player:public normal                //��Ա�� 
{ 
      public:
             player():ChangeMoney(0),kick(0),years(0){}
             ~player();
             void SetChangeMoney(int Cm);     //����ת��� 
             int GetChangeMoney();            //��ȡת��Ѻ���
             void SetKick(int ki);         //���ý����������� 
             int GetKick();                //��ȡ������������
             void SetYears(int ye);   //���÷������� 
             int GetYears();          //��ȡ�������޺��� 
             player AddPlayer();
       private:    
              int ChangeMoney;      //ת��� 
              int kick;        //�������� 
              int years;    //��������
};
player ::~player(){}
void player::SetChangeMoney(int CM)    {  ChangeMoney=CM;      } 
void player::SetKick(int ki)           {  kick=ki;             }
void player::SetYears(int ye)          {  years=ye;            }
int player::GetYears()                 {  return years;        }
int player::GetChangeMoney()           {  return ChangeMoney;  }
int player::GetKick()                  {  return kick;         }
player player::AddPlayer()    //���һ����Ա 
{
     string na;
     int ag;
     int po;
     int wa;
     int CM;
     int ki;
     int ye;
     player P;
     
     cout<<"��Ա��:  ";
     cin>>na;
     P.SetName(na);
     cout<<"����:  ";
     cin>>ag;
     P.SetAge(ag);
     cout<<"����(1����ǰ�棬2���������3�����Ž���4�����г�):  ";
     cin>>po;
     P.SetPower(po);    
     cout<<"��н:  ";   
     cin>>wa;
     P.SetWages(wa);
     cout<<"ת���:  ";
     cin>>CM;
     P.SetChangeMoney(CM);
     cout<<"��������:  ";
     cin>>ki;
     P.SetKick(ki);
     cout<<"��������:  ";
     cin>>ye;
     P.SetYears(ye);    
     return P;               
}

class club              //���ֲ��� 
{
      public:
             club():cash(0){} //��ʼ�����ֲ�����
             ~club();
             void SetCname(string Cn);   //�������ƺ���
             string GetCname();          //��ȡ���ƺ��� 
             void SetCash(int ca);     //�����ֽ��� 
             int GetCash();            //��ȡ�ֽ���
             club AddClub();            //���һ�����ֲ� 
             int GetNormalNumber();     //��ȡ���ֲ�����������Ա���� 
             int GetPlayerNumber();     //��ȡ���ֲ�������Ա���� 
             void SetPlayer(int num);   //��ȡ��Ա��Ϣ������ 
             void SetNormal(int num2);    //��ȡ������Ա��Ϣ������ 
             player GetPlayer(int num1);  //�õ�һ����Ա�� 
             normal GetNormal(int num3);  //�õ�һ��������Ա�� 
             void addoneplayer(player p);   //����һ����Ա
             void addonenormal(normal n);
             void deleteplayer(int num4);     //ɾ��һ����Ա 
             void clearplayer();
             void clearnormal();
      private:
              string Cname;         //���ֲ����� 
              int cash;           //���ֲ��ֽ� 
              vector<player> ClubPlayer;   //������Ա    
              vector<normal> ClubNormal;    //����������Ա  
};
club ::~club(){}
string club::GetCname()              {   return Cname;   }
player club::GetPlayer(int num1)     {   return ClubPlayer.at(num1);  }
normal club::GetNormal(int num3)     {   return ClubNormal.at(num3);  }
int club::GetCash()                  {   return cash;    }
int club::GetNormalNumber()          {   return ClubNormal.size();  }
int club::GetPlayerNumber()          {   return ClubPlayer.size();  }
void club::SetCash(int ca)           {   cash=ca;        }
void club::SetCname(string Cn)       {   Cname=Cn;       }
void club::clearplayer()             {   ClubPlayer.clear();   }
void club::clearnormal()             {   ClubNormal.clear();   }
void club::addoneplayer(player p)    {   ClubPlayer.push_back(p);     }
void club::addonenormal(normal n)    {   ClubNormal.push_back(n);     }
void club::deleteplayer(int num4)    {   ClubPlayer.erase(ClubPlayer.begin()+num4); }
void club::SetNormal(int num2)       
{
     normal n2,n3;
     for(int i=0;i<num2;i++)
     {
             cout<<"���ǵ�"<<i+1<<"��������Ա\n"; 
             n2=n3.AddNormal();
             ClubNormal.push_back(n2);
     }
}
void club::SetPlayer(int num)
{ 
     player p2,p3;
     for(int i=0;i<num;i++)   
     {
             cout<<"\n���ǵ�"<<i+1<<"����Ա\n";
             p2=p3.AddPlayer();
             ClubPlayer.push_back(p2);
     }
       
}
club club::AddClub()//���һ�����ֲ� 
{
     int CPnum=0;
     int CNnum=0;
     int i=1,j=1;
     string Cn;
     int ca;
     club C;
     player P;
     player p1;
     normal N;
     normal N1;

     cout<<"��������ֲ�����:  ";
     cin>>Cn;
     C.SetCname(Cn);
     cout<<"���ֲ����ֽ�:  ";
     cin>>ca;
     C.SetCash(ca); 
     cout<<"\n���ֲ���������Ա��:  ";
     cin>>CNnum;
     ClubNormal.clear();//���������Ա������ 
     C.SetNormal(CNnum);
     cout<<"\n���ֲ�����Ա��:  ";
     cin>>CPnum;
     ClubPlayer.clear();    //�����Ա������  
     C.SetPlayer(CPnum);
     return C;
}


void input();
void check(vector<club> cv2);
vector<club> sell(vector<club> cv);
club change(club Cl);
vector<player> search(vector<club> cv);
int value(char op1,int num1,int num2);
vector<club> readfile();
void writefile(vector<club> cv);
int main()
{
	//���弰��ʼ��
	 int err;
	 WORD versionRequired;
	 WSADATA wsaData;
	 versionRequired=MAKEWORD(1,1);
	 err=WSAStartup(versionRequired,&wsaData);//Э���İ汾��Ϣ
	 SOCKET clientSocket=socket(AF_INET,SOCK_STREAM,0);
	 SOCKADDR_IN clientsock_in;
	 clientsock_in.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	 clientsock_in.sin_family=AF_INET;
	 clientsock_in.sin_port=htons(6000);
     connect(clientSocket,(SOCKADDR*)&clientsock_in,sizeof(SOCKADDR));//��ʼ����
     
     if (!err)
	 {
	      printf("�ͻ���Ƕ�����Ѿ���!\n");
	 }
	 else
	 {
	      printf("�ͻ��˵�Ƕ���ִ�ʧ��!\n");
	      return 0;
     }

       int xx=0;
     //int i;
     int num=0;
     int nu=0;
     int buyer=0,seller=0;
     int num1=0;
	 int num2=0,num3=0;
	 int cash3=0;
     vector<club> cv1; 
     vector<player> pv1;
     club c;
     club c1;
     club c3;
     club c4;
     club cB;
     club cS;

	 char re[100];
	 string refer;
	 string s_temp;
     int i=0,k=0,n=0;
     int j=-1;
     int Num[20]={0};
     int val=1;
     int suc=0;
     char op[20]={0};
     char ch;
     string st[20];
     club clu;
     player pla;
	 player pr;
     vector<player> pv;
    
     cv1=readfile();
     if(cv1.size()==0)
	 {
		cout<<"�ļ��ǿյģ��ȴ�������ӣ�"<<endl;
	 }
	 else
		cout<<"ϵͳ���Ѿ��о��ֲ����ļ��ˣ�\n"<<endl;
		
     cout<<"��ѡ��Ҫʵ��ʲô����:"<<endl;
     cout<<"1--����һ�����ֲ�"<<endl;
     cout<<"2--ɾ��һ�����ֲ�"<<endl;
     cout<<"3--�鿴���ֲ�"<<endl;
     cout<<"4--�ı���ֲ���Ϣ"<<endl;
     cout<<"5--����һ����Ա����"<<endl;
     cout<<"6--����һ����Ա"<<endl;
     cout<<"-1--�˳�\n"<<endl;
     
     while(xx!=-1)
     {
           cout<<"\n��ѡ��Ҫʵ��ʲô����:"<<endl;       
           cin>>xx;
           switch(xx)
           {
               case 1:
                     c1=c.AddClub();
                     cv1.push_back(c1);
                     writefile(cv1);
                     break;
              case 2:
                     cout<<"����������ɾ���ľ��ֲ���ţ�";
                     cin>>num1;
                     cv1.erase(cv1.begin()+num1);
                     writefile(cv1);
                     cout<<"ɾ���ɹ�~~"<<endl;
                     break;
              case 3:
                     check(cv1);
                     break;
              case 4:
                     cout<<"������Ҫ�޸ĵľ��ֲ���ţ�";
                     cin>>nu;
                     c3=cv1.at(nu);
                     for(i=0;i<cv1.size();i++)  
                     {
                          c4=cv1.at(i);
                          if(c4.GetCname()==c3.GetCname())
                             cv1.erase(cv1.begin()+i);
                     } 
                     c3=change(c3);
                     cv1.push_back(c3);
                     writefile(cv1);
                     cout<<"���ĳɹ�~"<<endl;
                     break;
              case 5:
				  send(clientSocket,"5",strlen("5")+1,0);
					 cout<<"�������ѯ���ʽ:";
					  cin>>refer;
				  for(i=0;i<refer.size();i++)
					{
						ch=refer[i]; 
						if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
						{
							st[j]=st[j]+ch;       
						}
          
						else 
						{
							if((ch=='>')||(ch=='<')||(ch=='='))
							op[j]=ch; 
							else if((ch>='0')&&(ch<='9'))
							Num[j]=Num[j]*10+(int)ch-48;
						}   
						if(ch=='@')
							j++;
					}
                
					for(i=0;i<cv1.size();i++)
					{
						clu=cv1.at(i);
						 for(k=0;k<clu.GetPlayerNumber();k++)
						{
							pla=clu.GetPlayer(k); 
							for(n=0;n<=j;n++)
							{
							 //  cout<<st[n]<<""<<endl;
								if(st[n]=="age")
								 val=value(op[n],pla.GetAge(),Num[n]);
								else
								{
									if(st[n]=="years")
									val=value(op[n],pla.GetYears(),Num[n]);
									else 
									{
										if(st[n]=="kick")
											 val=value(op[n],pla.GetKick(),Num[n]);
										else 
										{
											 if(st[n]=="wages")
											 val=value(op[n],pla.GetWages(),Num[n]);
											else 
											{
												val=0;
												cout<<"�������������������������:"<<endl;
											}
										}
									}
								}            
								if(val==0)	
									break;
							 }
							 if(val==1)
							 {
								 cout<<pla.GetName()<<"��������\n"<<endl;
								pv.push_back(pla);
								suc=1;
							}
						}
					 }
				if(suc==0)
					cout<<"�ͻ���û�з�����������Ա"<<endl;
				
                   //  Pv=search(cv1,s);
                     
                     memset(re, 0, sizeof (re)); 
		             strcat(re,refer.c_str()); 
                     send(clientSocket,re,sizeof(re),0);
					 memset(re, 0, sizeof (re));
                     recv(clientSocket,re,sizeof(re)+10,0);
		             sscanf(re, "%d", &num3);
		             cout<<"����˷�����Ϣ����"<<endl;
		             if(num3==0) 
			         cout<<"�����û�з�����������Ա"<<endl;
		             else
		             {     
                           cout<<"������������Ա�У�"<<endl;
	                       for(i=0;i<num3;i++)    
			               {
				           memset(re, 0, sizeof (re));
						    recv(clientSocket,re,sizeof(re)+1,0);
				           cout<<"\n��Ա������"<<re<<endl;
			    
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"���䣺"<<re<<endl;

                           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"������"<<re<<endl;

				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"��н��"<<re<<endl;
                 
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"ת��ѣ�"<<re<<endl;

				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"����������"<<re<<endl;

				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"�������ޣ�"<<re<<endl;

                           } 
			               cout<<"��ѯ�����"<<endl;
                           }
					
                     break;
              case 6:
                    send(clientSocket,"6",strlen("6")+1,0);
                     cout<<"�ͻ�����������"<<cv1.size()<<"�����ֲ�"<<endl; 
       
	                 cout<<"����������Ա�ľ��ֲ���ţ�"<<endl;
		             cin>>num2;
		             
		             cout<<"ԭ����"<<cv1.at(num2).GetCname()<<"������Ա"<<endl;
					   memset(re, 0, sizeof (re));
						     s_temp=cv1.at(num2).GetCname();
						     strcat(re,s_temp.c_str());
						     send(clientSocket,re,sizeof(re)+1,0);
		             cout<<"�˾��ֲ����ֽ�Ϊ:"<<cv1.at(num2).GetCash()<<endl;
					 
		             cash3=cv1.at(num2).GetCash();
					 memset(re, 0, sizeof (re));
		            _itoa(cash3, re, 10);
                     send(clientSocket,re,sizeof(re)+1,0);
                 
					 memset(re, 0, sizeof (re));
                     recv(clientSocket,re,sizeof(re)+1,0);
                     
                      if(re[0]=='1')
		              {
			               cout<<"���׳ɹ���"<<endl;
                           memset(re, 0, sizeof (re));
				           recv(clientSocket,re,sizeof(re)+1,0);
				           cout<<"��Ա������"<<re<<endl;
				           pr.SetName(re);
				
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
		                   cout<<"���䣺"<<re<<endl;
			               int age1=0;
                           sscanf(re, "%d", &age1);
				           pr.SetAge(age1);
			    
                           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"������"<<re<<endl;
				           int power1=0;
                           sscanf(re, "%d", &power1);
				           pr.SetPower(power1);
			    
    				       memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"��н��"<<re<<endl;
				           int wages1=0;
                           sscanf(re, "%d", &wages1);
			               pr.SetWages(wages1);
			      
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"ת��ѣ�"<<re<<endl;
				           int changemoney1=0;
                           sscanf(re, "%d", &changemoney1);
				           pr.SetChangeMoney(changemoney1);
			    
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"��������"<<re<<endl;
				           int kick=0;
                           sscanf(re, "%d", &kick);
				           pr.SetKick(kick);
                 
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"��������:"<<re<<endl;
                           int years1=0;
                           sscanf(re, "%d", &years1);
				           pr.SetYears(years1);
				
				           cv1.at(num2).addoneplayer(pr);
				           cash3=cash3-pr.GetChangeMoney();
				           cv1.at(num2).SetCash(cash3);
				           cout<<"������ɺ�ľ��ֲ��ֽ�Ϊ:"<<cv1.at(num2).GetCash()<<endl;

		   }
		    else if(re[0]=='0')
			   cout<<"����ʧ��"<<endl;
            writefile(cv1);
                     break;
			case -1:
				send(clientSocket,"-1",strlen("-1")+1,0);
				cout<<"ллʹ�ã�";
				system("pause");
				exit(0);
				break;
             }   
	 }
	system("pause");
}

void check(vector<club> cv2)
{
       int i=0;
       string Cna;
       int number=0;
       club c;
       player p;
       normal n;
       
       cout<<"����"<<cv2.size()<<"�����ֲ�"<<endl;
       if(cv2.size()==0)
          cout<<"��ǰû�о��ֲ���Ϣ,���������~"<<endl;
       else
       {
          cout<<"��������Ҫ�鿴�ľ��ֲ��ţ�\n";
          cin>>number;
          c=cv2.at(number);
          cout<<"���ֲ�����:"<<c.GetCname()<<endl;
          cout<<"�ֽ�:"<<c.GetCash()<<endl;
          cout<<"����������Ա��"<<c.GetNormalNumber()<<"����"<<endl;
          for(i=0;i<c.GetNormalNumber();i++)
          {
                n=c.GetNormal(i);
                cout<<"\n������"<<n.GetName()<<endl;
                cout<<"���䣺"<<n.GetAge()<<endl;
                cout<<"������"<<n.GetPower()<<endl;
                cout<<"��н��"<<n.GetWages()<<endl;
          }
          cout<<"������Ա��"<<c.GetPlayerNumber()<<"����"<<endl;
       
          for(i=0;i<c.GetPlayerNumber();i++)
          {
                p=c.GetPlayer(i);
                cout<<"\n������"<<p.GetName()<<endl;
                cout<<"���䣺"<<p.GetAge()<<endl;
                cout<<"������"<<p.GetPower()<<endl;
                cout<<"��н��"<<p.GetWages()<<endl;
                cout<<"ת��ѣ�"<<p.GetChangeMoney()<<endl;
                cout<<"����������"<<p.GetKick()<<endl;
                cout<<"�������ޣ�"<<p.GetYears()<<endl;
          }
       }              
}
club change(club Cl)
{
     string Cn;
     int ca=0;
     int CNnum=0;
     int CPnum=0;
     
     cout<<"��������ֲ�����:  ";
     cin>>Cn;
     Cl.SetCname(Cn);
     cout<<"���ֲ����ֽ�:  ";
     cin>>ca;
     Cl.SetCash(ca); 
     cout<<"\n���ֲ���������Ա��:  ";
     cin>>CNnum;
     Cl.clearnormal();//���������Ա������ 
     Cl.SetNormal(CNnum);
     cout<<"\n���ֲ�����Ա��:  ";
     cin>>CPnum;
     Cl.clearplayer();    //�����Ա������  
     Cl.SetPlayer(CPnum);
     return Cl;
}
vector<club> sell(vector<club> cv)     //����һ����Ա 
{
     int num=0;
     int j=0;
     int i=0;
     int buyer=0;
     int seller=0;
     int success=0;
     int cas1=0;
     int cas2=0;
     player p1;
     club cB;
     club cS;
     club cM;
     
     if(cv.size()<2)
     cout<<"��ǰ�����������ֲ������ܽ�������~��"<<endl;
     else
     {
          cout<<"�������������������ֲ�֮��������Ա�أ�"<<endl;
          cin>>buyer>>seller;
         // cin>>seller;
          cB=cv.at(buyer);
          cS=cv.at(seller);
          for(i=0;i<cv.size();i++)  
          {
              cM=cv.at(i);
              if(cM.GetCname()==cB.GetCname())
                     cv.erase(cv.begin()+i);
          } 
          for(i=0;i<cv.size();i++)
          {
              cM=cv.at(i);
              if(cM.GetCname()==cS.GetCname())
                     cv.erase(cv.begin()+i); 
          }
           cout<<"ԭ����"<<cB.GetCname()<<"���"<<cS.GetCname()<<"��һ����Ա"<<endl;
           cout<<"���Ե�..."<<endl; 
                     
           num=cS.GetPlayerNumber();
           for(j=0;j<num;j++)
           {
              p1=cS.GetPlayer(j);
              if(cB.GetCash()>=p1.GetChangeMoney())
              {
                    cB.addoneplayer(p1); 
                    cS.deleteplayer(j);
                    cas1=cB.GetCash();
                    cas2=cS.GetCash();
                    cas1-=p1.GetChangeMoney();
                    cas2+=p1.GetChangeMoney();
                    cS.SetCash(cas2);
                    cB.SetCash(cas1); 
                    cout<<"�����ɹ���"<<endl;
                    success=1; 
              } 
           }
              cv.push_back(cB);
              cv.push_back(cS);
           if(success==0)
              cout<<"��Ա��ת���̫���ˣ�����׬��Ǯ������ɣ�"<<endl;
     }
           return cv;
}
vector<player> search(vector<club> cv)
{
     string refer;
     int i=0,k=0,n=0;
     int j=-1;
     int num[20]={0};
     int val=1;
     int suc=0;
     char op[20]={0};
     char ch;
     string st[20];
     club clu;
     player pla;
     vector<player> pv;
     
     cout<<"�������ѯ���ʽ:";
     cin>>refer;
     for(i=0;i<refer.size();i++)
     {
         ch=refer[i]; 
         if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
         {
            st[j]=st[j]+ch;       
         }
          
         else 
         {
              if((ch=='>')||(ch=='<')||(ch=='='))
                 op[j]=ch; 
              else if((ch>='0')&&(ch<='9'))
                     num[j]=num[j]*10+(int)ch-48;
         }   
         if(ch=='@')
                j++;
     }
                
     for(i=0;i<cv.size();i++)
     {
         clu=cv.at(i);
         for(k=0;k<clu.GetPlayerNumber();k++)
         {
             pla=clu.GetPlayer(k); 
             for(n=0;n<=j;n++)
             {
                 //  cout<<st[n]<<""<<endl;
                   if(st[n]=="age")
                         val=value(op[n],pla.GetAge(),num[n]);
                   else
                   {
                       if(st[n]=="years")
                          val=value(op[n],pla.GetYears(),num[n]);
                       else 
                       {
                            if(st[n]=="kick")
                               val=value(op[n],pla.GetKick(),num[n]);
                            else 
                            {
                                 if(st[n]=="wages")
                                   val=value(op[n],pla.GetWages(),num[n]);
                                 else 
                                 {
                                     val=0;
                                     cout<<"�������������������������:"<<endl;
                                 }
                            }
                       }
                   }            
                   if(val==0)
                        break;
             }
             if(val==1)
             {
                cout<<pla.GetName()<<"��������\n"<<endl;
                pv.push_back(pla);
                suc=1;
             }
        }
     }
     if(suc==0)
        cout<<"û�з�����������Ա"<<endl;
     return pv;
}

int value(char op1,int num1,int num2)
{
     
     switch(op1)
     {
        case '>':
             if(num1>num2)
               return 1;
             else return 0;
             break;
        case '<':
             if(num1<num2)
               return 1;
             else return 0;
        case '=':
             if(num1==num2)
                return 1;
             else 
                return 0;
     }
}
void writefile(vector<club> cv)
{
	  ofstream put;
	  put.open("vectorclub.txt",ios::trunc); //ios::trunc��ʾ�ڴ��ļ�ǰ���ļ����,������д��,�ļ��������򴴽�
      
      int i=0;
      int j=0; 
      club cl2;
      player pl2;
      normal nor2;
	  put<<cv.size()<<endl;
	  
      for(i=0;i<cv.size();i++)
	  {  
           cl2=cv.at(i); 
		   put<<cl2.GetCname()<<endl;
	       put<<cl2.GetCash()<<endl;
	       put<<cl2.GetNormalNumber()<<endl;
	       for(j=0;j<cl2.GetNormalNumber();j++)
		   {
                nor2=cl2.GetNormal(j);
			    put<<nor2.GetName()<<endl;
			    put<<nor2.GetAge()<<endl;
			    put<<nor2.GetPower()<<endl;
			    put<<nor2.GetWages()<<endl;
           }
		   put<<cl2.GetPlayerNumber()<<endl;
		   for(j=0;j<cl2.GetPlayerNumber();j++)
		   {
                pl2=cl2.GetPlayer(j);
			    put<<pl2.GetName()<<endl;
			    put<<pl2.GetAge()<<endl;
			    put<<pl2.GetPower()<<endl;
			    put<<pl2.GetWages()<<endl;
		        put<<pl2.GetChangeMoney()<<endl;
			    put<<pl2.GetKick()<<endl;
			    put<<pl2.GetYears()<<endl;
			    
			   
           }
	}	
    put.close();//�ر��ļ�
}
vector<club> readfile()
{
    int i=0,j=0,k=0;
	int Cnum=0,Pnum=0,Nnum=0;
    int age1=0,age2=0;
    int power1=0,power2=0;
    int wages1=0,wages2=0;
	int kick1=0,years1=0;
	int cash1=0;
	int changeMoney1=0;
    char buff[100]={0}; 
    vector<club> cv;
    club cl3;
    player pl3;
    normal nor3;
    
    ifstream  fout;
	fout.open( "vectorclub.txt"); 
 
	if(fout.fail())
    {
        cout<<"�ļ�������.��Ҫ����һ��."<<endl;
        fout.close();
    }
	else
	{
		fout.getline(buff,100);
		
	    while(!fout.eof())
	    {   
            sscanf(buff, "%d", &Cnum);

		    for(i=0;i<Cnum;i++)
		    {    
                 fout.getline(buff,100);
			     cl3.SetCname(buff);  
			     
                 fout.getline(buff,100);                          
                 sscanf(buff, "%d", &cash1);                 
                 cl3.SetCash(cash1);
                 
                 fout.getline(buff,100);
                 sscanf(buff, "%d", &Nnum);
                 for(j=0;j<Nnum;j++)
			     {  
                    fout.getline(buff,100);
				    nor3.SetName(buff);
				    
				    fout.getline(buff,100); 				  
				    sscanf(buff, "%d", &age1);;
				    nor3.SetAge(age2);
				    
                    fout.getline(buff,100);                
                    sscanf(buff, "%d", &power2);
		   	        nor3.SetPower(power2);
		   	        
                    fout.getline(buff,100);                   
                    sscanf(buff, "%d", &wages2);
		   	        nor3.SetWages(wages2);
		   	        
		   	        cl3.addonenormal(nor3);
		         } 
                 fout.getline(buff,100);            
                 sscanf(buff, "%d", &Pnum);
                 for(j=0;j<Pnum;j++) 
			     {    
                     fout.getline(buff,100);
				     pl3.SetName(buff);
				     
				     fout.getline(buff,100);                      
                     sscanf(buff, "%d", &age1);
                     pl3.SetAge(age1);
                     
                     fout.getline(buff,100);                   
                     sscanf(buff, "%d", &power1);
				     pl3.SetPower(power1);
				     
				     fout.getline(buff,100);
                     sscanf(buff, "%d", &wages1);
				     pl3.SetWages(wages1);
				     
                     fout.getline(buff,100);                    
                     sscanf(buff, "%d", &changeMoney1);
				     pl3.SetChangeMoney(changeMoney1);         
                    
                     fout.getline(buff,100);
                     sscanf(buff, "%d", &kick1);
			         pl3.SetKick(kick1);
			         
                     fout.getline(buff,100);
                     sscanf(buff, "%d", &years1);
				     pl3.SetYears(years1);
                   
                     cl3.addoneplayer(pl3);             
                   }
			 cv.push_back(cl3);
			 cl3.clearplayer();
			 cl3.clearnormal();
		 }
         fout.getline(buff,100);
      } 
       fout.close(); 
     }	
   return cv;
}



