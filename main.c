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
#define USER_1 "user_1.dat"
#define USER_2 "user_2.dat"
#define PRODUCT "product.dat"
#define MES "mes.dat"
#define BUY_RECORD "buy_record.dat"
#define VAULT "vault.dat"
#define DAY_SOLD "day_sold.dat"


struct message{
    char name[30];
    char content[100];
    char contract[20];
    char date[30];
};//�����û��ķ�����Ϣ
//��¼�û�������Ϣ
struct record{
    char name[20];
    char product[30];
    int quantity;
    char date[15];
};//�����û��Ĺ����¼
//��¼�û������¼
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
    int cart_count;//�˿ͷ��ڹ��ﳵ���������
};
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
struct day_sold{
    char date[15];
    int count;
};


void start();
void goToXY(int x,int y);
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
int count();//�����û�������Ϣ������
void show_page(char *file_name,char *str,char *name,int ver);
void page_up(char *file_name,char *str,int num,char *name,int ver);
void page_down(char *file_name,char *str,int num,char *name,int ver);
void drawInBorder();//������ҳ��ѯ���ڲ����߿�
void change_comm(char *name);
void add_comm(char *name);
void buy_record(char *name);
void buy_product(char *name);
void sort_search(char *name,int ver);
void admin_unsubscribe(char *name);
void cus_unsubscribe(char *name);
void out_file(char *name,int ver);
void info_change(char *name,int ver);
void search_comm(char *name,int ver);
void sales_ranking_query(char *name,int ver);
void buttom_title1(int num,int max_num,int ver);
void buttom_title2(int num,int max_num);
void del_pro(int del_num);
double vault(double out_price,int number);
void alert(char *name);
void sold_chart(char *name);
int count_days(char *min_date,char *max_date);
void show_chart(char *name,int days);
void chart_up(int num,char *name,int days);
void chart_down(int num,char *name,int days);
int count_sold(char * name);
void updown_bottom();
void file_oi(char *name);
void in_file(char *name);
int ver_comm(struct commodity comm);
void move_to_shopping_cart(char *name);
void empty_cart(char *name);
void del_cart(char *name);



int i,j,k;//����ѭ������


