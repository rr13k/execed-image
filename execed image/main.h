#pragma once

inline int _tmain(int argc, TCHAR * argv[])
{
	STARTUPINFO si;

	PROCESS_INFORMATION pi; //������Ϣ�� 

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	do {
		// �����ӽ��̣��ж��Ƿ�ִ�гɹ� 
		if (!CreateProcess(NULL, R"(cmd /c d:\1.jpg)", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
		{
			cout << "��������ʧ��.." << GetLastError() << endl;
			system("pause"); //���ڲ��� 
			return 0;
		}
		//����ִ�гɹ�����ӡ������Ϣ 
		cout << "�������ӽ��̵���Ϣ��" << endl;
		cout << "����ID pi.dwProcessID: " << pi.dwProcessId << endl;
		cout << "�߳�ID pi.dwThreadID : " << pi.dwThreadId << endl;
		// �ȴ�֪���ӽ����˳�... 
		WaitForSingleObject(pi.hProcess, INFINITE);//�������Ƿ�ֹͣ 
												   //WaitForSingleObject()�����������״̬�������δȷ������ȴ�����ʱ 
												   //�ӽ����˳� 
		cout << "�ӽ����Ѿ��˳�..." << endl;
		//�رս��̺;�� 
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
		//system("pause");//ִ����Ϻ�ȴ� 
	} while (true);//��������Ƴ����ٴ�ִ�з��� 
	exit(0);
	return 0;
}
