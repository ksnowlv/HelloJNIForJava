

LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := JNITest
LOCAL_SRC_FILES := com_ksnowlv_hellojniforjava_JavaCallJNI.c Person.cpp  PersonExtension.cpp
LOCAL_LDLIBS:=-L$(SYSROOT)/usr/lib -llog

include $(BUILD_SHARED_LIBRARY)


APP_STL = c++_static