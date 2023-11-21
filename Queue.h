#ifndef WEEK8_QUEUE_H
#define WEEK8_QUEUE_H
using namespace std;
template<class T>
class Queue {
private:
    struct Node {
        T element;
        Node* next;

        Node(T anElement, Node* aNextPointer = nullptr) {
            element = anElement;
            next = aNextPointer;
        }
    };

    Node* front;
    Node* back;
    int numNodes;

public:
    Queue();
    ~Queue();
    void enqueue(T);
    void dequeue(T &);
    bool isEmpty();
    void clear();
};

//************************************************
// Constructor                                   *
//************************************************
template<class T>
Queue <T>::Queue() {
    front = nullptr;
    back = nullptr;
    numNodes = 0;
}

//************************************************
// Destructor                                    *
//************************************************
template<class T>
Queue<T>::~Queue(){
    clear();
}

//************************************************
// Function enqueue inserts the value in num     *
// at the rear of the queue.                     *
//************************************************
template<class T>
void Queue<T>::enqueue(T num) {

    Node *newNode = new Node(num);
    if (isEmpty()) {
        front = newNode;
        back = newNode;
    }
    else {
        back->next = newNode;
        back = newNode;
    }
    numNodes++;

 /*   if (isEmpty()) {
        front->element = num;
    }
    else {
        while (front->next) {
            if (front->next == nullptr) {
                (front->next)->element = num;
            }
        }
    }
    */
}

//************************************************
// Function dequeue removes the value at the     *
// front of the queue, and copies it into num.   *
//************************************************
template<class T>
void Queue<T>::dequeue(T &num) {
    Node *newNode = nullptr;
    if(isEmpty()) {
        cout << "Queue empty" << endl;
    }
    else {
        num = front->element;
        newNode = front->next;
        delete front;
        front = newNode;
        numNodes--;
    }

}

//************************************************
// Function isEmpty returns true if the queue    *
// is empty, and false otherwise.                *
//************************************************

template<class T>
bool Queue<T>::isEmpty() {
    return numNodes == 0;
}
//************************************************
// Function clear dequeues all the elements      *
// in the queue.                                 *
//************************************************
template<class T>
void Queue<T>::clear() {
    T num;
    while(!isEmpty()) {
        dequeue(num);
    }
}

#endif //WEEK8_QUEUE_H
