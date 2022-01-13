#include <iostream>
#define MAX 100001

using namespace std;

int n;
int idx[MAX];
int inorder[MAX];
int postorder[MAX];

void input()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> inorder[i];
        idx[inorder[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> postorder[i];
    }
}

void getPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd || postStart > postEnd)
        return;

    int rootIndex = idx[postorder[postEnd]];
    int leftSize = rootIndex - inStart;
    int rightSize = inEnd - rootIndex;
    cout << inorder[rootIndex] << ' ';

    getPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    getPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
    input();
    getPreOrder(1, n, 1, n);
}