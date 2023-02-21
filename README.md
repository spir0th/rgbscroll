## rgbscroll
A small program that toggles RGB lights of a keyboard.

**This project is deprecated in favor of [keylight](https://github.com/spirothdev/keylight).**

### What does this do?
Most cheap (or Chinese-made) keyboards that have cool RGB lights only support Windows, this program fixes it for Linux by iterating the `/sys/class/leds` paths until it is found to be toggled by increasing the brightness value to `1`.

### Why does this exist when some of the keyboards that have RGB lights DO support Linux?
The intention here is to provide Linux users a simple program to toggle their keyboards' RGB lights when unsupported on Linux. This is also useful for beginners if they have the chance to flex their keyboard using Linux.

### Contribute
You can contribute to the source code, at anytime.
