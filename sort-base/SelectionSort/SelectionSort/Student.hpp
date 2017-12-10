//
//  Student.hpp
//  SelectionSort
//
//  Created by ling on 2017/12/10.
//  Copyright © 2017年 ling. All rights reserved.
//

#ifndef Student_hpp
#define Student_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

struct Student {
    
    string name;
    int score;
    
    //operator--运算符重载
    bool operator<(const Student &otherStudent){
        
        return score < otherStudent.score;
    }
    
    //friend 友元，公布私有成员或函数
    friend ostream &operator<<(ostream &os, Student &student){
        
        os<<"Student: " <<student.name<<" "<<student.score<<endl;
        return os;
    }
};

#endif /* Student_hpp */
