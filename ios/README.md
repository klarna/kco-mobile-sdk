# Klarna Checkout iOS SDK

## SDK Integration

### Setup

The simplest way to add the framework is to use cocoapods and specify the podspec supplied.

```
pod 'iOSKlarnaCheckoutSDK', :path => 'iOSKlarnaCheckoutSDK-0.1.6/'
```

Alternatively you can add the framework manually. Remember to link the required frameworks as well.

```
MobileCoreServices
SafariServices
JavascriptCore
SystemConfiguration
WebKit
Security
CFNetwork
```

### KCOCheckoutController

If you are using the Klarna checkout in a webview by loading your checkout url you should instead use a KCOCheckoutController and instantiate it with your current view controller and the webview. The SDK will handle the checkout flow and return signals on certain events. The SDK will keep a weak reference of the view controller, and we will never override the webview delegate, so you can keep using it as normal.

To set it up you create a KCOCheckoutController

```objective-c
self.checkout = [[KCOCheckoutController alloc] initWithViewController:self webView:yourWebView];
```

To correctly set up the checkout flow you must notify the controller that the view has loaded - so in your viewDidLoad call notifyViewDidLoad on the checkout controller

```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.checkout notifyViewDidLoad];
}
```

To handle the signals recieved from the SDK you should set up an observer listeing to the KCOSignalNotification.
To make sure the checkout shows the succesful screen you need to redirect your webview to the completion url upon recieveing the "complete" message.

```objective-c
- (void)handleNotification:(NSNotification *)notification
{
    NSString *name = notification.userInfo[KCOSignalNameKey];
    NSArray *args = notification.userInfo[KCOSignalArgsKey];
    
    if ([name isEqualToString:@"complete"]) {
        NSDictionary *argsDict = [args objectAtIndex:0];
        if (argsDict && [argsDict isKindOfClass:[NSDictionary class]]) {
            [self handleCompletionUri:[argsDict objectForKey:@"uri"]];
        }
    }
}


- (void)handleCompletionUri:(NSString *)uri{
    if (uri && [uri isKindOfClass:[NSString class]] && uri.length > 0) {
        NSURL *url = [NSURL URLWithString:uri];
        [self.webView loadRequest:[NSURLRequest requestWithURL:url]];
    }
}
```


### KCOKlarnaCheckout

The KCOKlarnaCheckout is the main entry point into the application if you load a checkout using an html snippet fetched through the order api.

This method is specifically to get a more native experience.

First you must create a checkout and set the html snippet.
```objective-c
KCOKlarnaCheckout *checkout = [[KCOKlarnaCheckout alloc] init];
checkout.snippet = snippet;
```

Setting the snippet will start preloading the checkout, which ensures a better experience for the users.

If you want to display this view controller straight up and down you can use it like normally by pushing it in your navigation stack.

```objective-c
 *  UIViewController<KCOCheckoutViewController> *viewController = [checkout checkoutViewController];
 *  // This viewController can be displayed as is.
 *  [self.navigationController pushViewController:viewController];
```

If you want to integrate it in your own native checkout flow, you can add the checkoutViewController as a childViewController and handle resize events for the checkout.

First you need to disable internal scrolling and suply a sizing delegate implementing ```<KCOEmbeddableCheckoutSizingDelegate>```. This will make the viewcontroller fill its internal scrollview to its parent, with no scrolling. Now you are responsible for making the checkout view as big as it needs to be.

```objective-c
viewController.internalScrollDisabled = YES;
viewController.sizingDelegate = self;
```

You need to implement these two methds. In the resize event it is up to you how to layout the views, but you need to make sure the view gets the required size. Wether you manually set frames or use autolayout is totally up to you.

```objective-c
#pragma mark - KCOEmbeddableCheckoutSizingDelegate
- (UIScrollView *)parentScrollViewForCheckoutViewController:(id)checkout
{
    // return the parent scroll view.
}
- (void)checkoutViewController:(id)checkout didResize:(CGSize)size
{
    // Update the size of the checkout view controller to match the new size.
}
```