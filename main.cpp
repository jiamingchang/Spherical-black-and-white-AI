#include<iostream>
using namespace std;

#define NONE 0
#define BLACK 1
#define WHITE 2

int*c1 = new int[9];int*c2 = new int[9];int*c3 = new int[9];
int*c4 = new int[9];int*c5 = new int[9];int*c6 = new int[9];

int loc[25] = { 0 };
int result = 0;
int down = 0;
int* findpoint = new int[3];

// loc in c
int cc[7][9]{
	{0},
	{0,1,2,3,4,5,6,7,8},
	{0,9,10,11,12,13,14,15,16},
	{0,1,9,17,21,14,6,24,20},
	{0,2,10,18,22,13,5,23,19},
	{0,20,19,3,11,18,17,16,8},
	{0,24,23,4,12,22,21,15,7},
};

// loc to c
void newc() {
	c1[1] = loc[1];  c1[2] = loc[2];  c1[3] = loc[3];  c1[4] = loc[4];  c1[5] = loc[5];  c1[6] = loc[6];  c1[7] = loc[7];  c1[8] = loc[8];
	c2[1] = loc[9];  c2[2] = loc[10]; c2[3] = loc[11]; c2[4] = loc[12]; c2[5] = loc[13]; c2[6] = loc[14]; c2[7] = loc[15]; c2[8] = loc[16];
	c3[1] = loc[1];  c3[2] = loc[9];  c3[3] = loc[17]; c3[4] = loc[21]; c3[5] = loc[14]; c3[6] = loc[6];  c3[7] = loc[24]; c3[8] = loc[20];
	c4[1] = loc[2];  c4[2] = loc[10]; c4[3] = loc[18]; c4[4] = loc[22]; c4[5] = loc[13]; c4[6] = loc[5];  c4[7] = loc[23]; c4[8] = loc[19];
	c5[1] = loc[20]; c5[2] = loc[19]; c5[3] = loc[3];  c5[4] = loc[11]; c5[5] = loc[18]; c5[6] = loc[17]; c5[7] = loc[16]; c5[8] = loc[8];
	c6[1] = loc[24]; c6[2] = loc[23]; c6[3] = loc[4];  c6[4] = loc[12]; c6[5] = loc[22]; c6[6] = loc[21]; c6[7] = loc[15]; c6[8] = loc[7];
}
// c to loc
void newloc(int a) {
	if (a == 1) {
		loc[1] = c1[1];  loc[2] = c1[2];  loc[3] = c1[3];  loc[4] = c1[4];  loc[5] = c1[5];   loc[6] = c1[6];   loc[7] = c1[7];   loc[8] = c1[8];
	}
	else if (a == 2) {
		loc[9] = c2[1];  loc[10] = c2[2]; loc[11] = c2[3]; loc[12] = c2[4]; loc[13] = c2[5];  loc[14] = c2[6];  loc[15] = c2[7];  loc[16] = c2[8];
	}
	else if (a == 3) {
		loc[1] = c3[1];  loc[9] = c3[2];  loc[17] = c3[3]; loc[21] = c3[4]; loc[14] = c3[5];  loc[6] = c3[6];   loc[24] = c3[7];  loc[20] = c3[8];
	}
	else if (a == 4) {
		loc[2] = c4[1];  loc[10] = c4[2]; loc[18] = c4[3]; loc[22] = c4[4]; loc[13] = c4[5];  loc[5] = c4[6];   loc[23] = c4[7];  loc[19] = c4[8];
	}
	else if (a == 5) {
		loc[20] = c5[1]; loc[19] = c5[2]; loc[3] = c5[3];  loc[11] = c5[4]; loc[18] = c5[5];  loc[17] = c5[6];  loc[16] = c5[7];  loc[8] = c5[8];
	}
	else if (a == 6) {
		loc[24] = c6[1]; loc[23] = c6[2]; loc[4] = c6[3];  loc[12] = c6[4]; loc[22] = c6[5];  loc[21] = c6[6];  loc[15] = c6[7];  loc[7] = c6[8];
	}
}

// 输出棋盘
void output() {
	cout << "    " << loc[17] << ' ' << loc[21] << ' ' << endl;
	cout << "    " << loc[18] << ' ' << loc[22] << ' ' << endl;
	for (int i = 9; i <= 16; i++) {
		cout << loc[i] << ' ';
	}cout << endl;
	for (int i = 1; i <= 8; i++) {
		cout << loc[i] << ' ';
	}cout << endl;
	cout << "    " << loc[19] << ' ' << loc[23] << ' ' << endl;
	cout << "    " << loc[20] << ' ' << loc[24] << ' ' << endl;
}

