#include<iostream>
#include  "resource.h"
using namespace std;
/*  保存图片到指点路径 */
//void SaveFiletoD(char* ImgBuffer, char ourFilePath[], int* length) {
//	FILE* fp;  //图片指针
//	if ((fp = fopen(ourFilePath, "wb+")) == NULL)
//	{
//		cout << "Open File failed!" << endl;
//		exit(0);
//	}
//	//从buffer中写数据到fp指向的文件中
//	fwrite(ImgBuffer, *length, 1, fp);
//	//关闭文件指针，释放buffer内存
//	fclose(fp);
//	free(ImgBuffer);
//}


void readRcImg(int rcId, wchar_t* rcName,int* length, LPVOID* pBuffer) {
	HRSRC hRsrc = ::FindResource(NULL, MAKEINTRESOURCE(rcId), rcName);
	if (NULL == hRsrc)
		return ;
	*length = SizeofResource(NULL, hRsrc);
	if (0 == *length)
		return ;
	HGLOBAL hGlobal = LoadResource(NULL, hRsrc);
	if (NULL == hGlobal)
		return ;

	*pBuffer = LockResource(hGlobal);
	if (NULL == *pBuffer)
		return ;

}


void SaveFiletoD(LPVOID* ImgBuffer, char ourFilePath[], int* length) {
	FILE* fp;  //图片指针
	if ((fp = fopen(ourFilePath, "wb+")) == NULL)
	{
		cout << "Open File failed!" << endl;
		exit(0);
	}
	//从buffer中写数据到fp指向的文件中
	if (*length == fwrite(*ImgBuffer,sizeof(char), *length, fp)) {
		cout << "write ok!" << endl;
	}
	//关闭文件指针，释放buffer内存
	fclose(fp);
	//free(ImgBuffer);
}
