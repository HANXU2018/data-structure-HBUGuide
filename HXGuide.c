/*
 1.���������б�
 2.����洢���ݽṹ��
 3.��д�û�����Ա��¼���棬�Լ��������á� 
 4.���Ƹ����������ܡ� 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h> 
#define MaxVerNum 100
#define MaxNameLength 100
#define MaxDiscrabeLength 1000
#define PASSWORD "root"
#define PASSWORDLENGTH 20 
#define INFINITY 1000000
#define DELAY 982337369
#define CONFIRMATION "QUEREN"
#define True 1
#define False 0

// 1.���������б�

	void showInfo(void);//������о���
	void Visiter(void);//�ο�ϵͳ
	void Administrator(void);//����Աϵͳ
	void introduct(void);//�������
	void Dijkstra(void);//�����ο����ھ�������������ľ���
	void Floyd(void);//�����ο�ָ�����������������·������
	void modifyInfo(void);//�޸ľ�����Ϣ
	void addInfo(void);//��Ӿ���
	void delInfo(void);//ɾ������
	void addPath(void);//��ӵ�·
	void delPath(void);//ɾ����·
	void showInfo(void);//չʾ���
	void create(void);//����ͼ
	


// 2.����洢���ݽṹ��


	typedef struct {
	    int num;
	    char name[MaxNameLength];
	    char features[MaxDiscrabeLength];
	}VertexType;//�ڵ����� 
	
	typedef int EdgeType;// ��Ե���� 
	
	typedef struct {
	    VertexType vexs[MaxVerNum];
	    EdgeType edges[MaxVerNum][MaxVerNum];
	    int n;
	    int e;
	}MGraph;// ͼ���� 
 

//ȫ�ֱ���

	MGraph HBUmap;//����У԰����ͼ
	static int flag = 1;//�ڱ������������ж� �û�Ȩ�� 


//������

int main(){
	create();
	printf("Weclome to the HBU\n");
	while(True){
		system("cls");
		printf("��ӭʹ��HBUGuide\n");
		printf("��ѡ����ʹ�õĽ�ɫ\n");
		printf("�ο��밴1\n");
		printf("����Ա�밴2\n");
		printf("����ѡ���˳�ϵͳ"); 
		
		int choose;
		scanf("%d",&choose);
		
		switch(choose){
			case 1:
            	Visiter();//ת���οͽ��� 
            	break; 
            case 2:
				 printf("�������������룺");
				 char password[PASSWORDLENGTH];
				 scanf("%s",password);
				 getchar();//һ��Ҫ�Իس�����ȻӰ����һ������
				 if(strcmp(password, PASSWORD)==False) {
				 	printf("������ȷ����������ϵͳ\n"); 
				 	Administrator();//ת�볬������Ա���� 
				 }else{
				 	printf("������󼴽��˻�������\n");
				 } 
				 break;
			default:
				printf("������1s���˳�ϵͳ����л����ʹ�á�");
				Sleep(1000); 
				return 0; 
		} 
	}
	return 0;
} 
//������о���
void showInfo(void){
	return;
}
//�ο�ϵͳ
void Visiter(void){
	system("cls");
	int choose=0;
	while(True){
		printf("�����ϵܣ���ӭ�����ӱ���ѧHBU\n");
		printf("���ܲ˵�\n");
		printf("1.��������\n");
		printf("2.��ѯ��ǰλ�õ�����λ�õ����·��\n");
		printf("3.��ѯ��������λ�õ����·��\n");
		printf("4.�뿪ϵͳ\n");
		scanf("%d",&choose);
		system("cls");
		switch (choose) {
            case 1:
            	printf("��������:\n"); 
                introduct();
                break;
            case 2:
            	printf("�ؽ�˹�����㷨���������·��\n"); 
                Dijkstra();
                break;
            case 3:
            	printf("�����׵ð��㿴��������������·��\n"); 
                Floyd();
                break;
            case 4:
            	printf("��� �ص��������ˣ��ϸ��ټ�~�\n"); 
                return;
            default:
                printf("�ϸ�������˰ɣ��������ԣ�\n");
                break;
        } 
	}
	return;
}
//����Աϵͳ
void Administrator(void){
	system("cls");
	while(True)
    {
        int choose;
        printf("ֻ�й���Ա���ܿ����Ĺ���ϵͳ\n");
        printf("1.�������\n"); 
        printf("2.���������ڵľ��㵽������������·��\n"); 
        printf("3.����������������֮������·��\n"); 
        printf("4.�޸ľ�����Ϣ\n"); 
        printf("5.���Ӿ�����Ϣ\n"); 
        printf("6.ɾ��������Ϣ\n"); 
        printf("7.���ӵ�·\n"); 
        printf("8.ɾ����·\n"); 
        printf("9.�˳�����ϵͳ\n"); 
        scanf("%d",&choose);
        switch (choose) {
            case 1:
            	system("cls");
            	printf("���Ҹ���������\n");
                introduct();
                break;
            case 2:
            	system("cls");
            	printf("�ؽ�˹�����㷨\n");
                Dijkstra();
                break;
            case 3:
            	system("cls");
            	printf("���������㷨\n");
                Floyd();
                break;
            case 4:
            	system("cls");
            	printf("�Ĵ��ˣ�����ģ�\n");
                modifyInfo();
                break;
            case 5:
            	system("cls");
            	printf("�ٶ�д�������\n");
                addInfo();
                break;
            case 6:
            	system("cls");
            	printf("д���ˣ�ɾ�˰�\n");
                delInfo();
                break;
            case 7:
            	system("cls");
            	printf("�Ӵ�����·��\n");
                addPath();
                break;
            case 8:
            	system("cls");
            	printf("����·�������ˣ�\n");
                delPath();
                break;
            case 9:
            	system("cls");
            	printf("�ټ�~~~\n");
                return;
            default:
            	system("cls");
                printf("�ϸ�����ˣ�Ҫ���������ԣ�\n");
                break;
        }
    }
	return;
}
//�������
void introduct(void){
	return;
}
//�����ο����ھ�������������ľ���
void Dijkstra(void){
	return;
}
//�����ο�ָ�����������������·������
void Floyd(void){
	return;
}
//�޸ľ�����Ϣ
void modifyInfo(void){
	return;
}
//��Ӿ���
void addInfo(void){
	return;
}
//ɾ������
void delInfo(void){
	return;
}
//��ӵ�·
void addPath(void){
	return;
}
//ɾ����·
void delPath(void){
	return;
}
//����ͼ
void create(void){
	return;
}