int main(){
    system("mode con cols=80 lines=24");
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
    updown_bottom();
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
                    system("cls");
                    drawBorder();
                    goToXY(28,11);
                    printf("��л����ʹ�ã��ټ���");
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
    goToXY(23,22);
    printf("���е�Ӫҵ��Ϊ��%.1lfԪ",vault(0,0));
    goToXY(28,3);
    printf("****�����б�****");
    goToXY(29,5);
    printf("1.�����Ʒ��Ϣ");
    goToXY(29,6);
    printf("2.�޸���Ʒ��Ϣ");
    goToXY(29,7);
    printf("3.�����ѯ��Ʒ");
    goToXY(29,8);
    printf("4.ɾ����Ʒ��Ϣ");
    goToXY(29,9);
    printf("5.�û�������Ϣ");
    goToXY(29,10);
    printf("6.�ؼ��ֲ�ѯ");
    goToXY(29,11);
    printf("7.���������ѯ");
    goToXY(29,12);
    printf("8.��ҳ��ʾ��Ʒ��Ϣ");
    goToXY(29,13);
    printf("9.���»�����Ϣ");
    goToXY(29,14);
    printf("10.�����ձ���");
    goToXY(29,15);
    printf("11.���Ľ�����ɫ");
    goToXY(29,16);
    printf("12.��Ʒ��Ϣ����/����");
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
            sort_search(name,1);
            break;
        case 4:
            del_comm(name);
            break;
        case 5:
            receive_mes(name);
            break;
        case 6:
            search_comm(name,1);
            break;
        case 7:
            sales_ranking_query(name,1);
            break;
        case 8:
            show_page(PRODUCT,"��Ʒ��Ϣ",name,1);
            break;
        case 9:
            info_change(name,1);
            break;
        case 10:
            sold_chart(name);
            break;
        case 11:
            color_change(name);
            break;
        case 12:
            file_oi(name);
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
    printf("3.�����ѯ��Ʒ");
    goToXY(29,8);
    printf("4.����������Ϣ");
    goToXY(29,9);
    printf("5.��Ʒ�����¼");
    goToXY(29,10);
    printf("6.���������ѯ");
    goToXY(29,11);
    printf("7.���»�����Ϣ");
    goToXY(29,12);
    printf("8.��ҳ�鿴��Ʒ��Ϣ");
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
            search_comm(name,2);
            break;
        case 3:
            sort_search(name,2);
            break;
        case 4:
            send_mes(name);
            break;
        case 5:
            buy_record(name);
            break;
        case 6:
            sales_ranking_query(name,2);
            break;
        case 7:
            info_change(name,2);
            break;
        case 8:
            show_page(PRODUCT,"��Ʒ��Ϣ",name,2);
            break;
        case 9:
            color_change(name);
            break;
        case 10:
            out_file(name,2);
            break;
        case 11:
            cus_unsubscribe(name);
            break;
        case 12:
        	system("cls");
            start();
            break;
        default:
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
    updown_bottom();
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
    updown_bottom();
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
      	pw = getch();
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
       	pw = getch();
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
                if(strcmp(User.name,admin.name)==0)
                break;
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
            goToXY(24,11);
            printf("����Ա���ע��ɹ����������������");
            getch();
            system("cls");
            admin_login();
        }
        else
        {
            fclose(file);
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
        goToXY(34,11);
        printf("ע��ʧ�ܣ�");
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
       	pw = getch();
    }
    cus.pass[i]='\0';
    goToXY(31,16);
    i=0;
    pw=getch();
    while( pw != 13)
	{
		if(pw == 8)
        {if(i!=0) {printf("%c %c",pw,pw);i--;}}
        else if(i==20&&pw!=8) {}
        else{
          	printf("*");
           	cus.pass_double[i] = pw;
          	i++;
        }
       	pw = getch();
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
            goToXY(24,11);
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
        alert(login_name);
        admin_main(login_name);
    }else if(correct == 0){
        system("cls");
        drawBorder();
        goToXY(30,9);
        printf("�û�����%s",login_name);
        goToXY(23,11);
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
        goToXY(23,11);
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
    int del_num;
    system("cls");
    drawBorder();
    goToXY(28,3);
    printf("****ɾ����Ʒ��Ϣ****");
    goToXY(24,10);
    printf("������Ҫɾ������Ʒ���:");
    scanf("%d",&del_num);
    del_pro(del_num);
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
void del_pro(int del_num){
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
    printf("��      �ڵ�����");
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
                    system("color 0A");
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
int count(char *file_name,char *name){
    int count = 0;
    FILE *file = fopen(file_name,"ab+");
    if(!strcmp(file_name,PRODUCT) || !strcmp(file_name,"copy1.dat") || !strcmp(file_name,"select.dat") || !strcmp(file_name,"tmp_1.dat")||!strcmp(file_name,name)){
        struct commodity tmp = {0,"",0.0,0.0,"",0.0,"",0,"",0};
        rewind(file);
        while(!feof(file)){
            int result = fread(&tmp,sizeof(struct commodity),1,file);
            if(result != 0){
                count ++;
            }
        }
    }else if(!strcmp(file_name,MES)){
        struct message tmp = {"","","",""};
        rewind(file);
        while(!feof(file)){
            int result = fread(&tmp,sizeof(struct message),1,file);
            if(result != 0){
                count ++;
            }
        }
    }else if(!strcmp(file_name,"tmp.dat")){
        struct record tmp = {"","",0,""};
        rewind(file);
        while(!feof(file)){
            int result = fread(&tmp,sizeof(struct record),1,file);
            if(result != 0){
                count ++;
            }
        }
    }else if(!strcmp(file_name,DAY_SOLD)){
        struct day_sold ds = {"",0};
        rewind(file);
        while(!feof(file)){
            int result = fread(&ds,sizeof(struct day_sold),1,file);
            if(result != 0){
                count ++;
            }
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
    buttom_title1(page_num,count(file_name,name)/5 + 1,ver);
    FILE *file = fopen(file_name,"ab+");
    if(!strcmp(file_name,PRODUCT) || !strcmp(file_name,"copy1.dat") || !strcmp(file_name,"select.dat")||!strcmp(file_name,name)){
        if(ver == 1){
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,"",0};
            goToXY(6,4);
            printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                for(i = 1;i < 6;i ++){
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
        }else if(ver == 2){
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,"",0};
            goToXY(6,4);
            printf("��Ʒ���\t��Ʒ����\t��Ʒ����\t����\t������\t�۸�");
            if(!strcmp(file_name,name)) {printf("  ����"); goToXY(52,22);printf("��S��ɾ��");}
            for(i = 1;i < 6;i ++){
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(16,4+3*i);
                    printf("%s",comm.name);
                    goToXY(32,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(48,4+3*i);
                    printf("%d",comm.sold);
                    goToXY(56,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(64,4+3*i);
                    printf("%.1lf",comm.out_price);
                     if(!strcmp(file_name,name))
                    {
                        goToXY(72,4+3*i);
                        printf("%d",comm.cart_count);
                    }
                }else{
                    break;
                }
            }
        }
    }else if(!strcmp(file_name,MES)){
        struct message mes = {"","","",""};
            goToXY(6,4);
            printf("�����û��ǳ�\t��������\t\t��ϵ��ʽ\t��������");
            for(i = 1;i < 6;i ++){
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
        goToXY(6,4);
        printf("�����û��ǳ�\t��Ʒ����\t\t��Ʒ����\t��������");
        for(i = 1;i < 6;i ++){
                int result = fread(&rec,sizeof(struct record),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",rec.name);
                    goToXY(25,4+3*i);
                    printf("%s",rec.product);
                    goToXY(49,4+3*i);
                    printf("%d",rec.quantity);
                    goToXY(64,4+3*i);
                    printf("%s",rec.date);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,"tmp_1.dat")){
        if(ver == 1){
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                for(i = 1;i < 6;i ++){
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
        }else if(ver == 2){
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ���\t��Ʒ����\t��Ʒ����\t\t������\t��Ʒ�۸�");
            for(i = 1;i < 6;i ++){
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(16,4+3*i);
                    printf("%s",comm.name);
                    goToXY(32,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(56,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(64,4+3*i);
                    printf("%.1lf",comm.out_price);
                }else{
                    break;
                }
            }
        }

    }
    fclose(file);
    int state = 1;
    int choice;
    while(state){
        switch(choice){
            case 110://N��
                state = 0;
                page_num++;
                if(page_num > count(file_name,name)/5){
                    page_num = count(file_name,name)/5;
                }
                page_down(file_name,str,page_num,name,ver);
                break;
            case 112://P��
                state = 0;
                page_num--;
                if(page_num < 0){
                    page_num = 0;
                }
                page_up(file_name,str,page_num,name,ver);
                break;
            case 98:
            if(ver==2&&strcmp(file_name,name)==0) empty_cart(name);
            else if(ver==2&&strcmp(file_name,name)!=0) move_to_shopping_cart(name);
            break;
            case 115:
            if(ver==2&&strcmp(file_name,name)==0) del_cart(name);
            break;
            case 27:
                state = 0;
                system("cls");
                switch(ver){
                    case 1:
                        admin_main(name);
                        break;
                    case 2:
                        cus_main(name);
                        break;
                }
                break;
            default:
                choice = getch();
        }
    }
}
void page_up(char *file_name,char *str,int num,char *name,int ver){
    int nums = 0;//����
    system("cls");
    drawBorder();
    buttom_title1(num,count(file_name,name)/5 + 1,ver);
    goToXY(25,2);
    printf("****�����ǲ�ѯ����%s****",str);
    drawInBorder();
    FILE *file = fopen(file_name,"ab+");

    if(!strcmp(file_name,PRODUCT) || !strcmp(file_name,"copy1.dat") || !strcmp(file_name,"select.dat")||!strcmp(file_name,name)){
        if(ver == 1){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,"",0};
            goToXY(6,4);
            printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                for(i = 1;i < 6;i ++){
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
        }else if(ver == 2){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ���\t��Ʒ����\t��Ʒ����\t����\t������\t��Ʒ�۸�");
             if(!strcmp(file_name,name)) {printf("  ����"); goToXY(52,22);printf("��S��ɾ��");}
            for(i = 1;i < 6;i ++){
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(16,4+3*i);
                    printf("%s",comm.name);
                    goToXY(32,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(48,4+3*i);
                    printf("%d",comm.sold);
                    goToXY(56,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(64,4+3*i);
                    printf("%.1lf",comm.out_price);
                     if(!strcmp(file_name,name))
                    {
                        goToXY(72,4+3*i);
                        printf("%d",comm.cart_count);
                    }
                }else{
                    break;
                }
            }
        }
    }
    else if(!strcmp(file_name,MES)){
        fseek(file,sizeof(struct message)*5*num,SEEK_SET);
        struct message mes = {"","","",""};
        goToXY(6,4);
        printf("�����û��ǳ�\t��������\t\t��ϵ��ʽ\t��������");
            for(i = 1;i < 6;i ++){
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
    }
    else if(!strcmp(file_name,"tmp.dat")){
        fseek(file,sizeof(struct record)*5*num,SEEK_SET);
        struct record rec = {"","",0,""};
        goToXY(6,4);
        printf("�����û��ǳ�\t��Ʒ����\t\t��Ʒ����\t��������");
        for(i = 1;i < 6;i ++){
                int result = fread(&rec,sizeof(struct record),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",rec.name);
                    goToXY(25,4+3*i);
                    printf("%s",rec.product);
                    goToXY(49,4+3*i);
                    printf("%d",rec.quantity);
                    goToXY(64,4+3*i);
                    printf("%s",rec.date);
                }else{
                    break;
                }
        }
    }else if(!strcmp(file_name,"tmp_1.dat")){
        if(ver == 1){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                for(i = 1;i < 6;i ++){
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
        }else if(ver == 2){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ���\t��Ʒ����\t��Ʒ����\t\t������\t��Ʒ�۸�");
            for(i = 1;i < 6;i ++){
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(16,4+3*i);
                    printf("%s",comm.name);
                    goToXY(32,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(56,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(64,4+3*i);
                    printf("%.1lf",comm.out_price);
                }else{
                    break;
                }
            }
        }

    }


    fclose(file);
    int state = 1;
    int choice;
    while(state){
        switch(choice){
            case 110://N��
                state = 0;
                num++;
                if(num > count(file_name,name)/5){
                    num = count(file_name,name)/5;
                }
                page_down(file_name,str,num,name,ver);
                break;
            case 112://P��
                state = 0;
                num--;
                if(num < 0){
                    num = 0;
                }
                page_up(file_name,str,num,name,ver);
                break;
                 case 98:
            if(ver==2&&strcmp(file_name,name)==0) empty_cart(name);
            else if(ver==2&&strcmp(file_name,name)!=0) move_to_shopping_cart(name);
            break;
        case 115:
            if(ver==2&&strcmp(file_name,name)==0) del_cart(name);
            break;
            case 27:
                state = 0;
                system("cls");
                switch(ver){
                    case 1:
                        admin_main(name);
                        break;
                    case 2:
                        cus_main(name);
                        break;
                }
                break;
            default:
                choice = getch();
        }
    }
}
void page_down(char *file_name,char *str,int num,char *name,int ver){
    int nums = 0;//����
    system("cls");
    drawBorder();
    buttom_title1(num,count(file_name,name)/5 + 1,ver);
    goToXY(25,2);
    printf("****�����ǲ�ѯ����%s****",str);
    drawInBorder();
    FILE *file = fopen(file_name,"ab+");


    if(!strcmp(file_name,PRODUCT) || !strcmp(file_name,"copy1.dat") || !strcmp(file_name,"select.dat")||!strcmp(file_name,name)){
        if(ver == 1){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,"",0};
            goToXY(6,4);
            printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                for(i = 1;i < 6;i ++){
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
        }else if(ver == 2){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ���\t��Ʒ����\t��Ʒ����\t����\t������\t��Ʒ�۸�");
            if(!strcmp(file_name,name)) {printf("  ����"); goToXY(52,22);printf("��S��ɾ��");}
            for(i = 1;i < 6;i ++){
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(16,4+3*i);
                    printf("%s",comm.name);
                    goToXY(32,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(48,4+3*i);
                    printf("%d",comm.sold);
                    goToXY(56,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(64,4+3*i);
                    printf("%.1lf",comm.out_price);
                     if(!strcmp(file_name,name))
                    {
                        goToXY(72,4+3*i);
                        printf("%d",comm.cart_count);
                    }
                }else{
                    break;
                }
            }
        }
    }else if(!strcmp(file_name,MES)){
        fseek(file,sizeof(struct message)*5*num,SEEK_SET);
        struct message mes = {"","","",""};
        goToXY(6,4);
        printf("�����û��ǳ�\t��������\t\t��ϵ��ʽ\t��������");
            for(i = 1;i < 6;i ++){
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
        goToXY(6,4);
        printf("�����û��ǳ�\t��Ʒ����\t\t��Ʒ����\t��������");
        for(i = 1;i < 6;i ++){
                int result = fread(&rec,sizeof(struct record),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%s",rec.name);
                    goToXY(25,4+3*i);
                    printf("%s",rec.product);
                    goToXY(49,4+3*i);
                    printf("%d",rec.quantity);
                    goToXY(64,4+3*i);
                    printf("%s",rec.date);
                }else{
                    break;
                }
            }
    }else if(!strcmp(file_name,"tmp_1.dat")){
        if(ver == 1){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ��� ��Ʒ���� ��Ʒ���� ��Ʒ��� ������ ������ ����� ���� �ۼ�");
                for(i = 1;i < 6;i ++){
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
        }else if(ver == 2){
            fseek(file,sizeof(struct commodity)*5*num,SEEK_SET);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
            goToXY(6,4);
            printf("��Ʒ���\t��Ʒ����\t��Ʒ����\t\t������\t��Ʒ�۸�");
            for(i = 1;i < 6;i ++){
                int result = fread(&comm,sizeof(struct commodity),1,file);
                if(result == 1){
                    goToXY(6,4+3*i);
                    printf("%d",comm.num);
                    goToXY(16,4+3*i);
                    printf("%s",comm.name);
                    goToXY(32,4+3*i);
                    printf("%s",comm.desc);
                    goToXY(56,4+3*i);
                    printf("%s",comm.provider);
                    goToXY(64,4+3*i);
                    printf("%.1lf",comm.out_price);
                }else{
                    break;
                }
            }
        }

    }
    fclose(file);
    int state = 1;
    int choice;
    while(state){
        switch(choice){
            case 110://N��
                state = 0;
                num++;
                if(num > count(file_name,name)/5){
                    num = count(file_name,name)/5;
                }
                page_down(file_name,str,num,name,ver);
                break;
            case 112://P��
                state = 0;
                num--;
                if(num < 0){
                    num = 0;
                }
                page_up(file_name,str,num,name,ver);
                break;
                case 98:
            if(ver==2&&strcmp(file_name,name)==0) empty_cart(name);
            else if(ver==2&&strcmp(file_name,name)!=0) move_to_shopping_cart(name);
            break;
        case 115:
            if(ver==2&&strcmp(file_name,name)==0) del_cart(name);
            break;
            case 27:
                state = 0;
                system("cls");
                switch(ver){
                    case 1:
                        admin_main(name);
                        break;
                    case 2:
                        cus_main(name);
                        break;
                }
                break;
            default:
                choice = getch();
        }
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
void add_comm(char *name){
    system("cls");
    drawBorder();
    struct commodity comm = {0,"",0.0,0.0,"",0,"",0,""};
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
    scanf("%d",&comm.count);
    goToXY(27,15);
    scanf("%s",comm.sort);
    goToXY(29,16);
    scanf("%d",&comm.sold);
    goToXY(29,17);
    scanf("%s",comm.provider);

    int state_now = 0;
    FILE *file = fopen(PRODUCT,"ab+");
    struct commodity comm_1 = {0,"",0.0,0.0,"",0.0,"",0,""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&comm_1,sizeof(struct commodity),1,file);
        if(result != 0){
            if(comm.num == comm_1.num){
                  state_now = 1;
            }
        }
    }
    fclose(file);
    if(state_now == 1)
    {
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("��Ʒ����ظ����������������");
        getch();
        add_comm(name);
    }

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
            add_comm(name);
            break;
        case 0:
            system("cls");
            admin_main(name);
    }
}
void change_comm(char *name){
    int change_num;
    int state = 0;//��ʾ�Ƿ��޸ĳɹ�
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
                state = 1;
                system("cls");
                int state = 0;
                drawBorder();
                goToXY(24,3);
                printf("��ѡ����Ҫ�޸ĵ���Ϣ��");
                goToXY(26,6);
                printf("��  ��  ����");
                goToXY(50,6);
                printf("��ǰ��%.1lf",comm.in_price);
                goToXY(26,8);
                printf("��      �ۼ�");
                goToXY(50,8);
                printf("��ǰ��%.1lf",comm.out_price);
                goToXY(26,10);
                printf("��      ��Ʒ����");
                goToXY(50,10);
                printf("��ǰ��%s",comm.desc);
                goToXY(26,12);
                printf("��      ���");
                goToXY(50,12);
                printf("��ǰ��%d",comm.count);
                goToXY(26,14);
                printf("��      ���");
                goToXY(50,14);
                printf("��ǰ��%s",comm.sort);
                goToXY(26,16);
                printf("��      ������");
                goToXY(50,16);
                printf("��ǰ��%d",comm.sold);
                goToXY(26,18);
                printf("��      ������");
                goToXY(50,18);
                printf("��ǰ��%s",comm.provider);
                updown_bottom();
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
                    }else if(choice == 27){
                        fclose(file);
                        fclose(file_copy);
                        system("cls");
                        admin_main(name);

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
     switch(state){
        case 0:
            goToXY(22,11);
            printf("�����������Ʒ��Ų����ڣ��������������");
            break;
        case 1:
            goToXY(25,11);
            printf("��Ʒ�޸ĳɹ����������������");
            break;
    }
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
                break;
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
    int state=0;
    system("cls");
    drawBorder();
    goToXY(28,3);
    printf("��ѡ����ʽ");
    goToXY(26,12);
    printf("��  ��  ��ѯ����");
    goToXY(26,14);
    printf("��      �鿴���ﳵ");
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

                FILE *file = fopen(PRODUCT,"ab+");
                struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,"",0};
                rewind(file);
                while(!feof(file))
                {
                    int result = fread(&comm,sizeof(struct commodity),1,file);
                    if((result == 1)&&(buy_code == comm.num))
                    {
                        state = 1;
                        break;
                    }
                }
                fclose(file);
                if(state == 1)
                {
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
                    if(comm.count < buy_count)
                    {
                        system("cls");
                        drawBorder();
                        goToXY(23,11);
                        printf("ѡ����Ʒ��治�㣬����ϵ����Ա��");
                        getch();
                        system("cls");
                        cus_main(name);
                    }
                    else
                    {
                        progressBar("ϵͳ���ڽ��㣬���Ժ�");
                        del_pro(buy_code);
                        FILE *file = fopen(PRODUCT,"ab+");
                        comm.sold += buy_count;
                        comm.count -= buy_count;
                        vault(comm.out_price,buy_count);
                        fwrite(&comm,sizeof(struct commodity),1,file);
                        fclose(file);

                        file = fopen(BUY_RECORD,"ab+");
                        struct record rec = {"","",0,""};
                        strcpy(rec.name,name);
                        strcpy(rec.product,comm.name);
                        rec.quantity = buy_count;
                        char date[15];
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
                        goToXY(23,11);
                        printf("ѡ����Ʒ�Ѿ�����ɹ����������������");
                        getch();
                        system("cls");
                        cus_main(name);
                    }
                }
                else if(state == 0)
                {
                    goToXY(18,8);
                    printf("��ʱδ����������Ҫ���ҵ���Ʒ�����ڴ������ϼܣ�");
                    goToXY(28,14);
                    printf("�������������");
                    getch();
                    system("cls");
                    cus_main(name);
                }


            }
            case 1:
                system("cls");
                show_page(name,"���ﳵ",name,2);
            }
        }

    }
}
void sort_search(char *name,int ver){
    remove("tmp_1.dat");
    int state = 0;
    system("cls");
    drawBorder();
    char input[20];
    goToXY(23,3);
    printf("****�����ѯҳ��,���Ի����Ĳ�ѯ��****");
    goToXY(20,7);
    printf("��������Ҫ��ѯ����Ʒ���");
    scanf("%s",input);
    FILE *file_tmp = fopen("tmp_1.dat","ab+");
    FILE *file = fopen(PRODUCT,"ab+");
    struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&comm,sizeof(struct commodity),1,file);
        if((result == 1)&&(!strcmp(comm.sort,input))){
            fwrite(&comm,sizeof(struct commodity),1,file_tmp);
            state = 1;
        }
    }
    fclose(file);
    fclose(file_tmp);
    progressBar("ϵͳ���ڶԸ������Ϣ���в�ѯ�����Ժ�");
    if(state == 0){
        system("cls");
        drawBorder();
        goToXY(18,11);
        printf("������ѯ����Ʒ��𲻴��ڣ�����������������棡");
        getch();
        switch(ver){
            case 1:
                system("cls");
                admin_main(name);
                break;
            case 2:
                system("cls");
                cus_main(name);
                break;
        }
    }else if(state == 1){
        show_page("tmp_1.dat","������Ʒ",name,ver);
    }
}
void admin_unsubscribe(char *name){
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
void cus_unsubscribe(char *name){
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
void out_file(char *name,int ver){
    if(ver == 1){
        FILE *file_out = fopen("��Ϣ����_����Ա.txt","w");
        FILE *file = fopen(PRODUCT,"ab+");
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
        while(!feof(file)){
            char info[100];
            int result = fread(&comm,sizeof(struct commodity),1,file);
            if(result == 1){
                sprintf(info,"��Ʒ��ţ�%d-��Ʒ���ƣ�%s-��Ʒ������%s-��Ʒ���%s-��Ʒ�����̣�%s-��������%d-�������%d-���ۣ�%.1lf-�ۼۣ�%.1lf\n",comm.num,comm.name,comm.desc,comm.sort,comm.provider,comm.sold,comm.count,comm.in_price,comm.out_price);
                fputs(info,file_out);
            }
        }
        fclose(file);
        fclose(file_out);
        system("cls");
        drawBorder();
        progressBar("���ڽ�ϵͳ��Ʒ����ת��Ϊ�ļ������Ժ�");
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("��Ʒ��Ϣ�����ɹ����������������");
        getch();
        system("cls");
        admin_main(name);
    }else if(ver == 2){
        FILE *file_out = fopen("��Ϣ����_�˿��û�.txt","w");
        FILE *file = fopen(PRODUCT,"ab+");
        struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
        while(!feof(file)){
            char info[100];
            int result = fread(&comm,sizeof(struct commodity),1,file);
            if(result == 1){
                sprintf(info,"��Ʒ��ţ�%d-��Ʒ���ƣ�%s-��Ʒ������%s-��Ʒ���%s-��Ʒ�����̣�%s-��Ʒ��������%d-��Ʒ�ۼۣ�%.1lf\n",comm.num,comm.name,comm.desc,comm.sort,comm.provider,comm.sold,comm.out_price);
                fputs(info,file_out);
            }
        }
        fclose(file);
        fclose(file_out);
        system("cls");
        drawBorder();
        progressBar("���ڽ�ϵͳ��Ʒ����ת��Ϊ�ļ������Ժ�");
        system("cls");
        drawBorder();
        goToXY(25,11);
        printf("��Ʒ��Ϣ�����ɹ����������������");
        getch();
        system("cls");
        cus_main(name);
    }
}
void info_change(char *name,int ver){
     FILE *file;
     if(ver == 1){
        file = fopen(USER_1,"ab+");
     }else if(ver == 2){
        file = fopen(USER_2,"ab+");
    }
    remove("copy.dat");
    FILE *file_copy = fopen("copy.dat","ab+");
     struct user use = {"","","","","",""};
     struct user User= {"","","","","",""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&use,sizeof(struct user),1,file);
         if(result != 0){
             if(strcmp(use.name,name)){
                fwrite(&use,sizeof(struct user),1,file_copy);
             }
             if(!strcmp(use.name,name)){
                system("cls");
                int state = 0;
                drawBorder();
                goToXY(24,3);
                printf("��ѡ����Ҫ�޸ĵ���Ϣ��");
                goToXY(26,6);
                printf("��  ��  �ǳ�");
                goToXY(46,6);
                printf("��ǰ��%s",use.name);
                goToXY(26,8);
                printf("��      �Ա�");
                goToXY(46,8);
                printf("��ǰ��%s",use.sex);
                goToXY(26,10);
                printf("��      ����");
                goToXY(46,10);
                printf("��ǰ��%s",use.mail);
                goToXY(26,12);
                printf("��      �ֻ���");
                goToXY(46,12);
                printf("��ǰ��%s",use.phone);
                goToXY(26,14);
                printf("��      ����");
                updown_bottom();
                while(TRUE){
                    char choice;
                    choice = getch();
                    if(choice == 72){
                        goToXY(30,6+state*2);
                        printf("\b  ");
                        state -= 1;
                        if(state == -1){
                            state = 4;
                        }
                        goToXY(30,6+state*2);
                        printf("��");
                    }else if(choice == 27){
                        fclose(file);
                        fclose(file_copy);
                        system("cls");
                        switch(ver){
                            case 1:
                                admin_main(name);
                                break;
                            case 2:
                                cus_main(name);
                                break;
                        }
                    }
                    else if(choice == 80){
                        goToXY(30,6+state*2);
                        printf("\b  ");
                        state += 1;
                        if(state == 5){
                            state = 0;
                        }
                        goToXY(30,6+state*2);
                        printf("��");
                    }else if(choice == '\r'){
                        system("cls");
                        drawBorder();
                        goToXY(24,10);
                        printf("��������Ҫ�޸ĵ���Ϣ��");
                        int state_1 = 1;
                        switch(state){
                            case 0:
                                scanf("%s",use.name);
                                char USER_NOW[30];
                                sprintf(USER_NOW,"USER_%d",ver);
                                FILE *file_info;
                                file_info = fopen(USER_NOW,"ab+");
                                rewind(file_info);
                                while(!feof(file))
                                {
                                    int result = fread(&User,sizeof(struct user),1,file);
                                    if(result != 0)
                                    {
                                        if(strcmp(User.name,use.name)==0){
                                            state_1 = 0;
                                            break;
                                        }
                                    }
                                }
                                if(state_1 == 0){
                                    system("cls");
                                    drawBorder();
                                    goToXY(25,11);
                                    printf("�û����ظ�����Ϣ�޸�ʧ�ܣ�");
                                    getch();
                                    system("cls");
                                    info_change(name,ver);
                                    cus_login();
                                }


                                break;

                            case 1:
                                scanf("%s",use.sex);
                                break;

                            case 2:
                                scanf("%s",use.mail);
                                break;

                            case 3:
                                scanf("%s",use.phone);
                                break;

                            case 4:
                                scanf("%s",use.pass);
                                strcpy(use.pass_double,use.pass);
                                break;
                        }
                        fwrite(&use,sizeof(struct user),1,file_copy);
                        break;
                    }
                }
            }
        }
    }
     fclose(file);
     fclose(file_copy);
     if(ver == 1){
        remove(USER_1);
        rename("copy.dat",USER_1);
     }
     else if(ver == 2){
        remove(USER_2);
        rename("copy.dat",USER_2);
     }
     progressBar("���ڸ��ĸ�����Ϣ�����Ժ�");
     system("cls");
     drawBorder();
     goToXY(25,11);
     printf("������Ϣ�޸ĳɹ����������������");
     getch();
     system("cls");
     if(ver == 1)
        admin_login_login();
     else if(ver == 2)
        cus_login_login();
}
void search_comm(char *name,int ver){
     system("cls");
     drawBorder();
     goToXY(28,3);
     printf("****�ؼ��ֲ�ѯ��Ʒ****");
     goToXY(24,10);
     printf("������ؼ���:");
     char key[15];
     scanf("%s",key);
     FILE *file = fopen(PRODUCT,"ab+");
     FILE *file_copy;
     file_copy = fopen("copy1.dat","w");
     struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
     rewind(file);
     while(!feof(file)){
         int result = fread(&comm,sizeof(struct commodity),1,file);
         if(result != 0){
             if(strstr(comm.name,key)!=NULL){
                 fwrite(&comm,sizeof(struct commodity),1,file_copy);
             }
         }
     }
     fclose(file);
     fclose(file_copy);
     show_page("copy1.dat","��Ʒ��Ϣ",name,ver);

}
void sales_ranking_query(char *name,int ver){
    system("cls");
    drawBorder();
    goToXY(23,3);
    printf("****�����ѯ��������****");
    goToXY(20,8);
    char view_sort[30];
    printf("��������鿴����Ʒ���");
    scanf("%s",view_sort);
    FILE *file =fopen("product.dat","ab+");

    struct commodity select_comm= {0,"",0.0,0.0,"",0.0,"",0,""};
    rewind(file);
    struct commodity product_select[1000];
    i=0;
    while(!feof(file))
    {
        int result = fread(&select_comm,sizeof(struct commodity),1,file);
        if(result != 0)
        {
            if(strcmp(select_comm.sort,view_sort)==0)
            {
                product_select[i]=select_comm;
                i++;
            }
        }
    }
    for(j=i-1; j>0; j--)
    {
        for(k=0; k<j; k++)
        {
            if(product_select[k].sold < product_select[k+1].sold)
            {
                struct commodity tmp=product_select[k];
                product_select[k]=product_select[k+1];
                product_select[k+1]=tmp;
            }
        }
    }
    fclose(file);
    FILE *file_select=fopen("select.dat","w");
    rewind(file_select);
    for(j=0; j<i; j++)
    {
        fwrite(&product_select[j],sizeof(struct commodity),1,file_select);
        printf("%s---%s---%d---%d\n",product_select[j].desc,product_select[j].provider,product_select[j].sold,product_select[j].count);
    }
    fclose(file_select);
	show_page("select.dat","��������",name,ver);
}
void buttom_title1(int num,int max_num,int ver){
    goToXY(6,21);
    if(ver==1)
    printf("��ESC������������\t��N�����ҳ\t��P����ǰ��ҳ\t��ǰҳ�룺%d/%d",num+1,max_num);
    else printf("��ESC������������ ��N�����ҳ ��P����ǰ��ҳ ��B������ ��ǰҳ�룺%d/%d",num+1,max_num);
}
void buttom_title2(int num,int max_num)
{
    goToXY(6,21);

    printf("��ESC������������\t��N�����ҳ\t��P����ǰ��ҳ\t��ǰҳ�룺%d/%d",num+1,max_num);

}
double vault(double out_price,int number){
    double total = 0.0;
    double total_tmp = 0.0;
    FILE *file;
    file = fopen(VAULT,"ab+");
    int result = fread(&total_tmp,sizeof(double),1,file);
    if(result == 1){
    	total = total_tmp;
	}
    fclose(file);
    total = total + out_price*number;
    file = fopen(VAULT,"w");
    fwrite(&total,sizeof(double),1,file);
    fclose(file);
    return total;
}
void alert(char *name){
    FILE *file = fopen(PRODUCT,"ab+");
    FILE *file_copy = fopen("copy1.dat","w");
    struct commodity comm = {0,"",0.0,0.0,"",0,"",0,""};
    rewind(file);
    int num = 0;
    while(!feof(file)){
        int result = fread(&comm,sizeof(struct commodity),1,file);
        if(result != 0){
            if(comm.count <= 3){
                fwrite(&comm,sizeof(struct commodity),1,file_copy);
                num = 1;
            }
        }
    }
    fclose(file);
    fclose(file_copy);
    if(num == 1)
    {
        show_page("copy1.dat","�����͵���Ʒ",name,1);
    }
}
void sold_chart(char *name){
    remove(DAY_SOLD);
    int days = 0;
    FILE *file = fopen(BUY_RECORD,"ab+");
    system("cls");
    drawBorder();
    progressBar("����Ϊ�������������������Ժ�");
    system("cls");
    struct record rec = {"","",0,""};
    rewind(file);
    char min_date[15] = "2020-12-30";

    while(!feof(file)){
        int result = fread(&rec,sizeof(struct record),1,file);
        if(result == 1 && (strcmp(rec.date,min_date) < 0)){
            strcpy(min_date,rec.date);
        }
    }
    char max_date[15];
    time_t timep;
    struct tm *p;
    time (&timep);
    p=gmtime(&timep);
    sprintf(max_date,"%d-%d-%d",p->tm_year + 1900,p->tm_mon + 1,p->tm_mday);
    days = count_days(min_date,max_date);
    FILE *file_day = fopen(DAY_SOLD,"ab+");
    struct day_sold ds = {"",0};
    int count = 0;
    int nouse_year;
    int month;
    int day;
    sscanf(min_date,"%d-%d-%d",&nouse_year,&month,&day);
    char date[15];
    for(i = 0;i < days;i++){
        count = 0;
        sprintf(date,"%d-%d-%d",nouse_year,month,day);
        rewind(file);
        while(!feof(file)){
            int result = fread(&rec,sizeof(struct record),1,file);
            if(result == 1 && !strcmp(rec.date,date)){
                count +=rec.quantity;
            }
        }
        strcpy(ds.date,date);
        ds.count = count;
        fwrite(&ds,sizeof(struct day_sold),1,file_day);
        day ++;
        if(month == 1 || month == 3 || month == 5|| month == 7 || month == 8 || month == 10 || month == 12){
            if(day == 32){
                day = 1;
                month++;
            }
        }else if(month == 2){
            if(day == 29){
                day =1;
                month++;
            }
        }else{
            if(day == 31){
                day =1;
                month++;
            }
        }

    }

    fclose(file);
    fclose(file_day);
    drawBorder();
    drawInBorder();
    goToXY(25,2);
    printf("****���������%d������������****",count_sold(name));
    show_chart(name,count_sold(name));
}
int count_sold(char *name){
    return count(DAY_SOLD,name);
}
void show_chart(char *name,int days){
    int page_num = 0;//��¼��ǰ�ķ�ҳ��
    buttom_title2(page_num,count(DAY_SOLD,name)/5 + 1);

    FILE *file = fopen(DAY_SOLD,"ab+");
    struct day_sold ds = {"",0};
    rewind(file);
    for(i = 1;i <= 6;i++){
        int result = fread(&ds,sizeof(struct day_sold),1,file);
        if(result == 1){
            char date[10];
            int month;
            int day;
            sscanf(ds.date,"%d-%d-%d",&k,&month,&day);
            sprintf(date,"%d-%d",month,day);
            goToXY(4,1+3*i);
            printf("%s: ",date);
            for(j = 0;j < ds.count/5 + 1;j++){
                printf("��");
            }
            goToXY(70,1+3*i);
            printf("%d��",ds.count);
        }
    }

    fclose(file);
    int state = 1;
    int choice = getch();
    while(state){
        switch(choice){
            case 110://N��
                state = 0;
                page_num++;
                if(page_num > count(DAY_SOLD,name)/5){
                    page_num = count(DAY_SOLD,name)/5;
                }
                chart_down(page_num,name,days);
                break;
            case 112://P��
                state = 0;
                page_num--;
                if(page_num < 0){
                    page_num = 0;
                }
                chart_up(page_num,name,days);
                break;
            case 27:
                state = 0;
                system("cls");
                admin_main(name);
                break;
            default:
                choice = getch();
        }
    }
}
void chart_up(int num,char *name,int days){
    int nums = 0;//����
    system("cls");
    drawBorder();
    drawInBorder();
    buttom_title2(num,count(DAY_SOLD,name)/5 + 1);
    goToXY(25,2);
    printf("****���������%d������������****",days);
    FILE *file = fopen(DAY_SOLD,"ab+");
    struct day_sold ds = {"",0};
    rewind(file);
    fseek(file,sizeof(struct day_sold)*5*num,SEEK_SET);
    for(i = 1;i <= 6;i++){
        int result = fread(&ds,sizeof(struct day_sold),1,file);
        if(result == 1){
            char date[15];
            int month;
            int day;
            sscanf(ds.date,"%d-%d-%d",&k,&month,&day);
            sprintf(date,"%d-%d",month,day);
            goToXY(4,1+3*i);
            printf("%s: ",date);
            for(j = 0;j < ds.count/5 + 1;j++){
                printf("��");
            }
            goToXY(70,1+3*i);
            printf("%d��",ds.count);
        }
    }
    fclose(file);
    int state = 1;
    int choice = getch();
    while(state){
        switch(choice){
            case 110://N��
                state = 0;
                num++;
                if(num > count(DAY_SOLD,name)/5){
                    num = count(DAY_SOLD,name)/5;
                }
                chart_down(num,name,days);
                break;
            case 112://P��
                state = 0;
                num--;
                if(num < 0){
                    num = 0;
                }
                chart_up(num,name,days);
                break;
            case 27:
                state = 0;
                system("cls");
                admin_main(name);
                break;
            default:
                choice = getch();
        }
    }
}
void chart_down(int num,char *name,int days){
    int nums = 0;//����
    system("cls");
    drawBorder();
    drawInBorder();
    buttom_title2(num,count(DAY_SOLD,name)/5 + 1);
    goToXY(25,2);
    printf("****���������%d������������****",days);
    FILE *file = fopen(DAY_SOLD,"ab+");
    struct day_sold ds = {"",0};
    rewind(file);
    fseek(file,sizeof(struct day_sold)*5*num,SEEK_SET);
    for(i = 1;i <= 6;i++){
        int result = fread(&ds,sizeof(struct day_sold),1,file);
        if(result == 1){
            char date[15];
            int month;
            int day;
            sscanf(ds.date,"%d-%d-%d",&k,&month,&day);
            sprintf(date,"%d-%d",month,day);
            goToXY(4,1+3*i);
            printf("%s: ",date);
            for(j = 0;j < ds.count/5 + 1;j++){
                printf("��");
            }
            goToXY(70,1+3*i);
            printf("%d��",ds.count);
        }
    }
    fclose(file);
    int state = 1;
    int choice = getch();
    while(state){
        switch(choice){
            case 110://N��
                state = 0;
                num++;
                if(num > count(DAY_SOLD,name)/5){
                    num = count(DAY_SOLD,name)/5;
                }
                chart_down(num,name,days);
                break;
            case 112://P��
                state = 0;
                num--;
                if(num < 0){
                    num = 0;
                }
                chart_up(num,name,days);
                break;
            case 27:
                state = 0;
                system("cls");
                admin_main(name);
                break;
            default:
                choice = getch();
        }
    }
}
int count_days(char *min_date,char *max_date){
    int count = 0;
    int max_year;
    int max_month;
    int max_day;
    int min_year;
    int min_month;
    int min_day;
    sscanf(max_date,"%d-%d-%d",&max_year,&max_month,&max_day);
    sscanf(min_date,"%d-%d-%d",&min_year,&min_month,&min_day);
    for(i = min_month + 1;i < max_month;i++){
        if(i == 1 || i == 3 || i == 5|| i == 7 || i == 8 || i == 10 || i == 12){
            count += 31;
        }else if(i == 2){
            count += 28;//��ʱ�����ǲ�������
        }else{
            count += 30;
        }
    }
    if(max_month != min_month){
        if(min_month == 1 || min_month == 3 || min_month == 5|| min_month == 7 || min_month == 8 || min_month == 10 || min_month == 12 ){
            count += 32 - min_day;
        }else if(min_month == 2){
            count += 29 - min_day;//��ʱ�����ǲ�������
        }else{
            count += 31 - min_day;
        }
        count += max_day;
    }else{
        count += max_day - min_day + 1;
    }

    return count;
}
void updown_bottom(){
    goToXY(7,21);
    printf("��ENTER��ѡ�����\t��ESC������\t����������\t����������");
}
void file_oi(char *name){
    int state = 0;
    system("cls");
    drawBorder();
    goToXY(26,9);
    printf("��ѡ�񵼳����룺");
    goToXY(26,12);
    printf("��  ��  ��Ϣ����");
    goToXY(26,14);
    printf("��      ��Ϣ����");
    updown_bottom();
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
            if(state == 2){
                state = 0;
            }
            goToXY(30,12+state*2);
            printf("��");

        }else if(choice == '\r'){
            switch(state){
                case 0:
                    in_file(name);
                    break;
                case 1:
                    system("cls");
                    drawBorder();
                    out_file(name,1);
                    break;
            }
        }else if(choice == 27){
            system("cls");
            drawBorder();
            admin_main(name);
        }
    }
    getchar();
}
void in_file(char *name){
    int count = 0;
    system("cls");
    drawBorder();
    char file_in[30],str[150],*result,delims[] = "-",nouse[30];
    goToXY(20,3);
    printf("****����������Խ��ļ��е���Ʒ��Ϣ����ϵͳ****");
    goToXY(18,8);
    printf("�������ļ����е���Ʒ��Ϣ�ļ���");
    scanf("%s",&file_in);
    system("copy product.dat pro.dat");
    struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,""};
    FILE *file = fopen(file_in,"r");
    FILE *file_pro = fopen(PRODUCT,"ab+");
    while(fgets(str,150,file)!=NULL){
        str[strlen(str) - 1] = '\0';
		result = strtok( str, delims );
		sscanf(result,"%10s%d",&nouse,&comm.num);
		result = strtok( NULL, delims );
		sscanf(result,"%10s%s",&nouse,&comm.name);
		result = strtok( NULL, delims );
		sscanf(result,"%10s%s",&nouse,&comm.desc);
		result = strtok( NULL, delims );
		sscanf(result,"%10s%s",&nouse,&comm.sort);
		result = strtok( NULL, delims );
		sscanf(result,"%12s%s",&nouse,&comm.provider);
		result = strtok( NULL, delims );
		sscanf(result,"%8s%d",&nouse,&comm.sold);
		result = strtok( NULL, delims );
		sscanf(result,"%8s%d",&nouse,&comm.count);
		result = strtok( NULL, delims );
		sscanf(result,"%6s%lf",&nouse,&comm.in_price);
		result = strtok( NULL, delims );
		sscanf(result,"%6s%lf",&nouse,&comm.out_price);

		if(ver_comm(comm) == 0){
            fwrite(&comm,sizeof(struct commodity),1,file_pro);
            count ++;
		}


	}
	fclose(file);
	fclose(file_pro);
    progressBar("���ڽ��ļ��е���Ϣ���룬���Ժ�");
    system("cls");
    drawBorder();
    if(count != 0){
        goToXY(22,11);
        printf("���ι�����%d����Ʒ��Ϣ���������������",count);
    }else{
        goToXY(22,10);
        printf("��Ǹ�������ṩ���ļ���û���ҵ���Ʒ��Ϣ��");
        goToXY(29,11);
        printf("�������������");
    }
    getch();
    system("cls");
    admin_main(name);
}
int ver_comm(struct commodity comm){
    int state = 0;
    FILE *file = fopen("pro.dat","ab+");
    struct commodity co = {0,"",0.0,0.0,"",0.0,"",0,""};
    rewind(file);
    while(!feof(file)){
        int result = fread(&co,sizeof(struct commodity),1,file);
        if(result == 1 && co.num == comm.num && !strcmp(co.name,comm.name) && !strcmp(co.desc,comm.desc)){
            state = 1;
            break;
        }
    }
    return state;
}
void move_to_shopping_cart(char *name)
{
    goToXY(6,22);
    int select_num,select_count;
    printf("����������빺�ﳵ����Ʒ���");
    scanf("%d",&select_num);
    FILE *file=fopen(PRODUCT,"ab+");
    FILE *file_cart=fopen(name,"ab+");
    struct commodity cart_comm= {0,"",0,0,"",0,"",0,"",0};
    struct commodity test_comm= {0,"",0,0,"",0,"",0,"",0};
    rewind(file);
    j=1;
    while(!feof(file))
    {
        int result = fread(&cart_comm,sizeof(struct commodity),1,file);
        if(result != 0)
        {
            if(cart_comm.num==select_num)
            {
                j=0;
                break;
            }


        }
    }
    if(j)
    {
        system("cls");
        goToXY(28,9);
        printf("û�д���Ʒ��");
        system("pause");
        system("cls");
        cus_main(name);
    }

    else
    {
        system("cls");
        goToXY(23,9);
        printf("��������빺�ﳵ��������");
        scanf("%d",&select_count);
        rewind(file);
        while(!feof(file_cart))
        {
            int result = fread(&test_comm,sizeof(struct commodity),1,file_cart);
            if(result != 0)
            {
                if(test_comm.num==select_num)
                {
                    j=1;
                    break;
                }
            }
        }
        if(!j)
        {
            cart_comm.cart_count=select_count;
            fwrite(&cart_comm,sizeof(struct commodity),1,file_cart);
            fclose(file);
            fclose(file_cart);
        }
        else
        {
            test_comm.cart_count+=select_count;


            FILE *file_move = fopen("cop.dat","ab+");
            rewind(file_cart);
            rewind(file_move);
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,"",0};
            rewind(file_cart);
            while(!feof(file_cart))
            {
                int result = fread(&comm,sizeof(struct commodity),1,file_cart);
                if(result != 0)
                {
                    if(comm.num != test_comm.num)
                    {
                        fwrite(&comm,sizeof(struct commodity),1,file_move);
                    }
                    else
                    {
                        fwrite(&test_comm,sizeof(struct commodity),1,file_move);
                    }
                }
            }
            fclose(file_cart);
            fclose(file_move);
            remove(name);
            rename("cop.dat",name);

        }

        system("cls");
        goToXY(28,9);
        printf("����ɹ���");
        system("pause");
        system("cls");
        cus_main(name);
    }


}
void empty_cart(char *name)
{
    int state=0;

    FILE *buy_file=fopen(name,"ab+");
    struct commodity buy_comm= {0,"",0.0,0.0,"",0.0,"",0,"",0};
    rewind(buy_file);
    j=1;
    while(!feof(buy_file))
    {
        int result = fread(&buy_comm,sizeof(struct commodity),1,buy_file);
        if(result != 0)
        {
            FILE *file = fopen(PRODUCT,"ab+");
            struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,"",0};
            rewind(file);

            while(!feof(file))
            {
                int result = fread(&comm,sizeof(struct commodity),1,file);//�ҵ��ⷿ�е���Ʒ
                if((result == 1)&&(buy_comm.num == comm.num))
                {
                    state = 1;
                    break;
                }
            }
            fclose(file);
            if(state == 1)
            {
                if(comm.count < buy_comm.cart_count)      //�ж��Ƿ��л�
                {
                    j=0;
                    system("cls");
                    drawBorder();
                    goToXY(23,11);
                    printf("��Ʒ%s��治��,���ι���ȡ����",buy_comm.name);
                    getch();
                    break;

                }
            }
        }
    }
    state=0;
    if(j==0)
    {
        system("cls");
        cus_main(name);
    }
    else
    {
        rewind(buy_file);
        while(!feof(buy_file))
        {
            int result = fread(&buy_comm,sizeof(struct commodity),1,buy_file);
            if(result != 0)
            {

                FILE *file = fopen(PRODUCT,"ab+");
                struct commodity comm = {0,"",0.0,0.0,"",0.0,"",0,"",0};
                rewind(file);
                while(!feof(file))
                {
                    int result = fread(&comm,sizeof(struct commodity),1,file);//�ҵ��ⷿ�е���Ʒ
                    if((result == 1)&&(buy_comm.num == comm.num))
                    {
                        state = 1;
                        break;
                    }
                }
                fclose(file);
                if(state == 1)
                {
                    progressBar("ϵͳ���ڽ��㣬���Ժ�");
                    del_pro(buy_comm.num);
                    FILE *file = fopen(PRODUCT,"ab+");
                    comm.sold += buy_comm.cart_count;
                    comm.count -= buy_comm.cart_count;
                    vault(comm.out_price,buy_comm.cart_count);
                    fwrite(&comm,sizeof(struct commodity),1,file);
                    fclose(file);

                    file = fopen(BUY_RECORD,"ab+");
                    struct record rec = {"","",0,""};
                    strcpy(rec.name,name);
                    strcpy(rec.product,comm.name);
                    rec.quantity = buy_comm.cart_count;
                    char date[15];
                    time_t timep;
                    struct tm *p;
                    time (&timep);
                    p=gmtime(&timep);
                    sprintf(date,"%d-%d-%d",p->tm_year + 1900,p->tm_mon + 1,p->tm_mday);
                    strcpy(rec.date,date);
                    fwrite(&rec,sizeof(struct record),1,file);
                    fclose(file);
                }


            }
        }
        system("cls");
        drawBorder();
        goToXY(23,11);
        printf("ѡ����Ʒ�Ѿ�����ɹ����������������");
        fclose(buy_file);
        FILE *buy_file=fopen(name,"w");
        fclose(buy_file);
        getch();
        system("cls");
        cus_main(name);
    }
}
void del_cart(char *name)
{   goToXY(6,22);
    int del_num,del_count;
    printf("��������ɾ������Ʒ���");
    scanf("%d",&del_num);
    FILE *file=fopen(name,"ab+");
    FILE *file_cart_del=fopen("name_cop.dat","ab+");
    struct commodity comm= {0,"",0,0,"",0,"",0,"",0};
    struct commodity comm_move= {0,"",0,0,"",0,"",0,"",0};
    rewind(file);
    j=1;
    while(!feof(file))
    {
        int result = fread(&comm,sizeof(struct commodity),1,file);
        if(result != 0)
        {
            if(comm.num==del_num)
            {
                j=0;
                break;
            }


        }
    }
    if(j)
    {
        system("cls");
        goToXY(26,9);
        printf("���ﳵ��û�д���Ʒ��");
        system("pause");
        system("cls");
        cus_main(name);
    }

    else
    {
        system("cls");
        goToXY(23,9);
        printf("������ɾ����������");
        goToXY(18,11);
        printf("�������������ڹ��ﳵ������,�Ὣ����Ʒȫ��ɾ��!");
        scanf("%d",&del_count);
        if(comm.cart_count>del_count)
        {
            comm.cart_count-=del_count;
            rewind(file);
            rewind(file_cart_del);
            while(!feof(file))
            {
                int result = fread(&comm_move,sizeof(struct commodity),1,file);
                if(result != 0)
                {
                    if(comm.num != comm_move.num)
                    {
                        fwrite(&comm_move,sizeof(struct commodity),1,file_cart_del);
                    }
                    else
                    {
                        fwrite(&comm,sizeof(struct commodity),1,file_cart_del);
                    }
                }
            }
            fclose(file);
            fclose(file_cart_del);
            remove(name);
            rename("name_cop.dat",name);
        }
        else if(comm.cart_count<=del_count)
        {
            rewind(file);
            rewind(file_cart_del);
            while(!feof(file))
            {
                int result = fread(&comm_move,sizeof(struct commodity),1,file);
                if(result != 0)
                {
                    if(comm.num != comm_move.num)
                    {
                        fwrite(&comm_move,sizeof(struct commodity),1,file_cart_del);
                    }
                }
            }
            fclose(file);
            fclose(file_cart_del);
            remove(name);
            rename("name_cop.dat",name);

        }

        system("cls");
        goToXY(28,9);
        printf("ɾ���ɹ���");
        system("pause");
        system("cls");
        cus_main(name);
    }



}
