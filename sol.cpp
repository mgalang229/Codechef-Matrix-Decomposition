#include <bits/stdc++.h>

using namespace std;

const int limit = (int) 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int n, a;
		cin >> n >> a;
		int prev = 1;
		int sum = 0;
		// perform Russian Peasant Multiplication
		auto RPM = [&](int x, int y) {
			int res = 1;
			while (y > 0) {
				if (y & 1) {
					res = (long long) res * x % limit;
				}
				x = (long long) x * x % limit;
				y = (long long) y / 2 % limit;
			}
			return (res % limit);
		};
		for (int i = 0; i < n; i++) {
			// multiply 'a' with 'prev' (with the previous 'p[i]')
			a = (long long) (a % limit) * (prev % limit) % limit;
			// store the new value of 'a' in 'prev'
			prev = a % limit;
			// multiply 'a' to itself (2i - 1) times
			a = (long long) RPM(a, (2 * (i + 1)) - 1) % limit;
			// calculate the sum of all the values of 'a'
			sum = (long long) (sum % limit) + (a % limit) % limit;
		}
		cout << sum % limit << '\n';
	}
	return 0;
}
