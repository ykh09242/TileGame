#pragma once

class System
	: public Singleton<System>
{
public:
	System();

private:
	HANDLE hBuffer[2];
	int nScreenIndex;

public:
	short srWidth;
	short srHeight;
	bool gameOver;
	bool exit;

public:
	void Init();
	void Update();
	void Render();
	void Quit();
	void WriteText(short x, short y, const char str[]);

private:
	void CreateBuffer(short width, short height);
	void FilpBuffer();
	void ClearBuffer();
	void DeleteBuffer();
};

