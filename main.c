//����ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <dos.h>
#include <time.h>

//�궨��
#define HEIGHT 23
#define WIDTH 80
#define LEN sizeof(struct commodity)
#define USER_1 "user_1.dat"
#define USER_2 "user_2.dat"
#define PRODUCT "product.dat"
#define MES "mes.dat"
#define BUY_RECORD "buy_record.dat"

struct message{
    char name[30];
    char content[100];
    char contract[20];
    char date[30];
};//�����û��ķ�����Ϣ

struct record{
    char name[20];
    char product[30];
    int quantity;
    char date[15];
};//�����û��Ĺ����¼


struct commodity{
    int num;//��Ʒ���
    char name[15];//��Ʒ����
    double in_price;//����
    double out_price;//�ۼ�
    char desc[100];//��Ʒ����
    int count;//�����
    char sort[30];//���
    int sold;//������
    char provider[50];//������
} ;
//�ṹ������
struct user{
    char name[20];
    char sex[10];
    char phone[20];
    char mail[30];
    char pass[20];
    char pass_double[20];
};
//�����û�����Ϣ



void start();
void goToXY();
void drawBorder();
void drawTitle();
void admin_main(char *name);
void cus_main(char *name);
void progressBar(char *text);//������
void admin_login();
void cus_login();
void admin_register();
void cus_register();
void admin_login_login();
void cus_login_login();
void hideCursor();
void switch_admin(int choice,char *name);
void switch_cus(int choice,char *name);
void del_comm(char *name);
void color_change(char *name);
void send_mes(char *name);
void receive_mes(char *name);
int count_mes();//�����û�������Ϣ������
void show_page(char *file_name,char *str,char *name,int ver);
void page_up(char *file_name,char *str,int num,char *name,int ver);
void page_down(char *file_name,char *str,int num,char *name,int ver);
void drawInBorder();//������ҳ��ѯ���ڲ����߿�
void change_comm(char *name);
void add_comm(char *name);
void buy_record(char *name);
void buy_product(char *name);
void sort_search(char *name);
void admin_unsubscribe(char *name);
void cus_unsubscribe(char *name);




int i,j,k;//����ѭ������
int del_num;

