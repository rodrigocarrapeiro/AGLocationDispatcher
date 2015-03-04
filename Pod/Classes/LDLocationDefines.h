//
//  LDLocationDefines.h
//  LocationDispatch
//
//  Created by Vladimir Zgonik on 09.02.15.
//  Copyright (c) 2015 Agilie. All rights reserved.
//

#import "LDLocation.h"

#ifndef LocationDispatch_LDLocationDefines_h
#define LocationDispatch_LDLocationDefines_h

static NSString *const kAlertAuthorizationMsg = @"Warning! Unable to find %@ in Info.plist.  \
CLLocationManager requires that %@ be set in \
the Info.plist in order to function correctly.  \
Please consult the Apple Developer documentation titled \
\"Information Property List Key Reference.\"";

static NSString *const kNSLocationWhenInUseUsageDescription = @"NSLocationWhenInUseUsageDescription";
static NSString *const kNSLocationAlwaysUsageDescription = @"NSLocationAlwaysUsageDescription";
static NSString *const LDLocationServiceUserLocationDidChangeNotification = @"RCLocationManagerUserLocationDidChangeNotification";
static NSString *const LDLocationServiceNotificationLocationUserInfoKey = @"newLocation";

static NSTimeInterval const kLDLocationUpdateIntervalOneSec = 1.f; // in seconds
static NSTimeInterval const kLDLocationUpdateIntervalTenSec = 10.f; // in seconds
static NSTimeInterval const kLDLocationUpdateIntervalOneMinute = 60.f; // in seconds
static NSTimeInterval const kLDLocationUpdateInterval15Minutes = 15.f * 60.f; // in seconds
static NSTimeInterval const kLDLocationUpdateInterval60Minutes = 60.f * 60.f; // in seconds

static CGFloat const kLDHorizontalAccuracyCity = 5000.f;  // in meters
static CGFloat const kLDHorizontalAccuracyNeighborhood = 1000.f;  // in meters
static CGFloat const kLDHorizontalAccuracyBlock = 100.f;  // in meters
static CGFloat const kLDHorizontalAccuracyHouse = 15.f;  // in meters
static CGFloat const kLDHorizontalAccuracyRoom = 5.f;  // in meters

static NSTimeInterval const kLDUpdateIntervalCity = 600.f;  // in seconds
static NSTimeInterval const kLDUpdateIntervalNeighborhood = 300.f;  // in seconds
static NSTimeInterval const kLDUpdateIntervalBlock = 60.f;  // in seconds
static NSTimeInterval const kLDUpdateIntervalHouse = 15.f;  // in seconds
static NSTimeInterval const kLDUpdateIntervalRoom = 5.f;  // in seconds

typedef NS_ENUM (NSInteger, LDLocationUpdateInterval) {
    LDLocationUpdateIntervalOneSec,
    LDLocationUpdateIntervalTenSec,
    LDLocationUpdateIntervalOneMinute,
    LDLocationUpdateInterval15Minutes,
    LDLocationUpdateInterval60Minutes
};

typedef enum {
    // 'None' is not valid as a desired accuracy.
    /** Inaccurate (>5000 meters, and/or received >10 minutes ago). */
            LDLocationAccuracyNone = 0,
    // The below options are valid desired accuracies.
    /** 5000 meters or better, and received within the last 10 minutes. Lowest accuracy. */
            LDLocationAccuracyCity,
    /** 1000 meters or better, and received within the last 5 minutes. */
            LDLocationAccuracyNeighborhood,
    /** 100 meters or better, and received within the last 1 minute. */
            LDLocationAccuracyBlock,
    /** 15 meters or better, and received within the last 15 seconds. */
            LDLocationAccuracyHouse,
    /** 5 meters or better, and received within the last 5 seconds. Highest accuracy. */
            LDLocationAccuracyRoom
} LDLocationAccuracy;

typedef enum {
    // These statuses will accompany a valid location.
    /** Got a location and desired accuracy level was achieved successfully. */
            LDLocationStatusSuccess = 0,
    /** Got a location, but the desired accuracy level was not reached before timeout. (Not applicable to subscriptions.) */
            LDLocationStatusTimedOut,
    // These statuses indicate some sort of error, and will accompany a nil location.
    /** User has not responded to the permissions dialog. */
            LDLocationStatusServicesNotDetermined,
    /** User has explicitly denied this app permission to access location services. */
            LDLocationStatusServicesDenied,
    /** User does not have ability to enable location services (e.g. parental controls, corporate policy, etc). */
            LDLocationStatusServicesRestricted,
    /** User has turned off device-wide location services from system settings. */
            LDLocationStatusServicesDisabled,
    /** An error occurred while using the system location services. */
            LDLocationStatusError
} LDLocationStatus;

#endif