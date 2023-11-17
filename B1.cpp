#include <jni.h>
#include <iostream>
#include "B1.h"

using namespace std;

JNIEXPORT jint JNICALL Java_B1_add(JNIEnv *env, jobject obj, jint a, jint b) {
    jint result = a + b;
    cout << a << " + " << b << " = " << result << endl;
    return result;
}
