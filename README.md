## rgbscroll
A small program that locates keyboards that have unsupported LED(s) and trigger them using the Scroll Lock key.

### What does this do?
Some cheap keyboards have LED(s) that can be triggered by using the scroll lock key, and GNU/Linux systems cannot toggle them.

So, this program will try to find those LED(s) by iterating the "/sys/class/leds" paths until it is found, then, it'll toggle them by increasing the brightness to "1".

### Contribute
You can contribute to the source code, at anytime.
