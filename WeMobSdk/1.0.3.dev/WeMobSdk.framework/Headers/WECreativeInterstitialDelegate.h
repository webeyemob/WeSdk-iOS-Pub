//
//  WECreativeInterstitialDelegate.h
//  WeDSPDemo
//
//  Created by 汤正 on 2019/6/14.
//  Copyright © 2019 WE. All rights reserved.
//

#ifndef WECreativeInterstitialDelegate_h
#define WECreativeInterstitialDelegate_h

#import <Foundation/Foundation.h>
#import "WeCreativeAdError.h"


@class WECreativeInterstitial;

@protocol WECreativeInterstitialDelegate <NSObject>

@required

- (void)impressionTrack:(WECreativeInterstitial *)view;
- (void)clickTrack:(WECreativeInterstitial *)view;

@optional

#pragma mark Ad Request Lifecycle Notifications

/// Called when an interstitial ad request succeeded. Show it at the next transition point in your
/// application such as when transitioning between view controllers.
- (void)interstitialAdDidLoad:(WECreativeInterstitial *)ad;

/// Called when an interstitial ad request completed without an interstitial to
/// show. This is common since interstitials are shown sparingly to users.
- (void)interstitial:(WECreativeInterstitial *)ad didLoadedFailWithError:(WeCreativeAdError *)error;

#pragma mark Display-Time Lifecycle Notifications

/// Called just before presenting an interstitial. After this method finishes the interstitial will
/// animate onto the screen. Use this opportunity to stop animations and save the state of your
/// application in case the user leaves while the interstitial is on screen (e.g. to visit the App
/// Store from a link on the interstitial).
- (void)interstitialWillPresentScreen:(WECreativeInterstitial *)ad;

/// Called when |ad| did to present.
- (void)interstitialDidPresentScreen:(WECreativeInterstitial *)ad;

/// Called before the interstitial is to be animated off the screen.
- (void)interstitialWillDismissScreen:(WECreativeInterstitial *)ad;

/// Called just after dismissing an interstitial and it has animated off the screen.
- (void)interstitialDidDismissScreen:(WECreativeInterstitial *)ad;

/// Called just before the application will background or terminate because the user clicked on an
/// ad that will launch another application (such as the App Store). The normal
/// UIApplicationDelegate methods, like applicationDidEnterBackground:, will be called immediately
/// before this.
- (void)interstitialWillLeaveApplication:(WECreativeInterstitial *)ad;

@end

#endif /* WECreativeInterstitialDelegate_h */