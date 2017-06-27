// draw.cpp : Defines the entry point for the application.

#include "stdafx.h"
#include "draw.h"
#include "classes.cpp"


// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];					// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

//MY GLOBAL VARIABLES
std::vector <Human> humans;

Floor FLOOR[5] = {

Floor(0, 220, 575),
Floor(1, 460, 451),
Floor(2, 220, 323),
Floor(3, 460, 203),
Floor(4, 220, 73) };

Winda winda;


void MyOnPaint(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255,128,128,255));
	//graphics.DrawLine(&pen,0,0,200,100);


	graphics.DrawRectangle(&pen, 255, winda.pos_y-125, 190, 125);		//rysowanie windy
}

void rysuj_szablon(HDC hdc)
{
	Graphics graphics(hdc);
	Pen pen(Color(255, 128, 128, 255));

	graphics.DrawRectangle(&pen, 250, 0, 200, 630);									//rysowanie szybu windy
	graphics.DrawRectangle(&pen, 30, FLOOR[0].get_y() + human_H, 220, 5);				//rysowanie platformy pierwszego piêtra
	graphics.DrawRectangle(&pen, 30, FLOOR[2].get_y() + human_H, 220, 5);				//rysowanie platformy trzeciego piêtra
	graphics.DrawRectangle(&pen, 30, FLOOR[4].get_y() + human_H, 220, 5);				//rysowanie platformy pi¹tego piêtra
	graphics.DrawRectangle(&pen, 450, FLOOR[1].get_y() + human_H, 200, 5);			//rysowanie platformy drugiego piêtra
	graphics.DrawRectangle(&pen, 450, FLOOR[3].get_y() + human_H, 200, 5);			//rysowanie platformy czwartego piêtra

}

void create_human(int x, int y, HWND hWnd)
{
	x = x - 1;
	y = y - 1;
	HDC hdc = GetDC(hWnd);

	Human human(x, y);

	FLOOR[x].stop = true;						//musisz zatrzymaæ siê na tym piêtrze aby osoba mog³a wsi¹œæ

	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 0, 0));

	if (FLOOR[x].how < max_on_floor)			//je¿eli na piêtrze jest miejsce na kolejn¹ osobê
	{
		graphics.DrawRectangle(&pen, FLOOR[x].new_x(), FLOOR[x].get_y(), human_W, human_H);			//narysuj t¹ osobê
		human.pos_x = FLOOR[x].new_x();																//zapisz pozycjê tej osoby
		human.pos_y = FLOOR[x].get_y();
		FLOOR[x].how++;																				//na piêtrze jest jedna osoba wiêcej

		humans.push_back(human);																	//zapisz osobê do wektora
	}
}
void up_and_down(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);

	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 0, 0));

	if (winda.pos_y == 123)
		winda.up = false;
	else if (winda.pos_y == 628)
		winda.up = true;

	if (winda.up == true)
		winda.pos_y -= 1;
	else
		winda.pos_y += 1;

	for (std::vector<Human>::iterator it = humans.begin(); it < humans.end(); it++)
	{
		if(it->w_windzie == true)   //je¿eli ta osoba jest w windzie to niech jej wsp_y zmienia siê tak samo jak pozycja windy
			graphics.DrawRectangle(&pen, it->pos_x, winda.pos_y - human_H, human_W, human_H);
	}

	if (FLOOR[0].stop == true || FLOOR[1].stop == true || FLOOR[2].stop == true || FLOOR[3].stop == true || FLOOR[4].stop == true)
	{
			for (int i = 0; i < 5; i++)
			{
				if (winda.pos_y == FLOOR[i].get_y() + human_H)
				{
					if(FLOOR[i].stop == true)
					{
						Sleep(500);

						for (std::vector<Human>::iterator it = humans.begin(); it < humans.end(); it++)
							if (it->finish_floor == i && it->w_windzie == true && it->delate == false)
							{
								it->w_windzie = false;		//ta osoba ju¿ nie jest w windzie
								it->delate = true;			//ta osoba ju¿ nie istnieje
								winda.how--;				//w windzie jest jedna osoba mnniej
							}

						for (std::vector<Human>::iterator it = humans.begin(); it < humans.end(); it++)
							if (it->start_floor == i && it->w_windzie == false && it->delate == false && winda.how < max_on_floor)
							{
								RECT drawArea = { it->pos_x, it->pos_y, it->pos_x + human_W + 1,it->pos_y + human_H + 1 };
								InvalidateRect(hWnd, &drawArea, TRUE);
								
								FLOOR[it->finish_floor].stop = true;		//na tym piêtrze musisz siê zatrzymaæ ¿eby osoba mog³a wysi¹œæ
								it->w_windzie = true;						//ta osoba jest teraz w windzie
								it->pos_x = winda.new_pos();				//zajêcie wolnego miejsca w windzie						
								FLOOR[i].how--;								//na tym piêtrze jest teraz jedna osoba mniej
								winda.how++;								//w windzie jest jedna osoba wiêcej
							}
						
						FLOOR[i].stop = false;		//na tym piêtrze ju¿ nie musisz siê zatrzymywaæ bo wszystko tutaj jest za³atwione
						
						//if(FLOOR[i].how != 0)
							ustaw(i, hWnd);				//odpowiednie przesuniêcie osób w windzie na wolne miejsca(¿eby nie by³o przerw miêdzy nimi)
						Sleep(1);
					}
				}
			}
	}
	else
		winda.pos_y = 628;
}

