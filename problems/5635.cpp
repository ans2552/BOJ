#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int n;
struct student {
	string name;
	int d;
	int m;
	int y;
};
student arr[100];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;

	string name;
	int d, m, y;
	for (int i = 0; i < n; i++) {
		cin >> name >> d >> m >> y;
		arr[i] = { name,d,m,y };
	}

	sort(arr, arr + n, [](const student& a, const student& b) {
		if (a.y > b.y)
			return true;
		else if (a.y == b.y) {
			if (a.m > b.m)
				return true;
			else if (a.m == b.m) {
				if (a.d > b.d)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	});

	cout << arr[0].name << '\n' << arr[n - 1].name;
}