// 下棋规则
void rule() {
	cout << "-----游戏规则如下-----" << endl;
	cout << "0:空  1:黑棋  2:白棋" << endl;
	cout << "请按照如下位置下棋" << endl;
	cout << "     17 21" << endl;
	cout << "     18 22" << endl;
	for (int i = 1; i <= 8; i++) {
		cout << cc[2][i] << " ";
	}cout << endl;
	for (int i = 1; i <= 8; i++) {
		cout << cc[1][i] << "  ";
	}cout << endl;
	cout << "     19 23" << endl;
	cout << "     20 24" << endl;
	cout << endl << "----------------------" << endl << endl;
}

// 开始游戏
void newGame() {
	loc[3] = WHITE;loc[12] = WHITE;loc[4] = BLACK;loc[11] = BLACK;
	newc();
	output();
}

// 返回点所在的两条线及其位置
int* inwhere(int a) {
	int *t = new int[4];
	int temp = 0;
	for (int i = 1; i <= 6; i++) {
		for (int j = 1; j <= 8; j++) {
			if (cc[i][j] == a) {
				t[temp] = i;
				t[temp + 1] = j;
				temp += 2;
			}
			if (temp == 4) { break; }
		}
		if (temp == 4) { break; }
	}
	return t;
}

// 返回两条线的重复点loc
int* findrepeat(int* t) {
	int* a = new int[3];
	for (int i = 1; i < 3; i++) {
		a[i] = 0;
	}
	int k = 1;
	for (int i = 1; i <= 8; i++) {
		for (int j = 1; j <= 8; j++) {
			if (cc[t[0]][i] == cc[t[2]][j]) {
				a[k] = cc[t[2]][j];
				k++;
			}
		}
	}
	return a;
}

// 判断对局是否结束
bool finish() {
	int sum = 0;
	int sum1 = 0, sum2 = 0;
	// 棋盘已满或全为一方棋子,对局结束
	for (int i = 1; i <= 24; i++) {
		if (loc[i] == NONE) {
			sum++;
		}
		if (loc[i] == BLACK) {
			sum1++;
		}
		if (loc[i] == WHITE) {
			sum2++;
		}
	}
	if (sum == 0) { return true; }
	if (sum1 == 0 || sum2 == 0) { return true; }
	return false;
}

// 判断谁赢了
void whowin() {
	int sum1 = 0, sum2 = 0;
	for (int i = 1; i <= 24; i++) {
		if (loc[i] == BLACK) {
			sum1++;
		}
		if (loc[i] == WHITE) {
			sum2++;
		}
	}
	if (sum1 > sum2) { cout << "黑棋胜利！！！" << endl; }
	else if (sum1 < sum2) { cout << "白棋胜利！！！" << endl; }
	else
	{
		cout << "平局！！！" << endl;
	}
}

// 判断能否翻转
int ifturn(int flag, int sum, int *t, int color, int*a) {
	int yes = 0;
	if(flag == 1 && sum == 0) {
		yes++;
	}
	else if (sum > 0) {
		int temp1 = t[1] + 1; if (temp1 == 9) { temp1 = 1; }
		int temp2 = t[1] - 1; if (temp2 == 0) { temp2 = 8; }
		for (int i = temp2;; i--) {
			if (i == 0) { i = 8; }
			if (a[i] == 0) {
				break;
			}
			if (a[i] == color) {
				if (i == temp2) { break; }
				yes++;
				break;
			}
		}
		for (int i = temp1;; i++) {
			if (i == 9) { i = 1; }
			if (a[i] == 0) {
				break;
			}
			if (a[i] == color) {
				if (i == temp1) { break; }
				yes++;
				break;
			}
		}
	}
	if (yes > 0) { return 1; }
	return 0;
}
// 找到能下的点
int findcan(int a,int color) {
	if (a < 1 || a>24) { return false; }
	if (loc[a] != 0) { return false; }
	int *t = new int[4];
	t = inwhere(a);
	int *a1 = NULL, *a2 = NULL;
	switch (t[0])
	{
	case 1:	a1 = c1; break; case 2:	a1 = c2; break; case 3:	a1 = c3; break;
	case 4:	a1 = c4; break; case 5:	a1 = c5; break; case 6:	a1 = c6; break;
	}
	switch (t[2])
	{
	case 1:	a2 = c1; break; case 2:	a2 = c2; break; case 3:	a2 = c3; break;
	case 4:	a2 = c4; break; case 5:	a2 = c5; break; case 6:	a2 = c6; break;
	}

	findpoint = findrepeat(t);

	// 限制下棋的位置
	// 判断能否翻转,如果能,则翻转
	int flag1 = 0;
	for (int i = 1; i <= 8; i++) {
		if (a1[i] == 0) {
			flag1++;
		}
	}
	int sum1 = 0;
	for (int i = 1; i <= 8; i++) {
		if (a1[i] == color) {
			sum1++;
		}
	}
	int flag2 = 0;
	for (int i = 1; i <= 8; i++) {
		if (a2[i] == 0) {
			flag2++;
		}
	}
	int sum2 = 0;
	for (int i = 1; i <= 8; i++) {
		if (a2[i] == color) {
			sum2++;
		}
	}

	result = 0;
	down = 0;
	if (flag1 == 0 && flag2 == 0) {
		return false;
	}

	int *t1 = new int[2]; int *t2 = new int[2];
	t1[0] = t[0]; t1[1] = t[1];
	t2[0] = t[2]; t2[1] = t[3];

	int yes1 = ifturn(flag1, sum1, t1, color, a1);
	int yes2 = ifturn(flag2, sum2, t2, color, a2);
	if (yes1 == 0 && yes2 == 0) {
		return 0;
	}
	return a;
}
// 找到所有能下的点
int* findallcan(int color) {
	int *allcan = new int[25];
	for (int i = 1; i <= 24; i++) {
		allcan[i] = 0;
	}
	int k = 1;
	for (int a = 1; a <= 24; a++) {
		if (findcan(a, color) != 0) {
			allcan[k] = findcan(a, color);
			k++;
		}
	}
	return allcan;
}

