
#include<windows.h>
typedef struct _WNDCLASS {
UINT style;// ��������
WNDPROC lpfnWndProc;//���ڴ�����
int cbClsExtra;//������չ
int cbWndExtra;//����ʵ����չ
HINSTANCE hInstance;//ʵ�����
HICON hIcon;//���ڵ���С��ͼ��
HCURSOR hCursor;//���������
HBRUSH hbrBackground;//���ڱ���ɫ
LPCTSTR lpszMenuName;//���ڲ˵�
LPCTSTR lpszClassName;// ��������
} WNDCLASS, *LPWNDCLASS;
HWND CreateWindowEx(
DWORD DdwExStyle,        //���ڵ���չ���
LPCTSTR lpClassName,    //ָ��ע��������ָ��
LPCTSTR lpWindowName,   //ָ�򴰿����Ƶ�ָ��
DWORD dwStyle,          //���ڷ��
int x,                  //���ڵ�ˮƽλ��
int y,                  //���ڵĴ�ֱλ��
int nWidth,             //���ڵĿ��
int nHeight,            //���ڵĸ߶�
HWND hWndParent,        //�����ڵľ��
HMENU hMenu,            //�˵��ľ�������Ӵ��ڵı�ʶ��
HINSTANCE hInstance,    //Ӧ�ó���ʵ���ľ��
LPVOID lpParam          //ָ�򴰿ڵĴ�������
);
 typedef struct tagMSG {
  HWND hwnd;
  UINT message;
  WPARAM wParam;
  LPARAM lParam;
  DWORD time;
  POINT pt;
 } MSG;
/*GetMessage��
LPMSG lpMsg,//ָ��MSG�ṹ��ָ�룬�ýṹ���̵߳���Ϣ�����������Ϣ��Ϣ
HWND hWnd,//ȡ������Ϣ�Ĵ��ڵľ��������ֵȡNULLʱ��GetMessageΪ�κ����ڵ����̵߳Ĵ��ڼ�����Ϣ���߳���Ϣͨ��PostThreadMessage���͸������̡߳�
UINT wMsgFilterMin,//ָ������������С��Ϣֵ����������ʡ��
UINT wMsgFilterMax//ָ���������������Ϣֵ����������ʡ��
)
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
HINSTANCE hinhwnd = 0;
HWND editor = 0;*/
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR pCmdLine, int nCmdeShow)
{
	const wchar_t CLASS_NAME[] = L"test";//����
	WNDCLASS wc = {};
	wc.style = 0;//ȱʡ
	wc.cbClsExtra = 0;//ȱʡ
	wc.cbWndExtra = 0;//ȱʡ
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);//ȱʡ
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);//��ͷ���
	wc.hbrBackground = (HBRUSH)(GetStockObject(WHITE_BRUSH));//��ɫˢ��
	wc.lpszMenuName = NULL;//�޲˵�
	wc.lpfnWndProc = WindowProc;//��Ϣ������
	hinhwnd=wc.hInstance = hInstance;
	wc.lpszClassName = CLASS_NAME;
	
	RegisterClass(&wc);
	HWND hwnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"test",//����
		WS_OVERLAPPEDWINDOW,//һ����
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,//Ĭ��λ�ü��ߴ�
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (hwnd == NULL)
		return 0;
	ShowWindow(hwnd,1);
	MSG msg = {};
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	return 0;
}
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		EndPaint(hwnd, &ps);

	}
	return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
