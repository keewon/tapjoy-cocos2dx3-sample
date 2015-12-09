//
//  TapjoyIntegration.cpp
//  TapjoySampleGame
//
//  Created by Keewon Seo on 2015. 1. 28..
//
//

#include "TapjoyIntegration.h"

#include "cocos2d.h"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include <jni.h>
#endif

#define COCOS2D_DEBUG 1

USING_NS_CC;
using namespace tapjoy;

static TJPlacementHandle p1;

static MyTJConnectListener connectListener;
static MyTJPlacementListener placementListener;
static MyEarnedCurrencyListener earnedCurrencyListener;
static MyGetCurrencyBalanceListener getCurrencyBalanceListener;
static MyVideoListener videoListener;

// MyTJConnectListener

void MyTJConnectListener::onConnectSuccess() {
    CCLOG("Tapjoy::onConnectSuccess");
    
    
    TJPlacementHandle placementHandle = TJPlacement::create("test_unit", &placementListener);
    TJPlacement::requestContent(placementHandle);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    Tapjoy::trackPurchaseInGooglePlayStore("{\"title\":\"TITLE\",\"price\":\"$3.33\",\"type\":\"inapp\",\"description\":\"DESC\",\"price_amount_micros\":3330000,\"price_currency_code\":\"USD\",\"productId\":\"3\"}", "{\"orderId\":\"123.456\",\"packageName\":\"com.tapjoy.easyapp.iaptest\",\"productId\":\"test_item_01\",\"purchaseTime\": 1234567890,\"purchaseState\":0,\"developerPayload\":\"bGoa+V7g/yqDXvKRqq+JTFn4uQZbPiQJo4pf9RzJ\",\"purchaseToken\":\"opaque-token-up-to-1000-characters\"}", "AAAA", 0);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    Tapjoy::trackPurchaseInAppleAppStore("productId", "currencyCode", 3.33, "transactionId", NULL);
#endif
};

void MyTJConnectListener::onConnectFailure() {
    CCLOG("Tapjoy::onConnectFailure");
};

// MyTJPlacementListener

void MyTJPlacementListener::onRequestSuccess(tapjoy::TJPlacementHandle placementHandle, const char* placementName) {
    CCLOG("%s %s available:%d ready:%d", __FUNCTION__, placementName,
        TJPlacement::isContentAvailable(placementHandle),
        TJPlacement::isContentReady(placementHandle)
        );
}

void MyTJPlacementListener::onRequestFailure(tapjoy::TJPlacementHandle placementHandle, const char* placementName, int errorCode, const char* errorMessage) {
    CCLOG("%s %s", __FUNCTION__, placementName);
}

void MyTJPlacementListener::onContentReady(tapjoy::TJPlacementHandle placementHandle, const char* placementName) {
    CCLOG("%s %s", __FUNCTION__, placementName);
    if (TJPlacement::isContentAvailable(placementHandle) && TJPlacement::isContentReady(placementHandle)) {
        TJPlacement::showContent(placementHandle);
        TJPlacement::isContentReady(placementHandle);
    }
}

void MyTJPlacementListener::onContentShow(tapjoy::TJPlacementHandle placementHandle, const char* placementName) {
    CCLOG("%s %s", __FUNCTION__, placementName);
}

void MyTJPlacementListener::onContentDismiss(tapjoy::TJPlacementHandle placementHandle, const char* placementName) {
    CCLOG("%s %s", __FUNCTION__, placementName);
}

void MyTJPlacementListener::onPurchaseRequest(tapjoy::TJPlacementHandle placementHandle, const char* placementName, tapjoy::TJActionRequestHandle requestHandle, const char* requestId, const char* requestToken, const char* productId) {
    CCLOG("%s %s", __FUNCTION__, placementName);
}

void MyTJPlacementListener::onRewardRequest(tapjoy::TJPlacementHandle placementHandle, const char* placementName, tapjoy::TJActionRequestHandle requestHandle, const char* requestId, const char* requestToken, const char* itemId, int quantity) {
    CCLOG("%s %s", __FUNCTION__, placementName);
}

void MyTJPlacementListener::onCurrencyRequest(tapjoy::TJPlacementHandle placementHandle, const char* placementName, tapjoy::TJActionRequestHandle requestHandle, const char* requestId, const char* requestToken, const char* currency, int amount) {
    CCLOG("%s %s", __FUNCTION__, placementName);
}

void MyTJPlacementListener::onNavigationRequest(tapjoy::TJPlacementHandle placementHandle, const char* placementName, tapjoy::TJActionRequestHandle requestHandle, const char* requestId, const char* requestToken, const char* location) {
    CCLOG("%s %s", __FUNCTION__, placementName);
}

void MyGetCurrencyBalanceListener::onGetCurrencyBalanceResponse(const char* currencyName, int balance) {
    CCLOG("%s %s %d", __FUNCTION__, currencyName, balance);
}

void MyGetCurrencyBalanceListener::onGetCurrencyBalanceResponseFailure(const char* error) {
    CCLOG("%s error:%s", __FUNCTION__, error);
}

void MyEarnedCurrencyListener::onEarnedCurrency(const char* currencyName, int amount) {
    CCLOG("%s %s %d", __FUNCTION__, currencyName, amount);
}

void MyVideoListener::onVideoStart() {
    CCLOG("%s", __FUNCTION__);
}

void MyVideoListener::onVideoClose() {
    CCLOG("%s", __FUNCTION__);
}

void MyVideoListener::onVideoError(int statusCode) {
    CCLOG("%s %d", __FUNCTION__, statusCode);
}

void MyVideoListener::onVideoComplete() {
    CCLOG("%s", __FUNCTION__);
}

///////
#pragma mark TapjoyIntegration

namespace TapjoyIntegration {
    void init() {
        Tapjoy::setDebugEnabled(true);

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
        // EasyApp iOS
        Tapjoy::connect("E7CuaoUWRAWdz_5OUmSGsgEBXHdOwPa8de7p4aseeYP01mecluf-GfNgtXlF", &connectListener);
#elif (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
        // EasyApp Android
        Tapjoy::connect("u6SfEbh_TA-WMiGqgQ3W8QECyiQIURFEeKm0zbOggubusy-o5ZfXp33sTXaD", &connectListener);
#endif
        
        Tapjoy::setEarnedCurrencyListener(&earnedCurrencyListener);
        Tapjoy::setVideoListener(&videoListener);
    }
    
    void getCurrencyBalance() {
        Tapjoy::getCurrencyBalance(&getCurrencyBalanceListener);
    }
    
    void showOffers() {
        //Tapjoy::showOffers(&offersListener);
    }
    
    void requestPlacement() {
        p1 = TJPlacement::create("test_unit", &placementListener);
        TJPlacement::requestContent(p1);
    }
}

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
extern "C" void Java_org_cocos2dx_cpp_AppActivity_setActivity(JNIEnv* jenv, jobject thiz) {
  static jobject context = jenv->NewGlobalRef(thiz);
  Tapjoy::setContext(context);
}
#endif
