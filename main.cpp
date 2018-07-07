#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstring> 


int m,n;
void calCompetitor();
void calRater();
void calScore();
void displayStud();
void displayRater();
void inqStud();
void inqRater();
void modStud();
void modRater();
void delStud();
void delRater();
void sort();
void save();
void read();


struct Compe
{
    int num;
	char name[20];
    char sex[10];
    char programnaem[20];
    char programsign[20];
    char clas[20];
    char  phone[20];
    float aver;

}compe[10];

struct Rater

{
    char name[20];
    char sex[20];
    char phone[20];

}rate[10];


void menu()

{
    printf("         ----------比赛打分系统 ------------\n");
    printf("         ---------1 录入选手信息 -----------\n");
    printf("         ---------2 录入评委信息 -----------\n");
    printf("         ---------3   现场打分   ------------\n");
    printf("         ---------4 显示选手信息 -----------\n");
    printf("         ---------5 显示评委信息 -----------\n");
    printf("         ---------6 查找选手信息 -----------\n");
    printf("         ---------7 查找评委信息 -----------\n");
    printf("         ---------8 修改选手信息 -----------\n");
    printf("         ---------9 修改评委信息 -----------\n");
    printf("         ---------10删除选手信息 -----------\n");
    printf("         ---------11删除评委信息 -----------\n");
	printf("         ---------12  分数排序   -----------\n");
	printf("         ---------13保存全部信息 -----------\n");
	printf("         ---------14读取全部信息 -----------\n");
}


void calRater()
{
    int q,a;
    a=1;
    printf("请输入评委人数：");//输入评委人数
    scanf("%d",&n);
    for(q=0;q<n;q++)

    {
        printf("请输入第%d位评委的信息:\n",a);
        printf("姓名：");
        scanf("%s",&rate[q].name);
        printf("性别：");
        scanf("%s",&rate[q].sex);
        printf("电话：");
        scanf("%s",&rate[q].phone);
        a=a+1;
    }
}

void calCompetitor()

{
    int i,c;
    c=1;
    printf("请输入录入的选手人数：");
    scanf("%d",&m);
    for(i=0;i<m;i++)

    {
        printf("请输入第%d位选手的信息:\n",c);
        printf("编号： ");
        scanf("%d",&compe[i].num);
        printf("姓名：");
        scanf("%s",&compe[i].name);
        printf("性别：");
        scanf("%s",&compe[i].sex);
        printf("节目名称：");
        scanf("%s",&compe[i].programnaem);
        printf("节目类别：");
        scanf("%s",&compe[i].programsign);
        printf("班级：");
        scanf("%s",&compe[i].clas);
        printf("电话：");
        scanf("%s",&compe[i].phone);
        c=c+1;

    }
}


int main()

{
    int e;
	while(1)
	{
		menu();
    	scanf("%d",&e);
	    switch (e)
	    {
	
	        case 1:calCompetitor();
					break;
	        case 2:
	            	calRater();
	            	break;
	        case 3:
	            	calScore();
	            	break;
	        case 4:
	           		displayStud();
	            	break;
	        case 5:
	            	displayRater();
	            	break;	 
	        case 6:
	            	inqStud();
	          		 break;
	        case 7:
	            	inqRater();
	          		 break;
	        case 8:
	        		modStud();
	            	break;
	        case 9:
	        		modRater();
	            	break;
	        case 10:
	        		delStud();
	            	break;
	        case 11:
	        		delRater();
	            	break;
	        case 12:
	        		sort();
	            	break;
	        case 13:
	        		save();
	            	break;
	        case 14:
	        		read();
	            	break;
	            	
	    }
	}

}
void calScore()

{
    int i,j;
    double sum=0,max=0,min=10,score,aver;
    printf("请输入选手成绩(0-10) \n");
    for(j=1;j<m+1;j++)
    {
    	aver=0;
    	max=0;
    	min=100;
    	sum=0;
    	printf("请给第%d位同学打分：\n",j); 
        for(i=1;i<n+1;i++)
        {
            printf("第%d位评委给分：",i);
            scanf("%lf",&score);
            sum=sum+score;
            if(max<score)
            {
            	 max=score;
			}
               
            if(min>score)
            {
            	min=score;
			}
                
        }
        sum=sum-max-min;
        printf("减去一个最高分：%.2f,减去一个最低分：%.2f\n",max,min);
        aver=(sum)/(n-2);
        printf("当前选手得分：%.3f\n",aver);
        compe[j-1].aver=aver;
    }
}

