// 1228dc3a29494c568700de7dc7e2bc32.cpp: Okre�la punkt wej�cia dla aplikacji.
//

#include "stdafx.h"
#include "1228dc3a29494c568700de7dc7e2bc32.h"

#define MAX_LOADSTRING 100

const int SPEED_X = 1;
const int SPEED_Y = 1;


//rope position
struct position
{
	int x = 292;
	int y = 350;
};
struct chest
{
	int x;
	int y = 370;
	bool CheckTheHook = false;
	int waga = 100;
};
position rope;
chest object;

// Global variables
HINSTANCE hInst;                                // bie��ce wyst�pienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytu�u
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna g��wnego
HWND randomizeweight;

// Przeka� dalej deklaracje funkcji do��czonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//METHODS:
void GetImage(HDC, HWND);
void DrawTheRope(HWND);
void ClearTheRope(HWND);
void DrawTheObject(HWND);
void ClearTheObject(HWND);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

	//Inicjalizacja GDI+
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    // TODO: W tym miejscu umie�� kod.
	srand(time(NULL));
    // Zainicjuj ci�gi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY1228DC3A29494C568700DE7DC7E2BC32, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjacje aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY1228DC3A29494C568700DE7DC7E2BC32));

    MSG msg;

    // G��wna p�tla wiadomo�ci:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

	GdiplusShutdown(gdiplusToken);
    return (int) msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  CEL: Rejestruje klas� okna.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY1228DC3A29494C568700DE7DC7E2BC32));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY1228DC3A29494C568700DE7DC7E2BC32);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   CEL: Zapisuje doj�cie wyst�pienia i tworzy okno g��wne
//
//   KOMENTARZE:
//
//        W tej funkcji doj�cie wyst�pienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wy�wietlane okno g��wne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Przechowuj doj�cie wyst�pienia w zmiennej globalnej

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
	   0, 0, 900, 550, nullptr, nullptr, hInstance, nullptr);
   
   randomizeweight = CreateWindowEx(0, L"BUTTON", L"LOSUJ WAGE", WS_CHILD | WS_VISIBLE, 740, 100, 100, 30, hWnd, NULL, hInstance, NULL);

   object.x = 292 + rand() % (700 - 292 + 1);
   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNKCJA: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  CEL: Przetwarza wiadomo�ci dla okna g��wnego.
//
//  WM_COMMAND � przetwarzaj menu aplikacji
//  WM_PAINT � pomaluj okno g��wne
//  WM_DESTROY � opublikuj komunikat o rezygnacji i wr��
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
	case WM_KEYDOWN:
	{
		switch ((int)wParam)
		{
		case VK_RIGHT:
			if (rope.x <= 710) {
				ClearTheRope(hWnd);
				rope.x += SPEED_X;
				DrawTheRope(hWnd);
				if (object.CheckTheHook)
				{
					ClearTheObject(hWnd);
					object.x += SPEED_X;
					DrawTheObject(hWnd);
				}

			}
			break;
		case VK_LEFT:
			if (rope.x >= 292) {
				ClearTheRope(hWnd);
				rope.x -= SPEED_X;
				DrawTheRope(hWnd);
				if (object.CheckTheHook)
				{
					ClearTheObject(hWnd);
					object.x -= SPEED_X;
					DrawTheObject(hWnd);
				}
			}

			break;
		case VK_UP:
			if (rope.y >= 148) {
				ClearTheRope(hWnd);
				rope.y -= SPEED_Y;
				DrawTheRope(hWnd);
				if (object.CheckTheHook)
				{
					ClearTheObject(hWnd);
					object.y -= SPEED_Y;
					DrawTheObject(hWnd);
				}
			}
			break;
		case VK_DOWN:
			if (rope.y < 370) {
				ClearTheRope(hWnd);
				rope.y += SPEED_Y;
				DrawTheRope(hWnd);
				if (object.CheckTheHook)
				{
					ClearTheObject(hWnd);
					object.y += SPEED_Y;
					DrawTheObject(hWnd);
				}
			}
			break;
		case VK_SPACE:


			if ((rope.x == object.x) && (rope.y == object.y)) {
				if (object.waga >= 300) {
					MessageBox(hWnd, L"Nie uda�o sie podniesc, za ciezki towar...", L"Nieudana proba podniesienia.", MB_OK);
				}
				else object.CheckTheHook = true;
			}
			break;
		case 0x5A:
			if ((rope.x == object.x) && (rope.y == object.y))
			{
				object.CheckTheHook = false;
				while (object.y < 370) {
					ClearTheObject(hWnd);
					object.y += SPEED_Y;
					DrawTheObject(hWnd);
					Sleep(1);
				}
			}
			break;
		}
	}
	break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizuj zaznaczenia menu:
			
			if ((HWND)lParam == randomizeweight) {
				object.waga = 1 + rand() % (400);
				wchar_t buffer[256];
				wsprintfW(buffer, L"%d", object.waga);
				MessageBox(hWnd, buffer, L"Zmieniasz wage.", MB_OK);

			}
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: tutaj dodaj kod rysowania u�ywaj�cy elementu hdc...
			GetImage(hdc, hWnd);
			DrawTheRope(hWnd);
			DrawTheObject(hWnd);			
			EndPaint(hWnd, &ps);


        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

