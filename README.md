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
void inq();
void mod();//定义评分过程的函数
struct Compe
{
    int num;
	char name;
    char sex;
    char programnaem;
    char programsign;
    char clas;
    int  phone;
    float aver;

}compe[10];

struct Rater

{
    char name;
    char sex;
    int  phone;

}rate[10];

void menu()

{
    printf("         ---------比赛打分系统------------\n");
    printf("         ---------1录入评委信息-----------\n");
    printf("         ---------2录入选手信息-----------\n");
    printf("         ---------3  现场打分 ------------\n");
    printf("         ---------4显示选手信息-----------\n");;
    printf("         ---------5查找选手信息-----------\n");
    printf("         ---------6修改选手信息-----------\n");
    printf("         ---------7删除选手信息-----------\n");

}
void calRater()
{
    int q,a,b;
    printf("请输入评委人数：");//输入评委人数
    scanf("%d",&n);
    a=1;
    b=0;
    for(q=0;q<n;q++)

    {
        printf("请输入第%d位评委的信息:\n",a);
        printf("姓名：");
        scanf("%s",&rate[b].name);
        printf("性别：");
        scanf("%s",&rate[b].sex);
        printf("电话：");
        scanf("%d",&rate[b].phone);
        a=a+1;
        b=b+1;
    }
}

void calCompetitor()

{
    int i,c,j;
    j=0;
    c=1;
    printf("请输入选手人数：");
    scanf("%d",&m);
    for(i=0;i<m;i++)

    {
        printf("请输入第%d位选手的信息:\n",c);
        printf("编号： ");
        scanf("%d",&compe[j].num);
        printf("姓名：");
        scanf("%s",&compe[j].name);
        printf("性别：");
        scanf("%s",&compe[j].sex);
        printf("节目名称：");
        scanf("%s",&compe[j].programnaem);
        printf("节目类别：");
        scanf("%s",&compe[j].programsign);
        printf("班级：");
        scanf("%s",&compe[j].clas);
        printf("电话：");
        scanf("%d",&compe[j].phone);
        c=c+1;
        j=j+1;

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
	
	        case 1:calRater();
					break;
	        case 2:
	            	calCompetitor();
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
	            	inq();
	          		 break;
	        case 7:
	        		mod();
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
    	printf("请给第%d位同学打分：\n",j); 
        for(i=1;i<n+1;i++)
        {
            printf("第%d位评委给分：",i);
            scanf("%lf",&score);
            sum=sum+score;
            if(max<score)
                max=score;
            if(min>score)
                min=score;
        }
        sum=sum-max-min;
        printf("减去一个最高分：%.2f,减去一个最低分：%.2f\n",max,min);
        aver=(sum)/(n-2);
        printf("当前选手得分：%.3f\n",aver);
        compe[j].aver=aver;
    }
}

void displayStud()
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("编号：  ");
        printf("%d",compe[i].num);
        printf("姓名: ");
        printf("%s     ",compe[i].name);
        printf("性别:");
        printf("%s     ",compe[i].sex);
        printf("节目名称:");
        printf("%s     ",compe[i].programnaem);
        printf("节目类别:     ");
        printf("%s   ",compe[i].programsign);
        printf("班级：");
        printf("%s   ",compe[i].clas);
        printf("电话：");
        printf("%d   ",compe[i].phone);
        printf("平均得分： %d",compe[i].aver);

    }

}
void displayRater()
{
	
}

int num;

void inq()

{
    int i,j;
    int flag,myid,pos;
    printf("please input inquire id:");
    scanf("%d",&myid);
    flag=0;
    for(i=0;i<num;i++)
    {
        if(compe[i].name==myid)
        {
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf(" no find this student \n");
       exit(0);

    }

    else
    {
        printf("编号：  ");
        printf("%d",compe[i].num);
        printf("姓名: ");
        printf("%s     ",compe[i].name);
        printf("性别:");
        printf("%s     ",compe[i].sex);
        printf("节目名称:");
        printf("%s     ",compe[i].programnaem);
        printf("节目类别:     ");
        printf("%s   ",compe[i].programsign);
        printf("班级：");
        printf("%s   ",compe[i].clas);
        printf("电话：");
        printf("%d   ",compe[i].phone);
        printf("平均得分： %d",compe[i].aver);

    }

}



void mod()

{

    int i,j;
    int flag,myid,pos;
    printf("please input modify id:");
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
        printf(" no find this student \n");
        exit(0);
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
        scanf("%d",&compe[i].phone);
        
    }

}
