//����ͷ�ļ�
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <dos.h>

//�궨��
#define HEIGHT 23
#define WIDTH 80
#define LEN sizeof(struct commodity)
#define FORMAT "%-15d%-15s%-15.1lf%-15.1lf%-15.1lf"
#define DATA comm[i].num,comm[i].name,comm[i].price,comm[i].count,comm[i].total
#define USER_1 "user_1.dat"
#define USER_2 "user_2.dat"
#define PRODUCT "product.dat"


struct commidity{
    int num;
    char name[15];
    double price;
    double count;
    double total;
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
struct commidity comm[50];



void start();
void goToXY();
void drawBorder();
void drawTitle();
void admin_main(char *name);
void cus_main(char *name);
void progressBar();//������
void admin_login();
void cus_login();
void admin_register();
void cus_register();
void admin_login_login();
void cus_login_login();


int i,j,k;//����ѭ������


int main()
{
    start();
    return 0;
}
void start(){
    int state = 0;//�����û������ѡ����Ϣ��0Ϊ����Ա��1Ϊ�˿�
    system("color f1");
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
        if(choice == '8'){
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1){
                state = 2;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == '2'){
            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");
        }else if(choice == '5'){
            switch(state){
                case 0:
                    progressBar();
                    Sleep(100);
                    system("cls");
                    admin_login();
                    break;

                case 1:
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
    printf("4.�û�������Ϣ");
    goToXY(29,9);
    printf("5.�����Ϣ��ѯ");
    goToXY(29,10);
    printf("6.������Ϣ��ѯ");
    goToXY(29,11);
    printf("7.��ҳ��ʾ��Ʒ��Ϣ");
    goToXY(29,12);
    printf("8.���»�����Ϣ");
    goToXY(29,13);
    printf("9.��ѯ��Ʒ��Ϣ");
    goToXY(29,14);
    printf("10.���Ľ�����ɫ");
    goToXY(29,15);
    printf("11.��Ʒ��Ϣ����");
    goToXY(29,16);
    printf("12.ע���˻�");
    goToXY(29,17);
    printf("13.�˳�");




    goToXY(25,20);
    printf("����������ѡ��|");
    goToXY(45,20);
    printf("|");
    goToXY(43,20);
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            break;
        case 13:
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
    switch(choice){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        case 11:
            break;
        case 12:
            system("cls");
            start();
            break;
    }
}
void progressBar(){
    goToXY(26,21);
    printf("ϵͳ���ڼ��أ����Ժ�");
    goToXY(19,19);
    for(i = 0;i <= 20;i++){
        goToXY(19+i*2,19);
        printf("��");
        goToXY(69,19);
        printf("%d%%",i*5);
        Sleep(100);
    }
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
        if(choice == '8'){
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1){
                state = 2;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == '2'){

            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");

        }else if(choice == '5'){
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
        if(choice == '8'){
            goToXY(30,12+state*2);
            printf("\b  ");
            state -= 1;
            if(state == -1){
                state = 2;
            }
            goToXY(30,12+state*2);
            printf("��");
        }
        else if(choice == '2'){
            goToXY(30,12+state*2);
            printf("\b  ");
            state += 1;
            if(state == 3){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");
        }else if(choice == '5'){
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
    gets(admin.name);
    goToXY(27,10);
    gets(admin.sex);
    goToXY(27,11);
    gets(admin.mail);
    goToXY(29,12);
    gets(admin.phone);
    goToXY(35,13);
    gets(code);
    goToXY(27,15);
    gets(admin.pass);
    goToXY(31,16);
    gets(admin.pass_double);



    if((!strcmp(code,"cjhz"))&&(!strcmp(admin.pass,admin.pass_double))){

        FILE *file;
        file = fopen(USER_1,"ab+");
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

    }else{
        system("cls");
        start();
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
    gets(cus.name);
    goToXY(27,10);
    gets(cus.sex);
    goToXY(27,11);
    gets(cus.mail);
    goToXY(29,12);
    gets(cus.phone);
    goToXY(27,15);
    gets(cus.pass);
    goToXY(31,16);
    gets(cus.pass_double);

     if(!strcmp(cus.pass,cus.pass_double)){

        FILE *file;
        file = fopen(USER_2,"ab+");
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
    gets(login_name);
    goToXY(31,9);
    gets(login_pass);

    goToXY(23,19);
    printf("ϵͳ������֤���ĵ�½��Ϣ�����Ժ�");

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

    goToXY(19,17);
    for(i = 0;i <= 20;i++){
        goToXY(19+i*2,17);
        printf("��");
        goToXY(69,17);
        printf("%d%%",i*5);
        Sleep(100);
    }
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
    gets(login_name);
    goToXY(31,9);
    gets(login_pass);

    goToXY(23,19);
    printf("ϵͳ������֤���ĵ�½��Ϣ�����Ժ�");

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

    goToXY(19,17);
    for(i = 0;i <= 20;i++){
        goToXY(19+i*2,17);
        printf("��");
        goToXY(69,17);
        printf("%d%%",i*5);
        Sleep(100);
    }
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
        admin_login();
    }
}
