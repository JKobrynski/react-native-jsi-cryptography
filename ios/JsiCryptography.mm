#import "JsiCryptography.h"
#import "react-native-jsi-cryptography.h"

#import <React/RCTBridge+Private.h>
#import <jsi/jsi.h>

#import <React/RCTUtils.h>
#import <ReactCommon/CallInvoker.h>

#import <memory>

@implementation JsiCryptography

@synthesize bridge = _bridge;

RCT_EXPORT_MODULE()

+ (BOOL)requiresMainQueueSetup {
    return YES;
}

- (void)setBridge:(RCTBridge *)bridge {
    _bridge = bridge;
    _setBridgeOnMainQueue = RCTIsMainQueue();

    RCTCxxBridge *cxxBridge = (RCTCxxBridge *)self.bridge;

    if(!cxxBridge.runtime) {
        return;
    }    

    installCryptography(*(facebook::jsi::Runtime *)cxxBridge.runtime);
}

// // Example method for C++
// // See the implementation of the example module in the `cpp` folder
// RCT_EXPORT_METHOD(multiply:(nonnull NSNumber*)a withB:(nonnull NSNumber*)b
//                   withResolver:(RCTPromiseResolveBlock)resolve
//                   withReject:(RCTPromiseRejectBlock)reject)
// {
//     NSNumber *result = @(example::multiply([a floatValue], [b floatValue]));

//     resolve(result);
// }

- (void)invalidate {
    cleanUpCryptography();
}

@end
