#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE);
	SetGraphMode(1, 1, 32);
	SetChangeScreenModeGraphicsSystemResetFlag(FALSE);
	if (DxLib_Init() == -1) return -1;


	const int a = LoadGraph("1.png", TRUE);
	int a_x{}, a_y{};
	GetGraphSize(a, &a_x, &a_y);

	const int screen = MakeScreen(a_x * 2, a_y, TRUE);
	SetDrawScreen(screen);
	ClearDrawScreen();

	//•`‰æ
	const int init_x = a_x / 2;
	DrawExtendGraph(init_x + a_x + a_x, 0, init_x + a_x, a_y, a, TRUE);
	DrawExtendGraph(init_x, 0, -init_x, a_y, a, TRUE);
	DrawExtendGraph(init_x, 0, init_x + a_x, a_y, a, TRUE);

	const int screen2 = MakeScreen(a_x * 2, a_y * 2, TRUE);
	SetDrawScreen(screen2);
	ClearDrawScreen();

	//•`‰æ
	const int init_y = a_y / 2;
	DrawExtendGraph(0, init_y + a_y + a_y, a_x*2, init_y + a_y, screen, TRUE);
	DrawExtendGraph(0, init_y, a_x*2, -init_y, screen, TRUE);
	DrawExtendGraph(0, init_y, a_x*2, init_y + a_y, screen, TRUE);
	DeleteGraph(screen);

	const int screen3 = MakeScreen(a_x, a_y, TRUE);
	SetDrawScreen(screen3);
	ClearDrawScreen();

	DrawExtendGraph(0, 0, a_x, a_y, screen2, TRUE);
	DeleteGraph(screen2);

	SaveDrawScreenToPNG(0, 0, a_x, a_y, "0.png", 0);
	SaveDrawScreenToJPEG(0, 0, a_x, a_y, "0.jpg", 100, TRUE);

	DxLib_End();
	return 0;
}
