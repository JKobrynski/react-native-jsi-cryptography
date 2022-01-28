#include "react-native-jsi-cryptography.h"
#include "sha1.h"
#include "md5.h"
#include "sha224.h"
#include "sha256.h"
#include "sha384.h"
#include <iostream>
#include <string>

using namespace facebook;
using namespace std;

void installCryptography(jsi::Runtime &rt) {
    cout << "Install JSI bindings" << endl;
    
    auto sha1Lambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        string argString = args[0].asString(rt).utf8(rt);
        string hashed = sha1::hash(argString);
        
        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };
    
    jsi::Function sha1Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "sha1"), 0, sha1Lambda);
    
    auto md5Lambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        string argString = args[0].asString(rt).utf8(rt);
        string hashed = md5::hash(argString);

        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };

    jsi::Function md5Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "md5"), 0, md5Lambda);
    
    auto sha224Lambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        string argString = args[0].asString(rt).utf8(rt);
        string hashed = sha224::hash(argString);

        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };

    jsi::Function sha224Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "sha224"), 0, sha224Lambda);
    
    auto sha256Lambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        string argString = args[0].asString(rt).utf8(rt);
        string hashed = sha256::hash(argString);

        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };

    jsi::Function sha256Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "sha256"), 0, sha256Lambda);
    
    auto sha384Lambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        string argString = args[0].asString(rt).utf8(rt);
        string hashed = sha384::hash(argString);

        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };

    jsi::Function sha384Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "sha384"), 0, sha384Lambda);
    
    rt.global().setProperty(rt, "sha1", move(sha1Host));
    rt.global().setProperty(rt, "md5", move(md5Host));
    rt.global().setProperty(rt, "sha224", move(sha224Host));
    rt.global().setProperty(rt, "sha256", move(sha256Host));
    rt.global().setProperty(rt, "sha384", move(sha384Host));
};

void cleanUpCryptography() {
    
};
