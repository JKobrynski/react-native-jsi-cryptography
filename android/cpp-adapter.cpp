#include <jni.h>
#include "react-native-jsi-cryptography.h"

extern "C" JNIEXPORT void JNICALL
Java_com_reactnativejsicryptography_JsiCryptographyModule_initialize(JNIEnv *env, jclass clazz, jlong jsiPtr)
{
  installCryptography(*reinterpret_cast<facebook::jsi::Runtime *>(jsiPtr));
}

extern "C" JNIEXPORT void JNICALL
Java_com_reactnativejsicryptography_JsiCryptographyModule_destruct(JNIEnv *env, jclass clazz)
{
  cleanUpCryptography();
}