// 判断并翻转
int* canturn(int flag, int sum, int *t, int color, int*a) {
	int* repeat = new int[3];   // 记录翻转的重复点loc
	for (int i = 1; i < 3; i++) {
		repeat[i] = 0;
	}
	int k = 1;
	if (flag == 1 && sum == 0) {
		for (int i = 1; i <= 8; i++) {
			a[i] = color;
			for (int j = 1; j < 3; j++) {
				if (cc[t[0]][i] == findpoint[j]) {
					repeat[k] = cc[t[0]][i];
					k++;
				}
			}
		}
		result++;
	}
	else if (sum > 0) {
		int temp1 = t[1] + 1; if (temp1 == 9) { temp1 = 1; }
		int temp2 = t[1] - 1; if (temp2 == 0) { temp2 = 8; }

		int yes1 = 0;
		int loc1 = 0;
		// 判断能否翻转
		for (int i = temp2;; i--) {
			if (i == 0) { i = 8; }
			if (a[i] == 0) {
				break;
			}
			if (a[i] == color) {
				if (i == temp2) { break; }
				yes1 = 1;
				loc1 = i;
				break;
			}
		}
		// 翻转
		if (yes1 == 1) {
			for (int i = temp2;; i--) {
				if (i == 0) { i = 8; }
				if (i != loc1) {
					a[i] = color;
					for (int j = 1; j < 3; j++) {
						if (cc[t[0]][i] == findpoint[j]) {
							repeat[k] = cc[t[0]][i];
							k++;
						}
					}
				}
				else { break; }
			}
			result++;
		}
		else { down++; }

		yes1 = 0;
		loc1 = 0;
		// 判断能否翻转
		for (int i = temp1;; i++) {
			if (i == 9) { i = 1; }
			if (a[i] == 0) {
				break;
			}
			if (a[i] == color) {
				if (i == temp1) { break; }
				yes1 = 1;
				loc1 = i;
				break;
			}
		}
		// 翻转
		if (yes1 == 1) {
			for (int i = temp1;; i++) {
				if (i == 9) { i = 1; }
				if (i != loc1) {
					a[i] = color;
					for (int j = 1; j < 3; j++) {
						if (cc[t[0]][i] == findpoint[j]) {
							repeat[k] = cc[t[0]][i];
							k++;
						}
					}
				}
				else { break; }
			}
			result++;
		}
		else { down++; }
	}
	else
	{
		down++;
	}
	return repeat;
}
// 下棋并翻转
bool canput(int a,int color) {
	if (a < 1 || a>24) { return false; }
	if (loc[a] != 0) { return false; }
	int *t = new int[4];
	t = inwhere(a);
	int *a1=NULL, *a2=NULL;
	switch (t[0])
	{
	case 1:	a1 = c1; break; case 2:	a1 = c2; break; case 3:	a1 = c3; break;
	case 4:	a1 = c4; break; case 5:	a1 = c5; break; case 6:	a1 = c6; break;
	}
	switch (t[2])
	{
	case 1:	a2 = c1; break; case 2:	a2 = c2; break; case 3:	a2 = c3; break;
	case 4:	a2 = c4; break; case 5:	a2 = c5; break; case 6:	a2 = c6; break;
	}
	
	findpoint = findrepeat(t);

	// 限制下棋的位置
	// 判断能否翻转,如果能,则翻转
	int flag1 = 0;
	for (int i = 1; i <= 8; i++) {
		if (a1[i] == 0) {
			flag1++;
		}
	}
	int sum1 = 0;
	for (int i = 1; i <= 8; i++) {
		if (a1[i] == color) {
			sum1++;
		}
	}
	int flag2 = 0;
	for (int i = 1; i <= 8; i++) {
		if (a2[i] == 0) {
			flag2++;
		}
	}
	int sum2 = 0;
	for (int i = 1; i <= 8; i++) {
		if (a2[i] == color) {
			sum2++;
		}
	}
	
	result = 0;
	down = 0;
	if (flag1 == 0 && flag2 == 0) {
		return false;
	}

	int *t1 = new int[2];int *t2 = new int[2];
	t1[0] = t[0]; t1[1] = t[1];
	t2[0] = t[2]; t2[1] = t[3];

	int* repeat1 = new int[3];int* repeat2 = new int[3];
	for (int i = 1; i <= 2; i++) { repeat1[i] = 0; }
	for (int i = 1; i <= 2; i++) { repeat2[i] = 0; }
	repeat1 = canturn(flag1, sum1, t1, color, a1);
	repeat2 = canturn(flag2, sum2, t2, color, a2);

	if (result > 0) {
		// 刷新(同步)棋盘
		newloc(t[0]);
		newloc(t[2]);
		newc();
		// 同步重复点(防止异步同步时被覆盖)
		for (int i = 1; repeat1[i] != 0&&i<=2; i++) {
			loc[repeat1[i]] = color;
		}
		for (int i = 1; repeat2[i] != 0&&i<=2; i++) {
			loc[repeat2[i]] = color;
		}
		loc[a] = color;
		newc();
		return true;
	}
	else { return false; }

}

