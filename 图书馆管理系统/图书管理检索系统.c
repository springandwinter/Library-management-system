#include<stdio.h>
#include<string.h>
#include "conio.h"
#include<stdlib.h>
#include <time.h>
#include <windows.h>
#define N1 200
#define N 25
#define M 10
#define MAX 100
#define BACKSPACE 8
typedef struct date1{
    int year;
    int mouth;
    int day;
}DATE1;
typedef struct book{
    char category[N];//������
    int every_leibie_shu_totalcount;//ÿһ���ͬ�����ʽ����
    DATE1 books_in_library[N];//�����ʱ��
    char tushubianhao[N][N];//��ı��
    char shuming[N][N];//�������
    int totalCount[N];//���鹲�ж��ٱ�
    int leftCount[N];//ʣ�౾��
    double price[N];//��ļ۸�
    char author[N][N];//�������
    char publishing_company[N][N];//��ĳ�����
    struct book *next1;
}BOOK;

typedef struct student{
    char studentID[N];
    char studentName[N];
    char password[N];
    char studentSex[N];
    char Tell[N];
    char xueyuan[N];
    char major[N];
    char Class[N];
    char student_email[N];
    struct student *next2;
}STUDENT;

typedef struct teacher{
    char teacherID[N];
    char teacherName[N];
    char teacherPassword[N];
    char teacherSex[N];
    char teacherTell[N];
    char teacherPosition[N];
    char teacher_email[N];
    struct teachar *next3;
}TEACHER;

typedef struct tushu_administration{
    char tushu_administrationID[N];
    char tushu_administrationName[N];
    char tushu_administrationPassword[N];
    char tushu_administrationSex[N];
    char tushu_administrationTell[N];
    char tushu_administration_email[N];
    struct tushu_administration *next4;
}TUSHU_ADMINISTRATION;
typedef struct xitong_administration{
    char xitong_administrationID[N];
    char xitong_administrationName[N];
    char xitong_administrationPassword[N];
    char xitong_administrationSex[N];
    char xitong_administrationTell[N];
    struct xitong_administration *next5;
}XITONG_ADMINISTRATION;
typedef struct date2{
    int year;
    int mouth;
    int day;
}DATE2;
typedef struct readerBooks{
    char readerID[N];//����ID
    int total_bookCount;//������ٱ�
    DATE2 borrowed_BooksTime[N];//��������ڣ����ν�ǵڶ��ε�
    DATE2 Return_BooksTime[N];//���������
    char readerBooks[N][N];//���ͼ������
    int reader_BooksTimes[N];//���鱻����������Ĵ���

    struct readerBooks *next6;
}READERBOOKS;
BOOK *creat_book();
STUDENT *creat_student();
TEACHER *creat_teacher();
TUSHU_ADMINISTRATION *creat_tushu_administration();
XITONG_ADMINISTRATION *creat_xitong_administration();
READERBOOKS *creat_readerbooks();
//��֤����
STUDENT *Student_verify(char id[],char password[],STUDENT *head2);
TEACHER *Teacher_verify(char id[],char password[],TEACHER *head3);
TUSHU_ADMINISTRATION *Tushu_Administration_verify(char id[],char password[],TUSHU_ADMINISTRATION *head4);
XITONG_ADMINISTRATION *Xitong_Administration_verify(char id[],char password[],XITONG_ADMINISTRATION *head5);
//���⺯��
void print();
void shijian();
void xitongshijian();
int Isleap(int year);
int Total_day(int year, int month ,int day);
int Total_day(int year, int month ,int day);
int Weekday(int year, int month ,int day);
int isright();
//ѧ������
void student_menu(BOOK *head1,STUDENT *r,STUDENT *head2,FILE *fp2,READERBOOKS *head6);
void student_info(STUDENT *r);
void student_borrow(READERBOOKS *head6,STUDENT *r);
void student_borrowagain(READERBOOKS *head6,STUDENT *r);
int student_changepassword(STUDENT *r);
void present_tushu_info(BOOK *head1);
//��ʦ����
void teacher_menu(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea);
void teacher_info(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea);
void teacher_changexinxi(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea);
void teacher_borrow(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea);
void teacher_changepassword(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea);
void teacher_borowagin(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *teaa);
void teacher_seacherbook(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea);
void present_tushu_info(BOOK *head1);
//ͼ�����Ա����
void tushu_administration_menu(TUSHU_ADMINISTRATION *t,TUSHU_ADMINISTRATION *head4,FILE *fp4,BOOK *head1,READERBOOKS * head6);//ͼ�����Ա�˵�
void tushu_administration_info(TUSHU_ADMINISTRATION *t);//��ʾͼ�����Ա��Ϣ
void look_reader_borrow(READERBOOKS *head6);
void present_borrow_tushu(READERBOOKS *head6,char c[]);
void present_book_info(BOOK *head1,char book_name[],int flag);
int tushu_administration_changepassword(TUSHU_ADMINISTRATION *t);//ͼ�����Ա��������
void help_reader_borrow_lend(READERBOOKS *head6,BOOK *head1);//Ϊ���߽軹�鼮
void present_tushu_info(BOOK *head1);//��ʾͼ����Ϣ
void book_in(BOOK *head1);//�������
void book_out(BOOK *head1);
//ϵͳ����Ա����
void xitong_administration_menu(STUDENT *head2,TEACHER *head3,TUSHU_ADMINISTRATION *head4,XITONG_ADMINISTRATION *head5,FILE *fp5,XITONG_ADMINISTRATION *y);
void xitong_administration_info(XITONG_ADMINISTRATION *y);
int xitong_administration_changepassword(XITONG_ADMINISTRATION *y);
void xitong_administration_find_reader(STUDENT *head2,TEACHER *head3,TUSHU_ADMINISTRATION *head4);
void xitong_administration_add_or_delete_reader(STUDENT *head2,TEACHER *head3,TUSHU_ADMINISTRATION *head4);

void color(const unsigned short color1)
{        /*���޸ı�0-15����ɫ;�����0-15��ôʵ��������ɫ   ��Ϊ�������15����ĸı�����ı�����ɫ��*/
        if(color1>=0&&color1<=15)
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color1);
        /*�������0-15�ķ�Χ��ɫ����ô��ΪĬ�ϵ���ɫ��ɫ��*/
    else
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

int main()
{
   print();
}
void xitongshijian()
{
    int H;
    time_t time_s;
    struct tm *date_time;
    time(&time_s);
    date_time = localtime(&time_s);
    COORD RD={0,0};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),RD);
    H=date_time->tm_hour;
    //printf("%04d��%02d��%02d�� %02d:%02d:%02d ",date_time->tm_year+1900,date_time->tm_mon+1,date_time->tm_mday,date_time->tm_hour,date_time->tm_min,date_time->tm_sec);
    if(H>=6&&H<=12)
    {
        color(10);
        printf("\n\n\t   �� �� �� ��");
    }
    if(H>12&&H<=18)
      {
          color(10);
          printf("\n\n\t   �� �� �� ��");
      }
    if(H>18)
    {
        color(10);
        printf("\n\n\t   �� �� �� ��");
    }
    if(H>=0&&H<6)
    {
        color(10);
        printf("\n\n\t    �� �� �� ��");
    }
}
void shijian()
{
    int y,m,d;
    time_t time_s;
    struct tm *date_time;
    time(&time_s);
    date_time = localtime(&time_s);
    y=date_time->tm_year+1900;
    m=date_time->tm_mon+1;
    d=date_time->tm_mday;
    if(m<1||m>12||d<1||d>31)
    {
        printf("error...\n");
        return -1;
    }
    xitongshijian();
    color(10);
    printf("%d �� %d �� %d �� �� �� һ �� �� �� %d ��\n\n",y,m,d,Total_day(y,m,d));
    display_week(y,m,d);
}
/*�ж����������Ƿ�Ϊ����
**����˵����year,Ҫ�жϵ����
**����ֵ 1�������꣬0����������
*/
int Isleap(int year)
{
    if( (year%400==0)||((year%4==0)&&(year%100!=0)) )
        return 1;
    else
        return 0;
}

/*�ж�������ݶ��·ݵ�����
**����˵����year,Ҫ�жϵ���ݣ�month��Ҫ�жϵ��·�
**����ֵ:Day[month-1],�ϸ��£�month-1��������
*/
int Max_day(int year, int month)
{
    int Day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(Isleap(year)==1)
        Day[1]=29;
    return Day[month-1];
}


/*�����������������һ��Ķ�����
**����˵����year,month,day �ֱ�Ϊ������ꡢ�¡���
**����ֵ:sum,�������������һ��Ķ�����
*/
int Total_day(int year, int month ,int day)
{
    int sum=0;
    int i=1;
    for(i=1;i<month;i++)
    sum=sum+Max_day(year,i);
    sum=sum+day;
    return sum;
}

/*������������жϵ��������ڼ�
**����˵����year,month,day �ֱ�Ϊ������ꡢ�¡���
**����ֵ:count,0��6���ֱ��ʾ�����ա�������
*/
int Weekday(int year, int month ,int day)
{
    int count;
    count=(year-1)+(year-1)/4-(year-1)/100+(year-1)/400 +Total_day(year,month,day);
    count=count%7;
    return count;
}