int main()
{
    system("color f1");
    hideCursor();
    start();
    return 0;
}
void start(){
    int state = 0;//�����û������ѡ����Ϣ��0Ϊ����Ա��1Ϊ�˿�
    drawBorder();
    drawTitle();
    goToXY(24,9);
    printf("��ѡ��������ݽ��е�¼��ע�᣺");
    goToXY(26,12);
    printf("��  ��  ���й���Ա");
    goToXY(26,14);
    printf("��      �˿�");
    goToXY(26,16);
    printf("��      �˳�ϵͳ");

    while(TRUE){
        char choice;
        choice = getch();
        if(choice == 72){
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1){
                state = 2;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == 80){
            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");
        }else if(choice == '\r'){
            switch(state){
                case 0:
                    progressBar("ϵͳ���ڼ��أ����Ժ�");
                    Sleep(100);
                    system("cls");
                    admin_login();
                    break;

                case 1:
                    progressBar("ϵͳ���ڼ��أ����Ժ�");
                    Sleep(100);
                    system("cls");
                    cus_login();
                    break;
                case 2:
                    goToXY(0,24);
                    exit(0);
            }
        }
    }
    getchar();
}
void goToXY(int x,int y){
    COORD position;
    position.X = x;
    position.Y = y;
    HANDLE handle;
    handle=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(handle, position);
}
void drawBorder(){
    goToXY(0,0);
    for(i = 1;i < WIDTH;i++){
        printf("=");
    }
    goToXY(0,0);
    printf("�X");
    goToXY(WIDTH-2,0);
    printf("�[");
    for(i = 1;i < HEIGHT;i++){
        goToXY(0,i);
        printf("�U");
        goToXY(WIDTH-2,i);
        printf("�U");
    }
    goToXY(0,HEIGHT);
    for(i = 1;i < WIDTH;i++){
            printf("=");
    }
    goToXY(0,HEIGHT);
    printf("�^");
    goToXY(WIDTH-2,HEIGHT);
    printf("�a");
}
void drawTitle(){
    goToXY(25,3);
    for(i = 0;i < 26;i++){
        printf("*");
    }
    goToXY(25,5);
    for(i = 0;i < 26;i++){
        printf("*");
    }
    for(i = 4;i < 5;i++){
        goToXY(25,i);
        printf("*");
        goToXY(50,i);
        printf("*");
    }
    goToXY(30,4);
    printf("��ӭʹ��MMS V1.0");
}
void admin_main(char *name){
    drawBorder();
    goToXY(60,3);
    printf("��ӭ����%s!",name);
    goToXY(28,3);
    printf("****�����б�****");
    goToXY(29,5);
    printf("1.�����Ʒ��Ϣ");
    goToXY(29,6);
    printf("2.�޸���Ʒ��Ϣ");
    goToXY(29,7);
    printf("3.�����ѯ����");
    goToXY(29,8);
    printf("4.ɾ����Ʒ��Ϣ");
    goToXY(29,9);
    printf("5.�û�������Ϣ");
    goToXY(29,10);
    printf("6.�����Ϣ��ѯ");
    goToXY(29,11);
    printf("6.������Ϣ��ѯ");
    goToXY(29,12);
    printf("7.��ҳ��ʾ��Ʒ��Ϣ");
    goToXY(29,13);
    printf("8.���»�����Ϣ");
    goToXY(29,14);
    printf("10.��ѯ��Ʒ��Ϣ");
    goToXY(29,15);
    printf("11.���Ľ�����ɫ");
    goToXY(29,16);
    printf("12.��Ʒ��Ϣ����");
    goToXY(29,17);
    printf("13.ע���˻�");
    goToXY(29,18);
    printf("14.�˳�");

    goToXY(25,20);
    printf("����������ѡ��|");
    goToXY(45,20);
    printf("|");
    goToXY(43,20);
    int choice;
    scanf("%d",&choice);
    switch_admin(choice,name);


}
void switch_admin(int choice,char *name){
	switch(choice){
        case 1:
            add_comm(name);
            break;
        case 2:
            change_comm(name);
            break;
        case 3:
            break;
        case 4:
            del_comm(name);
            break;
        case 5:
            receive_mes(name);
            break;
        case 6:
            break;
        case 7:
            show_page(PRODUCT,"��Ʒ��Ϣ",name,1);
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            color_change(name);
            break;
        case 12:
            break;
        case 13:
            admin_unsubscribe(name);
            break;
        case 14:
            system("cls");
            start();
            break;
    }
}
void cus_main(char *name){
    drawBorder();
    goToXY(60,3);
    printf("��ӭ����%s!",name);
    goToXY(28,3);
    printf("****�����б�****");
    goToXY(29,5);
    printf("1.ѡ����Ʒ");
    goToXY(29,6);
    printf("2.�ؼ��ֲ�ѯ");
    goToXY(29,7);
    printf("3.�����ѯ����");
    goToXY(29,8);
    printf("4.����������Ϣ");
    goToXY(29,9);
    printf("5.��Ʒ�����¼");
    goToXY(29,10);
    printf("6.���������ѯ");
    goToXY(29,11);
    printf("7.���»�����Ϣ");
    goToXY(29,12);
    printf("8.��ѯ��Ʒ��Ϣ");
    goToXY(29,13);
    printf("9.���Ľ�����ɫ");
    goToXY(29,14);
    printf("10.��Ʒ��Ϣ����");
    goToXY(29,15);
    printf("11.ע���˻�");
    goToXY(29,16);
    printf("12.�˳�");




    goToXY(25,20);
    printf("����������ѡ��|");
    goToXY(45,20);
    printf("|");
    goToXY(43,20);
    int choice;
    scanf("%d",&choice);
    switch_cus(choice,name);
}
void switch_cus(int choice,char *name){
	switch(choice){
        case 1:
            buy_product(name);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            send_mes(name);
            break;
        case 5:
            buy_record(name);
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            color_change(name);
            break;
        case 10:
            break;
        case 11:
            cus_unsubscribe(name);
            break;
        case 12:
        	system("cls");
            start();
            break;
    }
}
void progressBar(char *text){
    /*
    goToXY(26,21);
    printf(text);
    goToXY(19,19);
    for(i = 0;i <= 20;i++){
        goToXY(19+i*2,19);
        printf("��");
        goToXY(69,19);
        printf("%d%%",i*5);
        Sleep(100);
    }
    */
}
void admin_login(){
    int state = 0;//0��ʾע�ᣬ1��ʾ��½
    drawBorder();
    drawTitle();
    goToXY(24,9);
    printf("��ѡ���¼��ע�᣺");
    goToXY(26,12);
    printf("��  ��  ����Աע��");
    goToXY(26,14);
    printf("��      ����Ա��½");
    goToXY(26,16);
    printf("��      �˳�");

    while(TRUE){
        char choice;
        choice = getch();
        if(choice == 72){
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1){
                state = 2;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == 80){

            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");

        }else if(choice == '\r'){
            switch(state){
                case 0:
                    system("cls");
                    drawBorder();
                    admin_register();
                    break;
                case 1:
                    system("cls");
                    drawBorder();
                    admin_login_login();
                    break;
                case 2:
                    system("cls");
                    start();
                    break;
            }
        }
    }
    getchar();
}
void cus_login(){
    int state = 0;//0��ʾע�ᣬ1��ʾ��½
    drawBorder();
    drawTitle();
    goToXY(24,9);
    printf("��ѡ���¼��ע�᣺");
    goToXY(26,12);
    printf("��  ��  �˿�ע��");
    goToXY(26,14);
    printf("��      �˿͵�½");
    goToXY(26,16);
    printf("��      �˳�");


    while(TRUE){
        char choice;
        choice = getch();
        if(choice == 72){
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1){
                state = 2;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == 80){
            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");
        }else if(choice == '\r'){
            switch(state){
                case 0:
                    system("cls");
                    drawBorder();
                    cus_register();
                    break;

                case 1:
                    system("cls");
                    drawBorder();
                    cus_login_login();
                    break;
                case 2:
                    system("cls");
                    start();
                    break;
            }
        }
    }
    getchar();
}
void admin_register(){

    struct user admin = {"","","","","",""};
    char code[10];

    goToXY(28,3);
    printf("****����Աע����Ϣ****");
    goToXY(20,9);
    printf("�ǳƣ�");
    goToXY(20,10);
    printf("�Ա�");
    goToXY(20,11);
    printf("���䣺");
    goToXY(20,12);
    printf("�ֻ��ţ�");
    goToXY(20,13);
    printf("����Աע���룺");
    goToXY(20,15);
    printf("���룺");
    goToXY(20,16);
    printf("�ظ����룺");

    goToXY(27,9);
    scanf("%s",admin.name);
    goToXY(27,10);
    scanf("%s",admin.sex);
    goToXY(27,11);
    scanf("%s",admin.mail);
    goToXY(29,12);
    scanf("%s",admin.phone);
    goToXY(35,13);
    scanf("%s",code);
    goToXY(27,15);
    i=0;
    char pw;
    pw=getch();
    while(pw != 13){
    	if(pw == 8){
			if(i!=0){printf("%c %c",pw,pw);i--;}
        }
        else if(i==20&&pw!=8){}
        else
        {
          	printf("*");
           	admin.pass[i] = pw;
          	i++;
    	}
      	pw = getch(); //���������ַ�ch
    }
    admin.pass[i]='\0';
    goToXY(31,16);
    i=0;
    pw=getch();
    while(pw != 13){
		if ( pw == 8){
			if(i!=0) {printf("%c %c",pw,pw);i--;}
        }
        else if(i==20&&pw!=8) {}
        else{
          	printf("*");
           	admin.pass_double[i] = pw;
         	 i++;
        }
       	pw = getch(); //���������ַ�ch
    }
    admin.pass_double[i]='\0';



    if((!strcmp(code,"cjhz"))&&(!strcmp(admin.pass,admin.pass_double)))
    {

        FILE *file;
        file = fopen(USER_1,"ab+");
        rewind(file);
        struct user User= {"","","","","",""};
        while(!feof(file))
        {
            int result = fread(&User,sizeof(struct user),1,file);
            if(result != 0)
            {
                if(strcmp(User.name,admin.name)==0)  break;
            }
        }
        if(feof(file))
        {
            fwrite(&admin,sizeof(struct user),1,file);
            fclose(file);
            system("cls");
            drawBorder();
            goToXY(30,9);
            printf("�û�����%s",admin.name);
            goToXY(25,11);
            printf("����Ա���ע��ɹ����������������");
            getch();
            system("cls");
            admin_login();
        }
        else
        {
            system("cls");
            drawBorder();
            goToXY(25,11);
            printf("�û����ظ���ע��ʧ�ܣ�");
            getch();
            system("cls");
            admin_login();
        }

    }
    else{
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("�����������벻һ�£�ע��ʧ�ܣ�");
        getch();
        system("cls");
        admin_login();
    }


}
void cus_register(){
    struct user cus = {"","","","","",""};

    goToXY(28,3);
    printf("****�˿��û�ע����Ϣ****");
    goToXY(20,9);
    printf("�ǳƣ�");
    goToXY(20,10);
    printf("�Ա�");
    goToXY(20,11);
    printf("���䣺");
    goToXY(20,12);
    printf("�ֻ��ţ�");
    goToXY(20,15);
    printf("���룺");
    goToXY(20,16);
    printf("�ظ����룺");


    goToXY(27,9);
    scanf("%s",cus.name);
    goToXY(27,10);
    scanf("%s",cus.sex);
    goToXY(27,11);
    scanf("%s",cus.mail);
    goToXY(29,12);
    scanf("%s",cus.phone);
    goToXY(27,15);
    i=0;
    char pw;
	pw=getch();
    while ( pw != 13){
      	if(pw == 8){
			if(i!=0) {printf("%c %c",pw,pw);i--;}
        }else if(i==20&&pw!=8) {}
        else{
    		printf("*");
           	cus.pass[i] = pw;
          	i++;
        }
       	pw = getch(); //���������ַ�ch
    }
    cus.pass[i]='\0';
    goToXY(31,16);
    i=0;
    pw=getch();
    while( pw != 13) //�����ַ�ch��ΪEnter
	{
		if(pw == 8)  //�����ַ�chΪBackSpace
        {if(i!=0) {printf("%c %c",pw,pw);i--;}}
        else if(i==20&&pw!=8) {}
        else{
          	printf("*");
           	cus.pass_double[i] = pw;
          	i++;
        }
       	pw = getch(); //���������ַ�ch
    }
    cus.pass_double[i]='\0';

    if(!strcmp(cus.pass,cus.pass_double))
    {
        FILE *file;
        file = fopen(USER_2,"ab+");
        rewind(file);
        struct user User= {"","","","","",""};
        while(!feof(file))
        {
            int result = fread(&User,sizeof(struct user),1,file);
            if(result != 0)
            {
                if(strcmp(User.name,cus.name)==0)  break;
            }
        }
        if(feof(file))
        {
            fwrite(&cus,sizeof(struct user),1,file);
            fclose(file);
            system("cls");
            drawBorder();
            goToXY(30,9);
            printf("�û�����%s",cus.name);
            goToXY(25,11);
            printf("�˿����ע��ɹ����������������");
            getch();
            system("cls");
            cus_login();
        }
        else
        {
            system("cls");
            drawBorder();
            goToXY(25,11);
            printf("�û����ظ���ע��ʧ�ܣ�");
            getch();
            system("cls");
            cus_login();
        }
    }
    else
    {
        system("cls");

        drawBorder();
        goToXY(25,11);
        printf("�����������벻һ�£�ע��ʧ�ܣ�");
        getch();
        system("cls");
        cus_login();
        start();
    }

}

