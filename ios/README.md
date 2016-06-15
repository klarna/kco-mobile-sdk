# Klarna Checkout iOS SDK

## SDK Integration

### Setup

The simplest way to add the framework is to use cocoapods and specify the podspec supplied.

```
pod 'KlarnaCheckout'
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

### KCOKlarnaCheckout

#### Existing webview with checkout

If you are using the Klarna checkout in a webview by loading your checkout url you should instead use a KCOKlarnaCheckout and instantiate it with your current view controller and the webview. The SDK will handle the checkout flow and return signals on certain events. The SDK will keep a weak reference of the view controller, and we will never override the webview delegate, so you can keep using it as normal.

To set it up you create a KCOKlarnaCheckout

```objective-c
self.checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self redirectURI:<YOUR-URL>];
[self.checkout attachWebView:self.webview];
```

To correctly set up the checkout flow you must notify the checkout that the view has loaded - so in your viewDidLoad call notifyViewDidLoad on the checkout.

```objective-c
- (void)viewDidLoad {
    [super viewDidLoad];
	[[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:KCOSignalNotification object:nil];
    [self.checkout notifyViewDidLoad];
}
```

If your view has already loaded when you create the checkout, you should call notifyViewDidLoad immediatelly.
*Warning:* You should only call this method once!

To handle the signals received from the SDK you should set up an observer listening to the KCOSignalNotification.
To make sure the checkout shows the succesful screen you need to redirect your webview to the completion url upon recieveing the "complete" message.

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

If you want to display the confirmation page in another webview than the one you showed the initial flow in, you must first attach the webview to the checkout.
Handling the completion uri could look something like this:

```
- (void)handleCompletionUri:(NSString *)uri{
	if (uri && [uri isKindOfClass:[NSString class]] && uri.length > 0) {
		NSURL *url = [NSURL URLWithString:uri];
		[self.checkout attachWebView:self.confirmationWebView];
		[self.confirmationWebView loadRequest:[NSURLRequest requestWithURL:url]];
	}
}
```

#### Native

To add the checkout in your native flow instead of setting the webview you supply a snippet which you retrieved through the order api.

First you must create a checkout and set the html snippet.
```objective-c
self.checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self redirectURI:<YOUR-URL>];
checkout.snippet = snippet;
```

Setting the snippet will start preloading the checkout, which ensures a better experience for the users.

If you want to display this view controller straight up and down you can use it like normally by pushing it in your navigation stack.

```objective-c
UIViewController<KCOCheckoutViewController> *viewController = [checkout checkoutViewController];
// This viewController can be displayed as is.
[self.navigationController pushViewController:viewController];
```

If you want to integrate it in your own native checkout flow, you can add the checkoutViewController as a childViewController and handle resize events for the checkout.

First you need to disable internal scrolling and suply a sizing delegate implementing ```<KCOEmbeddableCheckoutSizingDelegate>```. This will make the viewcontroller fill its internal scrollview to its parent, with no scrolling. Now you are responsible for making the checkout view as big as it needs to be.

```objective-c
viewController.internalScrollDisabled = YES;
viewController.sizingDelegate = self;
viewController.parentScrollView = self.scrollView;
```

You need to implement the resize method. In the resize event it is up to you how to layout the views, but you need to make sure the view gets the required size. Wether you manually set frames or use autolayout is totally up to you.

```objective-c
- (void)checkoutViewController:(id)checkout didResize:(CGSize)size
{
// Update the size of the checkout view controller to match the new size.
}
```

#### Redirect URI

Some payment methods require auhtoriziation through third party applications. These can return to your application upon completion, but to do that you need to supply a url that should be used for returning. There does not need to be any special handlers on application load for that url, just that the application will load from that url.

for example you can supply a url like: ```my-schema:return.url``` and add the my-schema protocol to your info plist file.
