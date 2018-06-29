#include "stdafx.h"
#include "System.h"


// 게임 로직

System::System()
	: gameOver(false), exit(false),nScreenIndex(0)
{}

void System::Init()
{
	CreateBuffer(80, 30);
	g_scene->AddScene(sTitle, new Title());
	g_scene->Activate(sTitle);
}

void System::Update()
{
	g_scene->Update();
}

void System::Render()
{
	ClearBuffer();
	g_scene->Render();
	FilpBuffer();
}

void System::Quit()
{
	DeleteBuffer();
	g_scene->PurgeInstance();
	g_system->PurgeInstance();
}

#pragma region DoubleBuffering
void System::CreateBuffer(short width, short height)
{
	srWidth = width;
	srHeight = height;

	CONSOLE_CURSOR_INFO cci;
	COORD size = { srWidth, srHeight };
	SMALL_RECT rect;

	rect.Left = 0;
	rect.Top = 0;
	rect.Right = srWidth - 1;
	rect.Bottom = srHeight - 1;

	hBuffer[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[0], size);
	SetConsoleWindowInfo(hBuffer[0], TRUE, &rect);

	hBuffer[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleScreenBufferSize(hBuffer[1], size);
	SetConsoleWindowInfo(hBuffer[1], TRUE, &rect);

	cci.dwSize = 1;
	cci.dwSize = FALSE;
	SetConsoleCursorInfo(hBuffer[0], &cci);
	SetConsoleCursorInfo(hBuffer[1], &cci);
}

void System::WriteBuffer(short x, short y, const char str[])
{
	COORD CursorPosition = { x, y };
	DWORD dw;
	SetConsoleCursorPosition(hBuffer[nScreenIndex], CursorPosition);
	WriteFile(hBuffer[nScreenIndex], str, strlen(str), &dw, NULL);
}

void System::FilpBuffer()
{
	SetConsoleActiveScreenBuffer(hBuffer[nScreenIndex]);
	nScreenIndex = !nScreenIndex;
}

void System::ClearBuffer()
{
	COORD Coor = { 0,0 };
	DWORD dw;
	FillConsoleOutputCharacter(hBuffer[nScreenIndex], ' ', srWidth * srHeight , Coor, &dw);
}

void System::DeleteBuffer()
{
	CloseHandle(hBuffer[0]);
	CloseHandle(hBuffer[1]);
}
#pragma endregion