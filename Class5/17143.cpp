#include <iostream>
#include <cstring>
#include <vector>
#define MAX 101

using namespace std;

struct shark
{
    int y;
    int x;
    int speed;
    int direction;
    int size;
    int v_idx;
    bool isAlive = false;
};

struct cord_with_flipped
{
    int cord;
    bool isFlipped;
};

int R,
    C, M;
int x_move[4] = {0, 0, 1, -1};
int y_move[4] = {-1, 1, 0, 0};
vector<shark> sharks;
shark mock_shark = {0, 0, 0, 0, 0, false};
shark map[MAX][MAX];
int result = 0;

shark make_shark(int r, int c, int s, int d, int z, int v_idx)
{
    shark S = {r, c, s, d, z, v_idx, true};
    return S;
}

void initMap()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            map[i][j] = mock_shark;
        }
    }
}

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C >> M;

    int r, c, s, d, z;
    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> s >> d >> z;
        shark S = make_shark(r - 1, c - 1, s, d - 1, z, sharks.size());
        sharks.push_back(S);
        map[r - 1][c - 1] = S;
    }
}

void catchShark(int col_idx)
{
    for (int i = 0; i < R; i++)
    {
        // cout << "col: " << col_idx << '\n';
        if (map[i][col_idx].isAlive)
        {
            int idx = map[i][col_idx].v_idx;
            sharks[idx].isAlive = false;
            result += sharks[idx].size;
            // cout << sharks[idx].size << " " << idx << '\n';
            break;
        }
    }
}

cord_with_flipped calcCord(int cord, int limit, int dir, int speed)
{
    int org_dir = dir;

    if (dir == 0)
        return {cord, false};

    while (speed--)
    {
        if (((cord + dir) < 0) || ((cord + dir) >= limit))
            dir *= -1;

        cord += dir;
    }

    bool flipped = dir != org_dir;

    return {cord, flipped};
}

int make_new_direction(int org_dir, bool is_x_flipped, bool is_y_flipped)
{
    if (is_x_flipped)
    {
        if (org_dir == 3)
            return 2;
        return 3;
    }
    if (is_y_flipped)
    {
        if (org_dir == 0)
            return 1;
        return 0;
    }
    return org_dir;
}

void moveShark(shark S)
{
    if (!S.isAlive)
        return;
    cord_with_flipped next_x_struct = calcCord(S.x, C, x_move[S.direction], S.speed);
    cord_with_flipped next_y_struct = calcCord(S.y, R, y_move[S.direction], S.speed);

    int next_x = next_x_struct.cord;
    int next_y = next_y_struct.cord;
    int new_dir = make_new_direction(S.direction, next_x_struct.isFlipped, next_y_struct.isFlipped);

    shark new_shark = make_shark(next_y, next_x, S.speed, new_dir, S.size, S.v_idx);

    // cout << "flipped: " << next_y_struct.isFlipped << '\n';
    // cout << "dir: " << S.direction << '\n';
    // cout << "new_dir: " << new_dir << '\n';
    // cout << "isAlive : " << S.isAlive << '\n';
    // cout << S.y << " " << S.x << '\n';
    // cout << next_y << " " << next_x << '\n';
    // cout << "done" << '\n';

    if (map[next_y][next_x].isAlive)
    {
        shark origin = map[next_y][next_x];

        if (origin.size > S.size)
        {
            sharks[S.v_idx].isAlive = false;
        }
        else
        {
            sharks[origin.v_idx].isAlive = false;
            map[next_y][next_x] = new_shark;
            sharks[S.v_idx] = new_shark;
        }
    }
    else
    {
        map[next_y][next_x] = new_shark;
        sharks[S.v_idx] = new_shark;
    }
}

void moveSharks()
{
    // 맵을 초기화
    // 상어 이동 후 배치
    // 겹치는 상어의 경우 먹어주기

    initMap();

    for (int i = 0; i < sharks.size(); i++)
    {
        moveShark(sharks[i]);
    }
    // cout << '\n';
}

void makeAns()
{
    for (int i = 0; i < C; i++)
    {
        catchShark(i);
        moveSharks();
    }
}

int main()
{
    input();
    makeAns();

    cout << result;
}