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

class normal                //普通行政人员类 
{
      public:
            normal():age(0),power(0),wages(0){}        //构造函数 
            ~normal();        //析构函数 
            void SetName(string na); //设置姓名函数 
            string GetName();//提取姓名函数 
            void SetAge(int ag);//设置年龄函数
            int  GetAge();//提取年龄函数
            void SetPower(int po);//设置能力函数 
            int  GetPower();//提取能力函数
            void SetWages(int wa);//设置年薪函数
            int GetWages();//提取年薪函数 
            normal AddNormal();
      private:                     //私有数据成员 
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
normal normal::AddNormal()   //添加一个行政人员
{
     string na;
     int ag;
     int po;
     int wa;
     normal N;
     cout<<"姓名:  ";
     cin>>na;
     N.SetName(na);
     cout<<"年龄:  ";
     cin>>ag;
     N.SetAge(ag);
     cout<<"能力:(1代表助教，2代表主教练，3代表后勤): ";
     cin>>po;
     N.SetPower(po);
     cout<<"年薪:  ";
     cin>>wa;
     N.SetWages(wa);
     return N;
}

class player:public normal                //球员类 
{ 
      public:
             player():ChangeMoney(0),kick(0),years(0){}
             ~player();
             void SetChangeMoney(int Cm);     //设置转会费 
             int GetChangeMoney();            //提取转会费函数
             void SetKick(int ki);         //设置进球总数函数 
             int GetKick();                //提取进球总数函数
             void SetYears(int ye);   //设置服务年限 
             int GetYears();          //提取服务年限函数 
             player AddPlayer();
       private:    
              int ChangeMoney;      //转会费 
              int kick;        //进球总数 
              int years;    //服务年限
};
player ::~player(){}
void player::SetChangeMoney(int CM)    {  ChangeMoney=CM;      } 
void player::SetKick(int ki)           {  kick=ki;             }
void player::SetYears(int ye)          {  years=ye;            }
int player::GetYears()                 {  return years;        }
int player::GetChangeMoney()           {  return ChangeMoney;  }
int player::GetKick()                  {  return kick;         }
player player::AddPlayer()    //添加一个球员 
{
     string na;
     int ag;
     int po;
     int wa;
     int CM;
     int ki;
     int ye;
     player P;
     
     cout<<"球员名:  ";
     cin>>na;
     P.SetName(na);
     cout<<"年龄:  ";
     cin>>ag;
     P.SetAge(ag);
     cout<<"能力(1代表前锋，2代表后卫，3代表门将，4代表中场):  ";
     cin>>po;
     P.SetPower(po);    
     cout<<"年薪:  ";   
     cin>>wa;
     P.SetWages(wa);
     cout<<"转会费:  ";
     cin>>CM;
     P.SetChangeMoney(CM);
     cout<<"进球总数:  ";
     cin>>ki;
     P.SetKick(ki);
     cout<<"服务年限:  ";
     cin>>ye;
     P.SetYears(ye);    
     return P;               
}

class club              //俱乐部类 
{
      public:
             club():cash(0){} //初始化俱乐部属性
             ~club();
             void SetCname(string Cn);   //设置名称函数
             string GetCname();          //提取名称函数 
             void SetCash(int ca);     //设置现金函数 
             int GetCash();            //提取现金函数
             club AddClub();            //添加一个俱乐部 
             int GetNormalNumber();     //提取俱乐部里面行政人员数量 
             int GetPlayerNumber();     //提取俱乐部里面球员数量 
             void SetPlayer(int num);   //存取球员信息到容器 
             void SetNormal(int num2);    //存取行政人员信息到容器 
             player GetPlayer(int num1);  //得到一个球员类 
             normal GetNormal(int num3);  //得到一个行政人员类 
             void addoneplayer(player p);   //增加一个球员
             void addonenormal(normal n);
             void deleteplayer(int num4);     //删除一个球员 
             void clearplayer();
             void clearnormal();
      private:
              string Cname;         //俱乐部名称 
              int cash;           //俱乐部现金 
              vector<player> ClubPlayer;   //其下球员    
              vector<normal> ClubNormal;    //其下行政人员  
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
             cout<<"这是第"<<i+1<<"个行政人员\n"; 
             n2=n3.AddNormal();
             ClubNormal.push_back(n2);
     }
}
void club::SetPlayer(int num)
{ 
     player p2,p3;
     for(int i=0;i<num;i++)   
     {
             cout<<"\n这是第"<<i+1<<"个球员\n";
             p2=p3.AddPlayer();
             ClubPlayer.push_back(p2);
     }
       
}
club club::AddClub()//添加一个俱乐部 
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

     cout<<"请输入俱乐部名称:  ";
     cin>>Cn;
     C.SetCname(Cn);
     cout<<"俱乐部的现金:  ";
     cin>>ca;
     C.SetCash(ca); 
     cout<<"\n俱乐部的行政人员数:  ";
     cin>>CNnum;
     ClubNormal.clear();//清空行政人员容器类 
     C.SetNormal(CNnum);
     cout<<"\n俱乐部的球员数:  ";
     cin>>CPnum;
     ClubPlayer.clear();    //清空球员容器类  
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
	//定义及初始化
	 int err;
	 WORD versionRequired;
	 WSADATA wsaData;
	 versionRequired=MAKEWORD(1,1);
	 err=WSAStartup(versionRequired,&wsaData);//协议库的版本信息
	 SOCKET clientSocket=socket(AF_INET,SOCK_STREAM,0);
	 SOCKADDR_IN clientsock_in;
	 clientsock_in.sin_addr.S_un.S_addr=inet_addr("127.0.0.1");
	 clientsock_in.sin_family=AF_INET;
	 clientsock_in.sin_port=htons(6000);
     connect(clientSocket,(SOCKADDR*)&clientsock_in,sizeof(SOCKADDR));//开始连接
     
     if (!err)
	 {
	      printf("客户端嵌套字已经打开!\n");
	 }
	 else
	 {
	      printf("客户端的嵌套字打开失败!\n");
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
		cout<<"文件是空的，等待您的添加！"<<endl;
	 }
	 else
		cout<<"系统里已经有俱乐部的文件了！\n"<<endl;
		
     cout<<"请选择要实现什么功能:"<<endl;
     cout<<"1--增加一个俱乐部"<<endl;
     cout<<"2--删除一个俱乐部"<<endl;
     cout<<"3--查看俱乐部"<<endl;
     cout<<"4--改变俱乐部信息"<<endl;
     cout<<"5--搜索一个球员属性"<<endl;
     cout<<"6--买卖一个球员"<<endl;
     cout<<"-1--退出\n"<<endl;
     
     while(xx!=-1)
     {
           cout<<"\n请选择要实现什么功能:"<<endl;       
           cin>>xx;
           switch(xx)
           {
               case 1:
                     c1=c.AddClub();
                     cv1.push_back(c1);
                     writefile(cv1);
                     break;
              case 2:
                     cout<<"请输入您想删除的俱乐部编号：";
                     cin>>num1;
                     cv1.erase(cv1.begin()+num1);
                     writefile(cv1);
                     cout<<"删除成功~~"<<endl;
                     break;
              case 3:
                     check(cv1);
                     break;
              case 4:
                     cout<<"请输入要修改的俱乐部编号：";
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
                     cout<<"更改成功~"<<endl;
                     break;
              case 5:
				  send(clientSocket,"5",strlen("5")+1,0);
					 cout<<"请输入查询表达式:";
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
												cout<<"您输入的条件有误，请重新输入:"<<endl;
											}
										}
									}
								}            
								if(val==0)	
									break;
							 }
							 if(val==1)
							 {
								 cout<<pla.GetName()<<"符合条件\n"<<endl;
								pv.push_back(pla);
								suc=1;
							}
						}
					 }
				if(suc==0)
					cout<<"客户端没有符合条件的球员"<<endl;
				
                   //  Pv=search(cv1,s);
                     
                     memset(re, 0, sizeof (re)); 
		             strcat(re,refer.c_str()); 
                     send(clientSocket,re,sizeof(re),0);
					 memset(re, 0, sizeof (re));
                     recv(clientSocket,re,sizeof(re)+10,0);
		             sscanf(re, "%d", &num3);
		             cout<<"服务端返回信息如下"<<endl;
		             if(num3==0) 
			         cout<<"服务端没有符合条件的球员"<<endl;
		             else
		             {     
                           cout<<"符合条件的球员有："<<endl;
	                       for(i=0;i<num3;i++)    
			               {
				           memset(re, 0, sizeof (re));
						    recv(clientSocket,re,sizeof(re)+1,0);
				           cout<<"\n球员姓名："<<re<<endl;
			    
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"年龄："<<re<<endl;

                           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"能力："<<re<<endl;

				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"年薪："<<re<<endl;
                 
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"转会费："<<re<<endl;

				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"进球总数："<<re<<endl;

				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"服务年限："<<re<<endl;

                           } 
			               cout<<"查询已完成"<<endl;
                           }
					
                     break;
              case 6:
                    send(clientSocket,"6",strlen("6")+1,0);
                     cout<<"客户端现在已有"<<cv1.size()<<"个俱乐部"<<endl; 
       
	                 cout<<"请输入买球员的俱乐部编号："<<endl;
		             cin>>num2;
		             
		             cout<<"原来是"<<cv1.at(num2).GetCname()<<"想买球员"<<endl;
					   memset(re, 0, sizeof (re));
						     s_temp=cv1.at(num2).GetCname();
						     strcat(re,s_temp.c_str());
						     send(clientSocket,re,sizeof(re)+1,0);
		             cout<<"此俱乐部的现金为:"<<cv1.at(num2).GetCash()<<endl;
					 
		             cash3=cv1.at(num2).GetCash();
					 memset(re, 0, sizeof (re));
		            _itoa(cash3, re, 10);
                     send(clientSocket,re,sizeof(re)+1,0);
                 
					 memset(re, 0, sizeof (re));
                     recv(clientSocket,re,sizeof(re)+1,0);
                     
                      if(re[0]=='1')
		              {
			               cout<<"交易成功。"<<endl;
                           memset(re, 0, sizeof (re));
				           recv(clientSocket,re,sizeof(re)+1,0);
				           cout<<"球员姓名："<<re<<endl;
				           pr.SetName(re);
				
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
		                   cout<<"年龄："<<re<<endl;
			               int age1=0;
                           sscanf(re, "%d", &age1);
				           pr.SetAge(age1);
			    
                           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"能力："<<re<<endl;
				           int power1=0;
                           sscanf(re, "%d", &power1);
				           pr.SetPower(power1);
			    
    				       memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"年薪："<<re<<endl;
				           int wages1=0;
                           sscanf(re, "%d", &wages1);
			               pr.SetWages(wages1);
			      
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"转会费："<<re<<endl;
				           int changemoney1=0;
                           sscanf(re, "%d", &changemoney1);
				           pr.SetChangeMoney(changemoney1);
			    
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"进球总数"<<re<<endl;
				           int kick=0;
                           sscanf(re, "%d", &kick);
				           pr.SetKick(kick);
                 
				           memset(re, 0, sizeof (re));
			               recv(clientSocket,re,sizeof(re)+1,0);
			               cout<<"服务年限:"<<re<<endl;
                           int years1=0;
                           sscanf(re, "%d", &years1);
				           pr.SetYears(years1);
				
				           cv1.at(num2).addoneplayer(pr);
				           cash3=cash3-pr.GetChangeMoney();
				           cv1.at(num2).SetCash(cash3);
				           cout<<"买卖完成后的俱乐部现金为:"<<cv1.at(num2).GetCash()<<endl;

		   }
		    else if(re[0]=='0')
			   cout<<"交易失败"<<endl;
            writefile(cv1);
                     break;
			case -1:
				send(clientSocket,"-1",strlen("-1")+1,0);
				cout<<"谢谢使用！";
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
       
       cout<<"共有"<<cv2.size()<<"个俱乐部"<<endl;
       if(cv2.size()==0)
          cout<<"当前没有俱乐部信息,请您先添加~"<<endl;
       else
       {
          cout<<"请输入想要查看的俱乐部号：\n";
          cin>>number;
          c=cv2.at(number);
          cout<<"俱乐部名称:"<<c.GetCname()<<endl;
          cout<<"现金:"<<c.GetCash()<<endl;
          cout<<"其下行政人员有"<<c.GetNormalNumber()<<"个。"<<endl;
          for(i=0;i<c.GetNormalNumber();i++)
          {
                n=c.GetNormal(i);
                cout<<"\n姓名："<<n.GetName()<<endl;
                cout<<"年龄："<<n.GetAge()<<endl;
                cout<<"能力："<<n.GetPower()<<endl;
                cout<<"年薪："<<n.GetWages()<<endl;
          }
          cout<<"其下球员有"<<c.GetPlayerNumber()<<"个。"<<endl;
       
          for(i=0;i<c.GetPlayerNumber();i++)
          {
                p=c.GetPlayer(i);
                cout<<"\n姓名："<<p.GetName()<<endl;
                cout<<"年龄："<<p.GetAge()<<endl;
                cout<<"能力："<<p.GetPower()<<endl;
                cout<<"年薪："<<p.GetWages()<<endl;
                cout<<"转会费："<<p.GetChangeMoney()<<endl;
                cout<<"进球总数："<<p.GetKick()<<endl;
                cout<<"服务年限："<<p.GetYears()<<endl;
          }
       }              
}
club change(club Cl)
{
     string Cn;
     int ca=0;
     int CNnum=0;
     int CPnum=0;
     
     cout<<"请输入俱乐部名称:  ";
     cin>>Cn;
     Cl.SetCname(Cn);
     cout<<"俱乐部的现金:  ";
     cin>>ca;
     Cl.SetCash(ca); 
     cout<<"\n俱乐部的行政人员数:  ";
     cin>>CNnum;
     Cl.clearnormal();//清空行政人员容器类 
     Cl.SetNormal(CNnum);
     cout<<"\n俱乐部的球员数:  ";
     cin>>CPnum;
     Cl.clearplayer();    //清空球员容器类  
     Cl.SetPlayer(CPnum);
     return Cl;
}
vector<club> sell(vector<club> cv)     //买卖一个球员 
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
     cout<<"当前不足两个俱乐部，不能进行买卖~。"<<endl;
     else
     {
          cout<<"请问您想在哪两个俱乐部之间买卖球员呢？"<<endl;
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
           cout<<"原来是"<<cB.GetCname()<<"想从"<<cS.GetCname()<<"买一个球员"<<endl;
           cout<<"请稍等..."<<endl; 
                     
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
                    cout<<"买卖成功！"<<endl;
                    success=1; 
              } 
           }
              cv.push_back(cB);
              cv.push_back(cS);
           if(success==0)
              cout<<"球员的转会费太高了，还是赚够钱了再买吧！"<<endl;
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
     
     cout<<"请输入查询表达式:";
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
                                     cout<<"您输入的条件有误，请重新输入:"<<endl;
                                 }
                            }
                       }
                   }            
                   if(val==0)
                        break;
             }
             if(val==1)
             {
                cout<<pla.GetName()<<"符合条件\n"<<endl;
                pv.push_back(pla);
                suc=1;
             }
        }
     }
     if(suc==0)
        cout<<"没有符合条件的球员"<<endl;
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
	  put.open("vectorclub.txt",ios::trunc); //ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
      
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
    put.close();//关闭文件
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
        cout<<"文件不存在.需要创建一个."<<endl;
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



