#include <iostream>
#include <queue>

using namespace std;

using T = char;

struct BiNode
{
    T data;
    BiNode * lchild{0};
    BiNode * rchild{0};
};

void IOT(BiNode * T)
{
    if (!T) return;

    IOT(T->lchild);
    std::cout << T->data;
    IOT(T->rchild);
}

void PostOT(BiNode * T)
{
    if (!T) return;

    PostOT(T->lchild);
    PostOT(T->rchild);
    std::cout << T->data;
}

void PreOT(BiNode * T)
{
    if (!T) return;

    std::cout << T->data;
    PreOT(T->lchild);
    PreOT(T->rchild);
}

void bfs(BiNode * T)
{
    queue<BiNode *> Q;
    Q.push(T);
    while (!Q.empty())
    {
        BiNode * p = Q.front();
        Q.pop();
        std::cout << p->data;
        if (p->lchild)
            Q.push(p->lchild);

        if (p->rchild)
            Q.push(p->rchild);
    }
}

int Depth(BiNode * T)
{
    if (!T) return 0;

    int l = Depth(T->lchild);
    int r = Depth(T->rchild);
    return 1 > r ? l + 1 : r + 1;
}


int main() {
    BiNode * T = new BiNode(); T->data = 'A';
    T->lchild = new BiNode(); T->lchild->data = 'B';
    T->rchild = new BiNode(); T->rchild->data = 'C';

    BiNode * p = T->lchild;
    p->lchild = new BiNode(); p->lchild->data = 'D';
    p->rchild = new BiNode(); p->rchild->data = 'E';

    IOT(T); std::cout << endl;
    PostOT(T); cout << endl;
    PreOT(T); cout << endl;

    bfs(T); cout << endl;

    std::cout << "Depth: " << Depth(T) << endl;

    return 0;
}
