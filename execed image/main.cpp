
#include "stdafx.h"
#include "baseMethod.h"
#include <shellapi.h>
#include  "resource.h"

using namespace std;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // 设置入口地址
int main()
{
	wchar_t rcName[6] = L"kele";  // define image resources type /定义rc的类型，在资源中查看
	wchar_t* _rcName = rcName;
	int _length;  //  define leng/ 定义rcImg 的长度
	LPVOID  imgBuffer;  // define image /声明 rcImg空间
	readRcImg(IDR_KELE1, _rcName, &_length, &imgBuffer); // read image resources /读取图片资源文件

	char ourFilePath[20] = "d:\\windowInit.jpg"; //out file path/输出的路径
	char* _ourFilePath = ourFilePath;

	int _dwSize = (int)_length;
	SaveFiletoD(&imgBuffer, _ourFilePath,&_dwSize); // exec image our /执行图片输出
	ShellExecute(NULL, (LPCWSTR)L"open", (LPCWSTR)L"d:\\windowInit.jpg",NULL, NULL, SW_SHOWNORMAL); // open image/打开图片 

	//write your code！

	////example
	//char cmd[20] = "shutdown -s -t "; //关机指令
	//system(strcat(cmd, "100"));  //关机延时时间/s

	return 0;
}