// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <tchar.h>
#include <assert.h>
#include <crtdbg.h>
#include <Windows.h>

using namespace std;

// 매크로
#ifdef _DEBUG
#define new new(_CLIENT_BLOCK,__FILE__, __LINE__)
#endif // _DEBUG

#define SAFE_DELETE(p) { if(p) { delete p; p = nullptr; } }
#define SAFE_DELETE_ARRAY(p) { if(p) { delete[] p; p = nullptr; } }

#define PURE = 0
#define KEYMAX 111

#define delay(n) Sleep(n);
#define randomize() srand((unsigned)time(NULL));
#define random(n) (rand() % (n));

// enum
enum SceneName
{
	sTitle,
	sInGame,
	sOver
};

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#include "Vector.h"

#include "Singleton.h"
#include "System.h"
#include "BaseScene.h"
#include "SceneManager.h"

#include "Title.h"

#define g_system System::GetInstance()
#define g_scene  SceneManager::GetInstance()