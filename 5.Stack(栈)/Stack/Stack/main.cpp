//
//  main.cpp
//  Stack
//
//  Created by ling on 2018/1/23.
//  Copyright © 2018年 ling. All rights reserved.
//

#include <iostream>
#include "MyStack.hpp"

int main(int argc, const char * argv[]) {
    
    MyStack *s = new MyStack(4);
    s->push('h');
    s->push('e');
    s->push('l');
    s->push('w');
    s->stackTraverse();
    
    char elem;
    s->pop(elem);
    cout << elem << endl;
    s->stackTraverse();
    
    return 0;
}
