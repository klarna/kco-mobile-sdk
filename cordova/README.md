# Klarna Checkout Cordova Plugin

### Installation

Klarna Checkout Cordova plugin is available for iOS and Android platforms and can be installed with a single command:

```
cordova plugin add kco-mobile-sdk --save
```

### Usage

```javascript
jQuery('#placeholder').html(htmlSnippet)

_klarnaCheckout(function (api) {
  api.on({
    complete: function (data) {
      /* ..handle purchase completion here, load confirmation snippet.. */
    }
  })
})
```