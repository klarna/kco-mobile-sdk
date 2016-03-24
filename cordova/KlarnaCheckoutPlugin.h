#import <Cordova/CDVPlugin.h>

@interface KlarnaCheckoutPlugin : CDVPlugin

- (void)handleNotification:(NSNotification *)notification;
- (void)handleCompletionUri:(NSString *)uri;

@end
