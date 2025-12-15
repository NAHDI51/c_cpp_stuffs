#include <bits/stdc++.h>
using namespace std;

using vi = vector<int>;
using vii = vector<vi>;
using vs = vector<string>;
using vss = vector<vs>;
using vb = vector<bool>;
using ii = pair<int, int>;
using vpi = vector<ii>;
using vpii = vector<vpi>;
using ll = long long;
using table = unordered_map<unsigned long, int>;

#define f first
#define s second

#define forn(i, n) for(int i = 0; i < n; i++)
#define fore(i, a, b) for(int i = a; i <= b; i++)
#define for1n(i, n) for(int i = 1; i <= n; i++)
#define rof(i, n) for(int i = n-1; i >= 0; i--)
#define rofe(i, a, b) for(int i = b; i >= a; i--)
#define all(x) x.begin(), x.end()
#define dsc(type) greater<type>

#define FLAG cout << "Reached here.\n"

#define pb push_back
#define sz size
#define rsz resize
#define rsv reserve
#define ins insert
#define maxN 

#define onec(x) __builtin_popcount(x)
#define end0(x) __builtin_clz(x)
#define beg0(x) __builtin_ctz(x)

#define MAX 100000000
#define MIN -MAX

template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }

// Below arrays detail all eight possible movements
// for a knight
int row[] = { 2, 2, -2, -2, 1, 1, -1, -1 };
int col[] = { -1, 1, 1, -1, 2, -2, 2, -2 };
 
// Check if (x, y) is valid chessboard coordinates.
// Note that a knight cannot go out of the chessboard
bool isValid(int x, int y, int N) {
    return (x >= 0 && x < N) && (y >= 0 && y < N);
}
 
// A queue node used in BFS
struct Node
{
    // (x, y) represents chessboard coordinates
    // `dist` represents its minimum distance from the source
    int x, y, dist;
 
    // Node constructor
    Node(int x, int y, int dist = 0): x(x), y(y), dist(dist) {}
 
    // As we are using struct as a key in a `std::set`,
    // we need to overload `<` operator`.
    // Alternatively, we can use `std::pair<int, int>` as a key
    // to store the matrix coordinates in the set.
 
    bool operator<(const Node& o) const {
        return x < o.x || (x == o.x && y < o.y);
    }
};
 
// Find the minimum number of steps taken by the knight
// from the source to reach the destination using BFS
int findShortestDistance(int N, Node src, Node dest)
{
    // set to check if the matrix cell is visited before or not
    set<Node> visited;
 
    // create a queue and enqueue the first node
    queue<Node> q;
    q.push(src);
 
    // loop till queue is empty
    while (!q.empty())
    {
        // dequeue front node and process it
        Node node = q.front();
        q.pop();
 
        int x = node.x;
        int y = node.y;
        int dist = node.dist;
 
        // if the destination is reached, return distance
        if (x == dest.x && y == dest.y) {
            return dist;
        }
 
        // skip if the location is visited before
        if (!visited.count(node))
        {
            // mark the current node as visited
            visited.insert(node);
 
            // check for all eight possible movements for a knight
            // and enqueue each valid movement
            for (int i = 0; i < 8; i++)
            {
                // get the knight's valid position from the current position on
                // the chessboard and enqueue it with +1 distance
                int x1 = x + row[i];
                int y1 = y + col[i];
 
                if (isValid(x1, y1, N)) {
                    q.push({x1, y1, dist + 1});
                }
            }
        }
    }
 
    // return infinity if the path is not possible
    return INT_MAX;
}

void solve(int x, int y, int tx, int ty) {
    int N = 8;
    Node src = {x, y};
    Node dest = {tx, ty};
    cout << findShortestDistance(N, src, dest) << '\n';
}

int main() {
    while(1) {
    string a, b;
    cin >> a >> b;
    if(a[0] == '0' && b[0] == '0') return 0;
    solve(a[0]-97, a[1]-49, b[0]-97, b[1]-49);
    }
    
}