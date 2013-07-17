#include "mythread.h"
#include <QtCore>

extern "C"{
#include "p0f.h"
}

MyThread::MyThread()
{
}

void MyThread::run(){

    go();
}