// 换棋
int change(int color) {
	if (color == BLACK) {
		return WHITE;
	}
	else
	{
		return BLACK;
	}
}

// 一次贪心
int move(int color) {
	int* moveloc = new int[25];

	int* temploc = new int[25];
	for (int i = 1; i <= 24; i++) {
		temploc[i] = loc[i];
	}
	int* allcan = findallcan(color);
	int temp = 0;
	int location = 0;
	for (int i = 1; allcan[i] != 0; i++) {
		int sum = 0;
		canput(allcan[i], color);
		for (int j = 1; j <= 24; j++) {
			if (loc[j] == color) {
				sum++;
			}
		}
		if (sum > temp) {
			temp = sum;
			location = allcan[i];
			for (int j = 1; j <= 24; j++) {
				moveloc[j] = loc[j];
			}
		}
		for (int j = 1; j <= 24; j++) {
			loc[j] = temploc[j];
		}
		newc();
	}
	for (int j = 1; j <= 24; j++) {
		loc[j] = moveloc[j];
	}
	newc();
	return temp;
}

int max = 24;
// 贪心算法
int AI(int color) {
	int* oriloc = new int[25];
	for (int i = 1; i <= 24; i++) {
		oriloc[i] = loc[i];
	}
	
	int* all = findallcan(color);

	int* sum1 = new int[25];
	int* sum2 = new int[25];
	for (int i = 1; i <= 24; i++) { sum1[i] = 0; }
	for (int i = 1; i <= 24; i++) { sum2[i] = 0; }

	for (int i = 1; all[i] != 0; i++) {
		canput(all[i], color);
		for (int j = 1; j <= 24; j++) {
			if (loc[j] == color) {
				sum1[i]++;
			}
		}
		for (int j = 1; j <= max; j++) {
			// 对方贪心
			sum2[i] += move(change(color));
			// 我方贪心
			sum1[i] += move(color);
		}
		for (int j = 1; j <= 24; j++) {
			loc[j] = oriloc[j];
		}
		newc();
	}
	// 确定最优位置
	int nice = 0;
	int max = -9999;
	for (int i = 1; sum1[i] != 0; i++) {		
		int temp = sum1[i] - sum2[i];
		if (temp > max) {
			max = temp;
			nice = i;
		}
	}
	return all[nice];
}

int main() {
	rule();
	newGame();
	int location;
	int color = BLACK;
	while (1)
	{		
		if (finish()) {
			cout << endl << "对局已结束" << endl;
			whowin();
			return 0;
		}
		cout << "现在是棋子：" << color << endl;

		int* allcan = findallcan(color);
		if (allcan[1] == 0) {
			cout << "无位置可下,交由对方下棋" << endl;
			color = change(color);
		}
		else {
			if (color == BLACK) {
				cout << "你可以下的位置：";
				for (int i = 1; allcan[i] != 0; i++) {
					cout << allcan[i] << ' ';
				}cout << endl;

				cin >> location;
				if (canput(location, color)) {
					color = change(color);
				}
				else {
					cout << "请输入正确的位置" << endl;
				}
			}
			else
			{
				cout << "ai正在下棋" << endl;
				cout << "ai loc:" << AI(color) << endl;
				if (canput(AI(color), color)) {
					color = change(color);
				}
				else {
					cout << "ai error" << endl;
				}
			}
		}
		cout << endl << "----------------------" << endl << endl;
		output();
		
	} 
}