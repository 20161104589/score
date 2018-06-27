//
//  main.cpp
//  score
//
//  Created by 杨志伟 on 18/6/25.
//  Copyright © 2018年 杨志伟. All rights reserved.
//

#include <iostream>
void calCompetitor(int c,int j);
void calRater(int a,int b);
void calScore(int n);//定义评分过程的函数
struct Compe
{
    char name;
    char sex;
    char programnaem;
    char programsign;
    char clas;
    int  phone;
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
    printf("         ---------3现场打分  ------------\n");
    printf("         ---------          -----------\n");
    printf("         ---------          -----------\n");
}

void calRater(int a,int b)
{
    int n,q;
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
int main()
{
    menu();
    int e;
    scanf("%d",&e);
    switch (e) {
        case 1:
            void calRater();
            break;
        case 2:
            void calCompetitor();
            break;
        case 3:
            void calScore();
            break;
        default:
            break;
    }
    return 0;
}


void calCompetitor(int c,int j)
{
    int m,i;
    j=0;
    c=1;
    printf("请输入选手人数：");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("请输入第%d位选手的信息:\n",c);
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
void calScore(int n)
{
    int i;
    double sum=0,max=0,min=10,score,aver;
    printf("请输入选手成绩(0-10)\n");
    for(i=1;i<=n;i++)
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

}
