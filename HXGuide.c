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
	system("cls");
	printf("HBU�����б�:\n");
	int i;
	for(i = 0;i<HBUmap.n;i++)
        printf("%d : %s\n",i+1,HBUmap.vexs[i].name);
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
	if(HBUmap.n <= 0)
    {
        printf("���Ǹ���ѧУ��û���κξ���~\n");
        return;
    }
    showInfo();
    printf("��Ҫ���Ǹ�˵��:");
    int a;
    scanf("%d",&a);
    system("cls");
    while(a<1 || a>HBUmap.n)
    {
        printf("�ⶼ�����1��%d֮�䣬�����䣡\n",HBUmap.n);
        scanf("%d",&a);
    }
    printf("%s:%s\n",HBUmap.vexs[a-1].name,HBUmap.vexs[a-1].features);
    Sleep(1000);
	printf("����1S�󷵻�������\n"); 
	Sleep(1000);
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
	if(HBUmap.n <= 0)
    {
        printf("����һ����ٵ�ѧУ����Ȼû���κξ���\n");
        return;
    }
    showInfo();
    int a;
    printf("��˵����Ҫ�ģ�˵��ţ�\n");
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("�������ˣ���1��ʼ��%d���������Ա��\n",HBUmap.n);
        scanf("%d",&a);
    }
    char newName[100];
    char newFeatures[1000];
    printf("����ԭ����%s,��Ҫ��������ɶ����\n",HBUmap.vexs[a-1].name);
    scanf("%s",newName);getchar();
    printf("��������ǣ�\n%s\n��˵�ĳ�ɶ����\n",HBUmap.vexs[a-1].features);
    scanf("%s",newFeatures);getchar();
    printf("�����޸�...\n");
    strcpy(HBUmap.vexs[a-1].name, newName);
    strcpy(HBUmap.vexs[a-1].features, newFeatures);
    long long int i=0;
	for(i = 0;i<DELAY ;i++);
    printf("���˸ĺ���\n");
    printf("Ҫ���ľ�����1�����ľ��˳���\n");
    int flag;
    scanf("%d",&flag);
    if(flag == True)
        modifyInfo();
	return;
}
//��Ӿ���
void addInfo(void){
	
	if(HBUmap.n >= MaxVerNum)
    {
        printf("�Ӵ��Ѿ����˲����ټ���\n");
        return;
    }
    showInfo();
    char newName[100];char newFeatures[500];
    printf("�¼ӵ����������ɶ����\n");
    scanf("%s",newName);getchar();
    printf("%s��ɶ�ص㣿\n",newName);
    scanf("%s",newFeatures);getchar();
    showInfo();
    int m;
    printf("���Ա��м������㣿\n");
    scanf("%d",&m);
    int i ;
	for(i= 0;i<m;i++)
    {
        int a,distance;
        printf("��һ��%s�ĵ�%d�������ľ���ı��:\n",newName,i+1);
        scanf("%d",&a);
        while(a<1 || a>HBUmap.n || HBUmap.edges[a-1][HBUmap.n] != INFINITY)
        {
            if(a<1 || a>HBUmap.n)
            {
                printf("����ˣ������1��%d֮�䣬�����䣡\n",HBUmap.n);
                scanf("%d",&a);
            }
            if(HBUmap.edges[a-1][HBUmap.n] != INFINITY)
            {
                printf("�ϸ磬����Ѿ����ˣ�������\n");
                scanf("%d",&a);
            }
        }
        printf("%s��%s֮��ľ����Ƕ��٣�:\n",newName,HBUmap.vexs[a-1].name);
        scanf("%d",&distance);
        while(distance <=0 || distance>INFINITY)
        {
            printf("��������Ƿ����������룡\n");
            scanf("%d",&distance);
        }
        HBUmap.edges[a-1][HBUmap.n] = HBUmap.edges[HBUmap.n][a-1] = distance;
    }
    printf("������Ӿ���...\n");
    strcpy(HBUmap.vexs[HBUmap.n++].name,newName);
    strcpy(HBUmap.vexs[HBUmap.n-1].features,newFeatures);
    HBUmap.e += m;
    
	for(i= 0;i<DELAY ;i++);
    printf("���������ӳɹ��ˣ�\n");
    printf("��Ҫ�Ӿ�����1�����������ַ����˳�\n");
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
        addInfo();
	return;
}
//ɾ������
void delInfo(void){
	if(HBUmap.n <= 0)
    {
        printf("�Ѿ�ɾû�ˣ�������ɾ����\n");
        return;
    }
    showInfo();
    printf("��Ҫɾ���ĸ����㣿\n");
    int a;
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("%d,���㶼����ˣ��������룡\n",HBUmap.n);
        scanf("%d",&a);
    }
    printf("ɾ���ľ���Ϊ��%s���Ҫɾ�� ����1 for sure�� \n",HBUmap.vexs[a-1].name);
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
    {
        printf("ɾ������ING\n");
        int i,j;
        int count = 0;
        for(i = 0;i<HBUmap.n;i++)
            if(HBUmap.edges[a-1][i] != INFINITY)
                count++;
        for(i = a-1;i<HBUmap.n;i++)
            HBUmap.vexs[i] = HBUmap.vexs[i+1];
        for(i = 0;i<HBUmap.n;i++)
            
			for(j = a-1;j<HBUmap.n;j++)
                HBUmap.edges[i][j] = HBUmap.edges[i][j+1];
        for(i = 0;i<HBUmap.n;i++)
            for(j = a-1;j<HBUmap.n;j++)
                HBUmap.edges[j][i] = HBUmap.edges[j+1][i];
        HBUmap.n--;
        HBUmap.e -= count;
    }
    else
        return;
        long long i; 
    for(i = 0;i<DELAY ;i++);
    printf("�Ѿ�ɾ����\n��1s��ص�������");
    Sleep(1000); 
	return;
}
//��ӵ�·
void addPath(void){
	if(HBUmap.n <= 0)
    {
        printf("�����ϱ�û��·���ߵ��˶��˾�����·�����ڻ�û��·��~\n");
        return;
    }
    showInfo();
    if(HBUmap.e == 0)
        printf("����Ŀǰ���޵�·\n");
    else
        printf("Ŀǰ�ܹ���%d����·\n",HBUmap.e);
    printf("�������·�����յ㣺\n");
    int a,b;
    scanf("%d %d",&a,&b);
    while(a<1 || a>HBUmap.n || b<1 || b>HBUmap.n || a == b)
    {
        if(a == b)
            printf("����˰ɣ�����զһ���أ���\n");
        else
            printf("����������������%d��������\n",HBUmap.n);
        scanf("%d %d",&a,&b);
    }
    if(HBUmap.edges[a-1][b-1] != INFINITY){
        printf("%s��%s֮������·�Ѿ����ˣ���Ҫ����ӣ�\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        return;
    }
    else
    {
        int distance;
        printf("������%s��%s֮���·�ĳ��ȣ�\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        scanf("%d",&distance);
        while(distance <=0 || distance >= INFINITY)
        {
            printf("�������������\n");
            scanf("%d",&distance);
        }
        printf("������ӵ�·...\n");
        HBUmap.edges[a-1][b-1] = HBUmap.edges[b-1][a-1] = distance;
        HBUmap.e++;
        long long i;
        for(i = 0;i<DELAY ;i++);
        printf("��·��ӳɹ���\n");
        printf("1s��ص�������");
    Sleep(1000); 
    }
	return;
}
//ɾ����·
void delPath(void){
	if(HBUmap.n <= 0)
    {
        printf("���κξ��㣬�������\n");
        return;
    }
    if(HBUmap.e <= 0)
    {
        printf("��ͼ�����κε�·��������ӣ�\n");
        return;
    }
    showInfo();
    printf("Ŀǰ�ܹ���%d����·\n",HBUmap.e);
    printf("������Ҫɾ����·�����������ţ��м��ÿո������\n");
    int a,b;
    scanf("%d %d",&a,&b);
    while(a<1 || a>HBUmap.n || b<1 || b>HBUmap.n || a == b)
    {
        if(a == b)
            printf("��������������ͬ��ţ��������룡\n");
        else
            printf("�����������������Ŷ�Ӧλ��1��%d֮�䣬�������룡\n",HBUmap.n);
        scanf("%d %d",&a,&b);
    }
    if(HBUmap.edges[a-1][b-1] == INFINITY)
    {
        printf("%s��%s֮���޵�·��\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        return;
    }
    else
    {
        printf("��Ҫɾ������%s��%s�ĵ�·,ȷ������1 \n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        int flag;
        scanf("%d",&flag);
        if(flag == 1)
        {
            printf("����ɾ����·...\n");
            HBUmap.edges[a-1][b-1] = HBUmap.edges[b-1][a-1] = INFINITY;
            HBUmap.e--;
            long long i;
            for(i = 0;i<DELAY ;i++);
            printf("��·ɾ���ɹ���\n");
        }
        else
            return;
        	printf("1s��ص�������");
    		Sleep(1000); 
    }
    return ; 
}
//����ͼ
void create(void){
	HBUmap.n = 12;//12������ 
    HBUmap.e = 20;//20��· 
    int i ;
	for(i = 0;i<MaxVerNum;i++)
    {
        HBUmap.vexs[i].num = i+1;
    }
    for(i = 0;i<MaxVerNum;i++){
    	int j=0;
		for(j = 0;j<MaxVerNum;j++)
            HBUmap.edges[i][j] = INFINITY;	
	}
    strcpy(HBUmap.vexs[0].name, "�ٳ�");
    strcpy(HBUmap.vexs[0].features, "��һǧ�׵ĺõط�");
    strcpy(HBUmap.vexs[1].name, "ͼ���");
    strcpy(HBUmap.vexs[1].features, "������Ҫʹ��ѧ������΢�Ź��ں�ԤԼ");
    strcpy(HBUmap.vexs[2].name, "�������");
    strcpy(HBUmap.vexs[2].features, "˭�ܸ���������Ǹ�ɶ�ģ�");
    strcpy(HBUmap.vexs[3].name, "У�ű���");
    strcpy(HBUmap.vexs[3].features, "����ڲ���������������ѧ��ʱ�����Ҳ���ý���");
    strcpy(HBUmap.vexs[4].name, "���Ӿ���");
    strcpy(HBUmap.vexs[4].features, "�������԰�����µ�����");
    strcpy(HBUmap.vexs[5].name, "����������");
    strcpy(HBUmap.vexs[5].features, "һ����ί�ٰ���ĵط�");
    strcpy(HBUmap.vexs[6].name, "����");
    strcpy(HBUmap.vexs[6].features, "�����������ԵĲ�඼��");
    strcpy(HBUmap.vexs[7].name, "��԰����");
    strcpy(HBUmap.vexs[7].features, "û�п�������û�п�����");
    strcpy(HBUmap.vexs[8].name, "У�Ŷ���");
    strcpy(HBUmap.vexs[8].features, "���м�����ڳ�ȥ��ȫ�Ƿ�С���ġ�");
    strcpy(HBUmap.vexs[9].name, "��Ϣѧ��");
    strcpy(HBUmap.vexs[9].features, "����ض������أ���ûȥ����");
    strcpy(HBUmap.vexs[10].name, "����ѧԺ");
    strcpy(HBUmap.vexs[10].features, "C1������ռ䰲ȫ������ѧԺ");
    strcpy(HBUmap.vexs[11].name, "У���Ͽ�");
    strcpy(HBUmap.vexs[11].features, "ѧУ���ڵĴ��ſ�");
    //��ӱ�Ȩ 
    HBUmap.edges[0][2] = HBUmap.edges[2][0] = 350;
    HBUmap.edges[0][5] = HBUmap.edges[5][0] = 480;
    HBUmap.edges[0][1] = HBUmap.edges[1][0] = 280;
    HBUmap.edges[0][3] = HBUmap.edges[3][0] = 200;
    HBUmap.edges[3][4] = HBUmap.edges[4][3] = 100;
    HBUmap.edges[3][6] = HBUmap.edges[6][3] = 100;
    HBUmap.edges[4][6] = HBUmap.edges[6][4] = 100;
    HBUmap.edges[2][5] = HBUmap.edges[5][2] = 200;
    HBUmap.edges[1][5] = HBUmap.edges[5][1] = 400;
    HBUmap.edges[1][7] = HBUmap.edges[7][1] = 160;
    HBUmap.edges[1][8] = HBUmap.edges[8][1] = 300;
    HBUmap.edges[6][8] = HBUmap.edges[8][6] = 100;
    HBUmap.edges[5][9] = HBUmap.edges[9][5] = 500;
    HBUmap.edges[11][10] = HBUmap.edges[10][11] = 400;
    HBUmap.edges[11][9] = HBUmap.edges[9][11] = 400;
    HBUmap.edges[11][7] = HBUmap.edges[7][11] = 500;
    HBUmap.edges[11][8] = HBUmap.edges[8][11] = 600;
    HBUmap.edges[10][5] = HBUmap.edges[5][10] = 500;
    HBUmap.edges[9][7] = HBUmap.edges[7][9] = 150;
    HBUmap.edges[8][7] = HBUmap.edges[7][8] = 200;
	return;
}



