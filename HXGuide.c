/*
 1.构建函数列表
 2.构造存储数据结构体
 3.编写用户管理员登录界面，以及函数调用。 
 4.完善各个函数功能。 
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

// 1.构建函数列表

	void showInfo(void);//输出所有景点
	void Visiter(void);//游客系统
	void Administrator(void);//管理员系统
	void introduct(void);//景点介绍
	void Dijkstra(void);//查找游客所在景点与其他景点的距离
	void Floyd(void);//查找游客指定的两个景点间的最短路径长度
	void modifyInfo(void);//修改景点信息
	void addInfo(void);//添加景点
	void delInfo(void);//删除景点
	void addPath(void);//添加道路
	void delPath(void);//删除道路
	void showInfo(void);//展示面板
	void create(void);//生成图
	


// 2.构造存储数据结构体


	typedef struct {
	    int num;
	    char name[MaxNameLength];
	    char features[MaxDiscrabeLength];
	}VertexType;//节点类型 
	
	typedef int EdgeType;// 边缘类型 
	
	typedef struct {
	    VertexType vexs[MaxVerNum];
	    EdgeType edges[MaxVerNum][MaxVerNum];
	    int n;
	    int e;
	}MGraph;// 图类型 
 

//全局变量

	MGraph HBUmap;//生成校园导航图
	static int flag = 1;//哨兵变量，用于判断 用户权限 


//主函数

int main(){
	create();
	printf("Weclome to the HBU\n");
	while(True){
		system("cls");
		printf("欢迎使用HBUGuide\n");
		printf("请选择您使用的角色\n");
		printf("游客请按1\n");
		printf("管理员请按2\n");
		printf("其他选择将退出系统"); 
		
		int choose;
		scanf("%d",&choose);
		
		switch(choose){
			case 1:
            	Visiter();//转入游客界面 
            	break; 
            case 2:
				 printf("请输入您的密码：");
				 char password[PASSWORDLENGTH];
				 scanf("%s",password);
				 getchar();//一定要吃回车，不然影响下一次输入
				 if(strcmp(password, PASSWORD)==False) {
				 	printf("密码正确，即将进入系统\n"); 
				 	Administrator();//转入超级管理员界面 
				 }else{
				 	printf("密码错误即将退回主界面\n");
				 } 
				 break;
			default:
				printf("即将在1s后退出系统，感谢您的使用。");
				Sleep(1000); 
				return 0; 
		} 
	}
	return 0;
} 
//输出所有景点
void showInfo(void){
	return;
}
//游客系统
void Visiter(void){
	system("cls");
	int choose=0;
	while(True){
		printf("来了老弟，欢迎来到河北大学HBU\n");
		printf("功能菜单\n");
		printf("1.景点描述\n");
		printf("2.查询当前位置到其它位置的最短路径\n");
		printf("3.查询任意两个位置的最短路径\n");
		printf("4.离开系统\n");
		scanf("%d",&choose);
		system("cls");
		switch (choose) {
            case 1:
            	printf("景点描述:\n"); 
                introduct();
                break;
            case 2:
            	printf("地杰斯特拉算法帮你瞅瞅最短路径\n"); 
                Dijkstra();
                break;
            case 3:
            	printf("弗洛易得帮你看看任意两点的最短路径\n"); 
                Floyd();
                break;
            case 4:
            	printf("这就 回到主界面了，老哥再见~n"); 
                return;
            default:
                printf("老哥您输错了吧，再来试试？\n");
                break;
        } 
	}
	return;
}
//管理员系统
void Administrator(void){
	system("cls");
	while(True)
    {
        int choose;
        printf("只有管理员才能看到的管理系统\n");
        printf("1.景点介绍\n"); 
        printf("2.查找您所在的景点到其他景点的最短路径\n"); 
        printf("3.查找任意两个景点之间的最短路径\n"); 
        printf("4.修改景点信息\n"); 
        printf("5.增加景点信息\n"); 
        printf("6.删除景点信息\n"); 
        printf("7.增加道路\n"); 
        printf("8.删除道路\n"); 
        printf("9.退出管理系统\n"); 
        scanf("%d",&choose);
        switch (choose) {
            case 1:
            	system("cls");
            	printf("来我给您讲讲：\n");
                introduct();
                break;
            case 2:
            	system("cls");
            	printf("地杰斯特拉算法\n");
                Dijkstra();
                break;
            case 3:
            	system("cls");
            	printf("弗洛伊德算法\n");
                Floyd();
                break;
            case 4:
            	system("cls");
            	printf("哪错了？给你改：\n");
                modifyInfo();
                break;
            case 5:
            	system("cls");
            	printf("再多写两句介绍\n");
                addInfo();
                break;
            case 6:
            	system("cls");
            	printf("写错了，删了吧\n");
                delInfo();
                break;
            case 7:
            	system("cls");
            	printf("河大又修路了\n");
                addPath();
                break;
            case 8:
            	system("cls");
            	printf("又修路不让走了？\n");
                delPath();
                break;
            case 9:
            	system("cls");
            	printf("再见~~~\n");
                return;
            default:
            	system("cls");
                printf("老哥输错了，要不您再试试？\n");
                break;
        }
    }
	return;
}
//景点介绍
void introduct(void){
	return;
}
//查找游客所在景点与其他景点的距离
void Dijkstra(void){
	return;
}
//查找游客指定的两个景点间的最短路径长度
void Floyd(void){
	return;
}
//修改景点信息
void modifyInfo(void){
	return;
}
//添加景点
void addInfo(void){
	return;
}
//删除景点
void delInfo(void){
	return;
}
//添加道路
void addPath(void){
	return;
}
//删除道路
void delPath(void){
	return;
}
//生成图
void create(void){
	return;
}



