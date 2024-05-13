#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

struct worker{
	char id[100];
	char name[100];
	char gender[100];
	int age;
	char degree[100];
	int delv;
	int wage;
	char add[100];
	char tel[100];
	int lv;
	char label[100];
}workers[10005];
//构建职工信息结构体
char clv[4][100]={"","经理","主管","职工"};	
//用于表示各职位
char de[5][100]={"","博士","硕士","本科","专科"};
int checklv(char c[])
{
	for(int i=1;i<=4;i++)
	{
		if(!strcmp(de[i],c))
		{
			return i;
		}
	}
	return 0;
}
//该函数作用在于判断职位类型workers[i].lv
//将职工字符串表示转化为lv(int型)方便后续根据职位排序查询
int checkde(char c[])
{
	for(int i=1;i<=3;i++)
	{
		if(!strcmp(clv[i],c))
		{
			return i;
		}
	}
	return 0;
}
void CreateMenu(int n)
{
	printf("——————职工管理系统——————\n");
	printf("     1.职工信息录入\n");
	printf("     2.职工信息浏览\n");
	printf("     3.查询职工信息\n");
	printf("     4.职工信息修改\n");
	printf("     5.职工信息删除\n");
	printf("——————按0退出操作————————\n");
}
//制作菜单栏，每次执行完功能后都需要使用到
void putInfo(int n)
{
	int t;
	char temp[100];
	printf("请输入职工号：");
	scanf("%s",workers[n].id);
	printf("请输入姓名：");
	scanf("%s",workers[n].name);
	printf("请输入性别：");
	scanf("%s",workers[n].gender);
	printf("请输入年龄：");
	scanf("%d",&t);
	workers[n].age = t;
	printf("请输入学历：");
	scanf("%s",workers[n].degree);
	workers[n].delv = checkde(workers[n].degree);
	printf("请输入工资：");
	scanf("%d",&t);
	workers[n].wage = t;
	printf("请输入职位：");
	scanf("%s",workers[n].label);
	workers[n].lv = checklv(workers[n].label);
	printf("请输入住址：");
	scanf("%s",workers[n].add);
	printf("请输入电话：");
	scanf("%s",workers[n].tel);
	printf("\n\n");
	CreateMenu(1);
}
//功能1：输入职工信息
int getlen(int num)
{	
	int len = 0;
	for(int i=num;i>=1;i/=10)
		len++;
	return len;
}
//get the length of num(int)
int len[10]={0,16,9,11,9,9,10,9,14,18};
//set the length of each elements in blank
//用于格式化输出的表格
void show(int n)
{
	if(n==0){
		printf("暂时还没有职工！\n");
		CreateMenu(1);
		return;
	}
	int sum = 0;
	for(int i=1;i<=9;i++)
		sum += len[i];
	for(int i=1;i<=sum;i++)
		printf("-");
	printf("\n");
	printf("|    职工号    |  姓名  |   性别   |  年龄  |  学历  |   工资  |  职位  |     住址    |       电话      |\n");
	printf("|");
		for(int i=2;i<sum;i++)
			printf("-");
		printf("|\n");
	for(int i=1;i<=n;i++)
	{
		printf("|%s",workers[i].id);
		for(int j=strlen(workers[i].id)+1;j<15;j++)
			printf(" ");
		printf("|%s",workers[i].name);
		for(int j=strlen(workers[i].name)+1;j<9;j++)
			printf(" ");
		printf("|%s",workers[i].gender);
		for(int j=strlen(workers[i].gender)+1;j<11;j++)
			printf(" ");
		printf("|%d",workers[i].age);
		for(int j=getlen(workers[i].age)+1;j<9;j++)
			printf(" ");
		printf("|%s",workers[i].degree);
		for(int j=strlen(workers[i].degree)+1;j<9;j++)
			printf(" ");
		printf("|%d",workers[i].wage);
		for(int j=getlen(workers[i].wage)+1;j<10;j++)
			printf(" ");
		printf("|%s",workers[i].label);
		for(int j=strlen(workers[i].label)+1;j<9;j++)
			printf(" ");
		printf("|%s",workers[i].add);
		for(int j=strlen(workers[i].add)+1;j<14;j++)
			printf(" ");
		printf("|%s",workers[i].tel);
		for(int j=strlen(workers[i].tel)+1;j<18;j++)
			printf(" ");
		printf("|\n");
	//	printf("%d\n",workers[i].lv);	//测试checklv函数是否起作用
		if(i!=n){
			printf("|");
			for(int i=2;i<sum;i++)
				printf("-");
			printf("|\n");
		}
	}
	for(int i=1;i<=sum;i++)
		printf("-");
	printf("\n");
	CreateMenu(1);
}
//功能2：职工信息浏览功能 －－输出
void find_and_sort(int n)
{
	printf("请输入")
}
void change_wage(int n)
{
	printf("请选择修改方式：\n");
	printf("1.按职工号修改\n2.按职称等级修改\n");
	int choice;
	scanf("%d",&choice);
	if(choice==1)	//按单个职工的工资变动修改
	{
		printf("请输入职工号：");
		char ID[100];
		scanf("%s",ID);
		int p=0;
		for(int i=1;i<=n;i++)
		{
			if(!strcmp(workers[i].id,ID))
			{
				p=i;
				printf("查找成功，请输入其工资变动：");	
				int w;
				scanf("%d",&w);
				workers[p].wage+=w;
				printf("修改完成！\n");
				CreateMenu(1);
				break;
			}
		}
		if(!p)
		{
			printf("查无此人！\n");
			CreateMenu(1);
		}
		return;
	}
	if(choice == 2)	//按级别的全体职工的工资变动
	{
		printf("请输入要调整工资的职称：");
		char Lab[100];
		scanf("%s",Lab);
		printf("请输入其工资变动：");	
		int w;
		scanf("%d",&w);
		int L = checklv(Lab);
		for(int i=1;i<=n;i++)
		{
			if(workers[i].lv == L)
				workers[i].wage += w;
		}
		printf("修改完成！\n");
		CreateMenu(1);
		return;
	}
}
//功能4：职工信息修改功能
int delete_info(int n)
{
	char ID[100];
	printf("请输入职工ID：");
	scanf("%s",ID);
	int p=1,k=n;
	for(int i=1;i<=n;i++)
	{
		if(!strcmp(ID,workers[i].id))
		{
			p=0;
			for(int j=i+1;j<=n;j++)
			{
				workers[j-1]=workers[j];
			}
			printf("\n删除成功！\n");
			CreateMenu(1);
			k--;
		}
	}
	if(p)
	{
		printf("\n不存在此人\n");
		CreateMenu(1);
	}
	return k;
}
//功能5：删除员工信息函数
int main(){
	int n;                    
	CreateMenu(1);
	int num = 0;
	while(scanf("%d",&n))
	{
		if(n==0)
		{
			printf("操作完毕，退出操作系统！\n");
			break;
		}
		if(n<0||n>5){
			printf("输入有误，请重新输入！\n");
			continue;
		}
		if(n==1)
		{
			num++;
			putInfo(num);
			continue;
		}
		if(n==2)
		{
			show(num);
		}
		if(n==4)
		{
			change_wage(num);
		}
		if(n==5)
		{
			if(!num)	
			{
				printf("暂时还没有职工！\n");
				CreateMenu(1);
				continue;
			}
			//特例：还没有员工的情况下（即num==0）可立刻退出进入下一轮循环。
			num = delete_info(num);		//使用int型函数，若存在要删除的人num--，否则num不变
			//printf("%d",num);
		}
	}
	return 0;
}