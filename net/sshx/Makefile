PORTNAME=	sshx
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.5
CATEGORIES=	net

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Collaborative live terminal sharing over the web
WWW=		https://sshx.io

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	protoc:devel/protobuf

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	ekzhang

PLIST_FILES=	bin/sshx

.include <bsd.port.mk>
