#include<iostream>
#include<string> 

using namespace std;

class Queue{ 
    private:
        int arr[5];
        int front, rear;

    public:
        Queue(){ 
            front = -1;
            rear = -1;
            for (int i = 0; i < 5; i++)
            {
                arr[i] = 0;
            }
            
        }

        bool isEmpty() {
            if(front == -1 && rear == -1) return true;
            else
                return false;
        }

        bool isFull() {
            if(rear == 4) return true;
            else
                return false;
        }

        void enqueue(int val) { 
            if(isFull()) {
                cout << "Queue is Full!" << endl;
                return;
            } else if(isEmpty()) {
                front = rear = 0;
                arr[rear] = val;
            } else {
                rear++;
                arr[rear] = val;
            }
        }

        int dequeue() {
            int x = 0;
            if(isEmpty()){
                cout << "Queue is Empty!" << endl;
                return 0;
            } else if(front == rear) {
                x = arr[front];
                arr[front] = 0;
                front = rear = -1;
                return x;
            } else {
                x = arr[front];
                arr[front] = 0;
                front++;
                return x;
            }
        }

        int count() {
            return (rear-front+1);
        }
        
        void display() {
            cout << "All Values in Queue Are : " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << arr[i] << " " << endl;
            }
        }

};

int main() { 
    Queue q1;
    int option, value;
    do {
        cout << "What Operation Do You Want to Perform, Or Enter 0 to Exit" << endl;
        cout << "1. Enqueue()" << endl;
        cout << "2. Dequeue()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. count()" << endl;
        cout << "6. display()" << endl;
        cout << "7. Clear Screen" << endl;

        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter an item to enqueue in the queue" << endl;
                cin >> value;
                q1.enqueue(value);
                break;
            
            case 2: 
                cout << "Deque Function Called - Dequeued Value : " << q1.dequeue() << endl;
                break;

            case 3:
                if(q1.isEmpty()){
                    cout << "Queue Is Empty" << endl;
                } else {
                    cout << "Queue Is Not Empty" << endl;
                }
                break;

            case 4: 
                if(q1.isFull()){
                    cout << "Queue Is Full" << endl;
                } else {
                    cout << "Queue Is Not Full" << endl;
                }
                break;

            case 5: 
                cout << "Count Function Called - Number of items in the stack is " << q1.count() << endl;
                break;

            case 6:
                cout << "Display Function Called -" << endl;
                q1.display();
                break;

            case 7:
                system("cls");
                break;

            default:
                cout << "Please Enter Proper Option Number" << endl;
        }
    } while (option != 0);
    
    return 0;
}