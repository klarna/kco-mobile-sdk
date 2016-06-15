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
 *  ViewController containing the checkout.
 *  To display either add it as a child view controller 
 *  and implement the sizing delegate, and turn of internal scrolling
 *  or simply push it to your navigation stack.
 *
 *  @note Should only be used if you provide a snippet. If you are providing a webview
 *  which will contain the checkout then you should not use this property.
 *
 *  @see KCOCheckoutViewControllerProtocol
 */
@property (nonatomic, readonly) UIViewController<KCOCheckoutViewControllerProtocol> *checkoutViewController;

/**
 *  We will keep a week reference to the view controller.
 *  @note This initializer will call initWithViewController:redirectURI: with redirectURI as nil
 *  @param viewController The viewcontroller that will be presenting this checkout.
 *  @see initWithViewController:redirectURI:
 */
- (instancetype)initWithViewController:(UIViewController *)viewController;

/**
 *  Designated initializer.
 *
 *  @param viewController The view controller that will contain the checkout.
 *  @param redirectURI  A uri to be used for third party applications, to be able to return to your application.
 *  It should be a url that you are subscribing to in your info plist, with a protocol that should
 *  be unique for your application.
 *  @returns A KCOKlarnaCheckout object that can be used in the context of the view controller.
 */
- (instancetype)initWithViewController:(UIViewController *)viewController redirectURI:(NSURL *)redirectURI;

/**
 *  Html snippet containing to start the Klarna checkout.
 */
- (void)setSnippet:(NSString *)snippet;

/**
 *  Set a webview to use for the checkout. Either use this or setSnippet.
 *  Do not use both.
 *  We will never take over the webview delegate.
 *
 *  @param webView Your webview to attach use for the checkout.
 */
- (void)setWebView:(id)webView;

/**
 *  If you call setWebView with your own webview - you also need to 
 *  notify that the viewControllers view has been loaded. So we can properly setup
 *  our view hierarchy.
 *  You do not need to call it if you use setSnippet:
 */
- (void)notifyViewDidLoad;

/**
 *  Suspend the current checkout flow
 */
- (void)suspend;

/**
 *  Resume a suspended checkout flow
 */
- (void)resume;

/**
 *  Dismantle the checkout properly
 *  After the checkout has been destroyed - it should not be reused. Instead create a new checkout.
 *  If the checkout is using the same mode and the same view controller you can reuse the checkout by either
 *  setting the webview or the snippet again. This is preferred as there is less overhead.
 *  However if you want to change the view controller. Destroy, nil out, and recreate a new checkout 
 *  for the new view controller.
 *  @see setWebView:
 *  @see setSnippet:
 *  @see initWithViewController:redirectURI:
 */
- (void)destroy;

@end
