#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include <cstdlib>

using namespace std;

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
void normal::SetWages(int wa)    {   wages=wa;       }
int normal::GetWages()           {   return wages;   } 
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
void player::SetChangeMoney(int CM)  {  ChangeMoney=CM;      } 
int player::GetChangeMoney()         {  return ChangeMoney;  }
void player::SetKick(int ki)           {  kick=ki;             }
int player::GetKick()                  {  return kick;         }
void player::SetYears(int ye)          {  years=ye;            }
int player::GetYears()                 {  return years;        }
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
             void addonenormal(normal n);    //����һ��������Ա 
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
void club::SetCname(string Cn)       {   Cname=Cn;       }
string club::GetCname()              {   return Cname;   }
void club::SetCash(int ca)           {   cash=ca;        }
int club::GetCash()                  {   return cash;    }
int club::GetNormalNumber()          {   return ClubNormal.size();  }
int club::GetPlayerNumber()          {   return ClubPlayer.size();  }
player club::GetPlayer(int num1)     {   return ClubPlayer.at(num1);  }
normal club::GetNormal(int num3)     {   return ClubNormal.at(num3);  }
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

void check(vector<club> cv2);
vector<player> search(vector<club> cv,string refer);
int value(char op1,int num1,int num2);
vector<club> readfile();
void writefile(vector<club> cv);
int main()
{
	 //�����׽���
	 WORD myVersionRequest;
	 WSADATA wsaData;
	 myVersionRequest=MAKEWORD(1,1);
	 int err;
	 err=WSAStartup(myVersionRequest,&wsaData);
	 SOCKET serSocket=socket(AF_INET,SOCK_STREAM,0);//�����˿�ʶ���׽���
	 //��Ҫ�󶨵Ĳ���
	 SOCKADDR_IN addr;
	 addr.sin_family=AF_INET;
	 addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//ip��ַ
	 addr.sin_port=htons(6000);//�󶨶˿�
	 
	 bind(serSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR));//�ƶ����ص�ַ�������
	 listen(serSocket,5);//���еڶ������������ܹ����յ�����������
	 SOCKADDR_IN clientsocket;
	 int len=sizeof(SOCKADDR);
	 
	 SOCKET serConn=accept(serSocket,(SOCKADDR*)&clientsocket,&len);//������ﲻ��accept����conection�Ļ������ͻ᲻�ϵļ���
	 
	 if (!err)
		cout<<"�Ѵ��׽���\n"<<endl;  
	 else
	 {
	  //��һ�����׽���
	  cout<<"Ƕ����δ��!"<<endl;
	  return 0;
     }
     
     int i=0;
     int j=0,k=0;
     int flag=-1;
     int cash1=0;
     int cash2=0;
     vector<club> cv1; 
     char receiveBuf[100];
     char c[100];//����
     string s;
     player player1;
     player player2;
     vector<player> Pv;
     club cb;
     club c1;
     club c2;
     club c3;
     club c4;
     string cN;
     string pN;
            
     //club cB;
     //club cS;
    
     cv1=readfile();
     if(cv1.size()==0)
     {
		 cout<<"�ļ��ǿյģ��ȴ�������ӣ�"<<endl;
		 c1=cb.AddClub();
         cv1.push_back(c1);
         writefile(cv1);
     }	 
	 else
	 {
		int choice=0;
	     cout<<"ϵͳ���Ѿ��о��ֲ����ļ��ˣ�\n"<<endl;
		 while(choice!=-1)
		 {
			 cout<<"��������Ҫ���еĲ�����"<<endl;
			cout<<"��1�����  ��2����ѯ  ��3�����տͻ�������"<<endl;
			cin>>choice;
			if(choice==1)
			{
				 c1=cb.AddClub();
				cv1.push_back(c1);
				writefile(cv1);
			 }
			 else
				if(choice==2)
					check(cv1);
			 else
			 {
				cout<<"���ڵȴ�����˷����������Ժ�......"<<endl;
	  
				recv(serConn,receiveBuf,strlen(receiveBuf)+1,0);
				cout<<receiveBuf<<endl;//��������*/
				while(receiveBuf[0]!='-1')
				{
					if(receiveBuf[0]=='5')
					{
     					memset(c, 0, sizeof(c));
						recv(serConn,c,sizeof(c)+1,0);
						cout<<c<<endl;
						Pv=search(cv1,c);
        	 
						memset(c, 0, sizeof(c));
						itoa(Pv.size(),c,10);
					   send(serConn,c,sizeof(c)+1,0);	  
			  
					  for(i=0;i<Pv.size();i++)
 					  {
								player1=Pv.at(i);
								cout<<player1.GetName();				
								memset(c, 0, sizeof (c));
								s=player1.GetName();
								strcat(c,s.c_str());
								send(serConn,c,sizeof(c)+1,0);
			       
								memset(c, 0, sizeof (c));
								itoa(player1.GetAge(),c,10);
								send(serConn,c,sizeof(c)+1,0);
	             
								memset(c, 0, sizeof (c));
								itoa(player1.GetPower(),c,10);
								send(serConn,c,sizeof(c)+1,0);

								memset(c, 0, sizeof (c));
								itoa(player1.GetWages(),c,10);
								send(serConn,c,sizeof(c)+1,0);

								memset(c, 0, sizeof (c));
								itoa(player1.GetChangeMoney(),c,10);
								send(serConn,c,sizeof(c)+1,0);

								memset(c, 0, sizeof (c));
								itoa(player1.GetKick(),c,10);
								send(serConn,c,sizeof(c)+1,0);

								memset(c, 0, sizeof (c));
								itoa(player1.GetYears(),c,10);
								send(serConn,c,sizeof(c)+1,0);
					  }
					 writefile(cv1);
			
					 recv(serConn,receiveBuf,strlen(receiveBuf)+1,0);
					 cout<<receiveBuf<<endl;//��������*/
			 }  
			 else if(receiveBuf[0]=='6')
				   {
						cout<<"��������о��ֲ����£�"<<endl;
						for(j=0;j<cv1.size();j++)
						{
							c2=cv1.at(j);
							cout<<c2.GetCname()<<endl;
						}
						cout<<"����������Ա�ľ��ֲ�����:"<<endl;
						cin>>cN;

						for(j=0;j<cv1.size();j++)
						{
							c4=cv1.at(j);
		   					if(cN==c4.GetCname())
							{    
								cout<<"�˾��ֲ�������ԱΪ:"<<endl;
								for(i=0;i<c4.GetPlayerNumber();i++)   //�����˾��ֲ�
								{
									player2=c4.GetPlayer(i);
									cout<<"����:"<<player2.GetName()<<endl;
									cout<<"ת���:"<<player2.GetChangeMoney()<<endl;
								}
								cout<<"������Ҫ�����Ա"<<endl;
								cin>>pN;
								flag=j;
								for(k=0;k!=c4.GetPlayerNumber();k++)//����Ҫ�����ֲ���������Ա
								{   
									 player2=c4.GetPlayer(k);
									if(pN==player2.GetName())
									{
										cout<<"ת���:"<<player2.GetChangeMoney()<<endl;
										memset(c, 0, sizeof(c));
										recv(serConn,c,sizeof(c)+1,0);
										cout<<"�ͻ�����������Ա�ľ��ֲ�����Ϊ��"<<c<<endl;
										memset(c, 0, sizeof(c));
										recv(serConn,c,sizeof(c)+1,0);
										cout<<"���ֲ��ֽ�Ϊ��"<<c<<endl;
										cash1=atoi(c);
										 if(cash1 >= player2.GetChangeMoney())
										{
											cout<<"�ɹ�����һ����Ա����"<<endl;
											send(serConn,"1",sizeof("1")+1,0);
                          
											memset(c, 0, sizeof (c));
											s=player2.GetName();
											strcat(c,s.c_str());
											send(serConn,c,sizeof(c)+1,0);
					       
											memset(c, 0, sizeof (c));
											itoa(player2.GetAge(),c,10);
											send(serConn,c,sizeof(c)+1,0);
			             
											memset(c, 0, sizeof (c));
											itoa(player2.GetPower(),c,10);
											send(serConn,c,sizeof(c)+1,0);

											memset(c, 0, sizeof (c));
											itoa(player2.GetWages(),c,10);
											send(serConn,c,sizeof(c)+1,0);

											memset(c, 0, sizeof (c));
											itoa(player2.GetChangeMoney(),c,10);
											send(serConn,c,sizeof(c)+1,0);

											memset(c, 0, sizeof (c));
											itoa(player2.GetKick(),c,10);
											send(serConn,c,sizeof(c)+1,0);

											memset(c, 0, sizeof (c));
											itoa(player2.GetYears(),c,10);
											send(serConn,c,sizeof(c)+1,0);
                          
											cash2=c4.GetCash();
											cash2=cash2 + player2.GetChangeMoney();
						     
											cv1.at(flag).SetCash(cash2);
											cout<<c4.GetCname()<<"���ھ��ֲ����ֽ�"<<cv1.at(flag).GetCash()<<endl;

											cv1.at(flag).deleteplayer(k);//ɾ����Ա
											cout<<"��ɾ��"<<pN<<"����Ϣ"<<endl;
										}//end if
								  else
								  { 
									  cout<<"��Աת���̫�ߣ�����׬��Ǯ����ɣ�"<<endl;
									  send(serConn,"0",strlen("0")+1,0);
								  }//end else
							  }//end if
						  }//end for
					   }//end if	
				   }//end for
				}//end if
          writefile(cv1); 		
		  
		  recv(serConn,receiveBuf,strlen(receiveBuf)+1,0);
		  cout<<receiveBuf<<endl;//��������*/
		}//end while
	}//end else
		system("pause");	
	}//end while
	}
	  closesocket(serConn);//�ر�
	  WSACleanup();//�ͷ���Դ�Ĳ���
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

vector<player> search(vector<club> cv,string refer)
{
     //string refer;
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
     
     for(i=0;i<refer.size();i++)
     {
         ch=refer[i]; 
         if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
         {
            st[j]=st[j]+ch;       
         }
          
         else 
         {
              if((ch=='>')||(ch=='<')||ch=='=')
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
                                   val=0;
                            }
                       }
                   }
             
                   if(val==0)
                        break;
             }
             if(val==1)
             {
                cout<<pla.GetName()<<"��������\n"<<endl;
                suc=1;
                pv.push_back(pla);
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
             if(num1=num2)
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