//Procedura obs�ugi wiadomo�ci dla okna informacji o programie.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}



void GetImage(HDC hdc, HWND hwnd)
{
	HBITMAP hbmImage;
	BITMAP bmInfo;
	hbmImage = (HBITMAP)LoadImage(NULL, L"dzwig.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	HDC hdcNew = CreateCompatibleDC(NULL);
	HBITMAP hbmOld = (HBITMAP)SelectObject(hdcNew, hbmImage);
	GetObject(hbmImage, sizeof(bmInfo), &bmInfo);
	hdc = GetDC(hwnd);
	BitBlt(hdc, 50, 50, bmInfo.bmWidth, bmInfo.bmHeight, hdcNew, 0, 0, SRCCOPY);
	ReleaseDC(hwnd, hdc);

	DeleteObject(hbmImage); 
	SelectObject(hdcNew, hbmOld);
	DeleteDC(hdcNew);
}
void DrawTheRope(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 0));
	graphics.DrawLine(&pen, rope.x, 127, rope.x, rope.y);
	ReleaseDC(hWnd, hdc);
}

void ClearTheRope(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, rope.x, 127, rope.x, rope.y);
	ReleaseDC(hWnd, hdc);
}

void DrawTheObject(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 0));
	graphics.DrawLine(&pen, object.x - 15, object.y, object.x + 15, object.y);
	graphics.DrawLine(&pen, object.x - 15, object.y, object.x - 15, object.y + 60);
	graphics.DrawLine(&pen, object.x + 15, object.y, object.x + 15, object.y + 60);
	graphics.DrawLine(&pen, object.x - 15, object.y + 60, object.x + 15, object.y + 60);
	graphics.DrawLine(&pen, object.x - 15, object.y, object.x + 15, object.y + 60);
	graphics.DrawLine(&pen, object.x + 15, object.y, object.x - 15, object.y + 60);

	ReleaseDC(hWnd, hdc);
}

void ClearTheObject(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, object.x - 15, object.y, object.x + 15, object.y);
	graphics.DrawLine(&pen, object.x - 15, object.y, object.x - 15, object.y + 60);
	graphics.DrawLine(&pen, object.x + 15, object.y, object.x + 15, object.y + 60);
	graphics.DrawLine(&pen, object.x - 15, object.y + 60, object.x + 15, object.y + 60);
	graphics.DrawLine(&pen, object.x - 15, object.y, object.x + 15, object.y + 60);
	graphics.DrawLine(&pen, object.x + 15, object.y, object.x - 15, object.y + 60);

	ReleaseDC(hWnd, hdc);
}