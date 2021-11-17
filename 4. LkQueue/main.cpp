#include <iostream>
#include <queue>
using namespace std;

template <typename T>
class LkQueue
{
    struct Node
    {
        T data;
        Node * next;
    };

    Node* front;
    Node* back;

public:
    LkQueue();
    bool push(T e);
    bool pop();
    T& front_item()
    {
        if (front == back) throw "Empty Queue.\n";

        return front->next->data;
    }
};

template<class T>
LkQueue<T>::LkQueue()
{
    front = back = new Node();

    if (!front or !back) throw "No Memory.\n";

    front->next = 0;
}

template<class T>
bool LkQueue<T>::push(T e)
{
    Node *p = new Node();

    if (!p) return false;

    p->data = e;
    p->next = 0;

    back->next = p;
    back = p;

    return true;
}

template<class T>
bool LkQueue<T>::pop()
{
    if (front == back) return false;

    front->next = front->next->next;

    if (back == front->next)
        back = front;

    delete front->next;

    return true;
}

int main() {
//    LkQueue<int> Q;

    queue<int> Q;

    Q.push(10);
    Q.push(3);
    Q.push(5);
//    cout << Q.front_item() << endl;
    cout << Q.front() << endl;
    Q.pop();
//    cout << Q.front_item() << endl;
    cout << Q.front() << endl;

    return 0;
}
