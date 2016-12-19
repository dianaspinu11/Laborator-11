
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Stack
{
public:
    void push(const T&);
    void pop();
    bool isEmpty();
    T& top();
private:
    struct Node
    {
        T dat;
        Node *next;
        Node(const T& newData, Node *nextNode)
            {
                dat=newData;
                next=nextNode;
            }
    };
    Node *topN = 0;
};

template<class T>
void Stack<T>::push(const T& item)
{
    topN = new Node(item,topN);
}

template<class T>
void Stack<T>::pop()
{
    if(!isEmpty())
    {
        Node *newTop = topN;
        topN = topN->next;
        delete newTop;
    }
}

template<class T>
T& Stack<T>::top()
{
    if(!isEmpty())
    {
        return topN->dat;
    }
}

template<class T>
bool Stack<T>::isEmpty()
{
    return topN == 0;
}

template<class T>
class Stiva
{
public:
    bool isEmpty();
    void push(const T&);
    const T& top();
    void pop();
private:
    vector<T> vect;
};

template<class T>
bool Stiva<T>::isEmpty()
{
    return (vect.size() !=0 ? 0:1);
}

template<class T>
void Stiva<T>::push(const T& item)
{
    vect.push_back(item);
}

template<class T>
const T& Stiva<T>::top()
{
    return vect.back();
}

template<class T>
void Stiva<T>::pop()
{
    vect.pop_back();
}

int main()
{
    Stack <int> stiva;
    stiva.push(10);
    stiva.push(12);
    stiva.push(15);
    cout<<stiva.top()<<endl;
    stiva.pop();
    cout<<stiva.top()<<endl;
    stiva.pop();
    cout<<stiva.top()<<endl;
    stiva.pop();
    if(stiva.isEmpty())
        cout<<"da";
    else
        cout<<"nu";
    cout<<"\n\n";
    Stiva<int> s;
    s.push(3);
    s.push(2);
    s.push(9);

    cout<<s.top()<<endl;
    s.pop();
    cout<<s.top()<<endl;
    s.pop();
    if(s.isEmpty())
        cout<<"da";
    else
        cout<<"nu";
    return 0;
}
