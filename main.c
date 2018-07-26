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

struct commidity{
    int num;
    char name[15];
    double price;
    double count;
    double total;
} ;
//�ṹ������
struct commidity comm[50];



void start();
void goToXY();
void drawBorder();
void drawTitle();
void admin_main();
void cus_main();
void progressBar();//������


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

    while(TRUE){
        char choice;
        choice = getch();
        if(choice == '8'){
            goToXY(30,14);
            printf("\b  ");
            goToXY(30,12);
            printf("��");
            state = 0;
        }
        else if(choice == '2'){
            goToXY(30,12);
            printf("\b  ");
            goToXY(30,14);
            printf("��");
            state = 1;
        }else if(choice == '5'){
            switch(state){
                case 0:
                    progressBar();
                    Sleep(100);
                    system("cls");
                    admin_main();
                    break;

                case 1:
                    system("cls");
                    cus_main();
                    break;
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
void admin_main(){
    drawBorder();
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
    char choice;
    choice = getchar();
    switch(choice){
        case '1':
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            break;
        case '8':
            break;
        case '9':
            break;
        case '10':
            break;
        case '11':
            break;
        case '12':
            break;
        case '13':
            break;
    }

}
void cus_main(){

}
void progressBar(){
    goToXY(26,19);
    printf("ϵͳ���ڼ��أ����Ժ�");
    goToXY(19,17);
    for(i = 0;i <= 20;i++){
        goToXY(19+i*2,17);
        printf("��");
        goToXY(69,17);
        printf("%d%%",i*5);
        Sleep(100);
    }


}
