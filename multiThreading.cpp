#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;

void taskA(){
    for(int i = 0; i<10; ++i){
        sleep(1);
        cout << "TaskA " << i ;
    }
}

void taskB(){
    for(int i = 0; i<10; ++i){
        sleep(1);
        cout << "TaskB " << i ;
    }
}

int main(){

    thread t1(taskA);
    thread t2(taskB);

    return 0;
}
// If we try to run the program then an error will occur "terminate called without
//an active exception"
//Why this error because the main function or main thread exited before the taskA
//and taskB

//To resolve this

#include<iostream>
#include<thread>
#include<unistd.h>
using namespace std;

void taskA(){
    for(int i = 0; i<10; ++i){
        sleep(1);
        cout << "TaskA " << i ;
    }
}

void taskB(){
    for(int i = 0; i<10; ++i){
        sleep(1);
        cout << "TaskB " << i ;
    }
}

int main(){

    thread t1(taskA);
    thread t2(taskB);

    t1.join();
    t2.join();

    //t2 waits till t1 completes and both run simultaneously
    return 0;
}