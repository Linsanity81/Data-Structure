#include <iostream>
#include <string>

using namespace std;

template <typename T>
class SqList
{
    T *data;
    int capacity, n;

public:
    SqList(int cap = 3)
    {
        data = new T[cap];
        if (!data) throw "Memory allocation fails.";
        capacity = cap;
        n = 0;
    }

    int size()
    {
        return n;
    }

    bool get(int i, T &e)
    {
        if ( i < 1 or i > n)
            return false;

        e = data[i - 1];
        return true;
    }

    bool set(int i, T e)
    {
        if ( i < 1 or i > n)
            return false;

        data[i - 1] = e;
        return true;
    }

    bool push_back(T e)
    {
        if (n == capacity)
        {
            if (!realloc())
                return false;
        }

        data[n] = e;

        n++;

        return true;
    }

    bool insert(int i, T e)
    {
        if ( i < 1 or i > n + 1)
            return false;

        if (n == capacity)
        {
            if (!realloc())
                return false;
        }

        for (int j = n; j >= i; --j)
        {
            data[j] = data[j - 1];
        }

        data[i - 1] = e;

        n++;

        return true;
    }

    bool remove(int i)
    {
        if (i < 1 or i > n)
            return false;

        for (int j = i + 1; j <= n; ++j)
        {
            data[j - 2] = data[j - 1];
        }
        n--;
        return true;
    }

    bool pop_back()
    {
        if (n == 0)
            return false;

        n--;

        return true;
    }

    bool remove_front()
    {
        for (int j = 2; j <= n; ++j)
        {
            data[j - 2] = data[j - 1];
        }
        n--;
        return true;
    }

    void traverse (void (*fp) (T &e))
    {
        for (int i = 1; i <= n; ++i)
        {
            fp(data[i - 1]);
        }
    }

    void converse()
    {
        for (int i = 0, j = n - 1; i < j; i++, j--)
        {
            T t = data[i];
            data[i] = data[j];
            data[j] = t;
        }
    }

private:
    bool realloc()
    {
        T *p = new T[2 * capacity];
        if (!p) return false;

        for (int i = 0; i < n; ++i)
        {
            p[i] = data[i];
        }

        delete[] data;

        data = p;

        capacity *= 2;

        return true;
    }
};

template <typename T>
void print(SqList<T> &L)
{
    T e;

    for (int i = 1 ; i <= L.size(); ++i)
    {
        L.get(i, e);
        std::cout << e;
    }

    cout << std::endl;
}

void Print(char &ch)
{
    cout << ch << " ";
}

struct student
{
    string name;
    double score;
    student(string n = "none", double s = 0)
    {
        name = n;
        score = s;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    SqList <char> list;

    list.push_back('A'); print(list);
    list.push_back('B'); print(list);
    list.push_back('C'); print(list);
    list.push_back('D'); print(list);

    list.set(2,'H'); print(list);

    list.insert(2, 'K'); print(list);

    list.remove(3); print(list);

    list.pop_back(); print(list);

    list.remove_front(); print(list);

    list.traverse(Print); cout << endl;

    list.converse(); print(list);

    return 0;
}
