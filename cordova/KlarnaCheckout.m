#import "KlarnaCheckout.h"
#import <Cordova/CDVPlugin.h>
#import <KlarnaCheckout/KlarnaCheckout.h>

@interface KlarnaCheckout ()

@property (strong) KCOCheckoutController *checkout;

@end


@implementation KlarnaCheckout

-(void)pluginInitialize {
    self.checkout = [[KCOCheckoutController alloc] initWithViewController:self.viewController];
    [self.checkout notifyViewDidLoad];
    [self.checkout attachWebView:self.webView];
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNotification:) name:KCOSignalNotification object:nil];
}

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
        [((UIWebView*) self.webView) loadRequest:[NSURLRequest requestWithURL:url]];
    }
}

-(void)dispose{
    self.checkout = nil;
    [[NSNotificationCenter defaultCenter] removeObserver:self name:KCOSignalNotification object:nil];
}

@end