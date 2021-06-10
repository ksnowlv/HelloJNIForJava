//
// Created by ksnowlv on 2019/4/9.
//

#include "com_ksnowlv_hellojniforjava_JavaCallJNI.h"
#include "PersonExtension.hpp"
#include "JNILog.h"
#include <stdlib.h>
#include <string.h>

JNIEXPORT jint JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_showValue
  (JNIEnv * enc, jclass cls , jint value) {

    LOGI("jni value = %d",value);
	value = value + 1;
	LOGI("jni value +1 = %d",value);
    return value;
  }


/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    createPerson
 * Signature: ()Ljava/lang/Object;
 */
JNIEXPORT jlong JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_createPerson
  (JNIEnv *env, jclass cls) {


    void *p = createPerson();

    return (jlong)p;
  }

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    destroyPerson
 * Signature: (Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_destroyPerson
  (JNIEnv *env, jclass cls, jlong o) {

      destroyPerson((void*)o);
  }

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    setPersonAge
 * Signature: (Ljava/lang/Object;I)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_setPersonAge
  (JNIEnv *env, jclass cls, jlong o, jint value) {
    setPersonAge((void*)o,value);
  }

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    personAge
 * Signature: (Ljava/lang/Object;)I
 */
JNIEXPORT jint JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_personAge
  (JNIEnv *env, jclass cls, jlong o) {
   return personAge((void*)o);
  }

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    setPersonName
 * Signature: (Ljava/lang/Object;Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_setPersonName
  (JNIEnv *env, jclass cls, jlong o, jstring string) {

    int length1 = (*env)->GetStringLength(env, string);
    const jchar * jcstr = (*env)->GetStringChars(env, string, NULL);


    LOGI("sJava_com_ksnowlv_hellojniforjava_JavaCallJNI_setPersonName1 = %s",jcstr);

    LOGI("sJava_com_ksnowlv_hellojniforjava_JavaCallJNI_setPersonName2 = %s",string);

     jclass   clsstring   =   (*env)->FindClass(env,"java/lang/String");  //String
     jstring   code   =   (*env)->NewStringUTF(env,"UTF-8"); //"UTF-8"
     jmethodID   methodID   =   (*env)->GetMethodID(env,clsstring,   "getBytes",   "(Ljava/lang/String;)[B"); //getBytes();
     jbyteArray   byteArray =   (jbyteArray)(*env)->CallObjectMethod(env,string,methodID,code);
     jsize   length   =   (*env)->GetArrayLength(env,byteArray);
     jbyte*   bytes   =   (*env)->GetByteArrayElements(env,byteArray,JNI_FALSE);


     if( length > 0){

        char* buf =   (char*)malloc(length+1);         //"\0"
        memcpy(buf,bytes,length);
        buf[length]=0;
        setPersonName((void*)o, buf);
        LOGI("set name = %s",buf);
        free(buf);
     }else{
        setPersonName((void*)o, NULL);
     }

     (*env)->ReleaseByteArrayElements(env,byteArray,bytes,0);  //释放内存空间
  }

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    personName
 * Signature: (Ljava/lang/Object;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_personName
  (JNIEnv *env, jclass cls, jlong o) {

    LOGI("jni get name");
    const char *name = personName((void*)o);

    if ( name != NULL ) {
        LOGI("jni name = %s",name);
        return  (*env)->NewStringUTF(env,name);
    }else {
        return (*env)->NewStringUTF(env,"");
    }
  }

  JNIEXPORT jobject JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument
    (JNIEnv *env, jclass cls,jbyteArray data, jint width, jint height) {

    //jbyte *bytesData= (*env)->GetByteArrayElements(env,data, 0);
    int bytesLen = (*env)->GetArrayLength(env,data);
    unsigned char* buf = (unsigned char*)malloc(bytesLen);
    (*env)->GetByteArrayRegion (env,data, 0, bytesLen, (jbyte *)buf);

    LOGI("Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument data = %s",buf);
    free(buf);

    LOGI("Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument width = %d height = %d",width,height);

    LOGI("jni Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument ");
    jclass imageInfoClass = (*env)->FindClass(env,"com/ksnowlv/hellojniforjava/XImageInfo");
    jmethodID construction_id = (*env)->GetMethodID(env,imageInfoClass,"<init>","()V");
    jobject imageInfoObject =  (*env)->NewObject(env, imageInfoClass, construction_id);

    LOGI("jni Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument1");
    jfieldID   field_imageData = (*env)->GetFieldID(env,imageInfoClass,"imageData","[B");
    jfieldID field_res = (*env)->GetFieldID(env,imageInfoClass,"res","I");

    LOGI("jni Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument2 ");
    (*env)->SetIntField(env,imageInfoObject,field_res,-1);

    LOGI("jni Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument3 ");

    const int resDataLen = 10;

    unsigned char *bytes = (unsigned char*)malloc(resDataLen);

    for(int i = 0;i < resDataLen; ++i ){
      bytes[i] = (unsigned char)i;
    }

    jbyteArray ret = (*env)->NewByteArray(env,resDataLen);
    (*env)->SetByteArrayRegion (env,ret, 0, resDataLen, (const jbyte*)bytes);
    (*env)->SetObjectField(env,imageInfoObject,field_imageData,ret);

    free(bytes);
    (*env)->DeleteLocalRef(env, ret);
    LOGI("jni Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument5 ");
    return imageInfoObject;
  }