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
void normal::SetWages(int wa)    {   wages=wa;       }
int normal::GetWages()           {   return wages;   } 
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
void player::SetChangeMoney(int CM)  {  ChangeMoney=CM;      } 
int player::GetChangeMoney()         {  return ChangeMoney;  }
void player::SetKick(int ki)           {  kick=ki;             }
int player::GetKick()                  {  return kick;         }
void player::SetYears(int ye)          {  years=ye;            }
int player::GetYears()                 {  return years;        }
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
             void addonenormal(normal n);    //增加一个行政人员 
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

void check(vector<club> cv2);
vector<player> search(vector<club> cv,string refer);
int value(char op1,int num1,int num2);
vector<club> readfile();
void writefile(vector<club> cv);
int main()
{
	 //创建套接字
	 WORD myVersionRequest;
	 WSADATA wsaData;
	 myVersionRequest=MAKEWORD(1,1);
	 int err;
	 err=WSAStartup(myVersionRequest,&wsaData);
	 SOCKET serSocket=socket(AF_INET,SOCK_STREAM,0);//创建了可识别套接字
	 //需要绑定的参数
	 SOCKADDR_IN addr;
	 addr.sin_family=AF_INET;
	 addr.sin_addr.S_un.S_addr=htonl(INADDR_ANY);//ip地址
	 addr.sin_port=htons(6000);//绑定端口
	 
	 bind(serSocket,(SOCKADDR*)&addr,sizeof(SOCKADDR));//制定本地地址，绑定完成
	 listen(serSocket,5);//其中第二个参数代表能够接收的最多的连接数
	 SOCKADDR_IN clientsocket;
	 int len=sizeof(SOCKADDR);
	 
	 SOCKET serConn=accept(serSocket,(SOCKADDR*)&clientsocket,&len);//如果这里不是accept而是conection的话。。就会不断的监听
	 
	 if (!err)
		cout<<"已打开套接字\n"<<endl;  
	 else
	 {
	  //进一步绑定套接字
	  cout<<"嵌套字未打开!"<<endl;
	  return 0;
     }
     
     int i=0;
     int j=0,k=0;
     int flag=-1;
     int cash1=0;
     int cash2=0;
     vector<club> cv1; 
     char receiveBuf[100];
     char c[100];//接收
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
		 cout<<"文件是空的，等待您的添加！"<<endl;
		 c1=cb.AddClub();
         cv1.push_back(c1);
         writefile(cv1);
     }	 
	 else
	 {
		int choice=0;
	     cout<<"系统里已经有俱乐部的文件了！\n"<<endl;
		 while(choice!=-1)
		 {
			 cout<<"请输入您要进行的操作："<<endl;
			cout<<"（1）添加  （2）查询  （3）接收客户端请求"<<endl;
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
				cout<<"正在等待服务端发出请求，请稍候......"<<endl;
	  
				recv(serConn,receiveBuf,strlen(receiveBuf)+1,0);
				cout<<receiveBuf<<endl;//接受命令*/
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
					 cout<<receiveBuf<<endl;//接受命令*/
			 }  
			 else if(receiveBuf[0]=='6')
				   {
						cout<<"服务端现有俱乐部如下："<<endl;
						for(j=0;j<cv1.size();j++)
						{
							c2=cv1.at(j);
							cout<<c2.GetCname()<<endl;
						}
						cout<<"请输入卖球员的俱乐部名称:"<<endl;
						cin>>cN;

						for(j=0;j<cv1.size();j++)
						{
							c4=cv1.at(j);
		   					if(cN==c4.GetCname())
							{    
								cout<<"此俱乐部现有球员为:"<<endl;
								for(i=0;i<c4.GetPlayerNumber();i++)   //遍历此俱乐部
								{
									player2=c4.GetPlayer(i);
									cout<<"姓名:"<<player2.GetName()<<endl;
									cout<<"转会费:"<<player2.GetChangeMoney()<<endl;
								}
								cout<<"请输入要买的球员"<<endl;
								cin>>pN;
								flag=j;
								for(k=0;k!=c4.GetPlayerNumber();k++)//遍历要卖俱乐部的所有球员
								{   
									 player2=c4.GetPlayer(k);
									if(pN==player2.GetName())
									{
										cout<<"转会费:"<<player2.GetChangeMoney()<<endl;
										memset(c, 0, sizeof(c));
										recv(serConn,c,sizeof(c)+1,0);
										cout<<"客户端欲购买球员的俱乐部名称为："<<c<<endl;
										memset(c, 0, sizeof(c));
										recv(serConn,c,sizeof(c)+1,0);
										cout<<"俱乐部现金为："<<c<<endl;
										cash1=atoi(c);
										 if(cash1 >= player2.GetChangeMoney())
										{
											cout<<"成功的买到一个球员啦！"<<endl;
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
											cout<<c4.GetCname()<<"现在俱乐部的现金："<<cv1.at(flag).GetCash()<<endl;

											cv1.at(flag).deleteplayer(k);//删除球员
											cout<<"已删除"<<pN<<"的信息"<<endl;
										}//end if
								  else
								  { 
									  cout<<"球员转会费太高，还是赚够钱再买吧！"<<endl;
									  send(serConn,"0",strlen("0")+1,0);
								  }//end else
							  }//end if
						  }//end for
					   }//end if	
				   }//end for
				}//end if
          writefile(cv1); 		
		  
		  recv(serConn,receiveBuf,strlen(receiveBuf)+1,0);
		  cout<<receiveBuf<<endl;//接受命令*/
		}//end while
	}//end else
		system("pause");	
	}//end while
	}
	  closesocket(serConn);//关闭
	  WSACleanup();//释放资源的操作
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
                cout<<pla.GetName()<<"符合条件\n"<<endl;
                suc=1;
                pv.push_back(pla);
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
             if(num1=num2)
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

