// Projekt4TP.cpp: Okreœla punkt wejœcia dla aplikacji.
//

#include "stdafx.h"
#include "Projekt4TP.h"


#define MAX_LOADSTRING 100

// Zmienne globalne:
HINSTANCE hInst;                                // bie¿¹ce wyst¹pienie
WCHAR szTitle[MAX_LOADSTRING];                  // Tekst paska tytu³u
WCHAR szWindowClass[MAX_LOADSTRING];            // nazwa klasy okna g³ównego

// Przeka¿ dalej deklaracje funkcji do³¹czonych w tym module kodu:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

void MyOnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 155, 0));
	graphics.DrawLine(&pen, 300, 100, 300, 600);
	graphics.DrawLine(&pen, 250, 100, 250, 600);
	graphics.DrawLine(&pen, 0, 600, 1400, 600);
	graphics.DrawLine(&pen, 50, 100, 1000, 100);
	graphics.DrawLine(&pen, 50, 100, 50, 70);
	graphics.DrawLine(&pen, 50, 70, 950, 70);
	graphics.DrawLine(&pen, 950, 70, 1000, 100);
	graphics.DrawLine(&pen, 250, 70, 250, 30);
	graphics.DrawLine(&pen, 300, 70, 300, 30);
	graphics.DrawLine(&pen, 250, 30, 300, 30);
	graphics.DrawLine(&pen, 50, 70, 250, 30);
	graphics.DrawLine(&pen, 300, 30, 500, 70);
	graphics.DrawLine(&pen, 300, 30, 700, 70);
	graphics.DrawLine(&pen, 300, 550, 250, 550);
	graphics.DrawLine(&pen, 300, 500, 250, 500);
	graphics.DrawLine(&pen, 300, 450, 250, 450);
	graphics.DrawLine(&pen, 300, 400, 250, 400);
	graphics.DrawLine(&pen, 300, 350, 250, 350);
	graphics.DrawLine(&pen, 300, 300, 250, 300);
	graphics.DrawLine(&pen, 300, 250, 250, 250);
	graphics.DrawLine(&pen, 300, 200, 250, 200);
	graphics.DrawLine(&pen, 300, 150, 250, 150);
	graphics.DrawLine(&pen, 50, 100, 100, 70);
	graphics.DrawLine(&pen, 100, 70, 150, 100);
	graphics.DrawLine(&pen, 150, 100, 200, 70);
	graphics.DrawLine(&pen, 200, 70, 250, 100);
	graphics.DrawLine(&pen, 250, 100, 300, 70);
	graphics.DrawLine(&pen, 300, 70, 350, 100);
	graphics.DrawLine(&pen, 350, 100, 400, 70);
	graphics.DrawLine(&pen, 400, 70, 450, 100);
	graphics.DrawLine(&pen, 450, 100, 500, 70);
	graphics.DrawLine(&pen, 500, 70, 550, 100);
	graphics.DrawLine(&pen, 550, 100, 600, 70);
	graphics.DrawLine(&pen, 600, 70, 650, 100);
	graphics.DrawLine(&pen, 650, 100, 700, 70);
	graphics.DrawLine(&pen, 700, 70, 750, 100);
	graphics.DrawLine(&pen, 750, 100, 800, 70);
	graphics.DrawLine(&pen, 800, 70, 850, 100);
	graphics.DrawLine(&pen, 850, 100, 900, 70);
	graphics.DrawLine(&pen, 900, 70, 950, 100);
	graphics.DrawLine(&pen, 950, 100, 950, 70);

} 

void Podnosnik(HDC hdc, int x1, int y1, int x2, int y2)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	graphics.DrawLine(&pen, x1, y1, x2, y2);
}

void erasePodnosnik(HDC hdc, int x1, int y1, int x2, int y2)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1, y1, x2, y2);	
}

void Paczka(HDC hdc, int x1, int y1)
{
	int y3 = y1 - 50;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 0, 0, 255));
	graphics.DrawLine(&pen, x1, y1, x2, y1);
	graphics.DrawLine(&pen, x1, y3, x2, y3);
	graphics.DrawLine(&pen, x1, y1, x1, y3);
	graphics.DrawLine(&pen, x2, y1, x2, y3);

}

