# Klarna Checkout SDK for Mobile Apps
[![CocoaPods](https://img.shields.io/cocoapods/v/KlarnaCheckoutSDK.svg)](https://cocoapods.org/pods/KlarnaCheckoutSDK)
[![Maven](https://img.shields.io/maven-metadata/v/https/x.klarnacdn.net/mobile-sdk/com/klarna/checkout/sdk/maven-metadata.xml.svg)](https://github.com/klarna/kco-mobile-sdk/blob/master/android/README.md)
[![Carthage compatible](https://img.shields.io/badge/carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![License](https://img.shields.io/github/license/klarna/kco-mobile-sdk)](https://github.com/klarna/kco-mobile-sdk/blob/master/LICENSE)
![Platforms](https://img.shields.io/badge/platform-ios%20%7C%20android-lightgrey)

> [!WARNING]  
> This library has been deprecated as Klarna Checkout is now supported by the [Klarna Mobile SDK](https://github.com/klarna/klarna-mobile-sdk).

The Checkout SDK allows to integrate [Klarna Checkout](https://docs.klarna.com/klarna-checkout/) in native or hybrid iOS and Android applications.
It's aimed to make integration simple and provide the smoothest in-app purchase experience.

**Looking for Klarna Payments?** Check out the [Klarna Mobile SDK](https://github.com/klarna/klarna-mobile-sdk) repo instead.

## Requirements
* iOS 10 or later.
* Android 4.0 or later.

## What does Klarna Checkout SDK Offer?
Klarna Checkout SDK offers two integration approaches: **Native integration** and **Hybrid integration**.

In the Native approach, your mobile app presents the Klarna Checkout view using our mobile SDK. The mobile SDK requests the Klarna checkout HTML snippet from Klarna through your end point. Your back-end acts as a communication tunnel.

In the Hybrid approach, your mobile app displays the Klarna checkout as a WebView. Your back-end acts as a web server, rendering the Klarna Checkout on a web page that you host, presented in the WebView in your mobile app.

## Overview

### Native Integration
The components in the Native approach are:

* An integration of Klarna Checkout from your servers to Klarna's servers.
* An end-point on your servers, where Klarna Checkout is fetched from the mobile SDK.
* Klarna Checkout SDK for mobile apps.
* Your mobile app.

Integrating Klarna Checkout consists of six steps:

1. Installation of Klarna Checkout.
2. Prepare your app by changing the configuration or app manifest.
3. Prepare backend endpoint to fetch a Checkout snippet.
4. Initialie the SDK with the Checkout snippet.
5. Present the Klarna Checkout view.
6. Configure event listeners.

### Hybrid Integration
The components in the Hybrid approach are:

* An integration of Klarna Checkout from your servers to Klarna's servers.
* A web page on your servers, where Klarna Checkout is fetched from the mobile SDK.
* Klarna Checkout SDK for mobile apps.
* Your mobile app.

Integrating Klarna Checkout consists of six steps:

1. Installation of Klarna Checkout.
2. Prepare your app by changing the configuration or app manifest.
3. Prepare your web page with Klarna Checkout integrated.
4. Initialize the SDK with your WebView.
5. Present your web page.
6. Configure event listeners.

## iOS

iOS SDK is shipped as a framework and can be installed using Cocoapods:

```
pod 'KlarnaCheckoutSDK'
```

Carthage:

```
binary "https://raw.githubusercontent.com/klarna/kco-mobile-sdk/master/KlarnaCheckoutSDK.json"
```

Swift Package Manager (+Xcode 12):

In Swift Packages, Add the KlarnaCheckoutSDK package repository URL.

```
https://github.com/klarna/kco-mobile-sdk
```

##### [Usage](ios/README.md) | [Documentation](https://cocoapods.org/pods/KlarnaCheckoutSDK/) | [Example app](https://github.com/klarna/kco-ios-example-app)



## Android
Android SDK is available on our Maven repository, perform the following steps to add it to your application.

```
repositories {
        ....
        maven {
            url 'https://x.klarnacdn.net/mobile-sdk/'
        }
    }
```

Add as a dependency:

```
implementation 'com.klarna.checkout:sdk:1.x.x'
```

##### [Usage](android/README.md) | [Documentation](https://rawgit.com/klarna/kco-mobile-sdk/master/android/docs/index.html) | [Example app](https://github.com/klarna/kco-android-example-app)

## License
Copyright 2018 Klarna Bank AB

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
