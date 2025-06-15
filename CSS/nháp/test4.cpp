#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, u, v;
char a[1001][1001];
bool visited[1001][1001];
int d[1001][1001]; // Lưu số bước đi từ ô bắt đầu tới ô i,j
pair<int, int> parent[1001][1001]; // Lưu vị trí cha của mỗi ô
string ve[1001][1001];

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

void bfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    visited[i][j] = true;
    d[i][j] = 0;
    parent[i][j] = {-1, -1}; // Điểm bắt đầu không có cha

    while (!q.empty()) {
        pair<int, int> v = q.front(); q.pop();
        for (int k = 0; k < 4; k++) {
            int i1 = v.first + dx[k];
            int j1 = v.second + dy[k];
            if (i1 >= 1 && i1 <= n && j1 >= 1 && j1 <= m && a[i1][j1] != '1' && !visited[i1][j1]) {
                d[i1][j1] = d[v.first][v.second] + 1;
                parent[i1][j1] = {v.first, v.second}; // Lưu cha của ô hiện tại
                if (a[i1][j1] == 'B') return;
                q.push({i1, j1});
                visited[i1][j1] = true;
            }
        }
    }
}

void printPath(int x, int y) {
    if (parent[x][y] == make_pair(-1, -1)) {
        ve[x][y]="*";
        return;
    }
    printPath(parent[x][y].first, parent[x][y].second);
    ve[x][y]="*";
}

void inp() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'A') {
                s = i;
                t = j;
            } else if (a[i][j] == 'B') {
                u = i;
                v = j;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ve[i][j]=" ";
        }
        cout << endl;
    }
    system("cls");
    memset(visited, false, sizeof(visited));
    bfs(s, t);
    if (d[u][v] == 0) cout << "Khong co duong di\n";
    else {
        cout << "So buoc: " << d[u][v] << endl;
        cout << "Duong di: \n";
        printPath(u, v);
        cout << endl;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout << ve[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {
    system("color 2");
    inp();
    
    return 0;
}