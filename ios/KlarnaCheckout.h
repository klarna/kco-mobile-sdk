#import <Cordova/CDVPlugin.h>

@interface KlarnaCheckout : CDVPlugin

- (void)handleNotification:(NSNotification *)notification;
- (void)handleCompletionUri:(NSString *)uri;

@end
