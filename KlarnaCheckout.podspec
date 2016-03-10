Pod::Spec.new do |s|
  s.name = 'KlarnaCheckout'
  s.version = '1.0.0'
  s.summary = 'A short description of iOS-Klarna-Checkout-SDK.'
  s.license = 'MIT'
  s.authors = {"Johan Rydenstam"=>"johan.rydenstam@klarna.com"}
  s.homepage = 'https://github.com/<GITHUB_USERNAME>/iOS-Klarna-Checkout-SDK'
  s.description = ''
  s.weak_frameworks = 'JavaScriptCore', 'Contacts', 'SafariServices', 'SystemConfiguration'
  s.frameworks = ["UIKit", "WebKit", "Security", "CFNetwork", "MobileCoreServices"]
  s.libraries = 'z'
  s.requires_arc = true
  s.source = {}

  s.ios.deployment_target    = '7.0'
  s.ios.preserve_paths       = 'ios/iOSKlarnaCheckoutSDK.framework'
  s.ios.public_header_files  = 'ios/iOSKlarnaCheckoutSDK.framework/Versions/A/Headers/*.h'
  s.ios.resource             = 'ios/iOSKlarnaCheckoutSDK.framework/Versions/A/Resources/**/*'
  s.ios.vendored_frameworks  = 'ios/iOSKlarnaCheckoutSDK.framework'
end
