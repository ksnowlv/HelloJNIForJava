//
//  PersonExtension.cpp
//  SwiftCallC
//
//  Created by ksnowlv on 2019/3/29.
//  Copyright © 2019 ksnowlv. All rights reserved.
//

#include "PersonExtension.hpp"
#include "Person.hpp"

void * createPerson()
{
    Person *p = new Person();
    
    return (void *)p;
}

void destroyPerson(void* p) {
    if (p) {
        Person *person = (Person*)p;
        delete person;
    }
}


void setPersonAge(void* p, const int age) {
    
    if (p) {
        Person *person = (Person*)p;
        person->setAge(age);
    }
}

int personAge(void* p) {
    
    if (p) {
        Person *person = (Person*)p;
        return person->age();
    }
    
    return 0;
}

void setPersonName(void* p, const char* name) {
    if (p) {
        Person *person = (Person*)p;
        person->setName(name);
    }
}

const char* personName(void* p) {
    if (p) {
        Person *person = (Person*)p;
        return person->name();
    }
    
    return nullptr;
}


