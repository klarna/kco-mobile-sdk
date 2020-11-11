# Klarna Checkout iOS SDK

## Setup

The Klarna Checkout SDK is currently avaliable through Cocoapods. The simplest way to add the framework is to the pod with our supplied podspec.

```
pod 'KlarnaCheckoutSDK'
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

## Integration

The SDK allows developers to integrate a native checkout experience into their applications. When you create an order through Klarna's checkout API, you are provided an HTML snippet to render Klarna Checkout. 

We offer two ways applications may present Klarna Checkout:
- Native mode: We manage the checkout view (either as a full standalone view or embedded into your application.)
- Hybrid mode: We manage the checkout view when you provide us with a web view (e.g. your application renders HTML around the checkout and handles the sizing and rendering of the web view). 


### Native Mode

#### Initialization

To add the checkout in your native flow, you supply a snippet which you retrieved through order API.

First, you create a `KCOKlarnaCheckout` and set the html snippet:
```objective-c
self.checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self returnURL:<YOUR-URL>];
checkout.snippet = snippet;
```

Setting the snippet will start preloading the checkout, which ensures a better experience for the users.

#### Standalone View

If you wish to display this view controller as a standalone view, you can retrieve a `KCOCheckoutViewController` and present it by pushing it in your navigation stack:

```objective-c
UIViewController<KCOCheckoutViewController> *viewController = [checkout checkoutViewController];
// This viewController can be displayed as is.
[self.navigationController pushViewController:viewController];
```

#### Embedded View

If you want to integrate it into your own native checkout view, you can add the checkoutViewController as a childViewController and handle resize events for the checkout.

First, you need to disable internal scrolling and supply a sizing delegate implementing `KCOCheckoutSizingDelegate`. This will make the viewcontroller fill its internal scrollview to its parent and not scroll. 

```objective-c
viewController.internalScrollDisabled = YES;
viewController.sizingDelegate = self;
viewController.parentScrollView = self.scrollView;
```

You are then responsible for resizing the checkout view to be as big as it needs to be. To do this, you'll need to implement the resize method. At this point, whether you manually set frames or use autolayout is totally up to you.

```objective-c
- (void)checkoutViewController:(id)checkout didResize:(CGSize)size
{
// Update the size of the checkout view controller to match the new size.
}
```

#### Completion

When you get the completion signal from the SDK (see below in Signalling), you should render the completion view for users. 

In native mode, you can do this by rendering the completion snippet Klarna provides you with. Your backend can retrieve the snippet as detailed [here, in Klarna's documentation](https://developers.klarna.com/en/gb/kco-v3/checkout/3-render-the-confirmation-snippet). 

Once your app has the completion snippet, it should set the snippet on the checkout object:
```objective-c
checkout.snippet = snippet;
```

This insures that the fullscreen loading view disappears and the user sees important information about their order.


### Hybrid Mode

#### Initialization

If you are using the Klarna Checkout in a web view by loading your Checkout URL (or by loading another URL that contains the checkout snippet), you instantiate `KCOKlarnaCheckout` in the same way as before, but you instead attach your web view.

```objective-c
self.checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self returnURL:<YOUR-URL>];
[self.checkout setWebView:self.webview];
```

The SDK will handle the checkout flow and return signals on certain events. The SDK will keep a weak reference of the view controller and we will never override the web view delegate, so you can keep using the web view as normal.

To correctly set up the checkout flow you must notify the checkout that the view has loaded - so in your `viewDidLoad` call `notifyViewDidLoad` on the checkout.

```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
    [self.checkout notifyViewDidLoad];
}
```

If your view has already loaded when you create the checkout, you should call `notifyViewDidLoad` immediately.

*Warning:* You should only call this method once!

#### Completion

When you get the completion signal from the SDK (see below in Signalling), you should render the completion view for users. 

In hybrid mode, this is accomplished by opening the URL you get in the completion notifiction in your web view. You can parse the contents of the notification with `KCOSignalNameKey` and `KCOSignalDataKey`.


```objective-c
- (void)handleNotification:(NSNotification *)notification
{
    NSString *name = notification.userInfo[KCOSignalNameKey];
    NSDictionary *data = notification.userInfo[KCOSignalDataKey];

    if ([name isEqualToString:@"complete"]) {
        [self handleCompletionUri:[data objectForKey:@"uri"]];
    }
}

- (void)handleCompletionUri:(NSString *)uri{
    if (uri && [uri isKindOfClass:[NSString class]] && uri.length > 0) {
        NSURL *url = [NSURL URLWithString:uri];
        [self.webView loadRequest:[NSURLRequest requestWithURL:url]];
    }
}
```

If you don't want to navigate away from current URL in your web view, you must retrieve the completion snippet from Klarna and render it in your web view yourself. Your backend can retrieve the snippet as detailed [here, in Klarna's documentation](https://developers.klarna.com/en/gb/kco-v3/checkout/3-render-the-confirmation-snippet). 


This insures that the fullscreen loading view disappears and the user sees important information about their order.


If you want to display the confirmation page in another webview than the one you showed the initial flow in, you must first attach the webview to the checkout.
Handling the completion uri could look something like this:

```objective-c
- (void)handleCompletionUri:(NSString *)uri{
    if (uri && [uri isKindOfClass:[NSString class]] && uri.length > 0) {
        NSURL *url = [NSURL URLWithString:uri];
        [self.checkout attachWebView:self.confirmationWebView];
        [self.confirmationWebView loadRequest:[NSURLRequest requestWithURL:url]];   
    }
}
```



### Signalling

The SDK will signal your application when the order is complete through an `NSNotification`. You can observe for signals through the default `NSNotificationCenter`, listening to a `KCOSignalNotification`:

```objective-c
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:KCOSignalNotification object:nil];
```

```objective-c
- (void)handleNotification:(NSNotification *)notification
{
    NSString *name = notification.userInfo[KCOSignalNameKey];
    NSDictionary *data = notification.userInfo[KCOSignalDataKey];

    if ([name isEqualToString:@"complete"]) {
        // Order is complete!
    }
}
```
For a full list of all the signals see the [Checkout JavaScript API](https://developers.klarna.com/documentation/klarna-checkout/javascript-api/#checkout-events).

### Return URL

Some payment methods require authorization through third-party applications. These can return to your application upon completion, but to do that you need to supply a URL that should be used for returning.

There do not need to be any special handlers on application load for that URL, our only requirement is that the user is returned to your application from the third-party application.

For example, you can supply a url like: `my-schema:return.url` and add the my-schema protocol to your `info.plist` file.

>**Note:** In cases where the user needs to authenticate with their bank for credit card payments, the bank itself might open a third-party app such as Bank ID. Since the SDK does not create these sessions, the user would have to return to the app manually, and then you will get the completion signal from the checkout.
