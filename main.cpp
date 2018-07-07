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
    printf("         ----------�������ϵͳ ------------\n");
    printf("         ---------1 ¼��ѡ����Ϣ -----------\n");
    printf("         ---------2 ¼����ί��Ϣ -----------\n");
    printf("         ---------3   �ֳ����   ------------\n");
    printf("         ---------4 ��ʾѡ����Ϣ -----------\n");
    printf("         ---------5 ��ʾ��ί��Ϣ -----------\n");
    printf("         ---------6 ����ѡ����Ϣ -----------\n");
    printf("         ---------7 ������ί��Ϣ -----------\n");
    printf("         ---------8 �޸�ѡ����Ϣ -----------\n");
    printf("         ---------9 �޸���ί��Ϣ -----------\n");
    printf("         ---------10ɾ��ѡ����Ϣ -----------\n");
    printf("         ---------11ɾ����ί��Ϣ -----------\n");
	printf("         ---------12  ��������   -----------\n");
	printf("         ---------13����ȫ����Ϣ -----------\n");
	printf("         ---------14��ȡȫ����Ϣ -----------\n");
}


void calRater()
{
    int q,a;
    a=1;
    printf("��������ί������");//������ί����
    scanf("%d",&n);
    for(q=0;q<n;q++)

    {
        printf("�������%dλ��ί����Ϣ:\n",a);
        printf("������");
        scanf("%s",&rate[q].name);
        printf("�Ա�");
        scanf("%s",&rate[q].sex);
        printf("�绰��");
        scanf("%s",&rate[q].phone);
        a=a+1;
    }
}

void calCompetitor()

{
    int i,c;
    c=1;
    printf("������¼���ѡ��������");
    scanf("%d",&m);
    for(i=0;i<m;i++)

    {
        printf("�������%dλѡ�ֵ���Ϣ:\n",c);
        printf("��ţ� ");
        scanf("%d",&compe[i].num);
        printf("������");
        scanf("%s",&compe[i].name);
        printf("�Ա�");
        scanf("%s",&compe[i].sex);
        printf("��Ŀ���ƣ�");
        scanf("%s",&compe[i].programnaem);
        printf("��Ŀ���");
        scanf("%s",&compe[i].programsign);
        printf("�༶��");
        scanf("%s",&compe[i].clas);
        printf("�绰��");
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
    printf("������ѡ�ֳɼ�(0-10) \n");
    for(j=1;j<m+1;j++)
    {
    	aver=0;
    	max=0;
    	min=100;
    	sum=0;
    	printf("�����%dλͬѧ��֣�\n",j); 
        for(i=1;i<n+1;i++)
        {
            printf("��%dλ��ί���֣�",i);
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
        printf("��ȥһ����߷֣�%.2f,��ȥһ����ͷ֣�%.2f\n",max,min);
        aver=(sum)/(n-2);
        printf("��ǰѡ�ֵ÷֣�%.3f\n",aver);
        compe[j-1].aver=aver;
    }
}

void displayStud()
{
    int i;
    for(i=0;i<m;i++)
    {
        printf("���");
        printf("%d  ",compe[i].num);
        printf("����:");
        printf("%s  ",compe[i].name);
        printf("�Ա�:");
        printf("%s  ",compe[i].sex);
        printf("��Ŀ����:");
        printf("%s  ",compe[i].programnaem);
        printf("��Ŀ���:");
        printf("%s  ",compe[i].programsign);
        printf("�༶:");
        printf("%s  ",compe[i].clas);
        printf("�绰:");
        printf("%s  ",compe[i].phone);
        printf("ƽ���÷֣�%.3f\n",compe[i].aver);

    }

}
void displayRater()
{
	int i;
    for(i=0;i<n;i++)
    {
        printf("����:");
        printf("%s  ",rate[i].name);
        printf("�Ա�:");
        printf("%s  ",rate[i].sex);
        printf("�绰��");
        printf("%s  \n",rate[i].phone);

    }
}

int num;

void inqStud()

{
    int i,j;
    int flag,myid;
    printf("��������Ҫ���ҵ�ѡ�ֱ��:");
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
        printf("û���ҵ���ѧ���� \n");

    }

    else
    {
        printf("���");
        printf("%d  ",compe[i].num);
        printf("����:");
        printf("%s  ",compe[i].name);
        printf("�Ա�:");
        printf("%s  ",compe[i].sex);
        printf("��Ŀ����:");
        printf("%s  ",compe[i].programnaem);
        printf("��Ŀ���:");
        printf("%s  ",compe[i].programsign);
        printf("�༶:");
        printf("%s  ",compe[i].clas);
        printf("�绰:");
        printf("%s  ",compe[i].phone);
        printf("ƽ���÷֣�%.3f\n",compe[i].aver);

    }

}


void inqRater()

{
    int i,j;
    int flag;
	char str[20]; 
    printf("��������Ҫ���ҵ���ί����:");
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
        printf("û���ҵ�����ί�� \n");

    }

    else
    {
		printf("����:");
        printf("%s  ",rate[i].name);
        printf("�Ա�:");
        printf("%s  ",rate[i].sex);
        printf("�绰��");
        printf("%s  \n",rate[i].phone);

    }

}


