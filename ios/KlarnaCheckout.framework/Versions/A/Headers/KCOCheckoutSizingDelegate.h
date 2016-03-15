//
//  KCOCheckoutSizingDelegate.h
//  Pods
//
//  Created by Johan Rydenstam on 11/11/15.
//
//

#import <Foundation/Foundation.h>

@protocol KCOCheckoutViewControllerProtocol;
@protocol KCOCheckoutSizingDelegate <NSObject>

@required
/**
 * Notifies that the checkout view controller did resize. It's
 * the content of the view that is resized, the recevier of this message
 * is reposinsible for updating the UI
 **/
- (void)checkoutViewController:(UIViewController<KCOCheckoutViewControllerProtocol> *)checkoutViewController didResize:(CGSize)size;

/**
 * Should return the parent scrollview relative to the checkout view controller.
 * It's used to handle the focusing of input text field.
 */
- (UIScrollView *)parentScrollViewForCheckoutViewController:(UIViewController<KCOCheckoutViewControllerProtocol> *)checkoutViewController;

@end