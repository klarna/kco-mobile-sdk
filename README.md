# Klarna Checkout SDK for Mobile Apps
[![CocoaPods](https://img.shields.io/cocoapods/v/KlarnaCheckoutSDK.svg)](https://cocoapods.org/pods/KlarnaCheckoutSDK)
[![Maven](https://img.shields.io/maven-metadata/v/https/x.klarnacdn.net/mobile-sdk/com/klarna/checkout/sdk/maven-metadata.xml.svg)](https://github.com/klarna/kco-mobile-sdk/blob/master/android/README.md)
[![Carthage compatible](https://img.shields.io/badge/carthage-compatible-4BC51D.svg?style=flat)](https://github.com/Carthage/Carthage)
[![License](https://img.shields.io/github/license/klarna/kco-mobile-sdk)](https://github.com/klarna/kco-mobile-sdk/blob/master/LICENSE)
![Platforms](https://img.shields.io/badge/platform-ios%20%7C%20android-lightgrey)

The Checkout SDK allows to integrate [Klarna Checkout](https://www.klarna.com/us/business/sell-online-with-klarna) in native or hybrid iOS and Android applications.
It's aimed to make integration simple and provide the smoothest in-app purchase experience.

**Looking for Klarna Payments?** Check out the [Klarna In-App SDK](https://github.com/klarna/klarna-mobile-sdk) repo instead.

## Requirements
* iOS 10 or later.
* Android 4.0 or later.

### Developer Documentation
* [Klarna Checkout](https://developers.klarna.com/documentation/klarna-checkout/)
* [Mobile Apps Integrations](https://developers.klarna.com/documentation/klarna-checkout/mobile-apps/)

### API Documentation
*  [Android](https://rawgit.com/klarna/kco-mobile-sdk/master/android/docs/index.html)
*  [iOS](https://cocoadocs.org/docsets/KlarnaCheckoutSDK/)

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

![](https://developers.klarna.com/static/native_approach.png)

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

![](https://developers.klarna.com/static/hybrid_approach.png)

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

>**Note:** Please upgrade to the latest version (1.6.8 or above) if you experience crashes on Android 9.0 or later.

## Contributing

### Support

If you are having any issues using the SDK in your project or if you think that something is wrong with the SDK itself, please create an issue on [Github](https://github.com/klarna/kco-mobile-sdk/issues) or report a bug by following the guidelines in the next section. 

### How can I contribute?

Thank you for reading this and taking time to contribute to Klarna Checkout SDK! Below is a set of guidelines to help you contribute whether you want to report a bug, come with suggestions or modify code.

#### Reporting Bugs
This section will guide you through submitting a bug report for Klarna Checkout SDK.

Before submitting a bug report, please check that the issue hasn't been reported before. If you find a *Closed* issue that seem to describe an issue that is similar to what you want to report, open a new issue and link to the original issue in the new one. When you have checked that the issue hasn't been reported before **fill out [the required template](https://github.com/klarna/kco-mobile-sdk/blob/2409f459c59ecf4f5ad5537be46bc1e86ce30211/.github/ISSUE_TEMPLATE/bug_report.md)** which will help us resolve the issue faster. 

##### Submitting a Bug Report
Bugs that are submitted are tracked as [GitHub issues](https://guides.github.com/features/issues/). To report a bug, create an issue and use [the template](https://github.com/klarna/kco-mobile-sdk/blob/2409f459c59ecf4f5ad5537be46bc1e86ce30211/.github/ISSUE_TEMPLATE/bug_report.md) to provide information about the bug. Explain the problem thoroughly and include any additional information that you think might help the maintainers reproduce the issue. When creating the GitHub issue please make sure that you:

* **Use a clear and descriptive title** for the issue.
* **Describe the exact steps which reproduce the problem** with as many details as possible. It's generally better to provide too much than too little information.
* **Describe the behavior you observed after following the steps** and explain exactly what the problem is with that behavior.
* **Explain which behavior you expected instead** and why.
* **Provide screenshots and/or screen recordings** that might help explain the issue you are facing. To screen record a phone connected to Android Studio or an emulator follow the steps [here](https://developer.android.com/studio/debug/am-video). To screen record on iOS follow the steps described [here](https://support.apple.com/en-us/HT207935).
* **Include relevant logs in the bug report** by putting it in a [code block](https://help.github.com/en/github/writing-on-github/getting-started-with-writing-and-formatting-on-github#multiple-lines), a [file attachment](https://help.github.com/en/github/managing-your-work-on-github/file-attachments-on-issues-and-pull-requests) or in a [gist](https://help.github.com/en/github/writing-on-github/creating-gists) and provide a link to that gist.
* **Tell how recently you started having the issue.** When was the first time you experienced the issue and was it after updating the SDK version? Or has it always been a problem?
* If the problem started happening recently, **can you reproduce it in an older version of the SDK?** What's the most recent version in which the problem doesn't happen?
* **Can you reliably reproduce the issue?** If not, explain how often it occurs and under what conditions it normally happens. For example in what environment you are running Checkout.

Include details about the device/emulator/simulator you are experiencing the issue on:

* **Which version of the SDK are you using?**
* **Which OS is this a problem in, iOS, Android or both?** What version(s)? Also add the appropriate label to the issue.
* **Did you experience the issue in simulator/emulator or on real device(s)?**

#### Contributing with Code
Before contributing and if you are unsure about how the SDK or Checkout works you might want to read the documentation for [Klarna Checkout](https://developers.klarna.com/documentation/klarna-checkout/) and [Checkout SDK](https://developers.klarna.com/documentation/klarna-checkout/mobile-apps/).

##### Branching
Prefix the branch you are going to work on depending on what you are working on (bug fix or feature). Use the following prefixes when creating a new branch:

* **feature/** if the branch contains a new feature, example: `feature/my-shiny-feature`.
* **bugfix/**  if the branch contains a bug fix, example: `bugfix/my-bug-fix`.

##### Pull Requests
When creating a PR include as much information as possible about the type of enhancement, whether if it's a bugfix, new functionality or any other change. There's [a template](https://github.com/klarna/kco-mobile-sdk/blob/2409f459c59ecf4f5ad5537be46bc1e86ce30211/.github/ISSUE_TEMPLATE/pull-request.md) for you to fill out which will make the review process for the maintainers faster. When creating a PR do it against the `master` branch. The PR should include:

* **A clear and descriptive title**.
* **Description of the issue** if you are fixing a bug together with a link to the relevant issue or **background for introducing a new feature**.

## License
Copyright 2018 Klarna Bank AB

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License.
You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License.
