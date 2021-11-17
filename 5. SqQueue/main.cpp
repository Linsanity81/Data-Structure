#include <iostream>

using namespace std;

template<typename T>
class SqQueue
{
    T * data;
    int front_;
    int rear_;
    int capacity;

public:
    SqQueue(int cap = 3)
    {
        data = new T[cap];

        if (!data) throw "No memory\n";

        front_ = rear_ = 0;
    }

    bool push(T e)
    {
        if ((rear_ + 1) % capacity == front_)
        {
            T * p = new T[2 * capacity];
            if (!p) return false;

            for (int i = 0; i < capacity; ++i)
            {
                p[i] = data[i];
            }

            delete [] data;
            data = p;
            capacity *= 2;
        }

        data[rear_] = e;
        rear_ = (rear_ + 1) % capacity;
        return true;
    }

    bool pop()
    {
        if (front_ == rear_) return false;
        front_ = (front_ + 1) % capacity;
        return true;
    }

    T & front()
    {
        if (front_ == rear_) throw "Empty Queue\n";
        return data[front_];
    }

    T & rear()
    {
        if (front_ == rear_) throw "Empty Queue\n";
        return data[(rear_ - 1 + capacity) % capacity];
    }

    int size()
    {
        return (rear_ - front_ + capacity) % capacity;
    }

    bool empty()
    {
        return front_ == rear_;
    }

    bool clear()
    {
        front_ = rear_ = 0;
    }

};
int main() {

    SqQueue<int> Q;

    Q.push(3);
    Q.push(4);
    Q.push(5);

    while (!Q.empty())
    {
        int f = Q.front();
        Q.pop();
        std::cout << f << " ";
    }

    cout << endl;

    return 0;
}
