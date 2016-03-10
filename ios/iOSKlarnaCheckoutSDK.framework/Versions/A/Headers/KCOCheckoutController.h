//
//  KCOCheckoutController.h
//  Pods
//
//  Created by Johan Rydenstam on 08/12/15.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol KCOCheckoutControllerDelegate <NSObject>

- (void)focusOnFieldWithRect:(CGRect)rect;
- (void)resizeCheckoutWithHeight:(CGFloat)height;

@end

/**
 * This is the controller for the checkout.
 * If the checkout will be rendered by inserting a snippet, it's highly recommended to make use of
 * KCOCheckoutViewController.
 */
@protocol KCOWebViewProxyProvider;
@protocol KCOWebViewProxyProtocol;
@interface KCOCheckoutController : NSObject

@property (nonatomic, weak) id<KCOCheckoutControllerDelegate> delegate;
@property (nonatomic, readonly) id<KCOWebViewProxyProtocol> checkoutWebViewProxy;


/**
 * Returns a controller instance. It will handle checkout events and logic require by Klarna Checkout.
 * This controller will keep a weak reference to the viewcontroller.
 */
- (instancetype)initWithViewController:(UIViewController *)viewController;

/**
 *  Attaches a webview for use in the checkout.
 *  The checkout will never steal the delegates of the webview.
 *
 *  @param webView A UIWebView or WKWebView instance
 */
- (void)attachWebView:(id)webView;


/**
 * This method NEEDS to be called when the provided viewController view is loaded
 */
- (void)notifyViewDidLoad;
- (void)setSnippet:(NSString *)snippet;
- (void)loadSnippet;

/**
 *  Suspend the current checkout flow
 */
- (void)suspend;

/**
 *  Resume a suspended checkout flow
 */
- (void)resume;

@end