/*��ʾ��������������ڼ�
**����˵����year,month,day �ֱ�Ϊ������ꡢ�¡���
**����ֵ:��
*/
void display_week(int year, int month , int day)
{
    int count;
    count=Weekday(year,month,day);
    switch(count)
        {
            case 0:printf("\t\t\t         Sunday\n" );break;
            case 1:printf("\t\t\t         Monday\n" );break;
            case 2:printf("\t\t\t         Tuesday\n" );break;
            case 3:printf("\t\t\t         Wednesday\n" );break;
            case 4:printf("\t\t\t         Thursday\n" );break;
            case 5:printf("\t\t\t         Friday\n" );break;
            case 6:printf("\t\t\t         Saturday\n" );break;
            default: system("cls");printf("error\n");
        }
}
void print(){
    int n;
    char id[20],ch1;
    char password[20];
    FILE *fp1,*fp2,*fp3,*fp4,*fp5,*fp6;
    BOOK *head1,*boo,*p1,*s1;
    STUDENT *head2,*stu,*p2,*s2,*r;
    TEACHER *head3,*tea,*p3,*s3,*s;
    TUSHU_ADMINISTRATION *head4,*tus,*p4,*s4,*t;
    XITONG_ADMINISTRATION *head5,*xit,*p5,*s5,*y;
    READERBOOKS *head6,*rea,*p6,*s6;
    /*boo=creat_book();
   if((fp1=fopen("ͼ����Ϣ","wb"))==NULL)
    {
        printf("cannot open file,press any key to exit!");
	 	getch();
	 	exit(1);
	 }
     do
	 {
	    fwrite(boo,sizeof(BOOK),1,fp1);
	 	boo=boo->next1;
	 }while(boo!=NULL);
	 fclose(fp1);*/
    if((fp1=fopen("ͼ����Ϣ","rb+"))==NULL)
	 {
	    printf("Failure to open!");
	 	getch();
        exit(1);
	 }
     head1 = (BOOK*)malloc(sizeof(BOOK));
     head1->next1 = NULL;
     p1 = head1;
     while(!feof(fp1))
     {
        s1 = (BOOK*)malloc(sizeof(BOOK));
        fread(s1,sizeof(BOOK),1,fp1);
        s1->next1 = NULL;
        p1->next1 = s1;
        p1 = s1;
     }

     /*stu=creat_student();
     if((fp2=fopen("ѧ����Ϣ","wb"))==NULL)
	 {
	    printf("cannot open file,press any key to exit!");
	 	getch();
	 	exit(1);
	 }
     do
	 {
	    fwrite(stu,sizeof(STUDENT),1,fp2);
	 	stu=stu->next2;
	 }while(stu!=NULL);
	 fclose(fp2);*/
    if((fp2=fopen("ѧ����Ϣ","r"))==NULL)
	 {
	    printf("Failure to open!");
	 	getch();
        exit(1);
	 }
     head2=(STUDENT*)malloc(sizeof(STUDENT));
     head2->next2=NULL;
     p2 = head2;
     while(!feof(fp2))
     {
        s2=(STUDENT*)malloc(sizeof(STUDENT));
        fread(s2,sizeof(STUDENT),1,fp2);
        s2->next2 = NULL;
        p2->next2 = s2;
        p2 = s2;
     }
    p2->next2 = NULL;
     /*tea=creat_teacher();
     if((fp3=fopen("��ʦ��Ϣ","wb"))==NULL)
	 {
	    printf("cannot open file,press any key to exit!");
	 	getch();
	 	exit(1);
	 }
     do
	 {
	    fwrite(tea,sizeof(TEACHER),1,fp3);
	 	tea=tea->next3;
	 }while(tea!=NULL);
	 fclose(fp3);*/
    if((fp3=fopen("��ʦ��Ϣ","rb+"))==NULL)
	 {
	    printf("Failure to open!");
	 	getch();
        exit(1);
	 }
     head3 = (TEACHER*)malloc(sizeof(TEACHER));
     head3->next3 = NULL;
     p3 = head3;
     while(!feof(fp3))
     {
        s3 = (TEACHER*)malloc(sizeof(TEACHER));
        fread(s3,sizeof(TEACHER),1,fp3);
        s3->next3 = NULL;
        p3->next3 = s3;
        p3 = s3;
     }

     /*tus=creat_tushu_administration();
     if((fp4=fopen("ͼ�����Ա��Ϣ","wb"))==NULL)
	 {
	    printf("cannot open file,press any key to exit!");
	 	getch();
	 	exit(1);
	 }
     do
	 {
	    fwrite(tus,sizeof(TUSHU_ADMINISTRATION),1,fp4);
	 	tus=tus->next4;
	 }while(tus!=NULL);
	 fclose(fp4);*/
    if((fp4=fopen("ͼ�����Ա��Ϣ","rb+"))==NULL)
	 {
	    printf("Failure to open!");
	 	getch();
        exit(1);
	 }
     head4 = (TUSHU_ADMINISTRATION*)malloc(sizeof(TUSHU_ADMINISTRATION));
     head4->next4 = NULL;
     p4 = head4;
     while(!feof(fp4))
     {
        s4 = (TUSHU_ADMINISTRATION*)malloc(sizeof(TUSHU_ADMINISTRATION));
        fread(s4,sizeof(TUSHU_ADMINISTRATION),1,fp4);
        s4->next4 = NULL;
        p4->next4 = s4;
        p4 = s4;
     }

     /*xit=creat_xitong_administration();
     if((fp5=fopen("ϵͳ����Ա��Ϣ","wb"))==NULL)
	 {
	    printf("cannot open file,press any key to exit!");
	 	getch();
	 	exit(1);
	 }
     do
	 {
	    fwrite(xit,sizeof(XITONG_ADMINISTRATION),1,fp5);
	 	xit=xit->next5;
	 }while(xit!=NULL);
	 fclose(fp5);*/
    if((fp5=fopen("ϵͳ����Ա��Ϣ","rb+"))==NULL)
	 {
	    printf("Failure to open!");
	 	getch();
        exit(1);
	 }
     head5 = (XITONG_ADMINISTRATION*)malloc(sizeof(XITONG_ADMINISTRATION));
     head5->next5 = NULL;
     p5 = head5;
     while(!feof(fp5))
     {
        s5 = (XITONG_ADMINISTRATION*)malloc(sizeof(XITONG_ADMINISTRATION));
        fread(s5,sizeof(XITONG_ADMINISTRATION),1,fp5);
        s5->next5 = NULL;
        p5->next5 = s5;
        p5 = s5;
     }

     /*rea=creat_readerbooks();
     if((fp6=fopen("���߽�����Ϣ","wb"))==NULL)
	 {
	    printf("cannot open file,press any key to exit!");
	 	getch();
	 	exit(1);
	 }
     do
	 {
	    fwrite(rea,sizeof(READERBOOKS),1,fp6);
	 	rea=rea->next6;
	 }while(rea!=NULL);
	 fclose(fp6);*/
     if((fp6=fopen("���߽�����Ϣ","rb+"))==NULL)
	 {
	    printf("Failure to open!");
	 	getch();
        exit(1);
	 }
     head6 = (READERBOOKS*)malloc(sizeof(READERBOOKS));
     head6->next6 = NULL;
     p6 = head6;
     while(!feof(fp6))
     {
        s6 = (READERBOOKS*)malloc(sizeof(READERBOOKS));
        fread(s6,sizeof(READERBOOKS),1,fp6);
        s6->next6 = NULL;
        p6->next6 = s6;
        p6 = s6;
     }
    system("cls");
    color(7);
    shijian();
    char *pic[90],*p;

    pic[0]="\n\n\t\t< _ > �� ӭ �� �� ͼ �� �� �� �� ϵ ͳ < _ >\n\n\n";
    pic[1] ="\t\t\t\t1 �� ��\n\n";
    pic[2]="\t\t\t\t0 ȡ ��\n\n\n";

    color(12);
	p=pic[0];//ÿ��10�������1����
    printf("%s",p),Sleep(500);

    color(5);
    p=pic[1];//ÿ��10�������1����
    printf("%s",p),Sleep(500);

	color(6);
	p=pic[2];//ÿ��10�������1����
	printf("%s",p),Sleep(500);

    int ch;
    color(3);
    printf("\t\t      �� �� ѡ �� 1 �� �� 0 �� ����");
    scanf("%d",&ch);
    if(ch==0)
    {
        printf("\n\t\t\t�� л ʹ �� ͼ �� �� �� �� ϵ ͳ>_<");
        exit(1);
    }
    system("cls");
    shijian();
loop:printf("\n\n\t    ~ ~ ~ ~ ~ ~ �� ӭ �� �� ͼ �� �� �� �� ϵ ͳ ~ ~ ~ ~ ~ ~\n");
     printf("\t     * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
	 printf("\t\t- - - - - -\t\t    \t    - - - - - -\n");
	 printf("\t\t    * * * * \t\t    \t    * * * *\n");
    color(12);
	 printf("\t\t\t         ��  �ţ�");
     scanf("%s",&id);
     color(10);
	 printf("\n\t\t\t         ��  �룺");
	 int j =0 ;
     while((ch1 = getch()) != '\r')
     {
      if (ch1 == BACKSPACE)
      {
       if (j > 0)
       {
        password[--j] = NULL;
        printf("\b ");
        printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
       }
       else
        putchar(7);
      }
      else
      {
           password[j++] = ch1;
           printf("*");
      }
     }
    password[j] = '\0';
    printf("\n\n\t\t\t\t ");
    int sum=0,i,error;
    while(1)
    {
        color(14);
        error=isright();
        if(error ==0) break;
        else
        {
            system("cls");
            goto loop;
        }
    }
     printf("\t\t    * * * * \t\t    \t    * * * *\n");
	 printf("\t\t- - - - - -\t\t    \t    - - - - - -\n");
     printf("\t    * * * * * * * * * * * * * * * * * * * * * * * * * * *\n");
     printf("\t   ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~\n");
     color(16);
     if(id[0]=='S')
     {

            r=Student_verify(id,password,head2);
            if(r==NULL)
            {
                printf("\t\t �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
                getch();
                system("cls");
                goto loop;
            }
            else
            {
                system("cls");
                student_menu(head1,r,head2,fp2,head6);
            }
     }
      else if(id[0] == 'T')
     {
            s = Teacher_verify(id,password,head3);
            if(s == NULL)
            {
                printf("\t\t �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ");
                getch();
                system("cls");
                goto loop;
            }
            else
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }

     }
     else if(id[0] == 'A')
     {
            t = Tushu_Administration_verify(id,password,head4);
            if(t == NULL)
            {
                printf("\t\t  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
                getch();
                system("cls");
                goto loop;
            }
            else
            {
                system("cls");
                tushu_administration_menu(t,head4,fp4,head1,head6);
            }
     }
        else if(id[0] == 'X')
        {
            y = Xitong_Administration_verify(id,password,head5);
            if(y == NULL)
            {
                printf("\t\t �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
                getch();
                system("cls");
                goto loop;
            }
            else
            {
                system("cls");
                xitong_administration_menu(head2,head3,head4,head5,fp5,y);
            }
        }
        else
        {
            printf("\t\t  �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
            getch();
            system("cls");
            goto loop;
        }
}
int isright()
{
    int i,input,letter,flag=0;
    int t[4],num,upper,lower;
    char a,b,c,d;
    srand((unsigned)time(NULL));
    for(i=0;i<4;i++)
    {
        input=rand()%3;   //��֤�����Ϊ�����֡���д��ĸ��Сд��ĸ
        if(input==0) {num=rand()%10+48;printf("%c",num);t[i]=num;}  //����
        letter=rand()%26;
        if(input==1)       //��д��ĸ
        {upper=letter+65;printf("%c",upper);t[i]=upper;}
        if(input==2)       //Сд��ĸ
        {lower=letter+97;printf("%c",lower);t[i]=lower;}
    }
     printf(" �� ֤ �� ��");
     scanf(" %c%c%c%c",&a,&b,&c,&d);   //������֤��
     if(a==t[0]&&b==t[1]&&c==t[2]&&d==t[3])
         {printf("\n\t\t\t\t �� ֤ �� �� ȷ\n");flag =0;} //��֤��ƥ��
     else {printf("\t\t\t\t  �� ֤ �� �� ��\n");flag=1;}
     return flag;   //�����򷵻�1����ȷ����0
}
//ѧ����֤
STUDENT *Student_verify(char id[],char password[],STUDENT *head2)
{
    STUDENT *pre,*p;
    pre=NULL ;
    p=head2;
    if(!p)
    {
        printf("�ļ�Ϊ��!");
        getch();
        exit(0);
    }
    while(p)
	 {
	     if(strcmp(p->studentID,id)==0&&strcmp(p->password,password)==0)
		 {
			 pre=p;
			 break;
		 }
		 else
		 {
		    p=p->next2;
		 }
	 }
	 printf("%s",p->studentID);
     return pre;
}
//ѧ���˵�
void student_menu(BOOK *head1,STUDENT *r,STUDENT *head2,FILE *fp2,READERBOOKS *head6)
{
    int ch,flag;
    STUDENT *fp0;
    while(1)
    {

        system("cls");
        printf("\n\n\t\t\t  %s ͬ ѧ �� ӭ �� �٣�\n",r->studentName);
        printf("             ��������������������������������������������������\n");
        printf("             ��  ��      ѧ �� ͼ �� �� �� �� �� ��      ��  ��\n");
        printf("             ��  ������������������������������������������  ��\n");
        printf("             ��               ��[1]ѧ �� �� Ϣ               ��\n");
        printf("             ��                                              ��\n");
        printf("             ��               ��[2]�� �� ͼ ��               ��\n");
        printf("             ��                                              ��\n");
        printf("             ��               ��[3]�� �� �� ��               ��\n");
        printf("             ��                                              ��\n");
        printf("             ��               ��[4]�� �� �� ��               ��\n");
        printf("             ��                                              ��\n");
        printf("             ��               ��[5]�� ѯ �� ��               ��\n");
        printf("             ��                                              ��\n");
        printf("             ��               ��[0]�� �� �� ��               ��\n");
        printf("             ��������������������������������������������������\n");
        printf("\t\t\t  �� �� �� �� ѡ �� :");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            student_info(r);
            getch();
            break;
        case 2:
            student_borrow(head6,r);
            getch();
            break;
        case 3:
            student_borrowagain(head6,r);
            getch();
            break;
        case 4:
            flag = student_changepassword(r);
            if(flag)
            {
                STUDENT *p;
                p = head2;
                fclose(fp2);
                if(remove("ѧ����Ϣ")==0)
                if((fp0=fopen("ѧ����Ϣ","wb"))==NULL)
				 {
	                 printf("cannot open file,press any key to exit!");
	 	             getch();
	 	             exit(1);
				 }
                do
				{
				   fwrite(p,sizeof(STUDENT),1,fp0);
	 	           p = p->next2;
				}while(p);
                fclose(fp0);
            }
            getch();
            break;
        case 5:
            present_tushu_info(head1);
            getch();
            break;
        case 0:
            print();
            getch();
        }
    }

}
//ѧ��������Ϣ
void student_info(STUDENT *r)
{
    system("cls");
    printf("\n\n");
    printf("\t\t* * * * * * * ѧ �� �� �� �� Ϣ * * * * * * * *\n");
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    printf("\t\tѧ �ţ�%s",r->studentID);
    printf("\t\t���䣺%s\n\n",r->student_email);
    printf("\t\t�� ����%s",r->studentName);
    printf("\t\t�� ϵ �� ʽ��%s\n\n",r->Tell);
    printf("\t\t�� ��%s",r->studentSex);
    printf("\t\tѧ Ժ��%s\n\n",r->xueyuan);
    printf("\t\t�� ����%s",r->Class);
    printf("\tר ҵ��%s\n\n",r->major);
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n\t\t�� �� �� �� �� �� ѧ �� �� ����");
}
//ѧ���������
void student_borrow(READERBOOKS *head6,STUDENT *r)
{
    system("cls");
    printf("\n\t\t* * * * * * * * * * �� �� �� �� �� �� * * * * * * * * * * *");
    printf("\n\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    READERBOOKS *pre,*p;
    int i;
    pre=head6;
    p=head6->next6;
    while(p)
    {
        if(strcmp(p->readerID,r->studentID)==0)
            break;
        pre = p;
        p = p->next6;
    }
    printf("\t\t������������������������������-����������������������������\n");
    printf("\t\t���� �� �� ��     ���� �� �� ��  ����  ��         ���� ����\n");
    printf("\t\t������������������������������-����������������������������\n");
    for(i = 0 ;i < p->total_bookCount ; i++)
    {
        printf("\t\t�� %4d/%2d/%2d  ",p->borrowed_BooksTime[i].year,p->borrowed_BooksTime[i].mouth,p->borrowed_BooksTime[i].day);
        printf("\t  ��%4d/%2d/%2d  ",p->Return_BooksTime[i].year,p->Return_BooksTime[i].mouth,p->Return_BooksTime[i].day);
        printf(" ��%15s",p->readerBooks[i]);
        printf("��%4d",p->reader_BooksTimes[i]);
        printf(" ��\n\t\t��������������������������������-��������������������������\n");
    }
    printf("\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
    printf("\n\t\t�� �� �� �� �� �� �� �� ��");
}
//ѧ����������
void student_borrowagain(READERBOOKS *head6,STUDENT *r)
{
    system("cls");
    int flag,flag1;
    printf("\n\t\t\t* * * * * * * * ѧ �� �� �� �� �� * * * * * * * * ");
    READERBOOKS *pre,*p;
    int i;
    char shuming[N];
    pre=head6;
    p=head6->next6;
    while(p)
    {
        if(strcmp(p->readerID,r->studentID)==0)
            break;
        pre=p;
        p=p->next6;
    }
flag1: printf("\n\t\t\t        �� ǰ �� �� ͼ �� �� Ϣ �� �� ��\n");
    printf("\t\t������������������������������-����������������������������\n");
    printf("\t\t���� �� �� ��     ���� �� �� ��  ����  ��         ���� ����\n");
    printf("\t\t������������������������������-����������������������������\n");
    for(i = 0 ;i < p->total_bookCount ; i++)
    {
        printf("\t\t�� %4d/%02d/%02d  ",p->borrowed_BooksTime[i].year,p->borrowed_BooksTime[i].mouth,p->borrowed_BooksTime[i].day);
        printf("\t  ��%4d/%02d/%02d  ",p->Return_BooksTime[i].year,p->Return_BooksTime[i].mouth,p->Return_BooksTime[i].day);
        printf(" ��%15s",p->readerBooks[i]);
        printf("��%4d",p->reader_BooksTimes[i]);
        printf(" ��\n\t\t��������������������������������-��������������������������\n");
    }
    printf("\t\t - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
flag: printf("\n\t\t�� �� �� �� �� �� �� ��");
    scanf("%s",&shuming);
    for(i = 0 ;i < p->total_bookCount ; i++)
    {
        if(strcmp(shuming,p->readerBooks)==0) break;
    }
    if(i == p->total_bookCount||p->reader_BooksTimes>2)
    {
        printf("\n\n\t\t�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� һ �� ���� �� �� �� �룺");
        system("cls");
        goto flag1;
    }
    p->Return_BooksTime[i].mouth++;
    printf("\n\t\t�� �� �� �� �� �� ���� �� �� �� �� 0 ���� 1 �� �� �� �� ͼ �� �� Ϣ��");
    scanf("%d",&flag);
    p->reader_BooksTimes[i]++;
    if(flag == 0 )goto flag;
    else student_borrowagain(head6,r);
    printf("\n\t\t�� �� �� �� �� �� �� ���� �� �� �� �� �� �� �� �� ��");
}
//ѧ����������
int student_changepassword(STUDENT *r)
{
    system("cls");
    int num,flag = 0 ;
    char ch[N];
    system("cls");
    printf("\n\n\t\t^_^ ^_^ ^_^ ^_^ ^_^�� �� �� �� �� ��^_^ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t\t-----------------------------------------------------\n\n");
    printf("\t\t   �� �� �� Ը �� �� �� �� �� ���� 1 �� �� 0 ��:");
    scanf("%d",&num);
    printf("\n");
    if(num==1)
    {
        while(1)
        {
            printf("\t\t\t  �� �� �� �� �� �� �� �� ��:");
            scanf("%s",&ch);
            if(strcmp(ch,r->password)==0)
            {
                break;
            }
            else
            {
                system("cls");
                printf("\n\n");
            }
        }
        printf("\n");
        printf("\t\t\t      �� �� �� �� �� �� ��:");
        int j =0 ;
        char ch1;
        char new_password[N];
        while((ch1 = getch()) != '\r')
        {
        if (ch1 == BACKSPACE)
            {
            if (j > 0)
                {
                    new_password[--j] = NULL;
                    printf("\b ");
                    printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
                }
            else
            putchar(7);
            }
        else
        {
           new_password[j++] = ch1;
           printf("*");
        }
        }
        new_password[j] = '\0';
        printf("\n");
        strcpy(r->password,new_password);
        printf("\n\t\t\t       �� �� �� �� Ϊ :%s ",r->password);
        flag = 1;
        printf("\n\n\t\t\t        �� �� �� �� �� ��\n\n");
        printf("\t\t\t           -----------\n\n");
        printf("\t\t\t             ^^^^^^^\n\n");
    }
    printf("\t\t\t       �� �� �� �� �� �� ��");
    return flag;
}
//��ʦ��֤
TEACHER *Teacher_verify(char id[],char password[],TEACHER *head3)
{
    TEACHER *pre,*p;
    pre=NULL ;
    p=head3;
    if(!p)
    {
        printf("�ļ�Ϊ��!");
        getch();
        exit(0);
    }
    while(p)
	 {
	     if(strcmp(p->teacherID,id)==0&&strcmp(p->teacherPassword,password)==0)
		 {
			 pre=p;
			 break;
		 }
		 else
		 {
		    p=p->next3;
		 }
	 }
     return pre;
}
//��ʦ�˵�
void teacher_menu(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea)
{
    int ch;
    printf("\n\t\t       %s �� ʦ �� ӭ �� �� \n\n",s->teacherName);
    printf("             ��������������������������������������������������\n");
    printf("             ��  ��           �� ʦ �� ��                ��  ��\n");
    printf("             ��  ������������������������������������������  ��\n");
    printf("             ��           ��[1]�� ʦ �� Ϣ                   ��\n");
    printf("             ��                                              ��\n");
    printf("             ��           ��[2]�� �� ͼ ��                   ��\n");
    printf("             ��                                              ��\n");
    printf("             ��           ��[3]�� �� �� ��                   ��\n");
    printf("             ��                                              ��\n");
    printf("             ��           ��[4]�� �� �� ��                   ��\n");
    printf("             ��                                              ��\n");
    printf("             ��           ��[5]�� ѯ �� ��                   ��\n");
    printf("             ��                                              ��\n");
    printf("             ��           ��[6]�޸ĸ�����Ϣ                  ��\n");
    printf("             ��                                              ��\n");
    printf("             ��           ��[7]ͼ �� �� ��                   ��\n");
    printf("             ��                                              ��\n");
    printf("             ��           ��[0]�� �� �� ��                   ��\n");
        printf("             ��������������������������������������������������\n");
    printf("\t\t\tinput your choice:");
    scanf("%d",&ch);
    switch(ch)
    {
    case 1:
        teacher_info(s,head3,fp3,head1,head6,tea);getch(); break;
    case 2:
        teacher_borrow(s,head3,fp3,head1,head6,tea);  ;break;
    case 3:
        teacher_borowagin(s,head3,fp3,head1,head6,tea); break;
    case 4:
        teacher_changepassword(s,head3,fp3,head1,head6,tea); break;
    case 5:
        present_tushu_info(head1); break;
    case 6:
       teacher_changexinxi(s,head3,fp3,head1,head6,tea); break;
    case 7:
        teacher_seacherbook(s,head3,fp3,head1,head6,tea);break;
    case 0:
        print(); break;
    }
}
//��ʦ��ѯͼ��
void teacher_seacherbook(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea)
{
     system("cls");
    int y,m,d;
    time_t time_s;
    struct tm *date_time;
    time(&time_s);
    char id[10],book[N],tushu_leibie[N],book_name[20];
    int i,i1,j,choice,choice1,flag,flag1,flag2;
    int flag3,flag4,flag5,flag6=0;
    READERBOOKS *pre,*p;
    BOOK *q;BOOK *r,*s1;
    BOOK *pre1,*p1,*q1;
    pre1 = head1;
    p1= pre1->next1;
    date_time = localtime(&time_s);
    y=date_time->tm_year+1900;
    m=date_time->tm_mon+1;
    d=date_time->tm_mday;
    q = head1->next1;
    p = head6->next6;
    present_tushu_info(head1);
    printf("\n\t\t\t���� �� �� �� ID��");
    scanf("%s",&id);
    while(p)
    {
        if(strcmp(p->readerID,id) == 0) break;
        pre = p;
        p = p->next6;
    }
    if(p)
    {
        printf("\n\n\n\t\t�� Ŀ ǰ �� �� ͼ �� �� Ϣ �� �� ��\n\n");
        printf("\t������������������������������������-����������������������������������");
        printf("\n\t����������      ����������      ��   ����ͼ������       ���������   ��\n");
        printf("\t������������������������������������-����������������������������������\n");
        for(i = 0 ;i < p->total_bookCount ; i++)
        {
            printf("\t��%4d/%02d/%02d  ",p->borrowed_BooksTime[i].year,p->borrowed_BooksTime[i].mouth,p->borrowed_BooksTime[i].day);
            printf("\t��%d/%02d/%02d  ",p->Return_BooksTime[i].year,p->Return_BooksTime[i].mouth,p->Return_BooksTime[i].day);
            printf("\t��%17s",p->readerBooks[i]);
            printf("\t��%4d",p->reader_BooksTimes[i]);
            printf("       ��\n\t������������������������������������-����������������������������������\n");
        }
  m4:printf("\n\t\t\t���� �� �� �� �� ѡ �� 0 ��, 1 �� :");
    scanf("%d",&choice);
    switch(choice)
        {
        case 0:
            {
                for(i= 0 ; i < p->total_bookCount ; i++)
                {
                    if(p->reader_BooksTimes[i]==2) break;
                }
                if(i == p->total_bookCount)
                {

                            printf("\n\t\t\t���� �� �� �� �� ��");
                            scanf("%s",book_name);
                               while(p1)
                                {
                                    for(i1=0 ; i1 < p1->every_leibie_shu_totalcount ; i1++)
                                    {
                                        if(strcmp(p1->shuming[i1],book_name)==0)
                                        {
                                            flag6=1;
                                            break;
                                        }
                                    }
                                    pre1 = p1;
                                    p1=p1->next1;
                                }
                               if(!flag6)
                                {
                                    printf("\n\t\t\tû�д���!\n");
                                    goto m4;
                                }
							r = head1->next1;
                            strcpy(p->readerBooks[p->total_bookCount],book_name);
                            p->borrowed_BooksTime[p->total_bookCount].year=date_time->tm_year+1900;
                            p->borrowed_BooksTime[p->total_bookCount].mouth=date_time->tm_mon+1;
                            p->borrowed_BooksTime[p->total_bookCount].day=date_time->tm_mday;
                            p->Return_BooksTime[p->total_bookCount].year=date_time->tm_year+1900;
                            p->Return_BooksTime[p->total_bookCount].mouth=date_time->tm_mon+2;
                            p->Return_BooksTime[p->total_bookCount].day=date_time->tm_mday;
                            p->reader_BooksTimes[p->total_bookCount] = 1;
                            p->total_bookCount++;
                            printf("\n\t\t\t��� �� �� �� ��^ - ^ ,�� �� �� �� �� �� 0 ������ص��˵�!");
                            scanf("%d",&flag);
                            if(flag ==0 )
                            {
                                system("cls");
                                flag3 = 1;
                                present_book_info(head1,book_name,flag3);
                                teacher_seacherbook(s,head3,fp3,head1,head6,tea);
                            }
                            else
                            {
                                system("cls");
                                teacher_menu(s,head3,fp3,head1,head6,tea);
                            }
                }
                break;
            }
        case 1:
            {
                printf("\n\t\t\t���� �� �� �� �� ��");
                scanf("%s",&book_name);
                for(i = 0 ; i < p->total_bookCount;)
                {
                    if(strcmp(p->readerBooks[i],book_name)!=0)i++;
                    else break;
                }
                for(j = i ; j < p->total_bookCount ; j++)
                {
                    p->borrowed_BooksTime[j].year = p->borrowed_BooksTime[j+1].year;
                    p->borrowed_BooksTime[j].mouth = p->borrowed_BooksTime[j+1].mouth;
                    p->borrowed_BooksTime[j].day = p->borrowed_BooksTime[j+1].day;
                    p->Return_BooksTime[j].year = p->Return_BooksTime[j+1].year;
                    p->Return_BooksTime[j].mouth = p->Return_BooksTime[j+1].mouth;
                    p->Return_BooksTime[j].day = p->Return_BooksTime[j+1].day;
                    strcpy(p->readerBooks[j],p->readerBooks[j+1]);
                    p->reader_BooksTimes[j] = p->reader_BooksTimes[j+1];
                }
                p->total_bookCount--;
                printf("\n\t\t\t�� �� �� �� ��^ - ^ ,�� �� �� �� �� �� 0 ������ص��˵�!");
                scanf("%d",&flag);
                if(flag ==0 )
                {
                system("cls");
                flag4 =2;
                present_book_info(head1,book_name,flag4);
                teacher_seacherbook(s,head3,fp3,head1,head6,tea);
                }
                else
                {
                    system("cls");
                    teacher_menu(s,head3,fp3,head1,head6,tea);
               }
               break ;
            }
        }
    }
    else
        printf("\n\t\tδ �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
}
//��ʦ�ı�����
void teacher_changepassword(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea)
{
    TEACHER *p;
    p = head3;char ch1;int j=0,j1=0;
    fclose(fp3);
    system("cls");
    char a,d,b[N],c[N],e[N];
    printf("\n�Ƿ��޸�����N or Y?");
    scanf(" %c",&a);
    if(a=='y'||a=='Y')
    {
            do
            {
                    system("cls");
                    printf("����ɵ����룺");
                    scanf("%s",b);
            }while(strcmp(s->teacherPassword,b)!=0);
          m2:  printf("\n�����µ����룺");j=0;
          while((ch1 = getch()) != '\r')
            {
              if (ch1 == BACKSPACE)
              {
               if (j > 0)
               {
                e[--j] = NULL;
                printf("\b ");
                printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
               }
               else
                putchar(7); //bell
              }
              else
              {
                   e[j++] = ch1;
                   printf("*");
              }
            }
     e[j] = '\0';
        printf("\n\n�ٴ�ȷ�����룺");  j1=0;
    while((ch1 = getch()) != '\r')
    {
      if (ch1 == BACKSPACE)
      {
       if (j1 > 0)
       {
        c[--j1] = NULL;
        printf("\b ");
        printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
       }
       else
        putchar(7); //bell
      }
      else
      {
           c[j1++] = ch1;
           printf("*");
      }
    }
     c[j1] = '\0';
            if(strcmp(e,c)) goto m2;
              strcpy(s->teacherPassword,c);
                if(remove("��ʦ��Ϣ")==0)
                if((fp3=fopen("��ʦ��Ϣ","wb"))==NULL)
				 {
	                 printf("cannot open file,press any key to exit!");
	 	             getch();
	 	             exit(1);
				 }
                do
				{
				   fwrite(p,sizeof(TEACHER),1,fp3);
	 	           p = p->next3;
				}while(p);
				 fclose(fp3);
            printf("\n\n�޸�����ɹ���");
            printf("\n\n���޸ĵ�����Ϊ��%s  ���ס��",c);
            printf("\n\n�Ƿ����N or Y:");
            scanf(" %c",&d);
            if(d=='y'||d=='Y')
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
            else
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
    }
             else
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
}
//��ʦ����
void teacher_borowagin(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea)
{
    system("cls");
    int flag=1;
    char a[20],d;
    READERBOOKS *p;
    p=head6->next6;
    int i=0,j;
    int m,m1,y,d1;
    time_t time_s;
    struct tm *date_time;
    time(&time_s);
    date_time = localtime(&time_s);
    d1=date_time->tm_mday;y=date_time->tm_mon;m=(y-p->borrowed_BooksTime[i].mouth)*20+(d1-p->borrowed_BooksTime[i].day);
    m1=d1-p->borrowed_BooksTime[i].day;
    while(p)
    {
        if(strcmp(s->teacherID,p->readerID)== 0) break;
        p=p->next6;
    }
    j=p->total_bookCount;
    printf("\n\t\t                  %s�� ʦ  �� �ã�  ��Ľ������Ϊ��\n\n\n",s->teacherName);
    printf("\t\t\t          ����ͼ��               ��������       �黹����   �ۼƽ������\n");
    printf("\t\t\t-----------------------------------------------------------------------------\n");
    for(i=0;i<j;i++)
    {
            printf("\t\t\t%20s           %5d/%02d/%02d     %d/%02d/%02d        %d\n",p->readerBooks[i],p->borrowed_BooksTime[i].year,p->borrowed_BooksTime[i].mouth,p->borrowed_BooksTime[i].day,p->Return_BooksTime[i].year,p->Return_BooksTime[i].mouth,p->Return_BooksTime[i].day,p->reader_BooksTimes[i]);
    }
    m3:printf("\n\t\t\t�Ƿ�����? N or Y:");
      scanf(" %c",&d);
      if(d=='y'||d=='Y')
            {
                printf("\n\t\t\t��������Ҫ�����������");
                scanf("%s",a);
                for(i=0;i<j;i++)
                {
                            if(strcmp(a,p->readerBooks[i])==0&&p->reader_BooksTimes[i]<2)
                           {
                               if(p->reader_BooksTimes[i]==2&&m>60)
                               {
                                   printf("\n\t\t\t���������������Գ��ڲ������裡\n");
                                   goto m3;
                               }
                               if(m1<20||p->reader_BooksTimes[i]==1&&m>30)
                               {
                                   printf("\n\t\t\t���������ڻ�����Գ��ڲ������裡\n");
                                   goto m3;
                               }
                               else
                               {
                                   if(p->borrowed_BooksTime[i].mouth<12)
                                  ++p->Return_BooksTime[i].mouth;
                               else
                               {
                                   p->borrowed_BooksTime[i].year++;
                                   p->borrowed_BooksTime[i].mouth=1;
                               }
                               printf("\n\t\t\t����ɹ���\n");
                               flag=0;
                               ++p->reader_BooksTimes[i];
                               }
                           }
                }
                   if(flag)
                   {
                       printf("\n\t\t\t��������ȷ���Ѿ�����������費�ɹ���\n");
                   }
                   printf("\n\t\t\t�Ƿ��������? N or Y:");
                   scanf(" %c",&d);
                   if(d=='y'||d=='Y')
                   {
                           teacher_borowagin(s,head3,fp3,head1,head6,tea);
                   }
                   else
                   {
                       system("cls");
                       teacher_menu(s,head3,fp3,head1,head6,tea);
                   }
            }
            else
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
}
//��ʦ�������
void teacher_borrow(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea)
{
    system("cls");
    char d;
    READERBOOKS *p;
    p=head6->next6;
    int i=0,j;
    while(p)
    {
        if(strcmp(s->teacherID,p->readerID)== 0) break;
        p=p->next6;
    }
    j=p->total_bookCount;
    printf("\n\t\t                  %s�� ʦ  �� �ã�  ��Ľ������Ϊ��\n\n\n",s->teacherName);
    printf("\t\t\t          ����ͼ��               ��������       �黹����   �ۼƽ������\n");
    printf("\t\t\t----------------------------------------------------------------------------\n");
    for(i=0;i<j;i++)
    {
            printf("\t\t\t%20s           %5d/%02d/%02d     %d/%02d/%02d        %d\n",p->readerBooks[i],p->borrowed_BooksTime[i].year,p->borrowed_BooksTime[i].mouth,p->borrowed_BooksTime[i].day,p->Return_BooksTime[i].year,p->Return_BooksTime[i].mouth,p->Return_BooksTime[i].day,p->reader_BooksTimes[i]);
    }
    printf("\n\t\t\t�� Y �������˵� N����:");
            scanf(" %c",&d);
            if(d=='y'||d=='Y')
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
            else
                getchar();
}
//��ʦ�ı���Ϣ
void teacher_changexinxi(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea)
{
    TEACHER *p;
    p = head3;
    fclose(fp3);
    system("cls");
    char a,d,c[N],c1[N];
    int b;
    printf("\n�Ƿ��޸Ľ�ʦ��ϢN or Y?");
    scanf(" %c",&a);
    system("cls");
    if(a=='y'||a=='Y')
    {
        printf("\t\t\t*******************************\n");
        printf("\t\t\t****                       ****\n");
        printf("\t\t\t**** 1:�޸���ϵ��ʽ        ****\n");
        printf("\t\t\t**** 2: �޸�����           ****\n");
        printf("\t\t\t****                       ****\n");
        printf("\t\t\t*******************************\n");
        printf("\t\t\t");
        scanf("%d",&b);
        switch(b)
        {
        case 1:
            printf("\t\t\t�ɵ���ϵ��ʽ��%s\n",s->teacherTell);
            m2:printf("\n\t\t\t�����µ���ϵ��ʽ��");
            scanf("%s",c);
            if(strlen(c)!=11)
            {
                printf("\n\t\t\t�ֻ���λ�����ԣ�");
                goto m2;
            }
            m1:printf("\n\t\t\t�ٴ�ȷ���µ���ϵ��ʽ��");
            scanf("%s",c1);
            if(strcmp(c,c1)==0)
            {
                strcpy(s->teacherTell,c);
                if(remove("��ʦ��Ϣ")==0)
                if((fp3=fopen("��ʦ��Ϣ","wb"))==NULL)
				 {
	                 printf("cannot open file,press any key to exit!");
	 	             getch();
	 	             exit(1);
				 }
                do
				{
				   fwrite(p,sizeof(TEACHER),1,fp3);
	 	           p = p->next3;
				}while(p);
				 fclose(fp3);
            teacher_info(s,head3,fp3,head1,head6,tea);
            }
            else
            {
                printf("\t\t\tȷ�ϲ���ȷ��");
                goto m1;
            }
            printf("\n\n\t\t\t�Ƿ����N or Y:");
            scanf(" %c",&d);
            if(d=='y'||d=='Y')
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
            else
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
            break;
        case 2:
            printf("\t\t\t�ɵ���ϵ��ʽ��%s\n",s->teacher_email);
            printf("\t\t\t�����µ����䣺");
            scanf("%s",c);
            strcpy(s->teacher_email,c);
            if(remove("��ʦ��Ϣ")==0)
                if((fp3=fopen("��ʦ��Ϣ","wb"))==NULL)
				 {
	                 printf("cannot open file,press any key to exit!");
	 	             getch();
	 	             exit(1);
				 }
                do
				{
				   fwrite(p,sizeof(TEACHER),1,fp3);
	 	           p = p->next3;
				}while(p);
				 fclose(fp3);
            teacher_info(s,head3,fp3,head1,head6,tea);
            printf("\n\n\t\t\t�Ƿ����N or Y:");
            scanf(" %c",&d);
            if(d=='y'||d=='Y')
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
           else
            {
                system("cls");
                teacher_menu(s,head3,fp3,head1,head6,tea);
            }
            break;
        }
    }
    else
    {
        system("cls");
        teacher_menu(s,head3,fp3,head1,head6,tea);
    }
}
//��ʦ��Ϣ
void teacher_info(TEACHER *s,TEACHER *head3,FILE *fp3,BOOK *head1,READERBOOKS *head6,TEACHER *tea)
{
    char d;
    system("cls");
    printf("\n\n");
    printf("\t\t* * * * * * * �� ʦ �� �� �� Ϣ * * * * * * * *\n");
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - -\n\n");
    printf("\t\t�� ����%s",s->teacherName);
    printf("\t\t�� ��%s\n",s->teacherSex);
    printf("\n\t\t��ѧ�ţ�%s",s->teacherID);
    printf("\t\t�� ϵ �� ʽ��%s\n\n",s->teacherTell);
    printf("\t\t���䣺%s\n\n",s->teacher_email);
    printf("\t\t- - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *\n");
    printf("\t\t�� Y �������˵�:");
    scanf(" %c",&d);
    if(d=='y'||d=='Y')
    {
        system("cls");
        teacher_menu(s,head3,fp3,head1,head6,tea);
    }
}
//ͼ�����Ա��֤
TUSHU_ADMINISTRATION *Tushu_Administration_verify(char id[],char password[],TUSHU_ADMINISTRATION *head4)
{
    TUSHU_ADMINISTRATION *pre,*p;
    pre=NULL ;
    p=head4;
    if(!p)
    {
        printf("�ļ�Ϊ��!");
        getch();
        exit(0);
    }
    while(p)
	 {
	     if(strcmp(p->tushu_administrationID,id)==0&&strcmp(p->tushu_administrationPassword,password)==0)
		 {
			 pre=p;
			 break;
		 }
		 else
		 {
		    p=p->next4;
		 }
	 }
     return pre;
}
//ͼ�����Ա�˵�
void tushu_administration_menu(TUSHU_ADMINISTRATION *t,TUSHU_ADMINISTRATION *head4,FILE *fp4,BOOK *head1,READERBOOKS *head6)
{
    TUSHU_ADMINISTRATION *fp0;
    int  chioce,flag;
   while(1)
   {
        system("cls");
          printf("\n\t\t      %s ͼ �� �� �� Ա �� ӭ �� ��\n\n",t->tushu_administrationName);
          printf("             ��������������������������������������������������\n");
          printf("             ��  ��         ͼ �� �� �� Ա �� ��         ��  ��\n");
          printf("             ��  ������������������������������������������  ��\n");
          printf("             ��          ��[1]�� ѯ �� �� �� �� Ϣ           ��\n");
          printf("             ��                                              ��\n");
          printf("             ��          ��[2]�� �� �� �� �� �� ��           ��\n");
          printf("             ��                                              ��\n");
          printf("             ��          ��[3]�� �� �� �� �� �� ��           ��\n");
          printf("             ��                                              ��\n");
          printf("             ��          ��[4]�� �� �� �� �� �� ��           ��\n");
          printf("             ��                                              ��\n");
          printf("             ��          ��[5]�� ѯ �� �� �� �� Ϣ           ��\n");
          printf("             ��                                              ��\n");
          printf("             ��          ��[6]�� ͼ �� �� �� �� ��           ��\n");
          printf("             ��                                              ��\n");
          printf("             ��          ��[7]�� �� �� ��                    ��\n");
          printf("             ��                                              ��\n");
          printf("             ��          ��[0]�� �� �� ��                    ��\n");
          printf("             ��������������������������������������������������\n");
        printf("\t\t\t �� �� �� �� ѡ �� :");
        scanf("%d",&chioce);
        switch(chioce)
        {
        case 1:
            tushu_administration_info(t);
            getch();
            break;
        case 2:
            flag = tushu_administration_changepassword(t);
            if(flag == 1)
            {
                TUSHU_ADMINISTRATION *p;
                p = head4;
                fclose(fp4);
                if(remove("ͼ�����Ա��Ϣ")==0)
                if((fp0=fopen("ͼ�����Ա��Ϣ","wb"))==NULL)
				 {
	                 printf("cannot open file,press any key to exit!");
	 	             getch();
	 	             exit(1);
				 }
                do
				{
				   fwrite(p,sizeof(TUSHU_ADMINISTRATION),1,fp0);
	 	           p = p->next4;
				}while(p);
                fclose(fp0);
            }
            getch();
            break;
        case 3:
            help_reader_borrow_lend(head6,head1);
            getch();
            break;
        case 4:
            look_reader_borrow(head6);
            getch();
            break;
        case 5:
            present_tushu_info(head1);
            getch();
            break;
        case 6:
            book_in(head1);
            getch();
            break;
        case 7:
            book_out(head1);
            break;
            getch();
        case 0:
            print();
            getch();
            break;
        default:
            printf("error!");
            break;
        }
   }
}
//ͼ�����Ա��Ϣ
void tushu_administration_info(TUSHU_ADMINISTRATION *t)
{
    system("cls");
    printf("\n\n");
    printf("\t   ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ͼ �� �� �� Ա �� �� �� Ϣ  ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t     ---------------------------------------------------------------------------\n\n");
    printf("\t      |  �� ��  |    �� ��    |    �� ��   |  �� ϵ �� ʽ  |      ��    ��    |\n\n");
    printf("\t          %s        %s           %s        %s    %s \n\n",t->tushu_administrationID,t->tushu_administrationName,t->tushu_administrationSex,t->tushu_administrationTell,t->tushu_administration_email);
    printf("\t     ---------------------------------------------------------------------------\n");
    printf("\n\t   ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t   �� �� �� �� �� �� ��");
}
//ͼ�����Ա��������
int tushu_administration_changepassword(TUSHU_ADMINISTRATION *t)
{
    int num,j=0,flag = 0;
    TUSHU_ADMINISTRATION *p;
    char password[10],new_password[10],ch1,e[10];
    system("cls");
    printf("\n\n\t\t^_^ ^_^ ^_^ ^_^ ^_^�� �� �� �� �� ��^_^ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t\t-----------------------------------------------------\n\n");
    printf("\t\t   �� �� �� Ը �� �� �� �� �� ���� 1 �� �� 0 ��:");
    scanf("%d",&num);
    printf("\n");
    if(num==1)
    {
        while(1)
        {
            printf("\t\t\t  �� �� �� �� �� �� �� �� ��:");
            scanf("%s",&password);
            if(strcmp(password,t->tushu_administrationPassword)==0)
            {
                break;
            }
            else
            {
                system("cls");
                printf("\n\n");
            }
        }
        printf("\n");
        printf("\t\t\t      �� �� �� �� �� �� ��:");
        int j =0 ;
        char ch1;
        char new_password[N];
        while((ch1 = getch()) != '\r')
        {
        if (ch1 == BACKSPACE)
            {
            if (j > 0)
                {
                    new_password[--j] = NULL;
                    printf("\b ");
                    printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
                }
            else
            putchar(7);
            }
        else
        {
           new_password[j++] = ch1;
           printf("*");
        }
        }
        new_password[j] = '\0';
        printf("\n");
        strcpy(t->tushu_administrationPassword,new_password);
        printf("\n\t\t\t       �� �� �� �� Ϊ :%s ",t->tushu_administrationPassword);
        flag = 1;
        printf("\n\n\t\t\t        �� �� �� �� �� ��\n\n");
        printf("\t\t\t           -----------\n\n");
        printf("\t\t\t             ^^^^^^^\n\n");
    }
    printf("\t\t\t       �� �� �� �� �� �� ��");
    return flag;
}
//Ϊ���߽���
void help_reader_borrow_lend(READERBOOKS *head6,BOOK *head1)
{
    system("cls");
    int y,m,d;
    time_t time_s;
    struct tm *date_time;
    time(&time_s);
    date_time = localtime(&time_s);
    y=date_time->tm_year+1900;
    m=date_time->tm_mon+1;
    d=date_time->tm_mday;
    char id[10],book[N],tushu_leibie[N],book_name[20];
    int i,j,choice,choice1,flag,flag1,flag2;
    int flag3,flag4,flag5;
    READERBOOKS *pre,*p;
    BOOK *q;
    q = head1->next1;
    p = head6->next6;
    printf("\n\n\t\t^_^ ^_^ ^_^ ͼ �� �� �� Ա Ϊ �� �� �� �� ͼ �� ��^_^ ^_^ ^_^ \n\n");
    printf("\t\t���� �� �� �� ID��");
    scanf("%s",&id);
    while(p)
    {
        if(strcmp(p->readerID,id) == 0) break;
        pre = p;
        p = p->next6;
    }
    if(p)
    {
        printf("\n\n\n\t\t�� Ŀ ǰ �� �� ͼ �� �� Ϣ �� �� ��\n\n");
        printf("\t������������������������������������-����������������������������������");
        printf("\n\t����������      ����������      ��   ����ͼ������       ���������   ��\n");
        printf("\t������������������������������������-����������������������������������\n");
        for(i = 0 ;i < p->total_bookCount ; i++)
        {
            printf("\t��%4d/%02d/%02d  ",p->borrowed_BooksTime[i].year,p->borrowed_BooksTime[i].mouth,p->borrowed_BooksTime[i].day);
            printf("\t��%d/%02d/%02d  ",p->Return_BooksTime[i].year,p->Return_BooksTime[i].mouth,p->Return_BooksTime[i].day);
            printf("\t��%17s",p->readerBooks[i]);
            printf("\t��%4d",p->reader_BooksTimes[i]);
            printf("       ��\n\t������������������������������������-����������������������������������\n");
        }
flag: printf("\n\t\t���� �� �� �� �� ѡ �� 0 ��, 1 �� :");
    scanf("%d",&choice);
    switch(choice)
        {
        case 0:
            {
                for(i= 0 ; i < p->total_bookCount ; i++)
                {
                    if(p->reader_BooksTimes[i]==3) break;
                }
                if(i == p->total_bookCount)
                {
                    printf("\n\t\t���� �� �� �� ѡ �� 0 �� 1 �� �� :");
                    scanf("%d",&choice1);
                    switch(choice1)
                    {
                        case 0:
                        {
                            printf("\n\t\t���� �� �� �� �� ��");
                            scanf("%s",book_name);
							BOOK *r,*s;
							r = head1->next1;
                            strcpy(p->readerBooks[p->total_bookCount],book_name);
                            p->borrowed_BooksTime[p->total_bookCount].year=date_time->tm_year+1900;
                            p->borrowed_BooksTime[p->total_bookCount].mouth=date_time->tm_mon+1;
                            p->borrowed_BooksTime[p->total_bookCount].day=date_time->tm_mday;
                            p->Return_BooksTime[p->total_bookCount].year=date_time->tm_year+1900;
                            p->Return_BooksTime[p->total_bookCount].mouth=date_time->tm_mon+2;
                            p->Return_BooksTime[p->total_bookCount].day=date_time->tm_mday;

                            p->reader_BooksTimes[p->total_bookCount] = 1;
                            p->total_bookCount++;
                            printf("\n\t\t��� �� �� �� ��^O^ , �� 1 �� �� �� �� �� �� �� �� ��");
                            scanf("%d",&flag);
                            if(flag ==0 )goto flag;
                            else present_borrow_tushu(head6,id);
                            flag3 = 1;
                            present_book_info(head1,book_name,flag3);
                            printf("\n\t\t�� �� �� �� �� 0 �� �� �� ������ �� �� �� �� �� �� �� ʾ �� �� �� �� �� �ɣ�  ");
                            int flag7;
                            scanf("%d",&flag7);
                            if(flag7 ==0 )goto flag;
                            else   printf("\n\t\t�� �� �� �� �� �� �� �� �� ��");
                        break;
                        }
                    case 1:
                    {
                        printf("\n\t\t���� �� �� �� �� ��");
                        scanf("%s",&book);
                        for(i = 0 ; i < p->total_bookCount;)
                        {
                            if(strcmp(p->readerBooks[i],book)!=0)i++;
                            else break;
                        }
                        printf("%s",p->readerBooks[i]);
                        p->reader_BooksTimes[i]++;
                        p->Return_BooksTime[i].mouth++;

                        printf("\n\t\t���� �� �� �� �� ��^O^ , �� 1 �� �� �� �� �� �� �� �� ��");
                        scanf("%d",&flag);
                        if(flag == 1) present_borrow_tushu(head6,id);
                        printf("\n\t\t�� �� �� �� �� 0 �� �� �� �� ���� �� �� �� �� �� �� �� ʾ �� �� �� �� �� �ɣ�  ");
                        int flag6;
                        scanf("%d",&flag6);
                        if(flag6 ==0 )goto flag;
                        else   printf("\n\t\t�� �� �� �� �� �� �� �� �� ��");
                        break;

                    }
                 }
                }
                else
                    printf("\n\t\t��ͬ ѧ ���� �� �� �� �� �� ���� �� �� �� ��");
                break;
            }
        case 1:
            {
                printf("\n\t\t���� �� �� �� �� ��");
                scanf("%s",&book);
                for(i = 0 ; i < p->total_bookCount;)
                {
                    if(strcmp(p->readerBooks[i],book)!=0)i++;
                    else break;
                }
                for(j = i ; j < p->total_bookCount ; j++)
                {
                    p->borrowed_BooksTime[j].year = p->borrowed_BooksTime[j+1].year;
                    p->borrowed_BooksTime[j].mouth = p->borrowed_BooksTime[j+1].mouth;
                    p->borrowed_BooksTime[j].day = p->borrowed_BooksTime[j+1].day;
                    p->Return_BooksTime[j].year = p->Return_BooksTime[j+1].year;
                    p->Return_BooksTime[j].mouth = p->Return_BooksTime[j+1].mouth;
                    p->Return_BooksTime[j].day = p->Return_BooksTime[j+1].day;
                    strcpy(p->readerBooks[j],p->readerBooks[j+1]);
                    p->reader_BooksTimes[j] = p->reader_BooksTimes[j+1];
                }
                p->total_bookCount--;
                printf("\n\t\t�� �� �� �� �� �� �� 1 �� �� �� �� ͼ �� ��");
                scanf("%d",&flag);
                if(flag ==0)goto flag;
                else present_borrow_tushu(head6,id);
                flag4 = 2;
                present_book_info(head1,book,flag4);
                printf("\n\t\t�� �� �� �� �� 0 �� �� �� ������ �� �� �� �� �� �� �� ʾ �� �� �� �� �� �ɣ�");
                int flag8;
                scanf("%d",&flag8);
                if(flag8 ==0 )goto flag;
                else printf("\n\t\t�� �� �� �� �� �� �� �� ����");
                break;

            }
        }
    }
    else
        printf("\n\t\tδ �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
}
//�ٴβ�ѯ����ͼ��
void present_borrow_tushu(READERBOOKS *head6,char c[])
{
    system("cls");
    READERBOOKS *pre,*p,*q;
    int count,i;
    p = head6->next6;
    while(p)
    {
        if(strcmp(p->readerID,c)==0)
            break;
            p =p->next6;
    }
    printf("\n\n\n\t\t�� �� ǰ �� �� ͼ �� �� Ϣ �� �� ��\n\n");
    printf("\t������������������������������������-����������������������������������");
    printf("\n\t����������      ����������      ��   ����ͼ������       ���������   ��\n");
    printf("\t������������������������������������-����������������������������������\n");
    for(i = 0 ;i < p->total_bookCount ; i++)
    {
        printf("\t��%4d/%02d/%02d  ",p->borrowed_BooksTime[i].year,p->borrowed_BooksTime[i].mouth,p->borrowed_BooksTime[i].day);
        printf("\t��%d/%02d/%02d  ",p->Return_BooksTime[i].year,p->Return_BooksTime[i].mouth,p->Return_BooksTime[i].day);
        printf("\t��%17s",p->readerBooks[i]);
        printf("\t��%4d",p->reader_BooksTimes[i]);
        printf("       ��\n\t������������������������������������-����������������������������������\n");
    }
}
//�ٴβ�ѯͼ����Ϣ
void present_book_info(BOOK *head1,char book_name[],int flag)
{
    int i;
    BOOK *pre,*p,*q;
    pre = head1;
    p = pre->next1;
    while(p)
    {
        for(i = 0 ; i < p->every_leibie_shu_totalcount ; i++)
        {
            if(strcmp(p->shuming[i],book_name)==0)
            {
                if(flag == 1) p->leftCount[i]--;
                if(flag == 2) p->leftCount[i]++;
                break;
            }
        }
        pre = p;
        p = p->next1;
    }
}
//�鿴���߽������
void look_reader_borrow(READERBOOKS *head6)
{
    system("cls");
    READERBOOKS *pre,*p,*q;
    int count,i;
    p = head6->next6;
    printf("\n\n\t^_^ ^_^ ^_^ ^_^ �� �� �� �� �� �� �� �� �� ^_^ ^_^ ^_^ ^_^");
    while(p->next6)
    {
        printf("");
        printf("\n\n\t�� �� �� Ϊ %s �� �� �� %d �� ͼ ��,�� �� �� �� �� �� �� ��\n\n",p->readerID,p->total_bookCount);
        printf("\t������������������������������������-����������������������������������");
        printf("\n\t����������      ����������      ��   ����ͼ������       ���������   ��\n");
        printf("\t������������������������������������-����������������������������������\n");
        for(i = 0 ;i < p->total_bookCount ; i++)
        {
            printf("\t��%4d/%02d/%02d  ",p->borrowed_BooksTime[i].year,p->borrowed_BooksTime[i].mouth,p->borrowed_BooksTime[i].day);
            printf("\t��%d/%d/%d  ",p->Return_BooksTime[i].year,p->Return_BooksTime[i].mouth,p->Return_BooksTime[i].day);
            printf("\t��%17s",p->readerBooks[i]);
            printf("\t��%4d",p->reader_BooksTimes[i]);
            printf("       ��\n\t������������������������������������-����������������������������������\n");
        }
        printf("\n");
        p = p->next6;
    }
    printf("\n\n\t�� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� �� ��");
}
//��ͼ����Ϣ
void present_tushu_info(BOOK *head1)
{
    int i,count = 0,flag,f=0;
    system("cls");
    BOOK *p;
    p = head1->next1;
    printf("\n\n\t^_^ ^_^ ^_^ ^_^ ͼ �� �� �� �� �� Ϣ �� �� ^_^ ^_^ ^_^ ^_^ \n\n");
    printf("\t\t �� �� ͼ �� �� �� 80 �� ���� ϸ �� �� ��");
    while(p->next1)
    {
        printf("\n\t�� �� Ϊ '%s' �� �� Ŀ �� �� %d �� �� �� Ϣ �� �£�\n",p->category,p->every_leibie_shu_totalcount);
        printf(" ��������������������������������������������������������������������-������������������������������������������������������������������������");
        printf("\n ���� �� �� �ک�                ��  ��   ��        �� �ũ�                   �� �� ��              �� �� �� λ��  �� ����   �� ����    �۸� �� \n");
        printf(" ��������������������������������������������������������������������-������������������������������������������������������������������������\n");
        for(i = 0 ; i < p->every_leibie_shu_totalcount ; i++)
        {
            printf(" ��%4d/%02d/%02d ",p->books_in_library[i].year,p->books_in_library[i].mouth,p->books_in_library[i].day);
            printf("��%25s",p->shuming[i]);
            printf("��%13s",p->tushubianhao[i]);
            printf("��%25s",p->author[i]);
            printf("��%25s",p->publishing_company[i]);
            printf("��%6d",p->totalCount[i]);
            printf(" ��%7d",p->leftCount[i]);
            printf(" ��    %.1f",p->price[i]);
            printf(" ��\n ��������������������������������������������������������������������-������������������������������������������������������������������������\n");
            Sleep(105);
        }
        p = p->next1;
    }
    printf("�� �� ���� �� �� �� ͼ �� �� ȫ �� �� �� ���� �� �� �� �� �� �� �� �� ��");
}
//�������
void book_in(BOOK *head1){
    system("cls");
    int count = 0,i,flag;
    char code[10],tushu_leibie[10];
    BOOK *pre,*p,*q;
    pre = head1;
    p = head1->next1;
    printf("\t\t\t^_^ ^_^ ^_^ ^_^ �� �� �� �� �� �� ^_^ ^_^ ^_^ ^_^\n");
   o:q = (BOOK*)malloc(sizeof(BOOK));
    printf("\n\t\t\t\t  �� �� �� ͼ �� �� �� :");
    scanf("%s",q->category);
    while(p->next1)
    {
        if(strcmp(p->category,q->category)==0)break;
        p = p->next1;
        count++;
    }
    if(count >= 20)
    {
        q->every_leibie_shu_totalcount = 0;
        printf("\n\t\t\t�� �� �� �� �� �� ʱ �� ��");
        scanf("%d",&q->books_in_library[0].year);
        scanf("%d",&q->books_in_library[0].mouth);
        scanf("%d",&q->books_in_library[0].day);
        printf("\n\t\t\t�� �� �� �� �� �� �� �� ��");
        scanf("%s",&q->tushubianhao[0]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%s",&q->shuming[0]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%d",&q->totalCount[0]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%d",&q->leftCount[0]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%lf",&q->price[0]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%s",&q->author[0]);
        printf("\n\t\t\t�� �� �� �� �� �� �� �̣�");
        scanf("%s",&q->publishing_company[0]);
        q->every_leibie_shu_totalcount++;
        q->next1=NULL;
        q->next1 = pre->next1;
        pre->next1 = q;
    }
    else
    {
        printf("\n\t\t\t�� �� �� �� �� �� ʱ �� ��");
        scanf("%d",&p->books_in_library[p->every_leibie_shu_totalcount].year);
        scanf("%d",&p->books_in_library[p->every_leibie_shu_totalcount].mouth);
        scanf("%d",&p->books_in_library[p->every_leibie_shu_totalcount].day);
        printf("\n\t\t\t�� �� �� �� �� �� �� �� ��");
        scanf("%s",&p->tushubianhao[p->every_leibie_shu_totalcount]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%s",&p->shuming[p->every_leibie_shu_totalcount]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%d",&p->totalCount[p->every_leibie_shu_totalcount]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%d",&p->leftCount[p->every_leibie_shu_totalcount]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%lf",&p->price[p->every_leibie_shu_totalcount]);
        printf("\n\t\t\t�� �� �� �� �� �� �� ��");
        scanf("%s",&p->author[p->every_leibie_shu_totalcount]);
        printf("\n\t\t\t�� �� �� �� �� �� �� �̣�");
        scanf("%s",&p->publishing_company[p->every_leibie_shu_totalcount]);
        p->every_leibie_shu_totalcount++;
    }
    printf("\n\n\t\t\t�� �� �� �� �� �� 1 ���� �� �� 0 :");
    scanf("%d",&flag);
    if(flag == 1) goto o;
    else printf("\n\n\t\t\t�� �� �� �� �� �� �� �� ��!");
}
//ͼ�����
void book_out(BOOK *head1)
{
    system("cls");
    int i,j,flag;
    char leibie[N],tushu_name[N];
    BOOK *pre,*p,*q;
    pre = head1 ;
    p = pre->next1;
    printf("\n\t\t^o^  ^o^ ^o^ ͼ �� �� �� �� �� ��^o^  ^o^  ^o^ ");
    flag:printf("\n\n\t\t\t�� �� �� Ҫ ɾ �� �� ͼ �� �� ��  ��");
    scanf("%s",&leibie);
    while(p->next1)
    {
        if(strcmp(leibie,p->category) == 0)break;
        p = p->next1;
    }
    printf("\n\n\t\t\t������ͼ�����֣�");
    scanf("%s",&tushu_name);
    for(i = 0 ; i < p->every_leibie_shu_totalcount ; i++)
    {
        if(strcmp(tushu_name,p->shuming[i])==0)break;
    }
    for(j = i ; j < p->every_leibie_shu_totalcount-1 ; j++)
    {
        p->books_in_library[j].year = p->books_in_library[j+1].year;
        p->books_in_library[j].mouth = p->books_in_library[j+1].mouth;
        p->books_in_library[j].day = p->books_in_library[j+1].day;
        strcpy(p->tushubianhao[j],p->tushubianhao[j+1]);
        strcpy(p->shuming[j],p->shuming[j+1]);
        p->totalCount[j] = p->totalCount[j+1];
        p->leftCount[j] = p->leftCount[j+1];
        strcpy(p->author[j],p->author[j+1]);
        p->price[j] = p->price[j+1];
        strcpy(p->publishing_company[j],p->publishing_company[j+1]);
    }
    p->every_leibie_shu_totalcount--;
    printf("\n\t\t\tY(^_^)Y�� �� �� �� ɾ �� �� �� ��");
    printf("\n\n\t\t\t�� �� ɾ �� �� �� 1 �� �� �� 0 ��");
    scanf("%d",&flag);
    if(flag==1) goto flag;
}
//ϵͳ����Ա��֤
XITONG_ADMINISTRATION *Xitong_Administration_verify(char id[],char password[],XITONG_ADMINISTRATION *head5)
{
    XITONG_ADMINISTRATION *pre,*p;
    pre=NULL ;
    p=head5;
    if(!p)
    {
        printf("�ļ�Ϊ��!");
        getch();
        exit(0);
    }
    while(p)
	 {
	     if(strcmp(p->xitong_administrationID,id)==0&&strcmp(p->xitong_administrationPassword,password)==0)
		 {
			 pre=p;
			 break;
		 }
		 else
		 {
		    p=p->next5;
		 }
	 }
     return pre;
}
//ϵͳ����Ա�˵�
void xitong_administration_menu(STUDENT *head2,TEACHER *head3,TUSHU_ADMINISTRATION *head4,XITONG_ADMINISTRATION *head5,FILE *fp5,XITONG_ADMINISTRATION *y)
{
    while(1)
    {
        system("cls");
        printf("\n\t\t\t      %s  �� ӭ �� ��\n\n",y->xitong_administrationName);
        printf("             ��������������������������������������������������\n");
        printf("             ��  ��        ϵ ͳ �� �� Ա �� ��          ��  ��\n");
        printf("             ��  ������������������������������������������  ��\n");
        printf("             ��            ��[1]�� ѯ �� �� �� �� Ϣ         ��\n");
        printf("             ��                                              ��\n");
        printf("             ��            ��[2]�� �� �� �� �� �� ��         ��\n");
        printf("             ��                                              ��\n");
        printf("             ��            ��[3]�� ְ �� �� �� �� Ϣ         ��\n");
        printf("             ��                                              ��\n");
        printf("             ��            ��[4]�� ɾ ְ �� �� �� ��         ��\n");
        printf("             ��                                              ��\n");
        printf("             ��            ��[0]�� �� �� ��                  ��\n");
        printf("             ��������������������������������������������������\n");
        int chioce;
        printf("\t\t\t �� �� �� �� �� ѡ �� :");
        scanf("%d",&chioce);
        int flag;
        XITONG_ADMINISTRATION *fp0;
        switch(chioce)
        {
        case 1:
            xitong_administration_info(y);
            getch();
            break;
        case 2:
            flag=xitong_administration_changepassword(y);
            if(flag == 1)
            {
                XITONG_ADMINISTRATION *p;
                p = head5;
                fclose(fp5);
                if(remove("ϵͳ����Ա��Ϣ")==0)
                if((fp0=fopen("ϵͳ����Ա��Ϣ","wb"))==NULL)
				 {
	                 printf("cannot open file,press any key to exit!");
	 	             getch();
	 	             exit(1);
				 }
                do
				{
				   fwrite(p,sizeof(XITONG_ADMINISTRATION),1,fp0);
	 	           p = p->next5;
				}while(p);
				 fclose(fp0);
            }
            getch();
            break;
        case 3:
            xitong_administration_find_reader(head2,head3,head4);
            getch();
            break;
        case 4:
            xitong_administration_add_or_delete_reader(head2,head3,head4);
            getch();
            break;
        case 0:
            print();
            getch();
        }
    }
}
//ϵͳ����Ա������Ϣ
void xitong_administration_info(XITONG_ADMINISTRATION *y)
{
    system("cls");
    printf("\n\n");
    printf("\t   ^_^ ^_^ ^_^ ^_^ ϵ ͳ �� �� Ա �� �� �� Ϣ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t   ----------------------------------------------------------\n\n");
    printf("\t       |  �� ��  |    �� ��    |    �� ��   |  �� ϵ �� ʽ  |\n\n");
    printf("\t           %s        %s           %s        %s\n\n",y->xitong_administrationID,y->xitong_administrationName,y->xitong_administrationSex,y->xitong_administrationTell);
    printf("\t   ----------------------------------------------------------\n");
    printf("\n\t   ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t   �� �� �� �� �� �� ��");
}
//ϵͳ����Ա�޸�����
int xitong_administration_changepassword(XITONG_ADMINISTRATION *y)
{
    system("cls");
    int num,flag = 0;
    char ch[10];
    char ch1[10];
    system("cls");
    printf("\n\n\t\t^_^ ^_^ ^_^ ^_^ ^_^�� �� �� �� �� ��^_^ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t\t-----------------------------------------------------\n\n");
    printf("\t\t   �� �� �� Ը �� �� �� �� �� ���� 1 �� �� 0 ��:");
    scanf("%d",&num);
    printf("\n");
    if(num==1)
    {
        while(1)
        {
            printf("\t\t\t  �� �� �� �� �� �� �� �� ��:");
            scanf("%s",&ch);
            if(strcmp(ch,y->xitong_administrationPassword)==0)
            {
                break;
            }
            else
            {
                system("cls");
                printf("\n\n");
            }
        }
        printf("\n");
        printf("\t\t\t      �� �� �� �� �� �� ��:");
        int j =0 ;
        char ch1;
        char new_password[N];
        while((ch1 = getch()) != '\r')
        {
        if (ch1 == BACKSPACE)
            {
            if (j > 0)
                {
                    new_password[--j] = NULL;
                    printf("\b ");
                    printf("%c%c%c", BACKSPACE, ' ', BACKSPACE);
                }
            else
            putchar(7);
            }
        else
        {
           new_password[j++] = ch1;
           printf("*");
        }
        }
        new_password[j] = '\0';
        printf("\n");
        strcpy(y->xitong_administrationPassword,new_password);
        printf("\n\t\t\t       �� �� �� �� Ϊ :%s ",y->xitong_administrationPassword);
        flag = 1;
        printf("\n\n\t\t\t        �� �� �� �� �� ��\n\n");
        printf("\t\t\t           -----------\n\n");
        printf("\t\t\t             ^^^^^^^\n\n");
    }
    printf("\t\t\t       �� �� �� �� �� �� ��");
    return flag;
}
//ϵͳ����Ա�鿴ְ���������Ϣ
void xitong_administration_find_reader(STUDENT *head2,TEACHER *head3,TUSHU_ADMINISTRATION *head4)
{
    system("cls");
    STUDENT *p;
    TEACHER *q;
    TUSHU_ADMINISTRATION *t;
    printf("\n\n\t\t^_^ ^_^ ^_^ ^_^ ^_^ �� �� �� �� �� ְ �� �� Ϣ ^_^ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t\t\t-----------------------------------------------------\n\n");
    int choice;
    char ID[N];
    printf("\t\t\t  �� ѯ �� �� �� Ϣ �� �� 0 , �� 1 ȫ �� �� ����");
    scanf("%d",&choice);
    if(choice == 0)
    {
        printf("\n\n\t\t\t\t   �� �� �� �� �� ID �� ��");
        scanf("%s",ID);
        if(ID[0] == 'S')
        {
            STUDENT *p;
            p = head2->next2;
            while(p->next2)
            {
                if(strcmp(ID,p->studentID)==0)break;
                p = p->next2;
            }
            system("cls");
            if(!p->next2)
            {
                printf("\n\n\t\t�� �� �� ��δ �� �� �� ͬ ѧ !");
            }
            else
            {
                printf("\t\t* * * * * * * ѧ �� �� �� �� Ϣ * * * * * * * *\n");
                printf("\t\t  - - - - - - - - - - - - - - - - - - - - - -\n\n");
                printf("\t\tѧ �ţ�%s",p->studentID);
                printf("\t\t���䣺%s\n\n",p->student_email);
                printf("\t\t�� ����%s",p->studentName);
                printf("\t\t�� ϵ �� ʽ��%s\n\n",p->Tell);
                printf("\t\t�� ��%s",p->studentSex);
                printf("\t\tѧ Ժ��%s\n\n",p->xueyuan);
                printf("\t\t�� ����%s",p->Class);
                printf("\tר ҵ��%s\n\n",p->major);
                printf("\t\t  - - - - - - - - - - - - - - - - - - - - - -\n");
                printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *");
            }
        }
        else if(ID[0] == 'T')
        {
            TEACHER *p;
            p = head3->next3;
            while(p->next3)
            {
                if(strcmp(ID,p->teacherID)==0)break;
                p = p->next3;
            }
            system("cls");
            if(!p->next3)printf("\n\n\t\t�� �� �� ��δ �� �� �� �� ʦ ��");
            printf("\t\t* * * * * * * �� ʦ �� �� �� Ϣ * * * * * * * *\n");
            printf("\t\t - - - - - - - - - - - - - - - - - - - - - - -\n\n");
            printf("\t\t�� ����%s",p->teacherName);
            printf("\t\t�� ��%s\n",p->teacherSex);
            printf("\n\t\t��ѧ�ţ�%s",p->teacherID);
            printf("\t\t�� ϵ �� ʽ��%s\n\n",p->teacherTell);
            printf("\t\t���䣺%s\n\n",p->teacher_email);
            printf("\t\t  - - - - - - - - - - - - - - - - - - - - - -\n");
            printf("\t\t* * * * * * * * * * * * * * * * * * * * * * * *");
        }
        else if(ID[0] == 'A')
        {
            TUSHU_ADMINISTRATION *p;
            p = head4->next4;
            while(p->next4)
            {
                if(strcmp(ID,p->tushu_administrationID)==0)break;
                p = p->next4;
            }
            system("cls");
            if(!p->next4)printf("\n\n\t\t�� �� �� ��δ �� �� �� ͼ �� �� �� Ա");
            printf("\t   ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ͼ �� �� �� Ա �� �� �� Ϣ  ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^\n\n");
            printf("\t     ---------------------------------------------------------------------------\n\n");
            printf("\t      |  �� ��  |    �� ��    |    �� ��   |  �� ϵ �� ʽ  |      ��    ��    |\n\n");
            printf("\t          %s        %s           %s        %s    %s \n\n",p->tushu_administrationID,p->tushu_administrationName,p->tushu_administrationSex,p->tushu_administrationTell,p->tushu_administration_email);
            printf("\t     ---------------------------------------------------------------------------\n");
            printf("\n\t   ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^ ^_^\n\n");
        }
    }
    else
    {
        p = head2->next2->next2->next2;
        printf("\n\n\t\t\t********�� �� Ϊ ѧ �� �� Ϣ ��******** \n\n");
        printf("\t\t������������������������������������������������������-����������������������������������������������������");
        printf("\n\t        �� �� ���� �� �� �� ѧ �� ��  ��  ��    ѧ  Ժ  ��  �� ѧ  ר ҵ  ��  ��  ��    ��  ��  ��  �� ϵ �� ʽ  ��\n");
        printf("\t\t������������������������������������������������������-����������������������������������������������������\n");
        while(p->next2->next2->next2)
        {
            printf("\t\t��%6s",p->studentName);
            printf("��%4s",p->studentSex);
            printf("   ��%6s",p->studentID);
            printf(" ��%20s",p->xueyuan);
            printf("��%16s",p->major);
            printf("��%20s",p->Class);
            printf("��%15s",p->Tell);
            printf("��\n\t\t������������������������������������������������������-����������������������������������������������������\n");
            p = p->next2;
        }
        q = head3->next3;
        printf("\n\n\t\t\t****�� �� Ϊ �� ʦ �� Ϣ ��**** \n");
        printf("\t\t������������������������-��������������������");
        printf("\n\t\t��  �� �� ��  �� �� �� ְ �� �� �� ϵ �� ʽ��\n");
        printf("\t\t������������������������-��������������������\n");
        while(q->next3)
        {
            printf("   \t\t��%6s",q->teacherName);
            printf("  ��%4s",q->teacherSex);
            printf("    ��%7s",q->teacherID);
            printf("��%s",q->teacherTell);
            q = q->next3;
            printf(" ��\n\t\t������������������������-��������������������\n");
        }
        t = head4->next4->next4 ;
       printf("\n\n\t\t   ****�� �� Ϊ ͼ �� �� �� Ա �� Ϣ ��****\n");
        printf("\t\t������������������������-��������������������");
        printf("\n\t\t��  �� �� ��  �� �� �� �� �� �� �� ϵ �� ʽ��\n");
        printf("\t\t������������������������-��������������������\n");
       while(t->next4->next4 )
       {
            printf("   \t\t��%6s",t->tushu_administrationName);
            printf("  ��%4s",t->tushu_administrationSex);
            printf("    ��%7s",t->tushu_administrationID);
            printf("��%s",t->tushu_administrationTell);
            t = t->next4;
            printf(" ��\n\t\t������������������������-��������������������\n");
      }
    }
    printf("\n\n\t\t �� �� �� �� �� �� �� �� ��");
}
//ϵͳ����Ա��ɾְ���Ի������Ϣ
void xitong_administration_add_or_delete_reader(STUDENT *head2,TEACHER *head3,TUSHU_ADMINISTRATION *head4)
{
    system("cls");
    char ID[N];
    int flag,num;
   n: printf("\n\n\t\t^_^ ^_^ ^_^ ^_^ ^_^ �� ɾ �� �� �� ְ �� ^_^ ^_^ ^_^ ^_^ ^_^\n\n");
    printf("\t\t  -----------------------------------------------------\n\n");
    printf("\t\t       �� �� �� �� �� ѡ �� 0 �� ��1 ɾ �� :");
    scanf("%d",&flag);
    printf("\n\n");
    if(flag == 0)
    {
        printf("\t\t          �� �� �� Ҫ ¼ �� �� �� �� ID ��");
        scanf("%s",ID);
        if(ID[0] == 'S')
        {
            STUDENT *pre,*p;
            pre = head2;
            p = (STUDENT*)malloc(sizeof(STUDENT));
            printf("\n\t\t           �� �� �� ѧ �� �� �� ��");
            scanf("%s",&p->studentName);
            printf("\t\t           �� �� �� ѧ �� �� �� ��");
            scanf("%s",&p->password);
            printf("\t\t           �� �� �� ѧ �� �� �� ��");
            scanf("%s",&p->studentSex);
            printf("\n\t\t           �� �� �� ѧ �� �� �� ��");
            scanf("%s",&p->Tell);
            printf("\n\t\t           �� �� �� ѧ �� ѧ Ժ ��");
            scanf("%s",&p->xueyuan);
            printf("\n\t\t           �� �� �� ѧ �� �� �� ��");
            scanf("%s",&p->major);
            printf("\n\t\t           �� �� �� ѧ �� �� �� ��");
            scanf("%s",&p->Class);
            printf("\n\t\t           �� �� �� ѧ �� E-mail ��");
            scanf("%s",&p->student_email);
            strcpy(p->studentID,ID);
            p->next2 = NULL;
            p->next2 = pre->next2->next2->next2;
            pre->next2->next2->next2 = p;
        }
        if(ID[0] == 'T')
        {
            TEACHER *p,*pre;
            pre = head3;
            p = (TEACHER*)malloc(sizeof(TEACHER));
            printf("\n\t\t           �� �� �� �� ʦ �� �� ��");
            scanf("%s",&p->teacherName);
            printf("\n\t\t           �� �� �� �� ʦ �� �� ��");
            scanf("%s",&p->teacherPassword);
            printf("\n\t\t           �� �� �� �� ʦ �� �� ��");
            scanf("%s",&p->teacherSex);
            printf("\n\t\t           �� �� �� �� ʦ �� �� ��");
            scanf("%s",&p->teacherTell);
            printf("\n\t\t           �� �� �� �� ʦ ְ λ ��");
            scanf("%s",&p->teacherPosition);
            printf("\n\t\t           �� �� �� �� ʦ E-mail ��");
            scanf("%s",&p->teacher_email);
            strcpy(p->teacherID,ID) ;
            p->next3 = pre->next3;
            pre->next3 = p;
        }
        if(ID[0] == 'A')
        {
            TUSHU_ADMINISTRATION *p,*pre;
            pre = head4;
            p=(TUSHU_ADMINISTRATION*)malloc(sizeof(TUSHU_ADMINISTRATION));
            printf("\n\t\t           �� �� �� ͼ �� �� �� Ա �� �� ��");
            scanf("%s",&p->tushu_administrationName);
            printf("\n\t\t           �� �� �� ͼ �� �� �� Ա �� �� ��");
            scanf("%s",&p->tushu_administrationPassword);
            printf("\n\t\t           �� �� �� ͼ �� �� �� Ա �� �� ��");
            scanf("%s",&p->tushu_administrationSex);
            printf("\n\t\t           �� �� �� ͼ �� �� �� Ա �� �� ��");
            scanf("%s",&p->tushu_administrationTell);
            printf("\n\t\t           �� �� �� ͼ �� �� �� Ա E-mail ��");
            scanf("%s",&p->tushu_administration_email);
            strcpy(p->tushu_administrationID,ID);
            p->next4 = pre->next4->next4;
            pre->next4->next4 = p;
        }
    }
    else
    {
        printf("\t\t        �� �� �� Ҫ ɾ �� �� ID ��");
        scanf("%s",ID);
        if(ID[0] == 'S')
        {
            STUDENT *pre,*p;
            pre = head2;
            p = head2->next2;
            while(p->next2)
            {
                if(strcmp(ID,p->studentID)==0)break;
                pre = p;
                p = p->next2;
            }
            pre->next2 = p->next2;
            free(p);
        }
        if(ID[0] == 'T')
        {
            TEACHER *pre,*p;
            pre = head3;
            p = head3->next3;
            while(p->next3)
            {
                if(strcmp(ID,p->teacherID)==0)break;
                pre = p;
                p = p->next3;
            }
            pre->next3 = p->next3;
            free(p);
        }
        if(ID[0] == 'A')
        {
            TUSHU_ADMINISTRATION *pre,*p;
            pre = head4;
            p = head4->next4;
            while(p->next4)
            {
                if(strcmp(ID,p->tushu_administrationID)==0)break;
                pre = p;
                p = p->next4;
            }
            pre->next4 = p->next4;
            free(p);
        }
    }
    printf("\n\n\t\t�� ɾ �� �� �� �� ���� �� �� �� 0 ���� �� �� 1��");
    scanf("%d",&num);
    if(num == 0 ) {system("cls");goto n;}
    else printf("\n\n\t\t        �� �� �� �� �� �� ϵ ͳ �� ����");
}
//¼��ͼ����Ϣ
/*BOOK *creat_book()
{
    int i,j;
    BOOK *head,*p,*q;
    printf("please input book infomation:\n");
    head=(BOOK*)malloc(sizeof(BOOK));
    head->next1=NULL;
    p = head;
    scanf("%s",&p->category);
    scanf("%d",&p->every_leibie_shu_totalcount);
    for(i = 0 ; i < 4 ; i++)
    {
        scanf("%d",&p->books_in_library[i].year);
        scanf("%d",&p->books_in_library[i].mouth);
        scanf("%d",&p->books_in_library[i].day);
        scanf("%s",&p->tushubianhao[i]);
        scanf("%s",&p->shuming[i]);
        scanf("%d",&p->totalCount[i]);
        scanf("%d",&p->leftCount[i]);
        scanf("%lf",&p->price[i]);
        scanf("%s",&p->author[i]);
        scanf("%s",&p->publishing_company[i]);
    }
      for(j=0;j<19;j++)
      {
        q=(BOOK*)malloc(sizeof(BOOK));
        scanf("%s",&q->category);
        scanf("%d",&q->every_leibie_shu_totalcount);
        for(i = 0 ; i < 4 ; i++)
        {
            scanf("%d",&q->books_in_library[i].year);
            scanf("%d",&q->books_in_library[i].mouth);
            scanf("%d",&q->books_in_library[i].day);
            scanf("%s",&q->tushubianhao[i]);
            scanf("%s",&q->shuming[i]);
            scanf("%d",&q->totalCount[i]);
            scanf("%d",&q->leftCount[i]);
            scanf("%lf",&q->price[i]);
            scanf("%s",&q->author[i]);
            scanf("%s",&q->publishing_company[i]);
        }
        q->next1=NULL;
        p->next1=q;
        p=q;
     }

    return head;
}

//¼��ѧ������Ϣ
STUDENT *creat_student()
{
    int i;
    STUDENT *head,*p,*q;
    printf("please input student information:\n");
    head=(STUDENT*)malloc(sizeof(STUDENT));
    head->next2=NULL;
    p=head;
    scanf("%s",&p->studentID);
    scanf("%s",&p->studentName);
    scanf("%s",&p->password);
    scanf("%s",&p->studentSex);
    scanf("%s",&p->Tell);
    scanf("%s",&p->xueyuan);
    scanf("%s",&p->major);
    scanf("%s",&p->Class);
    scanf("%s",&p->student_email);
    for(i=0;i<11;i++)
    {
        q=(STUDENT*)malloc(sizeof(STUDENT));
        scanf("%s",&q->studentID);
        scanf("%s",&q->studentName);
        scanf("%s",&q->password);
        scanf("%s",&q->studentSex);
        scanf("%s",&q->Tell);
        scanf("%s",&q->xueyuan);
        scanf("%s",&q->major);
        scanf("%s",&q->Class);
        scanf("%s",&q->student_email);
        q->next2=NULL;
        p->next2=q;
        p=q;
    }
    return head;
}
//¼���ʦ����Ϣ
TEACHER *creat_teacher()
{
    int i;
    TEACHER *head,*p,*q;
    printf("please input teacher infomation:\n");
    head=(TEACHER*)malloc(sizeof(TEACHER));
    head->next3=NULL;
    p=head;
    scanf("%s",&p->teacherID);
    scanf("%s",&p->teacherName);
    scanf("%s",&p->teacherPassword);
    scanf("%s",&p->teacherSex);
    scanf("%s",&p->teacherTell);
    scanf("%s",&p->teacherPosition);
    scanf("%s",&p->teacher_email);
    for(i=0;i<4;i++)
    {
        q=(TEACHER*)malloc(sizeof(TEACHER));
        scanf("%s",&q->teacherID);
        scanf("%s",&q->teacherName);
        scanf("%s",&q->teacherPassword);
        scanf("%s",&q->teacherSex);
        scanf("%s",&q->teacherTell);
        scanf("%s",&q->teacherPosition);
        scanf("%s",&q->teacher_email);
        q->next3=NULL;
        p->next3=q;
        p=q;
    }
    return head;
}
//¼��ͼ�����Ա��Ϣ
TUSHU_ADMINISTRATION *creat_tushu_administration()
{
    int i;
    printf("please input Tushu_Administration infomation:\n");
    TUSHU_ADMINISTRATION *head,*p,*q;
    head=(TUSHU_ADMINISTRATION*)malloc(sizeof(TUSHU_ADMINISTRATION));
    head->next4=NULL;
    p=head;
    scanf("%s",&p->tushu_administrationID);
    scanf("%s",&p->tushu_administrationName);
    scanf("%s",&p->tushu_administrationPassword);
    scanf("%s",&p->tushu_administrationSex);
    scanf("%s",&p->tushu_administrationTell);
    scanf("%s",&p->tushu_administration_email);
    for(i=0;i<2;i++)
    {
        q=(TUSHU_ADMINISTRATION*)malloc(sizeof(TUSHU_ADMINISTRATION));
        scanf("%s",&q->tushu_administrationID);
        scanf("%s",&q->tushu_administrationName);
        scanf("%s",&q->tushu_administrationPassword);
        scanf("%s",&q->tushu_administrationSex);
        scanf("%s",&q->tushu_administrationTell);
        scanf("%s",&q->tushu_administration_email);
        q->next4=NULL;
        p->next4=q;
        p=q;
    }
    return head;
}
//¼��ϵͳ����Ա��Ϣ
XITONG_ADMINISTRATION *creat_xitong_administration()
{
    int i;
    printf("please input Xitong_Administration infomation:\n");
    XITONG_ADMINISTRATION *head,*p,*q;
    head=(XITONG_ADMINISTRATION*)malloc(sizeof(XITONG_ADMINISTRATION));
    scanf("%s",&head->xitong_administrationID);
    scanf("%s",&head->xitong_administrationName);
    scanf("%s",&head->xitong_administrationPassword);
    scanf("%s",&head->xitong_administrationSex);
    scanf("%s",&head->xitong_administrationTell);
    head->next5=NULL;
    return head;
}

//¼����߽�����Ϣ
READERBOOKS *creat_readerbooks()
{
    int i,j;
    printf("please input readerbooks infomation:\n");
    READERBOOKS *head,*p,*q;
    head=(READERBOOKS*)malloc(sizeof(READERBOOKS));
    head->next6=NULL;
    p=head;
    scanf("%s",&p->readerID);
    scanf("%d",&p->total_bookCount);
    if(p->total_bookCount==10)
    {
        for(j=0;j<10;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    else if(p->total_bookCount==9)
    {
        for(j=0;j<9;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    else if(p->total_bookCount==8)
    {
        for(j=0;j<8;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    if(p->total_bookCount==7)
    {
        for(j=0;j<7;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    else if(p->total_bookCount==6)
    {
        for(j=0;j<6;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    if(p->total_bookCount==5)
    {
        for(j=0;j<5;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    else if(p->total_bookCount==4)
    {
        for(j=0;j<4;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    else if((p->total_bookCount==3))
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    else if((p->total_bookCount==2))
    {
        for(j=0;j<2;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    else if((p->total_bookCount==1))
    {
        for(j=0;j<1;j++)
        {
            scanf("%d",&p->borrowed_BooksTime[j].year);
            scanf("%d",&p->borrowed_BooksTime[j].mouth);
            scanf("%d",&p->borrowed_BooksTime[j].day);
            scanf("%d",&p->Return_BooksTime[j].year);
            scanf("%d",&p->Return_BooksTime[j].mouth);
            scanf("%d",&p->Return_BooksTime[j].day);
            scanf("%s",&p->readerBooks[j]);
            scanf("%d",&p->reader_BooksTimes[j]);
        }
    }
    else
    {
        printf("�ö�����δ���飡");
    }
    for(i=0;i<16;i++)
    {
        q=(READERBOOKS*)malloc(sizeof(READERBOOKS));
        scanf("%s",&q->readerID);
        scanf("%d",&q->total_bookCount);
        if(q->total_bookCount==10)
        {
            for(j = 0 ; j < 10 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        else if(q->total_bookCount==9)
        {
            for(j = 0 ; j < 9 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        else if(q->total_bookCount==8)
        {
            for(j = 0 ; j < 8 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        if(q->total_bookCount==7)
        {
            for(j = 0 ; j < 7 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        else if(q->total_bookCount==6)
        {
            for(j = 0 ; j < 6 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        if(q->total_bookCount==5)
        {
            for(j = 0; j < 5 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        else if(q->total_bookCount==4)
        {
            for(j = 0 ; j < 4 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        else if((q->total_bookCount==3))
        {
            for(j = 0 ; j < 3 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        else if((q->total_bookCount==2))
        {
            for(j = 0 ; j < 2 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        else if((q->total_bookCount==1))
        {
            for(j = 0 ; j < 1 ; j++)
            {
                scanf("%d",&q->borrowed_BooksTime[j].year);
                scanf("%d",&q->borrowed_BooksTime[j].mouth);
                scanf("%d",&q->borrowed_BooksTime[j].day);
                scanf("%d",&q->Return_BooksTime[j].year);
                scanf("%d",&q->Return_BooksTime[j].mouth);
                scanf("%d",&q->Return_BooksTime[j].day);
                scanf("%s",&q->readerBooks[j]);
                scanf("%d",&q->reader_BooksTimes[j]);
            }
        }
        else
        {
            printf("�ö�����δ���飡");
        }
        q->next6=NULL;
        p->next6=q;
        p=q;
  }
    return head;
}*/


