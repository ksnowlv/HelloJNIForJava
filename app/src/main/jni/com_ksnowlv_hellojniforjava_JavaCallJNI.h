/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_ksnowlv_hellojniforjava_JavaCallJNI */

#ifndef _Included_com_ksnowlv_hellojniforjava_JavaCallJNI
#define _Included_com_ksnowlv_hellojniforjava_JavaCallJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    showValue
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_showValue
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    createPerson
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_createPerson
  (JNIEnv *, jclass);

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    destroyPerson
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_destroyPerson
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    setPersonAge
 * Signature: (JI)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_setPersonAge
  (JNIEnv *, jclass, jlong, jint);

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    personAge
 * Signature: (J)I
 */
JNIEXPORT jint JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_personAge
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    setPersonName
 * Signature: (JLjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_setPersonName
  (JNIEnv *, jclass, jlong, jstring);

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    personName
 * Signature: (J)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_personName
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_ksnowlv_hellojniforjava_JavaCallJNI
 * Method:    extractDocument
 * Signature: ([BII)Lcom/ksnowlv/hellojniforjava/XImageInfo;
 */
JNIEXPORT jobject JNICALL Java_com_ksnowlv_hellojniforjava_JavaCallJNI_extractDocument
  (JNIEnv *, jclass, jbyteArray, jint, jint);

#ifdef __cplusplus
}
#endif
#endif
