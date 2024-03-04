PORTNAME=	xauth
PORTVERSION=	1.1.2
CATEGORIES=	x11

MAINTAINER=	x11@FreeBSD.org
COMMENT=	X authority file utility
WWW=		https://gitlab.freedesktop.org/xorg/app/xauth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	cmdtest:devel/py-cmdtest

USES=		shebangfix tar:xz xorg xorg-cat:app
USE_XORG=	x11 xau xext xmuu
SHEBANG_FILES=	${WRKSRC}/tests/*.script
SHEBANG_LANG=	nobash
nobash_OLD_CMD=	/bin/bash
nobash_CMD=	/bin/sh

PLIST_FILES=	bin/xauth share/man/man1/xauth.1.gz
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
