#############################################################
#
# openocd
#
#############################################################

OPENOCD_VERSION = 0.7.0
OPENOCD_SOURCE = openocd-$(OPENOCD_VERSION).tar.bz2
OPENOCD_SITE = http://downloads.sourceforge.net/project/openocd/openocd/$(OPENOCD_VERSION)

OPENOCD_AUTORECONF = YES
OPENOCD_CONF_OPT = \
	--oldincludedir=$(STAGING_DIR)/usr/include \
	--includedir=$(STAGING_DIR)/usr/include \
	--enable-ft2232_libftdi  \
	--enable-usbprog  \
	--disable-doxygen-html

HOST_OPENOCD_DEPENDENCIES = host-libusb-compat host-libftdi


HOST_OPENOCD_CONF_OPT = 	\
	--disable-doxygen-html 	\

OPENOCD_DEPENDENCIES = libusb-compat
OPENOCD_DEPENDENCIES += libftdi


$(eval $(autotools-package))
$(eval $(host-autotools-package))
