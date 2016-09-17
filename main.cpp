#include <iostream>
#include <iomanip>

using namespace std;

class Stack
{
private:
        int top = 0;
        const int size = 5;
public:
        string *stack = new string[size];

        Stack(string *data);
        ~Stack();
        void Push(const string &value);
        void Pop();
        void Print();

};

Stack::Stack(string *data)
{
    for(top=0; top<size; top++)
    {
        stack[top] = data[top];
    }
}

Stack::~Stack()
{
    delete [] stack;
}

void Stack::Push(const string &value)
{
    if (top < size)
    stack[top++] = value;
    else
    cout << "Stack is overflow!" << endl;
}

void Stack::Pop()
{
    if(top > 0) top--;
    else
    cout << "Stack is underflow!" << endl;
}

void Stack::Print()
{
    for (int i = top - 1; i >= 0; i--)
    cout << "|" << setw(4) << stack[i] << endl;
    cout << endl;
}

int main()
{
    string data[5];

    for(int i=0; i<5; i++)
    {
        cout << "[" << i+1 << "]: ";
        getline(cin, data[i]);
    }

    Stack example(data);

    example.Print();

    cout << "Delete item ->" << endl;
    example.Pop();

    example.Print();

    cout << "Add item: ";
    string value;
    getline(cin, value);
    example.Push(value);

    example.Print();

    return 0;
}
