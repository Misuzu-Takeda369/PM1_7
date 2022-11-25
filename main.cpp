#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

const char kWindowTitle[] = "GC1A_05_ウブカタ_コトハ_GC1A_15_タケダ_ミスズ";

typedef struct Vector2 {
	float x;
	float y;
};

typedef struct Object {
	Vector2 pos;
	Vector2 speed;
	Vector2 acs;
	float radish;
	int color;
};

float easeInSine(float x) {
	return 1 - cosf((x * M_PI) / 2);
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	const int playerNum = 4;
	Object Player[playerNum]{
		{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},50.0f,RED},//普通
		{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},50.0f,RED},
		{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},50.0f,RED},
		{{0.0f,0.0f},{0.0f,0.0f},{0.0f,0.0f},50.0f,RED}
	};

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		Player[0].pos.x = Player[0].speed.x;

		easeInSine(Player[1].pos.x);


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
