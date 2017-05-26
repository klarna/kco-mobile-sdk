# Klarna Checkout Cordova Plugin

[![Cordova NPM](https://img.shields.io/npm/v/kco-mobile-sdk.svg?style=flat-square)](https://www.npmjs.com/package/kco-mobile-sdk)
[![Cordova NPM](https://img.shields.io/npm/dt/kco-mobile-sdk.svg?style=flat-square)](https://www.npmjs.com/package/kco-mobile-sdk)
[![License](https://img.shields.io/npm/l/kco-mobile-sdk.svg?style=flat-square)](https://github.com/klarna/kco-mobile-sdk/blob/master/LICENSE)

- **[NPM package](https://www.npmjs.com/package/kco-mobile-sdk)**
- **[Example app](https://github.com/klarna/kco-cordova-example-app)**

---

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