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

/**
 *  Field was focused inside checkout
 *
 *  @param rect The rect of the field that was selected.
 */
- (void)focusOnFieldWithRect:(CGRect)rect;

/**
 *  Checkout was resized.
 *
 *  @param height New height of checkout.
 */
- (void)resizeCheckoutWithHeight:(CGFloat)height;

@end

@protocol KCOWebViewProxyProtocol;

/**
 * This is the controller for the checkout.
 * If you will be creating a checkout by inserting an html snippet, it is highly recommended to make use of
 * the KCOCheckoutViewController.
 * 
 * To instantiate a new KCOCheckoutController - supply a view controller which will contain the webview, and
 * then attatch the webview. Once the webview displays a Klarna checkout, it will initialize the SDK functionality.
 *
 * @see initWithViewController:
 * @see attachWebView:
 * @see KCOCheckoutViewController
 */
@interface KCOCheckoutController : NSObject

/**
 *  Delegate with methods that will be called for certain events in the webview.
 */
@property (nonatomic, weak) id<KCOCheckoutControllerDelegate> delegate;

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
 * This method MUST be called once the viewControllers view is loaded.
 * Easiest is just calling it in the viewDidLoad method. If this has already been executed once you setup
 * the checkout controller just call it directly. Important is that viewController.view is already existing.
 * @note Only call this method once!
 */
- (void)notifyViewDidLoad;

/**
 *  Set snippet on view controller, used to bootstrap the checkout.
 *  Nothing happens until you actually call loadSnippet.
 *
 *  @param snippet html Snippet containing klarna checkout startup code.
 *  @see loadSnippet
 */
- (void)setSnippet:(NSString *)snippet;

/**
 *  Starts checkout procces by loading in webviews.
 *  @see setSnippet:
 */
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

