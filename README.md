# arch-udevless
PKGBUILDs for Archlinux-based distros compiled without udev/xudev dependency

This repo contains PKGBUILD files to build software which require systemd-udev or xudev without these dependencies,
to use this software on udevless environment, e.g. [mdev](https://git.busybox.net/busybox/plain/docs/mdev.txt) or [smdev](https://core.suckless.org/smdev/).

# Contents
* [libudev-zero](https://github.com/illiliti/libudev-zero) - libudev replacement for udevless systems
* [smdev](https://git.suckless.org/smdev/log.html) - suckless uevent helper
* [nldev](http://r-36.net/scm/nldev) - a daemon listening for uevents, a frontend for smdev
* processdev - a script implementing rules for uevents post-processing, attempts to replace udev rules

# Todo
* improve processdev rules: some symlinks can be incorrect, some are missing
* add [mdevd](https://skarnet.org/software/mdevd)
* make init scripts replacement transparent, support more init systems
