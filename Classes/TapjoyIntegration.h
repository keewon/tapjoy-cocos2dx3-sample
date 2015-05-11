//
//  TapjoyIntegration.h
//  TapjoySampleGame
//
//  Created by Keewon Seo on 2015. 1. 28..
//
//

#ifndef __TapjoySampleGame__TapjoyIntegration__
#define __TapjoySampleGame__TapjoyIntegration__

#include <stdio.h>
#include "cocos2d.h"

#include "Tapjoy/TapjoyCpp.h"


namespace TapjoyIntegration {
    void init();
    void getCurrencyBalance();
    void showOffers();
    void requestPlacement();
}


class MyTJConnectListener : public tapjoy::TJConnectListener {
    virtual void onConnectSuccess();
    virtual void onConnectFailure();
};

class MyTJPlacementListener : public tapjoy::TJPlacementListener {
    virtual void onRequestSuccess(tapjoy::TJPlacementHandle placementHandle, const char* placementName);
    virtual void onRequestFailure(tapjoy::TJPlacementHandle placementHandle, const char* placementName, int errorCode, const char* errorMessage);
    virtual void onContentReady(tapjoy::TJPlacementHandle placementHandle, const char* placementName);
    virtual void onContentShow(tapjoy::TJPlacementHandle placementHandle, const char* placementName);
    virtual void onContentDismiss(tapjoy::TJPlacementHandle placementHandle, const char* placementName);
    virtual void onPurchaseRequest(tapjoy::TJPlacementHandle placementHandle, const char* placementName, tapjoy::TJActionRequestHandle requestHandle, const char* requestId, const char* requestToken, const char* productId);
    virtual void onRewardRequest(tapjoy::TJPlacementHandle placementHandle, const char* placementName, tapjoy::TJActionRequestHandle requestHandle, const char* requestId, const char* requestToken, const char* itemId, int quantity);
    virtual void onCurrencyRequest(tapjoy::TJPlacementHandle placementHandle, const char* placementName, tapjoy::TJActionRequestHandle requestHandle, const char* requestId, const char* requestToken, const char* currency, int amount);
    virtual void onNavigationRequest(tapjoy::TJPlacementHandle placementHandle, const char* placementName, tapjoy::TJActionRequestHandle requestHandle, const char* requestId, const char* requestToken, const char* location);
};

class MyGetCurrencyBalanceListener : public tapjoy::TJGetCurrencyBalanceListener {
    virtual void onGetCurrencyBalanceResponse(const char* currencyName, int balance);
    virtual void onGetCurrencyBalanceResponseFailure(const char* error);
};

class MyEarnedCurrencyListener : public tapjoy::TJEarnedCurrencyListener {
    virtual void onEarnedCurrency(const char* currencyName, int amount);
};

class MyOffersListener : public tapjoy::TJOffersListener {
    virtual void onOffersResponse();
};

class MyVideoListener : public tapjoy::TJVideoListener {
    virtual void onVideoStart();
    virtual void onVideoClose();
    virtual void onVideoError(int statusCode);
    virtual void onVideoComplete();
};

class MyViewListener : public tapjoy::TJViewListener {
    virtual void onViewWillClose(int viewType);
    virtual void onViewDidClose(int viewType);
    virtual void onViewWillOpen(int viewType);
    virtual void onViewDidOpen(int viewType);
};

#endif /* defined(__TapjoySampleGame__TapjoyIntegration__) */
