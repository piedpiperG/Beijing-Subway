#include<iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include <sstream>    //使用istringstream所需要的头文件 
#include <cassert>
#include<queue>
#include<vector>
#include<time.h>
#include<graphics.h>
#include<conio.h>
#include<easyx.h>
#include<windows.h>
#include<mmsystem.h>
#include <unordered_map>
using	namespace std;
/*采用邻接表作为存储结构
	构建站点Station和道路Road两种结构体*/
	//站点结构体如下:
int	Stationnum = 356;
int insistnum = 352;
struct Stations
{
	string name;	//站点名称
	string belongs[20];//所属线路（换乘站的话属于多条线路）
	Stations* nextStaion;//指向下一站的指针（换乘站可能有多个下一站）
}station[500];
Stations emptystation;

//计算最少换乘用图
vector<vector<int>>Map(Stationnum, vector<int>(Stationnum));

//道路结构体如下:
int	Roadnum = 800;
int staynum = 796;
struct Roads
{
	bool ifuse = true;
	string	from;	//从哪里来
	string	to;		//到哪里去
	string  belong;	//所属线路
	double	distance;	//道路长度
	double	equaltime;	//所用时间
}road[5000];

int	Sublinenum = 30;
//记录各条线路速度
struct Sublines
{
	string	name;
	int		speed;
}subline[35];

//记录搜索时的方式
struct pos
{
	string	Loc;	//所在位置
	int	Distance;//行程距离
	int	Changetime;//换乘次数
	int	Costtime;//花费时间
	vector<string>Rember;//记录途径地点
};

//存储结果的结构体
struct Outans
{
	vector<string>disans;	//最短路程结果数组
	vector<string>timans;	//最短时间结果数组
	int	Odistance;			//最短路程距离
	int distime;			//最短路程时间
	double Otime;			//最短时间时间
	int timdist;			//最短时间距离
	int	Dcostmoney;			//最短路程花费
	int Tcostmoney;			//最短时间花费
}outans, outans2;




//初始化邻接表和道路
void	readfile1();
//初始化各个线路的速度和时间
void	readfile2();
//寻找到车站的编号
int findStation(string str);
//寻找到道路的编号
int	findRoad(string start, string end);
//构建邻接表，插入结点
void insertStation(int start, int end);
//打印邻接表
void print1();
//打印道路
void print2();
//深搜给出解决方案
void bfs(string start, string end);
//最短路径搜索
void dijkstra(string start, string end);
//最短时间搜索
void dijkstra2(string start, string end);
//最少换乘搜索
void dijkstra3(string start, string end);
//最短路函数种搜索距离最小点函数
int	Ddismin(vector<int>arr, vector<int>brr);
int	Ddismin2(vector<double>arr, vector<int>brr);
//返回线路对应的速度
double	findspeed(string str);
//返回道路所属的线路
string findbelong(string start, string end);
//最少换乘路线
void dfs(string start, string end);
//easyx按键
void button(int x, int y, int w, int h, TCHAR* text);
//展示优先路程路径
void display();
//展示优先时间路径
void display2();
//展示最少换乘路径
void display3();
//计算里程花费的钱
int calculatemoney(double n);
//弹出错误
bool showerror(string name);
//停用站点
void forbiddenstation(string name);
//停用线路
void forbiddenroad(string name);
//初始化Map
void initMap();
//添加线路
void insertroad(string start, string end, string length);