void erasePaczkaPoziom(HDC hdc, int x1, int y1)
{
	int y3 = y1 - 52;
	int x2 = x1 + 50;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	//graphics.DrawLine(&pen, x1, y1, x2, y1);
	//graphics.DrawLine(&pen, x1, y3, x2, y3);
	graphics.DrawLine(&pen, x1-2, y1, x1-2, y3);
	graphics.DrawLine(&pen, x2-2, y1, x2-2, y3);

}

void erasePaczkaPion(HDC hdc, int x1, int y1)
{
	int y3 = y1 - 50;
	int x2 = x1 + 51;
	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 255, 255));
	graphics.DrawLine(&pen, x1-1, y1+2, x2, y1+2);
	graphics.DrawLine(&pen, x1-1, y3+2, x2, y3+2);
	//graphics.DrawLine(&pen, x1 + 2, y1, x1 + 2, y3);
	//graphics.DrawLine(&pen, x2 + 2, y1, x2 + 2, y3);

}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: W tym miejscu umieœæ kod.

    // Zainicjuj ci¹gi globalne
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_PROJEKT4TP, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Wykonaj inicjacje aplikacji:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_PROJEKT4TP));

    MSG msg;

    // G³ówna pêtla wiadomoœci:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNKCJA: MyRegisterClass()
//
//  CEL: Rejestruje klasê okna.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJEKT4TP));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_PROJEKT4TP);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNKCJA: InitInstance(HINSTANCE, int)
//
//   CEL: Zapisuje dojœcie wyst¹pienia i tworzy okno g³ówne
//
//   KOMENTARZE:
//
//        W tej funkcji dojœcie wyst¹pienia jest zapisywane w zmiennej globalnej i
//        jest tworzone i wyœwietlane okno g³ówne programu.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Przechowuj dojœcie wyst¹pienia w zmiennej globalnej

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

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
//  CEL: Przetwarza wiadomoœci dla okna g³ównego.
//
//  WM_COMMAND — przetwarzaj menu aplikacji
//  WM_PAINT — pomaluj okno g³ówne
//  WM_DESTROY — opublikuj komunikat o rezygnacji i wróæ
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Analizuj zaznaczenia menu:
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
            // TODO: tutaj dodaj kod rysowania u¿ywaj¹cy elementu hdc...
			MyOnPaint(hdc);

			int masa = 240;

			while (1) {
				if (GetAsyncKeyState('Q')) {
					break;
				}
			}
			int i = 355;
			int j = 545;
			while (1)
			{
				if (GetAsyncKeyState('D'))
				{
						Podnosnik(hdc, i, 101, i, j + 1);
						erasePodnosnik(hdc, i - 1, 101, i - 1, j + 1);
						Paczka(hdc, i - 25, j + 52);
						erasePaczkaPoziom(hdc, i - 24, j + 53);
						Sleep(10);
						if (i < 951 && masa <= 250) i++;
				}

				if (GetAsyncKeyState('A'))
				{
						Podnosnik(hdc, i, 101, i, j + 1);
						erasePodnosnik(hdc, i + 1, 101, i + 1, j + 1);
						Paczka(hdc, i - 25, j + 52);
						erasePaczkaPoziom(hdc, i - 22, j + 53);
						Sleep(10);
						if (i > 350 && masa <= 250) i--;
				}

				if (GetAsyncKeyState('W'))
				{
						erasePodnosnik(hdc, i, 101, i, j + 1);
						erasePodnosnik(hdc, i + 1, 101, i + 1, j + 1);
						erasePodnosnik(hdc, i - 1, 101, i - 1, j + 1);
						Podnosnik(hdc, i, 101, i, j);
						Paczka(hdc, i - 25, j + 52);
						erasePaczkaPion(hdc, i - 25, j + 51);
						Sleep(10);
						if (j > 105 && masa <= 250) j--;
				}

				if (GetAsyncKeyState('S'))
				{
						erasePodnosnik(hdc, i, 101, i, j);
						erasePodnosnik(hdc, i + 1, 101, i + 1, j);
						erasePodnosnik(hdc, i - 1, 101, i - 1, j);
						Podnosnik(hdc, i, 101, i, j);
						Paczka(hdc, i - 25, j + 52);
						erasePaczkaPion(hdc, i - 25, j + 49);
						Sleep(10);
						if (j < 546 && masa <= 250) j++;
				}

				if (GetAsyncKeyState('T')) break;
							
			}

			
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

//Procedura obs³ugi wiadomoœci dla okna informacji o programie.
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
