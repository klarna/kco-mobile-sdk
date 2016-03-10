Pod::Spec.new do |s|
  s.name = 'KlarnaCheckout'
  s.version = '1.1.0'
  s.summary = 'Klarna Checkout iOS SDK'
  s.license = 'Apache License, Version 2.0'
  s.authors = {"Johan Rydenstam"=>"johan.rydenstam@klarna.com"}
  s.homepage = 'https://github.com/klarna/kco-mobile-sdk'
  s.description = 'Simple integration of Klarna Checkout into native and hybrid iOS apps'
  s.weak_frameworks = 'JavaScriptCore', 'Contacts', 'SafariServices', 'SystemConfiguration'
  s.frameworks = ["UIKit", "WebKit", "Security", "CFNetwork", "MobileCoreServices"]
  s.libraries = 'z'
  s.requires_arc = true
  s.source = {"git"=>'https://github.com/klarna/kco-mobile-sdk.git', :tag => 'v1.1.0'}

  s.ios.deployment_target    = '7.0'
  s.ios.preserve_paths       = 'ios/iOSKlarnaCheckoutSDK.framework'
  s.ios.public_header_files  = 'ios/iOSKlarnaCheckoutSDK.framework/Versions/A/Headers/*.h'
  s.ios.resource             = 'iOS/iOSKlarnaCheckoutSDK.framework/Versions/A/Resources/**/*'
  s.ios.vendored_frameworks  = 'ios/iOSKlarnaCheckoutSDK.framework'
end
