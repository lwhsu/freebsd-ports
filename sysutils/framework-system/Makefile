PORTNAME=	framework-system
DISTVERSION=	0.1.0
CATEGORIES=	sysutils

MAINTAINER=	dhs@frame.work
COMMENT=	Framework Computer System Utility
WWW=		https://github.com/FrameworkComputer/framework-system

LICENSE=	BSD3CLAUSE

USES=		cargo

CPE_VENDOR=	${PORTNAME}_project

USE_GITHUB=	yes
GH_ACCOUNT=	FrameworkComputer
GH_PROJECT=	framework-system
GH_TAGNAME=	freebsd-pre0.1.1

CARGO_BUILD_ARGS=	-p framework_tool
CARGO_INSTALL_PATH=	framework_tool
CARGO_FEATURES=		--no-default-features freebsd

PLIST_FILES=	bin/framework_tool

.include <bsd.port.mk>