void displayStud()
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("编号");
        printf("%d  ",compe[i].num);
        printf("姓名:");
        printf("%s  ",compe[i].name);
        printf("性别:");
        printf("%s  ",compe[i].sex);
        printf("节目名称:");
        printf("%s  ",compe[i].programnaem);
        printf("节目类别:");
        printf("%s  ",compe[i].programsign);
        printf("班级:");
        printf("%s  ",compe[i].clas);
        printf("电话:");
        printf("%s  ",compe[i].phone);
        printf("平均得分：%.3f\n",compe[i].aver);

    }

}
void displayRater()
{
	int i;
    for(i=0;i<n;i++)
    {
        printf("姓名:");
        printf("%s  ",rate[i].name);
        printf("性别:");
        printf("%s  ",rate[i].sex);
        printf("电话：");
        printf("%s  \n",rate[i].phone);

    }
}

int num;

void inqStud()

{
    int i,j;
    int flag,myid;
    printf("请输入需要查找的选手编号:");
    scanf("%d",&myid);
    flag=0;
    for(i=0;i<m;i++)
    {
        if(compe[i].num==myid)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("没有找到该学生！ \n");

    }

    else
    {
        printf("编号");
        printf("%d  ",compe[i].num);
        printf("姓名:");
        printf("%s  ",compe[i].name);
        printf("性别:");
        printf("%s  ",compe[i].sex);
        printf("节目名称:");
        printf("%s  ",compe[i].programnaem);
        printf("节目类别:");
        printf("%s  ",compe[i].programsign);
        printf("班级:");
        printf("%s  ",compe[i].clas);
        printf("电话:");
        printf("%s  ",compe[i].phone);
        printf("平均得分：%.3f\n",compe[i].aver);

    }

}


void inqRater()

{
    int i,j;
    int flag;
	char str[20]; 
    printf("请输入需要查找的评委姓名:");
    scanf("%s",&str);
    flag=0;
    for(i=0;i<n;i++)
    {
		if(strcmp(rate[i].name,str)==0) 
		{
			flag=1;
			break;
		}
    }

    if(flag==0)
    {
        printf("没有找到该评委！ \n");

    }

    else
    {
		printf("姓名:");
        printf("%s  ",rate[i].name);
        printf("性别:");
        printf("%s  ",rate[i].sex);
        printf("电话：");
        printf("%s  \n",rate[i].phone);

    }

}


void modStud()

{

    int i,j;
    int flag,myid,pos;
    printf("请输入需要修改的选手的编号:");
    scanf("%d",&myid);
    flag=0;
    for(i=0;i<n;i++)
    {
        if(compe[i].num==myid)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf(" 没有找到该学生！\n");
    }

    else
    {
        printf("编号： ");
        scanf("%d",&compe[i].num);
        printf("姓名：");
        scanf("%s",&compe[i].name);
        printf("性别：");
        scanf("%s",&compe[i].sex);
        printf("节目名称：");
        scanf("%s",&compe[i].programnaem);
        printf("节目类别：");
        scanf("%s",&compe[i].programsign);
        printf("班级：");
        scanf("%s",&compe[i].clas);
        printf("电话：");
        scanf("%s",&compe[i].phone);
        
    }

}



void modRater()

{

    int i,j;
    int flag;
	char str[20]; 
    printf("请输入需要修改信息的评委的姓名:");
    scanf("%s",&str);
    flag=0;
    for(i=0;i<n;i++)
    {
        if(strcmp(rate[i].name,str)==0)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf(" 没有找到该评委！\n");
    }

    else
    {
        printf("姓名：");
        scanf("%s",&rate[i].name);
        printf("性别：");
        scanf("%s",&rate[i].sex);
        printf("电话：");
        scanf("%s",&rate[i].phone);
        
    }

}



void delStud()
{
	int i,j;
	int flag,myid,pos;
	printf("请输入要删除的选手编号:");
	scanf("%d",&myid);
	flag=0;
	for(i=0;i<m;i++)
	{
		if(compe[i].num==myid)
		{
			flag=1;
			break;
		}
	}
	if(flag==0)
	{
		printf(" 没有找到该学生！\n");
	}
	else
    {
            compe[i].num = compe[i+1].num; 
            strcpy(compe[i].name,compe[i+1].name); 
            strcpy(compe[i].sex,compe[i+1].sex); 
            strcpy(compe[i].programnaem,compe[i+1].programnaem); 
            strcpy(compe[i].programsign,compe[i+1].programsign); 
            strcpy(compe[i].clas,compe[i+1].clas); 
            strcpy(compe[i].phone,compe[i+1].phone); 
            compe[i].aver=compe[i+1].aver;
        	m=m-1;
        	printf("删除成功！\n"); 
    }
}



