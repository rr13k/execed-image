
#include "stdafx.h"
#include "baseMethod.h"
#include <shellapi.h>
#include  "resource.h"

using namespace std;
#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) // ������ڵ�ַ
int main()
{
	wchar_t rcName[6] = L"kele";  // define image resources type /����rc�����ͣ�����Դ�в鿴
	wchar_t* _rcName = rcName;
	int _length;  //  define leng/ ����rcImg �ĳ���
	LPVOID  imgBuffer;  // define image /���� rcImg�ռ�
	readRcImg(IDR_KELE1, _rcName, &_length, &imgBuffer); // read image resources /��ȡͼƬ��Դ�ļ�

	char ourFilePath[20] = "d:\\windowInit.jpg"; //out file path/�����·��
	char* _ourFilePath = ourFilePath;

	int _dwSize = (int)_length;
	SaveFiletoD(&imgBuffer, _ourFilePath,&_dwSize); // exec image our /ִ��ͼƬ���
	ShellExecute(NULL, (LPCWSTR)L"open", (LPCWSTR)L"d:\\windowInit.jpg",NULL, NULL, SW_SHOWNORMAL); // open image/��ͼƬ 

	//write your code��

	////example
	//char cmd[20] = "shutdown -s -t "; //�ػ�ָ��
	//system(strcat(cmd, "100"));  //�ػ���ʱʱ��/s

	return 0;
}