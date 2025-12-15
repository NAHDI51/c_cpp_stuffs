/*
#include <bits/stdc++.h>
using namespace std;

#define mx 100000000
int main() {
    int n;
    cin >> n;
    int dp[1002][12];
    int off[1002][12];
    while(n--) {
        int x;
        cin >> x;
        x /= 100;

        for(int i = 0; i < 12; i++) dp[0][i] = mx;
        for(int i = 0; i <= x; i++) dp[i][0] = dp[i][11] = mx;

        for(int i = 10; i >= 1; i--) for(int j = 1; j <= x; j++) cin >> off[j][i];

        dp[0][1] = 0;
        for(int i = 1; i <= x; i++) 
            for(int j = 1; j <= 10; j++)
                dp[i][j] = min({dp[i-1][j-1]+60, dp[i-1][j]+30, dp[i-1][j+1]+20}) - off[i][j];  
        
        cout << dp[x][1] << '\n';
    }
    return 0;
}
*/
#include <iostream>

	

#include <vector>

	

	

using namespace std;

	

	

int main()

	

{

	

	// fast io

	

	ios::sync_with_stdio(false);

	

	cin.tie(nullptr);

	

	cout.tie(nullptr);

	

	

	int N, X, a;

	

	vector< vector<int> > wind;

	

	vector< vector<int> > dp;

	

	

	cin >> N;

	

	while (N--)

	

	{

	

		cin >> X, X /= 100;

	

	

		// init

	

		wind.assign(10, vector<int>());

	

		dp.assign(10, vector<int>(X + 1, 100000));

	

		dp[0][0] = 0;

	

		

	

		// store wind data (up to down)

	

		for (int i = 9; i >= 0; --i) for (int j = 0; j < X; ++j)

	

		{

	

			cin >> a;

	

			wind[i].emplace_back(a);

	

		}

	

	

		// DP

	

		for (int j = 1; j <= X; ++j) for (int i = 0; i < 10; ++i)

	

		{

	

			int Min = 100000;

	

	

			if (i != 0)

	

			{

	

				Min = min(Min, dp[i][j - 1] + 30 - wind[i][j - 1]);

	

				Min = min(Min, dp[i - 1][j - 1] + 60 - wind[i - 1][j - 1]);

	

			}

	

			if (i != 9) Min = min(Min, dp[i + 1][j - 1] + 20 - wind[i + 1][j - 1]);

	

	

			dp[i][j] = Min;

	

		}

	

	

		cout << dp[0][X] << "\n\n";

	

	}

	

	

	return 0;

	

}



/*
2

400
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
1 9 9 1
1 -9 -9 1

1000
9 9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9 9
9 9 9 9 9 9 9 9 9 9 9
7 7 7 7 7 7 7 7 7 7 7
-5 -5 -5 -5 -5 -5 -5 -5 -5 -5
-7 -3 -7 -7 -7 -7 -7 -7 -7 -7
-9 -9 -9 -9 -9 -9 -9 -9 -9 -9
 */