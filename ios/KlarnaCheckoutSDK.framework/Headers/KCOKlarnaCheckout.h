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
 *Handling External Payment Methods
 * Feature flag for EPM(External Payment Method) integration, should be set before the checkout
 * process starts. True means that KCO will not handle external payment methods automatically,
 * leaving the handling to the merchant.
 *
 * @note If the value is false
 *  External payment methods shall be rendered in the SDK in an in-app browser.

 * @note if the value is true
 *  External payment methods shall be handled by the merchant. KCO will signal the merchant via the SDK with the external payment method's URL.
 */
@property (nonatomic, assign) BOOL merchantHandlesEpm;

/**
 * Handling Validation Error
 * Feature flag for checkout validating errors, should be set before the checkout
 * process starts. True means that KCO will not pop up an error with validation failure message,
 * leaving the handling to the merchant.
 *
 * If the parameter is undefined (e.g. due to using an older version of the SDK) it should be assumed to have a default value of false.
 *
 * @note If the value is false
 *  Validation errors shall be rendered in the SDK in an in-app browser.
 * @note If the value is true
 *  Validation errors shall be handled by the merchant. KCO will signal the merchant via the SDK with the failed result of a validation error.
*/
@property (nonatomic, assign) BOOL merchantHandlesValidationErrors;

/**
 *  Designated initializer.
 *
 *  @param viewController The view controller that will contain the checkout.
 *  @param returnURL  A uri to be used for third party applications, to be able to return to your application.
 *
 *  It should be a url that you are subscribing to in your info plist, with a protocol that should
 *  be unique for your application.
 *  @returns A KCOKlarnaCheckout object that can be used in the context of the view controller.
 */
- (instancetype)initWithViewController:(UIViewController *)viewController returnURL:(NSURL *)returnURL;

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
 *  @see initWithViewController:returnURL:
 */
- (void)destroy;

@end
