package com.klarna.checkout;

import android.app.Activity;
import android.webkit.WebView;

import com.klarna.checkout.sdk.KlarnaCheckout;
import com.klarna.checkout.sdk.SignalListener;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

public class KlarnaCheckoutPlugin extends CordovaPlugin {

    @Override
    public void pluginInitialize() {

        Activity activity = this.cordova.getActivity();
        final WebView webView = (WebView) this.webView.getView();
        KlarnaCheckout checkout = new KlarnaCheckout(activity, webView);

        checkout.setSignalListener(new SignalListener() {
            @Override
            public void onSignal(String s, JSONArray jsonArray) {
                if (s.equals("complete")) {
                    try {
                        String uri = jsonArray.getJSONObject(0).getString("uri");
                        webView.loadUrl(uri);
                    } catch (JSONException e) {
                        e.printStackTrace();
                    }

                }
            }
        });

    }

}