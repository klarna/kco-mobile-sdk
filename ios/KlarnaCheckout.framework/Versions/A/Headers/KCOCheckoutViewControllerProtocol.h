//
//  KCOCheckoutViewControllerProtocol.h
//  Pods
//
//  Created by Johan Rydenstam on 11/11/15.
//
//

#import <Foundation/Foundation.h>

@protocol KCOCheckoutSizingDelegate, KCOCheckoutDelegate;
@protocol KCOCheckoutViewControllerProtocol <NSObject>

/**
 * Disables the checkout scroll. Use this is you want to embedd it into
 * a wrapping scroll view and make sure to set 'sizingDelegate' to give the
 * checkout the possibility to scroll the parent scroll view.
 * Default value is NO.
 */
@property (nonatomic, assign) BOOL internalScrollDisabled;

/**
 * Make sure to set sizingDelegate when using it in a child view controller.
 * If you are embeddning the view in a scrollView you should also disable internal scroll,
 * otherwise setting this delegate won't have any effect.
 */
@property (nonatomic, weak) id<KCOCheckoutSizingDelegate> sizingDelegate;

/**
 * Returns the current height of the checkout. Use this to set an initial value for the height
 * when embeddning the checkout in a parent view controller.
 */
@property (nonatomic, readonly) NSUInteger currentCheckoutHeight;

/**
 *  Suspend the current checkout flow
 */
- (void)suspend;

/**
 *  Resume a suspended checkout flow
 */
- (void)resume;

@end