void delRater()
{
    int i,j;
    int flag;
	char str[20]; 
    printf("请输入需要删除的评委姓名:");
    scanf("%s",&str);
    flag=0;
    
    for(i=0;i<n;i++)
    {
        if(strcmp(rate[i].name,str)==0)
        {
            flag=1;
            break;
        }
    }
    
	if(flag==0)
	{
		printf(" 没有找到该评委！\n");
	}
	else
    {
            strcpy(rate[i].name,rate[i+1].name); 
            strcpy(rate[i].sex,rate[i+1].sex);  
            strcpy(rate[i].phone,rate[i+1].phone); 
        	n=n-1;
        	printf("删除成功！\n"); 
    }
    
    
}



void sort()
{	
	FILE *fp;
	int i,j,n;
	struct Compe temp;
	
	for(i=0;i<m-1;i++)
	  for(j=0;j<m-1;j++)
	  {
	  	if(compe[j].aver<compe[j+1].aver)
	  	{
	  		temp=compe[j];
	  		compe[j]=compe[j+1];
	  		compe[j+1]=temp;
	  	}
	  }
	  
	  
	for(i=0;i<m;i++)
    {
        printf("编号");
        printf("%d  ",compe[i].num);
        printf("姓名:");
        printf("%s  ",compe[i].name);
        printf("性别:");
        printf("%s  ",compe[i].sex);
        printf("节目名称:");
        printf("%s  ",compe[i].programnaem);
        printf("节目类别:");
        printf("%s  ",compe[i].programsign);
        printf("班级:");
        printf("%s  ",compe[i].clas);
        printf("电话:");
        printf("%s  ",compe[i].phone);
        printf("平均得分：%.3f\n",compe[i].aver);

    }
}



void save()
{
 	FILE *fp;
	
 	int i;
 	fp=fopen("Compe.csv","a+");

	for(i=0;i<m;i++)
	{
	 	fprintf(fp,"%d %s %s %s %s %s %s %.3f \n",compe[i].num,compe[i].name,compe[i].sex,compe[i].programnaem,compe[i].programsign,compe[i].clas,compe[i].phone,compe[i].aver);
	}
	 fclose(fp);
	 
	 
	FILE *fq;
	int j;
	fq=fopen("Rater.csv","a+");

	for(j=0;j<n;j++)
	{
	 	fprintf(fq,"%s %s %s\n",rate[j].name,rate[j].sex,rate[j].phone);
	}
	 fclose(fq);	
}



void read()
{
	FILE *fp;
	int i;
	struct Compe t[50];
	fp=fopen("Compe.csv","r");
	if(fp==NULL)
	{
		printf("打开文件错误！\n");
		exit(-1);
	}
	else 
	{
		i=0;
		while(fscanf(fp,"%d %s %s %s %s %s %s %f \n",&t[i].num,&t[i].name,&t[i].sex,&t[i].programnaem,&t[i].programsign,&t[i].clas,&t[i].phone,&t[i].aver)!=EOF)	
		{			
			printf("编号：%d  姓名：%s  性别：%s  节目名称：%s  节目类别：%s  班级：%s 电话：%s  得分：%f \n",t[i].num,t[i].name,t[i].sex,t[i].programnaem,t[i].programsign,t[i].clas,t[i].phone,t[i].aver);
			i++;
		}	
	}  
	fclose(fp);
	
	
	FILE *fq;
	int j;
	struct Rater r[50];
	fq=fopen("Rater.csv","r");
	if(fp==NULL)
	{
		printf("打开文件错误！\n");
		exit(-1);
	}
	else 
	{
		j=0;
		while(fscanf(fp,"%s %s %s \n",&r[i].name,&r[i].sex,&r[i].phone)!=EOF)	
		{			
			printf("姓名：%s  性别：%s  电话：%s \n",r[i].name,r[i].sex,r[i].phone);
			j++;
		}	
	}  
	
	fclose(fq);
}




