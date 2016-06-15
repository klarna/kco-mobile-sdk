# Klarna Checkout Android SDK

## SDK Integration

### Setup
#### Adding the library locally

1. Create a folder in your application module named _"libs"_

    [Project]/app/libs

2. Copy the _klarna-checkout-sdk-[version].aar_ to the libs folder

3. Edit your application level build.gradle file and add the following section (after the _android scope_):

```gradle
    repositories {
        flatDir {
            dirs 'libs'
        }
    }
```

4. Add a compile dependency for the library:

```gradle
    compile (name: 'klarna-checkout', ext: 'aar')
```

#### Update your application manifest

1. Add permissions

```xml
    <!-- Standard persmissions required by the SDK -->
    <permission android:name="android.permission.INTERNET" />
    <permission android:name="android.permission.WRITE_EXTERNAL_STORAGE" />

    <!-- OPTIONAL: Permissions required if using GCM -->
    <!-- permission android:name="android.permission.WAKE_LOCK" / -->
    <!-- permission android:name="com.google.android.c2dm.permission.RECEIVE" / -->

    <!-- OPTIONAL: Permissions required for Cellular switch on Android 5+ -->
    <!-- permission android:name="android.permission.ACCESS_NETWORK_STATE" / -->
    <!-- permission android:name="android.permission.CHANGE_NETWORK_STATE" / -->
    <!-- permission android:name="android.permission.CHANGE_WIFI_STATE" / -->
```

2. Add the BrowserActivity reference to your application context in the manifest

    <activity android:name="com.klarna.checkout.sdk.browser.BrowserActivity" />

#### Resynch project

Synch your project with the gradle files

### Primary checkout object for merchant integration.

#### Standard checkout initialization:

```java
KlarnaCheckout checkout = new KlarnaCheckout(myCurrentActivity);
checkout.setSnippet(/* ..the html snippet from merchant server.. */);
checkout.setSignalListener(/* ..an implementation of the SignalListener interface.. */);
View checkoutView = checkout.getView();
```

_(the returned view can then be placed in layout placeholder or fragment as required)_

#### "Hybrid" checkout initialization:

```java
KlarnaCheckout checkout = new KlarnaCheckout(myCurrentActivity);
checkout.setWebView(myWebView);
checkout.setSignalListener(/* ..an implementation of the SignalListener interface.. */);
```
_("myWebView" is a WebView instance that has loaded a web page which already contains the checkout code snippet)_

