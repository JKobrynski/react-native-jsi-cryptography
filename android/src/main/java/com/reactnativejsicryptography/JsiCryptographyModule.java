package com.reactnativejsicryptography;

import androidx.annotation.NonNull;

import com.facebook.react.bridge.Promise;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.module.annotations.ReactModule;

public class JsiCryptographyModule extends ReactContextBaseJavaModule {
    static {
        System.loadLibrary("jsi-cryptography");
    }

    private static native void initialize(long jsiPtr, String docDir);
    private static native void destruct();

    public JsiCryptographyModule(ReactApplicationContext reactContext) {
        super(reactContext);
    }

    @NonNull
    @Override
    public String getName() {
        return "JsiCryptography";
    }

    @NonNull
    @Override
    public void initialize() {
        super.initialize();

        JsiCryptographyModule.initialize(
            this.getReactApplicationContext().getJavaScriptContextHolder().get(),
            this.getReactApplicationContext().getFilesDir().getAbsolutePath()
        );
    }

    @Override
    public void onCatalystInstanceDestroy() {
        JsiCryptographyModule.destruct();
    }
}
