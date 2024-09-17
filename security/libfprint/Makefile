PORTNAME=	libfprint
PORTVERSION=	1.94.8
DISTVERSIONPREFIX=v
CATEGORIES=	security
WWW=		https://gitlab.freedesktop.org/libfprint/libfprint/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Library for fingerprint reader devices
WWW=		https://www.freedesktop.org/wiki/Software/fprint/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gtkdoc-scan:textproc/gtk-doc

LIB_DEPENDS=	libglib-2.0.so:devel/glib20 \
		libgusb.so:devel/libgusb \
		libnss3.so:security/nss \
		libnspr4.so:devel/nspr  \
		libpixman-1.so:x11/pixman \
		libudev.so:devel/libudev-devd

MESON_ARGS= 	-Dudev_rules=disabled -Dudev_hwdb=disabled

USE_GITLAB=	yes
GL_SITE=	https://gitlab.freedesktop.org
GL_ACCOUNT=	libfprint

USES=		meson pkgconfig python:build shebangfix tar:xz
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

SHEBANG_FILES=	tests/egismoc/custom.py \
		tests/focaltech_moc/custom.py \
		tests/elanmoc/custom.py \
		tests/realtek/custom.py \
		tests/goodixmoc/custom.py \
		tests/fpcmoc/custom.py \
		tests/synaptics/custom.py \
		tests/egismoc-05a1/custom.py \
		tests/egismoc-0586/custom.py \
		tests/egismoc-0587/custom.py \
		tests/realtek-5816/custom.py \
		tests/umockdev-test.py \
		tests/capture.py

.include <bsd.port.mk>
