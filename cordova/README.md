# Klarna Checkout Cordova Plugin

## Plugin Usage

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