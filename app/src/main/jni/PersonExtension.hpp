//
//  PersonExtension.hpp
//  SwiftCallC
//
//  Created by ksnowlv on 2019/3/29.
//  Copyright © 2019 ksnowlv. All rights reserved.
//

#ifndef PersonExtension_h
#define PersonExtension_h

#include <stdio.h>


#ifdef __cplusplus
extern "C"{
#endif
    //在这里写上c的代码
    
    //初始化一个Person的实例
    void * createPerson();
    void destroyPerson(void* p);
    void setPersonAge(void* p, const int age);
    int personAge(void* p);
    void setPersonName(void* p, const char* name);
    const char* personName(void* p);

#ifdef __cplusplus
}
#endif

#endif /* PersonExtension_hpp */
