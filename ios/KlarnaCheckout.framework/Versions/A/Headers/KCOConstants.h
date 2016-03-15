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
 *  Contains a userInfo payload where KCOSignalNameKey and KCOSignalArgsKey might be set.
 *  @see KCOSignalNameKey
 *  @see KCOSignalArgsKey
 */
FOUNDATION_EXPORT NSString * const KCOSignalNotification;

/**
 *  Key to get the name of the signal from the userInfo object for example, 'change', 'complete'
 *  NSString *name = notification.userInfo[KCOSignalNameKey];
 */
FOUNDATION_EXPORT NSString * const KCOSignalNameKey;

/**
 *  Key to get the arguments of the signal from the userInfo object.
 *  What this contains depends on what type of signal it is.
 */
FOUNDATION_EXPORT NSString * const KCOSignalArgsKey;
