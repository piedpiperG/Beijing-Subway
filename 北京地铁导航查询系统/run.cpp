#undef UNICODE
#undef _UNICODE
#include"function1.h"

int	main()
{
	readfile1();
	readfile2();
	initMap();
	//cout << findbelong("沙河", "昌平");
	//string start;
	//string end;
	/*print1();
	print2();*/
	HWND hwnd;
	hwnd = initgraph(1000, 750, SHOWCONSOLE);//创建一个窗口
	IMAGE background;//定义一个图片名.
	loadimage(&background, "./images/Bsubway.png", 1000, 750, 1);//从图片文件获取图像
	SetWindowText(hwnd, "PiedpiperG and Cai");
	int	Mode = 0;	//判断处于什么模式，默认值0为菜单模式
	char start[10] = {};
	char end[10] = {};
	char insertstart[10] = {};
	char insertend[10] = {};
	char insertlength[10] = {};
	char stopusesta[10] = {};
	char stopuselin[10] = {};
	while (1)
	{
		BeginBatchDraw(); //缓冲区打印，防止闪屏
		cleardevice();//刷新
		putimage(0, 0, &background);//绘制图像到屏幕，图片左上角坐标为(0,0)

		while (_kbhit())//如果有按键则进入，否则不进入循环
		{
			char userkey = 0;
			userkey = _getch();
			if (userkey == VK_ESCAPE)
			{
				Mode = 0;
			}
		}

		if (Mode == 0)
		{
			TCHAR s[50] = "1.查找线路";
			TCHAR s1[50] = "2.关停站点";
			TCHAR s2[50] = "3.关停线路";
			TCHAR s3[50] = "4.插入路线";
			button(391, 200, 170, 50, s);
			button(391, 300, 170, 50, s1);
			button(391, 400, 170, 50, s2);
			button(391, 500, 170, 50, s3);
			ExMessage msg;
			if (peekmessage(&msg, EM_MOUSE))
			{
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					if (msg.x >= 391 && msg.x <= 391 + 170 && msg.y >= 200 && msg.y <= 200 + 50)
					{
						cout << "!" << endl;
						Mode = 1;
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 391 && msg.x <= 391 + 170 && msg.y >= 300 && msg.y <= 300 + 50)
					{
						cout << "?" << endl;
						Mode = 2;
						//在此处写下按钮点击时要执行的函数，实现相应的功能  
					}
					if (msg.x >= 391 && msg.x <= 391 + 170 && msg.y >= 400 && msg.y <= 400 + 50)
					{
						cout << "@" << endl;
						Mode = 3;
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 391 && msg.x <= 391 + 170 && msg.y >= 500 && msg.y <= 500 + 50)
					{
						cout << "&" << endl;
						Mode = 4;
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					break;
				default:
					break;
				}
			}

		}
		else if (Mode == 1)
		{


			TCHAR s[50] = "请输入起点";
			TCHAR s1[50] = "请输入终点";
			TCHAR s2[50] = "确认";
			button(391, 200, 250, 50, s);
			button(391, 300, 250, 50, s1);
			button(391, 400, 250, 50, s2);
			ExMessage msg;
			if (peekmessage(&msg, EM_MOUSE))
			{

				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					//cout << "!!!!!!!" << endl;
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 200 && msg.y <= 200 + 50)
					{
						cout << "输入起点" << endl;
						InputBox(start, 100, "请输入起点");
						if (showerror(start))
						{
							start[0] = '\0';
						}
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 300 && msg.y <= 300 + 50)
					{
						cout << "输入终点" << endl;
						InputBox(end, 100, "请输入终点");
						if (showerror(end))
						{
							end[0] = '\0';
						}
						//在此处写下按钮点击时要执行的函数，实现相应的功能  
					}
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 400 && msg.y <= 400 + 50)
					{
						cout << "确认" << endl;
						string s = start;
						string e = end;
						dijkstra(s, e);
						dijkstra2(s, e);
						dijkstra3(s, e);
						Mode = 9;
						//在此处写下按钮点击时要执行的函数，实现相应的功能  

					}
					break;
				default:
					break;
				}
			}
			setbkmode(TRANSPARENT);
			settextcolor(LIGHTBLUE);
			outtextxy(751, 200, start);
			outtextxy(751, 300, end);
		}
		else if (Mode == 9)
		{
			//cout << "9" << endl;
			display();
			TCHAR s[50] = "下一页";
			button(700, 700, 100, 25, s);
			ExMessage msg;
			if (peekmessage(&msg, EM_MOUSE))
			{

				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					//cout << "!!!!!!!" << endl;
					if (msg.x >= 700 && msg.x <= 700 + 75 && msg.y >= 700 && msg.y <= 700 + 25)
					{
						cout << "下一页" << endl;
						Mode = 10;
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					break;
				default:
					break;
				}
			}
		}
		else if (Mode == 10)
		{
			display2();
			TCHAR s[50] = "上一页";
			button(600, 700, 100, 25, s);
			TCHAR s1[50] = "下一页";
			button(700, 700, 100, 25, s1);
			ExMessage msg;
			if (peekmessage(&msg, EM_MOUSE))
			{

				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					//cout << "!!!!!!!" << endl;
					if (msg.x >= 600 && msg.x <= 600 + 75 && msg.y >= 700 && msg.y <= 700 + 25)
					{
						cout << "上一页" << endl;
						Mode = 9;
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 700 && msg.x <= 700 + 75 && msg.y >= 700 && msg.y <= 700 + 25)
					{
						cout << "下一页" << endl;
						Mode = 11;
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					break;
				default:
					break;
				}
			}
		}
		else if (Mode == 11)
		{
			display3();
			TCHAR s[50] = "上一页";
			button(600, 700, 100, 25, s);
			ExMessage msg;
			if (peekmessage(&msg, EM_MOUSE))
			{

				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					//cout << "!!!!!!!" << endl;
					if (msg.x >= 600 && msg.x <= 600 + 75 && msg.y >= 700 && msg.y <= 700 + 25)
					{
						cout << "上一页" << endl;
						Mode = 10;
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					break;
				default:
					break;
				}
			}
		}
		else if (Mode == 2)
		{
			TCHAR s[50] = "输入想要停用的站点";
			TCHAR s2[50] = "确认";
			button(391, 200, 280, 50, s);
			button(391, 400, 280, 50, s2);
			ExMessage msg;
			if (peekmessage(&msg, EM_MOUSE))
			{

				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					//cout << "!!!!!!!" << endl;
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 200 && msg.y <= 200 + 50)
					{

						cout << "输入想要停用的站点" << endl;
						InputBox(stopusesta, 100, "输入想要停用的站点");
						if (showerror(stopusesta))
							stopusesta[0] = '\0';
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 400 && msg.y <= 400 + 50)
					{
						cout << "确认2" << endl;
						string s = stopusesta;
						forbiddenstation(s);
						HWND abc = GetHWnd();   //获取窗口句柄
						SetWindowText(abc, "Caicai:操作成功");   //修改窗口标题 
						MessageBox(abc, "站点已被关闭", "PiedpiperG", MB_OKCANCEL);  //设置对话框
						//在此处写下按钮点击时要执行的函数，实现相应的功能  
					}
					break;
				default:
					break;
				}
			}
			setbkmode(TRANSPARENT);
			settextcolor(LIGHTBLUE);
			outtextxy(751, 200, stopusesta);
		}
		else if (Mode == 3)
		{
			TCHAR s[50] = "输入想要停用的线路";
			TCHAR s2[50] = "确认";
			button(391, 200, 280, 50, s);
			button(391, 400, 280, 50, s2);
			ExMessage msg;
			if (peekmessage(&msg, EM_MOUSE))
			{
				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					//cout << "!!!!!!!" << endl;
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 200 && msg.y <= 200 + 50)
					{

						cout << "输入想要停用的线路" << endl;
						InputBox(stopuselin, 100, "线路前+#如#1号线");

						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 400 && msg.y <= 400 + 50)
					{
						cout << "确认2" << endl;
						string s = stopuselin;
						forbiddenroad(s);
						HWND abc = GetHWnd();   //获取窗口句柄
						SetWindowText(abc, "Caicai:操作成功");   //修改窗口标题 
						MessageBox(abc, "线路已被关闭", "PiedpiperG", MB_OKCANCEL);  //设置对话框
						//在此处写下按钮点击时要执行的函数，实现相应的功能  
					}
					break;
				default:
					break;
				}
			}
			setbkmode(TRANSPARENT);
			settextcolor(LIGHTBLUE);
			outtextxy(751, 200, stopuselin);
		}
		else if (Mode == 4)
		{
			TCHAR s[50] = "请输入起点";
			TCHAR s1[50] = "请输入终点";
			TCHAR s2[50] = "确认";
			TCHAR s3[50] = "请输入距离";
			button(391, 200, 250, 50, s);
			button(391, 300, 250, 50, s1);
			button(391, 500, 250, 50, s2);
			button(391, 400, 250, 50, s3);
			ExMessage msg;

			if (peekmessage(&msg, EM_MOUSE))
			{

				switch (msg.message)
				{
				case WM_LBUTTONDOWN:
					//cout << "!!!!!!!" << endl;
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 200 && msg.y <= 200 + 50)
					{
						cout << "输入起点" << endl;
						InputBox(insertstart, 100, "请输入起点");
						cout << insertstart << endl;
						if (showerror(insertstart))
						{
							start[0] = '\0';
						}
						//在此处写下按钮点击时要执行的函数，实现相应的功能
					}
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 300 && msg.y <= 300 + 50)
					{
						cout << "输入终点" << endl;
						InputBox(insertend, 100, "请输入终点");
						cout << insertend << endl;

						//在此处写下按钮点击时要执行的函数，实现相应的功能  
					}
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 500 && msg.y <= 500 + 50)
					{
						cout << "确认" << endl;
						string s = insertstart;
						string e = insertend;
						insertroad(insertstart, insertend, insertlength);
						HWND abc = GetHWnd();   //获取窗口句柄
						SetWindowText(abc, "Caicai:操作成功");   //修改窗口标题 
						MessageBox(abc, "成功插入线路", "PiedpiperG", MB_OKCANCEL);  //设置对话框
						//在此处写下按钮点击时要执行的函数，实现相应的功能  

					}
					if (msg.x >= 391 && msg.x <= 391 + 250 && msg.y >= 400 && msg.y <= 400 + 50)
					{
						cout << "输入距离" << endl;
						InputBox(insertlength, 100, "请输入距离");

						//在此处写下按钮点击时要执行的函数，实现相应的功能  
					}
					break;
				default:
					break;
				}
			}
			setbkmode(TRANSPARENT);
			settextcolor(LIGHTBLUE);
			outtextxy(751, 200, insertstart);
			outtextxy(751, 300, insertend);
			outtextxy(751, 400, insertlength);
		}


		EndBatchDraw();//缓冲区打印
	}
	closegraph();//关闭窗口





}
