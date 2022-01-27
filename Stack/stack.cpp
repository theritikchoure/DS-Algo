#include<iostream>
#include<string>

using namespace std;

class Stack{
    private: 
        int top;
        int arr[5];

    public:
        Stack(){
            top = -1;
            for (int i = 0; i < 5; i++)
            {
                arr[i] = 0;
            }
            
        }

        bool isEmpty(){
            if(top == -1) {
                return true;
            } else {
                return false;
            }
        };
        
        bool isFull(){
            if(top == 4) {
                return true;
            } else {
                return false;
            }
        };

        void push(int val){
            if(isFull()) {
                cout << "Stack Overflow" << endl;
            } else {
                top++;
                arr[top] = val;
            }
        }

        int pop(){ 
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return 0;
            } else { 
                int popValue = arr[top];
                arr[top] = 0;
                top--;
                return popValue;
            }
        }

        int count(){
            return top+1;
        }

        int peek(int pos){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
                return 0;
            } else {
                return arr[pos];
            }
        }

        void change(int pos, int val){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
            } else {
                arr[pos] = val;
            }
        }

        void display(){
            if(isEmpty()){
                cout << "Stack Underflow" << endl;
            } else {
                for (int i = 4; i >= 0; i--)
                {
                    cout << arr[i] << endl;
                }
            }
        }
};

int main() {
    Stack s1;
    int option, position, value;
    do {
        cout << "What Operation Do You Want to Perform, Or Enter 0 to Exit" << endl;
        cout << "1. Push()" << endl;
        cout << "2. Pop()" << endl;
        cout << "3. isEmpty()" << endl;
        cout << "4. isFull()" << endl;
        cout << "5. peek()" << endl;
        cout << "6. count()" << endl;
        cout << "7. change()" << endl;
        cout << "8. display()" << endl;
        cout << "9. Clear Screen" << endl;

        cin >> option;

        switch (option) {
            case 1:
                cout << "Enter an item to push in the stack" << endl;
                cin >> value;
                s1.push(value);
                break;
            
            case 2: 
                cout << "Pop Function Called - Poped Value : " << s1.pop() << endl;
                break;

            case 3:
                if(s1.isEmpty()){
                    cout << "Stack Is Empty" << endl;
                } else {
                    cout << "Stack Is Not Empty" << endl;
                }
                break;

            case 4: 
                if(s1.isFull()){
                    cout << "Stack Is Full" << endl;
                } else {
                    cout << "Stack Is Not Full" << endl;
                }
                break;

            case 5: 
                cout << "Enter the position of the item you want to peek:" << endl;
                cin >> position;
                cout << "Peek Function Called - Value at " << position << " is " << s1.peek(position) << endl;
                break;

            case 6: 
                cout << "Count Function Called - Number of items in the stack is " << s1.count() << endl;
                break;

            case 7: 
                cout << "Change Function Called -" << endl;
                cout << "Enter Position of item you want to change" << endl;
                cin >> position;
                cout << endl;
                cout << "Enter the value of item you want to change" << endl;
                cin >> value;
                s1.change(position, value);
                break;

            case 8:
                cout << "Display Function Called -" << endl;
                s1.display();
                break;

            case 9:
                system("cls");
                break;

            default:
                cout << "Please Enter Proper Option Number" << endl;
        }
    } while (option != 0);
    
    return 0;
}