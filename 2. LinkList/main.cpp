#include <iostream>

template <typename T>

class LkList{

    struct LNode
    {
        T data;
        LNode *next;
    };

    LNode * head;

public:
    LkList()
    {
        head = new LNode();
        head->next = 0;
    }

    bool get(int i, T &e)
    {
        if (i <= 0)
            return false;

        LNode *p = head;
        int j = 0;

        while (p && j < i)
        {
            p = p->next;
            ++j;
        }

        if (!p)
            return false;

        e = p->data;

        return true;
    }

    bool insert(int i, T e)
    {
        if (i <= 0)
            return false;

        LNode *p = head;
        int j = 0;

        while (p && j < i - 1)
        {
            p = p->next;
            ++j;
        }

        if (!p)
            return false;

        LNode *s = new LNode();
        s->data = e;
        s->next = p->next;
        p->next = s;

        return true;
    }

    bool remove(int i)
    {
        if (i <= 0)
            return false;

        LNode *p = head;
        int j = 0;

        while (p && j < i - 1)
        {
            p = p->next;
            ++j;
        }

        if (!p)
            return false;

        LNode *q = p->next;
        p->next = q->next;
        delete q;
        return true;
    }

    bool insert_front(T e)
    {
        LNode *s = new LNode();
        s->data = e;
        s->next = head->next;
        head->next = s;
        return true;
    }

    bool remove_front()
    {
        LNode *q = head->next;
        head->next = q->next;
        delete q;
        return true;
    }

    bool push_back(T e)
    {
        LNode * p = head;

        while (p->next)
        {
            p = p->next;
        }

        p->next = new LNode();
        if (!p->next) return false;
        p->next->next = 0;
        p->next->data = e;
        return true;
    }

    void traverse(void (*fp) (T &e))
    {
        LNode *p = head->next;
        while (p)
        {
            fp(p->data);
            p = p->next;
        }
    }
    void converse()
    {
        LNode *p = head->next;
        head->next = 0;

        while(p)
        {
            LNode *q = p->next;
            p->next = head->next;
            head->next = p;
            p = q;
        }
    }

};

void Print(char &ch)
{
    std::cout << ch << " ";
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    LkList<char> list;
    list.push_back('A'); list.traverse(Print); std::cout << std::endl;
    list.push_back('B'); list.traverse(Print); std::cout << std::endl;
    list.insert_front('C'); list.traverse(Print); std::cout << std::endl;
    list.insert_front('D'); list.traverse(Print); std::cout << std::endl;
    list.insert(2, 'E'); list.traverse(Print); std::cout << std::endl;

    list.converse(); list.traverse(Print); std::cout << std::endl;

    return 0;
}
