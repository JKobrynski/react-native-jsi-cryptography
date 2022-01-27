#include "react-native-jsi-cryptography.h"
#include "rsa.h"
#include "sha1.h"
//#include "md5.h"
#include "cryptography.h"
#include <iostream>
#include <string>

using namespace facebook;
using namespace std;

void installCryptography(jsi::Runtime &rt) {
    cout << "Install JSI bindings" << endl;
    
    auto multiplyLambda = [](jsi::Runtime &rt, const jsi::Value &thisValue, const jsi::Value *args, size_t count) -> jsi::Value {
        
        // throw an error
        if(count > 2) {
            jsi::detail::throwJSError(rt, "Too many argumnents");
        };
        
        // cast to basic types
        if(!args[0].isNumber()) {
            jsi::detail::throwJSError(rt, "Arg 1 is not a number");
        }
        
        double arg1 = args[0].asNumber();
        int intArg1 = (int)arg1;
        
        if(!args[1].isNumber()) {
            jsi::detail::throwJSError(rt, "Arg 2 is not a number");
        }
        
        double arg2 = args[1].asNumber();
        int intArg2 = (int)arg2;
        
        int result = intArg1 * intArg2;
        
        // cast to string
//        string argString = args[0].asString(rt).utf8(rt);
        
        // cast to object
//        jsi::Object obj = args[0].asObject(rt);
//        obj.getProperty(rt, "foo");
//        obj.setProperty(rt, "foo", jsi::Value(43));
        
        // In JavaScript arrays are just objects
//        jsi::Array arr = args[0].asObject(rt).asArray(rt);
//        auto size = arr.size(rt);
//        auto elem = arr.getValueAtIndex(rt, 0);
        
        // create basic values
//        jsi::Value res = jsi::Value(result);
        
        // create null value
//        jsi::Value res = jsi::Value(nullptr);
        
        // creating undefined value
//        jsi::Value res = jsi::Value::undefined();
        
        // create array
//        jsi::Array arrayRes = jsi::Array(rt, 20);
//        arrayRes.setValueAtIndex(rt, 0, jsi::Value(42));
        
        // create object
//        jsi::Object obj = jsi::Object();
//        obj.setProperty(rt, "foo", jsi::Value(42));
        
        return jsi::Value(result);
    };
    
    jsi::Function multiply = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "multiply"), 0, multiplyLambda);
    
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
        string hashed = cryptography::md5(argString);

        return jsi::Value(jsi::String::createFromUtf8(rt, hashed));
    };

    jsi::Function md5Host = jsi::Function::createFromHostFunction(rt, jsi::PropNameID::forAscii(rt, "md5"), 0, md5Lambda);
    
    rt.global().setProperty(rt, "jsiMultiplication", move(multiply));
    rt.global().setProperty(rt, "encryptMessage", move(encryptMessage));
    rt.global().setProperty(rt, "decryptMessage", move(decryptMessage));
    rt.global().setProperty(rt, "sha1", move(sha1Host));
    rt.global().setProperty(rt, "md5", move(md5Host));
};

void cleanUpCryptography() {
    
};
