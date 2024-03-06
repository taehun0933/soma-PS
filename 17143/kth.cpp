#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, m;

struct shark
{
    int s;
    int d;
    int z;
};

vector<shark> sharks[101][101];
int sharkGet;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> r >> c >> m;

    if (m == 0)
    {
        cout << "0";
        return 0;
    }

    for (int i{1}; i <= m; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        shark sk;
        sk.s = s;
        sk.d = d;
        sk.z = z;
        sharks[r][c].push_back(sk);
    }

    for (int i{1}; i <= c; i++)
    {
        // 상어 잡기
        for (int j{1}; j <= r; j++)
        {
            if (sharks[j][i].size() == 1)
            {
                sharkGet += sharks[j][i][0].z;
                sharks[j][i].pop_back();
                break;
            }
        }

        // 상어 이동
        vector<shark> newSharks[101][101];

        for (int a{1}; a <= r; a++)
        {
            for (int b{1}; b <= c; b++)
            {
                if (sharks[a][b].size() == 0)
                    continue;

                shark sk = sharks[a][b][0];
                int sp = sk.s;
                int posX = b;
                int posY = a;
                int add{1};

                switch (sk.d)
                {
                case 1:
                    // 위, r 관련
                    for (int num{0}; num < sp; num++)
                    {
                        posY -= add;
                        if (posY == 0)
                        {
                            posY += 2;
                            add *= -1;
                            sk.d = 2;
                        }
                        else if (posY > r)
                        {
                            posY -= 2;
                            add *= -1;
                            sk.d = 1;
                        }
                    }
                    newSharks[posY][posX].push_back(sk);
                    break;
                case 2:
                    // 아래, r 관련
                    for (int num{0}; num < sp; num++)
                    {
                        posY += add;

                        if (posY == 0)
                        {
                            posY += 2;
                            add *= -1;
                            sk.d = 2;
                        }
                        else if (posY > r)
                        {
                            posY -= 2;
                            add *= -1;
                            sk.d = 1;
                        }
                    }
                    newSharks[posY][posX].push_back(sk);
                    break;
                case 3:
                    // 오른쪽, c 관련
                    for (int num{0}; num < sp; num++)
                    {
                        posX += add;

                        if (posX > c)
                        {
                            posX -= 2;
                            add *= -1;
                            sk.d = 4;
                        }
                        else if (posX == 0)
                        {
                            posX += 2;
                            add *= -1;
                            sk.d = 3;
                        }
                    }
                    newSharks[posY][posX].push_back(sk);
                    break;
                case 4:
                    // 왼쪽, c 관련
                    for (int num{0}; num < sp; num++)
                    {
                        posX -= add;

                        if (posX > c)
                        {
                            posX -= 2;
                            add *= -1;
                            sk.d = 4;
                        }
                        else if (posX == 0)
                        {
                            posX += 2;
                            add *= -1;
                            sk.d = 3;
                        }
                    }
                    newSharks[posY][posX].push_back(sk);
                    break;
                }
            }
        }

        for (int a{1}; a <= r; a++)
        {
            for (int b{1}; b <= c; b++)
            {
                if (newSharks[a][b].size() > 1)
                {
                    int arr{0};
                    int max = newSharks[a][b][0].z;

                    for (int go{1}; go < newSharks[a][b].size(); go++)
                    {
                        if (max < newSharks[a][b][go].z)
                        {
                            max = newSharks[a][b][go].z;
                            arr = go;
                        }
                    }

                    shark biggestShark = newSharks[a][b][arr];
                    newSharks[a][b].clear();
                    newSharks[a][b].push_back(biggestShark);
                }

                sharks[a][b] = newSharks[a][b];
            }
        }
    }

    cout << sharkGet;
}
