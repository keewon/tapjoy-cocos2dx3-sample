# Tapjoy integration sample for Cocos2d-x 3.x

 - Tapjoy library is not included. (Visit http://dev.tapjoy.com/ )
 - cocos2d directory is not included. (Visit http://cocos2d-x.org/ )

## Build instruction
 1. Make new cocos project or copy cocos dir into this repository


    cocos new tapjoy-cocos2dx3-sample -p com.tapjoy.sample.cocos2dx3 -l cpp

 2. (Android) Place TapjoySDK for android


    unzip TapjoySDK_Android_vx.x.x.zip

    mv TapjoySDK_Android_vx.x.x tapjoy-cocos2dx3-sample/proj.android/

    cd tapjoy-cocos2dx3-sample/proj.android/

    mv TapjoySDK_Android_vx.x.x TapjoySDK

 3. (iOS) Place TapjoySDK for iOS


    unzip TapjoySDK_iOS_vx.x.x.zip

    mv TapjoySDK_iOS_vx.x.x tapjoy-cocos2dx3-sample/proj.ios_mac/

    cd tapjoy-cocos2dx3-sample/proj.ios_mac/

    mv TapjoySDK_iOS_vx.x.x TapjoySDK

## Run
### Android

    cocos run -p android

### iOS

    cocos run -p ios

Note that this is an unofficial sample.
