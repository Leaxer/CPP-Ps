#include "stack.h"

template<class T>
Stack<T>::Stack() : top(nullptr)
{
}

template<class T>
Stack<T>::Stack(const Stack<T>& aStack)
{
    if (aStack.isEmpty())
        top = nullptr;
    else
    {
        Node<T> *temp = aStack.top;
        Node<T> *end;
        end = new Node<T>(temp->getData(), temp->getLink());
        top = end;
        temp = temp->getLink();
        while (temp != nullptr)
        {
            end->setLink(new Node<T>(temp->getData(), nullptr));
            temp = temp->getLink();
            end = end->getLink();
        }
    }
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& rightSide)
{
    if (top == rightSide.top)
        return *this;
    else {
        T next;
        while(!isEmpty()) next = pop();
    }
    if(rightSide.isEmpty()) {
        top = nullptr;
        return *this;
    }
    else {
        Node<T>* temp;
            Node<T>* end;
            temp = rightSide.top;
            end = new Node<T>(temp->getData(), nullptr);
        top = end;
        temp = temp->getLink();
        while (temp != nullptr)
        {
            end->setLink(new Node<T>(temp->getData(), nullptr));
            temp = temp->getLink();
            end = end->getLink();
        }
        return *this;
    }
}

template<class T>
Stack<T>::~Stack()
{
    T next;
    while(!isEmpty()) next = pop();
}

template<class T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr);
}
template<class T>
void Stack<T>::push(T stackFrame)
{
    top = new Node<T>(stackFrame, top);
}

template<class T>
T Stack<T>::pop() throw(PopEmptyStackException)
{
    if (isEmpty()) {
        throw PopEmptyStackException();
    }else {
        T result = top->getData();
        Node<T> *discard = top;
        top = top->getLink();
        delete discard;
        return result;
    }
}

int main()
{
        Stack<int> s;
        s.push(4);
        s.push(10);
        s.push(54); // Attempt to pop from an empty stack
    try {
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
        cout << s.pop() << endl;
    }
    catch (PopEmptyStackException) {
        cout << "Tried to pop and empty stack!" << endl;
    }
    return 0;
}