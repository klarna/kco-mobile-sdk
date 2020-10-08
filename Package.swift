// swift-tools-version:5.3
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "KlarnaCheckoutSDK",
    products: [
        .library(
            name: "KlarnaCheckoutSDK",
            targets: ["KlarnaCheckoutSDK"]),
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "KlarnaCheckoutSDK",
            path: "ios/XCFramework/KlarnaCheckoutSDK.xcframework"
        )
    ]
)
