//
//  KCOKlarnaCheckout.h
//  Pods
//
//  Created by Johan Rydenstam on 11/11/15.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#import "KCOCheckoutViewControllerProtocol.h"

/**
 *  Instantiate a checkout and set snippet to start a checkout load.
 *  Use this method if you have your own way of obtaining a klarna checkout snippet.
 *  If you want to use an existing store inside a webview, use KCOCheckoutController instead.
 *  @see KCOCheckoutController.
 */
@interface KCOKlarnaCheckout : NSObject

/**
 *  Html snippet containing to start the Klarna checkout.
 */
@property (nonatomic, strong) NSString *snippet;

/**
 *  ViewController containing the checkout.
 *  To display either add it as a child view controller 
 *  and implement the sizing delegate, and turn of internal scrolling
 *  or simply push it to your navigation stack.
 *
 *  @see KCOCheckoutViewControllerProtocol
 */
@property (nonatomic, readonly) UIViewController<KCOCheckoutViewControllerProtocol> *checkoutViewController;

/**
 *  Suspend the current checkout flow
 */
- (void)suspend;

/**
 *  Resume a suspended checkout flow
 */
- (void)resume;

@end
