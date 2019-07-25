//
//  WeMobCreativeNativeAdDelegate.h

//
//  Created by tamefox on 2019/6/19.
//  Copyright © 2019 WeMob. All rights reserved.
//



#ifndef WeMobCreativeNativeAdDelegate_h
#define WeMobCreativeNativeAdDelegate_h


#import "WeMobCreativeAdError.h"


@class WeMobCreativeNativeAd;

/// Identifies native ad assets.
@protocol WeMobCreativeNativeAdDelegate <NSObject>

@required

- (void)clickTrack:(WeMobCreativeNativeAd *)view;

- (void)impressionTrack:(WeMobCreativeNativeAd *)view;


@optional

/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)nativeAdDidLoad:(WeMobCreativeNativeAd *)ad;

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)native:(WeMobCreativeNativeAd *)ad didLoadedFailWithError:(WeMobCreativeAdError *)error;

#pragma mark Click-Time Lifecycle Notifications

/// Called just before presenting the user a full screen view, such as a browser, in response to
/// clicking on an ad. Use this opportunity to stop animations, time sensitive interactions, etc.
///
/// Normally the user looks at the ad, dismisses it, and control returns to your application with
/// the nativeAdDidDismissScreen: message. However, if the user hits the Home button or clicks on an
/// App Store link, your application will end. The next method called will be the
/// applicationWillResignActive: of your UIApplicationDelegate object.Immediately after that,
/// nativeAdWillLeaveApplication: is called.
- (void)nativeAdWillPresentScreen:(WeMobCreativeNativeAd *)nativeAd;

/// Called just before dismissing a full screen view.
- (void)nativeAdWillDismissScreen:(WeMobCreativeNativeAd *)nativeAd;

/// Called just after dismissing a full screen view. Use this opportunity to restart anything you
/// may have stopped as part of nativeAdWillPresentScreen:.
- (void)nativeAdDidDismissScreen:(WeMobCreativeNativeAd *)nativeAd;

/// Called just before the application will go to the background or terminate due to an ad action
/// that will launch another application (such as the App Store). The normal UIApplicationDelegate
/// methods, like applicationDidEnterBackground:, will be called immediately before this.
- (void)nativeAdWillLeaveApplication:(WeMobCreativeNativeAd *)nativeAd;

@end


#endif /* WeMobCreativeNativeAdDelegate_h */