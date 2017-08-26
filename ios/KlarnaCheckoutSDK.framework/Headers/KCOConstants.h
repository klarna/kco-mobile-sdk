//
//  KCOConstants.h
//  Pods
//
//  Created by Johan Rydenstam on 25/11/15.
//
//

#import <Foundation/Foundation.h>

/**
 *  Klarna checkout notifications
 *  Contains a userInfo payload where KCOSignalNameKey and KCOSignalDataKey might be set.
 *  @see KCOSignalNameKey
 *  @see KCOSignalDataKey
 */
FOUNDATION_EXPORT NSString * const KCOSignalNotification;

/**
 *  Key to get the name of the signal from the userInfo object for example, 'change', 'complete'
 *  NSString *name = notification.userInfo[KCOSignalNameKey];
 */
FOUNDATION_EXPORT NSString * const KCOSignalNameKey;

/**
 *  Key to get the data of the signal from the userInfo object.
 *  This key will contain an NSDictionary or nil
 */
FOUNDATION_EXPORT NSString * const KCOSignalDataKey;
