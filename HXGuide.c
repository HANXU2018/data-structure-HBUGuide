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
	system("cls");
	printf("HBU景点列表:\n");
	int i;
	for(i = 0;i<HBUmap.n;i++)
        printf("%d : %s\n",i+1,HBUmap.vexs[i].name);
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
	if(HBUmap.n <= 0)
    {
        printf("这是个假学校，没有任何景点~\n");
        return;
    }
    showInfo();
    printf("你要看那个说号:");
    int a;
    scanf("%d",&a);
    system("cls");
    while(a<1 || a>HBUmap.n)
    {
        printf("这都输错了1到%d之间，重新输！\n",HBUmap.n);
        scanf("%d",&a);
    }
    printf("%s:%s\n",HBUmap.vexs[a-1].name,HBUmap.vexs[a-1].features);
    Sleep(1000);
	printf("即将1S后返回主界面\n"); 
	Sleep(1000);
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
	if(HBUmap.n <= 0)
    {
        printf("这是一个虚假的学校，竟然没有任何景点\n");
        return;
    }
    showInfo();
    int a;
    printf("你说哪里要改？说编号：\n");
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("编号输错了，从1开始到%d，你再试试别的\n",HBUmap.n);
        scanf("%d",&a);
    }
    char newName[100];
    char newFeatures[1000];
    printf("这里原来叫%s,你要把他换成啥？：\n",HBUmap.vexs[a-1].name);
    scanf("%s",newName);getchar();
    printf("简介现在是：\n%s\n你说改成啥？：\n",HBUmap.vexs[a-1].features);
    scanf("%s",newFeatures);getchar();
    printf("正在修改...\n");
    strcpy(HBUmap.vexs[a-1].name, newName);
    strcpy(HBUmap.vexs[a-1].features, newFeatures);
    long long int i=0;
	for(i = 0;i<DELAY ;i++);
    printf("行了改好了\n");
    printf("要还改就输入1，输别的就退出了\n");
    int flag;
    scanf("%d",&flag);
    if(flag == True)
        modifyInfo();
	return;
}
//添加景点
void addInfo(void){
	
	if(HBUmap.n >= MaxVerNum)
    {
        printf("河大已经满了不能再加了\n");
        return;
    }
    showInfo();
    char newName[100];char newFeatures[500];
    printf("新加的这个景儿叫啥？：\n");
    scanf("%s",newName);getchar();
    printf("%s有啥特点？\n",newName);
    scanf("%s",newFeatures);getchar();
    showInfo();
    int m;
    printf("它旁边有几个景点？\n");
    scanf("%d",&m);
    int i ;
	for(i= 0;i<m;i++)
    {
        int a,distance;
        printf("输一下%s的第%d个相连的景点的编号:\n",newName,i+1);
        scanf("%d",&a);
        while(a<1 || a>HBUmap.n || HBUmap.edges[a-1][HBUmap.n] != INFINITY)
        {
            if(a<1 || a>HBUmap.n)
            {
                printf("输错了，编号在1到%d之间，重新输！\n",HBUmap.n);
                scanf("%d",&a);
            }
            if(HBUmap.edges[a-1][HBUmap.n] != INFINITY)
            {
                printf("老哥，这个已经有了，重新输\n");
                scanf("%d",&a);
            }
        }
        printf("%s与%s之间的距离是多少？:\n",newName,HBUmap.vexs[a-1].name);
        scanf("%d",&distance);
        while(distance <=0 || distance>INFINITY)
        {
            printf("距离输入非法了重新输入！\n");
            scanf("%d",&distance);
        }
        HBUmap.edges[a-1][HBUmap.n] = HBUmap.edges[HBUmap.n][a-1] = distance;
    }
    printf("正在添加景点...\n");
    strcpy(HBUmap.vexs[HBUmap.n++].name,newName);
    strcpy(HBUmap.vexs[HBUmap.n-1].features,newFeatures);
    HBUmap.e += m;
    
	for(i= 0;i<DELAY ;i++);
    printf("这个景点添加成功了！\n");
    printf("还要加就输入1，输入其他字符就退出\n");
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
        addInfo();
	return;
}
//删除景点
void delInfo(void){
	if(HBUmap.n <= 0)
    {
        printf("已经删没了，不能再删除！\n");
        return;
    }
    showInfo();
    printf("您要删除哪个景点？\n");
    int a;
    scanf("%d",&a);
    while(a<1 || a>HBUmap.n)
    {
        printf("%d,个你都输错了，重新输入！\n",HBUmap.n);
        scanf("%d",&a);
    }
    printf("删除的景点为：%s真的要删吗？ 输入1 for sure： \n",HBUmap.vexs[a-1].name);
    int flag;
    scanf("%d",&flag);
    if(flag == 1)
    {
        printf("删除景点ING\n");
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
    printf("已经删完了\n，1s后回到主界面");
    Sleep(1000); 
	return;
}
//添加道路
void addPath(void){
	if(HBUmap.n <= 0)
    {
        printf("世界上本没有路，走的人多了就有了路，现在还没有路呢~\n");
        return;
    }
    showInfo();
    if(HBUmap.e == 0)
        printf("错误：目前暂无道路\n");
    else
        printf("目前总共有%d条道路\n",HBUmap.e);
    printf("请输入道路起点和终点：\n");
    int a,b;
    scanf("%d %d",&a,&b);
    while(a<1 || a>HBUmap.n || b<1 || b>HBUmap.n || a == b)
    {
        if(a == b)
            printf("输错了吧，这俩咋一样呢？！\n");
        else
            printf("编号输入有误，最大是%d，重新输\n",HBUmap.n);
        scanf("%d %d",&a,&b);
    }
    if(HBUmap.edges[a-1][b-1] != INFINITY){
        printf("%s与%s之间这条路已经有了，不要再添加！\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        return;
    }
    else
    {
        int distance;
        printf("请输入%s与%s之间道路的长度：\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        scanf("%d",&distance);
        while(distance <=0 || distance >= INFINITY)
        {
            printf("这个长度有问题\n");
            scanf("%d",&distance);
        }
        printf("正在添加道路...\n");
        HBUmap.edges[a-1][b-1] = HBUmap.edges[b-1][a-1] = distance;
        HBUmap.e++;
        long long i;
        for(i = 0;i<DELAY ;i++);
        printf("道路添加成功！\n");
        printf("1s后回到主界面");
    Sleep(1000); 
    }
	return;
}
//删除道路
void delPath(void){
	if(HBUmap.n <= 0)
    {
        printf("无任何景点，请先添加\n");
        return;
    }
    if(HBUmap.e <= 0)
    {
        printf("地图中无任何道路，请先添加！\n");
        return;
    }
    showInfo();
    printf("目前总共有%d条道路\n",HBUmap.e);
    printf("请输入要删除道路的两个景点编号，中间用空格隔开：\n");
    int a,b;
    scanf("%d %d",&a,&b);
    while(a<1 || a>HBUmap.n || b<1 || b>HBUmap.n || a == b)
    {
        if(a == b)
            printf("请勿输入两个相同编号，重新输入！\n");
        else
            printf("编号输入有误，两个编号都应位于1～%d之间，重新输入！\n",HBUmap.n);
        scanf("%d %d",&a,&b);
    }
    if(HBUmap.edges[a-1][b-1] == INFINITY)
    {
        printf("%s与%s之间无道路！\n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        return;
    }
    else
    {
        printf("您要删除的是%s与%s的道路,确认输入1 \n",HBUmap.vexs[a-1].name,HBUmap.vexs[b-1].name);
        int flag;
        scanf("%d",&flag);
        if(flag == 1)
        {
            printf("正在删除道路...\n");
            HBUmap.edges[a-1][b-1] = HBUmap.edges[b-1][a-1] = INFINITY;
            HBUmap.e--;
            long long i;
            for(i = 0;i<DELAY ;i++);
            printf("道路删除成功！\n");
        }
        else
            return;
        	printf("1s后回到主界面");
    		Sleep(1000); 
    }
    return ; 
}
//生成图
void create(void){
	HBUmap.n = 12;//12个景点 
    HBUmap.e = 20;//20条路 
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
    strcpy(HBUmap.vexs[0].name, "操场");
    strcpy(HBUmap.vexs[0].features, "跑一千米的好地方");
    strcpy(HBUmap.vexs[1].name, "图书馆");
    strcpy(HBUmap.vexs[1].features, "进入需要使用学生卡，微信公众号预约");
    strcpy(HBUmap.vexs[2].name, "体检中心");
    strcpy(HBUmap.vexs[2].features, "谁能告诉我这个是干啥的？");
    strcpy(HBUmap.vexs[3].name, "校门北口");
    strcpy(HBUmap.vexs[3].features, "这个口不外卖进不来，开学的时候哈罗也不让进。");
    strcpy(HBUmap.vexs[4].name, "银杏景观");
    strcpy(HBUmap.vexs[4].features, "大妈的乐园，情侣的天堂");
    strcpy(HBUmap.vexs[5].name, "邯郸音乐厅");
    strcpy(HBUmap.vexs[5].features, "一个团委举办大会的地方");
    strcpy(HBUmap.vexs[6].name, "餐厅");
    strcpy(HBUmap.vexs[6].features, "三层餐厅，想吃的差不多都有");
    strcpy(HBUmap.vexs[7].name, "花园景观");
    strcpy(HBUmap.vexs[7].features, "没有看到花，没有看到景");
    strcpy(HBUmap.vexs[8].name, "校门东口");
    strcpy(HBUmap.vexs[8].features, "从中间这个口出去，全是发小广告的。");
    strcpy(HBUmap.vexs[9].name, "信息学部");
    strcpy(HBUmap.vexs[9].features, "这个地儿很神秘，从没去过。");
    strcpy(HBUmap.vexs[10].name, "网计学院");
    strcpy(HBUmap.vexs[10].features, "C1，网络空间安全与计算机学院");
    strcpy(HBUmap.vexs[11].name, "校门南口");
    strcpy(HBUmap.vexs[11].features, "学校正宗的大门口");
    //添加边权 
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