void ustaw(int i, HWND hWnd)
{
	HDC hdc = GetDC(hWnd);

	Graphics graphics(hdc);
	Pen pen(Color(255, 255, 0, 0));

	winda.how = 0;

	for (std::vector<Human>::iterator it = humans.begin(); it < humans.end(); it++)
	{
		if (it->w_windzie == true)
		{
			it->pos_x = winda.new_pos();
			winda.how++;
		}
	}
	
}

int OnCreate(HWND window)
{
   SetTimer(window, TMR_1, 50, 0);
   return 0;
}

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;


	GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR           gdiplusToken;
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DRAW, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_DRAW));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
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

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_DRAW));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_DRAW);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;
   HWND hWndButton;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 700, 700, NULL, NULL, hInstance, NULL);

   //PRZYCISKI PIÊTRO PIERWSZE

   hWndButton = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 610, 20, 20, hWnd, (HMENU)ID_BUTTON12, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 580, 20, 20, hWnd, (HMENU)ID_BUTTON13, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 550, 20, 20, hWnd, (HMENU)ID_BUTTON14, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 520, 20, 20, hWnd, (HMENU)ID_BUTTON15, hInstance, NULL);

   //PRZYCISKI PIÊTRO TRZECIE

   hWndButton = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 357, 20, 20, hWnd, (HMENU)ID_BUTTON31, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 327, 20, 20, hWnd, (HMENU)ID_BUTTON32, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 297, 20, 20, hWnd, (HMENU)ID_BUTTON34, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 267, 20, 20, hWnd, (HMENU)ID_BUTTON35, hInstance, NULL);

   //PRZYCISKI PIÊTRO PI¥TE

   hWndButton = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 109, 20, 20, hWnd, (HMENU)ID_BUTTON51, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 79, 20, 20, hWnd, (HMENU)ID_BUTTON52, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 49, 20, 20, hWnd, (HMENU)ID_BUTTON53, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   5, 19, 20, 20, hWnd, (HMENU)ID_BUTTON54, hInstance, NULL);

   //PRZYCISKI PIÊTRO DRUGIE

   hWndButton = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   655, 486, 20, 20, hWnd, (HMENU)ID_BUTTON21, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   655, 456, 20, 20, hWnd, (HMENU)ID_BUTTON23, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("4"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   655, 426, 20, 20, hWnd, (HMENU)ID_BUTTON24, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   655, 396, 20, 20, hWnd, (HMENU)ID_BUTTON25, hInstance, NULL);

   //PRZYCISKI PIÊTRO CZWARTE

   hWndButton = CreateWindow(TEXT("button"), TEXT("1"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   655, 238, 20, 20, hWnd, (HMENU)ID_BUTTON41, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("2"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   655, 208, 20, 20, hWnd, (HMENU)ID_BUTTON42, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("3"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   655, 178, 20, 20, hWnd, (HMENU)ID_BUTTON43, hInstance, NULL);

   hWndButton = CreateWindow(TEXT("button"), TEXT("5"), WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
	   655, 148, 20, 20, hWnd, (HMENU)ID_BUTTON45, hInstance, NULL);
   
   OnCreate(hWnd);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	//OnCreate(hWnd,wParam,lParam);
	//OnTimer(hWnd,wParam,lParam);

	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		//przyciski pierwsze piêtro
		case ID_BUTTON12: {
			create_human(1, 2,hWnd);
			break; 
		}
		case ID_BUTTON13: {
			create_human(1, 3, hWnd);
			break; 
		}
		case ID_BUTTON14: {
			create_human(1, 4, hWnd);
			break; 
		}
		case ID_BUTTON15: {
			create_human(1, 5, hWnd);
			break;
		}
		
		//przyciski drugie pietro
		case ID_BUTTON21: {
			create_human(2,1, hWnd);
			break;
		}
		case ID_BUTTON23: {
			create_human(2,3, hWnd);
			break;
		}
		case ID_BUTTON24: {
			create_human(2,4, hWnd);
			break;
		}
		case ID_BUTTON25: {
			create_human(2,5, hWnd);
			break;
		}

		//przyciski trzecie pietro
		case ID_BUTTON31: {
			create_human(3,1, hWnd);
			break;
		}
		case ID_BUTTON32: {
			create_human(3,2, hWnd);
			break;
		}
		case ID_BUTTON34: {
			create_human(3,4, hWnd);
			break;
		}
		case ID_BUTTON35: {
			create_human(3,5, hWnd);
			break;
		}

		//przyciski czwarte pietro
		case ID_BUTTON41: {
			create_human(4,1, hWnd);
			break;
		}
		case ID_BUTTON42: {
			create_human(4,2, hWnd);
			break;
		}
		case ID_BUTTON43: {
			create_human(4,3, hWnd);
			break;
		}
		case ID_BUTTON45: {
			create_human(4,5, hWnd);
			break;
		}

		 //przyciski pi¹te pietro
		case ID_BUTTON51: {
			create_human(5,1, hWnd);
			break;
		}
		case ID_BUTTON52: {
			create_human(5,2, hWnd);
			break;
		}
		case ID_BUTTON53: {
			create_human(5,3, hWnd);
			break;
		}
		case ID_BUTTON54: {
			create_human(5,4, hWnd);
			break;
		}

		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT: {
		hdc = BeginPaint(hWnd, &ps);
		// TODO: Add any drawing code here..

		rysuj_szablon(hdc);

		EndPaint(hWnd, &ps);
		break; }
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	case WM_TIMER:
		switch (wParam)
		{
			case TMR_1:
				//force window to repaint
				RECT drawArea = { 251, 1, 450, 630};
				InvalidateRect(hWnd, &drawArea, TRUE);
				hdc = BeginPaint(hWnd, &ps);

				MyOnPaint(hdc);
				up_and_down(hWnd);

				EndPaint(hWnd, &ps);
			break;
		}

	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
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
