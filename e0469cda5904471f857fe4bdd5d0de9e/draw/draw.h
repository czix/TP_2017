#pragma once

#include <vector>
#include <queue>
#include "resource.h"

#define MAX_LOADSTRING 100
#define TMR_1 1

#define ID_BUTTON12 102
#define ID_BUTTON13 103
#define ID_BUTTON14 114
#define ID_BUTTON15 115

#define ID_BUTTON21 201
#define ID_BUTTON23 203
#define ID_BUTTON24 204
#define ID_BUTTON25 205

#define ID_BUTTON31 301
#define ID_BUTTON32 302
#define ID_BUTTON34 304
#define ID_BUTTON35 305

#define ID_BUTTON41 401
#define ID_BUTTON42 402
#define ID_BUTTON43 403
#define ID_BUTTON45 405

#define ID_BUTTON51 501
#define ID_BUTTON52 502
#define ID_BUTTON53 503
#define ID_BUTTON54 504

const int human_H = 50;				//wysokoœæ cz³owieka
const int human_W = 20;				//szerokoœæ cz³owieka
const int max_on_floor = 6;			//maksymalna liczba osób na piêtrze


void rysuj_szablon(HDC hdc);
void create_human(int x, int y, HWND hWnd);
void ustaw(int i, HWND hWnd);
void up_and_down(HWND hWnd);