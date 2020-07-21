# Android Integration

## Project Setup

The Payments SDK is available on our Maven Repository, perform the following steps to add it to your application:

1. Edit your application level `build.gradle` file and add the following repository to your `repositories` section:

    ```gradle
    repositories {
        ....
        maven {
            url 'https://x.klarnacdn.net/mobile-sdk/'
        }
    }
    ```

2. Add a `implementation` dependency for the library:

    ##### For projects already migrated to AndroidX
    ```gradle
    implementation ('com.klarna.checkout:sdk:<latest version>')
    ```
  
    >**Note**: If you were to use 1.0.0 it would look like:
    >```gradle
    >implementation 'com.klarna.checkout:sdk:1.0.0'
    >```
    >The latest version is [![Maven](https://img.shields.io/maven-metadata/v/https/x.klarnacdn.net/mobile-sdk/com/klarna/checkout/sdk/maven-metadata.xml.svg)](https://github.com/klarna/kco-mobile-sdk/blob/master/android/README.md)
    ##### For projects using Support Library
    
    ```gradle
    implementation ('com.klarna.checkout:sdk:<latest version>-support')
    ```
   
    >**Note**: If you were to use 1.0.0 it would look like:
    >```gradle
    >implementation 'com.klarna.checkout:sdk:1.0.0-support'
    >```
    >The latest version is [![Maven](https://img.shields.io/maven-metadata/v/https/x.klarnacdn.net/mobile-sdk/com/klarna/checkout/sdk/maven-metadata.xml.svg)](https://github.com/klarna/kco-mobile-sdk/blob/master/android/README.md)

3. Register an `intent-filter` for the `Activity` which will be hosting the checkout in your `AndroidManifest.xml` to support return URLs:

    ```xml
    <intent-filter>
        <action android:name="android.intent.action.VIEW" />
        <category android:name="android.intent.category.DEFAULT" />
        <category android:name="android.intent.category.BROWSABLE" />

        <data android:scheme="<your-custom-scheme>" />
        <data android:host="<your-custom-host>" />
    </intent-filter>
    ```


### Note:

The hosting `Activity` should be using `launchMode` of `singleTask` or `singleTop` to prevent a new instance from being created when returning from an external application.

```xmlstash
<activity
    android:launchMode="singleTask|singleTop">
```

## Integration
The SDK allows developers to integrate a Checkout into their applications in several ways. When you create an order through Klarna's Checkout API, you are provided with an HTML snippet to render Klarna Checkout.

We offer two ways applications may present Klarna Checkout:

- Native: You provide the SDK with the HTML snippet. The SDK returns a Checkout view that you can present either as a full standalone view or embedded into your application.

- Hybrid: You load the snippet into a Web View and provide the SDK with a reference to it. The SDK then manages the checkout flow while you manage the Web View. This may be useful if you wish to render additional HTML around the checkout view. 

If needed, you can read the Klarna's Checkout Integration guide [here](https://developers.klarna.com/en/se/kco-v3/checkout/1-prepare-your-site-for-klarna-checkout).


### Native Mode

#### Initialization

To add a checkout, create an instance of `KlarnaCheckout` and supply the snippet which you retrieved through the Klarna's API.

```java
final KlarnaCheckout checkout = new KlarnaCheckout(this, returnURL);
checkout.setSnippet(snippet);
```

Setting the snippet will start preloading the checkout, which ensures a better experience for the users.
The `returnURL` should match the custom web app URL scheme as defined in your `AndroidManifest.xml`.

### Presenting the Checkout View

To display the checkout, simply retrieve an instance of the checkout view and place it in a `ViewGroup` of choice, e.g. `FrameLayout`. Please note that the checkout view itself will not be scrollable and you need to have a `ScrollView` somewhere in the parent hierarchy to enable scrolling.

```java
final View checkoutView = checkout.getView();
final ViewGroup container = findViewById(R.id.checkoutContainer);
container.addView(checkoutView);
```

After adding the checkout container to your layout it could look something like this.
```xml
<ScrollView
    android:layout_width="match_parent"
    android:layout_height="match_parent">
    
    <LinearLayout
        android:layout_width="match_parent"
        android:layout_height="wrap_content"
        android:orientation="vertical">
    
        <!--...-->
    
        <FrameLayout
             android:id="@+id/checkoutContainer"
             android:layout_width="match_parent"
             android:layout_height="match_parent" />
        
        <!--...-->
        
    </LinearLayout>
</ScrollView>
```

### Configure Signalling

The SDK will signal your application throughout the checkout process via a `SignalListener`.
The only event you need to listen to is the `complete` event. When the complete event is triggered, redirect the customer to the confirmation page within your app.

```java
checkout.setSignalListener(new SignalListener() {  
    @Override  
    public void onSignal(String eventName, JSONObject jsonObject) {  
        if (eventName.equals("complete")) {  
            try {  
                final String confirmationURL = jsonObject.getString("uri");  
                loadConfirmationSnippet(confirmationURL);
            } catch (JSONException e) {  
                Log.e(TAG, e.getMessage(), e);  
            }  
        }  
    }  
);
```

Optionally, you may want to set up the listener to track field changes in the Klarna Checkout before the order is placed. See the reference guide for what events are available.

## Hybrid Mode

#### ❗️❗️Important ❗️❗️
Please note that this mode will will be deprecated in the future. If you are currently using Hybrid mode, please migrate from Hybrid mode as soon as possible. If you can't, don't hesitate to contact us and we'll investigate a solution that will work with your integration needs.

### Initialization

To add a checkout, create an instance of the `KlarnaCheckout` and supply it with the `WebView` in which the checkout should be rendered.

```java
final KlarnaCheckout checkout = new KlarnaCheckout(this, returnURL);
checkout.setWebView(myWebView);
```

### Presenting Checkout
From your WebView, load the URL to the web page where you have integrated Klarna Checkout. The Checkout SDK will automatically run when it detects the Checkout snippet in the Web View:

```java
myWebView.loadUrl("https://www.example.store/checkout");
```

### Configure Signalling

The SDK will signal your application throughout the checkout process via a `SignalListener`.
The only event you need to listen to is the `complete` event. When the complete event is triggered, redirect the customer to the confirmation page within your app.

```java
checkout.setSignalListener(new SignalListener() {  
    @Override  
    public void onSignal(String eventName, JSONObject jsonObject) {  
        if (eventName.equals("complete")) {  
            try {  
                final String confirmationURL = jsonObject.getString("uri");  
                myWebView.loadUrl(confirmationURL);
            } catch (JSONException e) {  
                Log.e(TAG, e.getMessage(), e);  
            }  
        }  
    }  
 );
```

Optionally, you may want to set up the listener to track field changes in the Klarna Checkout before the order is placed. See the reference guide for what events are available.

## Cleanup
When you are done with the checkout, make sure to call `destroy()` to release resources.
```java
checkout.destroy();
```

## Return URL

Some payment methods require authorization through third-party applications. These can return to your application upon completion, but to do that you need to supply a URL that should be used for returning.
There do not need to be any special handlers on application load for that URL, our only requirement is that the user is returned to your application from the third-party application.


>**Note:** In cases where the user needs to authenticate with their bank for credit card payments, the bank itself might open a third-party app such as Bank ID. Since the SDK does not create these sessions, the user would have to return to the app manually, and then you will get the completion signal from the checkout.
