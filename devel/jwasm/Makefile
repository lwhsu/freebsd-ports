PORTNAME=	jwasm
PORTVERSION=	2.19
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Fork of OpenWatcom x86 assembler with AMD64 support
WWW=		https://github.com/Baron-von-Riedesel/JWasm

LICENSE=	OpenWatcom
LICENSE_NAME=	Sybase Open Watcom Public License version 1.0
LICENSE_FILE=	${WRKSRC}/Html/License.html
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		dos2unix gmake

USE_GITHUB=	yes
GH_ACCOUNT=	Baron-von-Riedesel
GH_PROJECT=	JWasm
GH_TAGNAME=	v2.19

OPTIONS_DEFINE=	DOCS

MAKEFILE=	GccUnix.mak

PORTDOCS=	Readme.html Manual.html
PLIST_FILES=	bin/jwasm

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		'/^extra_c_flags/s|-O2|$$(CFLAGS)| ; \
		 /^CC/s| =| ?=| ; \
		 s|-s -o|-o|' ${WRKSRC}/GccUnix.mak

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/GccUnixR/jwasm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/Html/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
