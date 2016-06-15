
# Changelog 

## 1.4

### Removed KCOCheckoutController 

To unify the external api with the android release we removed the KCOCheckoutController, and moved the accesspoints to the KCOKlarnaCheckout.

If you want to create a checkout for your already existing webview, previously you would create a KCOCheckoutController, and attach the webview.

```objective-c
self.checkout = [[KCOCheckoutController alloc] initWithViewController:self];
[self.checkout attachWebView:self.webview];
```

This accesspoints are moved to the ```KCOKlarnaCheckout``` and renamed ```attachWebView:``` to ```setWebView:```

```objective-c
self.checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self];
[self.checkout setWebView:self.webview];
```

### Always require a view controller

If you want to create a checkout with a snippet loaded from your server, previously you would create a ```KCOKlarnaCheckout``` and set the snippet.

```objective-c
KCOKlarnaCheckout *checkout = [[KCOKlarnaCheckout alloc] init];
checkout.snippet = snippet;
```

Now to unify you would also supply a view controller, when creating a KCOKlarnaCheckout object.

```objective-c
KCOKlarnaCheckout *checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self];
checkout.snippet = snippet;
```

### Added redirectURI

To allow for thirdparty applications to return to your application, in case of third party authenticators or similar, you can supply a redirectURI, which you should handle as a normal iOS remote URL.

```objective-c
// hybrid webview
self.checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self redirectURI:<YOUR-URL>];
[self.checkout setWebView:self.webview];

// native snippet loading
self.checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self redirectURI:<YOUR-URL>];
checkout.snippet = snippet;
```

This url should be of your custom app schema which you implement in your info-plist file. You should not need to handle the calling of this URL in any special way, simply make sure the application will open for that schema.

### Refactored Signals

Signals are no longer sent with an ArgsKey, instead they have a Data object

Previously you would fetch a list of arguments for the signals, and cast the first argument to a dictionary, which it would almost always be, so we refactored it to make the interface a lot cleaner.

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

The new implementation will simply become this. 

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

### Parent scrollview

To further unify with the Android sdk we change the parentScrollViewForCheckoutViewController: method to a property on the ```UIViewController<KCOCheckoutViewController>``` object returned from the ```checkoutViewController``` method. So if you want to add a checkout to a native flow, you set the parentScrollView.

So where you would previously implement the KCOEmbeddableCheckoutSizingDelegate methods

```
#pragma mark - KCOEmbeddableCheckoutSizingDelegate
- (UIScrollView *)parentScrollViewForCheckoutViewController:(id)checkout
{
    // return the parent scroll view.
}
...
```

You would now instead just set the parentScrollView.

```
viewController.parentScrollView = self.scrollView;
```




