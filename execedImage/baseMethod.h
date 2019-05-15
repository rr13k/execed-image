#include<iostream>
#include  "resource.h"
using namespace std;
/*  ����ͼƬ��ָ��·�� */
//void SaveFiletoD(char* ImgBuffer, char ourFilePath[], int* length) {
//	FILE* fp;  //ͼƬָ��
//	if ((fp = fopen(ourFilePath, "wb+")) == NULL)
//	{
//		cout << "Open File failed!" << endl;
//		exit(0);
//	}
//	//��buffer��д���ݵ�fpָ����ļ���
//	fwrite(ImgBuffer, *length, 1, fp);
//	//�ر��ļ�ָ�룬�ͷ�buffer�ڴ�
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
	FILE* fp;  //ͼƬָ��
	if ((fp = fopen(ourFilePath, "wb+")) == NULL)
	{
		cout << "Open File failed!" << endl;
		exit(0);
	}
	//��buffer��д���ݵ�fpָ����ļ���
	if (*length == fwrite(*ImgBuffer,sizeof(char), *length, fp)) {
		cout << "write ok!" << endl;
	}
	//�ر��ļ�ָ�룬�ͷ�buffer�ڴ�
	fclose(fp);
	//free(ImgBuffer);
}
