#import "KlarnaCheckoutPlugin.h"
#import <Cordova/CDVPlugin.h>
#import "KlarnaCheckout/KlarnaCheckout.h"

@interface KlarnaCheckoutPlugin ()

@property (strong) KCOKlarnaCheckout *checkout;

@end


@implementation KlarnaCheckoutPlugin

-(void)pluginInitialize {
    self.checkout = [[KCOKlarnaCheckout alloc] initWithViewController:self.viewController];
    [self.checkout notifyViewDidLoad];
    [self.checkout setWebView:self.webView];
}

-(void)dispose{
    [self.checkout destroy];
}

@end