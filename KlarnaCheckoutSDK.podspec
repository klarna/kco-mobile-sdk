Pod::Spec.new do |s|
    s.name         = "KlarnaCheckoutSDK"
    s.version      = "1.7.3"
    s.summary      = "Klarna Checkout iOS SDK"
    s.description  = <<-DESC
    Simple integration of Klarna Checkout for native and hybrid iOS apps.
    DESC
    s.homepage     = "https://github.com/klarna/kco-mobile-sdk.git"
    s.license      = { :type => "Apache License, Version 2.0", :file => "LICENSE" }
    s.author       = { "Klarna Mobile SDK Team" => "mobile.sdk@klarna.com" }
    s.platform     = :ios, "10.0"
    s.source       = { :git => "https://github.com/klarna/kco-mobile-sdk.git", :tag => "v"+s.version.to_s }
    s.requires_arc = true

    s.subspec 'legacy' do |sb|
        sb.source_files = "ios/KlarnaCheckoutSDK.framework/Headers/*.h"
        sb.public_header_files = "ios/KlarnaCheckoutSDK.framework/Headers/*.h"
        sb.vendored_frameworks = "ios/KlarnaCheckoutSDK.framework"
        s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
        s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
    end

    s.subspec 'xcframework' do |sb|
        sb.vendored_frameworks = "ios/XCFramework/KlarnaCheckoutSDK.xcframework"
    end

    s.default_subspec = 'xcframework'
    s.frameworks = 'UIKit', 'WebKit', 'Security', 'CFNetwork', 'MobileCoreServices', 'SystemConfiguration', 'JavaScriptCore'

end
