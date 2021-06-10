package com.ksnowlv.hellojniforjava;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

import java.io.UnsupportedEncodingException;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        int value =  JavaCallJNI.showValue(1);
        Log.i("------Android ","" + value);

        long p =  JavaCallJNI.createPerson();
        JavaCallJNI.setPersonAge(p,10);
        int age = JavaCallJNI.personAge(p);
        Log.i("------Android ","" + age);
        JavaCallJNI.setPersonName(p,"ksnowlv(律威)");
        String name = JavaCallJNI.personName(p);
        Log.i("------Android ",name);
        JavaCallJNI.destroyPerson(p);

        String text = "hello";
        byte[] bytes = new byte[0];
        try {
            bytes = text.getBytes("UTF-8");
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }

        XImageInfo info = JavaCallJNI.extractDocument(bytes,10,20);
        Log.i("------Android ","" +info.res);


    }
}
