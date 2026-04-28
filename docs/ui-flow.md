# UI Flow

```text
Splash
  -> Home
      -> Beverage detail / hot water confirmation
          -> Dispensing
              -> Completed -> Home
              -> Cancelled -> Home
              -> Error -> Home
      -> Settings -> Home
      -> Diagnostics -> Home
```

The hot-water button is modeled as a normal beverage with dedicated copy and stricter confirmation language.
