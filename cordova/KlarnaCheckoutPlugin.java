package com.klarna.checkout;

import android.app.Activity;
import android.webkit.WebView;
import org.apache.cordova.CordovaPlugin;

public class KlarnaCheckoutPlugin extends CordovaPlugin {

    @Override
    public void pluginInitialize() {

        final Activity activity = this.cordova.getActivity();
        final WebView webView = (WebView) this.webView.getView();
        final KlarnaCheckout checkout = new KlarnaCheckout(activity);
        checkout.setWebView(webView);
    }

}