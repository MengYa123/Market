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

int i,j,k;//����ѭ������


int main()
{
    start();

    return 0;
}
void start(){
    system("color f1");
    drawBorder();
    drawTitle();
    goToXY(24,9);
    printf("��ѡ��������ݽ��е�¼��ע�᣺");
    goToXY(26,12);
    printf("��  ��  ���й���Ա");
    goToXY(26,14);
    printf("��      �˿�");


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