void admin_login_login(){
    char login_name[20];
    char login_pass[20];

    drawBorder();
    goToXY(30,3);
    printf("****����Ա��½****");
    goToXY(25,8);
    printf("�ǳƣ�");
    goToXY(25,9);
    printf("���룺");

    goToXY(31,8);
    scanf("%s",login_name);
    goToXY(31,9);


    i=0;
    char pw;
    pw=getch();
    while(pw != 13){
        if(pw == 8){if(i!=0) {printf("%c %c",pw,pw);i--;}}
        else if(i==20&&pw!=8) {}
        else{
            printf("*");
            login_pass[i] = pw;
            i++;
        }
        pw = getch();
    }
    login_pass[i]='\0';



    //��֤�˻�
    int correct = 0;//��֤״̬
    struct user vertify = {"","","","","",""};
    FILE *file = fopen("user_1.dat","ab+");
    rewind(file);
    while(!feof(file)){
        int result = fread(&vertify,sizeof(struct user),1,file);
        if(result != 0){
            if((!strcmp(vertify.name,login_name))&&(!strcmp(vertify.pass,login_pass))){
                correct = 1;
                break;
            }
        }
    }
    fclose(file);

    //progressBar("ϵͳ������֤���ĵ�¼��Ϣ�����Ժ�");
    system("cls");
    if(correct == 1){
        system("cls");
        admin_main(login_name);
    }else if(correct == 0){
        system("cls");
        drawBorder();
        goToXY(30,9);
        printf("�û�����%s",login_name);
        goToXY(25,11);
        printf("�û�����������󣬰������������");
        getch();
        system("cls");
        admin_login();
    }

}
void cus_login_login(){
    char login_name[20];
    char login_pass[20];

    drawBorder();
    goToXY(30,3);
    printf("****�˿͵�½****");
    goToXY(25,8);
    printf("�ǳƣ�");
    goToXY(25,9);
    printf("���룺");

    goToXY(31,8);
    scanf("%s",login_name);
    goToXY(31,9);


    i=0;
    char pw;
    pw=getch();
    while(pw != 13){
        if(pw == 8){if(i!=0) {printf("%c %c",pw,pw);i--;}}
        else if(i==20&&pw!=8) {}
        else{
            printf("*");
            login_pass[i] = pw;
            i++;
        }
        pw = getch();
    }
    login_pass[i]='\0';



    //��֤�˻�
    int correct = 0;//��֤״̬
    struct user vertify = {"","","","","",""};
    FILE *file = fopen("user_2.dat","ab+");
    rewind(file);
    while(!feof(file)){
        int result = fread(&vertify,sizeof(struct user),1,file);
        if(result != 0){
            if((!strcmp(vertify.name,login_name))&&(!strcmp(vertify.pass,login_pass))){
                correct = 1;
                break;
            }
        }
    }
    fclose(file);

    progressBar("ϵͳ������֤���ĵ�¼��Ϣ�����Ժ�");
    system("cls");
    if(correct == 1){
        system("cls");
        cus_main(login_name);
    }else if(correct == 0){
        system("cls");
        drawBorder();
        goToXY(30,9);
        printf("�û�����%s",login_name);
        goToXY(25,11);
        printf("�û�����������󣬰������������");
        getch();
        system("cls");
        cus_login();
    }
}
void hideCursor(){
    CONSOLE_CURSOR_INFO cursor_info;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&cursor_info);
}
void del_comm(char *name){
    system("cls");
    drawBorder();
    goToXY(28,3);
    printf("****ɾ����Ʒ��Ϣ****");
    goToXY(24,10);
    printf("������Ҫɾ������Ʒ���:");
    scanf("%d",&del_num);
    FILE *file = fopen(PRODUCT,"ab+");
    FILE *file_copy = fopen("copy.dat","ab+");
    struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&comm,sizeof(struct commodity),1,file);
        if(result != 0){
            if(comm.num != del_num){
                fwrite(&comm,sizeof(struct commodity),1,file_copy);
            }
        }
    }
    fclose(file);
    fclose(file_copy);
    remove(PRODUCT);
    rename("copy.dat",PRODUCT);
    progressBar("����ɾ����Ʒ�����Ժ�");
    system("cls");
    drawBorder();
    goToXY(30,9);
    printf("��Ʒ��ţ�%d",del_num);
    goToXY(25,11);
    printf("��Ʒɾ���ɹ����������������");
    getch();
    system("cls");
    admin_main(name);
}
void color_change(char *name){
    int state = 0;
    system("cls");
    drawBorder();
    goToXY(28,3);
    printf("****���Ľ�����ɫ****");
    goToXY(26,8);
    printf("��  ��  �׵׺���(��ϵͳĬ������)");
    goToXY(26,10);
    printf("��      �������");
    goToXY(26,12);
    printf("��      �ڵ׺���");
    goToXY(26,14);
    printf("��      �̵�����");
    goToXY(26,16);
    printf("��      �Ƶ�����");
    goToXY(26,18);
    printf("��      �̵װ���");
    goToXY(26,20);
    printf("��      �˳���������ɫ����");
    while(TRUE){
        char choice;
        choice = getch();
        if(choice == 72){
            goToXY(30,8+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1){
                state = 6;
            }
            goToXY(30,8+state*2);
            printf("��");
        }
        else if(choice == 80){
            goToXY(30,8+state*2);
            printf("\b  ");
            state += 1;
            if(state == 7){
                state = 0;
            }
            goToXY(30,8+state*2);
            printf("��");
        }else if(choice == '\r'){
            switch(state){
                case 0:
                    system("color F0");
                    break;
                case 1:
                    system("color 40");
                    break;
                case 2:
                    system("color 04");
                    break;
                case 3:
                    system("color 21");
                    break;
                case 4:
                    system("color 65");
                    break;
                case 5:
                    system("color 3f");
                    break;
                case 6:
                    system("cls");
                    admin_main(name);
                    break;
            }
        }
    }
    getchar();
}
void send_mes(char *name){
    struct message mes = {"","","",""};
    system("cls");
    drawBorder();
    goToXY(23,3);
    printf("****������Ϣҳ��,�ڴ�������������****");
    goToXY(15,8);
    printf("�����뷴����Ϣ��");
    goToXY(10,10);
    printf("������������ϵ��ʽ���Ա���������ȡ����ϵ��");
    goToXY(31,8);
    scanf("%s",mes.content);
    goToXY(52,10);
    scanf("%s",mes.contract);
    strcpy(mes.name,name);

    char date[10];
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    sprintf(date,"%d-%d-%d",p->tm_year + 1900,p->tm_mon + 1,p->tm_mday);
    strcpy(mes.date,date);

    FILE *file = fopen(MES,"ab+");
    fwrite(&mes,sizeof(struct message),1,file);
    fclose(file);
    goToXY(22,18);
    printf("�Ѿ��յ��������ţ������ڴ����õ����ǣ�");
    goToXY(29,19);
    printf("����������������棡");
    getch();
    system("cls");
    cus_main(name);
}
void receive_mes(char *name){

    system("cls");
    drawBorder();
    //goToXY(23,3);
    //printf("****��������%d���û���������Ϣ��****",count_mes());
    show_page(MES,"�û�����",name,1);

}
int count_mes(){
    int count = 0;
    FILE *file = fopen(MES,"ab+");
    struct message mes = {"","","",""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&mes,sizeof(struct message),1,file);
        if(result != 0){
            count ++;
        }
    }
    fclose(file);
    return count;
}
void show_page(char *file_name,char *str,char *name,int ver){


    int page_num = 0;//��¼��ǰ�ķ�ҳ��
    system("cls");
    drawBorder();
    goToXY(25,2);
    printf("****�����ǲ�ѯ����%s****",str);
    drawInBorder();
    FILE *file = fopen(file_name,"ab+");

    if(!strcmp(file_name,PRODUCT)){
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                }
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(15,4+3*i);
                    printf("%s",comm.name);
                    goToXY(25,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(33,4+3*i);
                    printf("%s",comm.sort);
                    goToXY(42,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(50,4+3*i);
                    printf("%d",comm.sold);
                    goToXY(56,4+3*i);
                    printf("%d",comm.count);
                    goToXY(63,4+3*i);
                    printf("%.1lf",comm.in_price);
                    goToXY(68,4+3*i);
                    printf("%.1lf",comm.out_price);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,MES)){
        struct message mes = {"","","",""};
            for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("�����û��ǳ�\t��������\t\t��ϵ��ʽ\t��������");
                }
                int result = fread(&mes,sizeof(struct message),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",mes.name);
                    goToXY(25,4+3*i);
                    printf("%s",mes.content);
                    goToXY(49,4+3*i);
                    printf("%s",mes.contract);
                    goToXY(65,4+3*i);
                    printf("%s",mes.date);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,"tmp.dat")){
        struct record rec = {"","",0,""};
        for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("�����û��ǳ�\t��Ʒ����\t\t��Ʒ����\t��������");
                }
                int result = fread(&rec,sizeof(struct record),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",rec.name);
                    goToXY(25,4+3*i);
                    printf("%s",rec.product);
                    goToXY(49,4+3*i);
                    printf("%d",rec.quantity);
                    goToXY(65,4+3*i);
                    printf("%s",rec.date);
                }else{
                    break;
                }
            }
    }

    fclose(file);
    char choice = getch();
    switch(choice){
        case 110://N��
            page_num++;
            page_down(file_name,str,page_num,name,ver);
            break;
        case 112://P��
            page_num--;
            if(page_num < 0){
                page_num = 0;
            }
            page_up(file_name,str,page_num,name,ver);
            break;
        case 27:
            system("cls");
            switch(ver){
                case 1:
                    admin_main(name);
                    break;
                case 2:
                    cus_main(name);
            }
            break;
    }
}
void page_up(char *file_name,char *str,int num,char *name,int ver){
    int nums = 0;//����
    system("cls");
    drawBorder();
    goToXY(25,2);
    printf("****�����ǲ�ѯ����%s****",str);
    drawInBorder();
    FILE *file = fopen(file_name,"ab+");


    if(!strcmp(file_name,PRODUCT)){
        fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                }
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(15,4+3*i);
                    printf("%s",comm.name);
                    goToXY(25,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(33,4+3*i);
                    printf("%s",comm.sort);
                    goToXY(42,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(50,4+3*i);
                    printf("%d",comm.sold);
                    goToXY(56,4+3*i);
                    printf("%d",comm.count);
                    goToXY(63,4+3*i);
                    printf("%.1lf",comm.in_price);
                    goToXY(68,4+3*i);
                    printf("%.1lf",comm.out_price);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,MES)){
        fseek(file,sizeof(struct message)*5*num,SEEK_SET);
        struct message mes = {"","","",""};
            for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("�����û��ǳ�\t��������\t\t��ϵ��ʽ\t��������");
                }
                int result = fread(&mes,sizeof(struct message),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",mes.name);
                    goToXY(25,4+3*i);
                    printf("%s",mes.content);
                    goToXY(49,4+3*i);
                    printf("%s",mes.contract);
                    goToXY(65,4+3*i);
                    printf("%s",mes.date);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,"tmp.dat")){
        fseek(file,sizeof(struct record)*5*num,SEEK_SET);
        struct record rec = {"","",0,""};
        for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("�����û��ǳ�\t��Ʒ����\t\t��Ʒ����\t��������");
                }
                int result = fread(&rec,sizeof(struct record),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",rec.name);
                    goToXY(25,4+3*i);
                    printf("%s",rec.product);
                    goToXY(49,4+3*i);
                    printf("%d",rec.quantity);
                    goToXY(65,4+3*i);
                    printf("%s",rec.date);
                }else{
                    break;
                }
            }
    }


    fclose(file);
    char choice = getch();
    switch(choice){
        case 110://N��
            num++;
            page_down(file_name,str,num,name,ver);
            break;
        case 112://P��
            num--;
            if(num < 0){
                num = 0;
            }
            page_up(file_name,str,num,name,ver);
            break;
        case 27:
            system("cls");
            switch(ver){
                case 1:
                    admin_main(name);
                    break;
                case 2:
                    cus_main(name);
            }
            break;
    }
}
void page_down(char *file_name,char *str,int num,char *name,int ver){
    int nums = 0;//����
    system("cls");
    drawBorder();
    goToXY(25,2);
    printf("****�����ǲ�ѯ����%s****",str);
    drawInBorder();
    FILE *file = fopen(file_name,"ab+");


    if(!strcmp(file_name,PRODUCT)){
        fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                }
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(15,4+3*i);
                    printf("%s",comm.name);
                    goToXY(25,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(33,4+3*i);
                    printf("%s",comm.sort);
                    goToXY(42,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(50,4+3*i);
                    printf("%d",comm.sold);
                    goToXY(56,4+3*i);
                    printf("%d",comm.count);
                    goToXY(63,4+3*i);
                    printf("%.1lf",comm.in_price);
                    goToXY(68,4+3*i);
                    printf("%.1lf",comm.out_price);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,MES)){
        fseek(file,sizeof(struct message)*5*num,SEEK_SET);
        struct message mes = {"","","",""};
            for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("�����û��ǳ�\t��������\t\t��ϵ��ʽ\t��������");
                }
                int result = fread(&mes,sizeof(struct message),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",mes.name);
                    goToXY(25,4+3*i);
                    printf("%s",mes.content);
                    goToXY(49,4+3*i);
                    printf("%s",mes.contract);
                    goToXY(65,4+3*i);
                    printf("%s",mes.date);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,"tmp.dat")){
        fseek(file,sizeof(struct record)*5*num,SEEK_SET);
        struct record rec = {"","",0,""};
        for(i = 0;i < 6;i ++){
                if(i == 1){
                    goToXY(6,4);
                    printf("�����û��ǳ�\t��Ʒ����\t\t��Ʒ����\t��������");
                }
                int result = fread(&rec,sizeof(struct record),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",rec.name);
                    goToXY(25,4+3*i);
                    printf("%s",rec.product);
                    goToXY(49,4+3*i);
                    printf("%d",rec.quantity);
                    goToXY(65,4+3*i);
                    printf("%s",rec.date);
                }else{
                    break;
                }
            }
    }
    fclose(file);
    char choice = getch();
    switch(choice){
        case 110://N��
            num++;
            page_down(file_name,str,num,name,ver);
            break;
        case 112://P��
            num--;
            if(num < 0){
                num = 0;
            }
            page_up(file_name,str,num,name,ver);
            break;
        case 27:
            system("cls");
            switch(ver){
                case 1:
                    admin_main(name);
                    break;
                case 2:
                    cus_main(name);
            }
            break;
    }
}
void drawInBorder(){
    goToXY(5,2);
    for(i = 0;i < 40;i++){
        if(i == 20){
            goToXY(54,2);
        }
        printf("*");
    }
    for(i = 1;i < 7;i++){
        goToXY(5,2+3*i);
        for(j = 0;j < 70;j++){
            printf("-");
        }
    }

}
void add_comm(char *name)
{
    system("cls");
    drawBorder();

    struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};

    goToXY(28,3);
    printf("****��������Ʒ��Ϣ****");
    goToXY(20,9);
    printf("��Ʒ��ţ�");
    goToXY(20,10);
    printf("��Ʒ���ƣ�");
    goToXY(20,11);
    printf("���ۣ�");
    goToXY(20,12);
    printf("�ۼۣ�");
    goToXY(20,13);
    printf("��Ʒ������");
    goToXY(20,14);
    printf("�������");
    goToXY(20,15);
    printf("���");
    goToXY(20,16);
    printf("��������");
    goToXY(20,17);
    printf("�����̣�");


    goToXY(31,9);
    scanf("%d",&comm.num);
    goToXY(31,10);
    scanf("%s",comm.name);
    goToXY(27,11);
    scanf("%lf",&comm.in_price);
    goToXY(27,12);
    scanf("%lf",&comm.out_price);
    goToXY(31,13);
    scanf("%s",comm.desc);
    goToXY(29,14);
    scanf("%lf",&comm.count);
    goToXY(27,15);
    scanf("%s",comm.sort);
    goToXY(29,16);
    scanf("%d",&comm.sold);
    goToXY(29,17);
    scanf("%s",comm.provider);

    FILE *file;
    file = fopen(PRODUCT,"ab+");
    fwrite(&comm,sizeof(struct commodity),1,file);
    fclose(file);
    int choice;
    while(TRUE){
        system("cls");
        drawBorder();
        goToXY(20,9);
        printf("�Ƿ���������Ʒ��������Yes/No:");
        char y_n[4];
        gets(y_n);
        if(!strcmp(y_n,"Yes")){
            choice = 1;
            break;
        }else if(!strcmp(y_n,"No")){
            choice = 0;
            break;
        }else
            printf("�������");
    }
    switch(choice)
    {
        case 1:
            add_comm(name);
            break;
        case 0:
            system("cls");
            admin_main(name);
    }
}
void change_comm(char *name)
{
    int change_num;
    system("cls");
    drawBorder();
    goToXY(28,3);
    printf("****�޸���Ʒ��Ϣ****");
    goToXY(24,10);
    printf("������Ҫ�޸ĵ���Ʒ���:");
    scanf("%d",&change_num);
    FILE *file = fopen(PRODUCT,"ab+");
    FILE *file_copy = fopen("copy.dat","ab+");
    struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&comm,sizeof(struct commodity),1,file);
        if(result != 0){
            if(comm.num != change_num){
                fwrite(&comm,sizeof(struct commodity),1,file_copy);
            }
            if(comm.num == change_num){
                system("cls");
                int state = 0;
                drawBorder();
                goToXY(24,3);
                printf("��ѡ����Ҫ�޸ĵ���Ϣ��");
                goToXY(26,6);
                printf("��  ��  ����");
                goToXY(26,8);
                printf("��      �ۼ�");
                goToXY(26,10);
                printf("��      ��Ʒ����");
                goToXY(26,12);
                printf("��      ���");
                goToXY(26,14);
                printf("��      ���");
                goToXY(26,16);
                printf("��      ������");
                goToXY(26,18);
                printf("��      ������");
                while(TRUE){
                    char choice;
                    choice = getch();
                    if(choice == 72){
                            goToXY(30,6+state*2);
                            printf("\b  ");
                            state -= 1;
                            if(state == -1){
                                    state = 6;
                            }
                            goToXY(30,6+state*2);
                            printf("��");
                    }
                    else if(choice == 80){
                            goToXY(30,6+state*2);
                            printf("\b  ");
                            state += 1;
                            if(state == 7){
                                    state = 0;
                            }
                            goToXY(30,6+state*2);
                            printf("��");
                    }else if(choice == '\r'){
                        system("cls");
                        drawBorder();
                        goToXY(24,10);
                        printf("��������Ҫ�޸ĵ���Ϣ��");
                        switch(state){
                            case 0:
                                scanf("%lf",&comm.in_price);
                                break;
                            case 1:
                                scanf("%lf",&comm.out_price);
                                break;
                            case 2:
                                scanf("%s",comm.desc);
                                break;
                            case 3:
                                scanf("%d",&comm.count);
                                break;
                            case 4:
                                scanf("%s",comm.sort);
                                break;
                            case 5:
                                scanf("%d",&comm.sold);
                                break;
                            case 6:
                                scanf("%s",comm.provider);
                                break;
                            }
                            fwrite(&comm,sizeof(struct commodity),1,file_copy);
                            break;
                        }
                    }
                }
            }
        }
     fclose(file);
     fclose(file_copy);
     remove(PRODUCT);
     rename("copy.dat",PRODUCT);
     progressBar("���ڸ�����Ʒ��Ϣ�����Ժ�");
     system("cls");
     drawBorder();
     goToXY(30,9);
     printf("��Ʒ��ţ�%d",change_num);
     goToXY(25,11);
     printf("��Ʒ�޸ĳɹ����������������");
     getch();
     system("cls");

     int choice;
     while(TRUE){
         system("cls");
         drawBorder();
         goToXY(20,9);
         printf("�Ƿ�����޸���Ʒ��Ϣ��������Yes/No:");
         char y_n[4];
         gets(y_n);
         if(!strcmp(y_n,"Yes")){
                choice = 1;
                break;
         }
         else if(!strcmp(y_n,"No")){
                choice = 0;
                break;
         }
         else
            printf("�������");
         }
         switch(choice)
         {
            case 1:
                change_comm(name);
                break;

            case 0:
                system("cls");
                admin_main(name);
         }
}
void buy_record(char *name){
    system("cls");
    drawBorder();
    remove("tmp.dat");
    FILE *file = fopen(BUY_RECORD,"ab+");
    FILE *file_tmp = fopen("tmp.dat","ab+");

    struct record rec = {"","",0,""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&rec,sizeof(struct record),1,file);
        if(result != 0){
            if(!strcmp(name,rec.name)){
                fwrite(&rec,sizeof(struct record),1,file_tmp);
            }
        }
    }

    fclose(file);
    fclose(file_tmp);

    show_page("tmp.dat","�����¼",name,2);
}
void buy_product(char *name){
    int state = 0;//��ʾ��ѯ��Ʒʱ��״̬
    int buy_code;
    int buy_count;
    system("cls");
    drawBorder();
    goToXY(23,3);
    printf("****��Ʒѡ��ҳ��,�ڴ������Ĺ��٣�****");
    goToXY(20,6);
    printf("��������Ҫ��������Ʒ��ţ�");
    scanf("%d",&buy_code);
    progressBar("���ڼ������ݿ⣬���Ժ�");

    FILE *file = fopen(PRODUCT,"ab+");
    struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&comm,sizeof(struct commodity),1,file);
        if((result == 1)&&(buy_code == comm.num)){
            state = 1;
            break;
        }
    }
    fclose(file);
    if(state == 1){
        goToXY(25,8);
        printf("��Ʒ��ţ�%d",comm.num);
        goToXY(25,9);
        printf("��Ʒ���ƣ�%s",comm.name);
        goToXY(25,10);
        printf("��Ʒ������%s",comm.desc);
        goToXY(25,11);
        printf("��Ʒ���%s",comm.sort);
        goToXY(25,12);
        printf("��Ʒ�����̣�%s",comm.provider);
        goToXY(25,13);
        printf("��Ʒ�ۼۣ�%.1lf",comm.out_price);
        goToXY(18,16);
        printf("��������Ҫ�������Ʒ������");
        scanf("%d",&buy_count);
        progressBar("ϵͳ���ڽ��㣬���Ժ�");

        FILE *file = fopen(BUY_RECORD,"ab+");
        struct record rec = {"","",0,""};
        strcpy(rec.name,name);
        strcpy(rec.product,comm.name);
        rec.quantity = buy_count;
        char date[10];
        time_t timep;
        struct tm *p;
        time (&timep);
        p=gmtime(&timep);
        sprintf(date,"%d-%d-%d",p->tm_year + 1900,p->tm_mon + 1,p->tm_mday);
        strcpy(rec.date,date);
        fwrite(&rec,sizeof(struct record),1,file);
        fclose(file);
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("ѡ����Ʒ�Ѿ�����ɹ����������������");
        getch();
        system("cls");
        cus_main(name);
    }else if(state == 0){
        goToXY(18,8);
        printf("��ʱδ����������Ҫ���ҵ���Ʒ�����ڴ������ϼܣ�");
        goToXY(28,14);
        printf("�������������");
        getch();
        system("cls");
        cus_main(name);
    }
}
void sort_search(char *name){
    system("cls");
    drawBorder();
    char input[20];
    goToXY(23,3);
    printf("****�����ѯҳ��,���Ի����Ĳ�ѯ��****");


}
void admin_unsubscribe(char *name)
{
    int state=0;
    system("cls");
    drawBorder();
    goToXY(28,3);
    printf("��ȷ��Ҫע�����˺ţ�");
    goToXY(26,12);
    printf("��  ��  ȷ��");
    goToXY(26,14);
    printf("��      ȡ��");
    while(TRUE)
    {
        char choice;
        choice = getch();
        if(choice == 72)
        {
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1)
            {
                state = 1;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == 80)
        {
            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 2)
            {
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == '\r')
        {
            switch(state)
            {
            case 0:
               {
                FILE *file = fopen("user_1.dat","ab+");
                FILE *file_copy = fopen("copy.dat","ab+");
                struct user User= {"","","","","",""};
                rewind(file);
                while(!feof(file))
                {
                    int result = fread(&User,sizeof(struct user),1,file);
                    if(result != 0)
                    {
                        if(strcmp(User.name,name)!=0)
                        {
                            fwrite(&User,sizeof(struct user),1,file_copy);
                        }
                    }
                }
                fclose(file);
                fclose(file_copy);
                remove("user_1.dat");
                rename("copy.dat","user_1.dat");
                system("cls");
                drawBorder();
                goToXY(28,9);
                printf("�˻�ע���ɹ�����������˳���");
                getch();
                system("cls");
                start();
                break;}
            case 1:
                system("cls");
                admin_main(name);
            }
        }
    }
}
void cus_unsubscribe(char *name)
{
    int state=0;
    system("cls");
    drawBorder();
    goToXY(28,3);
    printf("��ȷ��Ҫע�����˺ţ�");
    goToXY(26,12);
    printf("��  ��  ȷ��");
    goToXY(26,14);
    printf("��      ȡ��");
    while(TRUE)
    {
        char choice;
        choice = getch();
        if(choice == 72)
        {
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1)
            {
                state = 1;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == 80)
        {
            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 2)
            {
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == '\r')
        {
            switch(state)
            {
            case 0:
               {
                FILE *file = fopen("user_2.dat","ab+");
                FILE *file_copy = fopen("copy.dat","ab+");
                struct user User= {"","","","","",""};
                rewind(file);
                while(!feof(file))
                {
                    int result = fread(&User,sizeof(struct user),1,file);
                    if(result != 0)
                    {
                        if(strcmp(User.name,name)!=0)
                        {
                            fwrite(&User,sizeof(struct user),1,file_copy);
                        }
                    }
                }
                fclose(file);
                fclose(file_copy);
                remove("user_2.dat");
                rename("copy.dat","user_2.dat");
                system("cls");
                drawBorder();
                goToXY(28,9);
                printf("�˻�ע���ɹ�����������˳���");
                getch();
                system("cls");
                start();
                break;}
            case 1:
                system("cls");
                cus_main(name);
            }
        }

    }
}