void modStud()

{

    int i,j;
    int flag,myid,pos;
    printf("��������Ҫ�޸ĵ�ѡ�ֵı��:");
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
        printf(" û���ҵ���ѧ����\n");
    }

    else
    {
        printf("��ţ� ");
        scanf("%d",&compe[i].num);
        printf("������");
        scanf("%s",&compe[i].name);
        printf("�Ա�");
        scanf("%s",&compe[i].sex);
        printf("��Ŀ���ƣ�");
        scanf("%s",&compe[i].programnaem);
        printf("��Ŀ���");
        scanf("%s",&compe[i].programsign);
        printf("�༶��");
        scanf("%s",&compe[i].clas);
        printf("�绰��");
        scanf("%s",&compe[i].phone);
        
    }

}



void modRater()

{

    int i,j;
    int flag;
	char str[20]; 
    printf("��������Ҫ�޸���Ϣ����ί������:");
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
        printf(" û���ҵ�����ί��\n");
    }

    else
    {
        printf("������");
        scanf("%s",&rate[i].name);
        printf("�Ա�");
        scanf("%s",&rate[i].sex);
        printf("�绰��");
        scanf("%s",&rate[i].phone);
        
    }

}



void delStud()
{
	int i,j;
	int flag,myid,pos;
	printf("������Ҫɾ����ѡ�ֱ��:");
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
		printf(" û���ҵ���ѧ����\n");
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
        	printf("ɾ���ɹ���\n"); 
    }
}



void delRater()
{
    int i,j;
    int flag;
	char str[20]; 
    printf("��������Ҫɾ������ί����:");
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
		printf(" û���ҵ�����ί��\n");
	}
	else
    {
            strcpy(rate[i].name,rate[i+1].name); 
            strcpy(rate[i].sex,rate[i+1].sex);  
            strcpy(rate[i].phone,rate[i+1].phone); 
        	n=n-1;
        	printf("ɾ���ɹ���\n"); 
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
        printf("���");
        printf("%d  ",compe[i].num);
        printf("����:");
        printf("%s  ",compe[i].name);
        printf("�Ա�:");
        printf("%s  ",compe[i].sex);
        printf("��Ŀ����:");
        printf("%s  ",compe[i].programnaem);
        printf("��Ŀ���:");
        printf("%s  ",compe[i].programsign);
        printf("�༶:");
        printf("%s  ",compe[i].clas);
        printf("�绰:");
        printf("%s  ",compe[i].phone);
        printf("ƽ���÷֣�%.3f\n",compe[i].aver);

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
		printf("���ļ�����\n");
		exit(-1);
	}
	else 
	{
		i=0;
		while(fscanf(fp,"%d %s %s %s %s %s %s %f \n",&t[i].num,&t[i].name,&t[i].sex,&t[i].programnaem,&t[i].programsign,&t[i].clas,&t[i].phone,&t[i].aver)!=EOF)	
		{			
			printf("��ţ�%d  ������%s  �Ա�%s  ��Ŀ���ƣ�%s  ��Ŀ���%s  �༶��%s �绰��%s  �÷֣�%f \n",t[i].num,t[i].name,t[i].sex,t[i].programnaem,t[i].programsign,t[i].clas,t[i].phone,t[i].aver);
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
		printf("���ļ�����\n");
		exit(-1);
	}
	else 
	{
		j=0;
		while(fscanf(fp,"%s %s %s \n",&r[i].name,&r[i].sex,&r[i].phone)!=EOF)	
		{			
			printf("������%s  �Ա�%s  �绰��%s \n",r[i].name,r[i].sex,r[i].phone);
			j++;
		}	
	}  
	
	fclose(fq);
}




