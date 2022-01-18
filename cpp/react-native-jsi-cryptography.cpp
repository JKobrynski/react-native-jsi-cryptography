#include "react-native-jsi-cryptography.h"
#include <iostream>
#include "rsa.h"

//namespace example {
//	int multiply(float a, float b) {
//		return a * b;
//	}
//}

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
        
        rsa::runExample();
        
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
    
    rt.global().setProperty(rt, "jsiMultiplication", move(multiply));
};

void cleanUpCryptography() {
    
};
