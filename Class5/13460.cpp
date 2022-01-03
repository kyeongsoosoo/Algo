#include <iostream>
#include <queue>
#define MAX 13
#define COUNT_MAX 10

using namespace std;

struct coord
{
    int x;
    int y;
    bool is_fin;
};

struct coords
{
    coord red;
    coord blue;
    int move_count;
};

int N,
    M;
int visited[MAX][MAX][MAX][MAX];
char map[MAX][MAX];
coord initial_red;
coord initial_blue;
coord goal;
int x_move[4] = {0, 0, -1, 1};
int y_move[4] = {1, -1, 0, 0};
int res = 0;

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;

    string tmp;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        for (int j = 0; j < M; j++)
        {
            map[i][j] = tmp[j];
            if (tmp[j] == 'R')
            {
                initial_red.x = j;
                initial_red.y = i;
            }
            if (tmp[j] == 'B')
            {
                initial_blue.x = j;
                initial_blue.y = i;
            }
            if (tmp[j] == 'O')
            {
                goal.x = j;
                goal.y = i;
            }
        }
    }
}

bool shouldRedFirst(coord red, coord blue, int direction)
{
    // cout << "dir: " << direction << '\n';
    // cout << "rx bx " << (red.x + blue.x) << '\n';
    // cout << "red: " << red.y << " " << red.x << " blue: " << blue.y << " " << blue.x << '\n';
    //상하좌우
    switch (direction)
    {
    case 0:
        if (red.y > blue.y)
            return true;
        return false;
        break;

    case 1:
        if (red.y < blue.y)
            return true;
        return false;
        break;

    case 2:
        if (red.x < blue.x)
            return true;
        return false;
        break;

    case 3:
        if (red.x > blue.x)
            return true;
        return false;
        break;

    default:
        return false;
    }
}

bool ballCondition(int y, int x)
{
    // cout << map[2][2] << '\n';
    if (map[y][x] == '.' || map[y][x] == 'O')
        return true;
    return false;
}

coord moveBall(coord ball, int direction, char color)
{
    coord new_coord = ball;

    int next_x = x_move[direction];
    int next_y = y_move[direction];

    // cout << "color: " << color << " " << ball.y << " " << ball.x << '\n';
    while (true)
    {
        int next_x_coord = new_coord.x + next_x;
        int next_y_coord = new_coord.y + next_y;

        if (ballCondition(next_y_coord, next_x_coord))
        {
            new_coord.x = next_x_coord;
            new_coord.y = next_y_coord;
            if (map[next_y_coord][next_x_coord] == 'O')
            {
                new_coord.is_fin = true;
                break;
            }
        }
        else
            break;
    }
    // cout << "color: " << color << " " << new_coord.y << " " << new_coord.x << '\n';
    // cout << new_coord.is_fin << '\n';
    // cout << map[3][2] << '\n';

    return new_coord;
}

bool isFineFinish(bool red, bool blue)
{
    if (red && !blue)
        return true;
    return false;
}

bool isBadFinish(bool red, bool blue)
{
    if (blue)
        return true;
    return false;
}

void makeDFS()
{
    coords initialCoord = {initial_red, initial_blue, 0};

    queue<coords> Q;
    Q.push(initialCoord);

    // cout << '?';

    while (!Q.empty())
    {
        coords cur_coords = Q.front();
        coord red = cur_coords.red;
        coord blue = cur_coords.blue;
        int cur_count = cur_coords.move_count;
        Q.pop();

        if (cur_count == COUNT_MAX)
        {
            res = -1;
            return;
        }
        if (visited[red.y][red.x][blue.y][blue.x])
            continue;
        visited[red.y][red.x][blue.y][blue.x] = true;

        for (int direction = 0; direction < 4; direction++)
        {
            // cout << "dir: " << direction << '\n';
            bool isRedFirst = shouldRedFirst(cur_coords.red, cur_coords.blue, direction);
            coord red_result;
            coord blue_result;

            map[cur_coords.red.y][cur_coords.red.x] = 'R';
            map[cur_coords.blue.y][cur_coords.blue.x] = 'B';
            map[goal.y][goal.x] = 'O';

            // cout << "is: " << isRedFirst << '\n';

            if (isRedFirst)
            {
                red_result = moveBall(red, direction, 'R');
                map[cur_coords.red.y][cur_coords.red.x] = '.';
                map[red_result.y][red_result.x] = 'R';
                map[goal.y][goal.x] = 'O';
                blue_result = moveBall(blue, direction, 'B');
                map[cur_coords.blue.y][cur_coords.blue.x] = '.';
            }
            else
            {
                blue_result = moveBall(blue, direction, 'B');
                map[cur_coords.blue.y][cur_coords.blue.x] = '.';
                map[blue_result.y][blue_result.x] = 'B';
                map[goal.y][goal.x] = 'O';
                red_result = moveBall(red, direction, 'R');
                map[cur_coords.red.y][cur_coords.red.x] = '.';
            }

            // cout << blue_result.y << " " << blue_result.x << '\n';

            map[red_result.y][red_result.x] = '.';
            map[blue_result.y][blue_result.x] = '.';
            map[goal.y][goal.x] = 'O';

            // cout << '\n';
            if (isFineFinish(red_result.is_fin, blue_result.is_fin))
            {
                res = cur_count + 1;
                return;
            }
            if (isBadFinish(red_result.is_fin, blue_result.is_fin))
            {
                continue;
            }

            Q.push({red_result, blue_result, cur_count + 1});
            // cout << cur_count << '\n';
        }
    }
}

int main()
{
    input();
    makeDFS();

    cout << (res == 0 ? -1 : res);
}