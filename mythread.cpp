#include "mythread.h"
#include <QtCore>

extern "C"{
#include "p0f.h"
}

MyThread::MyThread()
{
}

//Start p0f
void MyThread::run(){
    go();
}
