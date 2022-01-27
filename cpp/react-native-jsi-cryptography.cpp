#include "react-native-jsi-cryptography.h"
#include "rsa.h"
#include "sha1.h"
#include "md5.h"
#include "sha224.h"
#include <iostream>
#include <string>

using namespace facebook;
using namespace std;

void installCryptography(jsi::Runtime &rt) {
    cout << "Install JSI bindings" << endl;
    
    auto encryptLambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        double message = args[0].asNumber();
        
        double encrypted = rsa::encryptMessage(message);
        
        cout << encrypted << endl;
        
        return jsi::Value(encrypted);
    };
    
    jsi::Function encryptMessage = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "encryptMessage"), 0, encryptLambda);
    
    auto decryptLambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        double encrypted = args[0].asNumber();
        
        double decrypted = rsa::decryptMessage(encrypted);
        
        cout << "DECRYPTED: " << decrypted << endl;
        
        return jsi::Value(decrypted);
    };
    
    jsi::Function decryptMessage = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "decryptMessage"), 0, decryptLambda);
    
    auto sha1Lambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        string argString = args[0].asString(rt).utf8(rt);
        string hashed = sha1::hash(argString);
        
        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };
    
    jsi::Function sha1Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "sha1"), 0, sha1Lambda);
    
    auto md5Lambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        string argString = args[0].asString(rt).utf8(rt);
        string hashed = md5::hash(argString);
        
        cout << sha224::hash("grape") << endl;

        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };

    jsi::Function md5Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "md5"), 0, md5Lambda);
    
    auto sha224Lambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        string argString = args[0].asString(rt).utf8(rt);
        string hashed = sha224::hash(argString);

        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };

    jsi::Function sha224Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "sha224"), 0, sha224Lambda);
    
    rt.global().setProperty(rt, "encryptMessage", move(encryptMessage));
    rt.global().setProperty(rt, "decryptMessage", move(decryptMessage));
    rt.global().setProperty(rt, "sha1", move(sha1Host));
    rt.global().setProperty(rt, "md5", move(md5Host));
    rt.global().setProperty(rt, "sha224", move(sha224Host));
};

void cleanUpCryptography() {
    
};
