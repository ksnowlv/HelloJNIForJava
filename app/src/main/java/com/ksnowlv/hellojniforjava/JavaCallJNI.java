package com.ksnowlv.hellojniforjava;

public class JavaCallJNI {

    static  {
        System.loadLibrary("JNITest");
    }


    public static native int showValue(int value);

    public static native long  createPerson();
    public static native void destroyPerson(long person);
    public static native void setPersonAge(long person,  int age);
    public static native int personAge(long person);
    public static native void setPersonName(long person, String name);
    public static native String  personName(long person);
    public static native XImageInfo extractDocument(byte[] data, int imageWidth, int imageHeight);

}
