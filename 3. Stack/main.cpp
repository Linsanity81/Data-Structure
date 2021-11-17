#include <iostream>
#include <string>
template <typename T>

class SqStack
{
    T *data, *top_;
    int capacity;

public:
    SqStack(int cap = 3)
    {
        data = new T[cap];
        if (!data)
        {
            top_ = 0;
            capacity = 0;
            return;
        }

        top_ = data;
        capacity = cap;
    }

    T& top()
    {
        if (top_ == data) throw "Empty Stack\n";

        return *(top_ - 1);
    }

    bool push(T e)
    {
        if (top_ - data == capacity)
        {
            T* p = new T[2 * capacity];
            if (!p) return false;
            for (int i = 0; i < capacity; ++i)
            {
                p[i] = data[i];
            }
            delete [] data;
            data = p;
            top_ = data + capacity;
            capacity = 2 * capacity;
        }

        *top_ = e;
        top_++;
        return true;
    }

    bool pop()
    {
        if (top_ == data) return false;
        top_--;
        return true;
    }

    bool empty()
    {
        return top_==data;
    }

    void clear()
    {
        top_ == data;
    }
};

bool isLeft(char ch)
{
    if (ch == '(' or ch == '[' or ch == '{')
        return true;

    return false;
}

int main() {

    /// Test

//    SqStack<char> S;
//
//    S.push('A');
//    S.push('B');
//    S.push('C');
//    S.push('D');
//
//    while(!S.empty())
//    {
//        char e = S.top();
//        std::cout << e << " ";
//        S.pop();
//    }

    ///  Conversion

//    int N = 1348;
//    int d = 8;
//
//    SqStack<int> number;

//    while(N)
//    {
//        number.push(N%d);
//        N = N / d;
//    }
//
//    while(!number.empty())
//    {
//        auto e = number.top();
//        std::cout << e;
//        number.pop();
//    }

    /// 括号匹配
    SqStack<char> stack;
    std::string s;
    std::cin >> s;

    for (int i = 0; i < s.size(); ++i)
    {
        if (isLeft(s[i]))
            stack.push(s[i]);

        else
        {
            if (stack.empty())
                return -1;


        }
    }



    return 0;
}
